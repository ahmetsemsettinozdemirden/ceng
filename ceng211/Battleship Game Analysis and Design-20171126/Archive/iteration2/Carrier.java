package iteration2;

public class Carrier {
	
	String id;
	final int size = 5;
	
	public Carrier(String id) {
		this.id = id;
		System.out.println(toString() + " created");
	}

	@Override
	public String toString() {
		return "Carrier [id=" + id + ", size=" + size + "]";
	}
	
}
