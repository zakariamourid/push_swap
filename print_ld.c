#include "push_swap.h"

void print_ld(t_data *head, const char *str) {
    int i = 0;
    
    if (str) {
        printf("----------- Stack %s -----------\n", str);
    }
    
    if (!head) {
        printf("The list is empty.\n");
        return;
    }

    printf("+-----+-------+\n");
    printf("|  #  | Value |\n");
    printf("+-----+-------+\n");
    
    while (head) {
        printf("| %3d | %5d |\n", i, head->value);
        head = head->next;
        i++;
    }
    
    printf("+-----+-------+\n");
}
