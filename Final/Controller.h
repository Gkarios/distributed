#ifndef __FINAL_CONTROLLER_H_
#define __FINAL_CONTROLLER_H_

#include <omnetpp.h>
#include <Node.h>

using namespace omnetpp;


class Controller : public cSimpleModule
{

  protected:
    int totalNodes;
    double xPos;
    double yPos;
    int nodeID;
    double l;
    int data;
    int numNeighbors;
    int maxNeighbors;
    Node* sink;
    bool isConnected;
    double distance;

    std::vector<Node*> nodes;

    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
    virtual void startConnected();
};

#endif
