module keyLock (
    input wire clk,
    input wire reset,
    input wire [3:0] digit,
    output reg locked
);

    reg [3:0] current_state;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            current_state <= 4'b0000;
            locked <= 1'b1;
        end else begin
            case (current_state) 
                4'b0000: 
                    if (digit == 4'b0011) begin 
                        current_state <= 4'b0001;
                    end
                    else begin 
                        current_state <= 4'b0000;
                    end
                4'b0001: 
                    if (digit == 4'b0011) begin 
                        current_state <= 4'b0010;
                    end
                    else begin 
                        current_state <= 4'b0000;
                    end
                4'b0010: 
                    if (digit == 4'b0101) begin 
                        current_state <= 4'b0011;
                    end
                    else begin 
                        current_state <= 4'b0000;
                    end
                4'b0011: 
                    if (digit == 4'b0010) begin 
                        current_state <= 4'b0100;
                    end
                    else begin
                        current_state <= 4'b0000;
                    end
                4'b0100: 
                    if (digit == 4'b0101) begin
                        current_state <= 4'b0101;
                    end
                    else begin 
                        current_state <= 4'b0000;
                    end
                4'b0101: 
                    if (digit == 4'b0110) begin
                        locked <= 1'b0;
                    end
                    else begin 
                        current_state <= 4'b0000;
                    end
                default: 
                    current_state <= 4'b0000;
            endcase
        end
    end

endmodule
