package iteration4;

import java.util.ArrayList;

public class Cruiser {
	
	String id;
	final int size = 3;
	ArrayList<Coordinate> position;
	
	public Cruiser(String id) {
		this.id = id;
		position = new ArrayList<Coordinate>();
		System.out.println(toString() + " created");
	}

	public void addPosition(Coordinate coordinate) {
		position.add(coordinate);
	}

	@Override
	public String toString() {
		return "Cruiser [id=" + id + ", size=" + size + "]";
	}

}
