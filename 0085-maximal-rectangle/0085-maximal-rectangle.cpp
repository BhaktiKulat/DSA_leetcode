class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();

    vector<int> right(n);
    vector<int> left(n);
    stack<int> s;

    // Next smaller element on the right
    for(int i = 0; i < n; i++){
        while(!s.empty() && heights[s.top()] > heights[i]){
            right[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()){
        right[s.top()] = n;
        s.pop();
    }

    // Previous smaller element on the left
    for(int i = 0; i < n; i++){
        while(!s.empty() && heights[s.top()] >= heights[i]){
            s.pop();
        }

        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    }

    return ans;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty() || matrix[0].empty()){
        return 0;
    }

    int ans = 0;
    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> heights(col, 0);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(matrix[i][j] == '0'){
                heights[j] = 0;
            }
            else{
                heights[j]++;
            }
        }

        ans = max(ans, largestRectangleArea(heights));
    }

    return ans;

        
    }
};