// Name: Vladimir Kataev
//
// Program file: RandomFunTester.java
//
// Class Description: randomly initialises a class and uses it's draw method; Classes may be DrawHouse/Square/Circle. In event of DrawCircle, select random radius between 30 and 50

import java.util.Random;
import apcslib.*;
public class RandomFunTester{
    public static void main(String[] args){
	Random chooser = new Random();
	int choice = chooser.nextInt(3) + 1;		// 3 is exclusive, so +1
	switch(choice){
		case 1:
			DrawHouse house = new DrawHouse();
			house.draw();
			break;
		case 2:
			DrawSquare square = new DrawSquare();
			square.draw();
			break;	
		case 3:
			DrawCircle circle = new DrawCircle();
			Random radiusSelector = new Random();
			circle.draw(radiusSelector.nextInt(31) + 20);	// minimum is 20, max is 50 (top exclusive, making 31)
			break;
		default:
			System.out.println("Error Message");
	}
    }
}
