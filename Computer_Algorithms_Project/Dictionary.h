class Dictionary
{
public:
	Dictionary(int key, int value, float coeff);
	~Dictionary();
	void setDictionaryElement(int key, int value, float coeff);
	int* getDictionaryElement();
	float getDictionaryCoeff();

private:
	int element[2];
	float coeff;
};

Dictionary::Dictionary(int key, int value, float coeff)
{
	setDictionaryElement(key, value, coeff);
}

Dictionary::~Dictionary()
{
}

inline void Dictionary::setDictionaryElement(int key, int value, float coeff)
{
	this->element[0] = key;
	this->element[1] = value;
	this->coeff = coeff;

}

inline int* Dictionary::getDictionaryElement()
{
	return element;
}

inline float Dictionary::getDictionaryCoeff()
{
	return coeff;
}
