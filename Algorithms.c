#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int size, int key);
int binarySearch(int arr[], int left, int right, int key);

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
