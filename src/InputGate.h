#pragma once
class InputGate 
{
	bool OutPutValue;
public:
	InputGate(bool val)
	{
		this->OutPutValue = val;
	}
	bool GetValue()
	{
		return this->OutPutValue;
	}
};