#!/usr/bin/python3
"""
Module for calculating the perimeter of an island
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island in a grid.
    Args:
        grid (list of list of int): grid representing the map
    Returns:
        int: Perimeter of the island
    """
    perimeter = 0
    rows, cols = len(grid), len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i-1][j] == 1:  # Check top
                    perimeter -= 2
                if j > 0 and grid[i][j-1] == 1:  # Check left
                    perimeter -= 2

    return perimeter
