module register (
    input   wire [15:0]     d_in,
    input   wire            reset,
    input   wire            clk,
    input   wire            en,
    output  wire [15:0]     d_out
);
    reg [15:0] reg_d_out;
    always @(posedge clk or posedge reset) begin
        if (reset) 
        begin
            reg_d_out <= 16'h0000;
        end
        else 
        begin
            if (en) 
            begin
                reg_d_out <= d_in;
            end
        end
    end
    assign d_out = reg_d_out;
endmodule
