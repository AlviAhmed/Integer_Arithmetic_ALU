#include "barrelshift.h" 

void barrel_shift :: barrel_method(){
	sc_uint<8> data;     
	sc_uint<8> data_temp;    
	sc_uint<3> s_amt;  
	sc_uint<8> output_data;  
	int ly = 0; 
	int ry = 0; 
	int i = 0;
	cout << endl; 
	cout << "Barrel Shifter Parameters: " << endl; 
	if(enable.read() == 1){ //since barrel shift has enable pin must include 
		data = din.read();        
		data_temp = din.read();
		s_amt = shift_amt.read();
		if(left_right.read() == 0){ //shift left
			cout << "[left]  Data = \n" << data.to_string(SC_BIN) << endl;   
			for (ly = 0; ly < s_amt; ly++){ /* repeating the shift by a specified amount*/
				for(i = 7; i > 0; i--){
					data[i] = data_temp[i-1]; 
				}  
				data[0] = 0;    
				data_temp = data;
			}  
			dout.write(data);
		}else if(left_right.read() == 1){
		cout << "[right] Data = \n" << data.to_string(SC_BIN) << endl;      
			for (ry = 0; ry < s_amt; ry++){
				for(i = 0; i < 7; i++){//shift right
					data[i] = data_temp[i+1];   
				}  
				data[7] = 0;   
				data_temp = data;
			}  
			dout.write(data);   
		}   
	} 
	else if (enable.read() == 0){  //if enable 0 pass data, shifting disabled 
		dout.write(din.read()); //writing the input data of barrel shifter to the output 
		output_data = din.read(); //take the input of the barrel shift and make it output
	}
	else { 
		cout << "Not enabled "<<endl; 
	}	   
	cout << " InputB/Output barrel:  " << dout.read() << endl;    
	cout << endl; 
	cout << endl; 
}


