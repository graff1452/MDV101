module moduleName (
    input run,
    input clk,
    input reset,
    input [15:0] instruction,
    output reg en_s,
    output reg en_c,
    output reg en_i,
    output reg en_0,
    output reg en_1,
    output reg en_2,
    output reg en_3,
    output reg en_4,
    output reg en_5,
    output reg en_6,
    output reg en_7,
    output reg mode,
    output reg [3:0] sel,
    output reg [3:0] mux_sel,
    output reg done
);

    parameter A=0, B=1, C=2, D=3;

    reg M;
    reg [1:0] state, next_state, Res2;
    reg [2:0] Rx, Ry, Res1;
    reg [3:0] ALU_sel;

    always @(*) begin
        case (state)
            A: next_state = B;
            B: next_state = C;
            C: next_state = D;
            D: next_state = D;
            default: next_state = A;
        endcase
    end

    always @(*) begin
        en_s = 0;
        en_c = 0;
        en_i = 0;
        en_0 = 0;
        en_1 = 0;
        en_2 = 0;
        en_3 = 0;
        en_4 = 0;
        en_5 = 0;
        en_6 = 0;
        en_7 = 0;
        mode = 0;
        sel = 4'b0000;
        mux_sel = 4'b0000;
        done = 0;
        case (state) 
            A: begin
                Rx = instruction[15:13];
                Ry = instruction[12:10];
                Res1 = instruction[9:7];
                ALU_sel = instruction[6:3];
                M = instruction[2];
                Res2 = instruction[1:0];
                en_i = 1;
            end
            B: begin
                en_s = 1;
                mux_sel = {1'b0, Rx};
            end
            C: begin
                en_c = 1;
                sel = ALU_sel;
                mux_sel = {1'b0, Ry};
            end
            D: begin
                done = 1;
            end
        endcase
    end

    always @(posedge clk) begin
        if (run) begin
            if (reset) begin
                state <= A;
            end
            else begin
                state <= next_state;
            end
        end
    end

endmodule
