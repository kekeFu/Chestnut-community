package n2_lanqiao;

import java.util.Scanner;

public class A4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int f1 = 1, f2 = 1, f3 = 1;

		if (n > 2) {
			for (int i = 3; i <= n; i++) {
				f3 = (f1 + f2) % 10007;
				f1 = f2;
				f2 = f3;
			}
		}

		System.out.println(f3);
		scanner.close();
	}

}
