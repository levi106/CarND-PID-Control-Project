#ifndef PID_H
#define PID_H

#include <list>

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  /*
  * Difference between the current CTE and previous CTE
  */
  double diff_cte;

  /*
  * Integrated CTE value
  */
  double int_cte;

private:

  double squared_error;
  int iteration;
  std::list<double> ctes;
  std::list<double>::size_type list_size;
};

#endif /* PID_H */

