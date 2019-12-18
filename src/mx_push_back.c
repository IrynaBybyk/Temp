//
// Created by Oleg Berdyshev on 10/25/19.
//
#include "libmx.h"

void mx_push_back(t_list **head, void *data) {
    t_list *new_node = mx_create_node(data);
    t_list *cur = NULL;

    if (head == NULL) 
        return;
    if (*head == NULL) {
        *head = new_node;
    }
    else {
        for (cur = *head; cur->next != NULL; cur = cur->next);
        cur->next = new_node;
    }
}

