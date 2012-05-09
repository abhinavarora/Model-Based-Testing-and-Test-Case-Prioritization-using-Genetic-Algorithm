#ifndef SEQUENCEDIAGRAMTESTER_H
#define SEQUENCEDIAGRAMTESTER_H
#include "sequencediagram.h"
#include "testsequence.h"
int getPriority(int);
class SequenceDiagramTester
{
    public:
        /** Default constructor */
        SequenceDiagramTester(SequenceDiagram sd);
        vector<TestSequence> generate();
    private:
        vector<Node> seq;
        void duplicateElements(vector<TestSequence>&, int);
        void generate(vector<TestSequence>&);
};

#endif // SEQUENCEDIAGRAMTESTER_H
