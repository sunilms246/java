/*1. Create both fixed and dynamic stack by implementing interface that defines push and pop
methods.
*/
// Interface
interface Stack {
    void push(int x);
    int pop();
}

// Fixed Stack
class FixedStack implements Stack {

    int s[] = new int[3];
    int top = -1;

    public void push(int x) {
        if (top == s.length - 1) {
            System.out.println("Fixed Stack Overflow");
            return;
        }
        s[++top] = x;
    }

    public int pop() {
        if (top == -1) {
            System.out.println("Fixed Stack Underflow");
            return -1;
        }
        return s[top--];
    }
}

// Dynamic Stack
class DynamicStack implements Stack {

    int s[] = new int[2];
    int top = -1;

    public void push(int x) {
        if (top == s.length - 1) {
            int temp[] = new int[s.length * 2];
            for (int i = 0; i < s.length; i++)
                temp[i] = s[i];
            s = temp;
        }
        s[++top] = x;
    }

    public int pop() {
        if (top == -1) {
            System.out.println("Dynamic Stack Underflow");
            return -1;
        }
        return s[top--];
    }
}

// Test Class
class StackDemo {
    public static void main(String[] args) {

        Stack s;

        s = new FixedStack();
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);   // overflow
        System.out.println("Popped: " + s.pop());

        s = new DynamicStack();
        s.push(1);
        s.push(2);
        s.push(3);    // auto resize
        System.out.println("Popped: " + s.pop());
    }
}
