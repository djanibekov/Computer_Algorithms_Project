//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
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
////TODO
//
//class Good {
//
//    int price;
//    int weight;
//    City* direction;
//
//    Good(int price, int weight) {
//        this->price = price;
//        this->weight = weight;
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
//    void deletenode(good good) {
//
//        node* node = head;
//        node* ptr = node;
//
//        while (ptr->getgood != good) {
//            node = ptr;
//            ptr = ptr->getnextnode;
//        }
//
//        node = ptr->getnextnode;
//        delete(ptr);
//        size--;
//    }
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
//
//
//int cities[10][10], shortWays[10][10], P[10][10];
//
//void calculateShortWays() {
//
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++) {
//            shortWays[i][j] = cities[i][j];
//        }
//    }
//
//    for (int k = 0; k < 10; k++) {
//        for (int i = 0; i < 10; i++) {
//            for (int j = 0; j < 10; j++) {
//                if (shortWays[i][j] > shortWays[k][j] + shortWays[i][k]) {
//                    shortWays[i][j] = shortWays[k][j] + shortWays[i][k];
//                    P[i][j] = k;
//                }
//            }
//        }
//    }
//
//}
//
//
//
//void getOptimalList() {
//
//
//}
//
//
//int main2() {
//
//
//
//    
//
//
//    return 0;
//}