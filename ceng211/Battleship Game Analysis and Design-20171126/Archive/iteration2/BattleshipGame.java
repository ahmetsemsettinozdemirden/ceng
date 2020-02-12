package iteration2;

public class BattleshipGame {

	Board board1, board2;
	Player player1, player2;
	
	public BattleshipGame() {
		board1 = null;
		board2 = null;
		player1 = null;
		player2 = null;
		System.out.println("BattleshipGame created");
	}
	
	public void start() {
		board1 = new Board("1");
		board2 = new Board("2");
		player1 = new Player("1", board1);
		player2 = new Player("2", board2);
	}
	
}
