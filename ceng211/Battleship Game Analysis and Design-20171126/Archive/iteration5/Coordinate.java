package iteration5;

public class Coordinate {

	int row;
	int column;

	public Coordinate(int row, int column) {
		this.row = row;
		this.column = column;
	}

	public Coordinate(String coordinate) {
		//TODO improve Coordinate(String coordinate)
		
		//TODO precondition check for coordinate argument
		
		// A0 top left being <0,0>, B4 being <1,4>, and J9 bottom right being <9,9> 
		column = Integer.parseInt(coordinate.substring(1, 2));
		String stringRow = coordinate.substring(0, 1);
		switch(stringRow) {
			case "A": row = 0; break;
			case "B": row = 1; break;
			case "C": row = 2; break;
			case "D": row = 3; break;
			case "E": row = 4; break;
			case "F": row = 5; break;
			case "G": row = 6; break;
			case "H": row = 7; break;
			case "I": row = 8; break;
			case "J": row = 9; break;	
		}
	}
	
	public int getRow() {
		return row;
	}

	public int getColumn() {
		return column;
	}

	public String getBoardCoordinate() {
		//TODO improve getBoardCoordinate()
		
		String boardCoordinate, stringRow = null, stringColumn = null;
		stringColumn = String.valueOf(column);
		switch(row) {
		case 0: stringRow = "A"; break;
		case 1: stringRow = "B"; break;
		case 2: stringRow = "C"; break;
		case 3: stringRow = "D"; break;
		case 4: stringRow = "E"; break;
		case 5: stringRow = "F"; break;
		case 6: stringRow = "G"; break;
		case 7: stringRow = "H"; break;
		case 8: stringRow = "I"; break;
		case 9: stringRow = "J"; break;	
		}

		boardCoordinate = stringRow + stringColumn;
		return boardCoordinate;
	}

	@Override
	public String toString() {
		return "Coordinate [row=" + row + ", column=" + column + "]";
	}

}
