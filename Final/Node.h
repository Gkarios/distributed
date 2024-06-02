//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef __FINAL_NODE_H_
#define __FINAL_NODE_H_

#include <omnetpp.h>


using namespace omnetpp;


class Node : public cSimpleModule
{
  protected:
    Node *parentNode;
    Node *sink;
    int nodeID;
    double l;
    double rng;
    bool visited;
    bool visited2;
    bool isSink;
    int totalNodes;
    int numNeighbors;
    int parentGateIndex;

    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

    void spreadMessage(cMessage *msg);
  public:
    int getNodeID();
//    int Counter;
    bool isVisited(){
        return visited;
    }

    double xPos;
    double yPos;
    double distance;
    int data;
    void startSink();
};

#endif
