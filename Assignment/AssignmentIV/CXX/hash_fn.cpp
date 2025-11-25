/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/21: Motify the hash finction

   Developer: Jun-Ren Su <s1133337@mail.yzu.edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    int digitSum = 0;
    while (key > 0) {
        int transform = key % 10;
        transform = transform + int('0');
        digitSum += transform ;
        key /= 10;
    }
    return digitSum % m;  // basic division method
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    // TODO: replace with your own design
	using namespace std;
    int digit[4] = {};
    int sum = 0, power = 1;

    for(int i = 0;i < str.size();i++){
        digit[i] = str[i] - 'a' + 1;
        sum += digit[i] * power;
        power *= 10;
    }
    hash = sum;
    return static_cast<int>(hash % m);  // basic division method
}
