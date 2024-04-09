//hello
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
    myId = par("nodeId");
    state = par("state");
    setDisplayString(color1);
    if (myId == 1000){
        cMessage * msg = new cMessage("hello", 0);
        send(msg, "port$o", 0);
    }
}

void Node::handleMessage(cMessage *msg)
{
    state = (state + 1) % 3;
    if (state == 0){
        setDisplayString(color2);
    } else if (state == 1){
        setDisplayString(color1);
    } else if (state == 2){
        setDisplayString(color3);
    }
    send(msg, "port$o", 0);
}
