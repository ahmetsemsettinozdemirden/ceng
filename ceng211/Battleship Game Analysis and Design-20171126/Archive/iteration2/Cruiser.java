package iteration2;

public class Cruiser {
	
	String id;
	final int size = 3;
	
	public Cruiser(String id) {
		this.id = id;
		System.out.println(toString() + " created");
	}

	@Override
	public String toString() {
		return "Cruiser [id=" + id + ", size=" + size + "]";
	}

}
