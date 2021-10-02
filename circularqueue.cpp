#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


/*
This is a circular queue implementation
*/


using namespace std;
int const size=100;
int frnt=-1,rear=-1,flag=0;
int queue[size];

void create(int q[])
{
	if(frnt!=-1)
	{
	    cout<<"Queue is already Created\n";
	    system("pause");
	}
	else
	{
	    frnt=0;
	    cout<<"\n Queue Created\n";
		system("pause");
	}

}

int insertq(int q[],int n)
{
    if(frnt==-1)
	{
		cout<<"\nQueue is not created\n";
		system("pause");
	}
	else if(rear!=-1 && frnt==rear+1 || frnt==0&&rear==n-1)
	{
		cout<<"\n------------Overflow-----------\n";
		system("pause");
	}
	else
	{
		int data;
		cout<<"Enter integer data:\n";
		cin>>data;
		if(rear==n-1)
		{
		    rear=0;
		    q[rear]=data;
		    cout<<"\nItem inserted\n";
            system("pause");
		}
		else
		{
		    rear++;
			q[rear]=data;
			cout<<"\nItem inserted\n";
            system("pause");
		}
	}
	return 0;
}

void deleteq(int q[],int n)
{
	int i,item;
	if(rear==-1)
	{
		cout<<"\n-------Underflow------\n";
		system("pause");
	}
	else if(frnt==rear)
	{
	    item=q[rear];
	    frnt=-1;
	    rear=-1;
	    cout<<"\nItem removed = "<<item<<"\n Queue Deleted\n";
	    system("pause");
	}
	else if(frnt==n)
	{
	    item=q[frnt];
		frnt=1;
		cout<<"\nItem Deleted = "<<item<<endl;
		system("pause");
	}
	else
	{
	    item=q[frnt];
		frnt++;
		cout<<"\nItem Deleted = "<<item<<endl;
		system("pause");
	}

}


void display(int q[],int n)
{
	int i;
	if(frnt==-1)
	{
		cout<<"\nQueue is not created\n";
	}
	else if(frnt<rear)
	{
		for(i=frnt;i<=rear;i++)
		{
			cout<<q[i]<<" ";
		}
		cout<<endl;
    }
    else if(frnt==rear)
    {
        cout<<q[frnt]<<endl;
    }

	else
	{
		for(i=0;i<=rear;i++)
		{
		    cout<<q[i]<<" ";
		}
		for(i=frnt;i<n;i++)
		{
		    cout<<q[i]<<" ";
		}
        cout<<endl;
    }
    system("pause");
}


int main()
{
	int data;
	char choic;
	int n;
	cout<<"Enter Size of Queue\n";
	cin>>n;
	cout<<endl;
	while(1)
        {
            system("cls");

            cout<<"1. Create \n"
            <<"2. Insert \n"
            <<"3. Delete \n"
            <<"4. Display\n"
            <<"5. Exit\n";
            fflush(stdin);
            choic = getche();
            cout<<endl;
            switch(choic)
            {
            case '1':
                create(queue);
                break;

            case '2':
                insertq(queue,n);
                break;

            case '3':
                deleteq(queue, n);
                break;

            case '4':
                display(queue, n);
                break;

            case '5':
                exit(1);

            }
}
}
