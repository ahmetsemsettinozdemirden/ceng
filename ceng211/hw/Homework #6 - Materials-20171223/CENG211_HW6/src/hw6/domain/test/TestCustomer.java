package hw6.domain.test;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import org.hamcrest.CoreMatchers;

import hw6.domain.Customer;
import hw6.domain.customer.CustomerCreatorWithExceptions;

public class TestCustomer {

	private Customer customer;
	private CustomerCreatorWithExceptions creator;
	private CoreMatchers matcher;
	
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {	
	}

	@AfterClass
	public static void tearDownAfterClass() throws Exception {
	}

	@Before
	public void setUp() throws Exception {
		creator = new CustomerCreatorWithExceptions();
		matcher = new CoreMatchers();
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void testCreateCustomer() {
		 
		try {
			creator.createCustomer(5, 'm', "Jack");
			fail();
        } catch (IllegalArgumentException e) {
        	assertThat(e.getMessage(), matcher.is("Invalid Age Parameter"));
        }
		
		try {
			creator.createCustomer(27, 'T', "Carl");
			fail();
        } catch (IllegalArgumentException e) {
        	assertThat(e.getMessage(), matcher.is("Invalid Gender Parameter"));
        }
		
		try {
			creator.createCustomer(33, 'f', null);
			fail();
        } catch (IllegalArgumentException e) {
        	assertThat(e.getMessage(), matcher.is("Invalid Name Parameter! Name can not be null or longer than 20 char"));
        }
		
		try {
			creator.createCustomer(44, 'M', "Fernando Miguel Alvarez Iglesias");
			fail();
        } catch (IllegalArgumentException e) {
        	assertThat(e.getMessage(), matcher.is("Invalid Name Parameter! Name can not be null or longer than 20 char"));
        }
	}
	
	@Test
	public void testToString() {
		
		customer = creator.createCustomer(44, 'M', "Ash Ketchup");		
		assertEquals("Adult [super="+"Customer [age=" + customer.getAge() + ", gender=" + customer.getGender() + ", name=" + customer.getName() + ", type=" + customer.getType() + "]]", customer.toString());
		
		customer = creator.createCustomer(27, 'f', "Misty");
		assertEquals("Young [super="+"Customer [age=" + customer.getAge() + ", gender=" + customer.getGender() + ", name=" + customer.getName() + ", type=" + customer.getType() + "]]", customer.toString());
		
		customer = creator.createCustomer(66, 'm', "Brock");
		assertEquals("Senior [super="+"Customer [age=" + customer.getAge() + ", gender=" + customer.getGender() + ", name=" + customer.getName() + ", type=" + customer.getType() + "]]", customer.toString());
	}

}
