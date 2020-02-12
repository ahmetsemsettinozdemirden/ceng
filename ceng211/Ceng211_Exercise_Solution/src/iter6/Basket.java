package iter6;

import java.util.ArrayList;



public class Basket {

	// private int count;	
	private ArrayList<Fruit> fruitList ;

	public Basket(){
		fruitList = new ArrayList<Fruit>();
	}
	
	public void addFruit(Fruit fruit){
		if(fruit != null){
			fruitList.add(fruit);
		}
	}
	public void removeFruit(Fruit fruit){
		if(fruit!=null && fruitList.contains(fruit)){
			fruitList.remove(fruit);
		}
	}
	
	public void removeFromList(Fruit fruit){
		if(fruit!=null && fruitList.contains(fruit)){
			for(int i = 0; i < fruitList.size() ; i++){
				if(fruit.equals(fruitList.get(i))){
					fruitList.remove(i);
				}
			}
		}
		
	}
	
	public float calculateTotalCalorie() {
		float total = 0.0f;
		// for each loop
		for (Fruit fruit : fruitList) {
			total += fruit.getCalorieValue();
		}
		
		return total;
	}
	
	public int getNumberOfFruits() {
		return fruitList.size();
	}
	
	public ArrayList<Fruit> getFruitsByColor(Color color) {
		ArrayList<Fruit> resultList = new ArrayList<Fruit>();
		
		for (Fruit fruit : fruitList) {
			if (fruit.getColor().equals(color)) {
				resultList.add(fruit);
			}
		}
		
		return resultList;
	}
	
	public ArrayList<Fruit> getFruitsBySeason(Season season) {
		ArrayList<Fruit> resultList = new ArrayList<Fruit>();
		
		for (Fruit fruit : fruitList) {
			if (fruit.getSeason().equals(season)) {
				resultList.add(fruit);
			}
		}
		
		return resultList;
	}
	
	
}

