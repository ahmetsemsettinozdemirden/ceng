package iter7;


public class BasketApp {

	
	public static void main(String[] args) {
		
		Basket basket = new Basket();
		
		Fruit fruit1 = new Fruit("strawberry", 48.1f, Color.RED, Season.SUMMER);
		Fruit fruit2 = new Fruit("grape", 67.5f, Color.GREEN, Season.SUMMER);
		Fruit fruit3 = new Fruit("watermelon", 45.4f, Color.GREEN, Season.SUMMER);
		Fruit fruit4 = new Fruit("cherry", 63.2f, Color.RED, Season.SUMMER);
		Fruit fruit5 = new Fruit("peach", 39, Color.YELLOW, Season.SUMMER);
		Fruit fruit6 = new Fruit("orange", 47.8f, Color.YELLOW, Season.WINTER);
		Fruit fruit7 = new Fruit("pomegranate", 61, Color.RED, Season.WINTER);
		Fruit fruit8 = new Fruit("apple", 52, Color.GREEN, Season.WINTER);
		Fruit fruit9 = new Fruit("mandarin", 50.5f, Color.YELLOW, Season.WINTER);
		Fruit fruit10 = new Fruit("quince", 39.1f, Color.YELLOW, Season.WINTER);
		Fruit fruit11 = new Fruit("plum", 47.3f, Color.GREEN, Season.SUMMER);
		
		basket.addFruit(fruit1);
		basket.addFruit(fruit2);
		basket.addFruit(fruit3);
		basket.addFruit(fruit4);
		basket.addFruit(fruit5);
		basket.addFruit(fruit6);
		basket.addFruit(fruit7);
		basket.addFruit(fruit8);
		basket.addFruit(fruit9);
		basket.addFruit(fruit10);
		
		System.out.println(basket.getFruitsBySeason(Season.SUMMER));
		System.out.println(basket.getFruitsByColor(Color.GREEN));
		System.out.println("Number of fruits in the basket: "+basket.getNumberOfFruits());
		System.out.println("The total calorie of fruits in the basket: "+basket.calculateTotalCalorie());
		basket.removeFruit(fruit10);
		
		System.out.println("The total calorie of fruits in the basket: "+basket.calculateTotalCalorie());
		System.out.println("Number of fruits in the basket: "+basket.getNumberOfFruits());
		
		basket.removeFruit(fruit11);
		System.out.println("Number of fruits in the basket: "+basket.getNumberOfFruits());

		basket.removeFruit(null);
		System.out.println("Number of fruits in the basket: "+basket.getNumberOfFruits());

		basket.printFruits();
	}

}
