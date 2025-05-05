//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while (t-- > 0) {
            String str = in.readLine();
            Solution ob = new Solution();
            System.out.println(ob.palPartition(str));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    //static int count;
    static int []dp;
    static int palPartition(String s) {
        // code here
       // count=Integer.MAX_VALUE;
       dp=new int[s.length()];
       Arrays.fill(dp,-1);
        //solve(0,s,0);
        //return count;
        return solve(0,s)-1;
    }
    // static void solve(int idx,String s,int cut){
    //     if(idx==s.length()){
    //       count=Math.min(cut-1,count); 
    //     }
    //     for(int i=idx;i<s.length();i++){
    //         if(isPalindrome(s,idx,i)){
    //             solve(i+1,s,cut+1);
    //         }
    //     }
    // }
    
    static int solve(int idx,String s){
        if(idx==s.length()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int minCut=Integer.MAX_VALUE;
        for(int i=idx;i<s.length();i++){
            if(isPalindrome(s,idx,i)){
               int cut=1+solve(i+1,s);
               minCut=Math.min(minCut,cut);
            }
        }
        return dp[idx]=minCut;
    }
    
    static boolean isPalindrome(String s,int i,int j){
        while(i<=j){
            if(s.charAt(i)!=s.charAt(j))
            return false;
            i++;
            j--;
        }
        return true;
    }
}