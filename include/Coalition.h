#pragma once
#include <vector>
using std::vector;

class Agent;
class Graph;


class Coalition{
 public:
 Coalition(int val);
 void addAgentToCoal(Agent a1,Graph g1);
 int getCoalitionId();
 vector<Agent> mAgentsOfTheCoalition;
 int mNumOfMandates;
 int mIdCoal;
 
 
 
};