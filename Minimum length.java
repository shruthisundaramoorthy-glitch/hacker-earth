

    import java.util.Scanner;
     
    public class MinimumSubarraySort {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            
            int t = sc.nextInt(); 
            while (t-- > 0) {
                int n = sc.nextInt(); 
                int[] a = new int[n]; 
                int[] b = new int[n]; 
                
                for (int i = 0; i < n; i++) {
                    a[i] = sc.nextInt(); // Read elements of array a
                }
     
                for (int i = 0; i < n; i++) {
                    b[i] = sc.nextInt(); // Read elements of array b
                }
                
                System.out.println(findMinimumSubarrayLength(a, b, n));
            }
            
            sc.close();
        }
     
        private static int findMinimumSubarrayLength(int[] a, int[] b, int n) {
            int start = 0;
            int end = n - 1;
     
        
            while (start < n && a[start] == b[start]) {
                start++;
            }
     
     
            if (start == n) {
                return 0;
            }
     
        
            while (end >= 0 && a[end] == b[end]) {
                end--;
            }
     
        
            return end - start + 1;
        }
    }

Language: Java 8
