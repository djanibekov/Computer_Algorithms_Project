#include<iostream>
#include<math.h>
#include"Good.h"

using namespace std;

int infinity = 1000;
int cities[10][10] = { 0, 150, 300, 200, infinity, infinity,infinity,infinity,infinity,infinity,
                      140, 0, 100, infinity, 200, infinity, infinity, infinity, infinity, infinity,
                      290, 90, 0, 100, infinity, 400, infinity, infinity, infinity, infinity,
                      190, infinity, 90, 0, infinity, infinity, 300, infinity, infinity, infinity,
                      infinity, 190, infinity, infinity, 0, infinity, infinity, 200, infinity, infinity,
                      infinity, infinity, 390, infinity, infinity, 0, infinity, 250, 300, 100,
                      infinity, infinity, infinity, 290, infinity, infinity, 0, infinity, infinity, 200,
                      infinity, infinity, infinity, infinity, 190, 240, infinity, 0, 100, infinity,
                      infinity, infinity, infinity, infinity, infinity, 290, infinity, 90, 0, infinity,
                      infinity, infinity, infinity, infinity, infinity, 90, 190, infinity, infinity, 0 },
    //predefined graph
    shortWays[10][10], P[10][10];

List** quickSort(List** list, int p, int r);
int partition(List** list, int p, int r);
void choseBestPivot(List** list, int size);
void calculateShortWays();
void onTheRoadGoods(List* good, int* visitedCities, int* counter);
bool isVisited(int city, int* visitedCities, int* numberOfElements);
int chooseGood(int max_weight, List** list, int lastIndex);
void shift(List** list, int lastIndex, int deletedIndex);
int* getOptimalList(int max_weight, int numberOfElements, List** list, int* optimalList);
void display();

int main() 
{
    int numberOfElements, weight, value, x, y;
    int id = 0, max_weight;

    calculateShortWays();//predefined graph

    display();

    cout << "Number of Goods: ";
    cin >> numberOfElements;

    cout << "Knapsack capasity: ";
    cin >> max_weight;

    Good good;
    List** list = new List * [numberOfElements]; // double pointer list to keep "good/product" pointers
    int* optimalList = new int[numberOfElements]; //final list that need to be deliver to get max profit
    
    cout << "\n|0. A\t1. B\t2. C\t3. D\t4. E\t5. F\t6. G\t7. H\t8. I\t9. J|\n" << endl;
    cout << "Please enter good`s information (Weight, Value, Destination): " << endl;
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << "Good #" << i + 1 << endl;
        cout << "Weight: ";
        cin >> weight;
        cout << "Value: ";
        cin >> value;
        cout << "Destination: ";
        cin >> x;
        y = 0;
        cout << endl;
        list[i] = good.addToList(id, weight, value, x, y);

        id++;
    }

    optimalList = getOptimalList(max_weight, numberOfElements, list, optimalList);

    int i = 0;
    cout << "Result list: " << endl;
    while (optimalList[i]!=-1)
    {
        cout << optimalList[i] + 1 << " ";//prints the id of good
        i++;
    }
    return 0;
}

void calculateShortWays() {
    //Floyd Warshall algorithm
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            shortWays[i][j] = cities[i][j];
        }
    }

    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (shortWays[i][j] > shortWays[k][j] + shortWays[i][k]) {
                    shortWays[i][j] = shortWays[k][j] + shortWays[i][k];
                    P[i][j] = k;
                }

            }
        }
    }

}

void display() //Debug purpose functoin
{
    //displays cities that predefined
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << cities[i][j] << "| ";
        }
        cout << endl;
    }
    cout << endl;

    //displays short ways from 0 to any city
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << shortWays[i][j] << "| ";
        }
        cout << endl;
    }
    cout << endl;

    //displays relations of cities
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << P[i][j] << "| ";
        }
        cout << endl;
    }
}

List** quickSort(List** list, int p, int r)
{
    if (p < r)
    {
        int q = partition(list, p, r);
        quickSort(list, p, q - 1);
        quickSort(list, q + 1, r);
    }
    return list;
}

int partition(List** list, int p, int r)
{
    float x = list[r]->getGoodCoeff();
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (list[j]->getGoodCoeff() <= x)
        {
            i = i + 1;
            swap(list[i], list[j]);
        }
    }
    swap(list[i + 1], list[r]);

    return i + 1;
}

void choseBestPivot(List** list, int size)
{
    int sum = 0, median, best_median, diff = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + list[i]->getGoodCoeff();
    }
    median = sum / size;
    best_median = 0;
    for (int i = 0; i < size; i++)
    {
        if (abs(median - list[best_median]->getGoodCoeff()) > abs(median - list[i]->getGoodCoeff()))
        {
            best_median = i;
        }
    }
    swap(list[0], list[best_median]);
}


void onTheRoadGoods(List* good, int* visitedCities, int* counter)
{
    int x = good->getDirectionX(), y = good->getDirectionY(), city;
    city = P[y][x];
    while (city != 0)
    {
        visitedCities[*counter] = city;
        x = city;
        (*counter)++;
        city = P[y][x];
    }
    visitedCities[*counter] = y;

    //for (int i = 0; i < *counter; i++)
    //    cout << visitedCities[i] << endl;
}

bool isVisited(int city, int* visitedCities, int* numberOfElements)
{
    for (int i = 0; i < *numberOfElements; i++)
    {
        if (city == visitedCities[i])
            return true;

    }
    return false;
}

int chooseGood(int max_weight, List** list, int lastIndex) {
    for (int i = lastIndex; i >= 0; i--)
        if (max_weight - list[i]->getGoodWeight() >= 0)
            return i;
        else
            return -1;
}

void shift(List** list, int lastIndex, int deletedIndex) {
    for (int i = deletedIndex; i < lastIndex; i++) {
        list[i] = list[i + 1];
    }
}

int* getOptimalList(int max_weight, int numberOfElements, List** list, int* optimalList) {
    List* good;
    int* visitedCities = new int[numberOfElements];
    int currentLocation = 0, lastIndex, counter = 0, optimalCounter = 0;
    while (max_weight != 0 || numberOfElements != 0)
    {
        lastIndex = numberOfElements - 1;
        //calculation of coefficients of the Knapsack
        for (int i = 0; i < numberOfElements; i++)
        {
            good = list[i];

            if (isVisited(good->getDirectionX(), visitedCities, &counter))
            {
                good->setGoodCoeff(
                    good->getGoodValue() / good->getGoodWeight()
                );
            }
            else
            {
                good->setGoodCoeff(
                    (good->getGoodValue() - shortWays[currentLocation][good->getDirectionX()]) / good->getGoodWeight()
                );
            }
            //cout << good->getGoodCoeff() << endl;
        }

        //sorted list in ascending order
        choseBestPivot(list, numberOfElements); // puts best pivot into beginning
        list = quickSort(list, 0, lastIndex);

        //since the list is sorted in ascending order the last element would be best
        //take last element add to optimalList and delete in list of all goods
        int index = chooseGood(max_weight, list, lastIndex); // choose best good that OK with weight
        if (index >= 0)
        {
            max_weight = max_weight - list[index]->getGoodWeight();

            optimalList[optimalCounter] = list[index]->getId();

            if (!isVisited(list[index]->getDirectionX(), visitedCities, &counter))
                //guard that checks whether path A to B had median C(or more)
            {
                onTheRoadGoods(list[index], visitedCities, &counter);//
                currentLocation = list[index]->getDirectionX(); //TODO discuss again
            }
            delete list[index];//deletion of good object in list, forms an empty space

            shift(list, lastIndex, index); //deals with empty space that left after delition
            //simply moves object that after "hole" by index - 1

            cout << "Add to Optimal List good #" << optimalList[optimalCounter] + 1 << endl;

            optimalCounter++;
        }
        else //there is no left good that is OK with weight. Break and go out from loop
        {
            break;
        }

        numberOfElements--;

    }
    optimalList[optimalCounter] = -1;
    return optimalList;

}