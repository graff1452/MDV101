module bitty_core (
    input   wire        clk,
    input   wire        reset,
    input   wire        run,
    input   wire [15:0] instruction,
    output  wire        done
);

    wire [3:0] sel;
    wire [3:0] mux_sel;
    wire mode;
    wire done;
    wire en_s;
    wire en_c;
    wire en_0;
    wire en_1;
    wire en_2;
    wire en_3;
    wire en_4;
    wire en_5;
    wire en_6;
    wire en_7;
    wire en_i;
    
    wire [15:0] Reg_Inst_Out;


    control_unit control_unit (.run(run),
                               .clk(clk), 
                               .reset(reset), 
                               .instruction(instruction)
                               .en_s(en_s)
                               .en_c(en_c)
                               .en_i(en_i)
                               .en_0(en_0)
                               .en_1(en_1)
                               .en_2(en_2)
                               .en_3(en_3)
                               .en_4(en_4)
                               .en_5(en_5)
                               .en_6(en_6)
                               .en_7(en_7)
                               .mode(mode)
                               .sel(sel))
                               .mux_sel(mux_sel)
                               .done(done);

    register Reg_Inst (.d_in(instruction),
                       .reset(reset),
                       .clk(clk),
                       .en(en_i),
                       .d_out(Reg_Inst_Out));
endmodule