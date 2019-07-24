//import
public class toStringTest{
	public static void main(String[] args){
		ClientRecord a = new ClientRecord(0,"a");
		ClientRecord b = new ClientRecord(1,"b");
		GameBoard fg = new GameBoard(a,b);
		System.out.println(a.toString());
		System.out.println(b.toString());
		System.out.println(fg.toString());

	}
}