package question3solution;

import java.util.Random;

public class Coin {
	private Random rand;
	
	public Coin() {	
		rand = new Random();
	}
	
	public CoinFace toss() {
		CoinFace type;
		int random = rand.nextInt(2);
		
		if (random == 0) {
			type = CoinFace.HEAD;
		} else {
			type = CoinFace.TAIL;
		}
		
		return type;
	}
}
