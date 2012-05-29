#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include<vector>
#include<algorithm>
#include<ctime>
#include <cstdlib>
#include<map>
#include "testsequence.h"
class Chromosome
{
    public:
        /** Default constructor */
        Chromosome();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Chromosome(const Chromosome& other);
        bool operator < (const Chromosome&) const;
        void generate(vector<TestSequence>,int);
        void create(vector<TestSequence>);
        void setSequence(vector<TestSequence>);
        vector<TestSequence> getSequence() const;
        void setFitness(double);
        void setWeight(int);
        void setCount(int);
        void setSize(int);
        void setMessageCount(int);
        void evalConditions();
        double getFitness()const;
        int getWeight() const;
        int getCount()const;
        int getSize()const;
        int getMessageCount()const;
        map<string,int> getConditionHash()const;

    private:
        vector<TestSequence> TSList;
        map<string,int> conditions;
        int TestCaseCount;
        int TotalWeight;
        double fitness;
        int mcount;
        int size;
};

#endif // CHROMOSOME_H
