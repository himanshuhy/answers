import java.util.*;
import java.lang.*;
import java.math.*;

class FCTRL2{
	public static void main(String args[]) throws java.lang.Exception{
		//System.out.println("Hello World!");
		Scanner in = new Scanner(System.in);
		int t=in.nextInt();
		while(t-- != 0){
			BigInteger big = BigInteger.valueOf(1);
			int n = in.nextInt();
			for(int i=2; i<=n; ++i)
				big = big.multiply(BigInteger.valueOf(i));
			System.out.println(big);
		}
		in.close();
	}
}