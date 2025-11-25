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
	ASCII code is a different kind of symbol of a number in computer, so I use this special code to define my hash function. 
	The result would be key number transform to ASCII code and mod the table size.
	I think this method could lminumize the collisions.
```

### Non-integer Keys
- Formula / pseudocode:
```text
	asign value to char: a -> 1, b -> 2, c -> 3...
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
- The project compile in ```Visual Studio 2026```.

### Result Snapshot
- Example output for integers:

  <img width="312" height="534" alt="image" src="https://github.com/user-attachments/assets/e44295b6-8ada-4c05-aaa3-50be1dec1bb6" />
  <img width="331" height="543" alt="image" src="https://github.com/user-attachments/assets/fcb2279b-4a4f-44c9-98db-4bf83f9463ba" />
  <img width="313" height="529" alt="image" src="https://github.com/user-attachments/assets/b8813394-9259-43af-a225-3524516be383" />

- Example output for strings:

  <img width="351" height="310" alt="image" src="https://github.com/user-attachments/assets/92a6d43f-fa29-44ef-8593-6a29ab119c9b" />
  <img width="355" height="317" alt="image" src="https://github.com/user-attachments/assets/52aed87b-b60c-421b-9db4-37a7ea15bd9d" />
  <img width="345" height="307" alt="image" src="https://github.com/user-attachments/assets/16046ad0-f3d8-4d7e-ab04-b11836fbaaa6" />

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [9, 0, 1, 2, 3, 4, 5, 6, 7, 9, 2, 3, 4, 5, 6, 7, 8, 9, 0, 2]
  Hash table (m=11): [0, 1, 2, 3, 4, 5, 6, 7, 8, 0, 3, 4, 5, 6, 7, 8, 9, 10, 0, 3]
  Hash table (m=37): [25, 26, 27, 28, 29, 30, 31, 32, 33, 25, 28, 29, 30, 31, 32, 33, 34, 35, 36, 28]
  ```
- Example output for strings:
  ```
  Hash table (m=10): [2, 3, 1, 2, 0, 4, 1, 7, 5, 5]
  Hash table (m=11): [10, 6, 9, 10, 6, 3, 1, 5, 2, 3]
  Hash table (m=37): [15, 3, 14, 11, 32, 2, 34, 15, 29, 3]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- Hash function - Integer v.s Non-integer : In integer case, my hash function just take ASCII code to get the hash value. Therefore, the original feature will be carried into the hash value. In non-integer case, I use the number to present each ```char``` and take this number to multiply by 10 to the power of index, that like weight, so it would be less collisions in this case.
- Prediction : I think, in integer case, the situation of collisions would be the same in every ```table size```; in non-integer case, it would decrease as table size increase.      

## Reflection
1. Use ```digit[4]``` to storage the number of each ```char``` and multiply the ```weight```(power).
2. return ```static_case<int>``` to sure the data type of ```hash value``` is correct. 
