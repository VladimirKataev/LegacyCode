// Writ by Vladimir Kataev
//
//Called Vowels.java
//
//it gets da input file, parses for 

import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
public class Vowels{
    public static void main(String[] args){
	Scanner reader;
	FileWriter out;
	try{
		out = new FileWriter("KATAEV_VLADIMIR_dentist.txt",false);
		reader = new Scanner (new File("poetry.txt"));
		int quantityVowelsA = 0;
		int quantityVowelsU = 0;
		int quantityVowelsO = 0;
		int quantityVowelsI = 0;
		int quantityVowelsE = 0;
		String nextLin;			//needed for 	  parsing
		char charParse;			//needed for meta-parsing
/*--------------------------------------------expired---------------------------
		while(reader.hasNext()){
			while(reader.hasNextLine()){
				next = reader.next();
				if(next == "a" || next == "A"){
					quantityVowelsA++;
				}		
				if(next == "i" || next == "I"){								//											The Indiana jones
					quantityVowelsI++;								//											Of the remnants
				}											//											of Debugging
				if(next == "e" || next == "E"){								//
					quantityVowelsE++;								//
				}											//
				if(next == "o" || next == "O"){								//
					quantityVowelsO++;
				}		
				if(next == "u" || next == "U"){
					quantityVowelsU++;
				}
				System.out.print(next + " ");
				if(next != " "){
					out.write(next + "~");
				}	
				out.write("\r\n");
				System.out.print("\n");
			}				
		}
-------------------------------------------------------------------------------------*/

		while(reader.hasNextLine()){
			nextLin = reader.nextLine();
			for(int i = 0; i < nextLin.length(); i++){
				charParse = nextLin.charAt(i);
				if(charParse == 'a' || charParse == 'A'){
					quantityVowelsA++;
				}
				if(charParse == 'i' || charParse == 'I'){				
					quantityVowelsI++;			
				}							
				if(charParse == 'e' || charParse == 'E'){				
					quantityVowelsE++;				
				}							
				if(charParse == 'o' || charParse == 'O'){				
					quantityVowelsO++;
				}		
				if(charParse == 'u' || charParse == 'U'){
					quantityVowelsU++;
				}
				System.out.print(charParse);
				if(charParse == ' '){
					out.write("~");
				}
				else{
				out.write(charParse);
				}	

			}
			System.out.print(nextLin + "\n");
			out.write("\r\n");

		}
		
		out.write("No. of A's:"+quantityVowelsA+" No. of E's:"+quantityVowelsE+" No. of I's:"+quantityVowelsI+" No. of O's:"+quantityVowelsO+" No. of U's:"+quantityVowelsU);
		out.close();
		//System.out.println("A:" + quantityVowelsA + "E:" + quantityVowelsE + "I:" + quantityVowelsI + "O:" + quantityVowelsO + "U:" + quantityVowelsU); 						Yet another archaelogical find
	}
	catch(IOException e){																						//	Ironically, never caught any exceptions
		System.out.println("Error reading file");	
	}

    }
}
