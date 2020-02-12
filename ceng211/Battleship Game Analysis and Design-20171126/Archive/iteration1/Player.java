package iteration1;

public class Player {
	
	String id;
	Board board;
	
	public Player(String id, Board board) {
		this.id = id;
		this.board = board;
		System.out.println("Player " + id + " created");
	}
	
	
}
