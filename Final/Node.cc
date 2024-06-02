#include "Node.h"

Define_Module(Node);


void Node::initialize()
{
   visited = false;
   visited2 = false;
   isSink = false;
   data = 0;
   distance = 0;
   l = getParentModule()->par("l");
   nodeID = par("nodeID");
   totalNodes = getParentModule()->par("totalNodes");
   xPos = par("xPos");
   yPos = par("yPos");

   if(nodeID == 1000){
       EV << totalNodes << endl;
       visited = true;
       cMessage * msg = new cMessage("flood", 0);
       spreadMessage(msg);
   }
}


void Node::handleMessage(cMessage *msg)
{
    if(msg->getKind() == 0){
        if(visited == false){
            visited = true;
            EV << "CHECKING CONNECTION" << endl;
            spreadMessage(msg);
        }else{
            delete msg;
        }
    }

    else if (msg->getKind() == 2){
        if (visited2 == false && isSink == false){
        visited2 = true;
        parentGateIndex = msg->getArrivalGate()->getIndex();
        EV << parentGateIndex << endl;
        spreadMessage(msg);
        cMessage * timerMsg = new cMessage("timerMsg", 1);
        scheduleAt(simTime() + 0.1, timerMsg);
    }else{
            delete msg;
        }
    }


    else if ((msg->getKind() == 1) && (isSink == false)){
        scheduleAt(simTime() + 1, msg);
        rng = uniform(0,1);
        if (rng<l){
            cMessage * dataPacket = new cMessage("data", 4);
            send(dataPacket->dup(), "port$o", parentGateIndex);
            delete dataPacket;
            data++;     //DATA PACKET COUNTER FOR NODE
        }
    }
    else if(msg->getKind() == 4){
        if(isSink == false){
            send(msg, "port$o", parentGateIndex);
        }
        else if (isSink == true){
            delete msg;
            EV <<"NEW MESSAGE" << endl;
            data++;
        }
    }
}




void Node::spreadMessage(cMessage *msg){
    for (int i = 0; i<gateSize("port"); i++){
        send(msg->dup(),gate("port$o", i));
    }
    delete msg;
}





void Node::startSink(){
    Enter_Method_Silent();
    isSink = true;
    cMessage * sinkMsg = new cMessage("sinkMsg", 2);
    spreadMessage(sinkMsg);
}
