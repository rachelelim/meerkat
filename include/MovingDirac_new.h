//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "DiracKernel.h"

class MovingDirac_new;

template <>
InputParameters validParams<MovingDirac_new>();

class MovingDirac_new : public DiracKernel
{
public:
  MovingDirac_new(const InputParameters & parameters);

  virtual void addPoints() override;
  virtual Real computeQpResidual() override;

protected:
  Real _value;
  Point _point;
};
