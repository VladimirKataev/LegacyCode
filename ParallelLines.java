import apcslib.*;
public class ParallelLines{
	public static void main(String args[]){
		SketchPad paper =  new SketchPad(700,400);
		DrawingTool pen = new DrawingTool(paper); 
		for(int i = 0; i< 8; i++){
			pen.home();			
			pen.up();
			int y = 150-(50*i);
			int x = -350;
			pen.move(x, y );
			pen.down();
			pen.move(350,y);

			for(int j = 0; j< 7; j++){
				int offset;
				if(i % 4 == 1){
					offset = 0;
				}
				else if(i % 4 == 2 || i % 4 == 0){
					offset = 10;			
				}
				else{
					offset = 20;
				}
				pen.up();
				pen.move(x+25+(100*j)+ offset,y+25);
				pen.down();
				pen.fillRect(50,50);
				pen.up();
			}
		}
	}
}