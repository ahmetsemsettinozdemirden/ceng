package question2enhancedsolution;

public class BookApp {

	public static void main(String[] args) {
		
		BookList bookList = new BookList();
		AuthorList authorList = new AuthorList();
		DataAccessLayer dal = new DataAccessLayer("books.dat");
		
		dal.readBooks(bookList, authorList);
		
		System.out.println(bookList);
		System.out.println(authorList);
		
		System.out.println(bookList.calculateTotalPrice());
		System.out.println(authorList.getAuthorsWithMultipleBook());
	}

}
