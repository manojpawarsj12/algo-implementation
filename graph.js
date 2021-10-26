let graph = {
  0: [8, 1, 5],
  1: [0],
  5: [0, 8],
  8: [0, 5],
  2: [3, 4],
  3: [2, 4],
  4: [3, 2],
};

function buildGraph(edges) {
  const graph = {};
  for (let edge of edges) {
    const [a, b] = edge;
    if (!(a in graph)) {
      graph[a] = [];
    }
    if (!(b in graph)) {
      graph[b] = [];
    }
    graph[a].push(b);
    graph[b].push(a);
  }
  return graph;
}

function dfs(graph, source) {
  let visited = new Set();
  let stack = [source];

  while (stack.length > 0) {
    let curr = stack.pop();
    console.log(curr);
    for (let neighbour of graph[curr]) {
      if (!visited.has(neighbour)) {
        visited.add(neighbour);
        stack.push(neighbour);
      }
    }
  }
}
function bfs(graph, source) {
  let queue = [source];
  let visited = new Set();
  while (queue.length > 0) {
    let curr = queue.shift();
    console.log(curr);
    for (let neighbour of graph[curr]) {
      if (!visited.has(neighbour)) {
        visited.add(neighbour);
        queue.push(neighbour);
      }
    }
  }
}

function dfs_recursion(graph, source) {
  console.log(source);
  for (let neighbour of graph[source]) {
    dfs_recursion(graph, neighbour);
  }
}

function hasPath(graph, src, dst) {
  if (src === dst) {
    return true;
  }
  for (let neighbour of graph[src]) {
    if (hasPath(graph, neighbour, dst)) {
      return true;
    }
  }
  return false;
}

let visited = new Set();
function CyclicHasPath(graph, src, dst) {
  if (src === dst) {
    return true;
  }
  if (visited.has(src)) {
    return false;
  }
  visited.add(src);
  for (let neighbour of graph[src]) {
    if (hasPath(graph, neighbour, dst)) {
      return true;
    }
  }
  return false;
}
function connectedComponentsCount(graph) {
  let visited = new Set();
  let count = 0;
  for (let node in graph) {
    if (explore(graph, node, visited)) {
      count++;
    }
  }
  return count;
}
function explore(graph, current, visited) {
  if (visited.has(String(current))) {
    return false;
  }
  visited.add(String(current));
  for (let neighbour of graph[current]) {
    explore(graph, neighbour, visited);
  }
  return true;
}

function longestConnectedComponent(graph) {
  let visited = new Set();
  let longest = 0;
  for (let node in graph) {
    let size = exploreSize(graph, node, visited);
    longest = Math.max(size, longest);
  }
  return longest;
}
function exploreSize(graph, current, visited) {
  if (visited.has(String(current))) {
    return 0;
  }
  visited.add(String(current));
  let size = 1;
  for (let neighbour of graph[current]) {
    size += exploreSize(graph, neighbour, visited);
  }
  return size;
}

function shortestPathBFS(edges, src, dst) {
  let visited = new Set([src]);
  let queue = [[src, 0]];
  let graph = buildGraph(edges);
  while (queue.length > 0) {
    let [node, distance] = queue.shift();
    if (node == dst) {
      return distance;
    }
    for (let neighbour of graph[node]) {
      if (!visited.has(neighbour)) {
        visited.add(neighbour);
        queue.push([neighbour, distance + 1]);
      }
    }
  }
  return -1;
}

function islandCount(grid) {
  let visited = new Set();
  let count = 0;
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
      if (exploreIsland(grid, i, j, visited)) {
        count++;
      }
    }
  }
  return count;
}
function exploreIsland(grid, r, c, visited) {

  const colcheck = 0 <= c && c < grid.length;
  const rowcheck = 0 <= r && r < grid.length;
  if (!colcheck || !rowcheck) {
    return false
  }
  if (grid[r][c] === "W") {
    return false;
  }

  let pos = r + "," + c;
  if (visited.has(pos)) {
    return false;
  }
  visited.add(pos);
  exploreIsland(grid, r + 1, c, visited);
  exploreIsland(grid, r, c + 1, visited);
  exploreIsland(grid, r - 1, c, visited);
  exploreIsland(grid, r, c - 1, visited);
  return true;
}

const grid = [
  ["W", "L", "W", "W", "W"],
  ["W", "L", "W", "W", "W"],
  ["W", "W", "W", "L", "W"],
  ["W", "W", "L", "L", "W"],
  ["L", "W", "W", "L", "L"],
  ["L", "L", "W", "W", "W"],
];

const edges = [
  ["a", "c"],
  ["a", "b"],
  ["c", "b"],
  ["c", "d"],
  ["b", "d"],
  ["e", "d"],
  ["g", "f"],
];
console.log(islandCount(grid))