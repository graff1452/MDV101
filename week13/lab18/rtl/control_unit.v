module control_unit (
    input   wire        run,
    input   wire        clk,
    input   wire        reset,
    input   wire [15:0] instruction,
    output  wire        en_s,
    output  wire        en_c,
    output  wire        en_i,
    output  wire        en_0,
    output  wire        en_1,
    output  wire        en_2,
    output  wire        en_3,
    output  wire        en_4,
    output  wire        en_5,
    output  wire        en_6,
    output  wire        en_7,
    output  wire [2:0]  sel,
    output  wire [3:0]  mux_sel,
    output  wire        done,
    output  wire [15:0] imm_val
);
    parameter INITIAL_STATE     = 2'b00; 
    parameter LOAD_STATE        = 2'b01;
    parameter EXECUTION_STATE   = 2'b10;
    parameter STORE_STATE       = 2'b11;

    parameter R_TYPE_INSTRUCTION = 2'b00;
    parameter I_TYPE_INSTRUCTION = 2'b01;
    parameter J_TYPE_INSTRUCTION = 2'b10;

    reg [1:0]   reg_state;
    reg [1:0]   reg_next_state;

    wire [1:0] instruction_format   = instruction[1:0];
    wire [2:0] alu_selection        = instruction[4:2];
    wire [2:0] first_operand        = instruction[15:13];
    wire [2:0] second_operand       = instruction[12:10];
    wire [7:0] immediate_value      = instruction[12:5];

    reg         reg_en_s; 
    reg         reg_en_c; 
    reg         reg_en_i; 
    reg         reg_en_0;
    reg         reg_en_1; 
    reg         reg_en_2; 
    reg         reg_en_3; 
    reg         reg_en_4; 
    reg         reg_en_5; 
    reg         reg_en_6; 
    reg         reg_en_7; 
    reg         reg_done;
    reg [2:0]   reg_sel;
    reg [3:0]   reg_mux_sel;
    reg [15:0]  reg_imm_val;

    assign en_s         = reg_en_s; 
    assign en_c         = reg_en_c; 
    assign en_i         = reg_en_i; 
    assign en_0         = reg_en_0;
    assign en_1         = reg_en_1; 
    assign en_2         = reg_en_2; 
    assign en_3         = reg_en_3; 
    assign en_4         = reg_en_4; 
    assign en_5         = reg_en_5; 
    assign en_6         = reg_en_6; 
    assign en_7         = reg_en_7; 
    assign sel          = reg_sel;
    assign mux_sel      = reg_mux_sel;
    assign done         = reg_done;
    assign imm_val      = reg_imm_val;

    always @(posedge clk or posedge reset) 
    begin
        if (reset)
        begin
            reg_state <= INITIAL_STATE;
        end
        else if (run)
        begin
            reg_state <= reg_next_state;
        end
    end

    always @(*)
    begin
        case (reg_state)
            INITIAL_STATE:      reg_next_state = LOAD_STATE;
            LOAD_STATE:         reg_next_state = EXECUTION_STATE;
            EXECUTION_STATE:    reg_next_state = STORE_STATE;
            STORE_STATE:        reg_next_state = INITIAL_STATE;
            default:            reg_next_state = INITIAL_STATE;
        endcase
    end

    always @(*) begin
        reg_en_s    = 1'b0;
        reg_en_c    = 1'b0;
        reg_en_i    = 1'b0;
        reg_en_0    = 1'b0;
        reg_en_1    = 1'b0;
        reg_en_2    = 1'b0;
        reg_en_3    = 1'b0;
        reg_en_4    = 1'b0;
        reg_en_5    = 1'b0;
        reg_en_6    = 1'b0;
        reg_en_7    = 1'b0;
        reg_sel     = 3'b000;
        reg_mux_sel = 4'b1111;
        reg_done    = 1'b0;
        reg_imm_val = 16'b0;
        
        if (!reset && run) 
        begin
            case (reg_state)
                INITIAL_STATE: 
                begin
                    reg_en_i = 1'b1;
                end
                LOAD_STATE: 
                begin
                    reg_en_s    = 1'b1;
                    reg_mux_sel = {1'b0, first_operand};
                end
                EXECUTION_STATE: 
                case (instruction_format)
                    R_TYPE_INSTRUCTION: 
                    begin
                        reg_mux_sel = {1'b0, second_operand};
                        reg_en_c = 1'b1;
                        reg_sel = alu_selection;
                    end
                    I_TYPE_INSTRUCTION:
                    begin
                        reg_mux_sel = 4'b1000;
                        reg_imm_val = {8'b00000000, immediate_value};
                        reg_en_c = 1'b0;
                        reg_sel = alu_selection;
                    end
                    default:
                    begin
                        reg_mux_sel = {1'b0, second_operand};
                        reg_en_c = 1'b1;
                        reg_sel = alu_selection;
                    end
                endcase
                STORE_STATE: 
                begin
                    case (first_operand) 
                        3'b000: reg_en_0 = 1'b1;
                        3'b001: reg_en_1 = 1'b1;
                        3'b010: reg_en_2 = 1'b1;
                        3'b011: reg_en_3 = 1'b1;
                        3'b100: reg_en_4 = 1'b1;
                        3'b101: reg_en_5 = 1'b1;
                        3'b110: reg_en_6 = 1'b1;
                        3'b111: reg_en_7 = 1'b1;
                    endcase
                    reg_done = 1'b1;
                end
                default: 
                begin
                    reg_en_s    = 1'b0;
                    reg_en_c    = 1'b0;
                    reg_en_i    = 1'b0;
                    reg_en_0    = 1'b0;
                    reg_en_1    = 1'b0;
                    reg_en_2    = 1'b0;
                    reg_en_3    = 1'b0;
                    reg_en_4    = 1'b0;
                    reg_en_5    = 1'b0;
                    reg_en_6    = 1'b0;
                    reg_en_7    = 1'b0;
                    reg_done    = 1'b0;
                    reg_sel     = 3'b000;
                    reg_mux_sel = 4'b1111;
                    reg_imm_val = 16'b0;
                end
            endcase
        end
    end
endmodule
