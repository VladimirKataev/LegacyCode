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
	boolean getPos = false;

	public UserAction(){
		/*
		boolean up = false;
		boolean down = false;
		boolean left = false;
		boolean right = false;
		boolean mouseDown = false;
		boolean leftCam = false;
		boolean rightCam = false;
		boolean upCam = false;
		boolean downCam = false;
		*/
		boolean getPos = false;

	}
	public void chg(int k, boolean u){
			/*
			if(k == 87){ up = u;}		//W
			if(k == 83){ down = u;}		//S
			if(k == 65){ left = u;}		//A
			if(k == 68){ right = u;}	//D
			if(k == 73){ upCam = u;}	//I
			if(k == 75){ downCam = u;}	//K
			if(k == 74){ leftCam = u;}	//J
			if(k == 76){ rightCam = u;}	//L
			*/
			if(k == 71){ getPos = u;}


	}
	public void chg(int x, int y, boolean u){
		lastClickX = x;
		lastClickY = y;		
		mouseDown = u;
		System.out.println("["+lastClickX + ":" + lastClickY + "]");
	}

	/*
	public boolean getLeft(){return left;}
	public boolean getRight(){return right;}//xD
	public boolean getUp(){return up;}
	public boolean getDown(){return down;}//xD
	public boolean getLeftCam(){return leftCam;}
	public boolean getRightCam(){return rightCam;}
	public boolean getUpCam(){return upCam;}
	public boolean getDownCam(){return downCam;}
	*/

	public int getLastClickX(){return lastClickX;}
	public int getLastClickY(){return lastClickY;}
	public boolean getMouseDown(){return mouseDown;}
	public boolean getGetPos(){return getPos;}

}