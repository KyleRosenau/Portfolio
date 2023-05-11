#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

// A function that allocates memory on the heap and returns a pointer to the memory
int* allocate(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    return arr;
}

// A function that takes an array and its size as parameters, and fills the array with random values
void fill_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Generate a random number between 0 and 99
    }
}

int main() {
    // Allocate an array on the stack
    int arr1[5];

    // Allocate an array on the heap using a function
    int* arr2 = allocate(5);

    // Fill both arrays with random values
    fill_array(arr1, 5);
    fill_array(arr2, 5);

    // Print the arrays
    printf("Array 1 (stack): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Array 2 (heap): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Deallocate the memory for the heap array
    free(arr2);

    return 0;
}
