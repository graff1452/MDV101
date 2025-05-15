module instruction_memory (
    input   wire clk,
    input   wire [7:0] address,
    output  wire [15:0] out
);
    reg [15:0] out_reg;
    assign out = out_reg;

    reg [15:0] memory_cell [0:255]; // 256 x 16-bit memory

    initial 
    begin
        $readmemh("/home/zhan/Desktop/MDV101/week14/lab19/generator/instructions.txt", memory_cell);
    end

    always @(posedge clk) 
    begin
        out_reg <= memory_cell[address];
    end
endmodule
