#include<iostream>
#include<time.h>
#include<cmath>
#include<conio.h>
using namespace std;
int* createArray(int size);
void fillArray(int* arr, int size);
void printArray(int* arr, int size);
void deleteArray(int* a);
int numOfElement();
int allNumbersThatAreSmallerThenTheDifferenceBetweenTwoPrevious();
int numLineLenght();
int** createSquareMatrix(int n);
void fillSquareMatrix(int** matrix, int n);
void printSquareMatrix(int** matrix, int n);
void deleteSquareMatrix(int** a, int n);
int transponedMatrix();
double** createMatrixOfCoordinates(int n);
void fillMatrixOfCoordinates(double** matrix, int n);
void printMatrixOfCoordinates(double** matrix, int n);
void deleteMatrixOfCoordinates(double** matrix, int n);
int maxDistanceBetweenDots();
int main()
{
	int task;
	while (1)
	{
		cout << "Enter a task number(0-finish your work):"; cin >> task; cout << endl;
		switch (task)
		{
		case 1: numOfElement(); break;
		case 2: allNumbersThatAreSmallerThenTheDifferenceBetweenTwoPrevious(); break;
		case 3: numLineLenght(); break;
		case 4: transponedMatrix(); break;
		case 5: maxDistanceBetweenDots(); break;
		case 0: return 0; break;
		default:cout << "Error!!!Number 1 to 5!!!\nTry again" << endl;
		}

	}
	return 0;
}

int* createArray(int size)
{
	int* arr = new int[size];
	return arr;
}
void fillArray(int* arr, int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 21-10;
	}
}
void printArray(int* arr, int size)
{
	cout << "Your array:";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void deleteArray(int* a)
{
	delete[] a;
}
int numOfElement()
{
	int size;
	cout << "Enter the size of array" << endl;
	cin >> size; cout << endl;
	int n; cout << "Enter the element for search" << endl; cin >> n; cout << endl;
	int *arr = createArray(size);
	fillArray(arr, size);
	printArray(arr,size);
	for (int i = 0; i < size; i++)
	{
		if (n == arr[i]) { cout << "The number if this element is:" << i << endl; break; }
		if (i == size-1) { cout << "There is no such element in this array"<<endl; }
	}
	deleteArray(arr);
    return 0;
}
int allNumbersThatAreSmallerThenTheDifferenceBetweenTwoPrevious()
{
	int size; cout << "Enter the size of array" << endl; cin >> size; cout << endl;
	int* arr = createArray(size);
	fillArray(arr, size);
	printArray(arr, size);
	int k = 0;
	cout << "The numbers that are smaller then the diiference between two previous:";
	for (int i = 2; i < size; i++)
	{
		if (arr[i - 1] - arr[i - 2] > arr[i]) {
			cout << arr[i] << " "; k++;
		}
	}
	if (k==0) {
		cout << "There are no numbers that are smaller then the differce between two previous";
	}
	cout << endl;
	deleteArray(arr);
	return 0;
}
int numLineLenght()
{
	int size; 
	cout << "Enter the size of array" << endl; cin >> size; cout << endl;
	int* arr = createArray(size);
	fillArray(arr, size);
	printArray(arr, size);
	int j = 1; int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == arr[i + 1])j++;
		else {
			if (max < j)
				max = j;
				j = 1;
		}
	}
	cout <<"The longest line of the similar numbers:"<< max << endl;
	deleteArray(arr);
	return 0;
}
int** createSquareMatrix(int n)
{
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}
	return matrix;
}
void fillSquareMatrix(int** matrix, int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 21-10;
		}
	}
}
void printSquareMatrix(int** matrix, int n)
{
	cout << "Initial matrix:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void deleteSquareMatrix(int** a,int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[]a[i];
	}
	delete[]a;
}
int transponedMatrix()
{
	int size; cout << "Enter your matrix size(only square matrices are acceptable)" << endl;; cin >> size; cout << endl;
	int** matrix = createSquareMatrix(size);
	fillSquareMatrix(matrix, size);
	printSquareMatrix(matrix, size);
	cout << "Matrix transponed ragarding main diagonal:" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrix[j][i] << " ";
		}
		cout << endl;
	}
	cout << "Matrix transponed regarding collateral diagonal:" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrix[size - 1 - j][size - 1 - i] << " ";
		}
		cout << endl;
	}
	deleteSquareMatrix(matrix, size);
	return 0;
}
double** createMatrixOfCoordinates(int n)
{

	double** matrix = new double* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[n];
	}
	return matrix;
}
void fillMatrixOfCoordinates(double** matrix, int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matrix[i][j] = rand() % 21-10;
		}
	}
}
void printMatrixOfCoordinates(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void deleteMatrixOfCoordinates(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
}
int maxDistanceBetweenDots()
{
	int numDots;
	cout << "Number of dots:"; cin >> numDots; cout << endl;
	double** coordinateMtrx = createMatrixOfCoordinates(numDots);
	fillMatrixOfCoordinates(coordinateMtrx, numDots);
	cout << "Here is matrix of coordinates. First column-all X coordinates, second column-all Y coordinates." << endl;
	printMatrixOfCoordinates(coordinateMtrx, numDots);
	double distance;
	double max = 0;
    for (int i = 0; i < numDots; i++)
		{
			for (int k = 0; k < numDots - 1; k++)
			{

				distance = sqrt((coordinateMtrx[i][0] - coordinateMtrx[k][0]) * (coordinateMtrx[i][0] - coordinateMtrx[k][0]) + (coordinateMtrx[i][1] - coordinateMtrx[k][1]) * (coordinateMtrx[i][1] - coordinateMtrx[k][1]));
				if (max < distance)max = distance;
			}
		}
		cout << "Maximum distance is between two dots is " << max << endl;
		deleteMatrixOfCoordinates(coordinateMtrx, numDots);
	return 0;
}

