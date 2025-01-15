#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node*next;
};
void traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("elements %d \n", ptr->data);
        ptr = ptr->next;
    }
}
int empty(struct node*top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int full(struct node*top){
    struct node*p = (struct node*)malloc(sizeof(struct node));
    if(p == NULL){
        return 1;
    }
    else {
        return 0;
    }
}
struct node* push(int x, struct node*top){
    if(full(top)){
        printf("overflow");
    }
    else{
        struct node*n = (struct node*)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top; 
    }
}
int pop(struct node**top){
    if(empty(*top)){
        printf("underflow");
    }
    else{
        struct node*n = *top;
        *top = (*top)->next;
        int x = n-> data;
        free (n);
        return x;
    }
}
int main(){
    struct node*top = NULL;
    top = push(78, top);
    top = push(98, top);
    top = push(43, top);
    top = push(25, top);
    int element =pop(&top);
    printf("element removed %d\n", element);
    traversal(top);
    return 0;
}
