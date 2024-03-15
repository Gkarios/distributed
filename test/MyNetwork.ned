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

network MyNetwork
{
    submodules:
        node1: Node {
            nodeID = 1;
        };     
        node2: Node {
            nodeID = 2;
        };     
        node3: Node {
            nodeID = 3;
        };     
        node4: Node {
            nodeID = 4;
        };        
    connections allowunconnected:    
        node1.gate2 --> {delay = 100ms;} --> node2.gate1;
        node2.gate2 --> {delay = 100ms;} --> node3.gate1;
        node3.gate2 --> {delay = 100ms;} --> node4.gate1;
        node4.gate2 --> {delay = 100ms;} --> node1.gate1;
    
}
