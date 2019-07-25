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
		if(a.getCol() != b.getRow()){System.out.print(".");return null;}
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

	public static Matrix inverse(Matrix a) 
    	{	
        	int n = a.getRow();
		Matrix x = new Matrix(n,n);
		Matrix b = new Matrix(n,n);
        	int index[] = new int[n];

        	for (int i=0; i<n; ++i) 
        	    b.set(i,i,1);
 
 	       gaussian(a, index);
 
	        for (int i=0; i<n-1; ++i)
	            for (int j=i+1; j<n; ++j)
	                for (int k=0; k<n; ++k)
	                    b.add(index[j],k, -1*a.get(index[j],i)*b.get(index[i],k));
 
	        for (int i=0; i<n; ++i) 
        	{
        	    x.set(n-1,i, b.get(index[n-1],i)/a.get(index[n-1],n-1));
        	    for (int j=n-2; j>=0; --j) 
        	    {
        	        x.set(j,i,b.get(index[j],i));
        	        for (int k=j+1; k<n; ++k) 
        	        {
        	            x.add(j,i, -1*a.get(index[j],k)*x.get(k,i));
        	        }
        	        x.set(j,i, x.get(j,i) / a.get(index[j],j));
        	    }
        	}
        	return x;
    	}	
  
	public static void gaussian(Matrix a, int index[]) 
	{
		int n = index.length;
 		double c[] = new double[n];
		for (int i=0; i<n; ++i) 
        	    index[i] = i;
 	
	        for (int i=0; i<n; ++i) 
	        {
	            double c1 = 0;
	            for (int j=0; j<n; ++j) 
	            {
	                double c0 = Math.abs(a.get(i,j));
	                if (c0 > c1) c1 = c0;
	            }
	            c[i] = c1;
	        }
	        int k = 0;
	        for (int j=0; j<n-1; ++j) 
	        {
	            double pi1 = 0;
	            for (int i=j; i<n; ++i) 
	            {
	                double pi0 = Math.abs(a.get(index[i],j));
	                pi0 /= c[index[i]];
	                if (pi0 > pi1) 
	                {
	                    pi1 = pi0;
	                    k = i;
	                }
	            }
	 
                int itmp = index[j];
                index[j] = index[k];
                index[k] = itmp;
                for (int i=j+1; i<n; ++i) 	
         	{
	      		double pj = a.get(i,j) / a.get(j,i);
                	a.set(index[i],j, pj);
	                for (int l=j+1; l<n; ++l)
	                    a.add(index[i],l,-1*pj*a.get(index[j],l));
            	}
        }
    }
}