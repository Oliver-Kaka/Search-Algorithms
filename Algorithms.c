#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int size, int key);

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
