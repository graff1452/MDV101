module alu (
    input   wire [15:0] A,
    input   wire [15:0] B,
    input   wire [2:0]  Sel,
    output  wire  [15:0] ALUOut
);
    reg [15:0] reg_ALUOut;
    always @(*) begin
        case (Sel)
            3'b000:     reg_ALUOut = A + B;
            3'b001:     reg_ALUOut = A - B;
            3'b010:     reg_ALUOut = A & B;
            3'b011:     reg_ALUOut = A | B;
            3'b100:     reg_ALUOut = A ^ B;
            3'b101:     reg_ALUOut = A << (B % 16);
            3'b110:     reg_ALUOut = A >> (B % 16);
            3'b111:
            begin
                if (A == B) 
                begin
                    reg_ALUOut = 16'h0000;
                end
                else if (A > B) 
                begin
                    reg_ALUOut = 16'h0001;
                end
                else
                begin
                    reg_ALUOut = 16'h0002;
                end
            end 
        endcase
    end
    assign ALUOut = reg_ALUOut;
endmodule
