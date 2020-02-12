package point;

import java.awt.Color;

public class ColoredPoint extends Point {

	private Color color;
	
	public ColoredPoint() {
		super();
		color = Color.black;
	}
	
	public ColoredPoint(double x, double y) {
		this(x, y, Color.black);
	}

	public ColoredPoint(double x, double y, Color color) {
		super(x ,y);
		this.color = color;
	}

	@Override
	public String toString() {
		return "ColoredPoint [color=" + color + super.toString();
	}

}
