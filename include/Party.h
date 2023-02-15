#pragma once
#include <string>
#include <vector>
#include "Agent.h"


using std::vector;
using std::string;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 
    virtual ~Party();//destructor
    Party(const Party& other);//copy constructor
    Party& operator=(const Party& other);//copy assignment
    Party(Party&& other);//move constructor
    Party& operator=(Party&& other);//move assignment
    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    vector<Agent> getmPartyOfferingCurr();
    int getTimer();
    void updateTimer();
    void addToOffers(Agent& Offering);


private:
    vector<Agent> mPartyOfferingCurr;
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int mTimer;
    

};
