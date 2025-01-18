#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int empty(struct stack *ptr){
    if(ptr -> top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int full(struct stack*ptr){
    if(ptr ->top == ptr-> size-1 ){
        return 1;
    }
    else {
        return 0;
    }
}
void push(struct stack*ptr , int value){
    if(full(ptr)){
        printf("stack overflow \n");
    }
    else{
        ptr -> top ++;
        ptr -> arr[ptr->top]= value;
    }
}
int pop(struct stack*ptr){
    if(empty(ptr)){
        printf("stack underflow");
        return -1;
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr-> top--;
        return value;
    }
}
int peek(struct stack*s, int i){
    if(s->top - i+1 <0){
        printf("invalid position \n");
        return -1;
    }
    else{
        return (s-> arr[s->top - i +1]);
    }
}
int stacktop(struct stack*s){
    return( s-> arr[s->top]);
}
int stackbottom(struct stack*s){
    return(s->arr[0]);
}
int main(){
    struct stack *s= (struct stack*)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr= (int*)malloc(s->size *sizeof(int));
    printf("stack has been created succesfully \n");
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 0);
    pop(s);
    for(int j = 1; j<=s->top+1; j++){
        printf("%d\n", peek(s,j));
    }
    printf("The top most elemnet of stack is %d\n", stacktop(s));
    printf("The bottom most elemnet of stack is %d\n", stackbottom(s));
    return 0;
}
