#include "node.h"
Node::Node(int type,Message frag)
{
        this->type = type;
        this->mfrag = frag;
//        this->cfrag = NULL;
}

/*
Node::Node(int type,CombinedFragment frag)
{
        this->type = type;
        this->cfrag = frag;
        this->mfrag = NULL;
}
*/

int Node::getType()
{
    return this->type;
}

void Node::setType(int type)
{
    this->type = type;
}

Message Node::getmFrag()
{
    return this->mfrag;
}

void Node::setmFrag(Message frag)
{
    this->mfrag = frag;
//    this->cfrag = NULL;
}

/*
CombinedFragment Node::getcFrag()
{
    return this->cfrag;
}

void Node::setcFrag(CombinedFragment frag)
{
    this->cfrag = frag;
    this->mfrag = NULL;
}
*/
