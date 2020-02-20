#include <iostream> 

#define MAX_UINT 4294967295

typedef unsigned int uint;
typedef long long ll;



class LongNumber
{
private:
	int high_part;
	uint low_part;
	bool sign;

public:
	LongNumber()
	{
		high_part = 0;
		low_part = 0;
		sign = false;
	}

	LongNumber(const LongNumber& num)
	{
		high_part = num.high_part;
		low_part = num.low_part;
		sign = num.sign;
	}

	LongNumber(const ll& num)
	{
		low_part = num & 0xffffffff; //Побитовое операция И 
		high_part = num / 0x100000000;
		if (num < 0) //Проверка на знак числа 
			sign = true;
	}

	LongNumber Add(const LongNumber& num)
	{
		LongNumber Result;
		Result.low_part = (low_part + num.low_part);
		if (MAX_UINT - low_part < num.low_part)
			Result.high_part++;
		Result.high_part = high_part + num.high_part;
		return Result;
	}

	LongNumber Res(const LongNumber& num)
	{
		LongNumber Result;
		int flag = 0;
		if (low_part < num.low_part)
			flag = (low_part - num.low_part + 0x100000000) / 0x100000000;
		Result.low_part = (low_part - num.low_part + 0x100000000) & 0xffffffff;
		Result.high_part = high_part - num.high_part - flag;

		return Result;
	}

	LongNumber Div(const LongNumber& num)
	{
		LongNumber Result;
		Result.high_part = (((high_part * 0x100000000 + low_part) / (num.high_part * 0x100000000 + num.low_part))) / 0x100000000;
		Result.low_part = (((high_part * 0x100000000 + low_part) / (num.high_part * 0x100000000 + num.low_part))) & 0xffffffff;
		return Result;
	}

	LongNumber Mul(const LongNumber& num)
	{
		LongNumber Result, _num(num), _num1(num);
		int len_num = 0;
		while (_num1.high_part != 0)
		{
			len_num++;
			_num1.high_part /= 10;
		}
		while (_num1.low_part != 0)
		{
			len_num++;
			_num1.low_part /= 10;
		}

		int x = _num.low_part % 10;
		//if (!x && (_num.low_part || _num.high_part)) x = 10; 
		for (int i = 1; i < len_num; i++)
		{
			int flag = low_part * x / 0x100000000;
			Result.low_part = (Result.low_part + low_part * x) & 0xffffffff; //Просчитать для случая x -> (x + 10) 
			Result.high_part = (Result.high_part + high_part * x + flag) & 0xffffffff;

			x = _num.high_part % 10;
			_num.low_part = _num.low_part / 10 + (uint)1e9 * x;
			x = _num.low_part % 10;
			//if (!x && (_num.low_part || _num.high_part))x = 10; 

			flag = Result.low_part * 10 / 0x100000000;
			Result.low_part = (Result.low_part * 10) & 0xffffffff; //Если получится, этот код удалить 
			Result.high_part = (Result.high_part * 10 + flag) & 0xffffffff;
		}
		int flag = low_part * x / 0x100000000;
		Result.low_part = (Result.low_part + low_part * x) & 0xffffffff;
		Result.high_part = (Result.high_part + high_part * x + flag) & 0xffffffff;

		return Result;
	}

	void get(void)
	{
		std::cout << (high_part * 0x100000000 + low_part) << std::endl;
	}

	LongNumber operator+ (const LongNumber& num)
	{
		if ((this > 0) && (num > 0))
			LongNumber result(this->Add(num));
		if ((high_part > 0) && ());


	}
};

int main()
{

	LongNumber x(111111111111), y(222222222222); //4 294 967 296 
	x.get();
	y.get();
	LongNumber z = y.Add(x);
	z.get();

	system("pause");
}