#include"List.h"

class Good //Factory, generates objects
{
public:
	List* addToList(int id, int weight, int value, int xDirection, int yDirection)
	{
		return new List(id, weight, value, xDirection, yDirection);
	}

};
