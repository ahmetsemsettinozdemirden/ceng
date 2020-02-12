package iteration3;

import java.util.ArrayList;

public class Battleship {

	String id;
	final int size = 4;
	ArrayList<Coordinate> position;
	
	public Battleship(String id) {
		this.id = id;
		position = new ArrayList<Coordinate>();
		System.out.println(toString() + " created");
	}

	public void addPosition(Coordinate coordinate) {
		position.add(coordinate);
	}

	@Override
	public String toString() {
		return "Battleship [id=" + id + ", size=" + size + "]";
	}

}
