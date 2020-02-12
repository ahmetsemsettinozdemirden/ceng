package iteration4;

import java.util.ArrayList;

public class Carrier {
	
	String id;
	final int size = 5;
	ArrayList<Coordinate> position;
	
	public Carrier(String id) {
		this.id = id;
		position = new ArrayList<Coordinate>();
		System.out.println(toString() + " created");
	}

	public void addPosition(Coordinate coordinate) {
		position.add(coordinate);
	}
	
	@Override
	public String toString() {
		return "Carrier [id=" + id + ", size=" + size + "]";
	}
	
}
