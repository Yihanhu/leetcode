// Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list. 
//
// Example 1:
//
// Input: ["23:59","00:00"]
// Output: 1
//
//
//
// Note:
//
// The number of time points in the given list is at least 2 and won't exceed 20000.
// The input time is legal and ranges from 00:00 to 23:59.
//
//


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int bucket[1440] = {0};
        for(int i = 0; i < timePoints.size(); i++){
            int sectime = time2sec(timePoints[i]);
            // cout<<timePoints[i]<<" "<<sectime<<endl;
            bucket[sectime]++;
            if(bucket[sectime] >=2)
                return 0;
        }
        int last = -1;
        int start = -1;
        int mindiff = 1440;
        for(int i = 0; i < 1440; i++){
            if(bucket[i]){
                if(start < 0){
                    last = i;
                    start = i;
                    continue;
                }
                mindiff = min(mindiff, i - last);
                last = i;
            }
        }
        mindiff = min(mindiff, start + 1440 - last);
        return mindiff;
    }
    
    int time2sec(string time){
        return ((static_cast<int> (time[0] - '0'))*10 + static_cast<int> (time[1] - '0'))*60 + (static_cast<int> (time[3] - '0'))*10 + static_cast<int> (time[4] - '0');
    }
};
