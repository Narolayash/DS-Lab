    // 34. Write a menu driven program to implement following operations on the Stack 
    // using an Array 
    // • PUSH, POP, DISPLAY 
    // • PEEP, CHANGE 

    #include <stdio.h>

    // PUSH
    void push(int stack[], int size, int* top, int val) {
        if(*top >= size) {
            printf("stack overflow \n");
            return;
        }

        stack[++(*top)] = val;
    }

    // POP
    int pop(int stack[], int*top) {
        
        if(*top <= -1) {
            printf("stack underflow \n");
            return -1;
        }
        else
            return (stack[(*top)--]);
    }

    // DISPLAY
    void display(int stack[], int top) {
        if(top <= -1) {
            printf("stack underflow \n");
            return;
        }
            
        for(int i=top; i>=0; i--) {
            printf("%d \n", stack[i]);
        }
    }

    // PEEP
    int peep(int stack[], int top, int fromTop) {
        if((top-fromTop+1) < 0) {
            printf("stack underflow \n");
            return -1;
        }
        else 
            return stack[top-fromTop+1];
    }

    // CHANGE
    void change(int stack[], int top, int fromTop, int changeVal) {
        if((top-fromTop+1) < 0) 
            printf("stack underflow \n");

        else 
            stack[top-fromTop+1] = changeVal;
    }

    int main() {
        int stack[50], top = -1;
        int size = sizeof(stack) / sizeof(stack[0]);
        int choice, val, pos;
        while (1) {
            printf("\n1.Push\n2.Pop\n3.Display\n4.Peep\n5.Change\n6.Exit\nEnter choice: ");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    printf("Enter value to push: ");
                    scanf("%d", &val);
                    push(stack, size, &top, val);
                    break;
                case 2:
                    printf("Popped: %d\n", pop(stack, &top));
                    break;
                case 3:
                    display(stack, top);
                    break;
                case 4:
                    printf("Enter position from top: ");
                    scanf("%d", &pos);
                    printf("Peeped value: %d\n", peep(stack, top, pos));
                    break;
                case 5:
                    printf("Enter position from top and new value: ");
                    scanf("%d %d", &pos, &val);
                    change(stack, top, pos, val);
                    break;
                case 6:
                    return 0;
                default:
                    printf("Invalid choice!\n");
            }
        }
    }