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
    // TODO - Generated method body
    myID = par("nodeID");
    EV << "Hello I'm node with id: " << myID << endl;
    std::cout << "Hello I'm node with id: " << myID << endl;
    cMessage * timerMsg = new cMessage("abcdef");
    scheduleAt(simTime() + 5, timerMsg);
}

void Node::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    bubble("hello!");
    scheduleAt(simTIme() + 10, msg);
}
