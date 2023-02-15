#pragma once
#include <vector>

using std::vector;
class Party;
class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;
    Party &getParty(int partyId);
    const vector<Party> &getPartiesVector(vector<Party>);
private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};
