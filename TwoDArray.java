import java.util.Scanner;
import java.io.IOException;
import java.io.File;
import java.io.FileWriter;

public class TwoDArray {
  final private static int NUM = 6;
  
  public TwoDArray(){
  }
  
  public void load(int[][] grid){
    int row, col;
    String fileName = "data.txt";
    try{
    Scanner inFile = new Scanner(new File(fileName));
    for (row = 0; row < NUM; row++){
      for (col = 0; col < NUM; col++){
        grid[row][col] = inFile.nextInt();
      }
    }
    }catch(IOException e){
  	    System.out.println("Error: " + e.getMessage());
 	   }
  }
  
  public void display(int[][] grid){
    int row, col;
    for (row = 0; row < NUM; row++){
      for (col =0; col < NUM; col++){
        System.out.print(grid[row][col] + " ");
      }
      System.out.println();
    }
    System.out.println();
  }
  
  public void fun(int[][] grid){
    int row, col;
    for (row = 0; row < NUM; row++){
      for (col = 0; col < NUM; col++)
        if ((grid[row][col] % 2) == 0){
          grid[row][col] = 0;
        }
	}
  }
  
  public void numberOfDiagZeros(int[][] grid)
  {
	int[][] copy = new int[grid.length][grid[0].length];
	for(int i =0;i<copy.length;i++){
		for(int j = 0;j<copy[0].length;j++){
			copy[i][j] = grid[i][j];
		}
	}
	int num = 0;
	for(int x = 0; x < grid.length;x++){
		for(int y = 0; y < grid[x].length;y++){
			num = 0;
			try{
				if(copy[x-1][y-1] == 0){num++;}			
			}
			catch(ArrayIndexOutOfBoundsException e){}
			try{
				if(copy[x-1][y+1] == 0){num++;}			
			}
			catch(ArrayIndexOutOfBoundsException e){}
			try{
				if(copy[x+1][y-1] == 0){num++;}			
			}
			catch(ArrayIndexOutOfBoundsException e){}
			try{
				if(copy[x+1][y+1] == 0){num++;}			
			}
			catch(ArrayIndexOutOfBoundsException e){}
			grid[x][y] = num;

		}
	}
        
  }
}






