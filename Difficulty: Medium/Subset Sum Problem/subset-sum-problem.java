//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {

            String input_line[] = read.readLine().trim().split("\\s+");
            int N = input_line.length;
            int arr[] = new int[N];
            for (int i = 0; i < N; i++) arr[i] = Integer.parseInt(input_line[i]);
            int sum = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            if (ob.isSubsetSum(arr, sum))
                System.out.println("true");
            else
                System.out.println("false");

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
    static Boolean solve(int i,int arr[],int sum,Boolean [][]dp){
        if(sum==0) return true;
        
        if(i>=arr.length || sum<0) return false;
        
        if(dp[i][sum]!=null) return dp[i][sum];
        
        Boolean take=false,ntake=false;
        take=solve(i+1,arr,sum-arr[i],dp);
        ntake=solve(i+1,arr,sum,dp);
        
        return dp[i][sum]=(take||ntake);
    }

    static Boolean isSubsetSum(int arr[], int sum) {
        // code here
        int n=arr.length;
        Boolean [][]dp=new Boolean[n+1][sum+1];
        return solve(0,arr,sum,dp);
    }
}