#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
#define REPEAT 10000   // repeat to get measurable time

int linearSearch(int arr[], int size, int key);
int binarySearch(int arr[], int left, int right, int key);
// HASH prototypes
void initHash();
void insertHash(int key);
int searchHash(int key);

int main(){
    int arr[SIZE];
    int choice, key;
    clock_t start, end;
    double time_taken;

    // Fill array with sorted data
    for(int i = 0; i < SIZE; i++) {
        arr[i] = i * 2;
    }

    // Prepare hash table
    initHash();
    for(int i = 0; i < SIZE; i++) {
        insertHash(arr[i]);
    }

    printf("Enter element to search(last element is 1998 to check max time): ");
    scanf("%d", &key);

    printf("\nChoose Search Method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("3. Hashing\n");
    printf("4. Compare All\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    int result = -1;

    switch(choice) {

        case 1:
            start = clock();
            for(int i = 0; i < REPEAT; i++)
                result = linearSearch(arr, SIZE, key);
            end = clock();

            printf("\n[Linear Search]\n");
            break;

        case 2:
            start = clock();
            for(int i = 0; i < REPEAT; i++)
                result = binarySearch(arr, 0, SIZE - 1, key);
            end = clock();

            printf("\n[Binary Search]\n");
            break;

        case 3:
            start = clock();
            for(int i = 0; i < REPEAT; i++)
                result = searchHash(key);
            end = clock();

            printf("\n[Hashing]\n");
            break;

        case 4: {
            double t1, t2, t3;
            int r1, r2, r3;

            // Linear
            start = clock();
            for(int i = 0; i < REPEAT; i++)
            r1 = linearSearch(arr, SIZE, key);
            end = clock();
            t1 = ((double)(end - start)) / CLOCKS_PER_SEC;

            // Binary
            start = clock();
            for(int i = 0; i < REPEAT; i++)
                r2 = binarySearch(arr, 0, SIZE - 1, key);
            end = clock();
            t2 = ((double)(end - start)) / CLOCKS_PER_SEC;

            // Hashing
            start = clock();
            for(int i = 0; i < REPEAT; i++)
                r3 = searchHash(key);
            end = clock();
            t3 = ((double)(end - start)) / CLOCKS_PER_SEC;

            printf("\n--- Comparison ---\n");

            printf("Linear Search  : %f seconds | %s\n", t1, (r1 != -1) ? "Found" : "Not Found");
            printf("Binary Search  : %f seconds | %s\n", t2, (r2 != -1) ? "Found" : "Not Found");
            printf("Hashing        : %f seconds | %s\n", t3, (r3 != -1) ? "Found" : "Not Found");

            return 0;
        }

        default:
            printf("Invalid choice\n");
            return 0;
    }

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    printf("Time taken: %f seconds\n", time_taken);

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
#define TABLE_SIZE 2003
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
