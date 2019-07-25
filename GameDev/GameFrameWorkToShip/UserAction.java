//import
public class UserAction{
	boolean up = false;
	boolean down = false;
	boolean left = false;
	boolean right = false;
	public UserAction(){
		boolean up = false;
		boolean down = false;
		boolean left = false;
		boolean right = false;
	}
	public void chg(int k, boolean u){
			if(k == 87){ up = u;}
			if(k == 83){ down = u;}
			if(k == 65){ left = u;}
			if(k == 68){ right = u;}
	}
	public boolean getLeft(){return left;}
	public boolean getRight(){return right;}//xD
	public boolean getUp(){return up;}
	public boolean getDown(){return down;}//xD

}