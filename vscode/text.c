#include <math.h>
#include "stdio.h" 
#include "stdlib.h" 

#define E1 0.001 
#define ep 0.00001 
#define n 2 
#define k 4 


double af;
int i, j;
double X0[n], XX[n], X[k][n], FF[k];
double a[n], b[n];
double rm = 2657863.0;

double F(double C[n])//text function 
{
	double F;
	F = pow(C[0] - 3, 2) + pow(C[1] -4, 2);
	return F;
}
int cons(double D[n])
{
	if ((D[0] >= 0) && (D[1] >= 0) && (D[0] <= 6) && (D[1] <= 8) && ((2.5-D[0] + D[1]) >= 0) && ((5-D[0]-D[1]) >= 0))
		return 1;
	else
		return 0;
}
void bou()
{
	a[0] = 0; b[0] = 6;
	a[1] = 0; b[1] = 8;
}
double r()
{
	double r1, r2, r3, rr;
	r1 = pow(2, 35); r2 = pow(2, 36); r3 = pow(2, 37); rm = 5 * rm;
	if (rm >= r3) { rm = rm-r3; }
	if (rm >= r2) { rm = rm-r2; }
	if (rm >= r1) { rm = rm-r1; }
	rr = rm / r1;
	return rr;
}
void produce(double A[n], double B[n])
{
	int jj; double S;
sl: for (i = 0; i < n; i++)
{
	S = r();
	XX[i] = A[i] + S * (B[i]-A[i]);
}
	if (cons(XX) == 0)
	{
		goto sl;
	}
	for (i = 0; i < n; i++)
	{
		X[0][i] = XX[i];
	}
	for (j = 1; j < k; j++)
	{
		for (i = 0; i < n; i++)
		{
			S = r();
			X[j][i] = A[i] + S * (B[i]-A[i]);
		}
	}
	for (j = 1; j < k; j++)
	{
		for (i = 0; i < n; i++)
		{
			X0[i] = 0;
			for (jj = 1; jj < j + 1; jj++)
			{
				X0[i] += X[jj][i];
			}
			X0[i] = (1 / j) * (X0[i]);
		}
		if (cons(X0) == 0)
		{
			goto sl;
		}
		for (i = 0; i < n; i++)
		{
			XX[i] = X[j][i];
		}
		while (cons(XX) == 0)
		{
			for (i = 0; i < n; i++)
			{
				X[j][i] = X0[i] + 0.5 * (X[j][i]-X0[i]);
				XX[i] = X[j][i];
			}
		}
	}
}

int main()
{
	double EE, Xc[n], Xh[n], Xg[n], X1[n], Xr[n], Xs[n], w;
	int l, lp, lp1;
	bou();
s111:produce(a, b);
s222:for (j = 0; j < k; j++)
{
	for (i = 0; i < n; i++)
	{
		XX[i] = X[j][i];
	}
	FF[j] = F(XX);
}
	 for (l = 0; l < k-1; l++)
	 {
		 for (lp = 0; lp < k-1; lp++)
		 {
			 lp1 = lp + 1;
			 if (FF[lp] < FF[lp1])
			 {
				 w = FF[lp]; FF[lp] = FF[lp1]; FF[lp1] = w;
				 for (i = 0; i < n; i++)
				 {
					 XX[i] = X[lp][i]; X[lp][i] = X[lp1][i]; X[lp1][i] = XX[i];
				 }
			 }
		 }
	 }
	 for (i = 0; i < n; i++)
	 {
		 Xh[i] = X[0][i]; Xg[i] = X[1][i]; X1[i] = X[k-1][i];
	 }
	 for (i = 0; i < n; i++)
	 {
		 Xs[i] = 0;
		 for (j = 0; j < k; j++)
		 {
			 Xs[i] += X[j][i];
		 }
		 Xs[i] = 1 / (k + 0.0) * Xs[i];
	 }
	 EE = 0;
	 for (j = 0; j < k; j++)
	 {
		 EE += pow((FF[j]-F(Xs)), 2);
	 }
	 EE = pow((1 / (k + 0.0) * EE), 0.5);
	 if (EE <= E1)
	 {
		 goto s333;
	 }
	 for (i = 0; i < n; i++)
	 {
		 Xc[i] = 0;
		 for (j = 1; j < k; j++)
		 {
			 Xc[i] += X[j][i];
		 }
		 Xc[i] = 1 / (k-1.0) * Xc[i];
	 }
	 if (cons(Xc) == 1)
	 {
		 af = 1.3;
	 ss:for (i = 0; i < n; i++)
	 {
		 Xr[i] = Xc[i] + af * (Xc[i]-Xh[i]);
	 }
		if (cons(Xr) == 1)
		{
			if (F(Xr) >= F(Xh))
			{
				if (af <= ep)
				{
					for (i = 0; i < n; i++)
					{
						Xh[i] = Xg[i];
					}
					af = 1.3; goto ss;
				}
				else
				{
					af = 1 / 2.0 * af; goto ss;
				}
			}
			else
			{
				for (i = 0; i < n; i++)
				{
					X[0][i] = Xr[i];
				}
				goto s222;
			}
		}
		else
		{
			af = 1 / 2.0 * af; goto ss;
		}
	 }
	 else
	 {
		 for (i = 0; i < n; i++)
		 {
			 if (X1[i] < Xc[i])
			 {
				 a[i] = X1[i]; b[i] = Xc[i];
			 }
			 else
			 {
				 a[i] = Xc[i]; b[i] = X1[i];
			 }
		 }
		 goto s111;
	 }
 s333:printf("F(Xmin)=%f\n", F(X1));
	 for (i = 0; i < n; i++)
	 {
		 printf("\n The X%d is %f.", i, X1[i]);
	 }
   system ("pause");
}
