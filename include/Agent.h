#pragma once
#include <vector>
#include "Coalition.h"


class Simulation;
class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    virtual ~Agent();//destructor
    Agent(const Agent& other);//copy constructor
    Agent& operator=(const Agent& other);//copy assignment
    Agent(Agent&& other);//move constructor
    Agent& operator=(Agent&& other);//move assignment
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    void setId(int newval);
    void setPartyId(int newval);
    int mCoalId;    
private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
};
