package p156_Ananagrams;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Map<String, List<String>> map = new HashMap<String, List<String>>();
		PriorityQueue<String> outQueue = new PriorityQueue<String>();
		
		while(true){
			String word = sc.next();
			if(word.equals("#")) break;
			
			// we use the ordered lowercased word as a key
			String key = orderString(word);
			// case map doesn't contain key
			if(!map.containsKey(key)){
				map.put(key, new ArrayList<String>());
			}
			// add new word to map
			map.get(key).add(word);
		}
		// for every array of size 1 (which means that there is
		// no anagram on the dictionary, for that set of letters)
		// as so the only content of e is a ananagram
		for(List<String> e : map.values()){
			if(e.size() == 1){
				outQueue.add(e.get(0));
			}
		}
		
		// we use a PriorityQueue to get the given words in order
		while(!outQueue.isEmpty()){
			System.out.println(outQueue.poll());
		}
		
		sc.close();

	}
	
	private static String orderString(String toOrder){
		char[] c = toOrder.toLowerCase().toCharArray();
		Arrays.sort(c);
		String ret = String.valueOf(c);
		return ret;
	}

}
