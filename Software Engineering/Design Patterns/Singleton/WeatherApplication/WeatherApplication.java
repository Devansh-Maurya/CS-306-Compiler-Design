import java.util.Scanner;

class WeatherApplication {

    public static void main(String[] args) {
    
        double temp, rain;
        String name = null;
        Scanner in = new Scanner(System.in);
        
        System.out.print("Enter crop name: ");
        name = in.nextLine();
        
        System.out.print("Enter ideal temperature for " + name + ": ");
        temp = in.nextFloat();
        
        System.out.print("Enter ideal rainfall for " + name + ": ");
        rain = in.nextFloat();
        
        new FarmerHelp(new Crop(name, temp, rain)).farmerSuggest();
        
        in = new Scanner(System.in);
        
        System.out.println("\n\nYour travel planner for travelling to Lucknow: ");
        
        System.out.print("Enter your ideal temperature for travelling: ");
        temp = in.nextFloat();
        
        System.out.print("Enter your ideal rainfall for travelling: ");
        rain = in.nextFloat();
        
        new TravelPlanner(new City("Lucknow", temp, rain)).travelSuggest();
    }

}
