class Singleton {

	private static Singleton singleton;
	private static int counter;
	
	private Singleton() {
		counter++;
	}
	
	public static Singleton getInstance() {
		if (singleton == null)
            singleton = new Singleton();
        return singleton;    
	}
	
	public void print() {
	    System.out.println(counter + " instance exist");
	}

}
