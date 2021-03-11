#include "NOR_Gate.h"
NOR_Gate::NOR_Gate(int ID1, int ID2, int id) :Gate(1)
{
	this->InputID1 = ID1;
	this->InputID2 = ID2;
	this->ThisId = id;
}
void NOR_Gate::SetInput2(Gate* gate)
{
	this->Input2 = gate->OutPutValue;
}

void NOR_Gate::SetInput2(InputGate gate)
{
	this->Input2 = gate.GetValue();
}

void NOR_Gate::CalcOutPut()
{
	this->OutPutValue = !(this->Input1 || this->Input2);
}

int NOR_Gate::GetInputID2()
{
	return this->InputID2;
}

