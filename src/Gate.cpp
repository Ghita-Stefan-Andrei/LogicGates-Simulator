#include "Gate.h"
Gate::Gate(bool type)
{
	this->type = type;
}
int Gate::GetID()
{
	return this->ThisId;
}
bool Gate::GetValue()
{
	return OutPutValue;
}
void Gate::SetInput1(Gate* gate)
{
	this->Input1 = gate->OutPutValue;
}
void Gate::SetInput1(InputGate gate)
{
	this->Input1 = gate.GetValue();
}
void Gate::SetInput2(Gate* gate)
{
}
void Gate::SetInput2(InputGate gate)
{
}
int Gate::GetInputID1()
{
	return this->InputID1;
}

int Gate::GetInputID2()
{
	return 0;
}

void Gate::SetValue(bool val)
{
}

void Gate::CalcOutPut()
{
}
