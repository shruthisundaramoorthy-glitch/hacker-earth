import java.util.Scanner;
 
public class SignalStrength {
 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        
        for (int t = 0; t < testCases; t++) {
            int n = scanner.nextInt();
            String signal = scanner.next();
            System.out.println(maxConsecutiveHigh(signal));
        }
        
        scanner.close();
    }
 
    private static int maxConsecutiveHigh(String signal) {
        int maxCount = 0;
        int currentCount = 0;
 
        for (int i = 0; i < signal.length(); i++) {
            if (signal.charAt(i) == '1') {
                currentCount++;
                maxCount = Math.max(maxCount, currentCount);
            } else {
                currentCount = 0;
            }
        }
 
        return maxCount;
    }
}