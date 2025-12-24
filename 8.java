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

class LoginAWT extends Frame implements ActionListener, KeyListener {

    Label lUser, lPass, lResult;
    TextField tUser, tPass;
    Button btnLogin;

    LoginAWT() {
        // Set Frame properties
        setTitle("Login Window");
        setSize(300, 200);
        setLayout(new FlowLayout());

        // Create components
        lUser = new Label("Username:");
        tUser = new TextField(20);

        lPass = new Label("Password:");
        tPass = new TextField(20);
        tPass.setEchoChar('*');

        btnLogin = new Button("Login");
        lResult = new Label("");

        // Add components to frame
        add(lUser);
        add(tUser);
        add(lPass);
        add(tPass);
        add(btnLogin);
        add(lResult);

        // Register listeners
        btnLogin.addActionListener(this);
        tPass.addKeyListener(this);

        // Close window
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });

        setVisible(true);
    }

    // Login validation logic
    public void actionPerformed(ActionEvent e) {
        validateLogin();
    }

    void validateLogin() {
        String user = tUser.getText();
        String pass = tPass.getText();

        if (user.equals("admin") && pass.equals("1234")) {
            lResult.setText("Login Successful");
        } else {
            lResult.setText("Login Failed");
        }
    }

    // Trigger login on Enter key
    public void keyPressed(KeyEvent e) {
        if (e.getKeyCode() == KeyEvent.VK_ENTER) {
            validateLogin();
        }
    }

    public void keyReleased(KeyEvent e) {}
    public void keyTyped(KeyEvent e) {}

    public static void main(String[] args) {
        new LoginAWT();
    }
}
