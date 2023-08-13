public class Main {
    public static void main(String[] args) {
        String in_data = "this is the new way to code";

        if (in_data.isEmpty()) {
            System.out.println("String is empty");
        } else if (in_data.length() >= 2) {
            System.out.println("Last two characters: " + in_data.charAt(in_data.length() - 2) + in_data.charAt(in_data.length() - 1));
        } else {
            System.out.println("String has less than two characters");
        }
    }
}