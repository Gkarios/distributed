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
   visited = false;
   nodeID = par("nodeID");
   totalNodes = getParentModule()->par("totalNodes");

       if(nodeID == 1000){
          EV << totalNodes << endl;
          visited = true;
          cMessage * msg = new cMessage("flood", 0);
          spreadMessage(msg);
          delete msg;
      }}

int Node::getNodeID(){
    return this->nodeID;
}

bool Node::getVisited(){
    return this->visited;
}

void Node::handleMessage(cMessage *msg)
{
    std::string message = msg->getName();
    if(visited == false){
        visited = true;
        spreadMessage(msg);
    }
    delete msg;
}



void Node::spreadMessage(cMessage *msg){
    for (int i = 0; i<gateSize("port"); i++){
        send(msg->dup(),gate("port$o", i));
    }
}
