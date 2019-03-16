/*
 * functionality.cc
 *
 *  Created on: Mar 15, 2019
 *      Author: Mahe
 */

#include<string.h>
#include<omnetpp.h>

using namespace omnetpp; //gives scope to the identifiers that run the simulation

class node:public cSimpleModule{
protected:
    //virtual functions that hold the algorithms for the nodes
    virtual void initialize() override; //overrided function to init the nodes
    virtual void handleMessage(cMessage *msg) override; //to handle the message to send or receive
};

//now we need to register the node class with OMNeT++
Define_Module(node);

//now we can use the functions in the OMNeT++ namespace as the node class is registered

void node::initialize(){
    if(strcmp("node1", getName())==0){
        //checks if the node is node1
        cMessage *msg = new cMessage("hello");
        //cGate *in = gate("in_out$i");
        send(msg, "in_out$o", 0);
    }
    else if(strcmp("node2", getName())==0){
        cMessage *msg = new cMessage("hi");
        //cGate *in = gate("in_out$i");
        send(msg, "in_out$o", 0);
    }
}

int x=0;
void node::handleMessage(cMessage *msg){
    if(x%2==0){
        send(msg, "in_out$o", 0);
    }
    else{
        if(strcmp("node3", getName())==0){
            send(msg, "in_out$o", 1);
        }
        else{
            send(msg, "in_out$o", 0);
        }
    }
    x++;
}



