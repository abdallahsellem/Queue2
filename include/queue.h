#ifdef Queue_Array_Based

#define max_size 1000
struct queue
{
    int arr[max_size];
    int rear;
        int front;
        int size;
};

void create_queue( queue *pt);

void enqueue(int value, queue* pt);

int dequeue(queue* pt);
int peek(queue* pt);
int empty_queue(queue *pt);
int queue_size(queue *pt);
int queue_full(queue* pt);
void clear_queue(queue* pt);
void Display_queue(queue* pt);

#else

struct node {
    node* next;
    int data;
};
struct queue {
    node* front;
    node* rear;
    int size;
};
void create_queue(queue *pq);
void enqueue(int value,queue *pq);
int queue_size(queue* pq);
int dequeue(queue* pq);
void display(queue *pq);
void clear_queue(queue* pq);
int peek(queue* pq);
bool queue_empty(queue* pq);

#endif