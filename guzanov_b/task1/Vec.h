#pragma once
#include <iostream>	
using namespace std;
enum measure { kg, pound, troy};
class Vec
{
private:
	float v;
	measure typeV;
public:
	Vec(float ve = 0, measure tv = kg)
	{
		v = ve;
		typeV = tv;
	}
	Vec(const Vec& tmp)
	{
		v = tmp.v;
		typeV = tmp.typeV;
	}
	Vec& operator= (Vec tmp)
	{
		this->v = tmp.v;
		this->typeV = tmp.typeV;
		return *this;
	}
	void Setv(float Vkg)
	{
		v = Vkg;
	}
	float Getv()
	{
		return v;
	}
	measure GettypeV()
	{
		return typeV;
	}
	float Getvtype(measure tp)
	{
		switch (tp)
		{
		case pound:
		{
			float num1 = 2.0462233022f;
			return v * num1;
			break;
		}
		case troy:
		{
			float num2 = 32.1507f;
			return v * num2;
			break;
		}
		}
		return v;
	}
	Vec operator+ (Vec tmp)
	{
		Vec Rezult;
		if (typeV == tmp.typeV)
		{
			Rezult.v = v + tmp.v;
			float num3 = typeV;
			Rezult.v = num3;
		}
		return Rezult;
	}
	friend std::ostream& operator<<(std::ostream& out, const Vec& tmp)
	{
		out << tmp.v <<" "<< tmp.typeV << endl;
		return out;
	}
};
