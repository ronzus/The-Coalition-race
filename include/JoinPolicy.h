#pragma once
#include <vector>

using std::vector;

class Agent;
class Simulation;


class JoinPolicy {
    public:
    virtual JoinPolicy *Clone() = 0;
    virtual int join(vector<Agent> &PartiesOffering,Simulation& g)=0;
    virtual ~JoinPolicy()=default;

};

class MandatesJoinPolicy : public JoinPolicy {
    public:
    JoinPolicy *Clone();
    virtual int join(vector<Agent> &PartiesOffering,Simulation& g);


};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
    JoinPolicy *Clone();
    virtual int join(vector<Agent> &PartiesOffering,Simulation& g);


};