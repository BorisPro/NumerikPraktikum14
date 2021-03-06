#ifndef RANDOMDICE_H
#define RANDOMDICE_H

#include <random>
#include "IUniformDist.h"

class Cpp11UniformDice : public IUniformDist
{
public:
    Cpp11UniformDice();

    ~Cpp11UniformDice() = default;

    double roll();

    void setBounds(double Lower, double Upper);

private:
    double Lower, Upper;
    std::default_random_engine generator;
};

#endif // RANDOMDICE_H
