import java.util.Scanner;

/**
 * Created by Devansh on 26/3/19.
 */
public class Client {

    public static void main(String[] args) {
        ButtonFactory factory = ButtonFactory.getInstance();
        factory.loadButton();

        System.out.println("Enter type:\n\n");
        System.out.println("Checkbox: 1\nRadioButton: 2\nToggleButton: 3\n");

        Scanner scanner = new Scanner(System.in);
        int type = scanner.nextInt();

        Button button = factory.getButton(type);
        System.out.println(button.getClass() + ": " button.getName());
    }
}

