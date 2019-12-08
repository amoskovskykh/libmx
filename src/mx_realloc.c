#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
	if (!ptr)
		return malloc(size);
	if (size == 0){
		free(ptr);
		return NULL;
		}

	// size_t len = mx_lib_max(size, mx_lib_strlen(ptr));
	// void *dst = malloc(len);
	// if (dst){
	// 	mx_memmove(dst, ptr, mx_lib_min(len, malloc_size(ptr)));
	// 	free(ptr);
	// }
	// return dst;

	void *dst = malloc(((int) size > mx_strlen((char *) ptr)) ? size : mx_strlen(ptr));
	if (ptr == NULL || !dst)
		return dst;
	mx_memmove(dst, ptr, (size < malloc_size(ptr)) ? size : malloc_size(ptr));
	free(ptr);
	return dst;
}

// int main(void)
// {

//     char *srcv = (char *) malloc(sizeof(char) * 20);
// 	srcv = "12345690";
// 	printf ("old one: %s\n",srcv);
// 	mx_realloc(srcv,10);
// 	printf ("after realloc: %s\n",srcv);
// }
