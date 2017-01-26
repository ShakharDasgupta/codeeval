import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		String line;
		UglyNumbers ugly = new UglyNumbers();
		while((line = in.readLine()) != null)
			System.out.println(ugly.countUglyNumbers(line));
		in.close();
	}
}

class UglyNumbers {

	public long countUglyNumbers(String digits) {
		long c = 0;
		if(digits.length() < 2)
			return isUgly(Long.parseLong(digits))?1:0;
		for(long i = 0; i < (long) Math.pow(3, digits.length() - 1); i++) {
			String terneryString = Long.toString(i, 3);
			if(isUgly(evaluate(constructExpression(digits, terneryString))))
				c++;
		}
		return c;
	}

	private String constructExpression(String digits, String terneryString) {
		StringBuilder sb = new StringBuilder(digits);
		char[] symbolIndices = new char[digits.length() - 1];
		Arrays.fill(symbolIndices, 0, digits.length() - 1 - terneryString.length(), '0');
		for(int i = 0; i < terneryString.length(); i++)
			symbolIndices[digits.length() - 1 - terneryString.length() + i] = terneryString.charAt(i);
		for(int i = 0, j = 1; i < symbolIndices.length; i++) {
			if(symbolIndices[i] == '0')
				j++;
			else if(symbolIndices[i] == '1') {
				sb.insert(j, '+');
				j += 2;
			}
			else if(symbolIndices[i] == '2') {
				sb.insert(j, '-');
				j += 2;
			}
		}
		return sb.toString();
	}

	private boolean isUgly(long n) {
		return n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0;
	}

	private long evaluate(String s) {
		long num = 0;
		long result = 0;
		boolean add = true;
		for(int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if(Character.isDigit(c))
				num = num * 10 + (c - '0');
			else if(c == '+') {
				result = add ? result + num : result - num;
				num = 0;
				add = true;
			}
			else if(c == '-') {
				result = add ? result + num : result - num;
				num = 0;
				add = false;
			}
		}
		result = add? result + num : result - num;
		return result;
	}
}
