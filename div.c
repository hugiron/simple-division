#include "div.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char* resize(char* array, int size) {
	return (char*)realloc(array, size * sizeof(char));
}

char* simple_division(int a, int b, int n) {
	int step = n;
	int size = step;
	char* result = (char*)malloc(size * sizeof(char));
	bool point_used = false;
	bool extend_used = false;
	int current_index = 0;
	if (((a & (1 << 31)) ^ (b & (1 << 31))) != 0)
		result[current_index++] = '-';
	a = abs(a);
	b = abs(b);
	while (n > 0 && a != 0) {
		if (current_index == (size - 1)) {
			size += step;
			result = resize(result, size);
		}
		if (a >= b) {
			result[current_index++] = '0' + (a / b);
			a %= b;
			extend_used = false;
			if (point_used)
				--n;
		} else {
			if (!point_used) {
				point_used = true;
				if (current_index == 0 || (current_index == 1 && result[0] == '-'))
					result[current_index++] = '0';
				result[current_index++] = '.';
			}	
			if (extend_used) {
				result[current_index++] = '0';
				--n;
			} else {
				extend_used = true;
			}
			a *= 10;		
		}
	}	
	return result;
}
