# Chirped-Bragg Grating Design: Enhanced Transfer Matrix Method

## Introduction: End Goal

This simulation calculates the reflected and transmitted waves in a multilayer medium. The medium is assumed to be isotropic and spans infinitely in the `x` and `y` direction. The plane waves are propagating along the `z`-direction, however, the code can be adjusted for an incidence angle of choice. The electric and magnetic fields along the `z`-direction are discontinuous due to the multilayer medium. The boundary conditions are the continuity of the tangential components. Absorption is introduced through the imaginary part of the refractive index, where the sign of the wave vector depends on the propagation direction along the `z` axis (i.e. `z > 0` or `z < 0`). The usual Transfer Matrix Method (TMM) doesn't distinguish between forward and backward propagating plane modes and treats all waves as forward propagating, which leads to instabilities in the computation. Therefore a distinction between forward and backward propagating modes is required. This is achieved by calculating the Poynting vector and rearranging the columns of the eigen-vector matrix `W` and the columns of the eigen-value matrix `λ` accordingly.

Source: EM Possible: Computational Electromagnetics: Topic 2: TMM 

## Current Status:

1) Need to calculate Poynting vector for each mode and rearrange the column vectors of matrices `W` and `λ`.