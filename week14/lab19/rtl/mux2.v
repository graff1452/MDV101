module mux2 (
    input   wire [15:0]     in_0,
    input   wire [15:0]     in_1,
    input   wire            mux2_sel,
    output  wire [15:0]     mux2_out 
);
    reg [15:0] reg_mux2_out;
    assign mux2_out = reg_mux2_out;
    always @(*) 
    begin
        case (mux2_sel)
            1'b0: reg_mux2_out = in_0;
            1'b1: reg_mux2_out = in_1;
        endcase
    end
endmodule
