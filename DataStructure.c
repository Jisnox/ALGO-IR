#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define empty NULL

typedef struct cell {
    int head;
    struct cell* tail;
} *list;

list add(int h, list t) {
    list l = malloc(sizeof(struct cell));
    l->head = h; l->tail = t;
    return l;
}

void print_list(list l) {
    list p = l;
    printf("(");
    while (p != empty) {
        printf("%i", p->head);
        p = p->tail;
        if (p != empty) printf(" ");
    }
    printf(")\n");
}

int has(int v, list l) {
    if (l == empty) return 0;
    if (v == l->head) return 1;
    return has(v, l->tail);
}

list inter(list l1, list l2) {
    list l = empty;
    list p = l1;
    while (p != empty) {
        if (has(p->head, l2)) l = add(p->head, l);
        p = p->tail;
    }
    return l;
}

list rev(list l1) {
    list l = empty;
    list p = l1;
    while (p != empty) {
        l = add(p->head, l);
        p = p->tail;
    }
    return l;
}

list cat(list l1, list l2) {
    list l = empty;
    list p = l1;
    while (p != empty) {
        l = add(p->head, l);
        p = p->tail;
    }
    p = l2;
    while (p != empty) {
        l = add(p->head, l);
        p = p->tail;
    }
    return rev(l);
}

typedef struct sstack {
    int tab[100];
    int ptr;
} *stack;

stack new_stack() {
    stack s = malloc(sizeof(struct sstack));
    s->ptr = 0;
    return s;
}

void push(stack s, int x) {
    s->tab[s->ptr] = x;
    s->ptr++;
}

int pop(stack s) {
    s->ptr--;
    return s->tab[s->ptr];
}

int peek(stack s) {
    return s->tab[s->ptr - 1];
}

void add_stack(stack s) {
    int v2 = pop(s);
    int v1 = pop(s);
    push(s, v1 + v2);
}
void sub(stack s) {
    int v2 = pop(s);
    int v1 = pop(s);
    push(s, v1 - v2);
}

void mult(stack s) {
    int v2 = pop(s);
    int v1 = pop(s);
    push(s, v1 * v2);
}

void dup(stack s) {
    int v = peek(s);
    push(s, v);
}

void swap(stack s) {
    int v2 = pop(s);
    int v1 = pop(s);
    push(s, v2);
    push(s, v1);
}

typedef struct qqueue {
    list front;
    list back;
} *queue;

queue new_queue() {
    queue q = malloc(sizeof(struct qqueue));
    q->front = empty;
    q->back = empty;
    return q;
}

void enqueue(queue q, int x) {
    list newNode = add(x, empty);
    if (q->front == empty) {
        q->front = newNode;
        q->back = newNode;
    } else {
        q->back->tail = newNode;
        q->back = newNode;
    }
}

int dequeue(queue q) {
    int v = q->front->head;
    q->front = q->front->tail;
    if (q->front == empty) q->back = empty;
    return v;
}

typedef struct darray {
    int *data;
    int size;
    int capacity;
} *array;

array new_array(int cap) {
    array a = malloc(sizeof(struct darray));
    a->capacity = cap;
    a->size = 0;
    a->data = malloc(cap * sizeof(int));
    return a;
}

void insert_array(array a, int val) {
    if (a->size >= a->capacity) {
        a->capacity *= 2;
        a->data = realloc(a->data, a->capacity * sizeof(int));
    }
    a->data[a->size] = val;
    a->size++;
}

typedef struct htable {
    list *buckets;
    int size;
} *hashtable;

hashtable new_hashtable(int size) {
    hashtable ht = malloc(sizeof(struct htable));
    ht->size = size;
    ht->buckets = malloc(size * sizeof(list));
    for (int i = 0; i < size; i++) {
        ht->buckets[i] = empty;
    }
    return ht;
}

int hash(int key, int size) {
    return key % size;
}

void insert_hash(hashtable ht, int val) {
    int index = hash(val, ht->size);
    ht->buckets[index] = add(val, ht->buckets[index]);
}

int search_hash(hashtable ht, int val) {
    int index = hash(val, ht->size);
    return has(val, ht->buckets[index]);
}

void main() {
    printf("Test Lists\n");
    list l1 = add(1, add(2, add(3, empty)));
    list l2 = add(3, add(4, empty));
    printf("l1: "); print_list(l1);
    printf("l2: "); print_list(l2);
    printf("inter: "); print_list(inter(l1, l2));

    printf("Test Stack\n");
    stack s = new_stack();
    push(s, 10);
    push(s, 20);
    add_stack(s);
    printf("Top of stack after add: %d\n", pop(s));

    printf("Test Queue\n");
    queue q = new_queue();
    enqueue(q, 100);
    enqueue(q, 200);
    printf("Dequeue: %d\n", dequeue(q));

    printf("Test Hash Table\n");
    hashtable ht = new_hashtable(10);
    insert_hash(ht, 42);
    insert_hash(ht, 12);
    printf("Has 42 in hash? %s\n", search_hash(ht, 42) ? "Yes" : "No");
    printf("Has 99 in hash? %s\n", search_hash(ht, 99) ? "Yes" : "No");
    return;
}
