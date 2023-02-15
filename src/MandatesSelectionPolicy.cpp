#include "SelectionPolicy.h"
#include "Graph.h"
#include "Agent.h"
#include "Party.h"
#include "Simulation.h"

int MandatesSelectionPolicy::select(Agent& a1,Simulation& m1sim,vector<int>& validParties)
{
    int top = validParties[0];
    for(int i(0), Size(validParties.size());i<Size;i++){  
         if(m1sim.getGraph().getMandates(top)<m1sim.getGraph().getMandates(validParties[i])){
            top=validParties[i];
           
         }
    }

return top;
};

SelectionPolicy* MandatesSelectionPolicy::clone(){
    return new MandatesSelectionPolicy(*this);
}