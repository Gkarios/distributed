simple Node
{
    parameters:
        int nodeID = default(-1);
        double xPos = default(-1);
        double yPos = default(-1);
        double l = default(-1);
    gates:
        inout port[];
        input controllerInput@directIn;
}
