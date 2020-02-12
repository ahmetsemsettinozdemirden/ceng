package vehicle2;

public class Bus implements Vehicle {

	@Override
	public Integer getNumberOfSeats() {
		return 35;
	}

	@Override
	public Integer getNumberOfWheels() {
		return 6;
	}

	@Override
	public String getVehicleType() {
		return "Bus";
	}

	public Integer getNumberOfDoors() {
		return 4;
	}

}
