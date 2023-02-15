#include "Party.h"
#include "SelectionPolicy.h"
#include "Simulation.h"


Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mCoalId(agentId), mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
   
}

Agent::~Agent()
{//destructor
    if (mSelectionPolicy)
        delete  mSelectionPolicy;
    
}

//copy constructor
Agent::Agent(const Agent& other):mCoalId(other.mCoalId), mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy->clone()) {
}

//copy assignment
Agent& Agent::operator = (const Agent& other){
if(this != &other){
    if(mSelectionPolicy)
        delete mSelectionPolicy;
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy=other.mSelectionPolicy->clone();
    mCoalId = other.mCoalId;     
}
return *this;
}

//move constructor
Agent::Agent(Agent&& other): mCoalId(other.mCoalId),mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy){
    other.mSelectionPolicy = nullptr;
}

//move operator
Agent& Agent::operator=(Agent&& other){
    if(mSelectionPolicy)
        delete mSelectionPolicy;
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy=other.mSelectionPolicy;
    mCoalId = other.mCoalId;
    other.mSelectionPolicy = nullptr;
    return *this;
}

//============================================
int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::setId(int newval) 
{
    mAgentId=newval;
}

void Agent::setPartyId(int newval) 
{
    mPartyId=newval;
}

void Agent::step(Simulation &sim)
{
    
    // TODO: implement this method
    vector<int> validParties;
    bool check=true;
    for(int i=0;i<sim.getGraph().getNumVertices();i++){
        check=true;
       if(i!=(*this).getPartyId() && sim.getGraph().getEdgeWeight((*this).getPartyId(),i)>0){
           if(sim.getParty(i).getState() != Joined){
              for(int j(0), Size(sim.getParty(i).getmPartyOfferingCurr().size());j<Size;j++){
                  if((sim.getParty(i).getmPartyOfferingCurr()[j].mCoalId)==((*this).mCoalId)){
                     check=false;
                  }
              }
            if(check){     
             validParties.push_back(i);
            }
           } 
       }
    }
    if(!(validParties.empty())){
       sim.getParty(mSelectionPolicy->select(*this,sim,validParties)).addToOffers(*this);
    }
    

} 
    


