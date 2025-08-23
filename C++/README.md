# C++ Projects

## Monte Carlo Engine to Estimate value of PI

Built a basic monte carlo engine to simualate to 'n' instances to get value of pi.

Let:
- \( N \) be the total number of random points generated
- \( N_{\text{inside}} \) be the number of points that fall inside the quarter circle

Then the estimate of π is given by:

\[
\pi \approx 4 \times \frac{N_{\text{inside}}}{N}
\]

This works because the area of a quarter circle of radius 1 is \( \frac{\pi}{4} \), and the area of the enclosing unit square is 1. The ratio of points inside the circle to the total points approximates the ratio of these areas.
