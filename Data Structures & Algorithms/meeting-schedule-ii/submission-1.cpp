/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = 1000000;
        vector<int> arr(n, 0);
        
        for(auto interval: intervals)
        {
            arr[interval.start] += 1;
            arr[(interval.end)] -= 1;
        }

        for(int i = 1; i < n; i++)
            arr[i] += arr[i-1];

        int maxi = 0;
        for(int i = 0; i < n; i++)
            maxi = max(maxi, arr[i]);

        return maxi;
    }
};
