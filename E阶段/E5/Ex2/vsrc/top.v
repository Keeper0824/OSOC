module top(x,en,y,led4,seg0);
  input  [7:0] x;
  input  en;
  output reg [3:0]y;
  output wire led4;
  integer i;
  output reg [7:0] seg0;
  
  assign led4 = (|x);
  always @(x or en) begin
    if (en) begin
      y = 0;
      for( i = 0; i <= 7; i = i+1)
          if(x[i] == 1)  y = i[3:0];
    end
    else  y = 0;
  end
    always @(*) begin
        if (!en || !(|x)) begin
            seg0 = 8'b11111111;  
        end
        else begin
            case (y)
                4'd0: seg0 = 8'b00000011;
                4'd1: seg0 = 8'b10011111;
                4'd2: seg0 = 8'b00100101;
                4'd3: seg0 = 8'b00001101;
                4'd4: seg0 = 8'b10011001;
                4'd5: seg0 = 8'b01001001;
                4'd6: seg0 = 8'b01000001;
                4'd7: seg0 = 8'b00011111;
                default: seg0 = 8'b11111111;
            endcase
        end
    end
endmodule

