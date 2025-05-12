module register_8 (
    input   wire [7:0]     d_in,
    input   wire            reset,
    input   wire            clk,
    input   wire            en,
    output  wire [7:0]     d_out
);
    reg [7:0] reg_d_out;
    always @(posedge clk or posedge reset) 
    begin
        if (reset) 
        begin
            reg_d_out <= 8'h00;
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