public class FlexArrayPrimitive{
	private int mySize;
	private int[] myArray;
	FlexArrayPrimitive(){								// Works
		myArray = new int[20];
		mySize = 0;
	}
	FlexArrayPrimitive(int size){							//Works
		myArray = new int[size];
		mySize = 0;
	}
	public int getLength(){								//Works
		return mySize;
	}
	public boolean isEmpty(){							//Works
		if(mySize == 0){
			return true;		
		}
		return false;
	}
	public String toString(){							//Works
		String back = new String("[");
		for(int i = 0; i++ < myArray.length -1;){
			back += (myArray[i]+",");
		}
		back += (myArray[myArray.length-1]+"] ");
		return back;
	}
	public void append(int data){							//test						
		if(mySize == myArray.length){
			resize();
		}
		myArray[mySize++] = data;
	}
	public int discard(int index){							//Test
		if(index >= myArray.length || myArray[index] == 0){return -999;} // avoid questions
		else{
			mySize--;
			int tmp = myArray[index];
			myArray[index] = 0;
			return tmp;
		}		

	}	
	public void insert(int index, int data){					//FFFFFFIIIXXXX
		while(index > myArray.length){
			resize();
		}
		int tmp;
		resize();
		for(int i = 1; i < myArray.length-index-1; i++){
			tmp = myArray[index+i];
			myArray[index+i+1] = tmp;
		}
		myArray[index] = data;

	}
	public void sort(){								//Works
		for(int outer = 0; outer < myArray.length; outer++){
			int minIndex = findMin(outer);
			if(minIndex != outer){
				swap(outer,minIndex);		
			}
		}
	}
	public int compareTo(FlexArrayPrimitive f){					//Test
		int maxF = 0;
		int maxM = 0;
		for(int i = -1; ++i < f.getLength();){
			maxF += f.myArray[i];
		}
		for(int i = -1; ++i < getLength();){
			maxM += myArray[i];
		}
		return (maxM - maxF);
	}
	public int searchFor(int target){						//Test
		int n = -1;
		for(int i = 0; i++ < myArray.length;){
			if(myArray[i] == target){
				return i;	
			}
		}
		return n;
	}
	public int getValue(int loc){							//Test
		try{
		return myArray[loc];
		}
		catch(ArrayIndexOutOfBoundsException e){
			int n = -1;
			return n;
		}
	}
	public boolean equals(FlexArrayPrimitive f){					//Test
		if(f.getLength() == mySize){
			return true;
		}
		return false;
	}
	private void resize(){								//FFFFFIIIXXXX
		int[] tmp = new int[myArray.length+1];
		for(int i = 0; i < myArray.length; i++){
			tmp[i] = myArray[i];	
			//System.out.print((i)+"\t");		//Remnant of debugging
		}
		myArray = tmp;
		System.out.println(myArray.toString());		//remnant of debugging
		
	}
	private void swap(int a,int b){							//Works,for the sort
		int tmp = myArray[a];
		myArray[a] = myArray[b];
		myArray[b] = tmp;

	}

	private int findMin(int outer){							//Works,for the sort
		int min = myArray[outer];
		for(int i = outer-1; ++i < myArray.length;){
			if(myArray[i]<min){
				min = i;
			}
		}
		return min;
	}	
}