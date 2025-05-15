module instruction_fetch_unit (
    input wire clk,
    input wire reset,
    input wire bitty_core_done1,
    input wire bitty_core_done2,
    input wire [15:0] last_alu_result,
    output wire [15:0] instruction_out
);
    wire [7:0] pc_out;
    wire [7:0] branch_logic_out;
    wire [15:0] memory_out;
    reg [15:0] reg_instruction_out;

    assign instruction_out = reg_instruction_out;

    always@ (posedge clk or posedge reset) 
    begin
        if (reset) 
        begin
            reg_instruction_out <= 16'b0;
        end 
        else 
        begin
            reg_instruction_out <= memory_out;
        end
    end

    // PC Module
    pc my_pc (
        .d_in(branch_logic_out),
        .clk(clk),
        .en_pc(bitty_core_done2),
        .reset(reset),
        .d_out(pc_out)
    );

    // Memory Module
    insturction_memory my_memory (  
        .clk(clk),
        .address(pc_out),
        .out(memory_out)
    );

    // Branch Logic Module
    branch_logic my_branch_logic (
        .pc_address(pc_out),
        .instruction(memory_out),
        .register_c(last_alu_result),
        .bitty_core_done1(bitty_core_done1),
        .clk(clk),
        .reset(reset),
        .new_pc(branch_logic_out)
    );
endmodule
