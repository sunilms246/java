/*
6. A university wants to build a that accepts feedback from the console and stores it in a text
file. Design a Java program that
- Reads student name, course, and feedback using or
- Writes the details into a file using or .
- Automatically closes the file using .
*/
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class FeedbackSystem {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Student Name: ");
        String name = sc.nextLine();

        System.out.print("Enter Course: ");
        String course = sc.nextLine();

        System.out.print("Enter Feedback: ");
        String feedback = sc.nextLine();

        // Try-with-resources to auto close file
        try (FileWriter fw = new FileWriter("feedback.txt", true)) {

            fw.write("Student Name: " + name + "\n");
            fw.write("Course      : " + course + "\n");
            fw.write("Feedback    : " + feedback + "\n");
            fw.write("----------------------------------\n");

            System.out.println("Feedback saved successfully.");

        } catch (IOException e) {
            System.out.println("File error occurred.");
        }

        sc.close();
    }
}
