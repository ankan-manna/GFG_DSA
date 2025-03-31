//{ Driver Code Starts
import java.util.*;
import java.util.Scanner;
import java.util.Stack;

class SortedStack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            Stack<Integer> s = new Stack<>();
            int n = sc.nextInt();
            while (n-- > 0) s.push(sc.nextInt());
            GfG g = new GfG();
            Stack<Integer> a = g.sort(s);
            while (!a.empty()) {
                System.out.print(a.peek() + " ");
                a.pop();
            }
            System.out.println();
        
System.out.println("~");
}
    }
}
// } Driver Code Ends


/*Complete the function below*/
class GfG {
    public void help(Stack<Integer>s,int prev){
        if(s.isEmpty()){
            s.push(prev);
            return;
        } 
        
        Stack<Integer>st=new Stack<Integer>();
        
        while(!s.isEmpty()&&s.peek()>prev){
            int ele=s.peek();
            s.pop();
            st.push(ele);
        }
        
        s.push(prev);
        while(!st.isEmpty() ){
            int ele=st.peek();
            st.pop();
            s.push(ele);
        }
        
    }
    public void solve(Stack<Integer>s){
        if(s.isEmpty()) return;
        
        int prev=s.peek();
        s.pop();
        solve(s);
        
        //
        help(s,prev);
    }
    public Stack<Integer> sort(Stack<Integer> s) {
        // add code here.
        solve(s);
        return s;
    }
}