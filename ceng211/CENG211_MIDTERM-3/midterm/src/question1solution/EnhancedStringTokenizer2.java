package question1solution;

import java.util.ArrayList;
import java.util.StringTokenizer;

public class EnhancedStringTokenizer2 extends StringTokenizer {
	private ArrayList<String> tokens;
	
	public EnhancedStringTokenizer2(String theString) {
		super(theString);
		tokens = new ArrayList<String>();
	}
	
	public EnhancedStringTokenizer2(String theString, String delimiters) {
		super(theString, delimiters);
		tokens = new ArrayList<String>();
	}
	
	public String nextToken() {
		String token = super.nextToken();
		tokens.add(token);
		return token;
	}
	
	public String nextToken(String delimiters) {
		String token = super.nextToken(delimiters);
		tokens.add(token);
		return token;
	}
	
	public ArrayList<String> tokensSoFar() {
		ArrayList<String> arrayListToReturn = new ArrayList<String>();
		for (int i = 0; i< tokens.size(); i++) {
			arrayListToReturn.add(i, tokens.get(i));
		}
		
		return arrayListToReturn;
	}
}
