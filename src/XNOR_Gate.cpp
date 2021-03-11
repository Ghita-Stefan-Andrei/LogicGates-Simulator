#include "XNOR_Gate.h"
XNOR_Gate::XNOR_Gate(int ID1, int ID2, int id) :Gate(1)
{
	this->InputID1 = ID1;
	this->InputID2 = ID2;
	this->ThisId = id;
}
void XNOR_Gate::SetInput2(Gate* gate)
{
	this->Input2 = gate->OutPutValue;
}

void XNOR_Gate::SetInput2(InputGate gate)
{
	this->Input2 = gate.GetValue();
}

void XNOR_Gate::CalcOutPut()
{
	this->OutPutValue = !(this->Input1 ^ this->Input2);
}

int XNOR_Gate::GetInputID2()
{
	return this->InputID2;
}
