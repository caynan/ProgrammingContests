package p579_ClockHands;

import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		while (true) {
			String in;
			String[] inArray;

			// read & format input
			in = sc.nextLine();
			inArray = in.split(":");
			int hour = Integer.parseInt(inArray[0]);
			int minute = Integer.parseInt(inArray[1]);

			// stop condition
			if (hour == 0 && minute == 0)
				break;

			// calculate angle
			Double angle = smallerClockAngle(hour, minute);

			// print result
			out.format("%.3f%n", angle);
		}

		out.close();
		sc.close();
	}

	private static Double smallerClockAngle(int H, int M) {
		Double eqResult = Math.abs(11.0 * M - 60.0 * H) / 2;

		return Math.min(eqResult, 360 - eqResult);
	}

}
