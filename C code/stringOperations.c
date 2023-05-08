#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

// Function to search for a substring within a given string
int search_substring(char* str, char* sub) {
    // Get the length of the substring
    int sub_len = strlen(sub);

    // Loop through the main string
    for (int i = 0; i < strlen(str); i++) {
        // Check if the current character matches the first character of the substring
        if (str[i] == sub[0]) {
            // Check if the next characters in the main string match the substring
            if (strncmp(str + i, sub, sub_len) == 0) {
                // Return the index of the match
                return i;
            }
        }
    }

    // If no match was found, return -1
    return -1;
}

// Function to concatenate two strings
void concatenate_strings(char* str1, char* str2, char* result) {
    // Copy the first string into the result string
    strcpy(result, str1);

    // Append the second string to the result string
    strcat(result, str2);
}

// Function to compare two strings
int compare_strings(char* str1, char* str2) {
    // Loop through both strings
    for (int i = 0; i < strlen(str1); i++) {
        // If the characters at the current index are different, return the difference in their ASCII values
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }

    // If the loop completes without finding a difference, the strings are equal
    return 0;
}

// Sample main function to demonstrate usage
int main() {
    char str1[100] = "Hello, ";
    char str2[100] = "world!";
    char result[100];

    // Search for a substring
    int substring_index = search_substring(str1, "lo");
    if (substring_index != -1) {
        printf("Substring found at index %d.\n", substring_index);
    }
    else {
        printf("Substring not found.\n");
    }

    // Concatenate two strings
    concatenate_strings(str1, str2, result);
    printf("Concatenated string: %s\n", result);

    // Compare two strings
    int comparison_result = compare_strings(str1, "Hello, world!");
    if (comparison_result == 0) {
        printf("Strings are equal.\n");
    }
    else {
        printf("Strings are not equal. Difference: %d\n", comparison_result);
    }

    // Compare another two strings
    int comparison_result2 = compare_strings(str1, str2);
    if (comparison_result2 == 0) {
        printf("Strings are equal.\n");
    }
    else {
        printf("Strings are not equal. Difference: %d\n", comparison_result2);
    }

    return 0;
}