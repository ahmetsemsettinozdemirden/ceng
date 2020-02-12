package question3enhancedsolution;

import java.util.Random;

public class Coin {
	private CoinFace face;
	private Random rand;
	
	public Coin() {	
		rand = new Random();
		face = null;
	}
	
	public CoinFace toss() {
		int random = rand.nextInt(2);
		
		if (random == 0) {
			face = CoinFace.HEAD;
		} else {
			face = CoinFace.TAIL;
		}
		
		return face;
	}

	public CoinFace getFace() {
		return face;
	}

	public void setFace(CoinFace face) {
		this.face = face;
	}

	@Override
	public String toString() {
		return "Coin [face=" + face + "]";
	}

}
