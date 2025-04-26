//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

class GFG {
  public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    while (T-- > 0) {
      int n = sc.nextInt();
      int k = sc.nextInt();
      int a[] = new int[n];
      for(int i=0;i<n;i++){
        a[i]=sc.nextInt();
      }
     
      Solution obj = new Solution();
      boolean ans = obj.checkSubsequenceSum(n,a,k);
      System.out.println(ans?"Yes":"No");
    
System.out.println("~");
}
  }
}

// } Driver Code Ends




//User function Template for Java\





class Solution {
    public static boolean solve(int i,int N,int[] arr,int k,Boolean [][]dp){
        if(dp[i][k]!=null){
            return dp[i][k];
        }
        if(k==0){
            return true;
        }
        
        if(i>=N || k<0) return false;
        
        boolean take=false;
        if(k>=arr[i]){
           take= solve(i+1,N,arr,k-arr[i],dp);
        }
        boolean ntake=solve(i+1,N,arr,k,dp);
        
        return dp[i][k]=( take || ntake);
    }
  public static boolean checkSubsequenceSum(int N, int[] arr, int K) {
    // code here
    Boolean [][]dp=new Boolean[N+1][K+1];
        return solve(0,N,arr,K,dp);
  }
}
     