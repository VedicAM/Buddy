#include "BML\BFPM\FIXED.H"

fixed doubleToFixed(double d)
{
	return (fixed)(d * (double)(1 << dp) + (d >= 0 ? 0.5 : -0.5));
}

double fixedToDouble(fixed f)
{
	return (double)(f) / (1 << dp);
}

fixed add(fixed a, fixed b)
{
	return a + b;
}

fixed subtract(fixed a, fixed b)
{
	return a - b;
}

fixed multiply(fixed a, fixed b)
{
	long result = (long)a * (long)b;
	return (fixed)(result >> dp);
}

fixed divide(fixed a, fixed b)
{
	return (fixed)(((long)a << dp) / (long)b);
}
