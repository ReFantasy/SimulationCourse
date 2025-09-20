任意两质点 $x_i$ 和 $x_j$，列向量$x=x_i-x_j$ ，$v=v_i-v_j$，弹簧力为：
$$
f^s=\left[ \begin{matrix}f_e\\-f_e\end{matrix} \right]\\
f_e=-k_s(\Vert x\Vert - L)\frac{x}{\Vert x\Vert}
$$
弹簧力关于位置的导数(Tangent stiffness)：
$$
H^s(x)=\left[ \begin{matrix} \frac{\partial f_e}{\partial x_i}&\frac{\partial f_e}{\partial x_j} \\-\frac{\partial f_e}{\partial x_i}&-\frac{\partial f_e}{\partial x_j}            \end{matrix} \right]=\left[ \begin{matrix}H_e&-H_e\\-H_e&H_e\end{matrix} \right]\\
H_e=k_s\frac{xx^T}{\Vert x\Vert^2}+k_s(1-\frac{L}{\Vert x\Vert})(\mathbb{I}-\frac{xx^T}{\Vert x\Vert^2})
$$
阻尼力为：
$$
f^d=\left[ \begin{matrix}f_d\\-f_d\end{matrix} \right]\\
f_d = -k_d\frac{v\cdot x x}{\Vert x\Vert}
$$

阻尼力的Hessian
$$
H^d_x(v)=\left[ \begin{matrix} \frac{\partial f_d}{\partial x_i}&\frac{\partial f_d}{\partial x_j} \\-\frac{\partial f_d}{\partial x_i}&-\frac{\partial f_d}{\partial x_j}            \end{matrix} \right]=\left[ \begin{matrix}H_x&-H_x\\-H_x&H_x\end{matrix} \right]\\
H_x=-(t_1 xv^T-\frac{k_d t_2}{t_0^3}xx^T+t_1t_2 \mathbb{I}), \quad t_0=\Vert x\Vert,t_1=k_d/t_0,t_2=v^Tx
$$

$$
H^d_v(v)=\left[ \begin{matrix} \frac{\partial f_d}{\partial v_i}&\frac{\partial f_d}{\partial v_j} \\-\frac{\partial f_d}{\partial v_i}&-\frac{\partial f_d}{\partial v_j}            \end{matrix} \right]=\left[ \begin{matrix}H_v&-H_v\\-H_v&H_v\end{matrix} \right]\\
H_v=\frac{-k_d}{\Vert x\Vert}xx^T
$$



## Implicit time integration (BDF-1)

$$
\begin{bmatrix}
\mathbf{x}_{n+1}-\mathbf{x}_n \\
\mathbf{v}_{n+1}-\mathbf{v}_n
\end{bmatrix}=h
\begin{bmatrix}
\mathbf{v}_{n+1} \\
\mathbf{M}^{-1}\mathbf{f}(\mathbf{x}_{n+1},\mathbf{v}_{n+1})
\end{bmatrix}
$$

Let’s consider the case for $\Delta \mathbf{v}$ 
$$
\mathbf{M} \Delta \mathbf{v}=h \mathbf{f}(\mathbf{x}_{n+1},\mathbf{v}_{n+1})
$$
Linearize (one step of Neowton's method)
$$
\mathbf{f}(\mathbf{x}_{n+1},\mathbf{v}_{n+1})\approx\mathbf{f}(\mathbf{x}_{n},\mathbf{v}_{n})+\frac{\partial\mathbf{f}}{\partial\mathbf{x}}\Delta\mathbf{x}+\frac{\partial\mathbf{f}}{\partial\mathbf{v}}\Delta\mathbf{v}
$$
Substitute 
$$
\mathbf{M}\Delta\mathbf{v}=h\left[\mathbf{f}(\mathbf{x}_n,\mathbf{v}_n)+\frac{\partial\mathbf{f}}{\partial\mathbf{x}}\Delta\mathbf{x}+\frac{\partial\mathbf{f}}{\partial\mathbf{v}}\Delta\mathbf{v}\right]
$$
Substitute $\Delta\mathbf{x}=h[\mathbf{v}_n+\Delta \mathbf{v}]$ and clean up
$$
\left[\mathbf{M}-h\frac{\partial\mathbf{f}}{\partial\mathbf{v}}-h^2\frac{\partial\mathbf{f}}{\partial\mathbf{x}}\right]\Delta\mathbf{v}=h\left[\mathbf{f}+h\frac{\partial\mathbf{f}}{\partial\mathbf{x}}\mathbf{v}_n\right]
$$
