public class Solution_233{

	public static void main (String[] args) {
		Solution_233 sol = new Solution_233();
		System.out.println(sol.countDigitOne(1410065408));
	}

	public int countDigitOne(int n) {
		int res = 0;
		for (long i = 1; i <= n; i *= 10) {
			long a = n/i;
			long b = n%i;
			res += (a+8)/10*i;
			if (a%10 == 1) res += b + 1;
		}
		return res;
	}
}