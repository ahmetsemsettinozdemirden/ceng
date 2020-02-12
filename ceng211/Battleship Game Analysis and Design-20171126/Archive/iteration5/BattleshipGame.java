package iteration5;

import java.util.Scanner;

public class BattleshipGame {

	boolean endOfGame;
	Player player1, player2, winner;
	
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
		
		//TODO replace all Scanner operations with Swing 
		Scanner keyboard = new Scanner(System.in);
		endOfGame = false;
		while (!endOfGame) {
			Shot shot1 = player1.takeShot(keyboard);
			player2.getResponse(shot1);
			endOfGame = player2.checkEndOfGame();
			if (endOfGame) {
				winner = player1;
				continue;
			}
			Shot shot2 = player2.takeShot(keyboard);
			player1.getResponse(shot2);
			endOfGame = player1.checkEndOfGame();
			if (endOfGame) {
				winner = player2;
			}
		}
		keyboard.close();

		System.out.println("Game over. Winner is Player ID " + winner.getId());
		
	}
	
	private void createPlayers() {
		player1 = new Player("1");
		player2 = new Player("2");
	}
	
	private void placeFleets() {
		player1.placeFleet(PlaceFleetMethod.DEFAULT);
		player2.placeFleet(PlaceFleetMethod.DEFAULT);
	}
	
}
