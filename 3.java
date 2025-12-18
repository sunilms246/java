//3. Develop a java program to accept command line arguments. If the arguments are numeric,
  // convert them and perform all possible arithmetic operations and display results suitably and
  // handle exceptions if any. If arguments are strings treat it as exception and handle it
class CommandLineArithmetic {
    public static void main(String[] args) {
        try {
            if (args.length < 2) {
                throw new IllegalArgumentException("Please enter at least two arguments");
            }

            // Convert command line arguments to integers
            int a = Integer.parseInt(args[0]);
            int b = Integer.parseInt(args[1]);

            System.out.println("Addition       : " + (a + b));
            System.out.println("Subtraction    : " + (a - b));
            System.out.println("Multiplication : " + (a * b));

            // Division handling
            System.out.println("Division       : " + (a / b));
            System.out.println("Modulus        : " + (a % b));
        }
        catch (NumberFormatException e) {
            System.out.println("Exception: Non-numeric arguments are not allowed");
        }
        catch (ArithmeticException e) {
            System.out.println("Exception: Division by zero");
        }
        catch (Exception e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }
}
