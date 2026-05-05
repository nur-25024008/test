#include <stdio.h>

#define MAX_NODES 100
#define NULL_INDEX -1

typedef struct {
    int data;
    int next;  /* index of the next node in the array, or -1 */
} Node;

static Node nodes[MAX_NODES];
static int head = NULL_INDEX;      /* index of first element in the list */
static int free_head = 0;          /* index of first free node */

void init_list(void) {
    int i;
    head = NULL_INDEX;
    for (i = 0; i < MAX_NODES - 1; ++i) {
        nodes[i].next = i + 1;
    }
    nodes[MAX_NODES - 1].next = NULL_INDEX;
    free_head = 0;
}

int alloc_node(void) {
    if (free_head == NULL_INDEX) {
        return NULL_INDEX; /* no free nodes left */
    }
    int idx = free_head;
    free_head = nodes[free_head].next;
    nodes[idx].next = NULL_INDEX;
    return idx;
}

void free_node(int idx) {
    nodes[idx].next = free_head;
    free_head = idx;
}

/* Insert at the beginning of the list */
int insert_front(int value) {
    int idx = alloc_node();
    if (idx == NULL_INDEX) {
        return 0; /* failure */
    }
    nodes[idx].data = value;
    nodes[idx].next = head;
    head = idx;
    return 1; /* success */
}

/* Insert at the end of the list */
int insert_end(int value) {
    int idx = alloc_node();
    int current;

    if (idx == NULL_INDEX) {
        return 0; /* failure */
    }

    nodes[idx].data = value;
    nodes[idx].next = NULL_INDEX;

    if (head == NULL_INDEX) {
        head = idx;
        return 1;
    }

    current = head;
    while (nodes[current].next != NULL_INDEX) {
        current = nodes[current].next;
    }
    nodes[current].next = idx;
    return 1;
}

/* Delete first occurrence of value */
int delete_value(int value) {
    int current = head;
    int prev = NULL_INDEX;

    while (current != NULL_INDEX) {
        if (nodes[current].data == value) {
            if (prev == NULL_INDEX) {
                head = nodes[current].next;
            } else {
                nodes[prev].next = nodes[current].next;
            }
            free_node(current);
            return 1; /* deleted */
        }
        prev = current;
        current = nodes[current].next;
    }
    return 0; /* not found */
}

void print_list(void) {
    int current = head;
    printf("List: ");
    while (current != NULL_INDEX) {
        printf("%d ", nodes[current].data);
        current = nodes[current].next;
    }
    printf("\n");
}

int main(void) {
    init_list();

    insert_end(10);
    insert_end(20);
    insert_front(5);
    insert_end(30);

    print_list(); /* expected: 5 10 20 30 */

    delete_value(20);
    print_list(); /* expected: 5 10 30 */

    delete_value(5);
    print_list(); /* expected: 10 30 */

    return 0;
}