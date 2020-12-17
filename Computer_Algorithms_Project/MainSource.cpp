#include<iostream>
#include<string>
#include<vector>
using namespace std;
//
//class City {
//    char name;
//    int placeInMatrix;
//
//    char getName() {
//        return name;
//    }
//
//    void setName(char name) {
//        this->name = name;
//    }
//
//    int getPlaceInMatrix() {
//        return placeInMatrix;
//    }
//
//    void setPlaceInMatrix(int placeInMatrix) {
//        this->placeInMatrix = placeInMatrix;
//    }
//};
//
//class Good {
//
//    int price;
//    int weight;
//    City* direction;
//
//    Good(int price, int weight, City* direction) {
//        this->price = price;
//        this->weight = weight;
//        this->direction = direction;
//    }
//
//    int getPrice() {
//        return price;
//    }
//
//    int getWeight() {
//        return weight;
//    }
//
//    void setPrice(int price) {
//        this->price = price;
//    }
//
//    void setWeight(int weight) {
//        this->weight = weight;
//    }
//
//    City* getDirection() {
//        return direction;
//    }
//
//    void setDirection(City* direction) {
//        this->direction = direction;
//    }
//};
//
//class List {
//
//    Node* head;
//    int size;
//    Node* getHead() {
//        return head;
//    }
//public:
//    void insertNewNode(Node* newNode) {
//
//        Node* node = head;
//        while (node->getNextNode() != NULL) {
//            node = node->getNextNode();
//        }
//        node = newNode;
//        size++;
//    }
//
//    //void deleteNode(Good good) {
//
//    //    Node* node = head;
//    //    Node* ptr = node;
//
//    //    while (ptr->getGood != good) {
//    //        node = ptr;
//    //        ptr = ptr->getNextNode;
//    //    }
//
//    //    node = ptr->getNextNode;
//    //    delete(ptr);
//    //    size--;
//    //}
//
//    int getSize() {
//        return size;
//    }
//
//};
//
//class Node {
//
//    Node* nextNode;
//    Good good;
//
//public:
//
//    Node* getNextNode() {
//        return nextNode;
//    }
//
//    Good getGood() {
//        return good;
//    }
//
//};
//
int infinity = 1000;

int cities[10][10] = {0, 150, 300, 200, infinity, infinity,infinity,infinity,infinity,infinity,
                      140, 0, 100, infinity, 200, infinity, infinity, infinity, infinity, infinity, 
                      290, 90, 0, 100, infinity, 400, infinity, infinity, infinity, infinity, 
                      190, infinity, 90, 0, infinity, infinity, 300, infinity, infinity, infinity, 
                      infinity, 190, infinity, infinity, 0, infinity, infinity, 200, infinity, infinity, 
                      infinity, infinity, 390, infinity, infinity, 0, infinity, 250, 300, 100,
                      infinity, infinity, infinity, 290, infinity, infinity, 0, infinity, infinity, 200,
                      infinity, infinity, infinity, infinity, 190, 240, infinity, 0, 100, infinity, 
                      infinity, infinity, infinity, infinity, infinity, 290, infinity, 90, 0, infinity, 
                      infinity, infinity, infinity, infinity, infinity, 90, 190, infinity, infinity, 0},
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



void getOptimalList() {


}


int main() {
   
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << cities[i][j]<<" ";
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

    return 0;
}