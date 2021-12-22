#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<string>
using namespace std;
struct PersonalData
{
	string name;
	int age;
	double averageMark;
	int personalId;
};
long long int getFileSize(string fileName);
int countNumberOfStudents(string fileName);
PersonalData* readDataFromFile(string fileName, int& size);
void writeInverseDataInFile(string fileName, PersonalData* arr, int size, int openMode);
void writeDataInFile(string fileName, PersonalData* arr, int size, int openMode);
PersonalData* sortedByMark(PersonalData* array, int& size);
PersonalData* sortedByMark(PersonalData* array, int& size);
int main()
{
	int size = countNumberOfStudents("students.txt");
	PersonalData* array = readDataFromFile("students.txt", size);
	cout << "File <Students> is open and has " << getFileSize("students.txt") << " bytes" << endl;
	writeInverseDataInFile("inverse order.txt", array, size, ios_base::out);
	cout << "Check file <inverse order>." << endl;
	PersonalData* sortedArray = sortedByMark(array, size);
	writeDataInFile("sorted by mark.txt", sortedArray, size, ios_base::out);
	cout << "Check file <sorted by mark>. Students sorted from the lowest mark to the highest." << endl;
	cout << "DONE!" << endl;
	return 0;
}
long long int getFileSize(string fileName)
{
	fstream file(fileName);
	int sizeOfFile = 0;
	file.seekg(0, ios::end);
	sizeOfFile = file.tellg();
	return sizeOfFile;
}
int countNumberOfStudents(string fileName)
{
	int size = 0;
	string s;
	ifstream file(fileName);
	if (!file.is_open())
	{
		cout << "ERROR!!!File cannot be opened" << endl;
		return 0;
	}
	while (getline(file, s))size++;
	file.close();
	return size;
}
PersonalData* readDataFromFile(string fileName, int &size)
{
	ifstream file(fileName);
	if (!file.is_open())
	{
		cout << "ERROR!!!File cannot be opened" << endl;
		return nullptr;
	}
	size = countNumberOfStudents(fileName);
	PersonalData* arr = new PersonalData[size];
	int i = 0;
	while (!file.eof())
	{
		file >> arr[i].name;
		file >> arr[i].age;
		file >> arr[i].averageMark;
		file >> arr[i].personalId;
		i++;
	}
	file.close();
	return arr;
}
void writeInverseDataInFile(string fileName, PersonalData* arr, int size,int openMode)
{
	ofstream file(fileName, openMode);
	if (!file.is_open())
	{
		cout << "ERROR!!!File cannot be opened" << endl;
		return;
	}
	for (int i = size-1; i >=0; i--)
	{
		file << arr[i].name << " "
			<< arr[i].age << " "
			<< arr[i].averageMark << " "
			<< arr[i].personalId << endl;
	}
	file.close();
}
void writeDataInFile(string fileName, PersonalData* arr, int size, int openMode)
{
	ofstream file(fileName, openMode);
	if (!file.is_open())
	{
		cout << "ERROR!!!File cannot be opened" << endl;
		return;
	}
	for (int i = 0; i < size; i++)
	{
		file << arr[i].name << " "
			<< arr[i].age << " "
			<< arr[i].averageMark << " "
			<< arr[i].personalId << endl;
	}
	file.close();
}
PersonalData* sortedByMark(PersonalData* array, int &size)
{
	PersonalData* newArray = new PersonalData[size];
	for (int i = 0; i < size; i++)
	{
		newArray[i]=array[i];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++) 
		{
			if (newArray[i].averageMark > newArray[j].averageMark)swap(newArray[i], newArray[j]);
		}
	}
    return newArray;
}
