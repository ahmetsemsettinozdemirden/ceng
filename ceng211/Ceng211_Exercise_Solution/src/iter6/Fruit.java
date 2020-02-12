package iter6;


public class Fruit {
	private String name;
	private float calorieValue;
	private Color color;
	private Season season;
	
	public Fruit(String name, float calorieValue, Color color, Season season){
		setName(name);
		setCalorieValue(calorieValue);
		setColor(color);
		setSeason(season);
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
	
	public Color getColor() {
		return color;
	}

	public void setColor(Color color) {
		if(color == null) {
			color = Color.GREEN;	
		}
		this.color = color;
	}

	public Season getSeason() {
		return season;
	}

	public void setSeason(Season season) {
		if(season == null) {
			season = Season.SUMMER;	
		}
		this.season = season;
	
	}

	
	
}
