/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        // index of ticket
        enum Ticket { _1day, _7day, _30day };
        
        
        // set of travel days
        set<int> travelDays = set<int>(days.begin(), days.end());
        
        int lastTravelDay = days.back();
        
        // dp table, record for minimum cost ofticket to travel
        vector<int> dpCost = vector<int>( lastTravelDay+1 );
        
        // Solve min cost by DP
        for( int day_i = 1; day_i <= lastTravelDay ; day_i++ ){
            
            if( travelDays.count(day_i) == 0 ){
                
                // today is not traveling day
                // no extra cost
                dpCost[ day_i ] = dpCost[ day_i - 1 ];
                
            }else{
                
                // today is traveling day
                // compute optimal cost by DP
                dpCost[ day_i ] = min( {dpCost[ day_i - 1 ]            + costs[ _1day ], 
                                        dpCost[ max(day_i - 7, 0) ]    + costs[ _7day ], 
                                        dpCost[ max(day_i - 30, 0) ]   + costs[ _30day]} );
            }
        }

        return dpCost[lastTravelDay];
    }
};
// @lc code=end

