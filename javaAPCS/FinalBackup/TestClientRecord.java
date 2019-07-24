//import
public class TestClientRecord{
	public static void main(String[] args){
		ClientRecord a = new ClientRecord(0,"Vladimir");
		String txt = a.toString();		
		System.out.println(txt);
		ClientRecord b = new ClientRecord(txt);
		System.out.println(b.toString());
	}
}