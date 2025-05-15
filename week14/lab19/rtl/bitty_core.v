module bitty_core (
    input   wire        clk,
    input   wire        reset,
    input   wire        run,
    input   wire [15:0] instruction,
    output  wire        done1,
    output  wire        done2,
    // output  wire [15:0] Reg_0_Out,
    // output  wire [15:0] Reg_1_Out,
    // output  wire [15:0] Reg_2_Out,
    // output  wire [15:0] Reg_3_Out,
    // output  wire [15:0] Reg_4_Out,
    // output  wire [15:0] Reg_5_Out,
    // output  wire [15:0] Reg_6_Out,
    // output  wire [15:0] Reg_7_Out,
    output  wire [15:0] last_alu_result 
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
    wire en_register_memory;
    wire mux2_sel;
    wire en_m;

    // Multiplexor1 Wires
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

    // Multiplexor2 Wires
    wire [15:0] mux2_out;
    wire        mux2_sel;
    wire [15:0] Reg_M_Out;

    //ALU Wires
    wire [15:0] alu_out;

    assign last_alu_result = Reg_C_Out;

    //Register wires
    wire [15:0] register_memory_out;

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
                               .done1(done1),
                               .done2(done2),
                               .imm_val(imm_val),
                               .en_register_memory(en_register_memory),
                               .mux2_sel(mux2_sel),
                               .en_m(en_m));

    // Register Instances
    register_16 Reg_Inst (.d_in(instruction),
                       .reset(reset),
                       .clk(clk),
                       .en(en_i),
                       .d_out(Reg_Inst_Out));
    
    register_16 Reg_S (.d_in(mux_out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_s),
                    .d_out(Reg_S_Out));
    
    register_16 Reg_C (.d_in(alu_out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_c),
                    .d_out(Reg_C_Out));

    register_16 Reg_0 (.d_in(mux2_out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_0),
                    .d_out(Reg_0_Out));

    register_16 Reg_1 (.d_in(mux2_out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_1),
                    .d_out(Reg_1_Out));

    register_16 Reg_2 (.d_in(mux2_out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_2),
                    .d_out(Reg_2_Out));

    register_16 Reg_3 (.d_in(mux2_out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_3),
                    .d_out(Reg_3_Out));

    register_16 Reg_4 (.d_in(mux2_out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_4),
                    .d_out(Reg_4_Out));

    register_16 Reg_5 (.d_in(mux2_out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_5),
                    .d_out(Reg_5_Out));

    register_16 Reg_6 (.d_in(mux2_out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_6),
                    .d_out(Reg_6_Out));

    register_16 Reg_7 (.d_in(mux2_out),
                    .reset(reset),
                    .clk(clk),
                    .en(en_7),
                    .d_out(Reg_7_Out));

    register_16 Reg_M (.d_in(register_memory_out),
                       .reset(reset),
                       .clk(clk),
                       .en(en_m),
                       .d_out(Reg_M_Out));

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

    mux2 myMux2 (.in_0(Reg_C_Out),
                 .in_1(Reg_M_Out),
                 .mux2_sel(mux2_sel),
                 .mux2_out(mux2_out));
    
    alu myAlu (.A(Reg_S_Out),
               .B(mux_out),
               .Sel(sel),
               .ALUOut(alu_out));

    register_memory myRegisterMemory (.clk(clk),
                                      .instruction(instruction),
                                      .Reg_0(Reg_0_Out),
                                      .Reg_1(Reg_1_Out),
                                      .Reg_2(Reg_2_Out),
                                      .Reg_3(Reg_3_Out),
                                      .Reg_4(Reg_4_Out),
                                      .Reg_5(Reg_5_Out),
                                      .Reg_6(Reg_6_Out),
                                      .Reg_7(Reg_7_Out),
                                      .run(en_register_memory),
                                      .out(register_memory_out));
endmodule
