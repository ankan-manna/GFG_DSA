//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int N = sc.nextInt();
            int[][] arr = new int[N][3];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < 3; j++) {
                    arr[i][j] = sc.nextInt();
                }
            }
            Solution obj = new Solution();
            int res = obj.maximumPoints(arr);
            System.out.println(res);

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    private int solve(int idx,int prev,int arr[][],int [][]dp){
        int maxi=0;
        if(idx==0){
            maxi=0;
            for(int i=0;i<3;i++){
                if(i!=prev){
                    maxi=Math.max(maxi,arr[idx][i]);
                }
            }
            return maxi;
        }//base case -> if idx==o then it does not further call recurisive
        
        if(dp[idx][prev]!=-1) return dp[idx][prev];
        
        maxi=0;
        int points=0;
        for(int i=0;i<3;i++){
            if(i!=prev){
                points=arr[idx][i]+solve(idx-1,i,arr,dp);
                
                maxi=Math.max(maxi,points);
            }
        }
        
        return dp[idx][prev]=maxi;
    }
    public int maximumPoints(int arr[][]) {
        // code here
        int n=arr.length;
        int [][]dp=new int[n][4];
        for(int i=0;i<n;i++){
            int []row= dp[i];
            Arrays.fill(row,-1);
        }
        //due to we alawys have 3 columns
       return solve(n-1,3,arr,dp);
    }
}