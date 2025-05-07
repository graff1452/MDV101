module bitty_core (
    input   wire        clk,
    input   wire        reset,
    input   wire        run,
    input   wire [15:0] instruction,
    output  wire        done
);
    // Control Unit Wires
    wire [2:0] sel;
    wire [3:0] mux_sel;
    wire [15:0] imm_val;
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

    // Multiplexor Wires
    wire [15:0] mux_out;
    wire [15:0] Reg_Inst_Out;
    wire [15:0] Reg_S_Out;
    wire [15:0] Reg_C_Out;
    wire [15:0] Reg_0_Out;
    wire [15:0] Reg_1_Out;
    wire [15:0] Reg_2_Out;
    wire [15:0] Reg_3_Out;
    wire [15:0] Reg_4_Out;
    wire [15:0] Reg_5_Out;
    wire [15:0] Reg_6_Out;
    wire [15:0] Reg_7_Out;

    //ALU Wires
    wire [15:0] alu_out;

    // Control Unit Instance
    control_unit myControlUnit (.run(run),
                               .clk(clk), 
                               .reset(reset), 
                               .instruction(instruction),
                               .en_s(en_s),
                               .en_c(en_c),
                               .en_i(en_i),
                               .en_0(en_0),
                               .en_1(en_1),
                               .en_2(en_2),
                               .en_3(en_3),
                               .en_4(en_4),
                               .en_5(en_5),
                               .en_6(en_6),
                               .en_7(en_7),
                               .sel(sel),
                               .mux_sel(mux_sel),
                               .done(done),
                               .imm_val(imm_val));

    // Register Instances
    register Reg_Inst (.d_in(instruction),
                       .reset(reset),
                       .clk(clk),
                       .en(en_i),
                       .d_out(Reg_Inst_Out));
    
    register Reg_S (.d_in(mux_out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_s),
                    .d_out(Reg_S_Out));
    
    register Reg_C (.d_in(alu_out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_c),
                    .d_out(Reg_C_Out));

    register Reg_0 (.d_in(Reg_C_Out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_0),
                    .d_out(Reg_0_Out));

    register Reg_1 (.d_in(Reg_C_Out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_1),
                    .d_out(Reg_1_Out));

    register Reg_2 (.d_in(Reg_C_Out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_2),
                    .d_out(Reg_2_Out));

    register Reg_3 (.d_in(Reg_C_Out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_3),
                    .d_out(Reg_3_Out));

    register Reg_4 (.d_in(Reg_C_Out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_4),
                    .d_out(Reg_4_Out));

    register Reg_5 (.d_in(Reg_C_Out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_5),
                    .d_out(Reg_5_Out));

    register Reg_6 (.d_in(Reg_C_Out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_6),
                    .d_out(Reg_6_Out));

    register Reg_7 (.d_in(Reg_C_Out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_7),
                    .d_out(Reg_7_Out));

    mux myMux (.in_0(Reg_0_Out),
               .in_1(Reg_1_Out),
               .in_2(Reg_2_Out),
               .in_3(Reg_3_Out),
               .in_4(Reg_4_Out),
               .in_5(Reg_5_Out),
               .in_6(Reg_6_Out),
               .in_7(Reg_7_Out),
               .in_8(imm_val),
               .in_9(16'b0),
               .mux_sel(mux_sel),
               .mux_out(mux_out));
    
    alu myAlu (.A(Reg_S_Out),
               .B(mux_out),
               .Sel(sel),
               .ALUOut(alu_out));
endmodule
