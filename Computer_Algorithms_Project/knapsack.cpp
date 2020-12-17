#include<iostream>
#include"Factory.h"

Dictionary** quickSort(Dictionary** list, int p, int r);
int partition(Dictionary** list,int p, int r);
int choosePivot(Dictionary** list);

int main1()
{
	Factory dict;
	int numberOfElements, weight, value;
	float coeff;
	std::cin >> numberOfElements;

	Dictionary** list = new Dictionary*[numberOfElements];
	for (int i = 0; i < numberOfElements; i++)
	{
		std::cout << "Weight: ";
		std::cin >> weight;
		std::cout << "Value: ";
		std::cin >> value;
		std::cout << "\n";
		coeff = float(value) / float(weight);
		list[i] = dict.getObject(weight, value, coeff);
	}
	
	std::swap(list[0], list[choosePivot(list)]);

	quickSort(list, 0, numberOfElements-1);

	for (int i = 0; i < numberOfElements; i++)
	{
		std::printf("%d %d %.2f\n", *list[i]->getDictionaryElement(), 
			*(list[i]->getDictionaryElement() + 1), list[i]->getDictionaryCoeff());
	}


	return 0;
}

Dictionary** quickSort(Dictionary** list, int p, int r)
{
	if (p < r)
	{
		int q = partition(list, p, r);
		quickSort(list, p, q - 1);
		quickSort(list, q + 1, r);
	}
	return list;
}

int partition(Dictionary** list, int p, int r)
{
	float x = list[r]->getDictionaryCoeff();
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (list[j]->getDictionaryCoeff() >= x)
		{
			i = i + 1;
			std::swap(list[i], list[j]);
		}
	}
	std::swap(list[i + 1], list[r]);

	return i + 1;
}

int choosePivot(Dictionary** list)
{
	int length = sizeof(list)/4;
	int sum = 0, median, min_difference = NULL, difference, closestToMidean;

	for(int i = 0; i < length; i++)
		sum = sum + list[i]->getDictionaryCoeff();

	median = sum / length;

	for (int i = 0; i < length; i++)
	{
		difference = median - list[i]->getDictionaryCoeff();
		if (min_difference || difference < min_difference)
		{
			min_difference = difference;
			closestToMidean = list[i]->getDictionaryCoeff();
		}
	}

	return closestToMidean;
}

