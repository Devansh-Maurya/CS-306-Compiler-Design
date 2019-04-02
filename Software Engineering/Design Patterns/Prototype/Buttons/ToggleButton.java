/**
 * Created by Devansh on 26/3/19.
 */
public class ToggleButton implements Button {

    private String name;

    public ToggleButton(String name) {
        this.name = name;
    }

    @Override
    public Button clone() {
        return new ToggleButton(name);
    }

    @Override
    public String getName() {
        return name;
    }
}
