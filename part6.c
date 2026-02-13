#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// THis makes the code more reusable, we can have a bunch of functions and select between them by changing the input transposition function!
typedef void (*TranspositionFunc)(char *);

void reverse_string(char *str) {
	if (str == NULL) return;

	char *start = str;
	char *end = str + strlen(str) - 1;

	char temp;

	while (start < end) {
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}

// Accepts the data (str) and the function to apply to it (func)
void apply_and_print(char *str, TranspositionFunc func) {
	printf("\n--- Transposition Report ---\n");
	printf("Original String:   %s\n", str);
	
	func(str);
	
	printf("Transformed String: %s\n", str);
	printf("--------------------------\n");
}

int main() {
	size_t buffer_size = 1024;
	
	// Dynamic Allocation: Allocate memory on the heap for the input
	char *input_buffer = (char *)malloc(buffer_size * sizeof(char));

	if (input_buffer == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
	}

	printf("Enter a string to transpose: ");
	
	// Read input from stdin
	if (getline(&input_buffer, &buffer_size, stdin) != -1) {
		// Strip the newline character
		char *newline = strchr(input_buffer, '\n');
		if (newline) *newline = '\0';

		// Pass in the string and the function reverse_string
		apply_and_print(input_buffer, reverse_string);
	} else {
		printf("Error reading input.\n");
	}

	// Clean up heap memory
	free(input_buffer);

	return 0;
}
