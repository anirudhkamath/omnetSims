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

simple node
{
    gates:
        inout in_out[];
}

channel Link extends ned.DatarateChannel
{
    parameters:
        int cost = default(0);
}

network myNetwork
{
    @display("bgb=235,205");
    submodules:
        //submodules are the nodes, routers, or components of the network
        node1: node{}
        node2: node{}
        node3: node{}
    connections:
        node1.in_out++ <--> Link {  cost=100; } <--> node3.in_out++;
        node2.in_out++ <--> Link {  cost=50; } <--> node3.in_out++;

}
