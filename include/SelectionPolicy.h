#pragma once
#include <vector>
using std::vector;
class Graph;
class Agent;
class Party;
class Simulation;

class SelectionPolicy { 
    public:
    virtual SelectionPolicy* clone()=0;
    virtual int select(Agent& a1,Simulation& m1sim,vector<int>& validParties)=0;
    virtual ~SelectionPolicy()=default;

};

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
    SelectionPolicy* clone();
    virtual int select(Agent& a1,Simulation& m1sim,vector<int>& validParties);
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
    SelectionPolicy* clone();
    virtual int select(Agent& a1,Simulation& m1sim,vector<int>& validParties);


 };