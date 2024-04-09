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

#ifndef __DISTLAB06_NODE_H_
#define __DISTLAB06_NODE_H_

#include <omnetpp.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Node : public cSimpleModule
{
    private:
        int myId;
        int state;
    protected:
        const char * color1 = "b=20,20,rect,blue,blue,4";
        const char * color2 = "b=20,20,rect,yellow,yellow,4";
        const char * color3 = "b=20,20,rect,green,green,4";
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
};

#endif
