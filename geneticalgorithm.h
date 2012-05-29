#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H
#include<algorithm>
#include "chromosomebuilder.h"
extern vector<string> SeqD_conditions;
class GeneticAlgorithm
{
    public:
        /** Default constructor */
        GeneticAlgorithm();
        vector<Chromosome> crossover(vector<Chromosome>&);
        vector<Chromosome> mutation(vector<Chromosome>&);
        vector<TestSequence> generate(vector<TestSequence>,int);

    private:
};

#endif // GENETICALGORITHM_H
