#ifndef ACTORBUILDER_H
#define ACTORBUILDER_H
#include "tinyxml.h"
#include "actor.h"
#include<vector>
using namespace std;
class ActorBuilder
{
    public:
            void build(vector<Actor>& ,TiXmlElement*);
    private:
            Actor getActor(int,TiXmlElement*);
};

#endif // ACTORBUILDER_H
