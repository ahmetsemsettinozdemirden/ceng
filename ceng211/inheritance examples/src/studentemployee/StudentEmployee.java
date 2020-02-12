package studentemployee;

public class StudentEmployee implements Student, Employee {

	protected StudentImpl studentImpl;
	protected EmployeeImpl employeeImpl;
	
	public StudentEmployee() {
		studentImpl = new StudentImpl();
		employeeImpl = new EmployeeImpl();
	}
	
	public float getGPA() {
		return studentImpl.getGPA(); //delegation
	}

	public float getSalary() {
		return employeeImpl.getSalary(); //delegation
	}

}
