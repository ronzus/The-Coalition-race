#include "Simulation.h"
#include "Coalition.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), mCoalitions()
{

    // You can change the implementation of the constructor, but not the signature!
        for(int i(0), Size(mAgents.size());i<Size;i++)
        {
            int j=i;
            mCoalitions.push_back(Coalition(j));
            getCoalition(i).addAgentToCoal(mAgents[i],mGraph);

        }


}

void Simulation::step()
{
    // TODO: implement this method
        for(int i=0;i<mGraph.getNumVertices();i++){
            getParty(i).step(*this);
        }
        
        for(Agent Agent007: mAgents ){
            Agent007.step(*this);
        }


}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    //first cause for terminating
for(int i(0),Size(mCoalitions.size());i<Size;i++){
        if(mCoalitions[i].mNumOfMandates>60){
            return true;
        }
        
}   
    //second cause for terminating
for(int i=0;i<mGraph.getNumVertices();i++){
   if(mGraph.getParty(i).getState()!=Joined){
    return false;
   }
          
        
}
    
    return true;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

Graph &Simulation::getGraph()
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

vector<Agent> &Simulation::getAgents()
{
    return mAgents;
}

Coalition& Simulation::getCoalition(int mCoalId){
    return mCoalitions[mCoalId];
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

Party &Simulation::getParty(int partyId) 
{
    return mGraph.getParty(partyId);
}


/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> PartiesByCoalitions;
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    for(int i(0), Size(mCoalitions.size());i<Size;i++){
        vector<int> PartyBy;
        for(int j(0), jSize(mCoalitions[i].mAgentsOfTheCoalition.size());j<jSize;j++){
            PartyBy.push_back(mCoalitions[i].mAgentsOfTheCoalition[j].getPartyId());
           
        }
        PartiesByCoalitions.push_back(PartyBy);
    }
    return PartiesByCoalitions;
}
