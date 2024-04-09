network Network
{
    parameters:

    submodules:
        node1: Node {
            nodeID = 1001;
        }
        node2: Node {
            nodeID = 1002;
        }
        node3: Node {
            nodeID = 1003;
        }
        node4: Node {
            nodeID = 1004;
        }

    connections:
        node1.gate2 --> {  delay = 100ms; } --> node2.gate1;
        node2.gate2 --> {  delay = 100ms; } --> node3.gate1;
        node3.gate2 --> {  delay = 100ms; } --> node4.gate1;
        node4.gate2 --> {  delay = 100ms; } --> node1.gate1;

}
