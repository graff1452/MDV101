module ALU (
    input wire CIn,
    input wire [15:0] A,
    input wire [15:0] B,
    input wire [3:0] Sel,
    input wire Mode,
    output wire [15:0] ALUOut,
    output wire COut,
    output wire Cmp
);
    wire Arithmetic_Cmp, Arithmetic_COut;
    wire [15:0] Logic_LoOut, Arithmetic_ArOut;
    Logic myLogic (.A(A), .B(B), .Sel(Sel), .LoOut(Logic_LoOut));
    Arithmetic myArithmetic (.CIn(CIn), .A(A), .B(B), .Sel(Sel), .ArOut(Arithmetic_ArOut), .Cmp(Arithmetic_Cmp), .COut(Arithmetic_COut));
    assign ALUOut = Mode ? Logic_LoOut : Arithmetic_ArOut;
    assign COut = Mode ? 1'b0 : Arithmetic_COut;
    assign Cmp = Mode ? 1'b0 : Arithmetic_Cmp;
endmodule

module Logic (
    input wire [15:0] A,
    input wire [15:0] B,
    input wire [3:0] Sel,
    output wire [15:0] LoOut
);
    reg [15:0] reg_LoOut;
    always @(*) begin
        case (Sel)
            4'b0000: reg_LoOut = ~A;
            4'b0001: reg_LoOut = ~(A | B);
            4'b0010: reg_LoOut = ~A & B;
            4'b0011: reg_LoOut = 16'h0000;
            4'b0100: reg_LoOut = ~(A & B);
            4'b0101: reg_LoOut = ~B;
            4'b0110: reg_LoOut = A ^ B;
            4'b0111: reg_LoOut = A & ~B;
            4'b1000: reg_LoOut = ~A | B;
            4'b1001: reg_LoOut = ~(A ^ B);
            4'b1010: reg_LoOut = B;
            4'b1011: reg_LoOut = A & B;
            4'b1100: reg_LoOut = 16'hFFFF;
            4'b1101: reg_LoOut = A | ~B;
            4'b1110: reg_LoOut = A | B;
            4'b1111: reg_LoOut = A;
        endcase
    end
    assign LoOut = reg_LoOut;
endmodule

module Arithmetic (
    input wire CIn,
    input wire [15:0] A,
    input wire [15:0] B,
    input wire [3:0] Sel,
    output wire [15:0] ArOut,
    output wire Cmp,
    output wire COut
);
    reg [16:0] reg_ArOut;
    wire [16:0] a = {1'b0, A};
    wire [16:0] b = {1'b0, B};
    always @(*) begin
        case (Sel)
            4'b0000: reg_ArOut = a;
            4'b0001: reg_ArOut = a | b;
            4'b0010: reg_ArOut = a | ~b;
            4'b0011: reg_ArOut = {1'b0, 16'hFFFF};
            4'b0100: reg_ArOut = a | (a & ~b);
            4'b0101: reg_ArOut = (a | b) + (a & ~b) + {16'b0, CIn};
            4'b0110: reg_ArOut = a - b - 1;
            4'b0111: reg_ArOut = (a & ~b) - 1;
            4'b1000: reg_ArOut = a + (a & b) + {16'b0, CIn};
            4'b1001: reg_ArOut = a + b + {16'b0, CIn};
            4'b1010: reg_ArOut = (a | ~b) + (a & b) + {16'b0, CIn};
            4'b1011: reg_ArOut = (a & b) - 1;
            4'b1100: reg_ArOut = a + a + {16'b0, CIn};
            4'b1101: reg_ArOut = (a | b) + a + {16'b0, CIn};
            4'b1110: reg_ArOut = (a | ~b) + a + {16'b0, CIn};
            4'b1111: reg_ArOut = a - 1;
        endcase
    end
    assign ArOut = reg_ArOut[15:0];
    assign Cmp = A == B;
    assign COut = reg_ArOut[16];
endmodule
