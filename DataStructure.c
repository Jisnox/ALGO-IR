#include "basics.h"

DynamicArray newDynamicArray(int capacity) {
    DynamicArray arr;
    arr.capacity = capacity;
    arr.size = 0;
    arr.data = malloc(capacity * sizeof(int));
    return arr;
}


Stack newStack(int N) {
    Stack s;
    s.N = N;
    s.n = 0;
    s.S = malloc(s.N * sizeof(int));
    return s;
}

void push(Stack *s, int x) {
    if (s->n >= s->N) {
        printf("Stack is full\n");
        return;
    }
    s->S[s->n] = x;
    s->n++;
}

int pop(Stack *s) {
    if (s->n == 0) {
        printf("Stack is empty\n");
        return -1; 
    }
    s->n--;
    return s->S[s->n];
}

int peekStack(Stack *s) { 
    if (s->n == 0) {
        printf("Out of Stack\n");
        return -1;
    }
    return s->S[s->n - 1];
}

void enqueue(Queue *q, int x) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = x;
    newNode->next = NULL;
    if (q->back == NULL) {
        q->front = newNode;
        q->back = newNode;
    } else {
        q->back->next = newNode;
        q->back = newNode;
    }
}

int dequeue(Queue *q) {
    if (q->front == NULL) {
        return -1; 
    }
    Node *temp = q->front;
    int x = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->back = NULL;
    }
    free(temp);
    return x;
}

int peekQueue(Queue *q) { 
    if (q->front == NULL) return -1;
    return q->front->data;
}

HashTable newHashTable(int size) {
    HashTable ht;
    ht.size = size;
    ht.buckets = calloc(size, sizeof(Node*)); 
    return ht;
}

int Hash(char key[], int size) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum = sum + key[i];
    }
    return sum % size;
}

void insertHash(HashTable *ht, char key[], int value) {
    int index = Hash(key, ht->size);
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = value;
    newNode->next = ht->buckets[index]; 
    ht->buckets[index] = newNode;
}

int main() {
    Stack s = newStack(5);
    push(&s, 10);
    printf("Top of stack: %d\n", peekStack(&s));
    
    return 0;
}
