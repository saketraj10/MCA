import java.util.Scanner;
class Stack
{
    private int maxSize;
    private int[] stackArray;
    private int top;

    Stack(int size)
    {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    boolean isFull()
    {
        return top==maxSize-1;
    }

    boolean isEmpty()
    {
        return top == -1;
    }

    static void push(Stack s1, int item)
    {
        if(s1.isFull()){
            System.out.println("Stack is full, cannot push item.");
        }
        else{
            s1.stackArray[++s1.top] = item;
        }
    }

    static void pop(Stack s1){
        if(s1.isEmpty())
        {
            System.out.println("Stack is empty, cannot pop item.");
        }
        else
        {
            int item = s1.stackArray[s1.top--];
            System.out.println("Popped item: " + item);
        }
    }

    void display()
    {
        System.out.println("display stack item: ");
        if(isEmpty())
        {
            System.out.println("Stack is empty.");
        }
        else
        {
            for(int i=top; i>=0; i--){
                System.out.println(stackArray[i]);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of stack: ");
        int s = sc.nextInt();

        Stack s1 = new Stack(s);

        int ch;
        do
        {
            System.out.println("1. Item push into stack.");
            System.out.println("2. Item pop from stack.");
            System.out.println("3. Display the stack.");
            System.out.print("Enter the choice and 0 for exit: ");
            ch = sc.nextInt();
            switch(ch)
            {
                case 1:
                    System.out.print("Enter the item value push into stack: ");
                    int ele = sc.nextInt();
                    push(s1,ele);
                    break;
                case 2:
                    pop(s1);
                    break;
                case 3:
                    s1.display();
                    break;
                case 0:
                    return;
                default:
                    System.out.println("invalid input");
            }
        }while(ch!=0);

        sc.close();

    }
}