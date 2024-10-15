class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string>st;
        int n = board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){
                    string row = "row" + to_string(i) + board[i][j];
                    string col = "col" + to_string(j) + board[i][j];
                    string box = "box" + to_string((i/3)*3+j/3) + board[i][j];
                    if(st.find(row)==st.end()&&st.find(col)==st.end()&&st.find(box)==st.end()){
                        st.insert(row);
                        st.insert(col);
                        st.insert(box);
                    }
                    else return false; 
                }
            }
        
        }
        return true;
    }
};