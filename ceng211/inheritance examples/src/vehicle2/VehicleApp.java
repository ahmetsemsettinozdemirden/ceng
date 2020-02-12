package vehicle2;

public class VehicleApp {

	public static void main(String[] args) {

		Vehicle myCar = new Car();
		System.out.println("My " + myCar.getVehicleType() + " has " + myCar.getNumberOfSeats() + " seats.");
		System.out.println("My " + myCar.getVehicleType() + " has " + myCar.getNumberOfWheels() + " wheels.");
		
		Car car = new Car();
		boolean isVehicle = car instanceof Vehicle;
		System.out.println("car instanceof Vehicle? " + isVehicle);
		boolean isCar = car instanceof Car;
		System.out.println("car instanceof Car? " + isCar);
		
		Vehicle myBus = new Bus();
		System.out.println("My " + myBus.getVehicleType() + " has " + myBus.getNumberOfSeats() + " seats.");
		System.out.println("My " + myBus.getVehicleType() + " has " + myBus.getNumberOfWheels() + " wheels.");

	}

}
