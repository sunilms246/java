import java.util.*;
public class Login {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("enter username:");
        String user = sc.nextLine();
        System.out.println("password: ");
        String pass = sc.nextLine();
        if(user.equals("admin") && pass.equals("123")){
            System.out.println("login sucess");
        }
        else{
            System.out.println("login faild");
        }
    }
}
