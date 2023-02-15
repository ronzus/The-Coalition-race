#include "JoinPolicy.h"
#include "Agent.h"
#include "Simulation.h"

int LastOfferJoinPolicy::join(vector<Agent>& AgentsWhichOffered,Simulation& g){
   return (AgentsWhichOffered.size()-1);
 }
 
JoinPolicy* LastOfferJoinPolicy::Clone(){
    return new LastOfferJoinPolicy(*this);
}
