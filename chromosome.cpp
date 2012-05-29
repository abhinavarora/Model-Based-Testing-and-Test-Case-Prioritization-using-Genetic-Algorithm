#include "chromosome.h"

ptrdiff_t myrandom (ptrdiff_t i) { return rand()%i;}

// pointer object to it:
ptrdiff_t (*p_myrandom)(ptrdiff_t) = myrandom;

Chromosome::Chromosome()
{
    //ctor
}

Chromosome::Chromosome(const Chromosome& other)
{
    //copy ctor
    this->TSList = other.getSequence();
    this->conditions = other.getConditionHash();
    this->TestCaseCount = other.getCount();
    this->TotalWeight = other.getWeight();
    this->fitness = other.getFitness();
    this->mcount = other.getMessageCount();
    this->size = other.getSize();
}

bool Chromosome::operator < (const Chromosome& another)const
{
    if(this->TestCaseCount < another.getCount())
        return true;
    else if(this->TestCaseCount > another.getCount())
        return false;
    else
        return((this->fitness)< another.getFitness());
}

void Chromosome::setSequence(vector<TestSequence> TS)
{
    this->TSList = TS;
}

vector<TestSequence> Chromosome::getSequence() const
{
    return this->TSList;
}

void Chromosome::generate(vector<TestSequence> TS, int size)
{
    random_shuffle(TS.begin(),TS.end(), p_myrandom);
    random_shuffle(TS.begin(),TS.end(), p_myrandom);
    vector<TestSequence> list;
    this->TotalWeight = 0;
    this->mcount = 0;
    for(int i =0; i<size; i++)
    {
        list.push_back(TS[i]);
        (this->TotalWeight)+= TS[i].getPriority();
        (this->mcount)+= TS[i].getLength();
    }
    this->setSequence(list);
    this->setSize(size);
    this->evalConditions();
    double fit = (double)(this->TotalWeight)/(this->mcount);
    this->setFitness(fit);
}

void Chromosome::create(vector<TestSequence> TS)
{
    int size = TS.size();
    this->TotalWeight = 0;
    this->mcount = 0;
    for(int i =0; i<size; i++)
    {
        (this->TotalWeight)+= TS[i].getPriority();
        (this->mcount)+= TS[i].getLength();
    }
    this->setSequence(TS);
    this->setSize(size);
    this->evalConditions();
    double fit = (double)(this->TotalWeight)/(this->mcount);
    this->setFitness(fit);
}


void Chromosome::setFitness(double fit)
{
    this->fitness = fit;
}

void Chromosome::setWeight(int weight)
{
    this->TotalWeight = weight;
}

void Chromosome::setCount(int count)
{
    this->TestCaseCount = count;
}

void Chromosome::setSize(int s)
{
    this->size = s;
}

int Chromosome::getCount() const
{
    return this->TestCaseCount;
}

double Chromosome::getFitness() const
{
    return this->fitness;
}

int Chromosome::getWeight() const
{
    return this->TotalWeight;
}

int Chromosome::getSize() const
{
    return this->size;
}

void Chromosome::evalConditions()
{
    for(unsigned int i =0; i<SeqD_conditions.size(); i++)
    {
        for(unsigned int j=0; j<TSList.size(); j++)
        {
            map<string,int> temp = TSList[j].getConditions();
            if(temp[SeqD_conditions[i]])
            {
                this->conditions[SeqD_conditions[i]] = 1;
                break;
            }
        }
    }
    this->setCount((this->conditions).size());
}

map<string,int> Chromosome::getConditionHash()const
{
    return this->conditions;
}

void Chromosome::setMessageCount(int mcount)
{
    this->mcount = mcount;
}

int Chromosome::getMessageCount() const
{
    return this->mcount;
}
