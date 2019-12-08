#include "libmx.h"

char *mx_file_to_str(const char *file) {
	char *str;
	int fd = open(file, 'r');
	int len = 0;
	
	if (fd < 0)
		return NULL;
	for (char buf; read(fd, &buf, sizeof(char)) == sizeof(char); len++);
	close(fd);
	fd = open(file, 'r');
	if (fd < 0)
		return NULL;
	str = mx_strnew(len);
	if (str)
		read(fd, str, len * sizeof(char));
	close(fd);
	return str;
}

// int main()
// {
// 	printf("%s\n", mx_file_to_str("test.txt"));
// }
