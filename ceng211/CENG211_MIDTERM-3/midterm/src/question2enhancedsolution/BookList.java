package question2enhancedsolution;

import java.util.ArrayList;

public class BookList {
	
	private ArrayList<Book> bookList;
	
	public BookList() {
		bookList = new ArrayList<Book>();
	}
	
	public void addBook(Book book) {
		if (book != null) {
			bookList.add(book);
		}
	}
	
	public void removeBook(Book book) {
		if (book != null && bookList.contains(book)) {
			bookList.remove(book);
		}
	}
	
	public double calculateTotalPrice() {
		double totalPrice = 0.0d;
		
		for (Book book : bookList) {
			totalPrice += book.getPrice();
		}
		
		return totalPrice;
	}
	
	@Override
	public String toString() {
		return "BookList [bookList=" + bookList + "]";
	}
}
