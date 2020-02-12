package iteration4;

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

	public String getId() {
		return id;
	}

	public Carrier getCarrier() {
		return carrier;
	}

	public Battleship getBattleship() {
		return battleship;
	}

	public Submarine getSubmarine() {
		return submarine;
	}

	public Cruiser getCruiser() {
		return cruiser;
	}

	public Destroyer getDestroyer() {
		return destroyer;
	}

	@Override
	public String toString() {
		return "Fleet [id=" + id + ", carrier=" + carrier + ", battleship=" + battleship + ", submarine=" + submarine
				+ ", cruiser=" + cruiser + ", destroyer=" + destroyer + "]";
	}

}
