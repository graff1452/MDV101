module mux (
    input wire [15:0] in_0,
    input wire [15:0] in_1,
    input wire [15:0] in_2,
    input wire [15:0] in_3,
    input wire [15:0] in_4,
    input wire [15:0] in_5,
    input wire [15:0] in_6,
    input wire [15:0] in_7,
    input wire [15:0] in_8,
    input wire [15:0] in_9,
    input wire [3:0] mux_sel,
    output reg [15:0] mux_out 
);

    always @(*) begin
        case (mux_sel)
            4'b0000: mux_out = in_0;
            4'b0001: mux_out = in_1;
            4'b0010: mux_out = in_2;
            4'b0011: mux_out = in_3;
            4'b0100: mux_out = in_4;
            4'b0101: mux_out = in_5;
            4'b0110: mux_out = in_6;
            4'b0111: mux_out = in_7;
            4'b1000: mux_out = in_8;
            4'b1001: mux_out = in_9;
            default: mux_out = 16'h0000;
        endcase
    end

endmodule
