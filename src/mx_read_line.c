#include "../inc/libmx.h"

static char *mx_read_realloc(char *lineptr, int count, int size);
static int mx_check_static(char **lineptr, char **str, char delim);
static int mx_read_main_loop(char **lineptr, char **str, int count, t_read r);

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
	static char *str = NULL;
	int count = 0;

	if (buf_size < 1 || fd < 0)
		return -2;
	if (malloc_size(*lineptr))
		free(*lineptr);
	*lineptr = NULL;
	if (str)
		count = mx_check_static(lineptr, &str, delim);
	if (str)
		return count;
	count = mx_read_main_loop(lineptr, &str, count, (t_read){buf_size, delim, fd});
	if (count == 0)
		return -1;
	return count;
}

static char *mx_read_realloc(char *lineptr, int count, int size) {
	char *temp = mx_strnew(count + size);

	temp = mx_memcpy(temp, lineptr, count);
	free(lineptr);
	return temp;
}

static int mx_check_static(char **lineptr, char **str, char delim) {
	int n = mx_strlen(*str);
	int c = mx_get_char_index(*str, delim);
	char *temp;
	int count = 0;

	if (c != -1) {
		count += c;
		*lineptr = (char *) mx_memmove(mx_strnew(count), *str, count);
		temp = mx_strncpy(mx_strnew(n - c - 1), *str + c + 1, n - c - 1);
		free(*str);
		*str = temp;
		return count;
	}
	count += n;
	*lineptr = (char *) mx_memmove(mx_strnew(count), *str, count);
	free(*str);
	*str = NULL;

	return count;
}

static int mx_read_main_loop(char **lineptr, char **str, int count, t_read r) {
	char buf[r.buf_size];
	int c;

	for (int size = read(r.fd, buf, r.buf_size); size; size = read(r.fd, buf, r.buf_size)) {
		c = mx_get_char_index(buf, r.delim);
		if (c != -1) {
			*lineptr = mx_read_realloc(*lineptr, count, c);  
			mx_memjoin(*lineptr, buf, count, c);
			*str = mx_strncpy(mx_strnew(size - c - 1), buf + c + 1, size - c - 1);
			count += c;
			return count;
		}
		*lineptr = mx_read_realloc(*lineptr, count, size);
		mx_memjoin(*lineptr, buf, count, size);
		count += size;
	}
	return count;
}




