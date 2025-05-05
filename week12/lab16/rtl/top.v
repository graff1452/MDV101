module top (
    input wire clk,
    input wire reset,
    input wire run,
    output wire done
);
    wire [15:0] instruction_fetch_out;
    wire bitty_core_done;
    assign done = bitty_core_done;

    instruction_fetch_unit my_instuction_fetch_unit (
        .clk(clk),
        .en_pc(bitty_core_done),
        .reset(reset),
        .instruction_out(instruction_fetch_out)
    );

    bitty_core my_bitty_core (
        .clk(clk),
        .reset(reset),
        .run(run),
        .instruction(instruction_fetch_out),
        .done(bitty_core_done)
    );
endmodule