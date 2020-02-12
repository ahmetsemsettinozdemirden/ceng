package iteration5;

public class Board {
	
	Player player;
	String id;
	int numberOfRows;
	int numberOfColumns;
	String[][] resultMatrix;
	BoardPresentation boardPresentation;
	
	public Board(Player player, String id) {
		this.player = player;
		this.id = id;
		numberOfRows = 10;
		numberOfColumns = 10;
		resultMatrix = new String[numberOfRows][numberOfColumns];
		initializeResultMatrix();
		boardPresentation = new BoardPresentation(this);
		System.out.println("Board " + id + " created");
	}
	
	private void initializeResultMatrix() {
		for (int row = 0; row < numberOfRows; row++) { 
			for (int column = 0; column < numberOfColumns; column++) { 
				resultMatrix[row][column] = " ";
			}
		}
	}
	
	public void addShip(Coordinate coordinate){
		int row = coordinate.getRow();
		int column = coordinate.getColumn();
		resultMatrix[row][column] = "#";
	}

	public Player getPlayer() {
		return player;
	}

	public String getId() {
		return id;
	}

	public int getNumberOfRows() {
		return numberOfRows;
	}

	public int getNumberOfColumns() {
		return numberOfColumns;
	}

	public String getResultMatrixCell(int row, int column) {
		return resultMatrix[row][column];
	}

	public void setResultMatrixCell(int row, int column, Response response) {
		if (response == Response.HIT) resultMatrix[row][column] = "*";
		if (response == Response.MISS) resultMatrix[row][column] = "X";
	}

	public BoardPresentation getBoardPresentation() {
		return boardPresentation;
	}
	
}
