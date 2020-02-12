#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter) {
    int rez = 0;

    if (str == NULL)
        return -1;
    if (delimiter)
        return 1;
    for (int i = 0; str[i]; i++)
        if (str[i] != delimiter)
            for (rez++; (str[i + 1] != delimiter) && str[i + 1]; i++);
    return rez;
}
