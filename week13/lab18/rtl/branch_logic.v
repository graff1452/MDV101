module branch_logic (
    input wire [7:0] pc_address,
    input wire [15:0] instruction,
    input wire [15:0] register_c,
    input wire bitty_core_done1,
    input wire clk,
    input wire reset,
    output wire [7:0] new_pc
);
    wire [11:0] immediate_value = instruction[15:4];
    wire [1:0]  format = instruction[1:0];
    wire [1:0]  condition = instruction[3:2];

    reg [15:0]  reg_new_pc;

    register_8 Reg_branch_logic_Out (
        .d_in(reg_new_pc[7:0]),
        .reset(reset),
        .clk(clk),
        .en(bitty_core_done1),
        .d_out(new_pc)
    );

    always @(*)
    begin
        if (reset) 
        begin
            reg_new_pc = 16'b0;
        end 
        else if (bitty_core_done1) 
        begin
            if (format == 2'b10) 
            begin
                case (condition)
                    2'b00: if (register_c == 16'h0000) begin reg_new_pc = {8'b0, pc_address} + {4'b0, immediate_value}; end else begin reg_new_pc = {8'b0, pc_address} + 1; end
                    2'b01: if (register_c == 16'h0001) begin reg_new_pc = {8'b0, pc_address} + {4'b0, immediate_value}; end else begin reg_new_pc = {8'b0, pc_address} + 1; end
                    2'b10: if (register_c == 16'h0002) begin reg_new_pc = {8'b0, pc_address} + {4'b0, immediate_value}; end else begin reg_new_pc = {8'b0, pc_address} + 1; end
                    default: if (register_c == 16'h0000) begin reg_new_pc = {8'b0, pc_address} + {4'b0, immediate_value}; end else begin reg_new_pc = {8'b0, pc_address} + 1; end
                endcase
            end
            else 
            begin
                reg_new_pc = {8'b0, pc_address} + 1;
            end
        end
    end
endmodule
