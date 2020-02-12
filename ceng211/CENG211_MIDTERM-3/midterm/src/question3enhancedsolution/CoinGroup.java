package question3enhancedsolution;

import java.util.ArrayList;

public class CoinGroup {
	
	private ArrayList<Coin> coins;
	int groupSize;
	
	public CoinGroup(int groupSize) {
		this.groupSize = groupSize;
		coins = new ArrayList<Coin>(groupSize);
		for (int i = 0; i < groupSize; i++) {			
			coins.add(new Coin());
		}
	}
	
	public String tossAll() {
		String tossResult;
		tossResult = coins.get(0).toss()+",";
		for (int i = 1; i < groupSize; i++) {			
			tossResult = tossResult + coins.get(i).toss()+",";
		}
		
		return tossResult;
	}
	
	public void tossUntil(String pattern) {
		String tossAllResult;
		boolean flag = false;
		int tossCount = 0;
		while (!flag) {
			tossCount++;
			System.out.println("Toss : " + tossCount);
			tossAllResult = tossAll();
			System.out.println(tossAllResult);
			System.out.println("------------");
			flag = pattern.equals(tossAllResult);
		}
	}

}
