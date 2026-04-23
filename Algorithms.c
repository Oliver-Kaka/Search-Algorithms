#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int size, int key);
int binarySearch(int arr[], int left, int right, int key);
void initHash();
int searchHash(int key);

int main(){

    return 0;
}

int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return i; // return index where key is found
        }
    }
    return -1; // key not found
}

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid; // element found
        }
        else if (arr[mid] < key) {
            left = mid + 1; // search right half
        }
        else {
            right = mid - 1; // search left half
        }
    }
    return -1; // element not found
}

//HASHING
#define TABLE_SIZE 1000
int hashTable[TABLE_SIZE];

void initHash() {
    for(int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insertHash(int key) {
    int index = hashFunction(key);
    while(hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
}

int searchHash(int key) {
    int index = hashFunction(key);
    int start = index;

    while(hashTable[index] != -1) {
        if(hashTable[index] == key)
            return index;
        index = (index + 1) % TABLE_SIZE;

        if(index == start)
            break;
    }
    return -1;
}
