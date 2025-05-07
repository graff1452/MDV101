module instruction_fetch_unit (
    input wire clk,
    input wire reset,
    input wire en_pc,
    output wire [15:0] instruction_out
);
    reg [15:0] reg_instruction_out;
    wire [7:0] pc_d_in;
    wire [7:0] pc_d_out;
    wire [15:0] memory_out;

    assign instruction_out = reg_instruction_out;
    assign pc_d_in = pc_d_out + 1;

    pc pc_unit (
        .d_in(pc_d_in),
        .clk(clk),
        .en_pc(en_pc),
        .reset(reset),
        .d_out(pc_d_out)
    );

    memory memory_unit (
        .clk(clk),
        .address(pc_d_out),
        .out(memory_out)
    );

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            reg_instruction_out <= 16'b0;
        end else if (en_pc) begin
            reg_instruction_out <= memory_out;
        end
    end
endmodule
