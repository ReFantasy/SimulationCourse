#pragma once
// #define EIGEN_USE_MKL_ALL
#include <Eigen/Dense>
#include <Eigen/Sparse>

namespace snow
{
    using REAL = double;
    // using REAL = float;

    using MATRIX3    = Eigen::Matrix<REAL, 3, 3>;
    using MATRIX4    = Eigen::Matrix<REAL, 4, 4>;
    using MATRIX9    = Eigen::Matrix<REAL, 9, 9>;
    using MATRIX3x12 = Eigen::Matrix<REAL, 3, 12>;
    using MATRIX9x12 = Eigen::Matrix<REAL, 9, 12>;
    using MATRIX12   = Eigen::Matrix<REAL, 12, 12>;

    using VECTOR2  = Eigen::Matrix<REAL, 2, 1>;
    using VECTOR3  = Eigen::Matrix<REAL, 3, 1>;
    using VECTOR9  = Eigen::Matrix<REAL, 9, 1>;
    using VECTOR12 = Eigen::Matrix<REAL, 12, 1>;

    using VECTOR2I = Eigen::Matrix<int, 2, 1>;
    using VECTOR3I = Eigen::Matrix<int, 3, 1>;
    using VECTOR4I = Eigen::Matrix<int, 4, 1>;

    using ROWVECTOR2  = Eigen::RowVector<REAL, 2>;
    using ROWVECTOR3  = Eigen::RowVector<REAL, 3>;
    using ROWVECTOR4  = Eigen::RowVector<REAL, 4>;
    using ROWVECTOR2I = Eigen::RowVector<int, 2>;
    using ROWVECTOR3I = Eigen::RowVector<int, 3>;
    using ROWVECTOR4I = Eigen::RowVector<int, 4>;

    using VECTOR              = Eigen::Matrix<REAL, Eigen::Dynamic, 1>;
    using MATRIX              = Eigen::Matrix<REAL, Eigen::Dynamic, Eigen::Dynamic>;
    using VECTORI             = Eigen::Matrix<int, Eigen::Dynamic, 1>;
    using MATRIXI             = Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic>;
    using IndexType           = int;
    using SPARSE_MATRIX       = Eigen::SparseMatrix<REAL>;
    using SparseMatrixTriplet = Eigen::Triplet<REAL, IndexType>;
    using MATRIX3333 = Eigen::Matrix<MATRIX3, 3, 3>;

} // namespace snow
