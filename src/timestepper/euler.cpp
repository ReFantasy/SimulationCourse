#include "timestepper/euler.h"
namespace snow
{
    void EulerStep(System& system, REAL dt)
    {
        MATRIX x0, v0;
        system.GetState(x0, v0);


        // 设置新状态
        // system.SetState(x1, v1);
    }

} // namespace snow
