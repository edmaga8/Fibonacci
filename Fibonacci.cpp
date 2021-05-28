/*
	Este programa es para practicar Recursividad.
*/
#include <iostream>

int recursividad(int );
int recurs_mem(int );
int recur_iterativa(int);
int F[50];
int main()
{
	

	for (int i = 0; i < 50; i++)
	{
		F[i] = -1;
	}
	std::cout << "El valor Fibonacci es: " << recur_iterativa(6);

	return 0;
}

/*En este primer caso se aplica la recursividad tal cual, llamando a las funciones -1 y -2*/
int recursividad(int n)
{

	if (n <= 1)
	{
		return n;
	}

	else
		return recursividad(n - 1) + recursividad(n - 2);
}

/*En este caso se tiene la recursividad con memoization, esto es, reutilizando los valores ya calculados al guardarlos en un arreglo.

El arreglo es creado a parte e inicializando a -1 todos sus valores.
Luego, dentro de la función se inicializan los primeros valores y se pide que devuelvan eso si son solicitados.
Para el resto de valores, se retorna el valor en la posición respectiva del arreglo si estuviera y si no, se calcula y se carga.*/
int recurs_mem(int n)
{


	F[0] = 0;
	F[1] = 1;

	if (n <= 1)
	{
		return F[n];
	}

	if (F[n] != -1)
		return F[n];
	
	else
		F[n] = recurs_mem(n - 1) + recurs_mem(n - 2);

	return F[n];
}

/*
Esta implementación es la interativa, aquí se calcula un valor en función de los dos anteriores y se van actualizando hasta el valor a devolverse.*/
int recurs_iterativa(int n)
{
	if (n <= 1)
		return n;
	int f = 0;
	int f1 = 0;
	int f2 = 1;
	for (int i = 2; i <= n; i++)
	{
		f = f1 + f2;
		f1 = f2;
		f2 = f;
	}

	return f;
}