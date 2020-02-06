#include "../inc/libmx.h"

// _Bool bmx_strcmp(char *s1, char *s2) {
//     return (*s1 > *s2) ? true : false;
// }

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)){
    if (!lst )
        return lst;
    void *c;
    for (t_list *i = lst; i -> next; i = i -> next)
        for (t_list *j = i -> next; j; j = j -> next)
            if (cmp(i -> data, j -> data)){
                c = i -> data;
                i -> data = j -> data;
                j -> data = c;
            }
    return lst;
}
