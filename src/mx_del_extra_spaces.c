#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
	char *r;
	char *s;

	if (str == NULL) 
		return NULL;
	r = mx_strnew(mx_strlen(str));
	for (int i = 0, j = 0; str[i] != '\0'; r[j++] = str[i++])
		if (mx_isspace(str[i]))
			for (r[j++] = ' '; mx_isspace(str[i]); i++);
	s = mx_strtrim(r);
	free(r); 
	return s;
}
