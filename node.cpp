#include "node.h"
#include "combinedfragment.h"
class CombinedFragment;
Node::Node()
{
    this->cfrag = NULL;
}


Node& Node:: operator =(const Node& another)
{
    this->type = another.getType();
    this->mfrag = another.getmFrag();
    CombinedFragment* temp = another.getcFragP();
    CombinedFragment *ptr = NULL;
    if(temp!=NULL)
    {
        ptr = new CombinedFragment(*temp);
    }
    (this->cfrag) = ptr;
    return *this;
}

Node::Node(int type,Message frag)
{
        this->type = type;
        this->mfrag = frag;
        this->cfrag = NULL;
}


Node::Node(int type,CombinedFragment* frag)
{
        this->type = type;
        this->cfrag = frag;
}


int Node::getType() const
{
    return this->type;
}

void Node::setType(int type)
{
    this->type = type;
}

Message Node::getmFrag() const
{
    return this->mfrag;
}

void Node::setmFrag(Message frag)
{
    this->mfrag = frag;
    this->cfrag = NULL;
}


CombinedFragment Node::getcFrag()
{
    if(this->cfrag!=NULL)
        return *(this->cfrag);
    else
    {
     CombinedFragment cf_null(string(""),-1);
     return cf_null;
    }
}

void Node::setcFrag(CombinedFragment* frag)
{
    this->cfrag = frag;
}

CombinedFragment* Node::getcFragP() const
{
    return this->cfrag;
}
