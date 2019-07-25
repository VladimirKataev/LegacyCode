//import
import java.io.*;
import java.util.*;
public class FilePrinter{
	public static void main(String[] args)throws Exception{
		String get = "";
		Scanner reader = new Scanner(new File("info.txt"));
		try{
			while(reader.hasNextLine()){
				get = get + reader.nextLine() + "\n";
			}
		}
		catch(Exception e){
			System.out.println("oof");
		}
		System.out.print(get);
	}
}
