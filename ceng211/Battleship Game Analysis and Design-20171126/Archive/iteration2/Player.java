package iteration2;

public class Player {
	
	String id;
	Board board;
	Fleet fleet;
	
	public Player(String id, Board board) {
		this.id = id;
		this.board = board;
		fleet = new Fleet(id);
		System.out.println("Player " + id + " created");
	}
	
	
}
