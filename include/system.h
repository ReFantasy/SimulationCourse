#pragma once
#include "types.h"

namespace snow
{
    class System
    {
    public:
        System() = default;
        int  Dims() const;
        bool GetState(MATRIX& x, MATRIX& v) const;
        bool SetState(const MATRIX x, const MATRIX v);

        bool GetMass(SPARSE_MATRIX& M);

        // the derivative of x,v respect to time
        void Derivative(MATRIX& v, MATRIX& a);

        const MATRIX& Force() const { return _f; }

        virtual ~System();

    private:
        virtual void CalculateForces() = 0;

        // private:
    public:
        MATRIX _x;         // array of position
        MATRIX _v;         // array of velocity
        MATRIX _f;         // array of force
        VECTOR _m;         // array of mass
        REAL   _time = 0.; // simulation clock
    };
} // namespace snow
