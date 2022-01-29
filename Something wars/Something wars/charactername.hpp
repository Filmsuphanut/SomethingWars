#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<sstream>


using namespace sf;
using namespace std;

class charactername
{
public:
	charactername();
	~charactername();
	stringstream ss;
	
	String callname(int random);
protected:

private:

	void data();
	String name[101];
	
};

