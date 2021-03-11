#include "NOT_Gate.h"
NOT_Gate::NOT_Gate(int ID1, int id) :Gate(0)
{
	this->InputID1 = ID1;
	this->ThisId = id;
}
void NOT_Gate::CalcOutPut()
{
	this->OutPutValue = !this->Input1;
}
