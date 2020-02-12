package bicycle;

public class Bicycle {

    // the Bicycle class has three fields
	private int cadence;
	private int gear;
	private int speed;
        
    // the Bicycle class has one constructor
    public Bicycle(int startCadence, int startSpeed, int startGear) {
        gear = startGear;
        cadence = startCadence;
        speed = startSpeed;
    }
        
    // the Bicycle class has four methods
    public void setCadence(int newValue) {
        cadence = newValue;
    }
        
    public void setGear(int newValue) {
        gear = newValue;
    }
        
    public void applyBrake(int decrement) {
        speed -= decrement;
    }
        
    public void speedUp(int increment) {
        speed += increment;
    }

	@Override
	public String toString() {
		return "Bicycle [cadence=" + cadence + ", gear=" + gear + ", speed=" + speed + "]";
	}
        
}
