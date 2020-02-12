package question2solution;

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
	
	public void readBooks(BookList bookList) {
		String title = "default title";
		String author = "default author";
		double price = 0.0d;
		
		StringTokenizer tokenizer;
		
		
		while (scanner.hasNextLine()) {
			String line = scanner.nextLine();
			tokenizer = new StringTokenizer(line, ",");
			
			if (tokenizer.hasMoreTokens()) {
				title = tokenizer.nextToken();
			}
			
			if (tokenizer.hasMoreTokens()) {
				author = tokenizer.nextToken();
			}
			
			if (tokenizer.hasMoreTokens()) {
				price = Double.parseDouble(tokenizer.nextToken());
			}
			
			bookList.addBook(new Book(title, author, price));
		}
	}
}
