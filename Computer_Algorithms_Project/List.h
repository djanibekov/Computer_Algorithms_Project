#include"City.h"
class List
{
public:
	List(int weight, int value, int xDirection, int yDirection);
	~List() {}
	int getGoodWeight();
	int getGoodValue();
	float getGoodCoeff();
	void setGoodCoeff(int coeff);
	int getDirectionX();
	int getDirectionY();
	void setName(int name);
	int getName();

private:
	int weight, value;
	float coeff;
	City direction;
	int name;
};

List::List(int weight, int value, int xDirection, int yDirection)
{
	this->weight = weight;
	this->value = value;
	this->direction = City(xDirection, yDirection);
	coeff = 0;
}

inline int List::getGoodWeight()
{
	return weight;
}

inline int List::getGoodValue()
{
	return weight;
}

inline float List::getGoodCoeff()
{
	return coeff;
}

inline void List::setGoodCoeff(int coeff)
{
	this->coeff = coeff;
}

inline int List::getDirectionX()
{
	return direction.getXDirection();
}

inline int List::getDirectionY()
{
	return direction.getYDirection();
}

inline void List::setName(int name)
{
	this->name = name;
}

inline int List::getName()
{
	return name;
}
