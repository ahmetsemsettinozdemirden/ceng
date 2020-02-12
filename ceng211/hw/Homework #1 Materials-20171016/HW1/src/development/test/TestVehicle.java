package development.test;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

import development.Vehicle;
import development.VehicleType;

public class TestVehicle {
		
	protected static Vehicle vehicle1;
	protected static Vehicle vehicle2;
	protected static Vehicle vehicle3;
	
	protected static Vehicle vehicle4;
	protected static Vehicle vehicle5;
	protected static Vehicle vehicle6;
	protected static Vehicle vehicle7;
	protected static Vehicle vehicle8;
	protected static Vehicle vehicle9;
	protected static Vehicle vehicle10;
	protected static Vehicle vehicle11;
	protected static Vehicle vehicle12;
	protected static Vehicle vehicle13;
	protected static Vehicle vehicle14;
	protected static Vehicle vehicle15;
	protected static Vehicle vehicle16;
	protected static Vehicle vehicle17;
	protected static Vehicle vehicle18;

	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		
		// valid input test setup
		vehicle1 = new Vehicle("Anakin Skywalker", "Azure Angel II", 2015, 100, 0.35, VehicleType.CAR);
		vehicle2 = new Vehicle("Han Solo", "Millennium Falcon", 2017, 150, 0.97, VehicleType.BUS);
		vehicle3 = new Vehicle("Boba Fett", "Slave I", 2013, 120, 0.06, VehicleType.MOTORCYCLE);
		
		// invalid input test setup (invalid types)
		vehicle4 = new Vehicle(null, "Honda", 2010, 100, 0.1, VehicleType.CAR);
		vehicle5 = new Vehicle("Iron Man", null, 2017, 110, 0.52, VehicleType.MOTORCYCLE);
		vehicle6 = new Vehicle("Hulk", "Feet", -1, 50, 0.89, VehicleType.BUS);
		vehicle7 = new Vehicle("Captain America", "I Run Each Team", 1944, -10, 0.25, VehicleType.MOTORCYCLE);
		vehicle8 = new Vehicle("Vision", "I believe I can fly", 1944, 500, -0.45, VehicleType.CAR);
		vehicle9 = new Vehicle("Star Lord", "Where is my ship", 2016, 325, 0.67, null);
		
		
		// boundry test
		vehicle10 = new Vehicle("Bumblebee", "Chevrolet Camaro", 2016, 1, 0.22, VehicleType.CAR);
		vehicle11 = new Vehicle("Bumblebee", "Chevrolet Camaro", 2016, 0, 0.22, VehicleType.CAR);
		vehicle12 = new Vehicle("Bumblebee", "Chevrolet Camaro", 2016, -1, 0.22, VehicleType.CAR);
		
		vehicle13 = new Vehicle("Optimus Prime", "Western Star 5700", 2014, 150, 0.0, VehicleType.BUS);
		vehicle14 = new Vehicle("Optimus Prime", "Western Star 5700", 2014, 150, 0.1, VehicleType.BUS);
		vehicle15 = new Vehicle("Optimus Prime", "Western Star 5700", 2014, 150, -0.1, VehicleType.BUS);
		
		vehicle16 = new Vehicle("Jazz", "Pontiac Solstice", 1, 170, 0.40, VehicleType.MOTORCYCLE);
		vehicle17 = new Vehicle("Jazz", "Pontiac Solstice", 0, 170, 0.40, VehicleType.MOTORCYCLE);
		vehicle18 = new Vehicle("Jazz", "Pontiac Solstice", -1, 170, 0.40, VehicleType.MOTORCYCLE);
		
	}

	@AfterClass
	public static void tearDownAfterClass() throws Exception {
	}

	@Before
	public void setUp() throws Exception {

	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void testVehicleGetOwner() {
		
		assertEquals("Anakin Skywalker", TestVehicle.vehicle1.getOwner());
		assertEquals("Han Solo", TestVehicle.vehicle2.getOwner());
		assertEquals("Boba Fett", TestVehicle.vehicle3.getOwner());
		assertEquals("NO NAME GIVEN", TestVehicle.vehicle4.getOwner());
		assertEquals("Iron Man", TestVehicle.vehicle5.getOwner());
		assertEquals("Hulk", TestVehicle.vehicle6.getOwner());
		assertEquals("Captain America", TestVehicle.vehicle7.getOwner());
		assertEquals("Vision", TestVehicle.vehicle8.getOwner());
		assertEquals("Star Lord", TestVehicle.vehicle9.getOwner());
		assertEquals("Bumblebee", TestVehicle.vehicle10.getOwner());
		assertEquals("Bumblebee", TestVehicle.vehicle11.getOwner());
		assertEquals("Bumblebee", TestVehicle.vehicle12.getOwner());
		assertEquals("Optimus Prime", TestVehicle.vehicle13.getOwner());
		assertEquals("Optimus Prime", TestVehicle.vehicle14.getOwner());
		assertEquals("Optimus Prime", TestVehicle.vehicle15.getOwner());
		assertEquals("Jazz", TestVehicle.vehicle16.getOwner());
		assertEquals("Jazz", TestVehicle.vehicle17.getOwner());
		assertEquals("Jazz", TestVehicle.vehicle18.getOwner());
		
	}
	
	@Test
	public void testVehicleGetBrand() {
		
		assertEquals("Azure Angel II", TestVehicle.vehicle1.getBrand());
		assertEquals("Millennium Falcon", TestVehicle.vehicle2.getBrand());
		assertEquals("Slave I", TestVehicle.vehicle3.getBrand());
		assertEquals("Honda", TestVehicle.vehicle4.getBrand());
		assertEquals("NO BRAND GIVEN", TestVehicle.vehicle5.getBrand());
		assertEquals("Feet", TestVehicle.vehicle6.getBrand());
		assertEquals("I Run Each Team", TestVehicle.vehicle7.getBrand());
		assertEquals("I believe I can fly", TestVehicle.vehicle8.getBrand());
		assertEquals("Where is my ship", TestVehicle.vehicle9.getBrand());
		assertEquals("Chevrolet Camaro", TestVehicle.vehicle10.getBrand());
		assertEquals("Chevrolet Camaro", TestVehicle.vehicle11.getBrand());
		assertEquals("Chevrolet Camaro", TestVehicle.vehicle12.getBrand());
		assertEquals("Western Star 5700", TestVehicle.vehicle13.getBrand());
		assertEquals("Western Star 5700", TestVehicle.vehicle14.getBrand());
		assertEquals("Western Star 5700", TestVehicle.vehicle15.getBrand());
		assertEquals("Pontiac Solstice", TestVehicle.vehicle16.getBrand());
		assertEquals("Pontiac Solstice", TestVehicle.vehicle17.getBrand());
		assertEquals("Pontiac Solstice", TestVehicle.vehicle18.getBrand());
	}
	
	@Test
	public void testVehicleGetProducedYear() {
		assertEquals(2015, TestVehicle.vehicle1.getProducedYear(), 0);
		assertEquals(2017, TestVehicle.vehicle2.getProducedYear(), 0);
		assertEquals(2013, TestVehicle.vehicle3.getProducedYear(), 0);
		assertEquals(2010, TestVehicle.vehicle4.getProducedYear(), 0);
		assertEquals(2017, TestVehicle.vehicle5.getProducedYear(), 0);
		assertEquals(2017, TestVehicle.vehicle6.getProducedYear(), 0);
		assertEquals(1944, TestVehicle.vehicle7.getProducedYear(), 0);
		assertEquals(1944, TestVehicle.vehicle8.getProducedYear(), 0);
		assertEquals(2016, TestVehicle.vehicle9.getProducedYear(), 0);
		assertEquals(2016, TestVehicle.vehicle10.getProducedYear(), 0);
		assertEquals(2016, TestVehicle.vehicle11.getProducedYear(), 0);
		assertEquals(2016, TestVehicle.vehicle12.getProducedYear(), 0);
		assertEquals(2014, TestVehicle.vehicle13.getProducedYear(), 0);
		assertEquals(2014, TestVehicle.vehicle14.getProducedYear(), 0);
		assertEquals(2014, TestVehicle.vehicle15.getProducedYear(), 0);
		assertEquals(1, TestVehicle.vehicle16.getProducedYear(), 0);
		assertEquals(2017, TestVehicle.vehicle17.getProducedYear(), 0);
		assertEquals(2017, TestVehicle.vehicle18.getProducedYear(), 0);
	}
	
	@Test
	public void testVehicleGetHorsePower() {
		
		assertEquals(100, TestVehicle.vehicle1.getHorsePower(), 0);
		assertEquals(150, TestVehicle.vehicle2.getHorsePower(), 0);
		assertEquals(120, TestVehicle.vehicle3.getHorsePower(), 0);
		assertEquals(100, TestVehicle.vehicle4.getHorsePower(), 0);
		assertEquals(110, TestVehicle.vehicle5.getHorsePower(), 0);
		assertEquals(50, TestVehicle.vehicle6.getHorsePower(), 0);
		assertEquals(null, TestVehicle.vehicle7.getHorsePower(), 0);
		assertEquals(500, TestVehicle.vehicle8.getHorsePower(), 0);
		assertEquals(325, TestVehicle.vehicle9.getHorsePower(), 0);
		assertEquals(1, TestVehicle.vehicle10.getHorsePower(), 0);
		assertEquals(null, TestVehicle.vehicle11.getHorsePower(), 0);
		assertEquals(null, TestVehicle.vehicle12.getHorsePower(), 0);
		assertEquals(150, TestVehicle.vehicle13.getHorsePower(), 0);
		assertEquals(150, TestVehicle.vehicle14.getHorsePower(), 0);
		assertEquals(150, TestVehicle.vehicle15.getHorsePower(), 0);
		assertEquals(170, TestVehicle.vehicle16.getHorsePower(), 0);
		assertEquals(170, TestVehicle.vehicle17.getHorsePower(), 0);
		assertEquals(170, TestVehicle.vehicle18.getHorsePower(), 0);
		
	}
	
	@Test
	public void testVehicleGetAccidentpenalty() {

		assertEquals(0.35, TestVehicle.vehicle1.getAccidentpenalty(), 0);
		assertEquals(0.97, TestVehicle.vehicle2.getAccidentpenalty(), 0);
		assertEquals(0.06, TestVehicle.vehicle3.getAccidentpenalty(), 0);
		assertEquals(0.1, TestVehicle.vehicle4.getAccidentpenalty(), 0);
		assertEquals(0.52, TestVehicle.vehicle5.getAccidentpenalty(), 0);
		assertEquals(0.89, TestVehicle.vehicle6.getAccidentpenalty(), 0);
		assertEquals(0.25, TestVehicle.vehicle7.getAccidentpenalty(), 0);
		assertEquals(1.0, TestVehicle.vehicle8.getAccidentpenalty(), 0);
		assertEquals(0.67, TestVehicle.vehicle9.getAccidentpenalty(), 0);
		assertEquals(0.22, TestVehicle.vehicle10.getAccidentpenalty(), 0);
		assertEquals(0.22, TestVehicle.vehicle11.getAccidentpenalty(), 0);
		assertEquals(0.22, TestVehicle.vehicle12.getAccidentpenalty(), 0);
		assertEquals(0, TestVehicle.vehicle13.getAccidentpenalty(), 0);
		assertEquals(0.1, TestVehicle.vehicle14.getAccidentpenalty(), 0);
		assertEquals(1.0, TestVehicle.vehicle15.getAccidentpenalty(), 0);
		assertEquals(0.40, TestVehicle.vehicle16.getAccidentpenalty(), 0);
		assertEquals(0.40, TestVehicle.vehicle17.getAccidentpenalty(), 0);
		assertEquals(0.40, TestVehicle.vehicle18.getAccidentpenalty(), 0);
		
	}
	
	@Test
	public void testVehicleGetVehicleType() {
		
		assertEquals(VehicleType.CAR, TestVehicle.vehicle1.getType());
		assertEquals(VehicleType.BUS, TestVehicle.vehicle2.getType());
		assertEquals(VehicleType.MOTORCYCLE, TestVehicle.vehicle3.getType());
		assertEquals(VehicleType.CAR, TestVehicle.vehicle4.getType());
		assertEquals(VehicleType.MOTORCYCLE, TestVehicle.vehicle5.getType());
		assertEquals(VehicleType.BUS, TestVehicle.vehicle6.getType());
		assertEquals(VehicleType.MOTORCYCLE, TestVehicle.vehicle7.getType());
		assertEquals(VehicleType.CAR, TestVehicle.vehicle8.getType());
		assertEquals(VehicleType.CAR, TestVehicle.vehicle9.getType());
		assertEquals(VehicleType.CAR, TestVehicle.vehicle10.getType());
		assertEquals(VehicleType.CAR, TestVehicle.vehicle11.getType());
		assertEquals(VehicleType.CAR, TestVehicle.vehicle12.getType());
		assertEquals(VehicleType.BUS, TestVehicle.vehicle13.getType());
		assertEquals(VehicleType.BUS, TestVehicle.vehicle14.getType());
		assertEquals(VehicleType.BUS, TestVehicle.vehicle15.getType());
		assertEquals(VehicleType.MOTORCYCLE, TestVehicle.vehicle16.getType());
		assertEquals(VehicleType.MOTORCYCLE, TestVehicle.vehicle17.getType());
		assertEquals(VehicleType.MOTORCYCLE, TestVehicle.vehicle18.getType());
		
	}
	
	@Test
	public void testVehicleToString() {
		
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle1.getOwner() + ", brand=" + TestVehicle.vehicle1.getBrand() + ", producedyear=" + TestVehicle.vehicle1.getProducedYear() + ", housepower="+ TestVehicle.vehicle1.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle1.getAccidentpenalty() + ", type=" + TestVehicle.vehicle1.getType() + "]", TestVehicle.vehicle1.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle2.getOwner() + ", brand=" + TestVehicle.vehicle2.getBrand() + ", producedyear=" + TestVehicle.vehicle2.getProducedYear() + ", housepower="+ TestVehicle.vehicle2.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle2.getAccidentpenalty() + ", type=" + TestVehicle.vehicle2.getType() + "]", TestVehicle.vehicle2.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle3.getOwner() + ", brand=" + TestVehicle.vehicle3.getBrand() + ", producedyear=" + TestVehicle.vehicle3.getProducedYear() + ", housepower="+ TestVehicle.vehicle3.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle3.getAccidentpenalty() + ", type=" + TestVehicle.vehicle3.getType() + "]", TestVehicle.vehicle3.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle4.getOwner() + ", brand=" + TestVehicle.vehicle4.getBrand() + ", producedyear=" + TestVehicle.vehicle4.getProducedYear() + ", housepower="+ TestVehicle.vehicle4.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle4.getAccidentpenalty() + ", type=" + TestVehicle.vehicle4.getType() + "]", TestVehicle.vehicle4.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle5.getOwner() + ", brand=" + TestVehicle.vehicle5.getBrand() + ", producedyear=" + TestVehicle.vehicle5.getProducedYear() + ", housepower="+ TestVehicle.vehicle5.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle5.getAccidentpenalty() + ", type=" + TestVehicle.vehicle5.getType() + "]", TestVehicle.vehicle5.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle6.getOwner() + ", brand=" + TestVehicle.vehicle6.getBrand() + ", producedyear=" + TestVehicle.vehicle6.getProducedYear() + ", housepower="+ TestVehicle.vehicle6.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle6.getAccidentpenalty() + ", type=" + TestVehicle.vehicle6.getType() + "]", TestVehicle.vehicle6.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle7.getOwner() + ", brand=" + TestVehicle.vehicle7.getBrand() + ", producedyear=" + TestVehicle.vehicle7.getProducedYear() + ", housepower="+ TestVehicle.vehicle7.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle7.getAccidentpenalty() + ", type=" + TestVehicle.vehicle7.getType() + "]", TestVehicle.vehicle7.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle8.getOwner() + ", brand=" + TestVehicle.vehicle8.getBrand() + ", producedyear=" + TestVehicle.vehicle8.getProducedYear() + ", housepower="+ TestVehicle.vehicle8.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle8.getAccidentpenalty() + ", type=" + TestVehicle.vehicle8.getType() + "]", TestVehicle.vehicle8.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle9.getOwner() + ", brand=" + TestVehicle.vehicle9.getBrand() + ", producedyear=" + TestVehicle.vehicle9.getProducedYear() + ", housepower="+ TestVehicle.vehicle9.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle9.getAccidentpenalty() + ", type=" + TestVehicle.vehicle9.getType() + "]", TestVehicle.vehicle9.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle10.getOwner() + ", brand=" + TestVehicle.vehicle10.getBrand() + ", producedyear=" + TestVehicle.vehicle10.getProducedYear() + ", housepower="+ TestVehicle.vehicle10.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle10.getAccidentpenalty() + ", type=" + TestVehicle.vehicle10.getType() + "]", TestVehicle.vehicle10.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle11.getOwner() + ", brand=" + TestVehicle.vehicle11.getBrand() + ", producedyear=" + TestVehicle.vehicle11.getProducedYear() + ", housepower="+ TestVehicle.vehicle11.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle11.getAccidentpenalty() + ", type=" + TestVehicle.vehicle11.getType() + "]", TestVehicle.vehicle11.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle12.getOwner() + ", brand=" + TestVehicle.vehicle12.getBrand() + ", producedyear=" + TestVehicle.vehicle12.getProducedYear() + ", housepower="+ TestVehicle.vehicle12.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle12.getAccidentpenalty() + ", type=" + TestVehicle.vehicle12.getType() + "]", TestVehicle.vehicle12.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle13.getOwner() + ", brand=" + TestVehicle.vehicle13.getBrand() + ", producedyear=" + TestVehicle.vehicle13.getProducedYear() + ", housepower="+ TestVehicle.vehicle13.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle13.getAccidentpenalty() + ", type=" + TestVehicle.vehicle13.getType() + "]", TestVehicle.vehicle13.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle14.getOwner() + ", brand=" + TestVehicle.vehicle14.getBrand() + ", producedyear=" + TestVehicle.vehicle14.getProducedYear() + ", housepower="+ TestVehicle.vehicle14.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle14.getAccidentpenalty() + ", type=" + TestVehicle.vehicle14.getType() + "]", TestVehicle.vehicle14.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle15.getOwner() + ", brand=" + TestVehicle.vehicle15.getBrand() + ", producedyear=" + TestVehicle.vehicle15.getProducedYear() + ", housepower="+ TestVehicle.vehicle15.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle15.getAccidentpenalty() + ", type=" + TestVehicle.vehicle15.getType() + "]", TestVehicle.vehicle15.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle16.getOwner() + ", brand=" + TestVehicle.vehicle16.getBrand() + ", producedyear=" + TestVehicle.vehicle16.getProducedYear() + ", housepower="+ TestVehicle.vehicle16.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle16.getAccidentpenalty() + ", type=" + TestVehicle.vehicle16.getType() + "]", TestVehicle.vehicle16.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle17.getOwner() + ", brand=" + TestVehicle.vehicle17.getBrand() + ", producedyear=" + TestVehicle.vehicle17.getProducedYear() + ", housepower="+ TestVehicle.vehicle17.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle17.getAccidentpenalty() + ", type=" + TestVehicle.vehicle17.getType() + "]", TestVehicle.vehicle17.toString());
		assertEquals("Vehicle [owner=" + TestVehicle.vehicle18.getOwner() + ", brand=" + TestVehicle.vehicle18.getBrand() + ", producedyear=" + TestVehicle.vehicle18.getProducedYear() + ", housepower="+ TestVehicle.vehicle18.getHorsePower() + ", accidentpenalty=" + TestVehicle.vehicle18.getAccidentpenalty() + ", type=" + TestVehicle.vehicle18.getType() + "]", TestVehicle.vehicle18.toString());
		
	}

}

