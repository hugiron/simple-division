#include "div.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char* simple_division(int a, int b, int n) {
	int size = sizeof(char) * (sizeof(int) + n);
	char* result = (char*)malloc(size);
	snprintf(result, sizeof(result), "%d", a / b);
	a = abs(a) % abs(b);
	bool point_used = false;
	bool extend_used = false;
	int current_index = strlen(result);
	while (n > 0 && a != 0) {
		if (a >= b) {
			result[current_index++] = '0' + (a / b);
			a %= b;
			extend_used = false;
			if (point_used)
				--n;
		} else {
			if (!point_used) {
				point_used = true;
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
	result[current_index] = '\0';	
	return result;
}
