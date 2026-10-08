#ifndef BASICS_H
#define BASICS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int capacity;
    int size;
} DynamicArray;

typedef struct Node {
    int data;            
    struct Node *next;    
} Node;

typedef struct {
    int N; 
    int n;  
    int *S; 
} Stack;

typedef struct {
    Node *front;
    Node *back;
} Queue;

typedef struct {
    int size;      
    Node **buckets;  
} HashTable;

DynamicArray newDynamicArray(int capacity);

Stack newStack(int N);
void push(Stack *s, int x);
int pop(Stack *s);
int peekStack(Stack *s); 

void enqueue(Queue *q, int x);
int dequeue(Queue *q);
int peekQueue(Queue *q);

HashTable newHashTable(int size);
int Hash(char key[], int size);
void insertHash(HashTable *ht, char key[], int value);

#endif
