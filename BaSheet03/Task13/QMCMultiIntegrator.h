/*
 * QMCMultiIntegrator.h
 *
 *  Created on: 28.05.2014
 *      Author: BlueCrescent
 */

#ifndef QMCMULTIINTEGRATOR_H_
#define QMCMULTIINTEGRATOR_H_

#include "MultiVariateIntegrator.h"
#include "HaltonSequence.h"
#include "Cpp11UniformDice.h"
#include <iostream>

#include <utility>

class QMCMultiIntegrator: public MultiVariateIntegrator {
public:
  NodesAndWeights getNodesAndWeights(int l, int d) const;

  template<typename T>
  long double integrateEfficient(int level, int d, T function) const;
};

template<typename T>
long double QMCMultiIntegrator::integrateEfficient(int level, int d, T function) const{
  const int N_l = pow(2, level) - 1;
  const double factor = 1. / N_l;
  std::vector<double> haltonPoint = generateFirstPoint(d);

// --------------------
//  std::vector<double> haltonTest = generateFirstPoint(2);
//  for (int k = 0; k < 4; ++k) {
//    for (int var = 0; var < 2; ++var) {
//      std::cout<< haltonTest[var] << " ";
//    }
//    std::cout<< std::endl;
//    haltonTest = std::move(generateNextHaltonValue(haltonTest));
//  }
// --------------------

  long double result = 0;

//  Cpp11UniformDice dice;
  for(int i = 0; i < N_l; ++i) {
//    if (i < 4) {
//      for (int var = 0; var < d; ++var) {
//        std::cout<< haltonPoint[var] << " ";
//      }
//      std::cout<< std::endl;
//    }
    result += function(haltonPoint) * factor;
//    haltonPoint.clear();
//    haltonPoint.reserve(d);
//    for (int i = 0; i < d; ++i) {
//      haltonPoint.push_back(dice.roll());
//    }
    haltonPoint = std::move(generateNextHaltonValue(haltonPoint));
  }
  return result;
}


#endif /* QMCMULTIINTEGRATOR_H_ */
