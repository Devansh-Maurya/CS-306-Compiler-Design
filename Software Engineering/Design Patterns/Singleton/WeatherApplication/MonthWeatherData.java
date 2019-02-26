class MonthWeatherData {

    private float temperature;
    private float rainfall;
    
    public MonthWeatherData(float temperature, float rainfall) {
        this.temperature = temperature;
        this.rainfall = rainfall;
    }

    float getTemperature() {
        return temperature;
    }
    
    float getRainfall() {
        return rainfall;
    }
    
    void setTemperature(float temperature) {
        this.temperature = temperature;   
    }
    
    void setRainfall(float rainfall) {
        this.rainfall = rainfall;
    }
}
