package n2_lanqiao;

import java.util.Scanner;
import java.math.BigInteger; 

public class A3 {

	public static void main(String[] args) {
		 Scanner scanner = new Scanner(System.in);
		 BigInteger a = scanner.nextBigInteger();
		 BigInteger b = scanner.nextBigInteger();
		 
		 System.out.println(a.add(b));
		 scanner.close();

	}

}
