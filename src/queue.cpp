#include<iostream>
using namespace std ;
#ifdef Queue_Array_Based
#include "../include/queue.h"

void create_queue( queue *pt)
{
    pt->rear = -1;
    pt->front = -1;
    pt->size = 0;
}

void enqueue(int value, queue * pt)
{
    pt->arr[++pt->rear%max_size] = value;
    pt->size++;
    if (pt->front == -1)
    {
        pt->front++;
    }

}

int dequeue(queue* pt)
{
    int value_front = pt->arr[pt->front];
    pt->size--;
    pt->front = (pt->front + 1) % max_size;
    return value_front;
}
int peek(queue* pt)
{
    return pt->arr[pt->front];
}
int empty_queue(queue *pt)
{
    return !pt->size;
}
int queue_size(queue *pt)
{
    return pt->size;
}
int queue_full(queue* pt)
{
    return pt->size == max_size;

}
void clear_queue(queue* pt)
{
    pt->size = 0;
    pt->front = -1;
    pt->rear = -1;
}
void Display_queue(queue* pt)
{
    int pos = pt->front;

    while (pos != pt->rear)
    {
        cout << pt->arr[pos] << endl;
        pos = pos + 1 % max_size;
    }
    if (pt->size != 0)
    {
        cout << pt->arr[pos] << endl;
    }

}

#else
#include "../include/queue.h"
void create_queue(queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
    
}

void enqueue(int value,queue *pq)
{
    node* pt = new node;
    pt->next = NULL;
    pt->data = value;

    if (pq->rear==NULL)
    {
        pq->front = pt;

    }
    else
    {
        pq->rear->next = pt;
    }
    pq->rear = pt;
    pq->size++;
}
int queue_size(queue* pq)
{

    return pq->size;
}
int dequeue(queue* pq)
{
    node* pt = pq->front;
    pq->front = pq->front->next;
    int value = pt->data;
    if (pq->front == NULL)
    {
        pq->rear = NULL;
    }
    delete pt;
    pq->size--;
    return value;
}
void display(queue *pq)
{
    node* pt = pq->front;
    while (pt != pq->rear)
    {
        cout << pt->data << " ";
        pt = pt->next;
    }
    if (pq->rear != NULL)
    {
        cout << pt->data;
    }
}
void clear_queue(queue* pq)
{
    node* pt = pq->front;
    node* temp = pt;
    while (pt != pq->rear)
    {
        pt = pt->next;
        delete temp;
        temp = pt;

    }
    if (pq->rear != NULL)
    {
        delete pt;
    }
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}
int peek(queue* pq)
{
    return pq->front->data;
}
bool queue_empty(queue* pq)
{
    return !pq->size;
}


#endif