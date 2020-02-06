#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
	if (str == NULL)
		return NULL;
	int i, j;

	for (i = 0; mx_isspace(str[i]) && str[i + 1]; i++);
	for (j = mx_strlen(str); j > i && mx_isspace(str[j - 1]); j--);
	return mx_strndup(&str[i], j - i);
}
