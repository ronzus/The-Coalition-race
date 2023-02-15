#include "Party.h"
#include "JoinPolicy.h"
#include "Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mPartyOfferingCurr(), mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), mTimer(0) 
{
    // You can change the implementation of the constructor, but not the signature!
}

Party::~Party()
{//destructor
    if(mJoinPolicy)
        delete mJoinPolicy;
}

Party::Party(const Party& other): mPartyOfferingCurr(other.mPartyOfferingCurr), mId(other.mId), mName(other.mName), mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy->Clone()), mState(other.mState), mTimer(other.mTimer)
{//copy constructor
}
Party& Party::operator=(const Party& other)
{//copy assignment
    if(this != &other){
    if(mJoinPolicy)
         delete mJoinPolicy;
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mState = other.mState;
    mTimer = other.mTimer;
    mJoinPolicy = other.mJoinPolicy->Clone();   
}
return *this;
}
Party::Party(Party&& other): mPartyOfferingCurr(other.mPartyOfferingCurr), mId(other.mId), mName(other.mName), mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy), mState(other.mState), mTimer(other.mTimer)
{//move constructor   
    other.mJoinPolicy = nullptr;    
}
Party& Party::operator=(Party&& other)
{//move assignment
    if(mJoinPolicy)
         delete mJoinPolicy;
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mState = other.mState;
    mTimer = other.mTimer;
    mJoinPolicy = other.mJoinPolicy;   
    other.mJoinPolicy = nullptr; 
    return *this;
}

//================================================
State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}
int Party::getTimer(){

    return mTimer;
}

vector<Agent> Party::getmPartyOfferingCurr(){

    return mPartyOfferingCurr;
}

void Party::updateTimer(){
    mTimer++;
}
void Party::addToOffers(Agent& Offering){
    mPartyOfferingCurr.push_back(Offering);
    if(this->getState()==Waiting){
        this->setState(CollectingOffers);
    }
}

void Party::step(Simulation &s)
{
    // TODO: implement this method
    if(mState==CollectingOffers)
    {
         updateTimer();
        if(getTimer()>2)
        {

        int agentA = mJoinPolicy->join(mPartyOfferingCurr,s);
        Agent b=mPartyOfferingCurr[agentA];
        b.setId(s.getAgents().size());
        b.setPartyId(mId);
        s.getCoalition(mPartyOfferingCurr.at(agentA).mCoalId).addAgentToCoal(b,s.getGraph());
        s.getAgents().push_back(b);
        s.getParty(b.getPartyId()).setState(Joined);

        }
         
    }
    
}
