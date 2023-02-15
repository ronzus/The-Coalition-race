#include "Coalition.h"
#include "Agent.h"
#include "Graph.h"
#include "Party.h"



Coalition::Coalition(int val): mAgentsOfTheCoalition(), mNumOfMandates(0), mIdCoal(val) {
};//constructor

void Coalition::addAgentToCoal(Agent a2,Graph g1){
  this->mAgentsOfTheCoalition.push_back(a2);
  mNumOfMandates=mNumOfMandates+g1.getParty(a2.getPartyId()).getMandates();// + numOfMandates of the joining party;
}

int Coalition::getCoalitionId(){
  return mIdCoal;
}