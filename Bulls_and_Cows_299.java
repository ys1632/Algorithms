public class Bulls_and_Cows_299{
    public static void main(String[] args) {
            System.out.println(getHint("1807", "7810"));
    }

    public static String getHint(String secret, String guess) {
            int bulls = 0;
            int cows = 0;
            int[] count = new int[10];
            
            for (int i = 0; i < secret.length(); i++) {
                if (secret.charAt(i) == guess.charAt(i)) {
                    bulls++;
                }
                else {
                    int cnt = ++count[secret.charAt(i) - '0'];
                    if (cnt <= 0) cows++;
                    cnt = --count[guess.charAt(i) - '0'];
                    if (cnt >= 0) cows++;
                }
            }
            
            return String.valueOf(bulls) + "A" + String.valueOf(cows) + "B";
    }
}