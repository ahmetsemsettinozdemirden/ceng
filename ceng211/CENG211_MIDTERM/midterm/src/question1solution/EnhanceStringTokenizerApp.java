package question1solution;

import java.util.ArrayList;
import java.util.Arrays;

public class EnhanceStringTokenizerApp {

	public static void main(String[] args) {
		EnhancedStringTokenizer tokenizer = new EnhancedStringTokenizer("This is a sample sentence");
		EnhancedStringTokenizer2 tokenizer2 = new EnhancedStringTokenizer2("This is a sample sentence");
		
		ArrayList<String> tokens = new ArrayList<String>();
		
		int counter = 0;
		while(tokenizer.hasMoreElements()) {
			String token = tokenizer.nextToken();
			System.out.println(counter + "th word is " + token);
			tokens.add(token);
			
			counter++;
		}
		
		counter = 0;
		while(tokenizer2.hasMoreElements()) {
			String token = tokenizer2.nextToken();
			System.out.println(counter + "th word is " + token);
			
			counter++;
		}
		
		System.out.println("Tokens So Far from method: " + Arrays.toString(tokenizer.tokensSoFar()));
		System.out.println("Tokens So Far from main: " + tokens.toString());
		System.out.println("Tokens So Far from method: " + tokenizer2.tokensSoFar().toString());
		
	}

}
