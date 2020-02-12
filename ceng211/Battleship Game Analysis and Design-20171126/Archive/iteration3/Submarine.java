package iteration3;

import java.util.ArrayList;

public class Submarine {
	
	String id;
	final int size = 3;
	ArrayList<Coordinate> position;
	
	public Submarine(String id) {
		this.id = id;
		position = new ArrayList<Coordinate>();
		System.out.println(toString() + " created");
	}

	public void addPosition(Coordinate coordinate) {
		position.add(coordinate);
	}

	@Override
	public String toString() {
		return "Submarine [id=" + id + ", size=" + size + "]";
	}

}
