package iteration1;

public class Board {
	
	String id;
	int numberOfRows;
	int numberOfColumns;
	
	public Board(String id) {
		this.id = id;
		numberOfRows = 10;
		numberOfColumns = 10;
		System.out.println("Board " + id + " created");
	}
}
