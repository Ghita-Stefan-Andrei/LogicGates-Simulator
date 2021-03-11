#pragma once
#include"InputGate.h"
class Gate
{
public:
	bool Input1;
	int ThisId;
	int InputID1;
	bool OutPutValue;
	bool type;
public:
	Gate(bool type);
	int GetID();
	bool GetValue();
	void SetInput1(Gate* gate);
	void SetInput1(InputGate gate);
	virtual void SetInput2(Gate* gate);
	virtual void SetInput2(InputGate gate);
	int GetInputID1();
	virtual int GetInputID2();
	virtual void SetValue(bool val);
	virtual void CalcOutPut();
};

