#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() 
  : diff_cte(0)
  , squared_error(0)
  , iteration(0)
  , list_size(100)
{}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  if (ctes.empty()) {
    ctes.push_back(cte);
  }

  double prev_cte = ctes.back();
  diff_cte = cte - prev_cte;

  ctes.push_back(cte);
  while (ctes.size() > list_size) ctes.pop_front();
  int_cte = 0;
  for (double v : ctes) int_cte += v;

  squared_error += cte * cte;
  iteration++;
}

double PID::TotalError() {
  return squared_error / iteration;
}
