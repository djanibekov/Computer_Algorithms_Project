#include"List.h"

class Good
{
public:
	List* addToList(int weight, int value, int xDirection, int yDirection)
	{
		return new List(weight, value, xDirection, yDirection);
	}

};
