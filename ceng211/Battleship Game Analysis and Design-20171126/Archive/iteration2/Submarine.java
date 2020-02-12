package iteration2;

public class Submarine {
	
	String id;
	final int size = 3;
	
	public Submarine(String id) {
		this.id = id;
		System.out.println(toString() + " created");
	}

	@Override
	public String toString() {
		return "Submarine [id=" + id + ", size=" + size + "]";
	}

}
