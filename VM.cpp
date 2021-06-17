#include "VM.h"

void VM::run(string filename)
{
	ifstream file(file_name.c_str());
   	if (!file)
   	{  
      	cout<<"Cannot open file\n";
      	return; 
   	}  
   	string line;
   	while (getline(file, line)) {
        	cout << line << endl;
    }
   	file.close();
	cout << 1;
}
int VN::split(string line, string*& sp){
	
}