#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ak 0.003
#define deta  0.001

double f(double* x)
{
	double y;
	y = (x[0] - 2) * (x[0] - 2) + (x[1] - 3) * (x[1] - 3);
	return y;
}

void fun(double* x_k1, double* x_k, double* s_k, double a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		x_k1[i] = x_k[i] + a * s_k[i];
	}
}

void GetSearchArea(int n, double* x_k, double* s_k, double* a1, double* a3)
{
	double a = ak, s, f0, a2 = 0;
	double f1 = 0, f2 = 0, f3 = 0;
	double* x_k1;
	x_k1 = (double*)malloc(n * sizeof(double));
	f2 = f(x_k);
	while (1)
	{
		*a1 = a2 + a;
		fun(x_k1, x_k, s_k, *a1, n);
		f1 = f(x_k1);
		if (f1 > f2)
		{
			if (a == ak)
			{
				*a3 = *a1;
				f3 = f1;
				a = -a;
				continue;
			}
			else if (*a1 > *a3)
			{
				s = *a1;
				*a1 = *a3;
				*a3 = s;
				f0 = f1;
				f1 = f3;
				f3 = f0;
				break;
			}
			else break;
		}
		else
		{
			*a3 = a2;
			a2 = *a1;
			f3 = f2;
			f2 = f1;
			continue;
		}
	}

}
void GoldDivision(int n, double a1, double a4, double* x_k, double* s_k)
{
	double a2, a3, f2, f3, a_star;
	double* x_k2, * x_k3;
	int i;
	x_k2 = (double*)malloc(n * sizeof(double));
	x_k3 = (double*)malloc(n * sizeof(double));

	for (i = 0; i < n; i++)
	{
		x_k2[i] = 0;
		x_k3[i] = 0;
	}

	a2 = a1 + 0.382 * (a4 - a1);
	fun(x_k2, x_k, s_k, a2, n);
	f2 = f(x_k2);
	a3 = a1 + 0.618 * (a4 - a1);
	fun(x_k3, x_k, s_k, a3, n);
	f3 = f(x_k3);
	do
	{
		if (f2 <= f3)
		{
			a4 = a3;
			a3 = a2;
			f3 = f2;
			a2 = a1 + 0.382 * (a4 - a1);
			fun(x_k2, x_k, s_k, a2, n);
			f2 = f(x_k2);
		}
		else
		{
			a1 = a2;
			a2 = a3;
			f2 = f3;
			a3 = a1 + 0.618 * (a4 - a1);
			fun(x_k3, x_k, s_k, a3, n);
			f2 = f(x_k3);
		}
	} while (fabs(a4 - a1) > deta);
	a_star = (a1 + a1) * 0.5;
	fun(x_k, x_k, s_k, a_star, n);
	free(x_k2);
	free(x_k3);
}

void LunHuan(int n, double* x_k, double* f0)
{
	double sum;
	double* a_star = 0, * f_star = 0, * x0;
	double** s_k;
	double a1 = 0, a3 = 0;
	double* a_1, * a_3;
	int i, j;
	a_1 = &a1;
	a_3 = &a3;
	x0 = (double*)malloc(n * sizeof(double));
	s_k = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++)
	{
		s_k[i] = (double*)malloc(n * sizeof(double));
		for (j = 0; j < n; j++)
			if (i == j)
				s_k[i][j] = 1;
			else
				s_k[i][j] = 0;
	}
	while (1)
	{
		for (i = 0; i < n; i++)
			x0[i] = x_k[i];
		for (i = 0; i < n; i++)
		{
			GetSearchArea(n, x_k, s_k[i], a_1, a_3);
			GoldDivision(n, *a_1, *a_3, x_k, s_k[i]);
		}
		sum = 0;
		for (i = 0; i < n; i++)
		{
			sum += (x0[i] - x_k[i]) * (x0[i] - x_k[i]);

		}
		if (sqrt(sum) <= deta)
			break;
	}
	*f0 = f(x_k);
	free(x0);
	for (i = 0; i < n; i++)
	{
		free(s_k[i]);
	}
	free(s_k);

}
int main()
{
	double* x_k, * f;
	double f0 = 0;
	f = &f0;
	int n, i;
	printf("f=(x[0]-2)*(x[0]-2)+(x[1]-3)*(x[1]-3)\n");
	printf("请输入维数n:\n");
	scanf_s("%d", &n);

	x_k = (double*)malloc(n * sizeof(double));

	printf("起始坐标x_k:\n");
	for (i = 0; i < n; i++)
		scanf_s("%lf", &x_k[i]);

	LunHuan(n, x_k, f);

	printf("函数极小点坐标:\n");
	for (i = 0; i < n; i++)
	{
		printf("%lf;", x_k[i]);
	}
	printf("\n");

	free(x_k);
	return 0;
	return 0;
}