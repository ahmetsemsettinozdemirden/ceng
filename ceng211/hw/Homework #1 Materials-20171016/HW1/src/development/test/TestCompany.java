package development.test;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

import development.Company;

public class TestCompany {
	
	protected static Company company1;
	protected static Company company2;
	
	protected static Company company3;
	protected static Company company4;
	protected static Company company5;
	
	protected static Company company6;
	protected static Company company7;
	protected static Company company8;
	
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		
		company1 = new Company(1.0 , 2.2, 3.5);
		company2 = new Company(0.01 , 1.5, 2.0);
		company3 = new Company(0.0 , 1.0, 1.0);
		company4 = new Company(1.0 , 0.0, 1.0);
		company5 = new Company(1.0 , 1.0, 0.0);
		company6 = new Company(-1.0, 1.0, 1.0);
		company7 = new Company(1.0 , -1.0, 1.0);
		company8 = new Company(1.0 , 1.0, -1.0);
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
	public void testCompanyNullObjects() {
		
		assertNotEquals(null, TestCompany.company1);
		assertNotEquals(null, TestCompany.company2);
		assertNotEquals(null, TestCompany.company3);
		assertNotEquals(null, TestCompany.company4);
		assertNotEquals(null, TestCompany.company5);
		assertNotEquals(null, TestCompany.company6);
		assertNotEquals(null, TestCompany.company7);
		assertNotEquals(null, TestCompany.company8);
	}
	
	@Test
	public void testCompanyGettersMethod(){
		
		assertEquals(1.0, TestCompany.company1.getWeightX(), 0);
		assertEquals(2.2, TestCompany.company1.getWeightY(), 0);
		assertEquals(3.5, TestCompany.company1.getWeightZ(), 0);
		
		assertEquals(0.01, TestCompany.company2.getWeightX(), 0);
		assertEquals(1.5, TestCompany.company2.getWeightY(), 0);
		assertEquals(2.0, TestCompany.company2.getWeightZ(), 0);
		
		assertEquals(1.0, TestCompany.company3.getWeightX(), 0);
		assertEquals(1.0, TestCompany.company3.getWeightY(), 0);
		assertEquals(1.0, TestCompany.company3.getWeightZ(), 0);
		
		assertEquals(1.0, TestCompany.company4.getWeightX(), 0);
		assertEquals(1.0, TestCompany.company4.getWeightY(), 0);
		assertEquals(1.0, TestCompany.company4.getWeightZ(), 0);
		
		assertEquals(1.0, TestCompany.company5.getWeightX(), 0);
		assertEquals(1.0, TestCompany.company5.getWeightY(), 0);
		assertEquals(1.0, TestCompany.company5.getWeightZ(), 0);
		
		assertEquals(1.0, TestCompany.company6.getWeightX(), 0);
		assertEquals(1.0, TestCompany.company6.getWeightY(), 0);
		assertEquals(1.0, TestCompany.company6.getWeightZ(), 0);
		
		assertEquals(1.0, TestCompany.company7.getWeightX(), 0);
		assertEquals(1.0, TestCompany.company7.getWeightY(), 0);
		assertEquals(1.0, TestCompany.company7.getWeightZ(), 0);
		
		assertEquals(1.0, TestCompany.company8.getWeightX(), 0);
		assertEquals(1.0, TestCompany.company8.getWeightY(), 0);
		assertEquals(1.0, TestCompany.company8.getWeightZ(), 0);
	}
	
	@Test
	public void testToString() {
		
		assertEquals("Company [weightX=" + TestCompany.company1.getWeightX() + ", weightY=" + TestCompany.company1.getWeightY() + ", weightZ=" + TestCompany.company1.getWeightZ() + "]", TestCompany.company1.toString());
		assertEquals("Company [weightX=" + TestCompany.company2.getWeightX() + ", weightY=" + TestCompany.company2.getWeightY() + ", weightZ=" + TestCompany.company2.getWeightZ() + "]", TestCompany.company2.toString());
		assertEquals("Company [weightX=" + TestCompany.company3.getWeightX() + ", weightY=" + TestCompany.company3.getWeightY() + ", weightZ=" + TestCompany.company3.getWeightZ() + "]", TestCompany.company3.toString());
		assertEquals("Company [weightX=" + TestCompany.company4.getWeightX() + ", weightY=" + TestCompany.company4.getWeightY() + ", weightZ=" + TestCompany.company4.getWeightZ() + "]", TestCompany.company4.toString());
		assertEquals("Company [weightX=" + TestCompany.company5.getWeightX() + ", weightY=" + TestCompany.company5.getWeightY() + ", weightZ=" + TestCompany.company5.getWeightZ() + "]", TestCompany.company5.toString());
		assertEquals("Company [weightX=" + TestCompany.company6.getWeightX() + ", weightY=" + TestCompany.company6.getWeightY() + ", weightZ=" + TestCompany.company6.getWeightZ() + "]", TestCompany.company6.toString());
		assertEquals("Company [weightX=" + TestCompany.company7.getWeightX() + ", weightY=" + TestCompany.company7.getWeightY() + ", weightZ=" + TestCompany.company7.getWeightZ() + "]", TestCompany.company7.toString());
		assertEquals("Company [weightX=" + TestCompany.company8.getWeightX() + ", weightY=" + TestCompany.company8.getWeightY() + ", weightZ=" + TestCompany.company8.getWeightZ() + "]", TestCompany.company8.toString());
	}
	

}
