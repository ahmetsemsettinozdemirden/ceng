package vehicle1;

public class VehicleApp {

	public static void main(String[] args) {
		
		Truck truck = new Truck("Ford", "F150", 2008, 0.5);
		System.out.println("Make = " + truck.getMake());
		System.out.println("Model = " + truck.getModel());
		System.out.println("Year = " + truck.getYear());
		System.out.println("Tonnage = " + truck.getTonnage());
		System.out.println(truck.toString());
		
	}

}
