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
int peek(int pos, struct node*top){
    struct node*ptr = top;
    for(int i =0; i<pos-1 && ptr != NULL; i++){
        ptr= ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}
int stacktop(struct node*top){
    if(empty(top)){
        return -1;
    }
    else{
        printf("the top element of stack is %d\n", top->data);
        }
}
int stackbottom(struct node*top){
    struct node*ptr = top;
    while(ptr->next!= NULL){
        ptr = ptr->next;
    }
    printf("the last element of stack is %d\n", ptr->data);
}
int main(){
    struct node*top = NULL;
    top = push(78, top);
    top = push(98, top);
    top = push(43, top);
    top = push(77, top);
    top = push(90, top);
    top = push(61, top);
    top = push(67, top);
    top = push(97, top);
    int elemnt =pop(&top);
    printf("element removed %d\n", elemnt);
    int element =pop(&top);
    printf("element removed %d\n", element);
    traversal(top);
    int k = peek(3,top);
    printf("The peeked element is %d\n", k);
    stackbottom(top);
    stacktop(top);
    return 0;
}
