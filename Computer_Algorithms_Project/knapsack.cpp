//#include<iostream>
//#include"Good.h"
//
//List** quickSort(List** list, int p, int r);
//int partition(List** list,int p, int r);
//int choosePivot(List** list);
//
//int main1()
//{
//	Good dict;
//	int numberOfElements, weight, value;
//	float coeff;
//	std::cin >> numberOfElements;
//
//	List** list = new List*[numberOfElements];
//	for (int i = 0; i < numberOfElements; i++)
//	{
//		std::cout << "Weight: ";
//		std::cin >> weight;
//		std::cout << "Value: ";
//		std::cin >> value;
//		std::cout << "\n";
//		coeff = float(value) / float(weight);
//		list[i] = dict.addToList(weight, value);
//	}
//	
//	std::swap(list[0], list[choosePivot(list)]);
//
//	quickSort(list, 0, numberOfElements-1);
//
//	for (int i = 0; i < numberOfElements; i++)
//	{
//		std::printf("%d %d %.2f\n", *list[i]->getGoodElement(), 
//			*(list[i]->getGoodElement() + 1), list[i]->getGoodCoeff());
//	}
//
//
//	return 0;
//}
//
//List** quickSort(List** list, int p, int r)
//{
//	if (p < r)
//	{
//		int q = partition(list, p, r);
//		quickSort(list, p, q - 1);
//		quickSort(list, q + 1, r);
//	}
//	return list;
//}
//
//int partition(List** list, int p, int r)
//{
//	float x = list[r]->getGoodCoeff();
//	int i = p - 1;
//	for (int j = p; j <= r - 1; j++)
//	{
//		if (list[j]->getGoodCoeff() >= x)
//		{
//			i = i + 1;
//			std::swap(list[i], list[j]);
//		}
//	}
//	std::swap(list[i + 1], list[r]);
//
//	return i + 1;
//}
//
////int choosePivot(List** list)
////{
////	int length = sizeof(list)/4;
////	int sum = 0, median, min_difference = NULL, difference, closestToMidean;
////
////	for(int i = 0; i < length; i++)
////		sum = sum + list[i]->getListCoeff();
////
////	median = sum / length;
////
////	for (int i = 0; i < length; i++)
////	{
////		difference = median - list[i]->getListCoeff();
////		if (min_difference || difference < min_difference)
////		{
////			min_difference = difference;
////			closestToMidean = list[i]->getListCoeff();
////		}
////	}
////
////	return closestToMidean;
////}
//
