module top(
	input [7:0] x,
	input en,
	output reg [2:0] y,
	output wire led4,
	output reg [7:0] seg0
);
	integer i;
	assign led4 = (|x)&&en;
	always @(*)begin
		if(!en)
			y=0;
		else begin
			y=0;
			for(i=0;i<8;i++)begin
				if(x[i])
					y=i[2:0];
			end
		end
	end
	always@(*)begin
        if(!en||!(|x))begin
            seg0 = 8'b11111111;  
        end
        else begin
            case(y)
		3'd0: seg0 = 8'b00000011;
                3'd1: seg0 = 8'b10011111;
                3'd2: seg0 = 8'b00100101;
                3'd3: seg0 = 8'b00001101;
                3'd4: seg0 = 8'b10011001;
                3'd5: seg0 = 8'b01001001;
                3'd6: seg0 = 8'b01000001;
                3'd7: seg0 = 8'b00011111;
                default: seg0 = 8'b11111111;
            endcase
        end
    end
endmodule
	
	

