/*
4. Declare a non-generic class called GenMethDemo and a static generic method within that
class called isIn( ). The isIn( ) method determines if an object is a member of an array. It
can be used with any type of object and array as long as the array contains objects that are
compatible with the type of the object being sought.
*/

class GenMethDemo {

    // Static Generic Method
    public static <T> boolean isIn(T obj, T[] array) {

        for (T element : array) {
            if (obj.equals(element)) {
                return true;
            }
        }
        return false;
    }

    // Main method to test isIn()
    public static void main(String[] args) {

        Integer[] numbers = {1, 2, 3, 4, 5};
        String[] names = {"Sunil", "Ravi", "Anil"};

        System.out.println("Is 3 in numbers? " + isIn(3, numbers));
        System.out.println("Is 7 in numbers? " + isIn(7, numbers));

        System.out.println("Is Sunil in names? " + isIn("Sunil", names));
        System.out.println("Is Kumar in names? " + isIn("Kumar", names));
    }
}
