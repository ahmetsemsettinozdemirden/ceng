package iteration3;

import java.util.ArrayList;

public class Destroyer {
	
	String id;
	final int size = 2;
	ArrayList<Coordinate> position;
	
	public Destroyer(String id) {
		this.id = id;
		position = new ArrayList<Coordinate>();
		System.out.println(toString() + " created");
	}

	public void addPosition(Coordinate coordinate) {
		position.add(coordinate);
	}

	@Override
	public String toString() {
		return "Destroyer [id=" + id + ", size=" + size + "]";
	}

}
