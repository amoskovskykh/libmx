#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int m;
    int n;

    if (str == NULL || sub == NULL) 
        return -2;
    m = mx_strlen(sub);
    if (m == 0)
        return mx_strlen(str);
    n = mx_strlen(str) - m + 1;
    
    for (int i = 0; i < n; i++)
		if (mx_strncmp(&str[i], sub, m) == 0)
			return i;
	return -1;
}
