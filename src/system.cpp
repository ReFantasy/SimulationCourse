#include "system.h"
#include "types.h"
#include <iostream>
namespace snow
{
    int  System::Dims() const { return _x.rows() * 6; }
    bool System::GetState(MATRIX& x, MATRIX& v) const
    {
        if (_x.rows() == 0)
            return false;

        x = _x;
        v = _v;
        return true;
    }
    bool System::SetState(const MATRIX x, const MATRIX v)
    {
        if (x.rows() != _x.rows() || x.cols() != _x.cols())
            return false;

        _x = x;
        _v = v;
        return true;
    }
    bool System::GetMass(SPARSE_MATRIX& SP_Mass)
    {
        int xdims = _x.rows() * 3;
        if (xdims == 0)
            return false;

        static SPARSE_MATRIX M(xdims, xdims);
        if (M.nonZeros() == 0)
        {
            std::vector<SparseMatrixTriplet> triplets;
            for (int i = 0; i < xdims; i++)
                triplets.push_back(SparseMatrixTriplet(i, i, _m(i / 3)));
            M.setFromTriplets(triplets.begin(), triplets.end());
        }
        SP_Mass = M;
        return true;
    }

    void System::Derivative(MATRIX& v, MATRIX& a)
    {
        // clear forcees
        if (_f.rows() != _x.rows() || _f.cols() != _x.cols())
            _f.resize(_x.rows(), _x.cols());
        _f.setZero();

        // compute force
        CalculateForces();

        v = _v;
        a = _f.array().colwise() / _m.array();
    }


    System::~System() {}
} // namespace snow
