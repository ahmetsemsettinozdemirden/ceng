package question2solution;

public class BookApp {

	public static void main(String[] args) {
		
		BookList list = new BookList();
		DataAccessLayer dal = new DataAccessLayer("books.dat");
		
		dal.readBooks(list);
		
		System.out.println(list);
		
		System.out.println(list.calculateTotalPrice());
		System.out.println(list.getAuthorsWithMultipleBook());
	}

}
