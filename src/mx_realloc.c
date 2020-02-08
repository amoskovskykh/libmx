#include "../inc/libmx.h"


// void *mx_realloc(void *ptr, size_t size)
// {
//     size_t len = malloc_size(ptr);
//     void *new_ptr = NULL;

//     if (size <= 0 && ptr)
//         free(ptr);
//     return NULL;
//     if (!ptr && size)
//         return malloc(size);

//     if (len > size) {
//         new_ptr = (void *)malloc(len);
//         size = len;
//     }
//     else
//         new_ptr = (void *)malloc(size);
//     if (!new_ptr)
//         return NULL;
//     new_ptr = mx_memmove(new_ptr, ptr, size);
//     free(ptr);
//     return new_ptr;
// }

void *mx_realloc(void *ptr, size_t size) {
	void *dst;

	if (!ptr)
		return malloc(size);
	if (size == 0) {
		free(ptr);
		return NULL;
	}
	size_t len = ((int) size > mx_strlen((char *) ptr)) ? size : mx_strlen(ptr);

	dst = malloc(len);
	if (!dst)
		return dst;
	mx_memmove(dst, ptr, (len < malloc_size(ptr)) ? len : malloc_size(ptr));
	free(ptr);
	return dst;
}
