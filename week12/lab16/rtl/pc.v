module pc (
    input wire  [7:0] d_in,
    input wire  clk,
    input wire  en_pc,
    input wire  reset,
    output wire [7:0] d_out
);

    reg [7:0] reg_d_out;
    assign d_out = reg_d_out;
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            reg_d_out <= 8'b0;
        end else if (en_pc) begin
            reg_d_out <= d_in;
        end
    end
endmodule
