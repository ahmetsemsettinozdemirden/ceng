package iteration2;

public class Fleet {

	String id;
	Carrier carrier;
	Battleship battleship;
	Submarine submarine;
	Cruiser cruiser;
	Destroyer destroyer;

	public Fleet(String id) {
		this.id = id;
		carrier = new Carrier(id);
		battleship = new Battleship(id);
		submarine = new Submarine(id);
		cruiser = new Cruiser(id);
		destroyer = new Destroyer(id);
		System.out.println("Fleet " + id + " created");
	}
	
}
