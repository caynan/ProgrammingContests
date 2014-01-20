package p10038_JollyJumpers;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while (sc.hasNextInt()) {
			int n = sc.nextInt();
			int[] inArray = new int[n];
			
			// receive input & store into array
			for (int i = 0; i < n; i++) {
				inArray[i] = sc.nextInt();
			}
			
			// output result
			if(isJolly(n, inArray)){
				System.out.println("Jolly");
			}else{
				System.out.println("Not jolly");
			}
		}
		
	}

	private static boolean isJolly(int size, int[] inArray) {
		boolean[] seqArray = new boolean[size-1];
		boolean isJolly = true;
		
		// calculate abs difference & change
		// value in array
		for (int i = 0; i < size - 1; i++) {
			int index = Math.abs(inArray[i+1] - inArray[i]);
			if(index > size || index < 0) return false;
			seqArray[index-1] = true;
		}
		
		// check for false slots in seqArray,
		// if any the sequence is not jolly
		for (boolean b : seqArray){
			if(!b){
				isJolly = false;
			}
		}
		
		return isJolly;
	}

}