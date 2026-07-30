module top (
    input clk,ps2_clk,ps2_data,resetn,
    output reg [7:0] seg0,
    output reg [7:0] seg1,
    output reg [7:0] seg2,
    output reg [7:0] seg3,
    output reg [7:0] seg4,
    output reg [7:0] seg5
);
    reg [9:0] buffer;        // ps2_data bits
    reg [3:0] count;  // count ps2_data bits
    reg [2:0] ps2_clk_sync;
    reg [7:0] out;
    reg [7:0] recv_count;
    reg [7:0] scan_to_ascii;
    reg key_down;
    reg break_pending;

    always @(posedge clk) begin
        ps2_clk_sync <=  {ps2_clk_sync[1:0],ps2_clk};
    end

    wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

    always @(posedge clk) begin
        if (resetn == 0) begin // reset
            count <= 0;
            buffer <= 10'd0;
            out <= 8'd0;
            recv_count <= 8'd0;
        end
        else begin
            if (sampling) begin
              if (count == 4'd10) begin
                if ((buffer[0] == 0) &&  // start bit
                    (ps2_data)       &&  // stop bit
                    (^buffer[9:1])) begin      // odd  parity
                    if(buffer[8:1]==8'hf0)begin
                    	break_pending <= 1'b1;
                    	key_down<=0;
                    end
                    else if(break_pending) begin
            			break_pending <= 1'b0;
        			end
                    else if(!key_down)begin
                    	out[7:0]<=buffer[8:1];
                    	recv_count <= recv_count + 8'd1;
                    	key_down <= 1'b1;
                    end
                end
                count <= 0;     // for next
              end else begin
                buffer[count] <= ps2_data;  // store ps2_data
                count <= count + 4'b1;
              end
            end
        end
    end


	always @(*) begin
		case(out)

                8'h45: scan_to_ascii = 8'h30; // 0
                8'h16: scan_to_ascii = 8'h31; // 1
                8'h1e: scan_to_ascii = 8'h32; // 2
                8'h26: scan_to_ascii = 8'h33; // 3
                8'h25: scan_to_ascii = 8'h34; // 4
                8'h2e: scan_to_ascii = 8'h35; // 5
                8'h36: scan_to_ascii = 8'h36; // 6
                8'h3d: scan_to_ascii = 8'h37; // 7
                8'h3e: scan_to_ascii = 8'h38; // 8
                8'h46: scan_to_ascii = 8'h39; // 9


                8'h1c: scan_to_ascii = 8'h61; // a
                8'h32: scan_to_ascii = 8'h62; // b
                8'h21: scan_to_ascii = 8'h63; // c
                8'h23: scan_to_ascii = 8'h64; // d
                8'h24: scan_to_ascii = 8'h65; // e
                8'h2b: scan_to_ascii = 8'h66; // f
                8'h34: scan_to_ascii = 8'h67; // g
                8'h33: scan_to_ascii = 8'h68; // h
                8'h43: scan_to_ascii = 8'h69; // i
                8'h3b: scan_to_ascii = 8'h6a; // j
                8'h42: scan_to_ascii = 8'h6b; // k
                8'h4b: scan_to_ascii = 8'h6c; // l
                8'h3a: scan_to_ascii = 8'h6d; // m
                8'h31: scan_to_ascii = 8'h6e; // n
                8'h44: scan_to_ascii = 8'h6f; // o
                8'h4d: scan_to_ascii = 8'h70; // p
                8'h15: scan_to_ascii = 8'h71; // q
                8'h2d: scan_to_ascii = 8'h72; // r
                8'h1b: scan_to_ascii = 8'h73; // s
                8'h2c: scan_to_ascii = 8'h74; // t
                8'h3c: scan_to_ascii = 8'h75; // u
                8'h2a: scan_to_ascii = 8'h76; // v
                8'h1d: scan_to_ascii = 8'h77; // w
                8'h22: scan_to_ascii = 8'h78; // x
                8'h35: scan_to_ascii = 8'h79; // y
                8'h1a: scan_to_ascii = 8'h7a; // z

                default:
                    scan_to_ascii = 8'h00;
        endcase
		if(!key_down)begin
			seg0=8'hff;
			seg1=8'hff;
			seg2=8'hff;
			seg3=8'hff;
		end
		else begin
            case(out[3:0])
                4'h0: seg0 = 8'b00000011;
                4'h1: seg0 = 8'b10011111;
                4'h2: seg0 = 8'b00100101;
                4'h3: seg0 = 8'b00001101;
                4'h4: seg0 = 8'b10011001;
                4'h5: seg0 = 8'b01001001;
                4'h6: seg0 = 8'b01000001;
                4'h7: seg0 = 8'b00011111;
                4'h8: seg0 = 8'b00000001;
                4'h9: seg0 = 8'b00001001;
                4'ha: seg0 = 8'b00010001;
                4'hb: seg0 = 8'b11000001;
                4'hc: seg0 = 8'b01100011;
                4'hd: seg0 = 8'b10000101;
                4'he: seg0 = 8'b01100001;
                4'hf: seg0 = 8'b01110001;
                default: seg0 = 8'hff;
            endcase
            case(out[7:4])
                4'h0: seg1 = 8'b00000011;
                4'h1: seg1 = 8'b10011111;
                4'h2: seg1 = 8'b00100101;
                4'h3: seg1 = 8'b00001101;
                4'h4: seg1 = 8'b10011001;
                4'h5: seg1 = 8'b01001001;
                4'h6: seg1 = 8'b01000001;
                4'h7: seg1 = 8'b00011111;
                4'h8: seg1 = 8'b00000001;
                4'h9: seg1 = 8'b00001001;
                4'ha: seg1 = 8'b00010001;
                4'hb: seg1 = 8'b11000001;
                4'hc: seg1 = 8'b01100011;
                4'hd: seg1 = 8'b10000101;
                4'he: seg1 = 8'b01100001;
                4'hf: seg1 = 8'b01110001;
                default: seg1 = 8'hff;
            endcase
            case(scan_to_ascii[3:0])
                4'h0: seg2 = 8'b00000011;
                4'h1: seg2 = 8'b10011111;
                4'h2: seg2 = 8'b00100101;
                4'h3: seg2 = 8'b00001101;
                4'h4: seg2 = 8'b10011001;
                4'h5: seg2 = 8'b01001001;
                4'h6: seg2 = 8'b01000001;
                4'h7: seg2 = 8'b00011111;
                4'h8: seg2 = 8'b00000001;
                4'h9: seg2 = 8'b00001001;
                4'ha: seg2 = 8'b00010001;
                4'hb: seg2 = 8'b11000001;
                4'hc: seg2 = 8'b01100011;
                4'hd: seg2 = 8'b10000101;
                4'he: seg2 = 8'b01100001;
                4'hf: seg2 = 8'b01110001;
                default: seg2 = 8'hff;
            endcase
            case(scan_to_ascii[7:4])
                4'h0: seg3 = 8'b00000011;
                4'h1: seg3 = 8'b10011111;
                4'h2: seg3 = 8'b00100101;
                4'h3: seg3 = 8'b00001101;
                4'h4: seg3 = 8'b10011001;
                4'h5: seg3 = 8'b01001001;
                4'h6: seg3 = 8'b01000001;
                4'h7: seg3 = 8'b00011111;
                4'h8: seg3 = 8'b00000001;
                4'h9: seg3 = 8'b00001001;
                4'ha: seg3 = 8'b00010001;
                4'hb: seg3 = 8'b11000001;
                4'hc: seg3 = 8'b01100011;
                4'hd: seg3 = 8'b10000101;
                4'he: seg3 = 8'b01100001;
                4'hf: seg3 = 8'b01110001;
                default: seg3 = 8'hff;
            endcase
            end
            case(recv_count[3:0])
                4'h0: seg4 = 8'b00000011;
                4'h1: seg4 = 8'b10011111;
                4'h2: seg4 = 8'b00100101;
                4'h3: seg4 = 8'b00001101;
                4'h4: seg4 = 8'b10011001;
                4'h5: seg4 = 8'b01001001;
                4'h6: seg4 = 8'b01000001;
                4'h7: seg4 = 8'b00011111;
                4'h8: seg4 = 8'b00000001;
                4'h9: seg4 = 8'b00001001;
                4'ha: seg4 = 8'b00010001;
                4'hb: seg4 = 8'b11000001;
                4'hc: seg4 = 8'b01100011;
                4'hd: seg4 = 8'b10000101;
                4'he: seg4 = 8'b01100001;
                4'hf: seg4 = 8'b01110001;
                default: seg4 = 8'hff;
            endcase
	    	case(recv_count[7:4])
                4'h0: seg5 = 8'b00000011;
                4'h1: seg5 = 8'b10011111;
                4'h2: seg5 = 8'b00100101;
                4'h3: seg5 = 8'b00001101;
                4'h4: seg5 = 8'b10011001;
                4'h5: seg5 = 8'b01001001;
                4'h6: seg5 = 8'b01000001;
                4'h7: seg5 = 8'b00011111;
                4'h8: seg5 = 8'b00000001;
                4'h9: seg5 = 8'b00001001;
                4'ha: seg5 = 8'b00010001;
                4'hb: seg5 = 8'b11000001;
                4'hc: seg5 = 8'b01100011;
                4'hd: seg5 = 8'b10000101;
                4'he: seg5 = 8'b01100001;
                4'hf: seg5 = 8'b01110001;
                default: seg5 = 8'hff;
            endcase
        
    	end
    
endmodule

