package question1solution;

import java.util.StringTokenizer;

public class EnhancedStringTokenizer extends StringTokenizer {
	private String[] tokens;
	private int count;
	
	public EnhancedStringTokenizer(String theString) {
		super(theString);
		tokens = new String[countTokens()];
		count = 0;
	}
	
	public EnhancedStringTokenizer(String theString, String delimiters) {
		super(theString, delimiters);
		tokens = new String[countTokens()];
		count = 0;
	}
	
	public String nextToken() {
		String token = super.nextToken();
		tokens[count] = token;
		count++;
		return token;
	}
	
	public String nextToken(String delimiters) {
		String token = super.nextToken(delimiters);
		tokens[count] = token;
		count++;
		return token;
	}
	
	public String[] tokensSoFar() {
		String[] arrayToReturn = new String[count];
		for (int i = 0; i< count; i++) {
			arrayToReturn[i] = tokens[i];
		}
		
		return arrayToReturn;
	}
}
