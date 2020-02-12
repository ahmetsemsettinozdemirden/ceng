package development.test;

import static org.junit.Assert.*;

import java.util.ArrayList;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

import development.FileParser;
import development.Vehicle;
import development.VehicleType;

public class TestFileParser {

	private ArrayList<Vehicle> vehicleList = new ArrayList<>();
	
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
	}

	@AfterClass
	public static void tearDownAfterClass() throws Exception {
	}

	@Before
	public void setUp() throws Exception {
		FileParser parser = new FileParser();
		vehicleList = parser.readFile();
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void testReadFile() {
		
		assertEquals("John Smith", vehicleList.get(0).getOwner());
		assertEquals("Opel Astra", vehicleList.get(0).getBrand());
		assertEquals(2011, vehicleList.get(0).getProducedYear(), 0);
		assertEquals(90, vehicleList.get(0).getHorsePower(), 0);
		assertEquals(0.6, vehicleList.get(0).getAccidentpenalty(), 0);
		assertEquals(VehicleType.CAR, vehicleList.get(0).getType());
		
		assertEquals("Chris Brown", vehicleList.get(1).getOwner());
		assertEquals("Man", vehicleList.get(1).getBrand());
		assertEquals(2014, vehicleList.get(1).getProducedYear(), 0);
		assertEquals(150, vehicleList.get(1).getHorsePower(), 0);
		assertEquals(0.5, vehicleList.get(1).getAccidentpenalty(), 0);
		assertEquals(VehicleType.BUS, vehicleList.get(1).getType());

		
		assertEquals("Emma Swift", vehicleList.get(2).getOwner());
		assertEquals("Kawasaki Ninja 250SL", vehicleList.get(2).getBrand());
		assertEquals(2016, vehicleList.get(2).getProducedYear(), 0);
		assertEquals(40, vehicleList.get(2).getHorsePower(), 0);
		assertEquals(0.71, vehicleList.get(2).getAccidentpenalty(), 0);
		assertEquals(VehicleType.MOTORCYCLE, vehicleList.get(2).getType());


	}

}
