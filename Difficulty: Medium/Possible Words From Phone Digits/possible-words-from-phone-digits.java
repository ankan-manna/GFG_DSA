//{ Driver Code Starts
import java.io.*;
import java.util.*;

class IntArray {
    public static int[] input(BufferedReader br, int n) throws IOException {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(ArrayList<String> a) {
        for (String e : a) System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String arr[] = br.readLine().split(" ");
            int a[] = new int[arr.length];

            for (int i = 0; i < arr.length; i++) {
                a[i] = Integer.parseInt(arr[i]);
            }

            Solution obj = new Solution();
            ArrayList<String> v = obj.possibleWords(a);
            Collections.sort(v); // Sorting the ArrayList lexicographically
            IntArray.print(v);
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
    private void solve(int idx,int[] arr,StringBuilder sb,String[] map,ArrayList<String>ans){
        if(idx==arr.length){
            ans.add(sb.toString());
            return;
        }
        int num=arr[idx];
        String s=map[num];
        for(int i=0;i<s.length();i++){
            sb.append(s.charAt(i));
            solve(idx+1,arr,sb,map,ans);
            sb.delete(sb.length()-1,sb.length());
        }
    }
    public ArrayList<String> possibleWords(int[] arr) {
        // code here
        String []map={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        
        ArrayList<String>ans=new ArrayList<String>();
        solve(0,arr,new StringBuilder(),map,ans);
        return ans;
    }
}