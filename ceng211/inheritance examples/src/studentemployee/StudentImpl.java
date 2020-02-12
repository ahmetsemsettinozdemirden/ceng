package studentemployee;

public class StudentImpl implements Student {
	
	protected float gpa;
	
	public float getGPA() {
		System.out.println("GPA");
		return 100;
	}
}
