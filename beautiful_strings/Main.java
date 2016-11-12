import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File(args[0]));
		Main beauty = new Main();
		while(sc.hasNextLine())
			System.out.println(beauty.maximumBeauty(sc.nextLine()));
		sc.close();
	}

	public int maximumBeauty(String s) {
		int[] freq = new int[26];
		for(int i = 0; i < s.length(); i++)
			if(Character.isLetter(s.charAt(i)))
				freq[Character.toUpperCase(s.charAt(i))-65]++;
		Arrays.sort(freq);
		int sum = 0;
		for(int i = 0; i < 26; i++)
			sum += freq[i] * (i + 1);
		return sum;
	}
}
