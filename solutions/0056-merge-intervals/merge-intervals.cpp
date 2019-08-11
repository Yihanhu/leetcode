// Given a collection of intervals, merge all overlapping intervals.
//
// Example 1:
//
//
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//
//
// Example 2:
//
//
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//
// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
//


/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
        
    // Compares two intervals according to staring times. 
    static bool compareInterval(Interval &i1, Interval &i2) 
    { 
       return (i1.start < i2.start); 
    };
    
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),compareInterval);
        if (n==0){
            return intervals;
        }
        int max_start = intervals[0].start;
        int max_end = intervals[0].end;
        int j = 0;
        for (int i = 1; i <= n ; i ++){
            // cout << max_end <<' '<<max_start<<' '<<i<<'\n'  ;
            if (i == n){
                intervals[j].start = max_start ;
                intervals[j].end = max_end;
                while (intervals.size()>j+1){
                    intervals.pop_back();
                }
                return intervals;
                }
            if (max_end >= intervals[i].start){
                if (max_end < intervals[i].end){
                    max_end = intervals[i].end;
                }
            }
            else{
                intervals[j].start = max_start ;
                intervals[j].end = max_end;
                j++;
                max_start = intervals[i].start;
                max_end = intervals[i].end;
            }
        }
    }
};
