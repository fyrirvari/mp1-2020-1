#pragma once
class DM
{
private:
	int n;
	double *arr;
public:
	DM();
	DM(int q);
	DM(DM &x);
	~DM();

	DM& operator=(DM &x);

	void set_n(int f);
	int get_n();

	void set_element(int x, double y);
	double get_element(int x);

	double get_min();
	int Test();

	DM Select();
};

