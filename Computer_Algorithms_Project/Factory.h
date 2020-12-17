#include"Dictionary.h"

class Factory
{
public:
	Dictionary* getObject(int key, int value, float coeff)
	{
		return new Dictionary(key, value, coeff);
	}

};
