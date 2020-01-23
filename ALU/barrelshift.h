#ifndef BARRELSHIFT_H   
#define BARRELSHIFT_H

#include <systemc.h>       

void make_barrel(); 

SC_MODULE(barrel_shift) {
	sc_in<bool > enable;
	sc_in<bool > left_right;
    	sc_in<sc_uint<3> > shift_amt;
    	sc_in<sc_uint<8> > din;
    	sc_out<sc_uint<8> > dout;
 
	void barrel_method();   
 
        SC_CTOR(barrel_shift) {

        SC_METHOD(barrel_method);
	dont_initialize();
        sensitive << din; //sensitive to any change or port signals
    }

};
#endif 
