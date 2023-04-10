# READ ME

This is a repository which is used to store my project files and some notes about algorithm class.

I feel deeply the importance of algorithm and its position in the field of computer science, So I hope this not just to store such rubbish works, but also push me to  get advanced in algorithm.

---

## Divide-and-Conquer

### Fast Fourier Transform

$$
f(x)=\sum_{i=0}^{n-1}a_{i}x^i
\\
=(a_{0} + a_{2}x^2 + ...+a_{n-2}x^{n-2}) + (a_{1} + a_{3}x^3 + ...+a_{n-1}x^{n-1})
\\\\
f_{1}=a_{0} + a_{2}x^2 + ...+a_{n-2}x^{n-2}
\\
f_{2}=a_{1} + a_{3}x^3 + ...+a_{n-1}x^{n-1}
\\\\
f(x)=f_{1}(x^2) + xf_{2}(x^2)
\\
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

### The Shortest Path
