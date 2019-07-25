//import
import java.io.*;
import java.awt.*;
public class UserAction{
	boolean up = false;
	boolean down = false;
	boolean left = false;
	boolean right = false;
	boolean leftCam = false;
	boolean rightCam = false;
	boolean upCam = false;
	boolean downCam = false;
	int lastClickX,lastClickY;
	boolean mouseDown;
	public UserAction(){
		boolean up = false;
		boolean down = false;
		boolean left = false;
		boolean right = false;
		boolean mouseDown = false;
		boolean leftCam = false;
		boolean rightCam = false;
		boolean upCam = false;
		boolean downCam = false;

	}
	public void chg(int k, boolean u){
			if(k == 87){ up = u;}
			if(k == 83){ down = u;}
			if(k == 65){ left = u;}
			if(k == 68){ right = u;}
			if(k == 73){ upCam = u;}
			if(k == 75){ downCam = u;}
			if(k == 74){ leftCam = u;}
			if(k == 76){ rightCam = u;}

	}
	public void chg(int x, int y, boolean u){
		lastClickX = x;
		lastClickY = y;
		mouseDown = u;
		System.out.println("["+lastClickX + ":" + lastClickY + "]");
	}
	public boolean getLeft(){return left;}
	public boolean getRight(){return right;}//xD
	public boolean getUp(){return up;}
	public boolean getDown(){return down;}//xD
	public boolean getLeftCam(){return leftCam;}
	public boolean getRightCam(){return rightCam;}
	public boolean getUpCam(){return upCam;}
	public boolean getDownCam(){return downCam;}

	public int getLastClickX(){return lastClickX;}
	public int getLastClickY(){return lastClickY;}
	public boolean getMouseDown(){return mouseDown;}
}