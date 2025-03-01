module fibonacci_generator (
    input clk,
    input rst,
    input enable,
    output reg[31:0] fib_out
);

reg [31:0] fib_prev;
reg [31:0] fib_curr;

always @(posedge clk or posedge rst) begin
    if (rst) 
    begin
        fib_prev <= 32'd0;
        fib_curr <= 32'd1;
        fib_out  <= 32'd0;
    end 
    else if (enable) 
    begin
        fib_out  <= fib_curr + fib_prev;
        fib_prev <= fib_curr;
        fib_curr <= fib_out;
    end
end

endmodule