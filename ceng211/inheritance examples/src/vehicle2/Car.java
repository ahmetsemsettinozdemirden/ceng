package vehicle2;

public class Car implements Vehicle {
	
	@Override
	public Integer getNumberOfSeats() {
		return 5;
	}

	@Override
	public Integer getNumberOfWheels() {
		return 4;
	}

	@Override
	public String getVehicleType() {
		return "Car";
	}

	public Integer getNumberOfDoors() {
		return 2;
	}

}
