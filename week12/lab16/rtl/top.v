module top (
    input wire clk,
    input wire reset,
    input wire run,
    output wire done
);
    wire [7:0] instruction_fetch_out;

    instuction_fetch_unit my_instuction_fetch_unit (
        .clk(clk),
        .en_pc(done),
        .reset(reset),
        .d_out(instruction_fetch_out)
    );

    bitty_core my_bitty_core (
        .clk(clk),
        .reset(reset),
        .run(run),
        .instruction(instruction_fetch_out),
        .done(done)
    );
endmodule