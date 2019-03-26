/**
 * Created by Devansh on 26/3/19.
 */
public class Checkbox implements Button {

    private String name;

    public Checkbox(String name) {
        this.name = name;
    }

    @Override
    public Button clone() {
        return new Checkbox(name);
    }

    @Override
    public String getName() {
        return name;
    }
}
