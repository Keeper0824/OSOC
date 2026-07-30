module top (
    input  wire signed [3:0] A,
    input  wire signed [3:0] B,
    input  wire [2:0] func,

    output wire signed [3:0] out,
    output wire zero,
    output wire overflow,
    output wire carry
);

    wire s0, s1, s2, s3;
    wire s4, s5, s6, s7;

    wire [3:0] add_result;
    wire [3:0] sub_result;
    wire add_carry;
    wire sub_carry;

    wire [3:0] not_result;
    wire [3:0] and_result;
    wire [3:0] or_result;
    wire [3:0] xor_result;
    wire [3:0] less_result;
    wire [3:0] equal_result;

    wire add_overflow;
    wire sub_overflow;
    wire signed_less;
    wire equal;

    assign s0 = ~func[2] & ~func[1] & ~func[0];  
    assign s1 = ~func[2] & ~func[1] & func[0];  
    assign s2 = ~func[2] & func[1] & ~func[0];  
    assign s3 = ~func[2] & func[1] & func[0];  
    assign s4 = func[2] & ~func[1] & ~func[0]; 
    assign s5 = func[2] & ~func[1] & func[0];  
    assign s6 = func[2] & func[1] & ~func[0];  
    assign s7 = func[2] & func[1] & func[0]; 

    addsub4 add_unit (A,B,1'b0,add_result,add_carry);
    addsub4 sub_unit (A,B,1'b1,sub_result,sub_carry);

    assign add_overflow = ~(A[3] ^ B[3]) & (add_result[3] ^ A[3]);
    assign sub_overflow = (A[3] ^ B[3]) & (sub_result[3] ^ A[3]);

    assign not_result = ~A;
    assign and_result = A & B;
    assign or_result  = A | B;
    assign xor_result = A ^ B;

    assign signed_less = sub_result[3] ^ sub_overflow;

    assign less_result = {3'b000, signed_less};

    assign equal = ~(|(A ^ B));
    assign equal_result = {3'b000, equal};

    assign out =
          ({4{s0}} & add_result)
        | ({4{s1}} & sub_result)
        | ({4{s2}} & not_result)
        | ({4{s3}} & and_result)
        | ({4{s4}} & or_result)
        | ({4{s5}} & xor_result)
        | ({4{s6}} & less_result)
        | ({4{s7}} & equal_result);


    assign zero = (s0 | s1) & ~(|out);

    assign overflow = (s0 & add_overflow) | (s1 & sub_overflow);

    assign carry = (s0 & add_carry) | (s1 & sub_carry);

endmodule

/* verilator lint_off DECLFILENAME */
module addsub4 (
    input  wire [3:0] A,
    input  wire [3:0] B,
    input  wire sub,
    output wire [3:0] result,
    output wire carry
);

    wire [3:0] BX;
    wire c1, c2, c3;

    assign BX = B ^ {4{sub}};

    full_adder fa0 (A[0],BX[0],sub,result[0],c1);
    full_adder fa1 (A[1],BX[1],c1,result[1],c2);
    full_adder fa2 (A[2],BX[2],c2,result[2],c3);
    full_adder fa3 (A[3],BX[3],c3,result[3],carry);

endmodule

module full_adder (
    input  wire a,
    input  wire b,
    input  wire cin,
    output wire sum,
    output wire cout
);
    assign sum  = a ^ b ^ cin;
    assign cout = (a & b) | (a & cin) | (b & cin);
endmodule
/* verilator lint_on DECLFILENAME */

