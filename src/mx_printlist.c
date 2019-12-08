#include "libmx.h"

void mx_printlist(t_list *p) {
    t_list *ptr = p;
    for (int i = 0; ptr -> next != NULL; i++) {
        //printf("%s ", ptr -> data);
        ptr = ptr -> next;
    }
    //printf("%s\n", ptr -> data);
}
