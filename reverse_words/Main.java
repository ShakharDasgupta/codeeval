import java.util.Scanner;
import java.io.File;
import java.io.IOException;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc1 = new Scanner(new File(args[0]));
		while(sc1.hasNextLine()) {
			String line = sc1.nextLine();
			Scanner sc2 = new Scanner(line);
			String reverse = sc2.next();
			while(sc2.hasNext())
				reverse = sc2.next() + " " + reverse;
			System.out.println(reverse);
		}
	}
}
