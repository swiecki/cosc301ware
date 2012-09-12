#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[128];
    struct node *next; 
};

void insert(char *name, struct node **phead) {
	struct node *newnode = malloc(sizeof(struct node));
	strncpy(newnode->name, name, 128);
	newnode->next = *phead;
	*phead = newnode;
}

void print_list(struct node *list) {
    int i = 0;
    printf("\n\nDumping list\n");
    while (list != NULL) {
        printf("%d: %s\n", i+1, list->name);
        list = list->next;
    }
}

void clear_list(struct node *list) {
    while (list != NULL) {
        struct node *tmp = list;
        list = list->next;
        free(tmp);
    }
}

int main(int argc, char **argv)
{
    char buffer[128];

    struct node *head = NULL;

    printf("Next string to add: ");
    fflush(stdout);
    while (fgets(buffer, 128, stdin) != NULL) {

        insert(buffer, &head);

        printf("Next string to add: ");
        fflush(stdout);
    }

    print_list(head);
    clear_list(head);

    return 0;
}
