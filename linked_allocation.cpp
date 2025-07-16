#include <stdio.h>
#include <stdlib.h>


struct block {
    int number;
    struct block* next;
};

struct block* createblock(int num) {
    struct block* newblock = (struct block*)malloc(sizeof(struct block));
    newblock->number = num;
    newblock->next = NULL;
    return newblock;
}

int main() {
    struct block* head = NULL;
    struct block* current = NULL;

  
    head = createblock(10);
    head->next = createblock(20);
    head->next->next = createblock(30);

    printf("Allocated Blocks: ");
    current = head;
    while (current != NULL) {
        printf("%d", current->number);
        if (current->next != NULL) {
            printf(" -> "); 
        }
        current = current->next;
    }
    printf("\n");


    current = head;
    while (current != NULL) {
        struct block* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

