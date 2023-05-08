#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function prototypes */
int factorial(int n);
float root(float n);
void sort();
void dynamicArr(int size);

/* Main function */
int main() {
    int choice, n;
    float num;
    int s;

    /* Display the menu and get the user's choice */
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Get the factorial of an entered number\n");
        printf("2. Get the root of an entered number\n");
        printf("3. Sort a list of numbers from a txt file\n");
        printf("4. Create an array Dynamically Allocated\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            /* Get a number from the user and get its factorial */
            printf("Enter a number to find its factorial: ");
            scanf("%d", &n);
            printf("Factorial of %d is %d\n", n, factorial(n));
            break;
        case 2:
            /* Get a number from the user and get its square root */
            printf("Enter a number to find its square root: ");
            scanf("%f", &num);
            printf("Square root of %.2f is %.2f\n", num, root(num));
            break;
        case 3:
            /* Sort a list of numbers from a txt file */
            sort();
            break;
        case 4:
            /* Create an array Dynamically Allocated */
            printf("Enter the size of the array: ");
            scanf("%d", &s);
            dynamicArr(s);
            break;
        case 5:
            /* Exit the program */
            exit(0);
        default:
            /* Display an error message for an invalid choice */
            printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}

/* Function to get the factorial of a number */
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

/* Function to get the square root of a number */
float root(float n) {
    return sqrt(n);
}

/* Function to sort a list of numbers from a text file */
void sort() {
    FILE* fp;
    int i, j, temp, arr[100], count = 0;

    /* Open the input file */
    fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        /* Display an error message if the file cannot be opened */
        printf("Failed to open file\n");
        return;
    }

    /* Read in the numbers from the input file */
    while (fscanf(fp, "%d", &arr[count]) != EOF)
        count++;

    /* Close the input file */
    fclose(fp);

    /* Sort the numbers using a bubble sort algorithm */
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    /* Display the sorted list of numbers */
    printf("\nSorted list:\n");
    for (i = 0; i < count; i++)
        printf("%d\n", arr[i]);
}

/* Function to get the square root of a number */
void dynamicArr(int size) {
    int* arr;

    // Dynamically allocate memory for the array
    arr = (int*)malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("\nMemory allocation failed.\n");
        exit(1);
    }

    printf("\nEnter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nSThe elements in the array are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Deallocate memory for the array
    free(arr);

    return 0;
}
