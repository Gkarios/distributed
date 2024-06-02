#include "Controller.h"

Define_Module(Controller);

void Controller::initialize()
{
    totalNodes = getParentModule()->par("totalNodes");
    for(int i = 0; i < totalNodes; i++){
        Node * node = (Node*) getParentModule()->getSubmodule("node", i);
        xPos = node->par("xPos");
        yPos = node->par("yPos");
        nodes.push_back(node);
    }

    cMessage *msg = new cMessage("check connected", 0);
    scheduleAt(simTime() + 1, msg);
}

void Controller::handleMessage(cMessage *msg)
{
    if (msg->getKind() == 0){
        delete msg;
        int numVisited = 0;
            for (long unsigned int i = 0; i<nodes.size(); i++){
            if(nodes.at(i)->isVisited()){
                numVisited++;
                EV << "success" << endl;
            }
        }
        if(numVisited == totalNodes){
            EV << "connected" <<endl;
            startConnected();
        }
        else {
            EV << "NOT connected!" << endl;
        }
    }
}


void Controller::startConnected(){
    isConnected = true;
    EV << "CONNECTED NETWORK || STARTER" << endl;
    sink = nodes.at(0);
    maxNeighbors = nodes.at(0)->gateSize("port");

    for (int i=0; i<totalNodes; i++){
        numNeighbors = nodes.at(i)->gateSize("port");
        if (maxNeighbors < numNeighbors){
            maxNeighbors = numNeighbors;
            sink = nodes.at(i);
        }
    }
    sink->startSink();
}


void Controller::finish(){
    EV <<" FINISH CALLED"<<endl;
    for(int i=0;i<totalNodes;i++){
        distance = std::sqrt(std::pow(sink->xPos - nodes.at(i)->xPos , 2) + std::pow(sink->yPos - nodes.at(i)->yPos, 2));
        EV << distance << "\t" <<nodes.at(i)->data << endl;
        FILE *fp = fopen("results.txt", "a");
        fprintf(fp, "%f\t%d\n", distance, nodes.at(i)->data);
    }
}

