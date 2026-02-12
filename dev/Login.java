
import java.util.Scanner;
public class Login {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the User name ");
        String Username = scan.nextLine();
        System.out.println("Enter the password");
        String password = scan.nextLine();

        if(Username.equals("Admin") && (password.equals("123"))){
            System.out.println("Login Successfully");
        }
        else{
            System.out.println("Login Failed");
        }
    }
}
