// Name: Vladimir Kataev
//
// Program file: RandomFunTesterDriver.java
//
// Class Description: 

import java.util.Random;
import apcslib.*;
public class RandomFunTesterDriver{
    public static void main(String[] args){
	Random chooser = new Random();
	int choice = chooser.nextInt();
	DrawHouse house = new DrawHouse();
	house.draw();
    }
}
