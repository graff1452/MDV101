import "DPI-C" function void notify_counter_reached_nine(); // 1

module counter(
    input logic clk, 
    input logic reset,
    output logic [3:0] count);

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            count <= 0;
        end else begin
            count <= count + 1;
            if (count == 4'd9) begin
                notify_counter_reached_nine(); // 2
            end
        end
    end
endmodule