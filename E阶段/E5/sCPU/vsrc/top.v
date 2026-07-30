module top(
    input wire clk,
    input wire resetn,
    output wire [7:0] seg0,
    output wire [7:0] seg1
);

    reg [3:0] pc;
    reg [7:0] R[0:3];
    reg [7:0] out;
    wire [7:0] inst;
    wire [1:0] opcode;

    assign inst = program_rom(pc);
    assign opcode = inst[7:6];

    always @(posedge clk) begin
        if(!resetn) begin
            pc <= 4'd0;
            R[0] <= 8'd10;
            R[1] <= 8'd0;
            R[2] <= 8'd0;
            R[3] <= 8'd0;
            out <= 8'd0;
        end
        else begin
            case(opcode)
                2'b00: begin
                    R[inst[5:4]] <= R[inst[3:2]] + R[inst[1:0]];
                    pc <= pc + 4'd1;
                end

                2'b01: begin
                    out <= R[inst[1:0]];
                    pc <= pc + 4'd1;
                end

                2'b10: begin
                    R[inst[5:4]] <= {4'b0000, inst[3:0]};
                    pc <= pc + 4'd1;
                end

                2'b11: begin
                    if(R[0] != R[inst[1:0]])
                        pc <= inst[5:2];
                    else
                        pc <= pc + 4'd1;
                end
            endcase
        end
    end

    function [7:0] program_rom;
        input [3:0] addr;

        begin
            case(addr)
                4'h0: program_rom = 8'h90; // li r1, 0
                4'h1: program_rom = 8'ha0; // li r2, 0
                4'h2: program_rom = 8'hb1; // li r3, 1
                4'h3: program_rom = 8'h17; // add r1,r1,r3
                4'h4: program_rom = 8'h29; // add r2,r2,r1
                4'h5: program_rom = 8'hcd; // bner0 3,r1
                4'h6: program_rom = 8'h42; // out r2
                4'h7: program_rom = 8'hdf; // bner0 7,r3

                default:
                    program_rom = 8'hdf;
            endcase
        end
    endfunction

assign seg0 = seven_seg(out % 8'd10);
assign seg1 = seven_seg(out / 8'd10);

function [7:0] seven_seg;
    input [7:0] num;

    begin
        case(num)
            8'd0: seven_seg = 8'b00000011;
            8'd1: seven_seg = 8'b10011111;
            8'd2: seven_seg = 8'b00100101;
            8'd3: seven_seg = 8'b00001101;
            8'd4: seven_seg = 8'b10011001;
            8'd5: seven_seg = 8'b01001001;
            8'd6: seven_seg = 8'b01000001;
            8'd7: seven_seg = 8'b00011111;
            8'd8: seven_seg = 8'b00000001;
            8'd9: seven_seg = 8'b00001001;
            default: seven_seg = 8'hff;
        endcase
    end
endfunction

endmodule
