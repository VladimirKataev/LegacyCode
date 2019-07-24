public class FlexArrayPrimitiveTester{
    public static void main(String[] args){
	FlexArrayPrimitive sup = new FlexArrayPrimitive(1);	//Should be size 3
	int[] stdArray = new int[3];
	stdArray[0] = 2;
	System.out.println(sup.toString());
	sup.append(1);
	System.out.println(sup.toString());
	sup.append(2);
	System.out.println(sup.toString());
    }

}
