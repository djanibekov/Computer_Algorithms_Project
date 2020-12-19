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



void getOptimalList(int max_weight, int numberOfElements, List **list) {

    List* good;
    int start = 0;
    int currentLocation = 0;
    while (max_weight!=0 || start != numberOfElements)
    {
        //Coefficient of Knapsack
        for (int i = start; i < numberOfElements; i++)
        {
            good = list[i];
            good->setGoodCoeff(

            (good->getGoodValue() - shortWays[currentLocation][good->getDirectionX()])/good->getGoodWeight()
            
            );
        }
        quickSort(list, 0, numberOfElements - 1);
        max_weight = max_weight - list[start]->getGoodWeight();

        //On the road Goods
        
        currentLocation = list[start]->getDirectionY();

        start++;

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
        if (list[j]->getGoodCoeff() >= x)
        {
            i = i + 1;
            std::swap(list[i], list[j]);
        }
    }
    std::swap(list[i + 1], list[r]);

    return i + 1;
}

void display();

int main() 
{
    //display();
    //return 0;


    int numberOfElements, weight, value, x, y;
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
