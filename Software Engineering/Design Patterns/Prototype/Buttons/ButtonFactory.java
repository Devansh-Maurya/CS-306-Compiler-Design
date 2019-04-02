class ButtonFactory {

    public static final int CHECKBOX = 1;
    public static final int RADIO_BUTTON = 2;
    public static final int TOGGLE_BUTTON = 3;

    private static ButtonFactory buttonFactory;

    private RadioButton radioButton;
    private ToggleButton toggleButton;
    private Checkbox checkBox;

    private ButtonFactory() {
        //Add data here
    }

    public static ButtonFactory getInstance() {
        if(buttonFactory == null)
            buttonFactory = new ButtonFactory();
        return buttonFactory;
    }

    public void loadButton() {
        radioButton = new RadioButton("MyRadioButton");
        toggleButton = new ToggleButton("MyToggleButton");
        checkBox = new Checkbox("MyCheckbox");
    }

    public Button getButton(int type) {
        switch (type) {
            case CHECKBOX:
                return checkBox.clone();
            case RADIO_BUTTON:
                return radioButton;
            case TOGGLE_BUTTON:
                return toggleButton;
        }
        return null;
    }
}
