# Multi Equation Solver

In this we use the Gauss Jordan method of solving a matrix to determine the exact solution of a set of multi variable equations, provided that the system of equations aren't inconsistent.

## Gauss Jordan

### Row Echelon Form & The Reduced Row Echelon Form
In this we make the reduced row echelon form of the matrix. 
<br>The properties of a **Reduced Row Echelon Matrix** are as follows :
- If a row doesn't consist of zeroes only, the first non zero number must be 1, and it's called the leading one.
- If a row only consists of zeroes, it must be moved to the bottom.
- For each non zero row, the leading one must be to the right, and below the other leading one's.
- In a column with a leading one, the other elements must be 0.

The only difference between the **row echelon** and a **reduced row echelon form** is the 4th point of the above mentioned properties.

### Why don't we consider any of the rows to be completely filled with zeroes in this project?
In this project however, we don't consider any of the rows to be completely filled with zeroes, as it would mean that the system of equations is inconsistent (since the rank of the matrix would be less than the number of variables).

### Rank of a Matrix
The rank of a matrix is the number of non zero rows in the reduced row echelon form of the matrix.

### Usage of rank to determine whether the system of equations is consistent or not
If we consider the equation matrix to be A, and the augmented matrix to be B, the form of the equation is AX=B. Also, we consider n to be the number of variables in the system of equations.

- If Rank(A) = Rank(A|B) < n -> Infinite Solutions
- If Rank(A) = Rank(A|B) = n -> Unique Solution
- If Rank(A) ≠ Rank(A|B) -> No Solution

### Cramers Rule Method for inconsistent systems
If the system of equations is inconsistent, we can use the Cramers Rule method to determine the solution of the system of equations.

It states that if the determinant of the coefficient matrix is zero, then the system of equations is inconsistent.

## Usage
In this project, we use Cramers rule to determine if the set of equations is consistent of not. If it is consistent, we use the Gauss Jordan method to determine the solution of the system of equations.

We could have used just the cramers rule method, but I used the Gauss Jordan method as I just learnt it and wanted to implement it. Also, I heard that it's faster than the Cramers rule method.

## How to use
- The first line of the input is the number of variables or the number of equations. We take this value as '**n**'.
- The next '**n**' lines are the coefficients of the variables in the equations. The last number in each line is the constant.
- For example, for the equation, 2x + 3y = 5, the input would be 2 3 5.


## Example
### Input
```bash
g++ main.cpp -o main
./main
3
1 2 3 6
4 5 6 15
1 1 1 3
```
Number of variables : **3**
<br>1x + 2y + 3z = 6 : **1 2 3 6**
<br>4x + 5y + 6z = 15 : **4 5 6 15**
<br>1x + 1y + 1z = 3 : **1 1 1 3**

### Output
```bash
1 0 0 1
0 1 0 1
0 0 1 1
```
The output is the reduced row echelon form of the augmented matrix.
<br>
<br>1x + 0y + 0z = 1 : **1 0 0 1** -> x = 1
<br>0x + 1y + 0z = 1 : **0 1 0 1** -> y = 1
<br>0x + 0y + 1z = 1 : **0 0 1 1** -> z = 1

The solution of the system of equations is x = 1, y = 1, z = 1.

## References
- [Gauss Jordan Method Youtube Video](https://www.youtube.com/watch?v=eYSASx8_nyg)
- [Gauss Elimination and Gauss Jordan Method Wikipedia](https://en.wikipedia.org/wiki/Gaussian_elimination#The_reduced_row_echelon_form)
- [Cramers Rule Wiki](https://en.wikipedia.org/wiki/Cramer%27s_rule)
- [Cramers Rule Youtube Video](https://www.youtube.com/watch?v=Ot87qLTODdQ)
- [Cramers Rule 3Blue1Brown Geometrical Video (cool stuff)](https://www.youtube.com/watch?v=jBsC34PxzoM)
- [Row and Reduced Row Echelon Form Wiki](https://en.wikipedia.org/wiki/Row_echelon_form)

# Bugs
1. Just discovered a bug (07-02-2024) for the input
```bash
4       
1 1 1 1 4
2 2 1 2 7
5 4 5 4 18
8 9 1 0 18
```
The output is 
```bash
------------------
         1          1          1          1          4 
         2          2          1          2          7
         5          4          5          4         18
         8          9          1          0         18
------------------
------------------
         1          1          1          1          4
         0          0         -1          0         -1
         0         -1          0         -1         -2
         0          1         -7         -8        -14
------------------
------------------
         1          1          1          1          4
       nan        nan       -inf        nan       -inf
         0         -1          0         -1         -2
         0          1         -7         -8        -14
------------------
------------------
         1          1          1          1          4
       nan        nan       -inf        nan       -inf 
       nan        nan       -inf        nan       -inf
       nan        nan        inf        nan        inf
------------------
------------------
         1          1          1          1          4
       nan        nan       -inf        nan       -inf
       nan        nan        nan        nan        nan
       nan        nan        inf        nan        inf
------------------
------------------
         1          1          1          1          4
       nan        nan       -inf        nan       -inf 
       nan        nan        nan        nan        nan
       nan        nan        nan        nan        nan
------------------
------------------
         1          1          1          1          4
       nan        nan       -inf        nan       -inf
       nan        nan        nan        nan        nan
       nan        nan        nan        nan        nan
------------------
------------------
         1          1          1          1          4
       nan        nan       -inf        nan       -inf
       nan        nan        nan        nan        nan
       nan        nan        nan        nan        nan
------------------
------------------
       nan        nan        nan        nan        nan
       nan        nan        nan        nan        nan
       nan        nan        nan        nan        nan
       nan        nan        nan        nan        nan 
------------------
```
<br>
<br>
### Why did this happen?
The reason is this happened is due to the fact that the second row is trying to divide itself by 0, since the second element of the second row is 0. This is a bug in the code. (However, the code is working fine for the other inputs, so I'm not going to fix it. I'm just going to leave it as it is.)

(The bug was identified between these two steps)
```bash
------------------
         1          1          1          1          4
         0          0         -1          0         -1
         0         -1          0         -1         -2
         0          1         -7         -8        -14
------------------
------------------
         1          1          1          1          4
       nan        nan       -inf        nan       -inf
         0         -1          0         -1         -2
         0          1         -7         -8        -14
------------------
```