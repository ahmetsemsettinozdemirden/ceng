package hw6.domain.test;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

import hw6.domain.Customer;
import hw6.domain.CustomerListAnalyticsImpl;
import hw6.domain.ICustomerListAnalytics;
import hw6.domain.customer.CustomerCreatorWithExceptions;

public class TestCustomerList {
	
	private int age = 28;
	private Customer customer;
	private ICustomerListAnalytics list;
	private CustomerCreatorWithExceptions creator;

	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
	}

	@AfterClass
	public static void tearDownAfterClass() throws Exception {
	}

	@Before
	public void setUp() throws Exception {
//		 buyer = ;
		 list = new CustomerListAnalyticsImpl();
		 creator = new CustomerCreatorWithExceptions();
		 
		 
		 char gender = 'f';
		 int customerAge = 22;
		 for(int i=0; i<10; i++) {	
			 if(i%3 == 0)
				 gender = 'm';
			 else
				 gender = 'f';
			 
			 if(i == 2)
				 customerAge = 35;
			 else if (i == 7)
				 customerAge = 60;
 
			customer = creator.createCustomer(customerAge++, gender, "Name_"+(i+1));
			list.add(customer);
		 }
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void testAddCustomer() {
		
		customer = creator.createCustomer(age, 'm', "Name_"+age++);
		assertTrue(list.add(customer));
		
		customer = creator.createCustomer(age, 'F', "Name_"+age++);
		assertTrue(list.add(customer));
		
		customer = creator.createCustomer(age, 'M', "Name_"+age++);
		assertTrue(list.add(customer));
		
		customer = null;
		assertFalse(list.add(customer));
		
		customer = creator.createCustomer(age+20, 'f', "Name_"+age++);
		assertTrue(list.add(customer));
		
		customer = creator.createCustomer(age+30, 'm', "Name_"+age++);
		assertTrue(list.add(customer));
		
		customer = creator.createCustomer(age+30, 'f', "Name_"+age++);
		assertTrue(list.add(customer));
	}
	
	@Test
	public void testGetNumberOfFemaleCustomers() {
		
		assertEquals(6, list.getNumberOfFemaleCustomers(), 0.0);
		customer = creator.createCustomer(age+20, 'F', "Name_"+age++);
		list.add(customer);
		assertEquals(7, list.getNumberOfFemaleCustomers(), 0.0);
		customer = creator.createCustomer(age+22, 'M', "Name_"+age++);
		list.add(customer);
		assertEquals(7, list.getNumberOfFemaleCustomers(), 0.0);
	}
	
	@Test
	public void testGetNumberOfMaleCustomers() {
		
		assertEquals(4, list.getNumberOfMaleCustomers(), 0.0);
		
		customer = creator.createCustomer(age+20, 'F', "Name_"+age++);
		list.add(customer);
		assertEquals(4, list.getNumberOfMaleCustomers(), 0.0);
		
		customer = creator.createCustomer(age+22, 'M', "Name_"+age++);
		list.add(customer);
		assertEquals(5, list.getNumberOfMaleCustomers(), 0.0);
		
		customer = creator.createCustomer(age+10, 'm', "Name_"+age++);
		list.add(customer);
		assertEquals(6, list.getNumberOfMaleCustomers(), 0.0);
	}
	
	@Test
	public void testGetNumberOfSeniorCustomers() {

		assertEquals(3, list.getNumberOfSeniorCustomers(), 0.0);
		
		customer = creator.createCustomer(age+35, 'F', "Name_"+age++);
		list.add(customer);
		
		customer = creator.createCustomer(age, 'F', "Name_"+age++);
		list.add(customer);
		
		assertEquals(4, list.getNumberOfSeniorCustomers(), 0.0);
	}
	

//	System.out.println(list.getNumberOfAdultCustomers());
//	System.out.println(list.getNumberOfYoungCustomers());
	
	
	@Test
	public void testGetNumberOfAdultCustomers() {

		assertEquals(5, list.getNumberOfAdultCustomers(), 0.0);
		
		customer = creator.createCustomer(35, 'f', "Name_"+age++);
		list.add(customer);
		
		customer = creator.createCustomer(19, 'M', "Name_"+age++);
		list.add(customer);
		
		assertEquals(6, list.getNumberOfAdultCustomers(), 0.0);
	}
	
	@Test
	public void testGetNumberOfYoungCustomers() {

		assertEquals(2, list.getNumberOfYoungCustomers(), 0.0);
		
		customer = creator.createCustomer(75, 'm', "Name_"+age++);
		list.add(customer);
		
		customer = creator.createCustomer(20, 'F', "Name_"+age++);
		list.add(customer);
		
		assertEquals(3, list.getNumberOfYoungCustomers(), 0.0);
	}
	
	@Test
	public void testGetNumberOfCustomersByCustomerType() {

		
		assertEquals(2, list.getNumberOfYoungCustomers(), 0.0);
		
		customer = creator.createCustomer(75, 'm', "Name_"+age++);
		list.add(customer);
		
		customer = creator.createCustomer(20, 'F', "Name_"+age++);
		list.add(customer);
		
		assertEquals(3, list.getNumberOfYoungCustomers(), 0.0);
	}
	
	@Test
	public void testToString() {
	
		
		ICustomerListAnalytics smallList = new CustomerListAnalyticsImpl();
		
		smallList.add(creator.createCustomer(22, 'f', "Pokemon"));
		smallList.add(creator.createCustomer(44, 'M', "Digimon"));
		smallList.add(creator.createCustomer(77, 'f', "Captain Tsubasa"));
		
		assertEquals("CustomerListImpl ["
				+ "buyers=["
				+ "Young [super=Customer [age=22, gender=f, name=Pokemon, type=Young]], "
				+ "Adult [super=Customer [age=44, gender=M, name=Digimon, type=Adult]], "
				+ "Senior [super=Customer [age=77, gender=f, name=Captain Tsubasa, type=Senior]]]]", smallList.toString());
	}

}
