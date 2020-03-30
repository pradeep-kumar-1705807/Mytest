#include<bits/stdc++.h>
using namespace std;

class UndergroundSystem {
public:
static map<int, int> checkInTime;
    static map<int,int> checkOutTime;
    static map<string,vector<int>> inPlace;
    static map<string,vector<int>> outPlace;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        inPlace[stationName].push_back(id);
        checkInTime[id]=t;
        
    }
    
    void checkOut(int id, string stationName, int t) {
        outPlace[stationName].push_back(id);
        checkOutTime[id]=t;
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int> &v1=inPlace[startStation];
        vector<int> &v2=outPlace[endStation];
        double sum=0.0;
        int count=0;
        for(auto &it: v1)
        {
            for(auto &jt :v2)
            {
                if(it==jt)
                {
                    sum+=(checkOutTime[jt]-checkInTime[it]);
                    count++;
                }
            }
        }
        double ans=0;
        if(count>0){
         ans=sum/count;
        }
        return ans;
    }
};

int main()
{

}