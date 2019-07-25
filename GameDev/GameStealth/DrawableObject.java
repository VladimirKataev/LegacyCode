//import
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

public class DrawableObject extends GameObject{
  Point pos, ePos;  //Global position and effective screen position
  public DrawableObject(){
    pos = new Point(0,0);
  }
  public void draw(Graphics canvas){
    return;
  }
}
