#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* parse_int_array(char* input_string, int* array_size) {
    // Count the number of commas in the input string to determine the size of the array
    *array_size = 1;
    for (int i = 0; i < strlen(input_string); i++) {
        if (input_string[i] == ',') {
            (*array_size)++;
        }
    }

    // Allocate memory for the array
    int* int_array = (int*) malloc(*array_size * sizeof(int));

    // Parse the input string and fill the array with integers
    char* token = strtok(input_string, ",");
    int i = 0;
    while (token != NULL) {
        int_array[i] = atoi(token);
        i++;
        token = strtok(NULL, ",");
    }

    // Return a pointer to the allocated memory
    return int_array;
}

int main() {
    char* input_string = "1,2,3,4,5";
    int array_size;
    int* int_array = parse_int_array(input_string, &array_size);

    // Print the contents of the array
    for (int i = 0; i < array_size; i++) {
        printf("%d ", int_array[i]);
    }

    // Free the allocated memory
    free(int_array);

    return 0;
}
