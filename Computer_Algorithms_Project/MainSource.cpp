#include<iostream>
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
    shortWays[10][10], P[10][10];

List** quickSort(List** list, int p, int r);
int partition(List** list, int p, int r);
void calculateShortWays();
void display();


void onTheRoadGoods(List* good, int *visitedCities, int* counter)
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

}

bool semaphore(int city, int* visitedCities, int numberOfElements)
{
    for (int i = 0; i < numberOfElements; i++)
    {
        if (city == *(visitedCities + i))
            return true;
    }

    return false;
}

int* getOptimalList(int max_weight, int numberOfElements, List **list) {
    int* optimalList = new int[numberOfElements], *visitedCities;
    int* visitedCities = new int[numberOfElements];
    List* good;
    int currentLocation = 0, lastIndex, *counter = 0;
    while (max_weight!=0 || numberOfElements != 0)
    {
        lastIndex = numberOfElements - 1;
        //Coefficient of Knapsack
        for (int i = 0; i < numberOfElements; i++)
        {
            good = list[i];
            if (semaphore(good->getDirectionY(), visitedCities, numberOfElements))
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
        }
        
        //sorted in ascending order
        quickSort(list, 0, lastIndex);
        
        //since the list is sorted in ascending order the last element would be best
        //take last element add to optimalList and delete in list of all goods
        if (max_weight - list[lastIndex]->getGoodWeight()>0)
        {
            max_weight = max_weight - list[lastIndex]->getGoodWeight();
            onTheRoadGoods(list[lastIndex], visitedCities, counter);
            optimalList[lastIndex] = list[lastIndex]->getName();
            delete list[lastIndex];
        }
        else
        {

        }
            
     
        //On the road Goods
        
        currentLocation = list[numberOfElements]->getDirectionX();
        numberOfElements--;

    }
    return optimalList;
    //TODO uchest kogda net podhodashih elementov, no max_weight != 0
    //TODO esli ne podhodit posledniy element to dvinutsa na pred
    //TODO kogda nado udalat' ne posledniy element nado sdelat' sdvig nalevo, inahche dirka

}



int main() 
{
    display();
    return 0;


    int numberOfElements, weight, value, x, y;
    int name = 0;
    cout << "Number of Goods: ";
    cin >> numberOfElements;

    List** list = new List * [numberOfElements];
    Good good;
    cout << "\n|0. A\t1. B\t2. C\t3. D\t4. E\t5. F\t6. G\t7. H\t8. I\t9. J|\n" << endl;
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << "Weight: ";
        cin >> weight;
        cout << "Value: ";
        cin >> value;
        cout << "Start: ";
        cin >> y;
        cout << "Finish: ";
        cin >> x;
        list[i] = good.addToList(weight, value, x, y);
        
        list[i]->setName(name);
        name++;
    }
    

    return 0;
}

void display()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << cities[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    calculateShortWays();

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << shortWays[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << P[i][j] << " ";
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

void calculateShortWays() {

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
