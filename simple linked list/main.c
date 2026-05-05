//C compiler to run C program
#include <stdio.h>
#include<stdlib.h>
struct node{
    int page;
    struct node *link;
};
int main() {
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));

    head->page=45;
    head->link=NULL;

    printf("%d",head->page);
    return 0;
}
