module register_memory (
    input   wire clk,
    input   wire [15:0] instruction,
    input   wire [15:0] Reg_0,
    input   wire [15:0] Reg_1,
    input   wire [15:0] Reg_2,
    input   wire [15:0] Reg_3,
    input   wire [15:0] Reg_4,
    input   wire [15:0] Reg_5,
    input   wire [15:0] Reg_6,
    input   wire [15:0] Reg_7,
    input   wire run,
    // output  wire [15:0] Reg_0_Out,
    // output  wire [15:0] Reg_1_Out,
    // output  wire [15:0] Reg_2_Out,
    // output  wire [15:0] Reg_3_Out,
    // output  wire [15:0] Reg_4_Out,
    // output  wire [15:0] Reg_5_Out,
    // output  wire [15:0] Reg_6_Out,
    // output  wire [15:0] Reg_7_Out,
    output  wire [15:0] out
);

    parameter LOAD  = 1'b0;
    parameter STORE = 1'b1;
    wire [2:0] Rx_number = instruction[15:13];
    wire [2:0] Ry_number = instruction[12:10];
    wire format = instruction[2];
    reg [15:0] reg_out;
    assign out = reg_out;
    // For debugging
    // assign Reg_0_Out = memory_cell[0];
    // assign Reg_1_Out = memory_cell[1];
    // assign Reg_2_Out = memory_cell[2];
    // assign Reg_3_Out = memory_cell[3];
    // assign Reg_4_Out = memory_cell[4];
    // assign Reg_5_Out = memory_cell[5];
    // assign Reg_6_Out = memory_cell[6];
    // assign Reg_7_Out = memory_cell[7]; 
    reg [15:0] memory_cell [0:7]; // 8 x 16-bit memory

    always @(posedge clk) 
    begin
        if (run) 
        begin
            case (format)
                LOAD: 
                    reg_out <= memory_cell[Ry_number];
                STORE:
                    case (Rx_number)
                        3'b000: memory_cell[Ry_number] <= Reg_0;
                        3'b001: memory_cell[Ry_number] <= Reg_1;
                        3'b010: memory_cell[Ry_number] <= Reg_2;
                        3'b011: memory_cell[Ry_number] <= Reg_3;
                        3'b100: memory_cell[Ry_number] <= Reg_4;
                        3'b101: memory_cell[Ry_number] <= Reg_5;
                        3'b110: memory_cell[Ry_number] <= Reg_6;
                        3'b111: memory_cell[Ry_number] <= Reg_7;
                    endcase
            endcase
        end
    end
endmodule