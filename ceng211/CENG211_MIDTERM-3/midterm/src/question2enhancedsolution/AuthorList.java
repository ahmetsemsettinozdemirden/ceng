package question2enhancedsolution;

import java.util.ArrayList;

public class AuthorList {

	private ArrayList<Author> authorList;
	
	public AuthorList() {
		authorList = new ArrayList<Author>();
	}
	
	public void addAuthor(Author author) {
		if (author != null) {
			authorList.add(author);
		}
	}
	
	public void removeAuthor(Author author) {
		if (author != null && authorList.contains(author)) {
			authorList.remove(author);
		}
	}

	public Author getAuthorWithName(String authorName) {
		Author authorFound = null;
		for(Author author: authorList) {
			if (author.getName().equals(authorName)) {
				authorFound = author;
				break;
			}
		}
		return authorFound;
	}
	
	public ArrayList<String> getAuthorsWithMultipleBook() {
		ArrayList<String> result = new ArrayList<String>();
		
		for (Author author : authorList) {
			if (author.numberOfBooks() > 1)
				result.add(author.toString());
		}
		
		return result;
	}

	@Override
	public String toString() {
		return "AuthorList [authorList=" + authorList + "]";
	}

}
