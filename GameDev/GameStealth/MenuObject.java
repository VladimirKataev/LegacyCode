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

public class MenuObject extends DrawableObject{
  boolean inFocus = false;
  String text = "";
  public MenuObject(Point e, String en){
    pos = e;
    text = en;
  }
  public MenuObject(double a, double b, String c){
    pos = new Point(a, b);
    text = c;
  }
  public void draw(Graphics canvas){
    canvas.drawRect((int)this.pos.x, (int)this.pos.y, 50, 20);
    canvas.drawString(text,(int)this.pos.x + 5, (int)this.pos.y + 15);
    if(inFocus){
      canvas.setColor(Color.RED);
      canvas.drawRect((int)this.pos.x - 5,(int) this.pos.y - 5, 60, 30);
      canvas.setColor(Color.BLACK);

    }
  }
}
