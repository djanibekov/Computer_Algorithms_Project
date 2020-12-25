#include"City.h"
class List
{
public:
	List(int id, int weight, int value, int xDirection, int yDirection);
	~List() {}
	int getGoodWeight();
	int getGoodValue();
	float getGoodCoeff();
	void setGoodCoeff(int coeff);
	int getDirectionX();
	int getDirectionY();
	int getId();

private:
	int id, weight, value;
	float coeff;
	City direction;
};

List::List(int id, int weight, int value, int xDirection, int yDirection)
{
	this->id = id;
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
	return value;
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

inline int List::getId()
{
	return id;
}
