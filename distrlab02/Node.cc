#include "Node.h"

Define_Module(Node);

void Node::initialize()
{
    nodeID = par("nodeID");

    EV<<"Hello i am node with id "<<nodeID<<endl;

    if (nodeID == 1001)
    {
        scheduleAt(simTime()+0.001, new cMessage("start"));
    }
}

void Node::handleMessage(cMessage *msg)
{
    std::string message = msg->getName();

    if (message == "start")
    {
        delete msg;
        cMessage * msg = new cMessage("minima_01");
        send(msg, "gate2");
    }
    else
    {
        //delete msg;

        if (message=="minima_01")
        {
            bubble("Hello");
        }
        else bubble("Bye!");
        delete msg;
        int coin = intuniform(0,1);

        if (coin==0)
        {
            msg = new cMessage("minima_01");
        }
        else
        {
            msg = new cMessage("minima_02");
        }

        send(msg, "gate2");
    }
}

void Node::finish()
{
    std::cout<<"Node "<<nodeID<<" says goodnight!"<<endl;
}

