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

#include "Controller.h"

Define_Module(Controller);

void Controller::initialize()
{
    totalNodes = getParentModule()->par("totalNodes");
    for(int i = 0; i < totalNodes; i++){
        Node * node = (Node*) getParentModule()->getSubmodule("node", i);
        nodes.push_back(node);
    }
    cMessage *msg = new cMessage("check connected", 0);
    scheduleAt(simTime() + 1, msg);
}

void Controller::handleMessage(cMessage *msg)
{
    if (msg->getKind() == 0){
        int numVisited = 0;
            for (int i = 0; i<nodes.size(); i++){
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
    EV <<"CONNECTED NETWORK || STARTER" << endl;
    int i;
    for (i=0; i<totalNodes; i++){
        nodepragma->at(i)->aridmosneighbors;
    }
}
