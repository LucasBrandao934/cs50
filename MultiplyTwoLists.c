#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node *newNode(int data)
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = newNode(new_data);

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

long long multiplyTwoLists (struct Node* first,struct Node* second)
{
    long long N = 1000000007;
    long long num1 = 0, num2 = 0;
    while (first || second){

        if(first){
            num1 = ((num1)*10)%N + first->data;
            first = first->next;
        }

        if(second)
        {
            num2 = ((num2)*10)%N + second->data;
            second = second->next;
        }

    }
    return ((num1%N)*(num2%N))%N;
}

void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d",node->data);
        if(node->next)
            printf("->");
        node = node->next;
    }
    printf("\n");
}

int main()
{
    struct Node* first = NULL;
    struct Node* second = NULL;

    push(&first, 7);
    push(&first, 3);
    push(&first, 8);
    printf("A primeira lista é: ");
    printList(first);

    push(&second, 2);
    push(&second, 4);
    printf("A segunda lista é: ");
    printList(second);

    printf("O resultado é: ");
    long long ans = multiplyTwoLists(first, second);
    printf("%lld",ans);

    return 0;
}