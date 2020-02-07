#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    int m;
    int n;

    if (str == NULL || sub == NULL)
        return -1;
    if (sub[0] == '\0')
        return 0;
    m = mx_strlen(str) - mx_strlen(sub) + 1; // upper bounded searching range
    n = mx_strlen(sub);

    for (int i = 0; i < m; i++)        
        if (mx_strncmp(&str[i], sub, n) == 0) {
            count++;
            i += n - 1;
        }
    return count;
}
