begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: lopcodes.h,v 1.142.1.2 2014/10/20 18:32:09 roberto Exp $ ** Opcodes for Lua virtual machine ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lopcodes_h
end_ifndef

begin_define
define|#
directive|define
name|lopcodes_h
end_define

begin_include
include|#
directive|include
file|"llimits.h"
end_include

begin_comment
comment|/*===========================================================================   We assume that instructions are unsigned numbers.   All instructions have an opcode in the first 6 bits.   Instructions can have the following fields: 	`A' : 8 bits 	`B' : 9 bits 	`C' : 9 bits 	'Ax' : 26 bits ('A', 'B', and 'C' together) 	`Bx' : 18 bits (`B' and `C' together) 	`sBx' : signed Bx    A signed argument is represented in excess K; that is, the number   value is the unsigned value minus K. K is exactly the maximum value   for that argument (so that -max is represented by 0, and +max is   represented by 2*max), which is half the maximum for the corresponding   unsigned argument. ===========================================================================*/
end_comment

begin_enum
enum|enum
name|OpMode
block|{
name|iABC
block|,
name|iABx
block|,
name|iAsBx
block|,
name|iAx
block|}
enum|;
end_enum

begin_comment
comment|/* basic instruction format */
end_comment

begin_comment
comment|/* ** size and position of opcode arguments. */
end_comment

begin_define
define|#
directive|define
name|SIZE_C
value|9
end_define

begin_define
define|#
directive|define
name|SIZE_B
value|9
end_define

begin_define
define|#
directive|define
name|SIZE_Bx
value|(SIZE_C + SIZE_B)
end_define

begin_define
define|#
directive|define
name|SIZE_A
value|8
end_define

begin_define
define|#
directive|define
name|SIZE_Ax
value|(SIZE_C + SIZE_B + SIZE_A)
end_define

begin_define
define|#
directive|define
name|SIZE_OP
value|6
end_define

begin_define
define|#
directive|define
name|POS_OP
value|0
end_define

begin_define
define|#
directive|define
name|POS_A
value|(POS_OP + SIZE_OP)
end_define

begin_define
define|#
directive|define
name|POS_C
value|(POS_A + SIZE_A)
end_define

begin_define
define|#
directive|define
name|POS_B
value|(POS_C + SIZE_C)
end_define

begin_define
define|#
directive|define
name|POS_Bx
value|POS_C
end_define

begin_define
define|#
directive|define
name|POS_Ax
value|POS_A
end_define

begin_comment
comment|/* ** limits for opcode arguments. ** we use (signed) int to manipulate most arguments, ** so they must fit in LUAI_BITSINT-1 bits (-1 for sign) */
end_comment

begin_if
if|#
directive|if
name|SIZE_Bx
operator|<
name|LUAI_BITSINT
operator|-
literal|1
end_if

begin_define
define|#
directive|define
name|MAXARG_Bx
value|((1<<SIZE_Bx)-1)
end_define

begin_define
define|#
directive|define
name|MAXARG_sBx
value|(MAXARG_Bx>>1)
end_define

begin_comment
comment|/* `sBx' is signed */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXARG_Bx
value|MAX_INT
end_define

begin_define
define|#
directive|define
name|MAXARG_sBx
value|MAX_INT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SIZE_Ax
operator|<
name|LUAI_BITSINT
operator|-
literal|1
end_if

begin_define
define|#
directive|define
name|MAXARG_Ax
value|((1<<SIZE_Ax)-1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXARG_Ax
value|MAX_INT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAXARG_A
value|((1<<SIZE_A)-1)
end_define

begin_define
define|#
directive|define
name|MAXARG_B
value|((1<<SIZE_B)-1)
end_define

begin_define
define|#
directive|define
name|MAXARG_C
value|((1<<SIZE_C)-1)
end_define

begin_comment
comment|/* creates a mask with `n' 1 bits at position `p' */
end_comment

begin_define
define|#
directive|define
name|MASK1
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((~((~(Instruction)0)<<(n)))<<(p))
end_define

begin_comment
comment|/* creates a mask with `n' 0 bits at position `p' */
end_comment

begin_define
define|#
directive|define
name|MASK0
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|(~MASK1(n,p))
end_define

begin_comment
comment|/* ** the following macros help to manipulate instructions */
end_comment

begin_define
define|#
directive|define
name|GET_OPCODE
parameter_list|(
name|i
parameter_list|)
value|(cast(OpCode, ((i)>>POS_OP)& MASK1(SIZE_OP,0)))
end_define

begin_define
define|#
directive|define
name|SET_OPCODE
parameter_list|(
name|i
parameter_list|,
name|o
parameter_list|)
value|((i) = (((i)&MASK0(SIZE_OP,POS_OP)) | \ 		((cast(Instruction, o)<<POS_OP)&MASK1(SIZE_OP,POS_OP))))
end_define

begin_define
define|#
directive|define
name|getarg
parameter_list|(
name|i
parameter_list|,
name|pos
parameter_list|,
name|size
parameter_list|)
value|(cast(int, ((i)>>pos)& MASK1(size,0)))
end_define

begin_define
define|#
directive|define
name|setarg
parameter_list|(
name|i
parameter_list|,
name|v
parameter_list|,
name|pos
parameter_list|,
name|size
parameter_list|)
value|((i) = (((i)&MASK0(size,pos)) | \                 ((cast(Instruction, v)<<pos)&MASK1(size,pos))))
end_define

begin_define
define|#
directive|define
name|GETARG_A
parameter_list|(
name|i
parameter_list|)
value|getarg(i, POS_A, SIZE_A)
end_define

begin_define
define|#
directive|define
name|SETARG_A
parameter_list|(
name|i
parameter_list|,
name|v
parameter_list|)
value|setarg(i, v, POS_A, SIZE_A)
end_define

begin_define
define|#
directive|define
name|GETARG_B
parameter_list|(
name|i
parameter_list|)
value|getarg(i, POS_B, SIZE_B)
end_define

begin_define
define|#
directive|define
name|SETARG_B
parameter_list|(
name|i
parameter_list|,
name|v
parameter_list|)
value|setarg(i, v, POS_B, SIZE_B)
end_define

begin_define
define|#
directive|define
name|GETARG_C
parameter_list|(
name|i
parameter_list|)
value|getarg(i, POS_C, SIZE_C)
end_define

begin_define
define|#
directive|define
name|SETARG_C
parameter_list|(
name|i
parameter_list|,
name|v
parameter_list|)
value|setarg(i, v, POS_C, SIZE_C)
end_define

begin_define
define|#
directive|define
name|GETARG_Bx
parameter_list|(
name|i
parameter_list|)
value|getarg(i, POS_Bx, SIZE_Bx)
end_define

begin_define
define|#
directive|define
name|SETARG_Bx
parameter_list|(
name|i
parameter_list|,
name|v
parameter_list|)
value|setarg(i, v, POS_Bx, SIZE_Bx)
end_define

begin_define
define|#
directive|define
name|GETARG_Ax
parameter_list|(
name|i
parameter_list|)
value|getarg(i, POS_Ax, SIZE_Ax)
end_define

begin_define
define|#
directive|define
name|SETARG_Ax
parameter_list|(
name|i
parameter_list|,
name|v
parameter_list|)
value|setarg(i, v, POS_Ax, SIZE_Ax)
end_define

begin_define
define|#
directive|define
name|GETARG_sBx
parameter_list|(
name|i
parameter_list|)
value|(GETARG_Bx(i)-MAXARG_sBx)
end_define

begin_define
define|#
directive|define
name|SETARG_sBx
parameter_list|(
name|i
parameter_list|,
name|b
parameter_list|)
value|SETARG_Bx((i),cast(unsigned int, (b)+MAXARG_sBx))
end_define

begin_define
define|#
directive|define
name|CREATE_ABC
parameter_list|(
name|o
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|((cast(Instruction, o)<<POS_OP) \ 			| (cast(Instruction, a)<<POS_A) \ 			| (cast(Instruction, b)<<POS_B) \ 			| (cast(Instruction, c)<<POS_C))
end_define

begin_define
define|#
directive|define
name|CREATE_ABx
parameter_list|(
name|o
parameter_list|,
name|a
parameter_list|,
name|bc
parameter_list|)
value|((cast(Instruction, o)<<POS_OP) \ 			| (cast(Instruction, a)<<POS_A) \ 			| (cast(Instruction, bc)<<POS_Bx))
end_define

begin_define
define|#
directive|define
name|CREATE_Ax
parameter_list|(
name|o
parameter_list|,
name|a
parameter_list|)
value|((cast(Instruction, o)<<POS_OP) \ 			| (cast(Instruction, a)<<POS_Ax))
end_define

begin_comment
comment|/* ** Macros to operate RK indices */
end_comment

begin_comment
comment|/* this bit 1 means constant (0 means register) */
end_comment

begin_define
define|#
directive|define
name|BITRK
value|(1<< (SIZE_B - 1))
end_define

begin_comment
comment|/* test whether value is a constant */
end_comment

begin_define
define|#
directive|define
name|ISK
parameter_list|(
name|x
parameter_list|)
value|((x)& BITRK)
end_define

begin_comment
comment|/* gets the index of the constant */
end_comment

begin_define
define|#
directive|define
name|INDEXK
parameter_list|(
name|r
parameter_list|)
value|((int)(r)& ~BITRK)
end_define

begin_define
define|#
directive|define
name|MAXINDEXRK
value|(BITRK - 1)
end_define

begin_comment
comment|/* code a constant index as a RK value */
end_comment

begin_define
define|#
directive|define
name|RKASK
parameter_list|(
name|x
parameter_list|)
value|((x) | BITRK)
end_define

begin_comment
comment|/* ** invalid register that fits in 8 bits */
end_comment

begin_define
define|#
directive|define
name|NO_REG
value|MAXARG_A
end_define

begin_comment
comment|/* ** R(x) - register ** Kst(x) - constant (in constant table) ** RK(x) == if ISK(x) then Kst(INDEXK(x)) else R(x) */
end_comment

begin_comment
comment|/* ** grep "ORDER OP" if you change these enums */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/*---------------------------------------------------------------------- name		args	description ------------------------------------------------------------------------*/
name|OP_MOVE
block|,
comment|/*	A B	R(A) := R(B)					*/
name|OP_LOADK
block|,
comment|/*	A Bx	R(A) := Kst(Bx)					*/
name|OP_LOADKX
block|,
comment|/*	A 	R(A) := Kst(extra arg)				*/
name|OP_LOADBOOL
block|,
comment|/*	A B C	R(A) := (Bool)B; if (C) pc++			*/
name|OP_LOADNIL
block|,
comment|/*	A B	R(A), R(A+1), ..., R(A+B) := nil		*/
name|OP_GETUPVAL
block|,
comment|/*	A B	R(A) := UpValue[B]				*/
name|OP_GETTABUP
block|,
comment|/*	A B C	R(A) := UpValue[B][RK(C)]			*/
name|OP_GETTABLE
block|,
comment|/*	A B C	R(A) := R(B)[RK(C)]				*/
name|OP_SETTABUP
block|,
comment|/*	A B C	UpValue[A][RK(B)] := RK(C)			*/
name|OP_SETUPVAL
block|,
comment|/*	A B	UpValue[B] := R(A)				*/
name|OP_SETTABLE
block|,
comment|/*	A B C	R(A)[RK(B)] := RK(C)				*/
name|OP_NEWTABLE
block|,
comment|/*	A B C	R(A) := {} (size = B,C)				*/
name|OP_SELF
block|,
comment|/*	A B C	R(A+1) := R(B); R(A) := R(B)[RK(C)]		*/
name|OP_ADD
block|,
comment|/*	A B C	R(A) := RK(B) + RK(C)				*/
name|OP_SUB
block|,
comment|/*	A B C	R(A) := RK(B) - RK(C)				*/
name|OP_MUL
block|,
comment|/*	A B C	R(A) := RK(B) * RK(C)				*/
name|OP_DIV
block|,
comment|/*	A B C	R(A) := RK(B) / RK(C)				*/
name|OP_MOD
block|,
comment|/*	A B C	R(A) := RK(B) % RK(C)				*/
name|OP_POW
block|,
comment|/*	A B C	R(A) := RK(B) ^ RK(C)				*/
name|OP_UNM
block|,
comment|/*	A B	R(A) := -R(B)					*/
name|OP_NOT
block|,
comment|/*	A B	R(A) := not R(B)				*/
name|OP_LEN
block|,
comment|/*	A B	R(A) := length of R(B)				*/
name|OP_CONCAT
block|,
comment|/*	A B C	R(A) := R(B).. ... ..R(C)			*/
name|OP_JMP
block|,
comment|/*	A sBx	pc+=sBx; if (A) close all upvalues>= R(A - 1)	*/
name|OP_EQ
block|,
comment|/*	A B C	if ((RK(B) == RK(C)) ~= A) then pc++		*/
name|OP_LT
block|,
comment|/*	A B C	if ((RK(B)<  RK(C)) ~= A) then pc++		*/
name|OP_LE
block|,
comment|/*	A B C	if ((RK(B)<= RK(C)) ~= A) then pc++		*/
name|OP_TEST
block|,
comment|/*	A C	if not (R(A)<=> C) then pc++			*/
name|OP_TESTSET
block|,
comment|/*	A B C	if (R(B)<=> C) then R(A) := R(B) else pc++	*/
name|OP_CALL
block|,
comment|/*	A B C	R(A), ... ,R(A+C-2) := R(A)(R(A+1), ... ,R(A+B-1)) */
name|OP_TAILCALL
block|,
comment|/*	A B C	return R(A)(R(A+1), ... ,R(A+B-1))		*/
name|OP_RETURN
block|,
comment|/*	A B	return R(A), ... ,R(A+B-2)	(see note)	*/
name|OP_FORLOOP
block|,
comment|/*	A sBx	R(A)+=R(A+2); 			if R(A)<?= R(A+1) then { pc+=sBx; R(A+3)=R(A) }*/
name|OP_FORPREP
block|,
comment|/*	A sBx	R(A)-=R(A+2); pc+=sBx				*/
name|OP_TFORCALL
block|,
comment|/*	A C	R(A+3), ... ,R(A+2+C) := R(A)(R(A+1), R(A+2));	*/
name|OP_TFORLOOP
block|,
comment|/*	A sBx	if R(A+1) ~= nil then { R(A)=R(A+1); pc += sBx }*/
name|OP_SETLIST
block|,
comment|/*	A B C	R(A)[(C-1)*FPF+i] := R(A+i), 1<= i<= B	*/
name|OP_CLOSURE
block|,
comment|/*	A Bx	R(A) := closure(KPROTO[Bx])			*/
name|OP_VARARG
block|,
comment|/*	A B	R(A), R(A+1), ..., R(A+B-2) = vararg		*/
name|OP_EXTRAARG
comment|/*	Ax	extra (larger) argument for previous opcode	*/
block|}
name|OpCode
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NUM_OPCODES
value|(cast(int, OP_EXTRAARG) + 1)
end_define

begin_comment
comment|/*===========================================================================   Notes:   (*) In OP_CALL, if (B == 0) then B = top. If (C == 0), then `top' is   set to last_result+1, so next open instruction (OP_CALL, OP_RETURN,   OP_SETLIST) may use `top'.    (*) In OP_VARARG, if (B == 0) then use actual number of varargs and   set top (like in OP_CALL with C == 0).    (*) In OP_RETURN, if (B == 0) then return up to `top'.    (*) In OP_SETLIST, if (B == 0) then B = `top'; if (C == 0) then next   'instruction' is EXTRAARG(real C).    (*) In OP_LOADKX, the next 'instruction' is always EXTRAARG.    (*) For comparisons, A specifies what condition the test should accept   (true or false).    (*) All `skips' (pc++) assume that next instruction is a jump.  ===========================================================================*/
end_comment

begin_comment
comment|/* ** masks for instruction properties. The format is: ** bits 0-1: op mode ** bits 2-3: C arg mode ** bits 4-5: B arg mode ** bit 6: instruction set register A ** bit 7: operator is a test (next instruction must be a jump) */
end_comment

begin_enum
enum|enum
name|OpArgMask
block|{
name|OpArgN
block|,
comment|/* argument is not used */
name|OpArgU
block|,
comment|/* argument is used */
name|OpArgR
block|,
comment|/* argument is a register or a jump offset */
name|OpArgK
comment|/* argument is a constant or register/constant */
block|}
enum|;
end_enum

begin_decl_stmt
name|LUAI_DDEC
specifier|const
name|lu_byte
name|luaP_opmodes
index|[
name|NUM_OPCODES
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|getOpMode
parameter_list|(
name|m
parameter_list|)
value|(cast(enum OpMode, luaP_opmodes[m]& 3))
end_define

begin_define
define|#
directive|define
name|getBMode
parameter_list|(
name|m
parameter_list|)
value|(cast(enum OpArgMask, (luaP_opmodes[m]>> 4)& 3))
end_define

begin_define
define|#
directive|define
name|getCMode
parameter_list|(
name|m
parameter_list|)
value|(cast(enum OpArgMask, (luaP_opmodes[m]>> 2)& 3))
end_define

begin_define
define|#
directive|define
name|testAMode
parameter_list|(
name|m
parameter_list|)
value|(luaP_opmodes[m]& (1<< 6))
end_define

begin_define
define|#
directive|define
name|testTMode
parameter_list|(
name|m
parameter_list|)
value|(luaP_opmodes[m]& (1<< 7))
end_define

begin_decl_stmt
name|LUAI_DDEC
specifier|const
name|char
modifier|*
specifier|const
name|luaP_opnames
index|[
name|NUM_OPCODES
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* opcode names */
end_comment

begin_comment
comment|/* number of list items to accumulate before a SETLIST instruction */
end_comment

begin_define
define|#
directive|define
name|LFIELDS_PER_FLUSH
value|50
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

