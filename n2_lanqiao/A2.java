package n2_lanqiao;

import java.util.Scanner;
import java.math.BigInteger;


public class A2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 Scanner scanner = new Scanner(System.in);
		 BigInteger a = scanner.nextBigInteger();
		 BigInteger t1 = new BigInteger("1");
		 BigInteger t2 = new BigInteger("2");
		 t1 = t1.add(a);
		 a = a.multiply(t1);
		 a = a.divide(t2);
		 System.out.println(a);
		 scanner.close();
	}

}
