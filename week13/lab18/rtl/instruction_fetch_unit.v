module instruction_fetch_unit (
    input wire clk,
    input wire reset,
    input wire en_pc,
    input wire [15:0] last_alu_result,
    output wire [15:0] instruction_out
);
    wire [7:0] pc_out;
    reg [7:0] pc_out_pipeline; // Pipeline register for delayed PC output
    wire [7:0] new_pc;
    wire [15:0] memory_out;
    reg [15:0] reg_instruction_out;

    assign instruction_out = reg_instruction_out;

    // PC Module
    pc my_pc (
        .d_in(new_pc),
        .clk(clk),
        .en_pc(en_pc),
        .reset(reset),
        .d_out(pc_out)
    );

    // Memory Module
    memory my_memory (  
        .clk(clk),
        .address(pc_out_pipeline), // Use delayed PC output
        .out(memory_out)
    );

    // Branch Logic Module
    branch_logic my_branch_logic (
        .pc_address(pc_out_pipeline), // Use delayed PC output
        .instruction(memory_out),
        .register_c(last_alu_result),
        .run(en_pc),
        .new_pc(new_pc)
    );

    // Pipeline Logic
    always @(posedge clk or posedge reset) 
    begin
        if (reset) 
        begin
            pc_out_pipeline <= 8'b0; // Reset pipeline register for PC
            reg_instruction_out <= 16'b0; // Reset instruction output
        end 
        else if (en_pc) 
        begin
            pc_out_pipeline <= pc_out; // Delay PC output by one cycle
            reg_instruction_out <= memory_out; // Update instruction output
        end
    end
endmodule
