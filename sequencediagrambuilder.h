#ifndef SEQUENCEDIAGRAMBUILDER_H
#define SEQUENCEDIAGRAMBUILDER_H
#include "tinyxml.h"
#include "sequencediagram.h"
#include<string>
#include<map>
extern map<string,CombinedFragment*>  Message_List;
class SequenceDiagramBuilder
{
    public:
        /** Default constructor */
        SequenceDiagramBuilder(string);
        void build(SequenceDiagram&);

    private:
        TiXmlDocument doc;
        TiXmlElement* docEle;
};

#endif // SEQUENCEDIAGRAMBUILDER_H
