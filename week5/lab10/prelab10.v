module traffic_light_fsm (
    input clk,
    input reset,
    output reg [2:0] light 
);
    parameter RED = 2'b00;
    parameter GREEN = 2'b01;
    parameter YELLOW = 2'b10;

    reg [1:0] current_state, next_state;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            current_state <= RED;
        end else begin
            current_state <= next_state;
        end
    end

    always @(*) begin
        case (current_state)
            RED: begin
                next_state = GREEN;
            end
            GREEN: begin
                next_state = YELLOW;
            end
            YELLOW: begin
                next_state = RED;
            end
            default: begin
                next_state = RED;
            end
        endcase
    end

    always @(*) begin
        case (current_state)
            RED: begin
                light = 3'b001; // RED light
            end
            GREEN: begin
                light = 3'b010; // GREEN light
            end
            YELLOW: begin
                light = 3'b100; // YELLOW light
            end
            default: begin
                light = 3'b001; // Default to RED light
            end
        endcase
    end
endmodule