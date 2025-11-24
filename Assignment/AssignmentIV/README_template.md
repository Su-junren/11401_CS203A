# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: Jun-Ren Su  
Email: s1133337@mail.yzu.edu.tw  

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
	each digit -> ASCII code and get their summation
	sum % table size
  ```
- Rationale: 
```text
¡@	ASCII code is a different kind of symbol of a number in computer, so I use this special code to define my hash function. 
	The result would be key number transform to ASCII code and mod the table size.
	I think this method could lminumize the collisions.

```

### Non-integer Keys
- Formula / pseudocode:
  ```text
	asign value to char: a -> 0, b -> 1, c -> 2...
	give key word index: "cat" c -> 0, a -> 1, t -> 2
	each char * 10 ^ (their index) and get their summation
	sum % tabel size
  ```
- Rationale: 
```text
	At the first, I give the char a number to caculate. Then, giving the char index in each word. Finaly, use their value to multiply by 10 to the power of index.
	The result would be the summation o f values of each char in each key string * 10 ^ (their index).
	I think the result would be much different from lexicographical order. 
```

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
Integer:
| Table Size (m) | Index Sequence         | Observation             
|----------------|------------------------|--------------------------------------|
| 10             | 1, 2, 3, 4, ...        | Repeats every 10 but lost some number|
| 11             | 10, 0, 1, 2, ...       | A little unique                      |
| 37             | 20, 21, 22, 23, ...    | Collisions appear in 25 to 36        |

Non-integer:
| Table Size (m) | Index Sequence         | Observation             
|----------------|------------------------|--------------------------------------|
| 10             | 1, 2, 3, 4, ...        | Collisions often appear              |
| 11             | 10, 0, 1, 2, ...       | Collisions often appear              | 
| 37             | 20, 21, 22, 23, ...    | Collisions rarely appear             |

## Compilation, Build, Execution, and Output

### Compilation
- The project compile in Visual Studio 2026.

### Result Snapshot
- Example output for integers:
  

- Example output for strings:
  

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- Prime vs non-prime `m`: Prime table sizes generally result in better distribution and fewer collisions.
- Patterns or collisions: Non-prime table sizes tend to produce repetitive patterns, leading to more collisions.
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.
