/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/21: Motify the hash finction

   Developer: Jun-Ren Su <s1133337@mail.yzu.edu.tw>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    int digitSum = 0;
    while(key > 0){
        int transform = key % 10;
        transform = transform + '0';
        digitSum += transform;
        key /= 10;
    }
    return digitSum % m;  // division method example
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    // TODO: replace with your own design
	int len = strlen(str);
    int digit[4] = {};
    int sum = 0, power = 1;

    for(int i = 0;i < len;i++){
        digit[i] = str[i] - 'a';
        sum += digit[i] * power;
        power *= 10;
    }
    hash = sum;
    
    return (int)(hash % m); // basic division method
}
