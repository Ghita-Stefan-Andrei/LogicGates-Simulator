#pragma once
#include "Gate.h"
class NOR_Gate : public Gate
{
private:
	bool Input2;
	int InputID2;
public:
	NOR_Gate(int ID1, int ID2, int id);
	void SetInput2(Gate* gate) override;
	void SetInput2(InputGate gate) override;
	void CalcOutPut();
	int GetInputID2() override;
};

