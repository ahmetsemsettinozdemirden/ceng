package iteration2;

public class Battleship {

	String id;
	final int size = 4;
	
	public Battleship(String id) {
		this.id = id;
		System.out.println(toString() + " created");
	}

	@Override
	public String toString() {
		return "Battleship [id=" + id + ", size=" + size + "]";
	}

}
