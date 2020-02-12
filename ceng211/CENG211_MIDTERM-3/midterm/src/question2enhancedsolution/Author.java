package question2enhancedsolution;

import java.util.ArrayList;

public class Author {
	
	private String name;
	private ArrayList<Book> books;
	
	public Author(String name) {
		this.name = name;
		books = new ArrayList<Book>();
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public ArrayList<Book> getBooks() {
		return books;
	}
	
	public void addBook(Book book) {
		if (book != null) {
			books.add(book);
		}
	}
	
	public void removeBook(Book book) {
		if (book != null && books.contains(book)) {
			books.remove(book);
		}
	}
	
	public boolean containsBook(Book book) {
		return books.contains(book);
	}
	
	public int numberOfBooks() {
		return books.size();
	}

	@Override
	public String toString() {
		return "Author [name=" + name + "]";
	}
}
