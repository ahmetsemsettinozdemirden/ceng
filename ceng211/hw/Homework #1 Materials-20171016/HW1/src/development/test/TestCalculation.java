package development.test;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

import development.Calculation;

public class TestCalculation {

	private Calculation calculation1;

	@BeforeClass
	public static void setUpBeforeClass() throws Exception {

		TestCompany.setUpBeforeClass();
		TestVehicle.setUpBeforeClass();
	}

	@AfterClass
	public static void tearDownAfterClass() throws Exception {
	}

	@Before
	public void setUp() throws Exception {

		calculation1 = new Calculation();
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void testCalculationComp1Veh1_18() {
		assertEquals(2695.0, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company1),0);
		assertEquals(6658.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company1),0);
		assertEquals(833.7500000000001, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company1),0);
		assertEquals(2242.8125, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company1),0);
		assertEquals(1408.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company1),0);
		assertEquals(4346.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company1),0);
		assertEquals(43.75, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company1),0);
		assertEquals(11350.0, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company1),0);
		assertEquals(8119.0, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company1),0);
		assertEquals(676.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company1),0);
		assertEquals(654.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company1),0);
		assertEquals(654.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company1),0);
		assertEquals(3550.0, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company1),0);
		assertEquals(3690.0, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company1),0);
		assertEquals(4950.0, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company1),0);
		assertEquals(1192.0, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company1),0);
		assertEquals(1762.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company1),0);
		assertEquals(1762.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company1),0);
	}

	@Test
	public void testCalculationComp2Veh1_18() {
		assertEquals(1642.5, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company2),0);
		assertEquals(3046.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company2),0);
		assertEquals(546.3125, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company2),0);
		assertEquals(1520.078125, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company2),0);
		assertEquals(604.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company2),0);
		assertEquals(1482.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company2),0);
		assertEquals(25.0, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company2),0);
		assertEquals(7700.0, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company2),0);
		assertEquals(5148.0, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company2),0);
		assertEquals(108.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company2),0);
		assertEquals(93.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company2),0);
		assertEquals(93.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company2),0);
		assertEquals(2252.5, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company2),0);
		assertEquals(2332.5, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company2),0);
		assertEquals(3052.5, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company2),0);
		assertEquals(805.0, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company2),0);
		assertEquals(850.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company2),0);
		assertEquals(850.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company2),0);
	}

	@Test
	public void testCalculationComp3Veh1_18() {

		assertEquals(1320.0, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company3),0);
		assertEquals(3888.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company3),0);
		assertEquals(394.25, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company3),0);
		assertEquals(1017.8125, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company3),0);
		assertEquals(882.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company3),0);
		assertEquals(2856.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company3),0);
		assertEquals(12.5, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company3),0);
		assertEquals(5100.0, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company3),0);
		assertEquals(3884.0, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company3),0);
		assertEquals(554.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company3),0);
		assertEquals(544.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company3),0);
		assertEquals(544.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company3),0);
		assertEquals(1750.0, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company3),0);
		assertEquals(1790.0, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company3),0);
		assertEquals(2150.0, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company3),0);
		assertEquals(530.0, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company3),0);
		assertEquals(1050.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company3),0);
		assertEquals(1050.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company3),0);


	}

	@Test
	public void testCalculationComp4Veh1_18() {
		assertEquals(1320.0, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company4),0);
		assertEquals(3888.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company4),0);
		assertEquals(394.25, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company4),0);
		assertEquals(1017.8125, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company4),0);
		assertEquals(882.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company4),0);
		assertEquals(2856.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company4),0);
		assertEquals(12.5, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company4),0);
		assertEquals(5100.0, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company4),0);
		assertEquals(3884.0, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company4),0);
		assertEquals(554.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company4),0);
		assertEquals(544.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company4),0);
		assertEquals(544.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company4),0);
		assertEquals(1750.0, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company4),0);
		assertEquals(1790.0, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company4),0);
		assertEquals(2150.0, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company4),0);
		assertEquals(530.0, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company4),0);
		assertEquals(1050.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company4),0);
		assertEquals(1050.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company4),0);

	}

	@Test
	public void testCalculationComp5Veh1_18() {
		assertEquals(1320.0, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company5),0);
		assertEquals(3888.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company5),0);
		assertEquals(394.25, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company5),0);
		assertEquals(1017.8125, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company5),0);
		assertEquals(882.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company5),0);
		assertEquals(2856.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company5),0);
		assertEquals(12.5, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company5),0);
		assertEquals(5100.0, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company5),0);
		assertEquals(3884.0, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company5),0);
		assertEquals(554.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company5),0);
		assertEquals(544.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company5),0);
		assertEquals(544.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company5),0);
		assertEquals(1750.0, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company5),0);
		assertEquals(1790.0, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company5),0);
		assertEquals(2150.0, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company5),0);
		assertEquals(530.0, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company5),0);
		assertEquals(1050.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company5),0);
		assertEquals(1050.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company5),0);


	}

	@Test
	public void testCalculationComp6Veh1_18() {
		assertEquals(1320.0, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company6),0);
		assertEquals(3888.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company6),0);
		assertEquals(394.25, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company6),0);
		assertEquals(1017.8125, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company6),0);
		assertEquals(882.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company6),0);
		assertEquals(2856.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company6),0);
		assertEquals(12.5, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company6),0);
		assertEquals(5100.0, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company6),0);
		assertEquals(3884.0, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company6),0);
		assertEquals(554.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company6),0);
		assertEquals(544.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company6),0);
		assertEquals(544.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company6),0);
		assertEquals(1750.0, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company6),0);
		assertEquals(1790.0, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company6),0);
		assertEquals(2150.0, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company6),0);
		assertEquals(530.0, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company6),0);
		assertEquals(1050.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company6),0);
		assertEquals(1050.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company6),0);

	}

	@Test
	public void testCalculationComp7Veh1_18() {
		assertEquals(1320.0, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company7),0);
		assertEquals(3888.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company7),0);
		assertEquals(394.25, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company7),0);
		assertEquals(1017.8125, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company7),0);
		assertEquals(882.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company7),0);
		assertEquals(2856.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company7),0);
		assertEquals(12.5, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company7),0);
		assertEquals(5100.0, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company7),0);
		assertEquals(3884.0, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company7),0);
		assertEquals(554.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company7),0);
		assertEquals(544.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company7),0);
		assertEquals(544.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company7),0);
		assertEquals(1750.0, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company7),0);
		assertEquals(1790.0, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company7),0);
		assertEquals(2150.0, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company7),0);
		assertEquals(530.0, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company7),0);
		assertEquals(1050.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company7),0);
		assertEquals(1050.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company7),0);

	}

	@Test
	public void testCalculationComp8Veh1_18() {
		assertEquals(1320.0, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company8),0);
		assertEquals(3888.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company8),0);
		assertEquals(394.25, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company8),0);
		assertEquals(1017.8125, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company8),0);
		assertEquals(882.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company8),0);
		assertEquals(2856.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company8),0);
		assertEquals(12.5, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company8),0);
		assertEquals(5100.0, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company8),0);
		assertEquals(3884.0, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company8),0);
		assertEquals(554.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company8),0);
		assertEquals(544.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company8),0);
		assertEquals(544.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company8),0);
		assertEquals(1750.0, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company8),0);
		assertEquals(1790.0, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company8),0);
		assertEquals(2150.0, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company8),0);
		assertEquals(530.0, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company8),0);
		assertEquals(1050.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company8),0);
		assertEquals(1050.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company8),0);

	}



}
