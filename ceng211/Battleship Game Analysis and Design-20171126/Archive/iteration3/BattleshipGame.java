package iteration3;

public class BattleshipGame {

	boolean endOfGame;
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
		createGameEntities();
		placeFleets();
		
		System.out.println("placing fleets completed");
	}
	
	private void createGameEntities() {
		board1 = new Board("1");
		board2 = new Board("2");
		player1 = new Player("1", board1);
		player2 = new Player("2", board2);
	}
	
	private void placeFleets() {
		player1.placeFleet(PlaceFleetMethod.MANUAL);
		player2.placeFleet(PlaceFleetMethod.DEFAULT);
	}
	
}
