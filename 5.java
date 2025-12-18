/*
5. Demonstrate a Generic Stack in Java. The program shall define a generic Stack class using
Java Generics and a Student class to demonstrate storing user-defined objects inside a
generic stack. Ensure to demonstrate following concepts:
i) Generic Class with Type Parameter <E>
ii) Type Safety (no explicit casting)
iii) Generic Array Creation using Type Casting
iv) Use of Generic Methods (push, pop, hasElements)
v) Custom Object Handling with Generics
*/
class Student {
    int id;
    String name;

    Student(int id, String name) {
        this.id = id;
        this.name = name;
    }

    void display() {
        System.out.println("ID: " + id + ", Name: " + name);
    }
}


class Stack<E> {
    private E[] stack;
    private int top = -1;
    private int size;

    @SuppressWarnings("unchecked")
    Stack(int size) {
        this.size = size;
        stack = (E[]) new Object[size]; // Generic array creation
    }

    void push(E element) {
        if (top == size - 1) {
            System.out.println("Stack Overflow");
            return;
        }
        stack[++top] = element;
    }

    E pop() {
        if (top == -1) {
            System.out.println("Stack Underflow");
            return null;
        }
        return stack[top--];
    }

    boolean hasElements() {
        return top != -1;
    }
}


public class GenericStackDemo {
    public static void main(String[] args) {

        Stack<Student> studentStack = new Stack<>(3);

        studentStack.push(new Student(1, "Sunil"));
        studentStack.push(new Student(2, "Ravi"));
        studentStack.push(new Student(3, "Anil"));

        System.out.println("Popped elements:");
        while (studentStack.hasElements()) {
            Student s = studentStack.pop();
            s.display();
        }
    }
}

