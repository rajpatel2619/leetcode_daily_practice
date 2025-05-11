class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int topRow = 0, rightCol = n, downRow = m, leftCol =0;
        List<Integer> res = new ArrayList<>();
        int dir = 0;
        while(topRow<downRow && leftCol<rightCol){
            // printing topRow
            if(dir==0){
                for(int i=leftCol;i<rightCol;i++)
                    res.add(matrix[topRow][i]);
                topRow++;
            }
            
            //printing right col
            if(dir==1){
            for(int i=topRow;i<downRow;i++)
                res.add(matrix[i][rightCol-1]);
            rightCol--;
            }
            //printing down row
            if(dir==2){
            for(int i=rightCol-1;i>=leftCol;i--){
                res.add(matrix[downRow-1][i]);
            }
            downRow--;
            }
            //printing left col
            if(dir==3){
            for(int i=downRow-1;i>=topRow;i--){
                res.add(matrix[i][leftCol]);
            }
            leftCol++;
            }
            dir++;
            if(dir==4)
                dir=0;
        }
        return res;
    }
}