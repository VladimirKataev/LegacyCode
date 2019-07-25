//import
import java.util.Scanner;
import java.util.ArrayList;
import java.io.DataInputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import javax.swing.JFrame;

public class Wall extends DrawableObject{
	Point a, b;
	Line lineRepresentation;
	boolean vert, horiz;
	public Wall(double a1, double b1, double c, double d){
		a = new Point(a1,b1);
		b = new Point(c,d);
		lineRepresentation = new Line(a,b);
		if(a1 == c){
			vert = true;
		}
		if(b1 == d){
			horiz = true;
		}
	}
	public void draw(Graphics canvas){
		canvas.drawLine((int)a.x,(int) a.y,(int) b.x,(int) b.y);
	}


}
