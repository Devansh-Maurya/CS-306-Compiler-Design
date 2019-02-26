class Weather {

    private MonthWeatherData[] data = new MonthWeatherData[24];
    private static Weather weather;
    
    private Weather() {
    
        //Add data here    
        
    }
    
    public getInstance() {
        if(weather == null)
            weather = new Weather();
        return weather;
    }
    
    public void setWeatherData(MonthWeatherData[] data) {
        this.data = data;
    }
    
    public MonthWeatherData[] getWeatherData() {
        return data;
    }
}
