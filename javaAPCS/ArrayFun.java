import java.util.Random;
public class ArrayFun{
	public static void main(String [] args){
		Rectangle[] rectList = new Rectangle[5];
		rectList[0] = new Rectangle(5,10);
		rectList[1] = new Rectangle(15,10);
		rectList[2] = new Rectangle(25,20);
		rectList[3] = new Rectangle(35,40);
		rectList[4] = new Rectangle(45,40);
		System.out.println("3rd width: "+ rectList[3].getWidth() +" Length: "+rectList[3].getLength());
		rectList[4].setWidth(5);
		try{
			System.out.println("Da end is "+ rectList[5]);
	
		}
		catch(ArrayIndexOutOfBoundsException e){
			System.out.println("YOU FAILURE");
		
		}
		Random chooser = new Random();
		int[] intList = new int[10];
		for(int i = 0; i < 8 ; i++){
			intList[i] = chooser.nextInt(26)-10;
			System.out.print(intList[i] + " ");
		}

		int total = 0;
		for(int i = 0; i < intList.length; i++){
			total += intList[i];
		}
		System.out.println(total);

		int lowest = intList[0];
		for(int i = 0; i < intList.length; i++){
			if(intList[i] < lowest){
				lowest = intList[i];
			}
		}
		System.out.println(lowest);

	}

}
