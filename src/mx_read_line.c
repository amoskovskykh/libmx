#include "../inc/libmx.h"

// static mx_process_line(char **lineptr, char *buf, char delim, )
// {

// }

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
	if (buf_size < 1 || fd < 0)
		return -2;
	if (*lineptr)
		free(*lineptr);

	static char *str = NULL;
	int count = 0;
	int c;
	char *buf = mx_strnew(buf_size);
	int size;
	// printf("\nstr: %s\n", str);

	if (str) {
		int n = mx_strlen(str);
		c = mx_get_char_index(str, delim);
		if (c != -1) {
			count += c;
			mx_strncat(*lineptr, str, c);
			str = mx_strncpy(mx_strnew(n - c - 1), str + c + 1, n - c - 1); ////
			return count;
		}
		count += n;
		mx_strncat(*lineptr, str, n);
	}

	for (size = read(fd, buf, buf_size); size; size = read(fd, buf, buf_size)) {
		c = mx_get_char_index(buf, delim);
		if (c != -1) {
			count += c;
			mx_strncat(*lineptr, buf, c);
			str = mx_strncpy(mx_strnew(size - c - 1), buf + c + 1, size - c - 1);
			return count;
		}
		count += size;
		mx_strncat(*lineptr, buf, size);
	}
	return count;
}

// int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
// 	static t_read_line p = {.data = NULL, .fd_stat = -1000};
// 	int count = 0;
// 	int c;

// 	if (buf_size < 1)
// 		return -2;
// 	if (p.fd_stat != fd) {
// 		free(p.data);
// 		p.data = NULL;






// 	}
// 	p.fd_stat = fd;

// 	if (p.data) {
// 		int n = mx_strlen(p.data);
// 		c = mx_strchr(p.data, delim, n);

// 		if (c != -1) {
// 			mx_memjoin(*lineptr, p.data, count, c);
// 			count += c;
// 			if (n - c - 1 != 0) {
// 				char *str = (char *) malloc(sizeof(char) * (n - c - 1));
// 				for (int i = 0; i < n - c - 1; i++)
// 					str[i] = p.data[1 + c + i];
// 				free(p.data);
// 				p.data = str;
// 			}
// 			return count;
// 		}
// 		mx_memjoin(*lineptr, p.data, count, n);
// 		count += n;
// 		free(p.data);
// 		p.data = NULL;
// 	}

// 	char temp[buf_size];
// 	int size = read(fd, temp, buf_size);

// 	if (size == -1) {
// 		free(p.data);
// 		p.data = NULL;
// 		return -2;
// 	}
// 	else if (size == 0 && count == 0) {
// 		return -1;
// 	}

// 	while (size > 0) {
// 		c = mx_strchr(temp, delim, size);
// 		if (c != -1) {
// 			mx_memjoin(*lineptr, temp, count, c);
// 			count += c;
// 			if (size - c - 1 != 0) {
// 				p.data = (char *) malloc(sizeof(char) * (size - c - 1));
// 				for (int i = 0; i < size - c - 1; i++)
// 					p.data[i] = temp[1 + c + i];
// 			}
// 			return count;
// 		}
// 		mx_memjoin(*lineptr, temp, count, size);
// 		count += size;
// 		size = read(fd, temp, buf_size);
// 	}
// 	return count;
// }




