#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    if (n == 0)
		return NULL;
    const char *s = src;
    char *d = dst;
    
	while (n-- > 0 && *s != c)
        *(d++) = *(s++);
    if (*s == c) {
        *d++ = *s;
        return d;
    }
	return NULL;
}
