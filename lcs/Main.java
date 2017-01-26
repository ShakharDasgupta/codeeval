import java.util.Scanner;
import java.io.File;
import java.io.IOException;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File(args[0]));
		LCS lcs = new LCS();
		String line;
		while(sc.hasNextLine()) {
			if((line = sc.nextLine()).length() > 0) {
				Scanner sc1 = new Scanner(line).useDelimiter(";");
				System.out.println(lcs.longest(sc1.next(), sc1.next()));
			}
		}
	}
}

class LCS {
	public String longest(String s1, String s2) {
		int s1len = s1.length();
		String longest = "";
		for(int i = 0; i < s1len; i++) {
			String str = "";
			int index = 0;
			for(int j = i; j < s1len; j++) {
				char jchar = s1.charAt(j);
				int in = s2.indexOf(jchar, index);
				if(in > -1) {
					str += Character.toString(jchar);
					index = in;
				}
			}
			if(str.length() > longest.length())
				longest = str;
		}
		return longest;
	}
}
