/*
6. A university wants to build a that accepts feedback from the console and stores it in a text
file. Design a Java program that
- Reads student name, course, and feedback using or
- Writes the details into a file using or .
- Automatically closes the file using .
*/
import java.io.*;
import java.util.Scanner;

public class FeedbackSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Name: "); String n = sc.nextLine();
        System.out.print("Course: "); String c = sc.nextLine();
        System.out.print("Feedback: "); String f = sc.nextLine();

        try (PrintWriter pw = new PrintWriter(new FileWriter("feedback.txt", true))) {
            pw.println("Name    : " + n);
            pw.println("Course  : " + c);
            pw.println("Feedback: " + f);
            pw.println("-------------------------");
            System.out.println("Saved!");
        } catch (IOException e) {
            System.out.println("File error!");
        }

        sc.close();
    }
}
