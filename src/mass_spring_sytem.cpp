#include "mass_spring_sytem.h"
#include "types.h"
#include <iostream>

namespace snow
{
    bool MassSpringSystem::SetSprings(const MATRIXI springs)
    {
        if (springs.rows() == 0 || springs.cols() != 2)
            return false;
        _springs = springs;
        _rest_length.resize(_springs.rows());
        for (int i = 0; i < _springs.rows(); i++)
        {
            VECTOR x0       = _x.row(_springs(i, 0));
            VECTOR x1       = _x.row(_springs(i, 1));
            REAL   len      = (x0 - x1).norm();
            _rest_length(i) = len;
        }
        return true;
    }

    void MassSpringSystem::CalculateForces()
    {
        MATRIX gravity = _m * ROWVECTOR3(0, -9.8, 0);
        _f += gravity;

        for (int i = 0; i < _springs.rows(); i++)
        {
        }

        _f += -_k * _v;
    }

} // namespace snow
