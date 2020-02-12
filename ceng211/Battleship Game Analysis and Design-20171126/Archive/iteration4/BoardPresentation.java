package iteration4;

public class BoardPresentation {

	Board board;
	
	public BoardPresentation (Board board) {
		this.board = board;
	}
	
	public void printBoard() {
		System.out.println();
		System.out.println("Player " + board.getPlayer().getId());
		System.out.println();
		System.out.println("  0  1  2  3  4  5  6  7  8  9 ");
		for (int row = 0; row < board.getNumberOfRows(); row++) { 
			System.out.print(getRowTitle(row) + " ");
			for (int column = 0; column < board.getNumberOfColumns(); column++) { 
				System.out.print(board.getResultMatrixCell(row, column) + " ");
			}
			System.out.println();
		}		
	}
	
	private String getRowTitle(int row) {
		String stringRow = null;
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
		return stringRow;
	}
}
