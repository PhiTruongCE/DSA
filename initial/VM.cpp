#include "VM.h"

void VM::exec(){
	for(int i = 0; i < CodeLoadedIndex ; i++){
            Instruction ins = codeMemory[IP];
            if(ins.code.compare("Move") == 0) this->Move(ins.op1, ins.op2);
            else if (ins.code.compare("Output") == 0) this->Output(ins.op1);
			else if (ins.code.compare("Add") == 0) this->Add(ins.op1,ins.op2);
			else if (ins.code.compare("Minus") == 0) this->Minus(ins.op1,ins.op2);
			else if (ins.code.compare("Mul") == 0) this->Mul(ins.op1,ins.op2);
			else if (ins.code.compare("Div") == 0) this->Div(ins.op1,ins.op2);
			else if (ins.code.compare("CmpEQ") == 0) this->CmpEQ(ins.op1,ins.op2);
			else if (ins.code.compare("CmpNE") == 0) this->CmpNE(ins.op1,ins.op2);
			else if (ins.code.compare("CmpLT") == 0) this->CmpLT(ins.op1,ins.op2);
			else if (ins.code.compare("CmpLE") == 0) this->CmpLE(ins.op1,ins.op2);
			else if (ins.code.compare("CmpGT") == 0) this->CmpGT(ins.op1,ins.op2);
			else if (ins.code.compare("CmpGE") == 0) this->CmpGE(ins.op1,ins.op2);
			else if (ins.code.compare("Not") == 0) this->Not(ins.op1);
			else if (ins.code.compare("And") == 0) this->And(ins.op1,ins.op2);
			else if (ins.code.compare("Or") == 0) this->Or(ins.op1,ins.op2);
			else if (ins.code.compare("Load") == 0) this->Load(ins.op1,ins.op2);
			else if (ins.code.compare("Store") == 0) this->Store(ins.op1,ins.op2);
			else if (ins.code.compare("Jump") == 0) this->Jump(ins.op1);
			else if (ins.code.compare("JumpIf") == 0) this->JumpIf(ins.op1,ins.op2);
			else if (ins.code.compare("Call") == 0) this->Call(ins.op1);
			else if (ins.code.compare("Return") == 0) this->Return();
			else if (ins.code.compare("Halt") == 0) this->Halt();
			else if (ins.code.compare("Input") == 0) this->Input(ins.op1);
			else throw InvalidInstruction(IP);
			IP++;
			if(i!=IP) i = IP;
        }
}

int VM::Text(string s){
	int t = 0;
	for(int i = 0; i < (int)s.length(); i++){
		if(s[i] == ' ' || s[i] == ','){
			t++;
		}
	}
	if(t == 1) return 1;
	else if(t == 3) return 2;
	else if(t == 0) return 3;
	else return 4;
}

void VM::Control(string instruction, int address){
	int t = Text(instruction);
	if (instruction[0] == ' ') throw InvalidInstruction(address);
 	if (instruction[instruction.length() - 1] == ' ') throw InvalidInstruction(address);
        
        vector<string> ins;

        Instruction Ins;
        
        char * cstr = new char [instruction.length()+1];
        strcpy (cstr, instruction.c_str());
        char * pch;
        pch = strtok(cstr," ,");
        
        while (pch != NULL)
        {
            ins.push_back(string(pch));
            pch = strtok(NULL, " ,");
        }
        if (ins[0] == "Move") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "Move";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
        else if (ins[0] == "Output")
        {
			if(t != 1) throw InvalidInstruction(address);
            Ins.code = "Output";
            Ins.op1 = ins[1];
        }
        else if (ins[0] == "Add") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "Add";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
		else if (ins[0] == "Halt"){
			if(t != 3) throw InvalidInstruction(address);
			Ins.code = "Halt";
		}
		else if (ins[0] == "Minus") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "Minus";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
		else if (ins[0] == "Mul") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "Mul";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
		else if (ins[0] == "Div") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "Div";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
		else if (ins[0] == "CmpEQ") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "CmpEQ";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
		else if (ins[0] == "CmpNE") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "CmpNE";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
		else if (ins[0] == "CmpLT") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "CmpLT";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
		else if (ins[0] == "CmpLE") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "CmpLE";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
		else if (ins[0] == "CmpGT") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "CmpGT";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
		else if (ins[0] == "CmpGE") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "CmpGE";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
		else if (ins[0] == "Not") {
			if(t != 1) throw InvalidInstruction(address);
            Ins.code = "Not";
            Ins.op1 = ins[1];
        }
		else if (ins[0] == "And") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "And";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
		else if (ins[0] == "Or") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "Or";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
		else if (ins[0] == "Load") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "Load";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
		else if (ins[0] == "Store") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "Store";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
		else if (ins[0] == "Jump") {
			if(t != 1) throw InvalidInstruction(address);
            Ins.code = "Jump";
            Ins.op1 = ins[1];
        }
		else if (ins[0] == "JumpIf") {
			if(t != 2) throw InvalidInstruction(address);
            Ins.code = "JumpIf";
            Ins.op1 = ins[1];
            Ins.op2 = ins[2];
        }
		else if (ins[0] == "Call") {
			if(t != 1) throw InvalidInstruction(address);
            Ins.code = "Call";
            Ins.op1 = ins[1];
        }
		else if(ins[0] == "Return"){
			if(t != 3) throw InvalidInstruction(address);
			Ins.code = "Return";
		}
		else if (ins[0] == "Input") {
			if(t != 1) throw InvalidInstruction(address);
            Ins.code = "Input";
            Ins.op1 = ins[1];
        }
        else throw InvalidInstruction(address);
        this->codeMemory[this->CodeLoadedIndex++] = Ins;
}

int VM::check(string s){ 
	if(s == "true" || s == "false") return 0; // bool
   else{
      int k =0;
      int t = 0;
      for (int i = 0; i < (int)s.length(); i++)
      {
         if(s[i] == '0' || s[i] == '1' ||s[i] == '2' ||s[i] == '3' ||s[i] == '4' ||s[i] == '5' ||s[i] == '6' ||s[i] == '7' ||s[i] == '8' ||s[i] == '9'){
            k++;
         }
         else if(s[i] == '.'){
            k = k+2;
            t++;
         }
         else if (i == (int)s.length() - 1 || s[i] == 'A')
         {
            k = k + 3;
         }
         else k = k + 4;
         
      }
      if(t <= 1){
         if(k == (int)s.length()){
            return 1; // integer
         }
         else if( k == (int)s.length() + 1) return 2; // float
         else if (k == (int)s.length() + 2) return 3; // address
         else return 4; // false
      }
      else return 4; // false
   }
}

bool VM::con2bool(string s){
   bool b = (s == "true");
   return b;
}

void VM::Add(string dest, string src){ // integer or float
	int destIdx = stoi(dest.substr(1)) - 1;
	if(src[0] == 'R'){
		int srcIdx = stoi(src.substr(1)) - 1;
		if(Reg[srcIdx].type == INT && Reg[destIdx].type == INT){
			Reg[destIdx].data1 += Reg[srcIdx].data1;
		}
		else if(Reg[destIdx].type == FLOAT && Reg[srcIdx].type == FLOAT){
			Reg[destIdx].data2 += Reg[srcIdx].data2;
		}
		else if(Reg[destIdx].type == FLOAT && Reg[srcIdx].type == INT){
			Reg[destIdx].data2 += Reg[srcIdx].data1;
		}
		else if(Reg[destIdx].type == INT && Reg[srcIdx].type == FLOAT){
			Reg[destIdx].data2 = Reg[destIdx].data1 + Reg[srcIdx].data2;
			Reg[destIdx].data1 = 0;
			Reg[destIdx].type = FLOAT;
		}
		else throw TypeMismatch(IP);
	}
	else{
		int t = check(src);
		if(t == 1){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data1 += stoi(src);
			}
			else if (Reg[destIdx].type == FLOAT){
				Reg[destIdx].data2 += stoi(src);
			}
			else throw TypeMismatch(IP);
		}
		else if(t == 2){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data2 = Reg[destIdx].data1 + stof(src);
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = FLOAT;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data2 += stof(src);
			}
			else throw TypeMismatch(IP);
		}
		else throw TypeMismatch(IP);
	}
}

void VM::Minus(string dest, string src){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(src[0] == 'R'){
		int srcIdx = stoi(src.substr(1)) - 1;
		if(Reg[srcIdx].type == INT && Reg[destIdx].type == INT){
			Reg[destIdx].data1 -= Reg[srcIdx].data1;
		}
		else if(Reg[destIdx].type == FLOAT && Reg[srcIdx].type == FLOAT){
			Reg[destIdx].data2 -= Reg[srcIdx].data2;
		}
		else if(Reg[destIdx].type == FLOAT && Reg[srcIdx].type == INT){
			Reg[destIdx].data2 -= Reg[srcIdx].data1;
		}
		else if(Reg[destIdx].type == INT && Reg[srcIdx].type == FLOAT){
			Reg[destIdx].data2 = Reg[destIdx].data1 - Reg[srcIdx].data2;
			Reg[destIdx].data1 = 0;
			Reg[destIdx].type = FLOAT;
		}
		else throw TypeMismatch(IP);
	}
	else{
		int t = check(src);
		if(t == 1){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data1 -= stoi(src);
			}
			else if (Reg[destIdx].type == FLOAT){
				Reg[destIdx].data2 -= stoi(src);
			}
			else throw TypeMismatch(IP);
		}
		else if(t == 2){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data2 = Reg[destIdx].data1 - stof(src);
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = FLOAT;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data2 -= stof(src);
			}
			else throw TypeMismatch(IP);
		}
		else throw TypeMismatch(IP);
	}
}

void VM::Mul(string dest, string src){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(src[0] == 'R'){
		int srcIdx = stoi(src.substr(1)) - 1;
		if(Reg[srcIdx].type == INT && Reg[destIdx].type == INT){
			Reg[destIdx].data1 *= Reg[srcIdx].data1;
		}
		else if(Reg[destIdx].type == FLOAT && Reg[srcIdx].type == FLOAT){
			Reg[destIdx].data2 *= Reg[srcIdx].data2;
		}
		else if(Reg[destIdx].type == FLOAT && Reg[srcIdx].type == INT){
			Reg[destIdx].data2 *= Reg[srcIdx].data1;
		}
		else if(Reg[destIdx].type == INT && Reg[srcIdx].type == FLOAT){
			Reg[destIdx].data2 = Reg[destIdx].data1 * Reg[srcIdx].data2;
			Reg[destIdx].data1 = 0;
			Reg[destIdx].type = FLOAT;
		}
		else throw TypeMismatch(IP);
	}
	else{
		int t = check(src);
		if(t == 1){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data1 *= stoi(src);
			}
			else if (Reg[destIdx].type == FLOAT){
				Reg[destIdx].data2 *= stoi(src);
			}
			else throw TypeMismatch(IP);
		}
		else if(t == 2){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data2 = Reg[destIdx].data1 * stof(src);
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = FLOAT;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data2 *= stof(src);
			}
			else throw TypeMismatch(IP);
		}
		else throw TypeMismatch(IP);
	}
}

void VM::Div(string dest, string src){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(src[0] == 'R'){
		int srcIdx = stoi(src.substr(1)) - 1;
		if(Reg[srcIdx].type == INT && Reg[destIdx].type == INT){
			if(Reg[srcIdx].data1 == 0) throw DivideByZero(IP);
			Reg[destIdx].data1 /= Reg[srcIdx].data1;
		}
		else if(Reg[destIdx].type == FLOAT && Reg[srcIdx].type == FLOAT){
			if(Reg[srcIdx].data2 == 0) throw DivideByZero(IP);
			Reg[destIdx].data2 /= Reg[srcIdx].data2;
		}
		else if(Reg[destIdx].type == FLOAT && Reg[srcIdx].type == INT){
			if(Reg[srcIdx].data1 == 0) throw DivideByZero(IP);
			Reg[destIdx].data2 /= Reg[srcIdx].data1;
		}
		else if(Reg[destIdx].type == INT && Reg[srcIdx].type == FLOAT){
			if(Reg[srcIdx].data2 == 0) throw DivideByZero(IP);
			Reg[destIdx].data2 = Reg[destIdx].data1 / Reg[srcIdx].data2;
			Reg[destIdx].data1 = 0;
			Reg[destIdx].type = FLOAT;
		}
		else throw TypeMismatch(IP);
	}
	else{
		int t = check(src);
		if(t == 1){
			if(stoi(src) == 0) throw DivideByZero(IP);
			else{
				if(Reg[destIdx].type == INT){
					Reg[destIdx].data1 /= stoi(src);
				}
				else if (Reg[destIdx].type == FLOAT){
					Reg[destIdx].data2 /= stoi(src);
				}
				else throw TypeMismatch(IP);
			}
		}
		else if(t == 2){
			if(stof(src) == 0) throw DivideByZero(IP);
			else{
				if(Reg[destIdx].type == INT){
					Reg[destIdx].data2 = Reg[destIdx].data1 / stof(src);
					Reg[destIdx].data1 = 0;
					Reg[destIdx].type = FLOAT;
				}
				else if(Reg[destIdx].type == FLOAT){
					Reg[destIdx].data2 /= stof(src);
				}
				else throw TypeMismatch(IP);
			}
		}
		else throw TypeMismatch(IP);
	}
}

void VM::CmpEQ(string dest, string src){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(src[0] == 'R'){
		int srcIdx = stoi(src.substr(1)) - 1;
		if(Reg[destIdx].type == BOOLEN && Reg[srcIdx].type == BOOLEN){		// check dest & src is boolen
			if(Reg[destIdx].data3 == Reg[srcIdx].data3) {
				Reg[destIdx].data3 = true;			
			}
			else {
				Reg[destIdx].data3 = false;
			}
		}
		else if(Reg[destIdx].type == BOOLEN && Reg[srcIdx].type != BOOLEN) throw TypeMismatch(IP);
		else if(Reg[destIdx].type != BOOLEN && Reg[srcIdx].type == BOOLEN) throw TypeMismatch(IP);
		else {
			if(Reg[destIdx].type == INT){								//check dest is int
				if(Reg[srcIdx].type == INT){
					if(Reg[destIdx].data1 == Reg[srcIdx].data1){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else if (Reg[srcIdx].type == FLOAT){
					if(Reg[destIdx].data1 == Reg[srcIdx].data2){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else throw TypeMismatch(IP);
			}
			else if(Reg[destIdx].type == FLOAT){							//check dest is float
				if(Reg[srcIdx].type == INT){
					if(Reg[destIdx].data2 == Reg[srcIdx].data1){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else if (Reg[srcIdx].type == FLOAT){
					if(Reg[destIdx].data2 == Reg[srcIdx].data2){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else throw TypeMismatch(IP);
			}
			else throw TypeMismatch(IP);
		}
	}
	else {
		int t = check(src);
		if(t == 0){
			if(Reg[destIdx].type == BOOLEN){
				Reg[destIdx].data3 = (Reg[destIdx].data3 == con2bool(src));
			}
			else throw TypeMismatch(IP);
		}
		else if(t == 1){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data3 = (Reg[destIdx].data1 == stoi(src));
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data3 = (Reg[destIdx].data2 == stoi(src));
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else throw TypeMismatch(IP);
		}
		else if(t == 2){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data3 = (Reg[destIdx].data1 == stof(src));
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data3 = (Reg[destIdx].data2 == stof(src));
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else throw TypeMismatch(IP);
		}
		else throw TypeMismatch(IP);
	}
}

void VM::CmpNE(string dest, string src){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(src[0] == 'R'){
		int srcIdx = stoi(src.substr(1)) - 1;
		if(Reg[destIdx].type == BOOLEN && Reg[srcIdx].type == BOOLEN){		// check dest & src is boolen
			if(Reg[destIdx].data3 != Reg[srcIdx].data3) {
				Reg[destIdx].data3 = true;			
			}
			else {
				Reg[destIdx].data3 = false;
			}
		}
		else if(Reg[destIdx].type == BOOLEN && Reg[srcIdx].type != BOOLEN) throw TypeMismatch(IP);
		else if(Reg[destIdx].type != BOOLEN && Reg[srcIdx].type == BOOLEN) throw TypeMismatch(IP);
		else {
			if(Reg[destIdx].type == INT){								//check dest is int
				if(Reg[srcIdx].type == INT){
					if(Reg[destIdx].data1 != Reg[srcIdx].data1){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else if (Reg[srcIdx].type == FLOAT){
					if(Reg[destIdx].data1 != Reg[srcIdx].data2){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else throw TypeMismatch(IP);
			}
			else if(Reg[destIdx].type == FLOAT){							//check dest is float
				if(Reg[srcIdx].type == INT){
					if(Reg[destIdx].data2 != Reg[srcIdx].data1){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else if (Reg[srcIdx].type == FLOAT){
					if(Reg[destIdx].data2 != Reg[srcIdx].data2){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else throw TypeMismatch(IP);
			}
			else throw TypeMismatch(IP);
		}
	}
	else {
		int t = check(src);
		if(t == 0){
			if(Reg[destIdx].type == BOOLEN){
				Reg[destIdx].data3 = (Reg[destIdx].data3 != con2bool(src));
			}
			else throw TypeMismatch(IP);
		}
		else if(t == 1){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data3 = (Reg[destIdx].data1 != stoi(src));
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data3 = (Reg[destIdx].data2 != stoi(src));
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else throw TypeMismatch(IP);
		}
		else if(t == 2){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data3 = (Reg[destIdx].data1 != stof(src));
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data3 = (Reg[destIdx].data2 != stof(src));
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else throw TypeMismatch(IP);
		}
		else throw TypeMismatch(IP);
	}
}

void VM::CmpLT(string dest, string src){
		int destIdx = stoi(dest.substr(1)) - 1;
	if(src[0] == 'R'){
		int srcIdx = stoi(src.substr(1)) - 1;
		if(Reg[destIdx].type == BOOLEN && Reg[srcIdx].type == BOOLEN){		// check dest & src is boolen
			if(Reg[destIdx].data3 < Reg[srcIdx].data3) {
				Reg[destIdx].data3 = true;			
			}
			else {
				Reg[destIdx].data3 = false;
			}
		}
		else if(Reg[destIdx].type == BOOLEN && Reg[srcIdx].type != BOOLEN) throw TypeMismatch(IP);
		else if(Reg[destIdx].type != BOOLEN && Reg[srcIdx].type == BOOLEN) throw TypeMismatch(IP);
		else {
			if(Reg[destIdx].type == INT){								//check dest is int
				if(Reg[srcIdx].type == INT){
					if(Reg[destIdx].data1 < Reg[srcIdx].data1){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else if (Reg[srcIdx].type == FLOAT){
					if(Reg[destIdx].data1 < Reg[srcIdx].data2){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else throw TypeMismatch(IP);
			}
			else if(Reg[destIdx].type == FLOAT){							//check dest is float
				if(Reg[srcIdx].type == INT){
					if(Reg[destIdx].data2 < Reg[srcIdx].data1){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else if (Reg[srcIdx].type == FLOAT){
					if(Reg[destIdx].data2 < Reg[srcIdx].data2){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else throw TypeMismatch(IP);
			}
			else throw TypeMismatch(IP);
		}
	}
	else {
		int t = check(src);
		if(t == 0){
			if(Reg[destIdx].type == BOOLEN){
				Reg[destIdx].data3 = (Reg[destIdx].data3 < con2bool(src));
			}
			else throw TypeMismatch(IP);
		}
		else if(t == 1){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data3 = (Reg[destIdx].data1 < stoi(src));
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data3 = (Reg[destIdx].data2 < stoi(src));
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else throw TypeMismatch(IP);
		}
		else if(t == 2){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data3 = (Reg[destIdx].data1 < stof(src));
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data3 = (Reg[destIdx].data2 < stof(src));
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else throw TypeMismatch(IP);
		}
		else throw TypeMismatch(IP);
	}
}

void VM::CmpLE(string dest, string src){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(src[0] == 'R'){
		int srcIdx = stoi(src.substr(1)) - 1;
		if(Reg[destIdx].type == BOOLEN && Reg[srcIdx].type == BOOLEN){		// check dest & src is boolen
			if(Reg[destIdx].data3 <= Reg[srcIdx].data3) {
				Reg[destIdx].data3 = true;			
			}
			else {
				Reg[destIdx].data3 = false;
			}
		}
		else if(Reg[destIdx].type == BOOLEN && Reg[srcIdx].type != BOOLEN) throw TypeMismatch(IP);
		else if(Reg[destIdx].type != BOOLEN && Reg[srcIdx].type == BOOLEN) throw TypeMismatch(IP);
		else {
			if(Reg[destIdx].type == INT){								//check dest is int
				if(Reg[srcIdx].type == INT){
					if(Reg[destIdx].data1 <= Reg[srcIdx].data1){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else if (Reg[srcIdx].type == FLOAT){
					if(Reg[destIdx].data1 <= Reg[srcIdx].data2){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else throw TypeMismatch(IP);
			}
			else if(Reg[destIdx].type == FLOAT){							//check dest is float
				if(Reg[srcIdx].type == INT){
					if(Reg[destIdx].data2 <= Reg[srcIdx].data1){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else if (Reg[srcIdx].type == FLOAT){
					if(Reg[destIdx].data2 <= Reg[srcIdx].data2){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else throw TypeMismatch(IP);
			}
			else throw TypeMismatch(IP);
		}
	}
	else {
		int t = check(src);
		if(t == 0){
			if(Reg[destIdx].type == BOOLEN){
				Reg[destIdx].data3 = (Reg[destIdx].data3 <= con2bool(src));
			}
			else throw TypeMismatch(IP);
		}
		else if(t == 1){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data3 = (Reg[destIdx].data1 <= stoi(src));
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data3 = (Reg[destIdx].data2 <= stoi(src));
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else throw TypeMismatch(IP);
		}
		else if(t == 2){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data3 = (Reg[destIdx].data1 <= stof(src));
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data3 = (Reg[destIdx].data2 <= stof(src));
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else throw TypeMismatch(IP);
		}
		else throw TypeMismatch(IP);
	}
}

void VM::CmpGT(string dest, string src){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(src[0] == 'R'){
		int srcIdx = stoi(src.substr(1)) - 1;
		if(Reg[destIdx].type == BOOLEN && Reg[srcIdx].type == BOOLEN){		// check dest & src is boolen
			if(Reg[destIdx].data3 > Reg[srcIdx].data3) {
				Reg[destIdx].data3 = true;			
			}
			else {
				Reg[destIdx].data3 = false;
			}
		}
		else if(Reg[destIdx].type == BOOLEN && Reg[srcIdx].type != BOOLEN) throw TypeMismatch(IP);
		else if(Reg[destIdx].type != BOOLEN && Reg[srcIdx].type == BOOLEN) throw TypeMismatch(IP);
		else {
			if(Reg[destIdx].type == INT){								//check dest is int
				if(Reg[srcIdx].type == INT){
					if(Reg[destIdx].data1 > Reg[srcIdx].data1){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else if (Reg[srcIdx].type == FLOAT){
					if(Reg[destIdx].data1 > Reg[srcIdx].data2){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else throw TypeMismatch(IP);
			}
			else if(Reg[destIdx].type == FLOAT){							//check dest is float
				if(Reg[srcIdx].type == INT){
					if(Reg[destIdx].data2 > Reg[srcIdx].data1){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else if (Reg[srcIdx].type == FLOAT){
					if(Reg[destIdx].data2 > Reg[srcIdx].data2){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else throw TypeMismatch(IP);
			}
			else throw TypeMismatch(IP);
		}
	}
	else {
		int t = check(src);
		if(t == 0){
			if(Reg[destIdx].type == BOOLEN){
				Reg[destIdx].data3 = (Reg[destIdx].data3 > con2bool(src));
			}
			else throw TypeMismatch(IP);
		}
		else if(t == 1){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data3 = (Reg[destIdx].data1 > stoi(src));
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data3 = (Reg[destIdx].data2 > stoi(src));
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else throw TypeMismatch(IP);
		}
		else if(t == 2){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data3 = (Reg[destIdx].data1 > stof(src));
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data3 = (Reg[destIdx].data2 > stof(src));
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else throw TypeMismatch(IP);
		}
		else throw TypeMismatch(IP);
	}
}

void VM::CmpGE(string dest, string src){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(src[0] == 'R'){
		int srcIdx = stoi(src.substr(1)) - 1;
		if(Reg[destIdx].type == BOOLEN && Reg[srcIdx].type == BOOLEN){		// check dest & src is boolen
			if(Reg[destIdx].data3 >= Reg[srcIdx].data3) {
				Reg[destIdx].data3 = true;			
			}
			else {
				Reg[destIdx].data3 = false;
			}
		}
		else if(Reg[destIdx].type == BOOLEN && Reg[srcIdx].type != BOOLEN) throw TypeMismatch(IP);
		else if(Reg[destIdx].type != BOOLEN && Reg[srcIdx].type == BOOLEN) throw TypeMismatch(IP);
		else {
			if(Reg[destIdx].type == INT){								//check dest is int
				if(Reg[srcIdx].type == INT){
					if(Reg[destIdx].data1 >= Reg[srcIdx].data1){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else if (Reg[srcIdx].type == FLOAT){
					if(Reg[destIdx].data1 >= Reg[srcIdx].data2){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else throw TypeMismatch(IP);
			}
			else if(Reg[destIdx].type == FLOAT){							//check dest is float
				if(Reg[srcIdx].type == INT){
					if(Reg[destIdx].data2 >= Reg[srcIdx].data1){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else if (Reg[srcIdx].type == FLOAT){
					if(Reg[destIdx].data2 >= Reg[srcIdx].data2){
						Reg[destIdx].data3 = true;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else{
						Reg[destIdx].data3 = false;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].type = BOOLEN;
					} 
				}
				else throw TypeMismatch(IP);
			}
			else throw TypeMismatch(IP);
		}
	}
	else {
		int t = check(src);
		if(t == 0){
			if(Reg[destIdx].type == BOOLEN){
				Reg[destIdx].data3 = (Reg[destIdx].data3 >= con2bool(src));
			}
			else throw TypeMismatch(IP);
		}
		else if(t == 1){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data3 = (Reg[destIdx].data1 >= stoi(src));
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data3 = (Reg[destIdx].data2 >= stoi(src));
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else throw TypeMismatch(IP);
		}
		else if(t == 2){
			if(Reg[destIdx].type == INT){
				Reg[destIdx].data3 = (Reg[destIdx].data1 >= stof(src));
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data3 = (Reg[destIdx].data2 >= stof(src));
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else throw TypeMismatch(IP);
		}
		else throw TypeMismatch(IP);
	}
}

void VM::Not(string dest){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(Reg[destIdx].type == BOOLEN){
		Reg[destIdx].data3 = !Reg[destIdx].data3;
	}
	else throw TypeMismatch(IP);
}

void VM::And(string dest, string src){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(src[0] == 'R'){
		int srcIdx = stoi(src.substr(1)) - 1;
		if(Reg[destIdx].type == BOOLEN && Reg[srcIdx].type == BOOLEN){
			Reg[destIdx].data3 = Reg[destIdx].data3 && Reg[srcIdx].data3;
		}
		else throw TypeMismatch(IP);
	}
	else{
		if(Reg[destIdx].type == BOOLEN){
			Reg[destIdx].data3 = Reg[destIdx].data3 && con2bool(src);
		}
		else throw TypeMismatch(IP);
	}
}

void VM::Or(string dest, string src){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(src[0] == 'R'){
		int srcIdx = stoi(src.substr(1)) - 1;
		if(Reg[destIdx].type == BOOLEN && Reg[srcIdx].type == BOOLEN){
			Reg[destIdx].data3 = Reg[destIdx].data3 || Reg[srcIdx].data3;
		}
		else throw TypeMismatch(IP);
	}
	else{
		if(Reg[destIdx].type == BOOLEN){
			Reg[destIdx].data3 = Reg[destIdx].data3 || con2bool(src);
		}
		else throw TypeMismatch(IP);
	}
}

void VM::Move(string dest, string src){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(src[0]=='R'){
		int srcIdx = stoi(src.substr(1)) - 1;
		if (Reg[destIdx].type == NONE){
			if(Reg[srcIdx].type == INT){
				Reg[destIdx].data1 = Reg[srcIdx].data1;
				Reg[destIdx].type = INT;
			}
			else if(Reg[srcIdx].type == FLOAT){
				Reg[destIdx].data2 = Reg[srcIdx].data2;
				Reg[destIdx].type = FLOAT;
			}
			else if(Reg[srcIdx].type == BOOLEN){
				Reg[destIdx].data3 = Reg[srcIdx].data3;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[srcIdx].type == ADDRESS){
				Reg[destIdx].data4 = Reg[srcIdx].data4;
				Reg[destIdx].type = ADDRESS;
			}
		}
		else if(Reg[destIdx].type == INT){
			if(Reg[srcIdx].type == INT){
				Reg[destIdx].data1 = Reg[srcIdx].data1;
			}
			else if(Reg[srcIdx].type == FLOAT){
				Reg[destIdx].data2 = Reg[srcIdx].data2;
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = FLOAT;
			}
			else if(Reg[srcIdx].type == BOOLEN){
				Reg[destIdx].data3 = Reg[srcIdx].data3;
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[srcIdx].type == ADDRESS){
				Reg[destIdx].data4 = Reg[srcIdx].data4;
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = ADDRESS;
			}
		}
		else if(Reg[destIdx].type == FLOAT){
			if(Reg[srcIdx].type == FLOAT){
				Reg[destIdx].data2 = Reg[srcIdx].data2;
			}
			else if(Reg[srcIdx].type == INT){
				Reg[destIdx].data1 = Reg[srcIdx].data1;
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = INT;
			}
			else if(Reg[srcIdx].type == BOOLEN){
				Reg[destIdx].data3 = Reg[srcIdx].data3;
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[srcIdx].type == ADDRESS){
				Reg[destIdx].data4 = Reg[srcIdx].data4;
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = ADDRESS;
			}
		}
		else if(Reg[destIdx].type == BOOLEN){
			if(Reg[srcIdx].type == BOOLEN){
				Reg[destIdx].data3 = Reg[srcIdx].data3;
			}
			else if(Reg[srcIdx].type == INT){
				Reg[destIdx].data1 = Reg[srcIdx].data1;
				Reg[destIdx].data3 = 0;
				Reg[destIdx].type = INT;
			}
			else if(Reg[srcIdx].type == FLOAT){
				Reg[destIdx].data2 = Reg[srcIdx].data2;
				Reg[destIdx].data3 = 0;
				Reg[destIdx].type = FLOAT;
			}
			else if(Reg[srcIdx].type == ADDRESS){
				Reg[destIdx].data4 = Reg[srcIdx].data4;
				Reg[destIdx].data3 = 0;
				Reg[destIdx].type = ADDRESS;
			}
		}
		else if(Reg[destIdx].type == ADDRESS){
			if(Reg[srcIdx].type == ADDRESS){
				Reg[destIdx].data4 = Reg[srcIdx].data4;
			}
			else if(Reg[srcIdx].type == INT){
				Reg[destIdx].data1 = Reg[srcIdx].data1;
				Reg[destIdx].data4 = "";
				Reg[destIdx].type = INT;
			}
			else if(Reg[srcIdx].type == FLOAT){
				Reg[destIdx].data2 = Reg[srcIdx].data2;
				Reg[destIdx].data4 = "";
				Reg[destIdx].type = FLOAT;
			}
			else if(Reg[srcIdx].type == BOOLEN){
				Reg[destIdx].data3 = Reg[srcIdx].data3;
				Reg[destIdx].data4 = "";
				Reg[destIdx].type = BOOLEN;
			}
		}
		else throw InvalidOperand(IP);
	}
	else{
		if(check(src) == 0){
			if (Reg[destIdx].type == NONE){
				Reg[destIdx].data3 = con2bool(src);
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == INT){
				Reg[destIdx].data3 = con2bool(src);
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data3 = con2bool(src);
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == ADDRESS){
				Reg[destIdx].data3 = con2bool(src);
				Reg[destIdx].data4 = "";
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[destIdx].type == BOOLEN){
				Reg[destIdx].data3 = con2bool(src);
			}
			else if(Reg[destIdx].type == NONE){
				Reg[destIdx].data3 = con2bool(src);
				Reg[destIdx].type = BOOLEN;
			}
		}
		else if(check(src) == 1){
			if (Reg[destIdx].type == NONE){
				Reg[destIdx].data1 = stoi(src);
				Reg[destIdx].type = INT;
			}
			else if(Reg[destIdx].type == INT){
				Reg[destIdx].data1 = stoi(src);
			}
			else if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data1 = stoi(src);
				Reg[destIdx].data2 = 0;
				Reg[destIdx].type = INT;
			}
			else if(Reg[destIdx].type == BOOLEN){
				Reg[destIdx].data1 = stoi(src);
				Reg[destIdx].data3 = 0;
				Reg[destIdx].type = INT;
			}
			else if(Reg[destIdx].type == ADDRESS){
				Reg[destIdx].data1 = stoi(src);
				Reg[destIdx].data4 = "";
				Reg[destIdx].type = INT;
			}
			else if(Reg[destIdx].type == NONE){
				Reg[destIdx].data1 = stoi(src);
				Reg[destIdx].type = INT;
			}
		}
		else if(check(src) == 2){
			if(Reg[destIdx].type == FLOAT){
				Reg[destIdx].data2 = stof(src);
			}
			else if(Reg[destIdx].type == INT){
				Reg[destIdx].data2 = stof(src);
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = FLOAT;
			}
			else if(Reg[destIdx].type == BOOLEN){
				Reg[destIdx].data2 = stof(src);
				Reg[destIdx].data3 = 0;
				Reg[destIdx].type = FLOAT;
			}
			else if(Reg[destIdx].type == ADDRESS){
				Reg[destIdx].data2 = stof(src);
				Reg[destIdx].data4 = "";
				Reg[destIdx].type = FLOAT;
			}
			else if(Reg[destIdx].type == NONE){
				Reg[destIdx].data2 = stof(src);
				Reg[destIdx].type = FLOAT;
			}
		}
		else if(check(src) == 3){
			if(Reg[destIdx].type == ADDRESS){
				Reg[destIdx].data4 = src;
			}
			else if(Reg[destIdx].type == INT){
				Reg[destIdx].data4 = src;
				Reg[destIdx].data1 = 0;
				Reg[destIdx].type = ADDRESS;
			}
			else if(Reg[destIdx].type == BOOLEN){
				Reg[destIdx].data4 = src;
				Reg[destIdx].data3 = 0;
				Reg[destIdx].type = ADDRESS;
			}
			else if(Reg[destIdx].type == ADDRESS){
				Reg[destIdx].data4 = src;
			}
			else if(Reg[destIdx].type == NONE){
				Reg[destIdx].data4 = src;
				Reg[destIdx].type = ADDRESS;
			}
		}
		else throw InvalidOperand(IP);
	}
}

void VM::Load(string dest, string src){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(src[0] == 'R'){
		int srcIdx = stoi(src.substr(1)) - 1;
			for(int i = 0; i < 15; i++){
				if(Reg[i].data4 == Reg[srcIdx].data4){
					if(Reg[i].type == INT){
						Reg[destIdx].data1 = Reg[i].data1;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].data3 = 0;
						Reg[destIdx].type = INT;
					}
					else if(Reg[i].type == FLOAT){
						Reg[destIdx].data2 = Reg[i].data2;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].data3 = 0;
						Reg[destIdx].type = FLOAT;
					}
					else if(Reg[i].type == BOOLEN){
						Reg[destIdx].data3 = Reg[i].data3;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].type = BOOLEN;
					}
					else if(Reg[i].type == ADDRESS){
						Reg[destIdx].data4 = Reg[i].data4;
						Reg[destIdx].type = ADDRESS;
					}
				}
			}
	}
	else{
		int t = check(src);
		if(t == 3){
			string s = src.substr(0,src.length()-1);
			for(int k = 0; k<15; k++){
				if(Reg[k].data4 == s){
					if(Reg[k].type == INT){
						Reg[destIdx].type = INT;
						Reg[destIdx].data1 = Reg[k].data1;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].data3 = 0;
					}
					else if(Reg[k].type == FLOAT){
						Reg[destIdx].type = FLOAT;
						Reg[destIdx].data2 = Reg[k].data2;
						Reg[destIdx].data1 = 0;
						Reg[destIdx].data3 = 0;
					}
					else if(Reg[k].type == BOOLEN){
						Reg[destIdx].type = BOOLEN;
						Reg[destIdx].data3 = Reg[k].data3;
						Reg[destIdx].data2 = 0;
						Reg[destIdx].data1 = 0;
					}
					else if(Reg[k].type == ADDRESS){
						Reg[destIdx].type = ADDRESS;
						Reg[destIdx].data4 = Reg[k].data4;
					}
				}
			}
			
		}
		else if( t < 3) throw TypeMismatch(IP);
		else throw InvalidOperand(IP);
	}
}

void VM::Store(string dest, string src){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(src[0] == 'R'){
		int srcIdx = stoi(src.substr(1)) - 1;
			if(Reg[srcIdx].type == BOOLEN){
				Reg[destIdx].data3 = Reg[srcIdx].data3;
				Reg[destIdx].type = BOOLEN;
			}
			else if(Reg[srcIdx].type == INT){
				Reg[destIdx].data1 = Reg[srcIdx].data1;
				Reg[destIdx].type = INT;
			}
			else if(Reg[srcIdx].type == FLOAT){
				Reg[destIdx].data2 = Reg[srcIdx].data2;
				Reg[destIdx].type = FLOAT;
			}
			else if(Reg[srcIdx].type == ADDRESS){
				Reg[destIdx].data4 = Reg[srcIdx].data4;
				Reg[destIdx].type = ADDRESS;
			}
			else throw InvalidOperand(IP);
	}
	else{
			int t = check(src);
			if(t == 0){
				Reg[destIdx].data3 = con2bool(src);
				Reg[destIdx].type = BOOLEN;
			}
			else if(t == 1){
				Reg[destIdx].data1 = stoi(src);
				Reg[destIdx].type = INT;
			}
			else if(t == 2){
				Reg[destIdx].data2 = stof(src);
				Reg[destIdx].type = FLOAT;
			}
			else if(t == 3){
				Reg[destIdx].data4 = src;
				Reg[destIdx].type = ADDRESS;
			}
			else throw InvalidOperand(IP);
	}
	
}

void VM::Jump(string src){
	int t = check(src);
	if(t == 3){
		string s = src.substr(0,src.length()-1);
		int k = stoi(s);
		if(k >= CodeLoadedIndex) throw InvalidDestination(IP);
		else{
			IP = k - 1;
		} 
	}
	else if (t<3) throw TypeMismatch(IP);
	else throw InvalidOperand(IP);
}

void VM::JumpIf(string dest, string src){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(Reg[destIdx].type == BOOLEN){
		if(Reg[destIdx].data3){
			int t = check(src);
			if(t == 3){
				string s = src.substr(0,src.length()-1);
				int k = stoi(s);
				if(k >= CodeLoadedIndex) throw InvalidDestination(IP);
				else IP = stoi(s) - 1;
			}
			else if (t<3) throw TypeMismatch(IP);
			else throw InvalidOperand(IP);
		}
	}
	else throw TypeMismatch(IP);
}

void VM::Call(string src){
	if(stack.size() < 1000){
		stack.add(IP);
	}
	else throw StackFull(IP);
	VM::Jump(src);
}
void VM::Return(){
	if(stack.empty()){
		return;
	}
	IP = stack.get();
}

void VM::Input(string dest){
	int destIdx = stoi(dest.substr(1)) - 1;
	if(Reg[destIdx].type == INT){
		cin>>Reg[destIdx].data1;
	}
	else if(Reg[destIdx].type == FLOAT){
		cin>>Reg[destIdx].data2;
	}
	else if(Reg[destIdx].type == BOOLEN){
		cin>>Reg[destIdx].data3;
	}
	else throw InvalidInput(IP);
}

void VM::Output(string dest){
	if(dest[0] == 'R'){
		int destIdx = stoi(dest.substr(1)) - 1;
		if(Reg[destIdx].type == INT){
			cout<<Reg[destIdx].data1;
		}
		else if(Reg[destIdx].type == FLOAT){
			cout<<Reg[destIdx].data2;
		}
		else if(Reg[destIdx].type == BOOLEN){
			cout<<Reg[destIdx].data3;
		}
		else if(Reg[destIdx].type == ADDRESS){
			cout<<Reg[destIdx].data4;
		}
	}
	else{
		int t = check(dest);
		if(t == 0){
			cout<<con2bool(dest);
		}
		else if(t == 1){
			cout<<stoi(dest);
		}
		else if(t == 2){
			cout<<stof(dest);
		}
		else if (t == 3){
			cout<<dest;
		}
		else throw TypeMismatch(IP);
	}
	
}

void VM::Halt(){
	exit(0);
}

void VM::run(string filename)
{
	int address = 0;
	ifstream file(filename.c_str());
   	if (!file)
   	{  
      	throw InvalidInstruction(6);
      	return; 
   	}  
   	string line;
   	while (getline(file, line)) {
        Control(line,address);//hàm check input đầu vào
		address++;
    }
	exec();
   	file.close();
}