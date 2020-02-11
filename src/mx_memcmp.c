#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    if (n != 0) {
        const char *d1 = s1, *d2 = s2;
        int i = 0;
        
        while (d1[i] && d1[i] == d2[i] && (--n > 0))
            i++;
        return d1[i] - d2[i];
    }
	return 0;
}
