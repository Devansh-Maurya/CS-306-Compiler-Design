class SingletonHelper {

    public static void main(String[] args) {
    
        Singleton object1 = Singleton.getInstance();
        object1.print();
        
        Singleton object2 = Singleton.getInstance();
        object2.print();
        
        Singleton object3 = Singleton.getInstance();
        object3.print();
    }
    

}
