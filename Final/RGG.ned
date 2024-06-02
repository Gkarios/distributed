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

network RGG
{
    parameters:
        int totalNodes = default(5);
        double rc = default(0.1);
        double l = default(0.1);
        @display("bgb=1,1");
        
    submodules:
        node[totalNodes]: Node
        {
            nodeID = 1000 + index;
            xPos = uniform(0,1);
            yPos = uniform(0,1);
            @display("p=$xPos,$yPos");
		}

		controller: Controller;

	connections:
	    for i = 0..totalNodes-1, for j = i+1..totalNodes-1{
	        node[i].port++ <--> {delay=100ms;} <--> node[j].port++
	        if (node[i].xPos-node[j].xPos)^2 + (node[i].yPos-node[j].yPos)^2 <= rc^2;
	        }
}
