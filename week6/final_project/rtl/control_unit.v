module moduleName (
    input wire run,
    input wire clk,
    input wire reset,
    input wire [15:0] instruction,
    output wire en_s,
    output wire en_c,
    output wire en_i,
    output wire en_0,
    output wire en_1,
    output wire en_2,
    output wire en_3,
    output wire en_4,
    output wire en_5,
    output wire en_6,
    output wire en_7,
    output wire mode,
    output wire [3:0] sel,
    output wire [3:0] mux_sel,
    output wire done
);
    parameter A = 2'b00, B = 2'b01, C = 2'b10, D = 2'b11;
    reg reg_M, reg_en_s, reg_en_c, reg_en_i, reg_en_0, reg_en_1, reg_en_2, reg_en_3, reg_en_4, reg_en_5, reg_en_6, reg_en_7, reg_mode, reg_done;
    reg [1:0] reg_state, reg_next_state, reg_Res2;
    reg [2:0] reg_Rx, reg_Ry, reg_Res1;
    reg [3:0] reg_ALU_sel, reg_sel, reg_mux_sel;

    always @(*) begin
        reg_en_s = 1'b0;
        reg_en_c = 1'b0;
        reg_en_i = 1'b0;
        reg_en_0 = 1'b0;
        reg_en_1 = 1'b0;
        reg_en_2 = 1'b0;
        reg_en_3 = 1'b0;
        reg_en_4 = 1'b0;
        reg_en_5 = 1'b0;
        reg_en_6 = 1'b0;
        reg_en_7 = 1'b0;
        reg_mode = 1'b0;
        reg_done = 1'b0;
        reg_sel = 4'b0000;
        reg_mux_sel = 4'b0000;
        reg_Rx = instruction[15:13];
        reg_Ry = instruction[12:10];
        reg_Res1 = instruction[9:7];
        reg_ALU_sel = instruction[6:3];
        reg_M = instruction[2];
        reg_Res2 = instruction[1:0];
        case (reg_state)
            A: 
            begin
                reg_en_i = 1'b1;
            end
            B: 
            begin
                reg_en_s = 1'b1;
                reg_mux_sel = {1'b0, reg_Rx};
            end
            C: 
            begin
                reg_en_c = 1'b1;
                reg_sel = reg_ALU_sel;
                reg_mux_sel = {1'b0, reg_Ry};
                reg_mode = reg_M;
            end
            D: 
            begin
                case (reg_Rx) 
                    3'b000: reg_en_0 = 1;
                    3'b001: reg_en_1 = 1;
                    3'b010: reg_en_2 = 1;
                    3'b011: reg_en_3 = 1;
                    3'b100: reg_en_4 = 1;
                    3'b101: reg_en_5 = 1;
                    3'b110: reg_en_6 = 1;
                    3'b111: reg_en_7 = 1;
                endcase
                reg_done = 1'b1;
            end
        endcase
    end

    always @(posedge clk) begin
        if (reset)
        begin
            reg_state <= A;
        end
        else if (run)
        begin
            case (reg_state)
                A: reg_next_state <= B;
                B: reg_next_state <= C;
                C: reg_next_state <= D;
                D: reg_next_state <= A;
                default: reg_next_state <= A;
            endcase
            reg_state <= reg_next_state;
        end
    end

    assign en_s = reg_en_s;
    assign en_c = reg_en_c;
    assign en_i = reg_en_i;
    assign en_0 = reg_en_0;
    assign en_1 = reg_en_1;
    assign en_2 = reg_en_2;
    assign en_3 = reg_en_3;
    assign en_4 = reg_en_4;
    assign en_5 = reg_en_5;
    assign en_6 = reg_en_6;
    assign en_7 = reg_en_7;
    assign mode = reg_mode;
    assign sel = reg_sel;
    assign mux_sel = reg_mux_sel;
    assign done = reg_done;
endmodule
