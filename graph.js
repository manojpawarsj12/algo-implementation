const graph = {
    a: ["b", "c"],
    b: ["d"],
    c: ["e"],
    d: ["f"],
    e: [],
    f: [],
};

function dfs(graph, source) {
    let stack = [source];

    while (stack.length > 0) {
        let curr = stack.pop();
        console.log(curr);
        for (let neighbour of graph[curr]) {
            stack.push(neighbour);
        }
    }
}
function bfs(graph, source) {
    let queue = [source];
    while (queue.length > 0) {
        let curr = queue.shift();
        console.log(curr);
        for (let neighbour of graph[curr]) {
            queue.push(neighbour);
        }
    }
}

function dfs_recursion(graph, source) {
    console.log(source);
    for (let neighbour of graph[source]) {
        dfs_recursion(graph, neighbour)
    }
}

dfs_recursion(graph, "a");
console.log("bfs");
bfs(graph, "a");
