package iter3;

public class Fruit {
	private String name;
	private float calorieValue;
	
	public Fruit(String name, float calorieValue){
		setName(name);
		setCalorieValue(calorieValue);
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
	     if (name == null){		
			name = "apple";
		  }
	     this.name= name;
	}
	
	public float getCalorieValue() {
		return calorieValue;
	}
	
	public void setCalorieValue(float calorieValue) {
		if (calorieValue < 0.0f) {
		   calorieValue = 0.0f;
		}
		this.calorieValue = calorieValue;
	}

	
	
}
