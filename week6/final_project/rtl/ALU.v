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
    wire [15:0] Logic_LoOut;
    wire [15:0] Arithmetic_ArOut;
    wire Arithmetic_Cmp;
    wire Arithmetic_COut;
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
    output reg [15:0] LoOut
);
    always @(*) begin
        case (Sel)
            4'b0000: LoOut = ~A;
            4'b0001: LoOut = ~(A | B);
            4'b0010: LoOut = ~A & B;
            4'b0011: LoOut = 16'h0000;
            4'b0100: LoOut = ~(A & B);
            4'b0101: LoOut = ~B;
            4'b0110: LoOut = A ^ B;
            4'b0111: LoOut = A & ~B;
            4'b1000: LoOut = ~A | B;
            4'b1001: LoOut = ~(A ^ B);
            4'b1010: LoOut = B;
            4'b1011: LoOut = A & B;
            4'b1100: LoOut = 16'hFFFF;
            4'b1101: LoOut = A | ~B;
            4'b1110: LoOut = A | B;
            4'b1111: LoOut = A;
        endcase
    end
endmodule

module Arithmetic (
    input wire CIn,
    input wire [15:0] A,
    input wire [15:0] B,
    input wire [3:0] Sel,
    output reg [15:0] ArOut,
    output wire Cmp,
    output wire COut
);
    reg [16:0] result;
    wire [16:0] a;
    wire [16:0] b;
    assign a = {1'b0, A};
    assign b = {1'b0, B};
    always @(*) begin
        case (Sel)
            4'b0000: result = a;
            4'b0001: result = a | b;
            4'b0010: result = a | ~b;
            4'b0011: result = {1'b0, 16'hFFFF};
            4'b0100: result = a | (a & ~b);
            4'b0101: result = (a | b) + (a & ~b) + {16'b0, CIn};
            4'b0110: result = a - b - 1;
            4'b0111: result = (a & ~b) - 1;
            4'b1000: result = a + (a & b) + {16'b0, CIn};
            4'b1001: result = a + b + {16'b0, CIn};
            4'b1010: result = (a | ~b) + (a & b) + {16'b0, CIn};
            4'b1011: result = (a & b) - 1;
            4'b1100: result = a + a + {16'b0, CIn};
            4'b1101: result = (a | b) + a + {16'b0, CIn};
            4'b1110: result = (a | ~b) + a + {16'b0, CIn};
            4'b1111: result = a - 1;
        endcase
    end
    assign ArOut = result[15:0];
    assign Cmp = A == B;
    assign COut = result[16];
endmodule