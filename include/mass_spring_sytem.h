#pragma once
#include "system.h"

namespace snow
{
    class MassSpringSystem : public System
    {
    public:
        bool SetSprings(const MATRIXI springs);
        REAL _k  = 0.0;   // spring stiffness
        REAL _ks = 400.0; // spring stiffness
        REAL _kd = 0.00;  // damping coefficient

    private:
        void    CalculateForces() override;
        MATRIXI _springs;
        VECTOR  _rest_length;
    };
} // namespace snow
