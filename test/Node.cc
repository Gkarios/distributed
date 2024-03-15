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
    myId = par("nodeID");
    EV << "my id is: " <<myId << endl;
    if (myId == 1){
        cMessage * msg = new cMessage("Hello-0");
        send(msg, "gate2");
        msg->setKind(0);
    }
}

void Node::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    std::string message = msg->getName();
    int kind = msg->getKind();
    if (kind == 0){
        bubble("Hello!");
    } else if (kind == 1){
        bubble("Bye!");
    if (message == "hello-0") {
        bubble("Hello");
    } else if (message == "hello-1"){

    }
    }
    delete msg;
    int coin = intuniform(0, 1);

    cMessage * mymsg;
    if (coin == 0){
        mymsg = new cMessage("hello-0");
        mymsg->setKind(0);
    } else if (coin == 1)
        {mymsg = new cMessage("hello-1")
    mymsg->setKind(0);
        }
    send(mymsg, "gate2");
}

void Node::finish(){
    std::cout << "node " << myId << "says goodnight" << endl;
}
