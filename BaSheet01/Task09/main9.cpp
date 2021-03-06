/*
 * main9.cpp
 *
 *  Created on: 19.04.2014
 *      Author: BlueCrescent
 */

#include "Cpp11NormalDice.h"

#include "convergence_plot_data.h"

#include <iostream>

int main9() {
  Cpp11NormalDice dice;
  const long long unsigned int numSamples = 1e7;
//  const unsigned int numSamplesToPrint = 1e4;
//  const unsigned int sampleInterval = numSamples / numSamplesToPrint;
  std::cout << "  Running task 9 with " << numSamples << " samples and dynamic sample interval:" << std::endl;

  const double mu = 2;

  const double sigma1 = 0.1;
  std::cout << "   Running with mu = " << mu << " and sigma = " << sigma1 << "..." << std::endl;
  generate_convergence_data_with(mu, sigma1, numSamples, dice);

  const double sigma2 = 1.;
  std::cout << "   Running with mu = " << mu << " and sigma = " << sigma2 << "..." << std::endl;
  generate_convergence_data_with(mu, sigma2, numSamples, dice);

  const double sigma3 = 10.;
  std::cout << "   Running with mu = " << mu << " and sigma = " << sigma3 << "..." << std::endl;
  generate_convergence_data_with(mu, sigma3, numSamples, dice);

  return 0;
}





