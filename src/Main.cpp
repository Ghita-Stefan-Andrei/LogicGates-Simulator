#include<vector>
#include<iostream>
#include"LogicGates.h"
#include<string>
#include<set>
#include<sstream>
#include<climits>
using namespace std;
int main()
{
	vector<InputGate>inputs;
	set<int>inputSize;
	vector<int>outputs;
	vector<Gate*>gates;
	int gateId = 1;
	int inputId = 0;
	while (1)
	{
		string Command;
		cin >> Command;
		if (Command == "CreateModel")
		{
			if (gates.size() != 0)
			{
				cout << " A model already exist" << endl;
				cout << "-----------------------------" << endl;
			}
			else
			{
				cout << "Creating Model:\n";
				string command;
				while (cin >> command)
				{
					if (command == "add")
					{
						string gateToAdd;
						cin >> gateToAdd;
						int pin1 = INT_MIN, pin2 = INT_MIN;
						if (gateToAdd == "and")
						{
							stringstream ss;
							string pins;
							getline(cin, pins);
							ss << pins;
							ss >> pin1 >> pin2;
							if (ss.peek() == 32)
							{
								cout << " To many pins" << endl;
							}
							else if (pin2 == INT_MIN)
							{
								cout << " Not enough pins" << endl;
							}
							else
							{
								if (pin1 < 0)
								{
									inputSize.insert(pin1);
								}
								if (pin2 < 0)
								{
									inputSize.insert(pin2);
								}
								gates.push_back(new AND_Gate(pin1, pin2, gateId++));
							}
						}
						else if (gateToAdd == "or")
						{
							stringstream ss;
							string pins;
							getline(cin, pins);
							ss << pins;
							ss >> pin1 >> pin2;
							if (ss.peek() == 32)
							{
								cout << " To many pins" << endl;
							}
							else if (pin2 == INT_MIN)
							{
								cout << " Not enough pins" << endl;
							}
							else
							{
								if (pin1 < 0)
								{
									inputSize.insert(pin1);
								}
								if (pin2 < 0)
								{
									inputSize.insert(pin2);
								}
								gates.push_back(new OR_Gate(pin1, pin2, gateId++));
							}
						}
						else if (gateToAdd == "nor")
						{
							stringstream ss;
							string pins;
							getline(cin, pins);
							ss << pins;
							ss >> pin1 >> pin2;
							if (ss.peek() == 32)
							{
								cout << " To many pins" << endl;
							}
							else if (pin2 == INT_MIN)
							{
								cout << " Not enough pins" << endl;
							}
							else
							{
								if (pin1 < 0)
								{
									inputSize.insert(pin1);
								}
								if (pin2 < 0)
								{
									inputSize.insert(pin2);
								}
								gates.push_back(new NOR_Gate(pin1, pin2, gateId++));
							}
						}
						else if (gateToAdd == "nand")
						{
							stringstream ss;
							string pins;
							getline(cin, pins);
							ss << pins;
							ss >> pin1 >> pin2;
							if (ss.peek() == 32)
							{
								cout << " To many pins" << endl;
							}
							else if (pin2 == INT_MIN)
							{
								cout << " Not enough pins" << endl;
							}
							else
							{
								if (pin1 < 0)
								{
									inputSize.insert(pin1);
								}
								if (pin2 < 0)
								{
									inputSize.insert(pin2);
								}
								gates.push_back(new NAND_Gate(pin1, pin2, gateId++));
							}
						}
						else if (gateToAdd == "xor")
						{
							stringstream ss;
							string pins;
							getline(cin, pins);
							ss << pins;
							ss >> pin1 >> pin2;
							if (ss.peek() == 32)
							{
								cout << " To many pins" << endl;
							}
							else if (pin2 == INT_MIN)
							{
								cout << " Not enough pins" << endl;
							}
							else
							{
								if (pin1 < 0)
								{
									inputSize.insert(pin1);
								}
								if (pin2 < 0)
								{
									inputSize.insert(pin2);
								}
								gates.push_back(new XOR_Gate(pin1, pin2, gateId++));
							}
						}
						else if (gateToAdd == "xnor")
						{
							stringstream ss;
							string pins;
							getline(cin, pins);
							ss << pins;
							ss >> pin1 >> pin2;
							if (ss.peek() == 32)
							{
								cout << " To many pins" << endl;
							}
							else if (pin2 == INT_MIN)
							{
								cout << " Not enough pins" << endl;
							}
							else
							{
								if (pin1 < 0)
								{
									inputSize.insert(pin1);
								}
								if (pin2 < 0)
								{
									inputSize.insert(pin2);
								}
								gates.push_back(new XNOR_Gate(pin1, pin2, gateId++));
							}
						}
						else if (gateToAdd == "not")
						{
							stringstream ss;
							string pins;
							getline(cin, pins);
							ss << pins;
							ss >> pin1;
							if (ss.peek() == 32)
							{
								cout << " To many pins" << endl;
							}
							else if (pin1 == INT_MIN)
							{
								cout << " Not enough pins" << endl;
							}
							else
							{
								if (pin1 < 0)
								{
									inputSize.insert(pin1);
								}
								gates.push_back(new NOT_Gate(pin1, gateId++));
							}
						}
						else
						{
							cout << gateToAdd << " is not a valid gate name" << endl;
							cout << " The valid gates are: and, or, nand, nor, xor, xnor, not." << endl;
							cout << " Check <help> command for more help" << endl;
						}
					}
					else if (command == "stop")
					{
						cout << "Creating Model stopped.\n";
						cout << "-----------------------------" << endl;
						break;
					}
					else
					{
						cout << command << " is not a valid command" << endl;
						cout << " The valid commands are: add <gate> <pin1> <pin2> (not gate has only pin1), stop" << endl;
						cout << " Check <help> command for more help" << endl;
					}
				}
			}
		}
		else if (Command == "SetInputs")
		{
			cout << "Setting Inputs:\n";
			inputId = 0;
			inputs.clear();
			for (int i = 0; i < inputSize.size(); i++)
			{
				int input;
				cin >> input;
				inputs.push_back(input);
			}
			cout << "Inputs set\n";
			cout << "-----------------------------" << endl;
		}
		else if (Command == "SetOutputs")
		{
			cout << "Setting OutPuts:\n";
			outputs.clear();
			int nr;
			cin >> nr;
			for (int i = 0; i < nr; i++)
			{
				int output;
				cin >> output;
				outputs.push_back(output);
			}
			cout << "OutPuts set\n";
			cout << "-----------------------------" << endl;
		}
		else if (Command == "RunModel")
		{
			if (gates.size() == 0)
			{
				cout << " Error 404: Model not found" << endl;
				cout << " Check <help> command for more help" << endl;
			}
			else
			{
				if (inputs.size() == 0)
				{
					cout << " There are no Inputs" << endl;
					cout << " Check <help> command for more help" << endl;
				}
				else
				{
					if (outputs.size() == 0)
					{
						cout << " There are no Outputs" << endl;
						cout << " Check <help> command for more help" << endl;
					}
					else
					{
						cout << "Outputs:  ";
						for (auto& gate : gates)
						{
							if (gate->type)
							{
								if (gate->GetInputID1() < 0)
								{
									gate->SetInput1(inputs[-gate->GetInputID1() - 1]);
								}
								else
								{
									gate->SetInput1(gates[gate->GetInputID1() - 1]);
								}
								if (gate->GetInputID2() < 0)
								{
									gate->SetInput2(inputs[-gate->GetInputID2() - 1]);
								}
								else
								{
									gate->SetInput2(gates[gate->GetInputID2() - 1]);
								}
							}
							else
							{
								if (gate->GetInputID1() < 0)
								{
									gate->SetInput1(inputs[-gate->GetInputID1() - 1]);
								}
								else
								{
									gate->SetInput1(gates[gate->GetInputID1() - 1]);
								}
							}
							gate->CalcOutPut();
						}
						for (auto& gate : gates)
						{
							if (gate->type)
							{
								if (gate->GetInputID1() < 0)
								{
									gate->SetInput1(inputs[-gate->GetInputID1() - 1]);
								}
								else
								{
									gate->SetInput1(gates[gate->GetInputID1() - 1]);
								}
								if (gate->GetInputID2() < 0)
								{
									gate->SetInput2(inputs[-gate->GetInputID2() - 1]);
								}
								else
								{
									gate->SetInput2(gates[gate->GetInputID2() - 1]);
								}
							}
							else
							{
								if (gate->GetInputID1() < 0)
								{
									gate->SetInput1(inputs[-gate->GetInputID1() - 1]);
								}
								else
								{
									gate->SetInput1(gates[gate->GetInputID1() - 1]);
								}
							}
							gate->CalcOutPut();
						}
						for (auto i : outputs)
						{
							cout << gates[i - 1]->GetValue() << " ";
						}
						cout << "\n-----------------------------" << endl;
					}
				}
			}
		}
		else if (Command == "StopModel")
		{
			break;
		}
		else 
		if (Command == "help")
		{
			cout << " Command list:" << endl;
			cout << "        CreateModel:                    || Start the creating proces to build a schematic " << endl;
			cout << "            add <gate> <pin1> <pin2>    || Add a gate into the schematic the pins means which gate output is conected to the gate you are adding (not gate has only pin 1) " << endl;
			cout << "            stop                        || Stops the create proces " << endl;
			cout << "        SetInputs:                      || Set the value for each input (<input value> <input value> and so on) " << endl;
			cout << "        SetOutputs:                     || Set which gates will be outputs <number of outputs> <gate id> <gate id> and so on " << endl;
			cout << "        RunModel:                       || Will start computing the answare " << endl;
			cout << "        StopModel:                      || will stop the program " << endl;
			cout << endl;
			cout << " Details: " << endl;
			cout << "	every gate will get an id starting from 1 the first gate you add will be gate 1 the second will be gate 2 and so on" << endl;
			cout << "	if a pin is conected to an input his id will be 0" << endl;
			cout << "	you can set the inputs and outputs multiple times and also run it every time you need, but u can create one model and u are unable to change it after" << endl;
			cout << "   if a pin is positive it means it is connected to a gate output if it is negative it means it is conected to |<pin id>|" << endl;
			cout << endl;
			cout << " Exemple of a model with an and gate connected to 2 inputs, a not gate connected to the and gate and the out put is the value of the not gate" << endl;
			cout << "	CreateModel    || start the creation of the model" << endl;
			cout << "	add and -1 -2  || adds a and gate with bot pins conected to inputs id = 1" << endl;
			cout << "	add not 1      || adds a not gate connected to the and gate by the id 1 not gate id = 2" << endl;
			cout << "	stop           || stops the creating of the model" << endl;
			cout << "	SetInputs      || starts the input adding menu" << endl;
			cout << "	1 1            || 1,1- value of inputs" << endl;
			cout << "	SetOutputs     || start the output setting menu" << endl;
			cout << "	1 2            || 1-the number of outputs 2-the id of the gate that will tell the output" << endl;
			cout << "	RunModel       || will run the model" << endl;
			cout << "	StopModel      || will close the program" << endl;
			cout << endl;
			cout << "   Author: Ghita Stefan-Andrei" << endl;
		}
		else
		{
			cout << Command << " is not a valid command\n";
			cout << " The valid commands are: CreateModel, SetInputs, SetOutputs, RunModel, StopModel" << endl;
			cout << " Check <help> command for more help" << endl;
		}
	}
	for (auto& i : gates)
	{
		delete i;
	}
}