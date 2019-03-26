/**
 * Created by Devansh on 26/3/19.
 */
public class RadioButton implements Button {

    private String name;

    public RadioButton(String name) {
        this.name = name;
    }

    @Override
    public Button clone() {
        return new RadioButton(name);
    }

    @Override
    public String getName() {
        return name;
    }
}
