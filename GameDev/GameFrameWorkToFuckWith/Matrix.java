//import
//package com.vladimir.GameFramework;
public class Matrix{
	double[][] dat;
	public Matrix(int rows, int columns){
		dat = new double[rows][columns];
	}
	public void makeCamera(){
		for(int i = 0; i < dat.length; i++){
			dat[i][i] = 1.0;
		}
	}
	public void set(int row, int column, double data){
		try{
			dat[row][column] = data;
		}
		catch(Exception e){return;}
	}
	
	public double get(int row, int column){
		return dat[row][column];
	}
	public static Matrix multiply(Matrix a, Matrix b){
		if(a.getCol() != b.getRow()){return null;}
		int aR = a.getRow(); int bC = b.getCol(); int aC = a.getCol();
		Matrix toRtn = new Matrix(aR,bC);
		for(int i = 0; i < aR; i++){
			for(int j = 0; j < bC; j++){
				for(int k = 0; k < aC; k++){
					toRtn.add(i,j, a.get(i,k)*b.get(k,j));
				}
			}
		}
		return toRtn;
	}
	public int getRow(){return dat.length;}
	public int getCol(){return dat[0].length;}
	public void add(int row, int column, double data){
		try{
			dat[row][column] += data;
		}
		catch(Exception e){System.out.println("EXC");return;}
	}
}