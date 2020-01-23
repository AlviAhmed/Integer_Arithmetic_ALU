//testing the ALU
#include <systemc.h>  
#include "barrelshift.h" 
#include "ALU.h" 

int sc_main(int argc, char* argv[]){
	 sc_trace_file *tf;                  // Create VCD file for tracing
	 sc_signal<sc_uint<8> > barrel_in, barrel_out;      //Declare signals  
	 sc_signal<sc_uint<8> > A_in;      //Declare signals 
	 sc_signal<sc_uint<8> > B_in;      //Declare signals 
	 sc_signal<sc_uint<8> > total_output;      //Declare signals
	 sc_signal<sc_uint<3> > shift_amount;      //Declare signals
	 sc_signal<bool > en;
	 sc_signal<bool > op;
	 sc_signal<bool > l_r;  
//	 sc_clock clk("clk",10,SC_NS,0.5);   //Create a clock signal
   	 barrel_shift testing_barrel("barrelshift");     //Create Device Under Test (DUT)
   	 alu_comp test_alu("ALU");     //Create Device Under Test (DUT)

	 //defining the barrelshifter variables
	 testing_barrel.enable(en);
	 testing_barrel.left_right(l_r); 
	 testing_barrel.shift_amt(shift_amount);  
	 testing_barrel.din(barrel_in); 
	 testing_barrel.dout(barrel_out);  

	 //defining the ALU variables 
   	 test_alu.A_input(A_in);  
   	 test_alu.B_input(barrel_out);  //making the b input of the ALU equal to the output of the barrel shifter
   	 test_alu.aluout(total_output);   
	 test_alu.op_code(op); 

       // Create wave file and trace the signals executing
	tf = sc_create_vcd_trace_file("trace_file");
        tf->set_time_unit(1, SC_NS);
	sc_trace(tf, A_in,"A_input"); 
	sc_trace(tf, barrel_out,"barrel_output_alu_input");  
	sc_trace(tf, en,"barrelshift_enable"); 
	sc_trace(tf, l_r,"barrelshift_left_right"); 
	sc_trace(tf, total_output,"Complete_Output"); 
	sc_trace(tf, op,"op_code_alu");   
	sc_trace(tf, barrel_in,"Barrel_Input"); 
	sc_trace(tf, shift_amount,"Shift_amount"); 
	cout << "\nExecuting ALU..... check .vcd produced"<<endl; 
	  // Now need to configure the testbench  
	  // 

// Case ********************  	
       //setting up barrel shifter values	  
	barrel_in.write(20);  
	en.write(1); 
	l_r.write(1);
	shift_amount.write(1);//shifting left once   

       //setting up ALU values	
	A_in.write(15);   
	op.write(0);  
	sc_start(15,SC_NS);      
//end ******************************   


// Case ********************  	
	barrel_in.write(4);  
	en.write(0); 
	l_r.write(1);
	shift_amount.write(1);   

       //setting up ALU values	
	A_in.write(20);   
	op.write(1); 
	sc_start(20,SC_NS);     
//end ******************************     


// Case ********************  	
       //setting up barrel shifter values	  
	barrel_in.write(3);  
	en.write(1); 
	l_r.write(0);
	shift_amount.write(2);   
       //setting up ALU values	
	A_in.write(30);   
	op.write(1); //substraction  
	sc_start(20,SC_NS);     
//end ******************************    


// Case ********************  	
       //setting up barrel shifter values	  
	barrel_in.write(10);  
	en.write(1); 
	l_r.write(0);
	shift_amount.write(2);   

       //setting up ALU values	
	A_in.write(40);   
	op.write(0);  
	sc_start(20,SC_NS);     
//end ******************************    


// Case ********************  	
       //setting up barrel shifter values	  
	barrel_in.write(10);  
	en.write(0); 
	l_r.write(1);
	shift_amount.write(1);   

       //setting up ALU values	
	A_in.write(50);   
	op.write(0);   
	sc_start(20,SC_NS);     
//end ******************************    


// Case ********************  	
       //setting up barrel shifter values	  
	barrel_in.write(1);  
	en.write(0); 
	l_r.write(1);
	shift_amount.write(1);   

       //setting up ALU values	
	A_in.write(60);   
	op.write(1);
	sc_start(20,SC_NS);     
//end ******************************    


// Case ********************  	
       //setting up barrel shifter values	  
	barrel_in.write(2);  
	en.write(1); 
	l_r.write(0);
	shift_amount.write(4);//shifting left once   

       //setting up ALU values	
	A_in.write(10);   
	op.write(1);   
	sc_start(20,SC_NS);     
//end ******************************     

// Case ********************  	NIL
       //setting up barrel shifter values	  
	barrel_in.write(0);  
	en.write(0); 
	l_r.write(0);
	shift_amount.write(0);//shifting left once   

       //setting up ALU values	
	A_in.write(0);   
	op.write(0);   
	sc_start(20,SC_NS);     
//end ******************************     

   	sc_close_vcd_trace_file(tf);
   	
   	return 0;                         
}
