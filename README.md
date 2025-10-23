# smoke-simulation

## Introduction
Smoke is a fluid, and we are going to be using the grid way of describing such a phenomenon. There are other ways of simulating a fluid, mainly Lagrangian method that tracks particles through space.

### Simplified Navier-Stokes Equations
Navier-Stokes equations are partial differential equations that describe the motion of viscous fluid substances. One millenium prize problem is proving (or disproving) existence of their smooth solutions.
That is not what we are going to be doing today, mainly because we find it boring, not because we cannot do it. 




### 2D Incompressible Navier-Stokes
For now we will concern ourselves with 2D case:

<div align="center">
  
Velocity: $\mathbf{u} = (u,v)$, density $\rho$, pressure $p$, viscosity $\nu$, forces $f_x, f_y$.

Momentum equations:

$$
\frac{\partial u}{\partial t} + u \frac{\partial u}{\partial x} + v \frac{\partial u}{\partial y} = -\frac{1}{\rho} \frac{\partial p}{\partial x} + \nu \left(\frac{\partial^2 u}{\partial x^2} + \frac{\partial^2 u}{\partial y^2}\right) + f_x
$$

$$
\frac{\partial v}{\partial t} + u \frac{\partial v}{\partial x} + v \frac{\partial v}{\partial y} = -\frac{1}{\rho} \frac{\partial p}{\partial y} + \nu \left(\frac{\partial^2 v}{\partial x^2} + \frac{\partial^2 v}{\partial y^2}\right) + f_y
$$

Continuity (incompressibility):

$$
\frac{\partial u}{\partial x} + \frac{\partial v}{\partial y} = 0
$$
</div>

However, as for our laziness, we will assume no outside forces and no viscosity:



