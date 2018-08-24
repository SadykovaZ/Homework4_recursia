#include <iostream>
#include<time.h>
using namespace std;

const int n = 10;
// 1.	Написать функцию, определяющую среднее арифметическое элементов передаваемого ей массива.
double average(int a[n], int i, double s)
{
	s += a[i];
	i++;
	if (i == n)return s / n;
	else return average(a, i, s);
}
//2.	Написать функцию, определяющую количество положительных, отрицательных и нулевых элементов передаваемого ей массива.
int function(int a[], int size, int &n, int &p, int &z)
{
	if (size == 0) return size;
	if (a[size] < 0) n++;
	else if (a[size] > 0) p++;
	else z++;
	return function(a, size - 1, n, p, z);
}
// 3.	Написать функцию, определяющую минимум и максимум (значение и номер) элементов передаваемого ей массива.
int aMin(int a[], int size, int min, int i)
{
	int index;
	if (i<size)
	{
		if (a[i]<min)
		{
			min = a[i];
			index = i;			
		}		
		i++;		
		return aMin(a, size, min, i);		
	}	
	else
	{			
		return min;
	}	
}
int minIndex(int a[], int size, int min, int i, int &index)
{
	if (i < size)
	{
		if (a[i] < min)
		{
			min = a[i];
			index = i;
		}
		i++;
		minIndex(a, size, min, i, index);
	}
	else return index;
}
int aMax(int a[], int size, int max, int i)
{
	int index;
	if (i<size)
	{
		if (a[i]>max)
		{
			max = a[i];
			index = i;			
		}
		i++;
		return aMax(a, size, max, i);
	}
	else
	{
		return max;
	}
}
int maxIndex(int a[], int size, int max, int i, int &index)
{
	if (i < size)
	{
		if (a[i] > max)
		{
			max = a[i];
			index = i;
		}
		i++;
		maxIndex(a, size, max, i, index);
	}
	else return index;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int f = 0;
start:
	cout << "Введите номер задания: ";
	cin >> f;

	if (f == 1)
	{
		cout << "1.Написать функцию, определяющую среднее арифметическое элементов передаваемого ей массива." << endl;

		int a[n];
		int i = 0;
		double s = 0;
		for (int i = 0; i < n; i++)
		{
			a[i] = 1 + rand() % 10;
			cout << a[i] << " ";
		}
		cout << endl;
		cout << average(a, i, s) << endl;
	}

	else if (f == 2)
	{
		cout << "2.Написать функцию, определяющую количество положительных, отрицательных и нулевых элементов передаваемого ей массива." << endl;
		int a[] = { -1,-3,0,0,5,8,9,5 };
		int positive = 0, negative = 0, zero = 0;

		cout << function(a, 8, negative, positive, zero);
		cout << "Positive = " << positive << endl;
		cout << "Negative = " << negative << endl;
		cout << "Zero = " << zero << endl;
	}

	else if (f == 3)
	{
		cout << "3.Написать функцию, определяющую минимум и максимум (значение и номер) элементов передаваемого ей массива." << endl;
		int a[] = { 1,2,30,-1,5,6 };
		int min = INT_MAX;
		int max = INT_MIN;
		int i=0;
		int i1 = 0;
		int index1, index;

		cout << "Минимальное значение = "<<aMin(a, 6, min, i) << endl;
		cout << "Индекс минимального значения = " << minIndex(a, 6, min, i, index) << endl;
		cout << endl;
		cout << "Максимальное значение = " << aMax(a, 6, max, i1) << endl;
		cout << "Индекс максимального значения = " << maxIndex(a, 6, max, i1, index1) << endl;
		cout << endl;
	}


	goto start;
	system("pause");
	return 0;
}