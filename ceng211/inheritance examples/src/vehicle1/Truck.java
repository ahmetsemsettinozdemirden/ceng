package vehicle1;

public class Truck extends Vehicle {
	private double tonnage;

	Truck(String make, String model, int year, double tonnage) {
		super(make, model, year);
		this.tonnage = tonnage;
	}

	public double getTonnage() {
		return tonnage;
	}

	public String toString() {
		return super.toString() + "Tonnage: " + tonnage;
	}

}
