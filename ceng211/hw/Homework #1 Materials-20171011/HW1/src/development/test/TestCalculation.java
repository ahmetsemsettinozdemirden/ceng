package development.test;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

import development.Calculation;
import development.Company;
import development.Vehicle;

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
		assertEquals(6322.5, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company1),0);
		assertEquals(5979.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company1),0);
		assertEquals(8802.5, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company1),0);
		assertEquals(130235.0, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company1),0);
		assertEquals(1317.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company1),0);
		assertEquals(3723.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company1),0);
		assertEquals(4.722366482869645E24, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company1),0);
		assertEquals(9.44473296573929E24, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company1),0);
		assertEquals(9384.5, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company1),0);
		assertEquals(2099.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company1),0);
		assertEquals(2077.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company1),0);
		assertEquals(2077.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company1),0);
		assertEquals(19300.0, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company1),0);
		assertEquals(19370.0, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company1),0);
		assertEquals(20000.0, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company1),0);
		assertEquals(Double.POSITIVE_INFINITY, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company1),0);
		assertEquals(1692.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company1),0);
		assertEquals(1692.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company1),0);
	}
	
	@Test
	public void testCalculationComp2Veh1_18() {
		assertEquals(1610.0, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company2),0);
		assertEquals(2658.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company2),0);
		assertEquals(626.0, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company2),0);
		assertEquals(2800.0, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company2),0);
		assertEquals(552.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company2),0);
		assertEquals(1126.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company2),0);
		assertEquals(4.722366482869645E22, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company2),0);
		assertEquals(9.44473296573929E22, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company2),0);
		assertEquals(5029.0, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company2),0);
		assertEquals(79.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company2),0);
		assertEquals(64.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company2),0);
		assertEquals(64.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company2),0);
		assertEquals(2410.0, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company2),0);
		assertEquals(2450.0, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company2),0);
		assertEquals(2810.0, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company2),0);
		assertEquals(Double.POSITIVE_INFINITY, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company2),0);
		assertEquals(810.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company2),0);
		assertEquals(810.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company2),0);
	}
	
	@Test
	public void testCalculationComp3Veh1_18() {
		assertEquals(5035.0, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company3),0);
		assertEquals(3694.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company3),0);
		assertEquals(8363.0, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company3),0);
		assertEquals(129010.0, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company3),0);
		assertEquals(856.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company3),0);
		assertEquals(2678.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company3),0);
		assertEquals(4.722366482869645E24, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company3),0);
		assertEquals(9.44473296573929E24, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company3),0);
		assertEquals(5317.0, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company3),0);
		assertEquals(2032.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company3),0);
		assertEquals(2022.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company3),0);
		assertEquals(2022.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company3),0);
		assertEquals(17500.0, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company3),0);
		assertEquals(17520.0, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company3),0);
		assertEquals(17700.0, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company3),0);
		assertEquals(Double.POSITIVE_INFINITY, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company3),0);
		assertEquals(1030.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company3),0);
		assertEquals(1030.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company3),0);
	}
	
	@Test
	public void testCalculationComp4Veh1_18() {
		assertEquals(5035.0, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company4),0);
		assertEquals(3694.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company4),0);
		assertEquals(8363.0, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company4),0);
		assertEquals(129010.0, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company4),0);
		assertEquals(856.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company4),0);
		assertEquals(2678.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company4),0);
		assertEquals(4.722366482869645E24, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company4),0);
		assertEquals(9.44473296573929E24, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company4),0);
		assertEquals(5317.0, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company4),0);
		assertEquals(2032.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company4),0);
		assertEquals(2022.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company4),0);
		assertEquals(2022.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company4),0);
		assertEquals(17500.0, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company4),0);
		assertEquals(17520.0, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company4),0);
		assertEquals(17700.0, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company4),0);
		assertEquals(Double.POSITIVE_INFINITY, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company4),0);
		assertEquals(1030.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company4),0);
		assertEquals(1030.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company4),0);
	}
	
	@Test
	public void testCalculationComp5Veh1_18() {
		assertEquals(5035.0, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company5),0);
		assertEquals(3694.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company5),0);
		assertEquals(8363.0, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company5),0);
		assertEquals(129010.0, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company5),0);
		assertEquals(856.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company5),0);
		assertEquals(2678.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company5),0);
		assertEquals(4.722366482869645E24, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company5),0);
		assertEquals(9.44473296573929E24, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company5),0);
		assertEquals(5317.0, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company5),0);
		assertEquals(2032.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company5),0);
		assertEquals(2022.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company5),0);
		assertEquals(2022.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company5),0);
		assertEquals(17500.0, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company5),0);
		assertEquals(17520.0, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company5),0);
		assertEquals(17700.0, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company5),0);
		assertEquals(Double.POSITIVE_INFINITY, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company5),0);
		assertEquals(1030.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company5),0);
		assertEquals(1030.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company5),0);
	}
	
	@Test
	public void testCalculationComp6Veh1_18() {
		assertEquals(5035.0, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company6),0);
		assertEquals(3694.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company6),0);
		assertEquals(8363.0, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company6),0);
		assertEquals(129010.0, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company6),0);
		assertEquals(856.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company6),0);
		assertEquals(2678.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company6),0);
		assertEquals(4.722366482869645E24, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company6),0);
		assertEquals(9.44473296573929E24, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company6),0);
		assertEquals(5317.0, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company6),0);
		assertEquals(2032.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company6),0);
		assertEquals(2022.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company6),0);
		assertEquals(2022.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company6),0);
		assertEquals(17500.0, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company6),0);
		assertEquals(17520.0, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company6),0);
		assertEquals(17700.0, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company6),0);
		assertEquals(Double.POSITIVE_INFINITY, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company6),0);
		assertEquals(1030.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company6),0);
		assertEquals(1030.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company6),0);
	}
	
	@Test
	public void testCalculationComp7Veh1_18() {
		assertEquals(5035.0, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company7),0);
		assertEquals(3694.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company7),0);
		assertEquals(8363.0, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company7),0);
		assertEquals(129010.0, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company7),0);
		assertEquals(856.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company7),0);
		assertEquals(2678.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company7),0);
		assertEquals(4.722366482869645E24, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company7),0);
		assertEquals(9.44473296573929E24, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company7),0);
		assertEquals(5317.0, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company7),0);
		assertEquals(2032.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company7),0);
		assertEquals(2022.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company7),0);
		assertEquals(2022.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company7),0);
		assertEquals(17500.0, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company7),0);
		assertEquals(17520.0, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company7),0);
		assertEquals(17700.0, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company7),0);
		assertEquals(Double.POSITIVE_INFINITY, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company7),0);
		assertEquals(1030.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company7),0);
		assertEquals(1030.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company7),0);
	}
	
	@Test
	public void testCalculationComp8Veh1_18() {
		assertEquals(5035.0, calculation1.calculate(TestVehicle.vehicle1, TestCompany.company8),0);
		assertEquals(3694.0, calculation1.calculate(TestVehicle.vehicle2, TestCompany.company8),0);
		assertEquals(8363.0, calculation1.calculate(TestVehicle.vehicle3, TestCompany.company8),0);
		assertEquals(129010.0, calculation1.calculate(TestVehicle.vehicle4, TestCompany.company8),0);
		assertEquals(856.0, calculation1.calculate(TestVehicle.vehicle5, TestCompany.company8),0);
		assertEquals(2678.0, calculation1.calculate(TestVehicle.vehicle6, TestCompany.company8),0);
		assertEquals(4.722366482869645E24, calculation1.calculate(TestVehicle.vehicle7, TestCompany.company8),0);
		assertEquals(9.44473296573929E24, calculation1.calculate(TestVehicle.vehicle8, TestCompany.company8),0);
		assertEquals(5317.0, calculation1.calculate(TestVehicle.vehicle9, TestCompany.company8),0);
		assertEquals(2032.0, calculation1.calculate(TestVehicle.vehicle10, TestCompany.company8),0);
		assertEquals(2022.0, calculation1.calculate(TestVehicle.vehicle11, TestCompany.company8),0);
		assertEquals(2022.0, calculation1.calculate(TestVehicle.vehicle12, TestCompany.company8),0);
		assertEquals(17500.0, calculation1.calculate(TestVehicle.vehicle13, TestCompany.company8),0);
		assertEquals(17520.0, calculation1.calculate(TestVehicle.vehicle14, TestCompany.company8),0);
		assertEquals(17700.0, calculation1.calculate(TestVehicle.vehicle15, TestCompany.company8),0);
		assertEquals(Double.POSITIVE_INFINITY, calculation1.calculate(TestVehicle.vehicle16, TestCompany.company8),0);
		assertEquals(1030.0, calculation1.calculate(TestVehicle.vehicle17, TestCompany.company8),0);
		assertEquals(1030.0, calculation1.calculate(TestVehicle.vehicle18, TestCompany.company8),0);
	}
	
	

}
