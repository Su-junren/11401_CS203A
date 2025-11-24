/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/21: Motify the hash finction
    - 2025/11/24: Motify the README

   Developer: Jun-Ren Su <s1133337@mail.yzu.edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    return key % m;  // basic division method
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    // TODO: replace with your own design
    int digit[str.size()] = {};
    int sum = 0, power = 1;

    for(int i = 0;i < str.size();i++){
        digit[i] = str[i] - 'a';
        sum += digit[i] * power;
        power *= 10;
    }
    hash = sum;
    return static_cast<int>(hash % m);  // basic division method
}
