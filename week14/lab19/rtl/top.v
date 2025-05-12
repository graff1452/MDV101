module top (
    input wire clk,
    input wire reset,
    input wire run,
    output wire [15:0] top_out
);
    wire [15:0] instruction_fetch_out_instruction;
    wire bitty_core_out_done1;
    wire bitty_core_out_done2;
    wire [15:0] bitty_core_out_last_alu_result;

    reg [15:0] reg_top_out;
    assign top_out = reg_top_out;

    always @(posedge clk or posedge reset) 
    begin
        if (reset) 
        begin
            reg_top_out <= 16'h0000;
        end
        else 
        begin
            reg_top_out <= instruction_fetch_out_instruction;
        end
    end

    instruction_fetch_unit my_instuction_fetch_unit (
        .clk(clk),
        .reset(reset),
        .bitty_core_done1(bitty_core_out_done1),
        .bitty_core_done2(bitty_core_out_done2),
        .last_alu_result(bitty_core_out_last_alu_result),
        .instruction_out(instruction_fetch_out_instruction)
    );

    bitty_core my_bitty_core (
        .clk(clk),
        .reset(reset),
        .run(run),
        .instruction(instruction_fetch_out_instruction),
        .done1(bitty_core_out_done1),
        .done2(bitty_core_out_done2),
        .last_alu_result(bitty_core_out_last_alu_result)
    );
endmodule
