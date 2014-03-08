import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String number = new String();
		BigInteger sum = new BigInteger("0");
		while(sc.hasNext()){
			number = sc.next();
			if (number.equals("0")) break;
			sum = sum.add(new BigInteger(number));
		}
		System.out.println(sum.toString());
		sc.close();
	}

}
