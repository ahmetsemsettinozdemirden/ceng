package question3solution;

public class FiveCoins {

	private Coin coins[];
	
	public FiveCoins() {
		coins = new Coin[]{new Coin(), new Coin(), new Coin(), new Coin(), new Coin()};
	}
	
	public boolean toss5ForAllHeads() {
		
		CoinFace toss;
		int headsCount = 0;
		
		for (int i = 0; i < coins.length; i++) {
			toss = coins[i].toss();
			
			System.out.print(toss + " ");
			
			if (toss == CoinFace.HEAD) {
				headsCount++;
			}
		}

		System.out.println();
		System.out.println("-----------------------");

		if (headsCount == 5) return true;
		else return false;
	}

	public void tossUntilAllHeads() {
		boolean allHeads = false;
		int tossCount = 0;
		while (!allHeads) {
			tossCount++;
			System.out.println("Toss : " + tossCount);
			allHeads = toss5ForAllHeads();
		}
	}
	
}
