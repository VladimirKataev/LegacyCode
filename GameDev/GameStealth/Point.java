//import
import java.lang.Math;
public class Point{
	double x, y;
	public Point(double a, double b){x = a; y = b;}
	public Point(Point a){x = a.x; y = a.y;}
	public double distance(Point a){
		return Math.hypot(a.x - x, a.y - y);
	}
}
