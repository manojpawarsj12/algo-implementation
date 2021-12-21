#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#define CAPACITY 640000
#define CHUNK_LIST_CAP 1024
size_t heap_size = 0;
uintptr_t heap[CAPACITY] = {0};
typedef struct
{
    uintptr_t *start;
    size_t size;
} Chunk;

typedef struct
{
    size_t count;
    Chunk chunks[CHUNK_LIST_CAP];
} Chunk_List;

Chunk_List allocated_chunks = {0};
Chunk_List freed_chunks = {0};

void *chunk_list_insert(Chunk_List *list, uintptr_t *start, size_t size)
{
    assert(list->count <= CHUNK_LIST_CAP);
    list->chunks[list->count].start = start;
    list->chunks[list->count].size = size;

    for (size_t i = list->count;
         i > 0 && list->chunks[i].start < list->chunks[i - 1].start;
         --i)
    {
        const Chunk t = list->chunks[i];
        list->chunks[i] = list->chunks[i - 1];
        list->chunks[i - 1] = t;
    }

    list->count += 1;
}

int chunk_list_find(const Chunk_List *list, uintptr_t *ptr)
{
    for (size_t i = 0; i < list->count; ++i)
    {
        if (list->chunks[i].start == ptr)
        {
            return (int)i;
        }
    }

    return -1;
}

void chunk_list_remove(Chunk_List *list, size_t index)
{
    assert(index < list->count);
    for (size_t i = index; i < list->count - 1; ++i)
    {
        list->chunks[i] = list->chunks[i + 1];
    }
    list->count -= 1;
}
void chunk_list_print(const Chunk_List *list, const char *name)
{
    printf("%s Chunks (%zu):\n", name, list->count);
    for (size_t i = 0; i < list->count; ++i)
    {
        printf("  start: %p, size: %zu\n",
               (void *)list->chunks[i].start,
               list->chunks[i].size);
    }
}

void *heap_alloc(size_t size)
{
    if (size > 0)
    {
        assert(heap_size + size <= CAPACITY);
        void *ptr = heap + heap_size;
        heap_size += size;
        chunk_list_insert(&allocated_chunks, ptr, size);
        return ptr;
    }
}

void heap_free(uintptr_t *ptr)
{
    if (ptr != NULL)
    {
        const int index = chunk_list_find(&allocated_chunks, ptr);
        assert(index >= 0);
        assert(ptr == allocated_chunks.chunks[index].start);
        chunk_list_insert(&freed_chunks,
                          allocated_chunks.chunks[index].start,
                          allocated_chunks.chunks[index].size);
        chunk_list_remove(&allocated_chunks, (size_t)index);
    }
}

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        void *p = heap_alloc(i);
        if (i & 1)
        {
            heap_free(p);
        }
    }
    chunk_list_print(&allocated_chunks, "Alloced");
    chunk_list_print(&freed_chunks, "Freed");
    return 0;
}
