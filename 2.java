/*
2. Consider a Student Management System that demonstrates
i) Exception handling using built-in exceptions. The system should simulate various real-
time errors such as:
- Invalid marks entry (ArithmeticException)
- Missing or null student records (NullPointerException)
- Unauthorized access to confidential student data (IllegalAccessException)
- Unexpected failures during result processing (RuntimeException)
- File reading or loading failures (IOException)
ii) Create a Custom Exception "InvalidMarksException" that is Thrown when a student’s 
marks are entered as negative or greater than 100.
  */




import java.io.*;

// Custom Exception
class InvalidMarksException extends Exception {
    public InvalidMarksException(String message) {
        super(message);
    }
}

class Student {
    String name;
    int marks;

    Student(String name, int marks) {
        this.name = name;
        this.marks = marks;
    }
}

public class StudentManagementSystem {

    // Method to validate marks
    static void validateMarks(int marks) throws InvalidMarksException {
        if (marks < 0 || marks > 100) {
            throw new InvalidMarksException("Marks must be between 0 and 100");
        }
    }

    // Method to simulate unauthorized access
    static void accessConfidentialData(boolean authorized)
            throws IllegalAccessException {
        if (!authorized) {
            throw new IllegalAccessException("Unauthorized access to student data");
        }
    }

    public static void main(String[] args) {

        // 1. ArithmeticException
        try {
            int total = 100;
            int subjects = 0; // Invalid
            int avg = total / subjects;
        } catch (ArithmeticException e) {
            System.out.println("ArithmeticException: Invalid marks calculation");
        }

        // 2. NullPointerException
        try {
            Student s = null;
            System.out.println(s.name);
        } catch (NullPointerException e) {
            System.out.println("NullPointerException: Student record missing");
        }

        // 3. IllegalAccessException
        try {
            accessConfidentialData(false);
        } catch (IllegalAccessException e) {
            System.out.println("IllegalAccessException: " + e.getMessage());
        }

        // 4. RuntimeException
        try {
            throw new RuntimeException("Unexpected error during result processing");
        } catch (RuntimeException e) {
            System.out.println("RuntimeException: " + e.getMessage());
        }

        // 5. IOException
        try {
            FileReader fr = new FileReader("student.txt");
        } catch (IOException e) {
            System.out.println("IOException: File loading failed");
        }

        // 6. Custom Exception – InvalidMarksException
        try {
            int marks = 150; // Invalid
            validateMarks(marks);
        } catch (InvalidMarksException e) {
            System.out.println("InvalidMarksException: " + e.getMessage());
        }

        System.out.println("Program executed successfully.");
    }
        }
