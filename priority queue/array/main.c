#include<stdio.h>
#include<stdlib.h>
#include <time.h>
/*priority queue implementation using array*/

#define N 20

int queue[N],priority[N];
int rear = -1,front = -1;

int is_full()
{
    if(front==0 && rear==N-1)
    {
        return 1;
    }
    return 0;
}

int is_empty()
{
    if(front==-1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int data,int p)
{
    if(is_full())
    {
        printf("Queue is full\n");
        return;
    }

    if(front==-1)
    {
        front = rear = 0;
        queue[rear] = data;
        priority[rear] = p;
    }
    else if(rear == N-1)
    {
        int i;
        for(i=front; i<=rear; i++)
        {
            queue[i-front] = queue[i];
            priority[i-front] = priority[i];
            rear = rear-front;
            front = 0;
            for(i = rear; i>front; i--)
            {
                if(p>priority[i])
                {
                    queue[i+1] = queue[i];
                    priority[i+1] = priority[i];
                }
                else
                    break;
                queue[i+1] = data;
                priority[i+1] = p;
                rear++;
            }
        }
    }
    else
    {
        int i;
        for(i = rear; i>=front; i--)
        {
            if(p>priority[i])
            {
                queue[i+1] = queue[i];
                priority[i+1] = priority[i];
            }
            else
                break;
        }
        queue[i+1] = data;
        priority[i+1] = p;
        rear++;
    }
}

void dequeue()
{
    if(is_empty())
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Element deleted is %d and its Priority is %d\n",queue[front],priority[front]);
    if(front==rear)
        front = rear = -1;
    else
        front++;
}

void peek()
{
    if(is_empty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The element is %d its priority %d\n",queue[front],priority[front]);
}

int main()
{
    int opt,data,p;
    while(1)
    {
        system("cls");
        printf("====================================================\n");
        printf("                    MAIN MENU\n");
        printf("====================================================\n");
        printf("[1]IsFull\n");
        printf("[2]IsEmpty\n");
        printf("[3]Insert\n");
        printf("[4]Delete\n");
        printf("[5]Peek\n");
        printf("[6]Exit\n");
        printf("::");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            if(is_full())
                printf("The Queue is full\n");
            else
                printf("The Queue is not full\n");
            break;
        case 2:
            if(is_empty())
                printf("The queue is empty\n");
            else
                printf("The queue is not empty\n");
            break;
        case 3:
            printf("Enter your Priority and data\n");
            scanf("%d %d",&p,&data);
            enqueue(data,p);
            break;
        case 4:
            dequeue();
            break;
        case 5:
            peek();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Incorrect Choice\n");
        }
        system("pause");
    }
    return 0;
}
