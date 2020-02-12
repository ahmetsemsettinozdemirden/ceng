package question2enhancedsolution;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.StringTokenizer;

public class DataAccessLayer {
	
	private Scanner scanner;
	
	public DataAccessLayer(String path) {
		try {
			scanner = new Scanner(new File(path));
		} catch (FileNotFoundException e) {
			System.out.println("File doesn not exist!");
		}
	}
	
	public void readBooks(BookList bookList, AuthorList authorList) {
		String bookTitle = "default title";
		String authorName = "default author";
		Book book = null;
		Author author = null;
		double bookPrice = 0.0d;
		
		StringTokenizer tokenizer;
		
		
		while (scanner.hasNextLine()) {
			String line = scanner.nextLine();
			tokenizer = new StringTokenizer(line, ",");
			
			if (tokenizer.hasMoreTokens()) {
				bookTitle = tokenizer.nextToken();
			}
			
			if (tokenizer.hasMoreTokens()) {
				authorName = tokenizer.nextToken();
			}
			
			if (tokenizer.hasMoreTokens()) {
				bookPrice = Double.parseDouble(tokenizer.nextToken());
			}
			
			author = authorList.getAuthorWithName(authorName);
			if (author == null) {
				author = new Author(authorName);
				authorList.addAuthor(author);
			}
			book = new Book(bookTitle, author, bookPrice);
			author.addBook(book);
			bookList.addBook(book);
		}
	}
}
