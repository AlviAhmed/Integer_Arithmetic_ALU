//Alvi Ahmed 500696421 
#include "ALU.h"  
 sc_uint<8> output; 
 sc_uint<8> out_data; 
 sc_uint<8> ain; 
 sc_uint<8> bin;  
 void alu_comp :: alu_comp_method() {     
   	//module name :: implementing the function defined 
	cout << endl; 
	cout << "ALU Parameters: " << endl;
       cout << " Input A: " << A_input.read() << ", Op Code: "  << op_code.read() << endl;  
//don't need a if enable, will auto run when positive edge of clA 
        	ain = A_input.read(); 
        	bin = B_input.read(); 
        	if (op_code.read() == 1){  
        	  output = ain + bin; 
        	  aluout.write(output);
        	} 
        	if (op_code.read() == 0){  
        	  output = ain - bin; 
        	  aluout.write(output);
        	}  
		out_data = aluout.read();
		cout << " Complete ALU Output: " << out_data << endl;  
    }
