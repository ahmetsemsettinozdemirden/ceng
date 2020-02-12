package iteration2;

public class Destroyer {
	
	String id;
	final int size = 2;
	
	public Destroyer(String id) {
		this.id = id;
		System.out.println(toString() + " created");
	}

	@Override
	public String toString() {
		return "Destroyer [id=" + id + ", size=" + size + "]";
	}

}
