// pseudo-code for a breadth-first search algorithm on a two-dimensional array

function breadthFirstSearch(array, startX, startY, endX, endY) {
  // create a queue and add the starting coordinates to it
  var queue = [];
  queue.push([startX, startY]);

  // create a 2D array to track visited cells
  var visited = [];
  for(var i = 0; i < array.length; i++) {
    visited.push([]);
  }
  visited[startX][startY] = true;

  // while the queue is not empty
  while(queue.length > 0) {
    // dequeue the first coordinate
    var coord = queue.shift();
    var x = coord[0];
    var y = coord[1];

    // if we have reached the end coordinate, return true
    if(x == endX && y == endY) {
      return true;
    }

    // check all 4 neighbors of the current cell
    if(x > 0 && array[x-1][y] == 1 && !visited[x-1][y]) {
      // if the left neighbor is valid and unvisited, add it to the queue
      queue.push([x-1, y]);
      visited[x-1][y] = true;
    }
    if(x < array.length-1 && array[x+1][y] == 1 && !visited[x+1][y]) {
      // if the right neighbor is valid and unvisited, add it to the queue
      queue.push([x+1, y]);
      visited[x+1][y] = true;
    }
    if(y > 0 && array[x][y-1] == 1 && !visited[x][y-1]) {
      // if the top neighbor is valid and unvisited, add it to the queue
      queue.push([x, y-1]);
      visited[x][y-1] = true;
    }
    if(y < array.length-1 && array[x][y+1] == 1 && !visited[x][y+1]) {
      // if the bottom neighbor is valid and unvisited, add it to the queue
      queue.push([x, y+1]);
      visited[x][y+1] = true;
    }
  }

  // if we have checked all possible cells and have not found a path, return false
  return false;
}
