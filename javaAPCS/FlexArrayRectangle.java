public class FlexArrayRectangle{
	private int mySize;
	private Rectangle[] myArray;
	FlexArrayRectangle(){
		myArray = new Rectangle[20];
	}
	FlexArrayRectangle(int size){
		myArray = new Rectangle[size];
	}
	public int getLength(){
		return mySize;
	}
	public boolean isEmpty(){
		if(mySize == 0){
			return true;		
		}
		return false;
	}
	public String toString(){
		String back = new String("\n[");
		for(int i = 0; i++ < myArray.length -1;){
			try{
				back += ("\nRectangle:"+myArray[i].getLength()+","+myArray[i].getWidth());
			}
			catch(NullPointerException e){
				back += " ,";
			}
		}
		back += ("] ");
		return back;
	}
	public void append(Rectangle data){
		if(++mySize == myArray.length){
			resize();
		}
		myArray[mySize] = data;
	}
	private void resize(){
		Rectangle[] tmp = new Rectangle[myArray.length+1];
		for(int i = 0; i++ < myArray.length -1;){
			tmp[i] = myArray[i];	
		}
		myArray = tmp;
		//System.out.println(myArray.length);	remnant of debugging
		
	}
	public Rectangle discard(int index){
		if(index >= myArray.length || myArray[index] == null){return null;} // avoid questions
		else{
			mySize--;
			Rectangle tmp = myArray[index];
			myArray[index] = null;
			return tmp;
		}		

	}	
	public void insert(int index, Rectangle data){
		while(index > myArray.length-1){
			resize();
		}
		Rectangle tmp = myArray[index];
		if(tmp == null){
			mySize++;
		}
		myArray[index] = data;
	}

}