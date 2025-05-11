module branch_logic (
    input wire [7:0] pc_address,
    input wire [15:0] instruction,
    input wire [15:0] register_c,
    input wire run,
    output wire [7:0] new_pc
);
    wire [11:0] immediate_value = instruction[15:4];
    wire [1:0]  format = instruction[1:0];
    wire [1:0]  condition = instruction[3:2];
    reg [7:0]   reg_new_pc;
    assign new_pc = reg_new_pc;
    always @(*) begin
        if (run) 
        begin
            if (format == 2'b10) 
            begin
                case (condition)
                    2'b00: 
                    begin
                        if (register_c == 0) 
                        begin
                            reg_new_pc <= pc_address + immediate_value;
                        end
                        else 
                        begin
                            reg_new_pc <= pc_address + 1;
                        end
                    end
                    2'b01: 
                    begin
                        if (register_c == 16'h0001) 
                        begin
                            reg_new_pc <= pc_address + immediate_value;
                        end
                        else 
                        begin
                            reg_new_pc <= pc_address + 1;
                        end
                    end
                    2'b10: 
                    begin
                        if (register_c == 16'h0002) 
                        begin
                            reg_new_pc <= pc_address + immediate_value;
                        end
                        else 
                        begin
                            reg_new_pc <= pc_address + 1;
                        end
                    end
                    default: 
                    begin
                        if (register_c == 0) 
                        begin
                            reg_new_pc <= pc_address + immediate_value;
                        end
                        else 
                        begin
                            reg_new_pc <= pc_address + 1;
                        end
                    end
                endcase
            end
            else 
            begin
                reg_new_pc <= pc_address + 1;
            end
        end
    end
endmodule
