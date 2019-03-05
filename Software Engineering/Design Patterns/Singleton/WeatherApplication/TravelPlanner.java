class TravelPlanner {

    public final City city;
    
    public TravelPlanner(City city) {
        this.city = city;
    }
    
    public void travelSuggest() {
        MonthWeatherData idealMonth = 
            Weather.getInstance().getIdealMonth(city.idealTemperature, city.idealRainfall);
        
       System.out.println("\nIdeal month for farming " + city.name + " is " + idealMonth.monthName);
       System.out.println(idealMonth.monthName + " has average temperature of " 
            + idealMonth.temperature);
       System.out.println(idealMonth.monthName + " has average rainfall of " 
            + idealMonth.rainfall);     
    }

}
