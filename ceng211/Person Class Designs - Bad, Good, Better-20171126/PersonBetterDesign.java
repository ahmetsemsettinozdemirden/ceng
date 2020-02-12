package week3;

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class PersonBetterDesign {

	private String firstName;
	private String lastName;
	private int yearOfBirth;

	public PersonBetterDesign(String firstName, String lastName, int yearOfBirth) {
		try {
			setFirstName(firstName);
			setLastName(lastName);
			setYearOfBirth(yearOfBirth);
		}
		catch(Exception e) {
			System.out.println(e);
			System.exit(-1);
		}
	}

	public String getFirstName() {
		return firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public int getYearOfBirth() {
		return yearOfBirth;
	}

	private void setFirstName(String firstName) throws Exception {
		if (nameChecker(firstName))
			this.firstName = firstName;
	}

	private void setLastName(String lastName) throws Exception {
		if (nameChecker(lastName))
			this.lastName = lastName;
	}

	private boolean nameChecker(String name) throws Exception {
		Pattern pattern = Pattern.compile(new String ("^[a-zA-Z\\s]*$"));
		Matcher matcher = pattern.matcher(name);
		if(matcher.matches()) {
			return true;
		}
		else {
			throw new Exception("name invalid");
		}		
	}

	private void setYearOfBirth(int yearOfBirth) throws Exception {
		if (1900 < yearOfBirth && yearOfBirth < 2016) {
			this.yearOfBirth = yearOfBirth;
		}
		else throw new Exception("year of birth out of range");
	}

	@Override
	public String toString() {
		return "PersonBetterDesign [firstName=" + firstName + ", lastName=" + lastName + ", yearOfBirth=" + yearOfBirth
				+ "]";
	}

}
