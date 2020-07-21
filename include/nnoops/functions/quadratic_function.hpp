#ifndef NNOOPS_LIB_CPP_QUADRATIC_FUNCTION_HPP_
#define NNOOPS_LIB_CPP_QUADRATIC_FUNCTION_HPP_

#include <cassert>

#include "nnoops/functions/base_function.hpp"

namespace nnoops {

struct QuadraticFunction : public BaseFunction<1> {
  QuadraticFunction() = default;
  QuadraticFunction(double a, double b, double c) : a(a), b(b), c(c) {
    assert(a != 0 && "'a' field should not equal to zero");
  }

  ~QuadraticFunction() override = default;

  double function(const Point<1>& x) const override;

  double derivative(const Point<1>& x) const override;

 private:
  double a{1.0};
  double b{0};
  double c{0};
};

}  // namespace nnoops

#endif