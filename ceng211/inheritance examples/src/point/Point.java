package point;

public class Point {
    private double x;   // Cartesian
    private double y;   // coordinates
   
    public Point() {
        x = 0.0;
        y = 0.0;
    }

    // create and initialize a point with given (x, y)
    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    // return Euclidean distance between invoking point p and q
    public double distanceTo(Point other) {
        double dx = this.x - other.x;
        double dy = this.y - other.y;
        return Math.sqrt(dx*dx + dy*dy);
    }

	@Override
	public String toString() {
		return "Point [x=" + x + ", y=" + y + "]";
	}

}
