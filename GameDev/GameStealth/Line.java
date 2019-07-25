//import
import java.lang.*;
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

public class Line{
	Point s,f, top, bottom, left, right;	//start and finish
	boolean horiz, vert;
	double length;
	public Line(){
		s = new Point(0,0);
		f = new Point(0,0);
		length = 0;
	}
	public Line(Point a, Point b){
		s = a;
		f = b;
		length = Math.hypot(a.x - b.x, a.y - b.y);
		if(s.x < f.x){
			left = s;
			right = f;
		}
		else{
			left = f;
			right = s;
		}
		if(s.y < f.y){
			top = f;
			bottom = s;
		}
		else{
			bottom = f;
			top = s;
		}
		if(a.x == b.x){
			vert  =true;
		}
		if(a.y == b.y){
			horiz = true;
		}
	}
	public Line(double a, double b, double c, double d){
		s = new Point(a,b);
		f = new Point(c,d);
		if(s.x < f.x){
			left = s;
			right = f;
		}
		else{
			left = f;
			right = s;
		}
		if(s.y < f.y){
			top = f;
			bottom = s;
		}
		else{
			bottom = f;
			top = s;
		}
		if(a == c){
			vert  =true;
		}
		if(b == d){
			horiz = true;
		}

		length = Math.hypot(a-c, b-d);
	}
	public boolean intersects(Line t){

		/*
		if((t.bottom.y > top.y)
		|| (t.top.y < bottom.y)
		|| (t.left.x > right.x)
		|| (t.right.x < left.x)){	// general rectangle checking
			return false;
		}
		*/
		boolean  a = orientsClockwise(s,f,t.s);
		boolean  b = orientsClockwise(s,f,t.f);
		boolean  c = orientsClockwise(t.s,t.f,s);
		boolean  d = orientsClockwise(t.s,t.f,f);
		if(a != b && c != d){
					return true;
		}
		return false;
	}
	public void change(Point a, Point b){
		s = a;
		f = b;
		length = Math.hypot(a.x - b.x, a.y - b.y);
		if(s.x < f.x){
			left = s;
			right = f;
		}
		else{
			left = f;
			right = s;
		}
		if(s.y < f.y){
			top = f;
			bottom = s;
		}
		else{
			bottom = f;
			top = s;
		}
		if(a.x == b.x){
			vert  =true;
		}
		if(a.y == b.y){
			horiz = true;
		}
	}
	public double length(){
		length = Math.hypot(s.x - f.x, s.y - f.y);
		return length;
	}
	public static boolean orientsClockwise(Point A, Point B, Point C){
		return( ((B.y - A.y) * (C.x - B.x) - (B.x - A.x) * (C.y - B.y) ) >0);
	}
	public static void main(String[] args){	// Here for testing
		Line test1 = new Line(0,0,3,4);
		Line test2 = new Line(2,0,0,1); // colls with 1
		Line test3 = new Line(0,5,-2,6);	// colinear with 2
											//	This should be true
		System.out.println(test1.intersects(test2) + " <> " + test2.intersects(test3));

		System.out.println(orientsClockwise(test1.s, test1.f, test2.s ));
		System.out.println(orientsClockwise(test1.s, test1.f, test2.f ));
		System.out.println(orientsClockwise(test2.s, test2.f, test1.s ));
		System.out.println(orientsClockwise(test2.s, test2.f, test1.f ));
	}
	public void draw(Graphics canvas){
		canvas.drawLine((int)s.x, (int)s.y,(int) f.x, (int)f.y);

	}
}
