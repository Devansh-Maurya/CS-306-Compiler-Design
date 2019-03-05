class FarmerHelp {

    public final Crop crop;
    
    public FarmerHelp(Crop crop) {
        this.crop = crop;
    }
    
    public void farmerSuggest() {
        MonthWeatherData idealMonth = 
            Weather.getInstance().getIdealMonth(crop.idealTemperature, crop.idealRainfall);
        
       System.out.println("\nIdeal month for farming " + crop.name + " is " + idealMonth.monthName);
       System.out.println(idealMonth.monthName + " has average temperature of " 
            + idealMonth.temperature);
       System.out.println(idealMonth.monthName + " has average rainfall of " 
            + idealMonth.rainfall);        
    }
}
