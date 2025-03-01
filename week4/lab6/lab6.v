module priority_encoder_9to4 (
    input wire in8,  
    input wire in7,  
    input wire in6,  
    input wire in5,  
    input wire in4,  
    input wire in3,  
    input wire in2,  
    input wire in1,  
    input wire in0,  

    output reg [3:0] out
);

always @(*) begin
    if (in8)
        out = 4'b1001;  // in8 is 9
    else if (in7)
        out = 4'b1000;  // in7 is 8 
    else if (in6)
        out = 4'b0111;  // in7 is 7
    else if (in5)
        out = 4'b0110;  // in7 is 6 
    else if (in4)
        out = 4'b0101;  // in7 is 5 
    else if (in3)
        out = 4'b0100;  // in7 is 4 
    else if (in2)
        out = 4'b0011;  // in7 is 3 
    else if (in1)
        out = 4'b0010;  // in7 is 2 
    else if (in0)
        out = 4'b0001;  // in7 is 1 
    else
        out = 4'b0000;  // No input is 0
end

endmodule