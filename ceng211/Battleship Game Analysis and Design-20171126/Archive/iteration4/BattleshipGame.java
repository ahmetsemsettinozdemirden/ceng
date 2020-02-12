package iteration4;

public class BattleshipGame {

	boolean endOfGame;
	Player player1, player2;
	
	public BattleshipGame() {
		player1 = null;
		player2 = null;
		System.out.println("BattleshipGame created");
	}
	
	public void start() {
		createPlayers();
		placeFleets();
		
		System.out.println("placing fleets completed");
		player1.getBoard().getBoardPresentation().printBoard();
		player2.getBoard().getBoardPresentation().printBoard();
	}
	
	private void createPlayers() {
		player1 = new Player("1");
		player2 = new Player("2");
	}
	
	private void placeFleets() {
		player1.placeFleet(PlaceFleetMethod.MANUAL);
		player2.placeFleet(PlaceFleetMethod.DEFAULT);
	}
	
}
