#ifndef FREE_END_WAVE_H
#define FREE_END_WAVE_H

#define MAXj 200 // 100 time steps (j) is enough time (given the speed of the wave and the length of the string) for the wave to propagate, reflect and propagate back.
#define MAXi 50 + 1 // Given the size of the string and delta(x), 50 spatial samples (i) is enough to measure the entire string.

extern double y[MAXi][3];
extern double dx, c, r, dt; // r = c*(dt/dx)

/* ********************************************************** */
/* ********************** Initialize ************************ */
/* ********************************************************** */
void initialize();

/* ********************************************************** */
/* *********************** Calculate ************************ */
/* ********************************************************** */
void calculate();

#endif