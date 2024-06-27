https://leetcode.com/problems/island-perimeter/
```C
int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int peri = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                peri += (i == 0 || !grid[i - 1][j]);
                peri += (i == gridSize - 1 || !grid[i + 1][j]);
                peri += (j == 0 || !grid[i][j - 1]);
                peri += (j == gridColSize[i] - 1 || !grid[i][j + 1]);
            }
        }
    }
    return peri;
}
```

Focus on how buffer overflow is checked using ||
Using the first condition, if it short circuits the ||, then the 2nd condition isnt checked only.