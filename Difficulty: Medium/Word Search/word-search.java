//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt(); // Number of test cases
        while (tc-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            char[][] mat = new char[n][m];

            // Reading the matrix
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = sc.next().charAt(0);
                }
            }

            String word = sc.next();
            Solution obj = new Solution();
            boolean ans = obj.isWordExist(mat, word);
            if (ans)
                System.out.println("true");
            else
                System.out.println("false");

            System.out.println("~");
        }
        sc.close();
    }
}
// } Driver Code Ends


class Solution {
    static public boolean isWordExist(char[][] mat, String word) {
        // Code here
        int m=mat.length;
        int n=mat[0].length;
        int [][]vis=new int[m][n];
        for(int i=0;i<m;i++){
            int []row=vis[i];
            Arrays.fill(row,-1);
        }
        
        // ArrayList<ArrayList<Integer>>visit=new ArrayList<>();
        // for(int i=0;i<m;i++){
        //     ArrayList<Integer> row=new ArrayList<>();
        //     for(int j=0;j<n;j++){
        //         row.add(-1);
        //     }
        //     visit.add(row);
        // }
        int []row={1,0,-1,0};
        int []col={0,1,0,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==word.charAt(0) && vis[i][j]==-1){
                    if(solve(i,j,m,n,mat,1,word,vis,row,col)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    static private boolean solve(int r,int c,int m,int n,char [][]mat,int idx,String word,int [][]vis,int []row,int []col){
        if(idx==word.length()){
            return true;
        }
        vis[r][c]=0;
        int nr=0,nc=0;
        for(int i=0;i<4;i++){
            nr=r+row[i];
            nc=c+col[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n){
                if(mat[nr][nc]==word.charAt(idx) && vis[nr][nc]==-1){
                   if(solve(nr,nc,m,n,mat,idx+1,word,vis,row,col)){
                       return true;
                   }
                   
                }
            }
        }
        vis[r][c]=-1;
        return false;
    }
}