package question2solution;

public class Book {
	private String title;
	private String author;
	private double price;
	
	public Book(String title, String author, double price) {
		setTitle(title);
		setAuthor(author);
		setPrice(price);
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		if (title == null) {
			title = "default title";
		}
		this.title = title;
	}

	public String getAuthor() {
		return author;
	}

	public void setAuthor(String author) {
		if (author == null) {
			author = "default author";
		}
		this.author = author;
	}

	public double getPrice() {
		return price;
	}

	public void setPrice(double price) {
		if (price < 0) {
			price = 0;
		}
		this.price = price;
	}

	@Override
	public String toString() {
		return "Book [title=" + title + ", author=" + author + ", price=" + price + "]";
	}
}
