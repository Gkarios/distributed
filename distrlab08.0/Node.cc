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

#include "Node.h"

Define_Module(Node);

void Node::initialize()
{
    myId = par("nodeId");
    totalNodes = getParentModule()->par("totalNodes");
    visited = false;
    numNeighbors = gateSize("port");


    if(myId == 1000){
        EV << totalNodes << endl;
        visited = true;
        cMessage * msg = new cMessage("flooding", 0);
        for (int i=0; i < numNeighbors; i++){
            send(msg->dup(), "port$o", i);
        }
        delete msg;
    }
}

void Node::handleMessage(cMessage *msg)
{
    if (visited){
        delete msg;
        return;
    }
    visited = true;
    EV << "message kind: " << msg -> getKind() << endl;
    for (int i = 0; i< numNeighbors; i++){
        send(msg->dup(), "port$o", i);
    }
    delete msg;
}
