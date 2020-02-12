package iteration5;

//TODO separate presentation and persistence from business for Player 
import java.util.Scanner;
import java.util.StringTokenizer;

public class Player {
	
	String id;
	Board board;
	Fleet fleet;
	int numberOfHits; //TODO replace with fleet totally sank
	
	public Player(String id) {
		this.id = id;
		board = new Board(this, id);
		fleet = new Fleet(id);
		numberOfHits = 0; //TODO replace with fleet totally sank
		System.out.println("Player " + id + " created");
	}
	
	public void placeFleet(PlaceFleetMethod placeFleetMethod) {
		if (placeFleetMethod == PlaceFleetMethod.DEFAULT) placeFleetByDefault();
		if (placeFleetMethod == PlaceFleetMethod.FILE) placeFleetFromFile();
		if (placeFleetMethod == PlaceFleetMethod.MANUAL) placeFleetManually();
		if (placeFleetMethod == PlaceFleetMethod.RANDOM) placeFleetRandomly();
	}

	public Shot takeShot(Scanner keyboard) {
		
		String keyboardInput;
		System.out.println("Enter coordinate of your shot : ");
		
		//TODO precondition check for coordinate of shot keyboard input

        keyboardInput = keyboard.nextLine();
			
		Coordinate coordinate = new Coordinate(keyboardInput);
		Shot shot = new Shot(coordinate);

		System.out.println("taking shot for player " + id + " completed");
		
		return shot;
	}

	public void getResponse(Shot shot) {
		Response response = checkShot(shot.getCoordinate());
		shot.setResponse(response);
		System.out.println("response from player " + id + " is " + response.toString());
		
		//TODO check the fleet if any ship get shot and if so mark it
		//fleet.informShot(shot);
	}
	
	public Response checkShot(Coordinate coordinate) {
		int row = coordinate.getRow();
		int column = coordinate.getColumn();
		if (board.getResultMatrixCell(row, column) == "#") {
			board.setResultMatrixCell(row, column, Response.HIT);
			numberOfHits++; //TODO replace with fleet totally sank
			return Response.HIT;
		}
		else {
			board.setResultMatrixCell(row, column, Response.MISS);
			return Response.MISS;
		}
	}

	public boolean checkEndOfGame() {
		//TODO replace with fleet totally sank
		if (numberOfHits == 17) return true;
		else return false;
	}
	
	public void placeFleetManually() {
		//TODO improve placeFleetManually()
		
		Scanner keyboard = new Scanner(System.in);
		String keyboardInput;
		StringTokenizer st;
		
		// example input for Carrier position : A1,A2,A3,A4,A5
		
		//TODO precondition check for Carrier position keyboard input
		
		System.out.println("Enter Carrier (size = 5) position : ");
		keyboardInput = keyboard.next();
		st = new StringTokenizer(keyboardInput, ",");
		while (st.hasMoreElements()) {
			String coordinateElement = st.nextElement().toString();
			System.out.println(coordinateElement);

			Coordinate coordinate = new Coordinate(coordinateElement);
			fleet.getCarrier().addPosition(coordinate);
			board.addShip(coordinate);
			System.out.println(coordinate.toString());
		}

		// example input for Battleship position : A1,A2,A3,A4
		
		//TODO precondition check for Battleship position keyboard input
		
		System.out.println("Enter Battleship (size = 4) position : ");
		keyboardInput = keyboard.next();
		st = new StringTokenizer(keyboardInput, ",");
		while (st.hasMoreElements()) {
			String coordinateElement = st.nextElement().toString();
			System.out.println(coordinateElement);

			Coordinate coordinate = new Coordinate(coordinateElement);
			fleet.getBattleship().addPosition(coordinate);
			board.addShip(coordinate);
			System.out.println(coordinate.toString());
		}

		// example input for Cruiser position : A1,A2,A3
		
		//TODO precondition check for Cruiser position keyboard input
		
		System.out.println("Enter Cruiser (size = 3) position : ");
		keyboardInput = keyboard.next();
		st = new StringTokenizer(keyboardInput, ",");
		while (st.hasMoreElements()) {
			String coordinateElement = st.nextElement().toString();
			System.out.println(coordinateElement);

			Coordinate coordinate = new Coordinate(coordinateElement);
			fleet.getCruiser().addPosition(coordinate);
			board.addShip(coordinate);
			System.out.println(coordinate.toString());
		}

		// example input for Submarine position : A1,A2,A3
		
		//TODO precondition check for Submarine position keyboard input
		
		System.out.println("Enter Submarine (size = 3) position : ");
		keyboardInput = keyboard.next();
		st = new StringTokenizer(keyboardInput, ",");
		while (st.hasMoreElements()) {
			String coordinateElement = st.nextElement().toString();
			System.out.println(coordinateElement);

			Coordinate coordinate = new Coordinate(coordinateElement);
			fleet.getSubmarine().addPosition(coordinate);
			board.addShip(coordinate);
			System.out.println(coordinate.toString());
		}

		// example input for Destroyer position : A1,A2
		
		//TODO precondition check for Destroyer position keyboard input
		
		System.out.println("Enter Destroyer (size = 2) position : ");
		keyboardInput = keyboard.next();
		st = new StringTokenizer(keyboardInput, ",");
		while (st.hasMoreElements()) {
			String coordinateElement = st.nextElement().toString();
			System.out.println(coordinateElement);

			Coordinate coordinate = new Coordinate(coordinateElement);
			fleet.getDestroyer().addPosition(coordinate);
			board.addShip(coordinate);
			System.out.println(coordinate.toString());
		}

		keyboard.close();
		System.out.println("placing fleet for player " + id + " manually completed");

	}
	
	public void placeFleetRandomly() {
		//TODO placeFleetRandomly()
	}

	public void placeFleetByDefault() {
		Coordinate coordinate;

		// place Carrier
		coordinate = new Coordinate(0, 0);
		fleet.getCarrier().addPosition(coordinate);
		board.addShip(coordinate);
		coordinate = new Coordinate(1, 0);
		fleet.getCarrier().addPosition(coordinate);
		board.addShip(coordinate);
		coordinate = new Coordinate(2, 0);
		fleet.getCarrier().addPosition(coordinate);
		board.addShip(coordinate);
		coordinate = new Coordinate(3, 0);
		fleet.getCarrier().addPosition(coordinate);
		board.addShip(coordinate);
		coordinate = new Coordinate(4, 0);
		fleet.getCarrier().addPosition(coordinate);
		board.addShip(coordinate);

		// place Battleship
		coordinate = new Coordinate(2, 2);
		fleet.getBattleship().addPosition(coordinate);
		board.addShip(coordinate);
		coordinate = new Coordinate(3, 2);
		fleet.getBattleship().addPosition(coordinate);
		board.addShip(coordinate);
		coordinate = new Coordinate(4, 2);
		fleet.getBattleship().addPosition(coordinate);
		board.addShip(coordinate);
		coordinate = new Coordinate(5, 2);
		fleet.getBattleship().addPosition(coordinate);
		board.addShip(coordinate);

		// place Cruiser
		coordinate = new Coordinate(5, 4);
		fleet.getCruiser().addPosition(coordinate);
		board.addShip(coordinate);
		coordinate = new Coordinate(6, 4);
		fleet.getCruiser().addPosition(coordinate);
		board.addShip(coordinate);
		coordinate = new Coordinate(7, 4);
		fleet.getCruiser().addPosition(coordinate);
		board.addShip(coordinate);

		// place Submarine
		coordinate = new Coordinate(7, 6);
		fleet.getSubmarine().addPosition(coordinate);
		board.addShip(coordinate);
		coordinate = new Coordinate(8, 6);
		fleet.getSubmarine().addPosition(coordinate);
		board.addShip(coordinate);
		coordinate = new Coordinate(9, 6);
		fleet.getSubmarine().addPosition(coordinate);
		board.addShip(coordinate);

		// place Destroyer
		coordinate = new Coordinate(0, 8);
		fleet.getDestroyer().addPosition(coordinate);
		board.addShip(coordinate);
		coordinate = new Coordinate(0, 9);
		fleet.getDestroyer().addPosition(coordinate);
		board.addShip(coordinate);

		System.out.println("placing fleet for player " + id + " by default completed");
	}
	
	public void placeFleetFromFile() {
		//TODO placeFleetFromFile()
	}

	public String getId() {
		return id;
	}

	public Board getBoard() {
		return board;
	}

	public Fleet getFleet() {
		return fleet;
	}

}
