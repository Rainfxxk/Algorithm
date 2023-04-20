# READ ME

This is a repository which is used to store my project files and some notes about algorithm class.

I feel deeply the importance of algorithm and its position in the field of computer science, So I hope this not just to store such rubbish works, but also push me to  get advanced in algorithm.

---

## Divide-and-Conquer

### Fast Fourier Transform

$$
f(x)=\sum_{i=0}^{n-1}a_{i}x^i
\newline
=(a_{0} + a_{2}x^2 + ...+a_{n-2}x^{n-2}) + (a_{1} + a_{3}x^3 + ...+a_{n-1}x^{n-1})
\newline
f_{1}=a_{0} + a_{2}x^2 + ...+a_{n-2}x^{n-2}
\newline
f_{2}=a_{1} + a_{3}x^3 + ...+a_{n-1}x^{n-1}
\newline
f(x)=f_{1}(x^2) + xf_{2}(x^2)
$$

## Dynamic Programming

dynamic programming is a method for solving a complex problem by **breaking it down** into a collection of simpler subproblems.

Just according to the definition, we maybe get confused about the differences between dynamic programming and divide-and-conquer.  they do have some similarities, but the biggest difference is in dynamic programming, the subproblems have connection with each other.

The following table gives the differences in detail.

|                                  | Dynamic Programming      | Divide and Conquer    |
| -------------------------------- | ------------------------ | --------------------- |
| subproblem                       | interconnection          | dependence            |
| the order of solving the problem | bottom-up                | top-down              |
| efficiency                       | no repeated calculations | repeated calculations |
|                                  |                          |                       |
|                                  |                          |                       |
|                                  |                          |                       |
|                                  |                          |                       |
|                                  |                          |                       |
|                                  |                          |                       |

### The Shortest or LongestPath

### String Editing Distance

$$
distance(i, j) = min(distance(i-1, j) +1,
\newline
distance(i, j-1)+1, 
\newline
distance(i-1, j-1)+diff(i, j))
$$

### The Bag Problem

In this problem, we can hava **two situations**:

1. the amount of each item is limited.

2. the amount of each item is countless.

No matter how, for each step, there **three options** for us to choose:

1. $W(bag, items) = W(smaller\enspace bag,\enspace less\enspace item) + value_{i}$

2. $W(bag, items) = W(smaller\enspace bag,\enspace items) + value_{i}$

3. $W(bag, items) = W(bag,\enspace less\enspace item)$

So according to each situation, we just need do the best choice, and we are gonna get the best sulotion.

### Matrix Concatenation

Ror mutiple matrix concatenation

$$
M = m_{1(p_{1},q_{1})}\times \ldots \times m_{j(p_{j},q_{j）}}
$$

When two matrices are multiplied $m_{i(p_{i},q_{i})}\times m_{j(p_{j},q_{j})}$ , this will perform $p_{i}q_{i}p_{j}$ times of  multiplication. 

By using $C(i, j)$ to express how many times  of multiplication are performed when the $m_{i}$ multiple $m_{j}$,   we can get the optimal solution according to the following formula,.

$$
C(i, j) = min(C(i,k) + C(k+1, j) + p_{i}q_{k}q_{j})
\newline
k \in [i, j)
$$

### Travelling Salesman



## Graph
