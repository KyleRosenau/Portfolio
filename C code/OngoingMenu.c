#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int n);
float root(float n);
void sort();

int main() {
    int choice, n;
    float num;

    while(1) {
        printf("Enter your choice:\n");
        printf("1. Get the factorial of an entered number\n");
        printf("2. Get the root of an entered number\n");
        printf("3. Sort a list of numbers from a txt file\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter a number to find its factorial: ");
                scanf("%d", &n);
                printf("Factorial of %d is %d\n", n, factorial(n));
                break;
            case 2:
                printf("Enter a number to find its square root: ");
                scanf("%f", &num);
                printf("Square root of %.2f is %.2f\n", num, root(num));
                break;
            case 3:
                sort();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

float root(float n) {
    return sqrt(n);
}

void sort() {
    FILE *fp;
    int i, j, temp, arr[100], count=0;

    fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return;
    }

    while(fscanf(fp, "%d", &arr[count]) != EOF)
        count++;

    fclose(fp);

    for(i=0; i<count; i++) {
        for(j=i+1; j<count; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sorted list:\n");
    for(i=0; i<count; i++)
        printf("%d\n", arr[i]);
}