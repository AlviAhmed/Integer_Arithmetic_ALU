//COE838 - Lab1 SystemC Intro
// BarrelShift Unit Tutorial
#ifndef ALU_H   //it is a guard feature, included in to prevent double declaration, this is in your C++ book you used to study
#define ALU_H
#include <systemc.h>       

SC_MODULE(alu_comp) { //some random names you can give I guess
	sc_in<sc_uint<8> > B_input;
	sc_in<sc_uint<8> > A_input;
	sc_in<bool > op_code;
    	sc_out<sc_uint<8> > aluout; 
//        sc_in<bool > clk; 
	void alu_comp_method();     
        SC_CTOR(alu_comp) { 
        SC_METHOD(alu_comp_method);
	dont_initialize();
        sensitive << A_input << B_input; //edge sensitive (positive)
    }
}; 

#endif 
