// Name: Vladimir Kataev
//
// Program file: DrawHouseDriver.java
//
// Class Description: Calls DrawHouse.java, and it's draw method to draw a house with vector graphics

import apcslib.*;
public class DrawHouseDriver{
    public static void main(String[] args){
	DrawHouse house = new DrawHouse();
	house.draw();
    }
}
