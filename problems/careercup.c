#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Google intevriew questions*/
/*You are given a matrix with N rows and N columns. Elements in matrix can be either 1 or 0. Each row and column of matrix is sorted in ascending order. 
 * Find number of 0-s in the given matrix. 
 * Example:*
 * 0 0 1
 * 0 1 1
 * 1 1 1
 * Answer: 3
 * 0 0
 * 0 0
 * Answer: 4
 *
 *Idea is to find 1st 0 position in first row and then  do that in every row. Max column we can cover in next rows will be only the one you travelled in previous rows. Worst case O(mn) if matrix has all 0's*/


