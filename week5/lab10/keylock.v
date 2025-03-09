module keylock (
    input clk,
    input reset,
    input [3:0] digit,
    output reg locked
);
    parameter FIRST     = 3'b000;
    parameter SECOND    = 3'b001;
    parameter THIRD     = 3'b010;
    parameter FOURTH    = 3'b011;
    parameter FIFTH     = 3'b100;
    parameter SIXTH     = 3'b101;
    parameter SEVENTH   = 3'b110;
    parameter UNLOCKED  = 3'b111;

    parameter THREE = 4'b0011;
    parameter FIVE  = 4'b0101;
    parameter TWO   = 4'b0010;
    parameter SIX   = 4'b0110;

    reg [2:0] current_state, next_state;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            current_state <= FIRST;
            locked <= 1;
        end else begin
            current_state <= next_state;
            locked <= (next_state != UNLOCKED);
        end
    end

    always @(*) begin
        case (current_state)
            FIRST:     next_state = (digit == THREE) ? SECOND : FIRST;
            SECOND:    next_state = (digit == THREE) ? THIRD : FIRST;
            THIRD:     next_state = (digit == FIVE)  ? FOURTH : FIRST;
            FOURTH:    next_state = (digit == TWO)   ? FIFTH  : FIRST;
            FIFTH:     next_state = (digit == FIVE)  ? SIXTH  : FIRST;
            SIXTH:     next_state = (digit == SIX)   ? SEVENTH : FIRST;
            SEVENTH:   next_state = UNLOCKED;
            UNLOCKED:  next_state = UNLOCKED;
            default:   next_state = FIRST;
        endcase
    end
endmodule
