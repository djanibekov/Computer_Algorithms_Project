class City
{
public:
	City() {}
	City(int xDirection, int yDirection);
	~City() {}
	int getXDirection();
	int getYDirection();
	void setXDirection(int xDirection);
	void setYDirection(int yDirection);

private:
	int xDirection, yDirection;
};

City::City(int xDirection, int yDirection)
{
	this->xDirection = xDirection;
	this->yDirection = yDirection;
}

inline int City::getXDirection()
{
	return xDirection;
}

inline int City::getYDirection()
{
	return yDirection;
}

inline void City::setXDirection(int xDirection)
{
	this->xDirection = xDirection;
}

inline void City::setYDirection(int yDirection)
{
	this->yDirection = yDirection;
}
