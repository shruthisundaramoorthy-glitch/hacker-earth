

    import java.util.Scanner;
     
    public class MinCostPalindrome {
     
        public static int minCostToMakePalindrome(String str) {
            int[] count = new int[26]; 
            int oddCount = 0; 
     
            
            for (char c : str.toCharArray()) {
                count[c - 'a']++;
            }
     
            
            for (int i = 0; i < 26; i++) {
                if (count[i] % 2 != 0) {
                    oddCount++;
                }
            }
     
            
            return Math.max(oddCount - 1, 0);
        }
     
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            
            int t = sc.nextInt();
            while (t-- > 0) {
        
                int length = sc.nextInt();  
                String str = sc.next();  
     
                
                int cost = minCostToMakePalindrome(str);
                System.out.println(cost);
            }
     
            sc.close(); 
        }
    }

Language: Java 8
