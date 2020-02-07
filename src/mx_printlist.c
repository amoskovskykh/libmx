#include "../inc/libmx.h"

void mx_printlist(t_list *p) {
    if (p == NULL)
        return;
    t_list *ptr = p;
    for (; ptr->next != NULL; ptr = ptr->next) {
        mx_printstr(ptr->data);
        mx_printstr(" ");
    }
    mx_printstr(ptr->data);
}
