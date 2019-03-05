import java.lang.Math;

class Weather {

    private MonthWeatherData[] data = new MonthWeatherData[12];
    private static Weather weather;
    
    private Weather() {
    
        for(int i = 0; i < data.length; i++) {
            data[i] = new MonthWeatherData();
        }
    
        //Add data here
        data[0].temperature = 15;
        data[1].temperature = 19;
        data[2].temperature = 24;
        data[3].temperature = 30;
        data[4].temperature = 32;
        data[5].temperature = 33;
        data[6].temperature = 30;
        data[7].temperature = 30;
        data[8].temperature = 29;
        data[9].temperature = 26;
        data[10].temperature = 21;
        data[11].temperature = 16;
        
        data[0].rainfall = 13.6;        
        data[1].rainfall = 27;        
        data[2].rainfall = 13.5;        
        data[3].rainfall = 13.5;        
        data[4].rainfall = 21.4;        
        data[5].rainfall = 79.6;        
        data[6].rainfall = 194.7;        
        data[7].rainfall = 179.4;        
        data[8].rainfall = 93.2;        
        data[9].rainfall = 26;        
        data[10].rainfall = 3.1;        
        data[11].rainfall = 5.5;
        
        data[0].monthName = "January";
        data[1].monthName = "February";
        data[2].monthName = "March";
        data[3].monthName = "April";
        data[4].monthName = "May";
        data[5].monthName = "June";
        data[6].monthName = "July";
        data[7].monthName = "August";
        data[8].monthName = "September";
        data[9].monthName = "October";
        data[10].monthName = "November";
        data[11].monthName = "December";
    }
    
    public MonthWeatherData getIdealMonth(double temp, double rain) {
        double minAbsDiff = Float.MAX_VALUE;
        double currentDiff = 0;
        MonthWeatherData idealMonth = null;
       
        for (MonthWeatherData month : data) {
            currentDiff = Math.abs(month.temperature - temp) + Math.abs(month.rainfall - rain);
            
            if (currentDiff < minAbsDiff) {
                minAbsDiff = currentDiff;
                idealMonth = month;
            }
        }
        
        return idealMonth;
    }
    
    public static Weather getInstance() {
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
