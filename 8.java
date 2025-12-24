/*
8. You are building a login window using AWT. Create a Frame with:
- TextField for username
- PasswordField
- Login Button
- When the Login button is clicked:
- Validate the username/password
- Display success/failure in a Label
- Add an event listener for pressing Enter key inside the password box to trigger login.

  */
import java.awt.*;
import java.awt.event.*;

public class 8{
    public static void main(String[] args){
        Frame f = new Frame("Login");
        f.setLayout(new FlowLayout());
        
        TextField user = new TextField(10);
        TextField pass = new TextField(10);
        pass.setEchoChar('*');

        Label l1 = new Label("user:");
        Label l2 = new Label("Pass:");
        Label msg = new Label("");
        Button b = new Button("Login");

        f.add(l1); f.add(user);
        f.add(l2); f.add(pass);
        f.add(b);
        f.add(msg);

        b.addActionListener(e ->{
            if(user.getText().equals("admin") && pass.getText().equals("123"))
                msg.setText("Success");
            else
                msg.setText("Fail");

        });

        f.setSize(200, 150);
        f.setVisible(true);

    }
}