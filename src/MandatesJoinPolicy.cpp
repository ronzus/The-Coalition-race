#include "JoinPolicy.h"
#include "Agent.h"
#include "Party.h"
#include "Simulation.h"



int MandatesJoinPolicy::join(vector<Agent>& AgentsWhichOffered,Simulation& g){
    
    int HighestMandatesCount = g.getCoalition(AgentsWhichOffered[0].mCoalId).mNumOfMandates;
    int Top=0;
    for (int i(0), Size(AgentsWhichOffered.size()) ; i < Size ; i++){
        int a1CoalId = AgentsWhichOffered[i].mCoalId;
        Coalition t = g.getCoalition(a1CoalId);
        if(HighestMandatesCount<t.mNumOfMandates){
            HighestMandatesCount=t.mNumOfMandates;
            Top=i;
        }
        
    }
    
    return Top;
}
JoinPolicy* MandatesJoinPolicy::Clone(){
    return new MandatesJoinPolicy(*this);
}
