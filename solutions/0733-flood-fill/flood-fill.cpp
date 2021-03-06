//
// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).
//
// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
//
// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on.  Replace the color of all of the aforementioned pixels with the newColor.
//
// At the end, return the modified image.
//
// Example 1:
//
// Input: 
// image = [[1,1,1],[1,1,0],[1,0,1]]
// sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: 
// From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
// by a path of the same color as the starting pixel are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected
// to the starting pixel.
//
//
//
// Note:
// The length of image and image[0] will be in the range [1, 50].
// The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
// The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
//


class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor == newColor)
            return image;
        dfs(image, sr, sc,oldColor, newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor){
        image[sr][sc] = newColor;
        // cout<<sr<<" "<<sc<<endl;
        for(int i = 0; i < 4; i++){
            int new_x = sr + dx[i];
            int new_y = sc + dy[i];
            if(new_x >= 0 and new_x < image.size() and new_y >=0 and new_y < image[0].size()  and image[new_x][new_y] == oldColor){
                dfs(image, new_x, new_y ,oldColor, newColor);
            }
        }
    }
};
