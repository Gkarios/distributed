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

#include "Node2.h"
#define START 0
#define HELLO 1

Define_Module(Node2);

void Node2::initialize()
{
    // TODO - Generated method body
    myId = par("nodeID");
    totalNodes = par("totalNodes");

    if(myId == 1000){
        cMessage *msg = new cMessage("start", START);
        scheduleAt(simTime() + 0.001, msg);
    }
}

void Node2::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    int msgKind = msg->getKind();
    if (msgKind == 0){
        EV << "I am the first node with ID: " << myId << endl;
    }
    forwardMessage();
    delete msg;
}

void Node2::forwardMessage(){
    int nextId;
    if (myId == 1000 + totalNodes - 1){
        nextId = 1000;
    } else {
        nextId = myId + 1;
    }
    for (int i = 0; i<gateSize("inoutGateVector");i++){
        cGate *myGate = gate("inoutGateVector$o", i);
        cGate *oppositeGate = myGate->getPathEndGate();
        Node2 *otherNode = (Node2*) oppositeGate->getOwnerModule();
        int otherId = otherNode->myId;
        if (otherId == nextId){
            cMessage *msg = new cMessage("hello", HELLO);
            send(msg, "inoutGateVector$o", i);
            //delete msg;
            break;

        }
    }
}