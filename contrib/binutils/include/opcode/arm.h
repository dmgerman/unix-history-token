begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ARM opcode list.    Copyright 1989, 1991 Free Software Foundation, Inc.  This file is part of GDB and GAS.  GDB and GAS are free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB and GAS are distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB or GAS; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* types of instruction (encoded in bits 26 and 27 of the instruction) */
end_comment

begin_define
define|#
directive|define
name|TYPE_ARITHMETIC
value|0
end_define

begin_define
define|#
directive|define
name|TYPE_LDR_STR
value|1
end_define

begin_define
define|#
directive|define
name|TYPE_BLOCK_BRANCH
value|2
end_define

begin_define
define|#
directive|define
name|TYPE_SWI
value|3
end_define

begin_comment
comment|/* bit 25 decides whether an instruction is a block move or a branch */
end_comment

begin_define
define|#
directive|define
name|SUBTYPE_BLOCK
value|0
end_define

begin_define
define|#
directive|define
name|SUBTYPE_BRANCH
value|1
end_define

begin_comment
comment|/* codes to distinguish the arithmetic instructions */
end_comment

begin_define
define|#
directive|define
name|OPCODE_AND
value|0
end_define

begin_define
define|#
directive|define
name|OPCODE_EOR
value|1
end_define

begin_define
define|#
directive|define
name|OPCODE_SUB
value|2
end_define

begin_define
define|#
directive|define
name|OPCODE_RSB
value|3
end_define

begin_define
define|#
directive|define
name|OPCODE_ADD
value|4
end_define

begin_define
define|#
directive|define
name|OPCODE_ADC
value|5
end_define

begin_define
define|#
directive|define
name|OPCODE_SBC
value|6
end_define

begin_define
define|#
directive|define
name|OPCODE_RSC
value|7
end_define

begin_define
define|#
directive|define
name|OPCODE_TST
value|8
end_define

begin_define
define|#
directive|define
name|OPCODE_TEQ
value|9
end_define

begin_define
define|#
directive|define
name|OPCODE_CMP
value|10
end_define

begin_define
define|#
directive|define
name|OPCODE_CMN
value|11
end_define

begin_define
define|#
directive|define
name|OPCODE_ORR
value|12
end_define

begin_define
define|#
directive|define
name|OPCODE_MOV
value|13
end_define

begin_define
define|#
directive|define
name|OPCODE_BIC
value|14
end_define

begin_define
define|#
directive|define
name|OPCODE_MVN
value|15
end_define

begin_comment
comment|/* condition codes */
end_comment

begin_define
define|#
directive|define
name|COND_EQ
value|0
end_define

begin_define
define|#
directive|define
name|COND_NE
value|1
end_define

begin_define
define|#
directive|define
name|COND_CS
value|2
end_define

begin_define
define|#
directive|define
name|COND_CC
value|3
end_define

begin_define
define|#
directive|define
name|COND_MI
value|4
end_define

begin_define
define|#
directive|define
name|COND_PL
value|5
end_define

begin_define
define|#
directive|define
name|COND_VS
value|6
end_define

begin_define
define|#
directive|define
name|COND_VC
value|7
end_define

begin_define
define|#
directive|define
name|COND_HI
value|8
end_define

begin_define
define|#
directive|define
name|COND_LS
value|9
end_define

begin_define
define|#
directive|define
name|COND_GE
value|10
end_define

begin_define
define|#
directive|define
name|COND_LT
value|11
end_define

begin_define
define|#
directive|define
name|COND_GT
value|12
end_define

begin_define
define|#
directive|define
name|COND_LE
value|13
end_define

begin_define
define|#
directive|define
name|COND_AL
value|14
end_define

begin_define
define|#
directive|define
name|COND_NV
value|15
end_define

begin_comment
comment|/* Describes the format of an ARM machine instruction */
end_comment

begin_struct
struct|struct
name|generic_fmt
block|{
name|unsigned
name|rest
range|:
literal|25
decl_stmt|;
comment|/* the rest of the instruction */
name|unsigned
name|subtype
range|:
literal|1
decl_stmt|;
comment|/* used to decide between block and branch */
name|unsigned
name|type
range|:
literal|2
decl_stmt|;
comment|/* one of TYPE_* */
name|unsigned
name|cond
range|:
literal|4
decl_stmt|;
comment|/* one of COND_* defined above */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arith_fmt
block|{
name|unsigned
name|operand2
range|:
literal|12
decl_stmt|;
comment|/* #nn or rn or rn shift #m or rn shift rm */
name|unsigned
name|dest
range|:
literal|4
decl_stmt|;
comment|/* place where the answer goes */
name|unsigned
name|operand1
range|:
literal|4
decl_stmt|;
comment|/* first operand to instruction */
name|unsigned
name|set
range|:
literal|1
decl_stmt|;
comment|/* == 1 means set processor flags */
name|unsigned
name|opcode
range|:
literal|4
decl_stmt|;
comment|/* one of OPCODE_* defined above */
name|unsigned
name|immed
range|:
literal|1
decl_stmt|;
comment|/* operand2 is an immediate value */
name|unsigned
name|type
range|:
literal|2
decl_stmt|;
comment|/* == TYPE_ARITHMETIC */
name|unsigned
name|cond
range|:
literal|4
decl_stmt|;
comment|/* one of COND_* defined above */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ldr_str_fmt
block|{
name|unsigned
name|offset
range|:
literal|12
decl_stmt|;
comment|/* #nn or rn or rn shift #m */
name|unsigned
name|reg
range|:
literal|4
decl_stmt|;
comment|/* destination for LDR, source for STR */
name|unsigned
name|base
range|:
literal|4
decl_stmt|;
comment|/* base register */
name|unsigned
name|is_load
range|:
literal|1
decl_stmt|;
comment|/* == 1 for LDR */
name|unsigned
name|writeback
range|:
literal|1
decl_stmt|;
comment|/* == 1 means write back (base+offset) into base */
name|unsigned
name|byte
range|:
literal|1
decl_stmt|;
comment|/* == 1 means byte access else word */
name|unsigned
name|up
range|:
literal|1
decl_stmt|;
comment|/* == 1 means add offset else subtract it */
name|unsigned
name|pre_index
range|:
literal|1
decl_stmt|;
comment|/* == 1 means [a,b] form else [a],b form */
name|unsigned
name|immed
range|:
literal|1
decl_stmt|;
comment|/* == 0 means immediate offset */
name|unsigned
name|type
range|:
literal|2
decl_stmt|;
comment|/* == TYPE_LDR_STR */
name|unsigned
name|cond
range|:
literal|4
decl_stmt|;
comment|/* one of COND_* defined above */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|block_fmt
block|{
name|unsigned
name|mask
range|:
literal|16
decl_stmt|;
comment|/* register mask */
name|unsigned
name|base
range|:
literal|4
decl_stmt|;
comment|/* register used as base of move */
name|unsigned
name|is_load
range|:
literal|1
decl_stmt|;
comment|/* == 1 for LDM */
name|unsigned
name|writeback
range|:
literal|1
decl_stmt|;
comment|/* == 1 means update base after move */
name|unsigned
name|set
range|:
literal|1
decl_stmt|;
comment|/* == 1 means set flags in pc if included in mask */
name|unsigned
name|increment
range|:
literal|1
decl_stmt|;
comment|/* == 1 means increment base register */
name|unsigned
name|before
range|:
literal|1
decl_stmt|;
comment|/* == 1 means inc/dec before each move */
name|unsigned
name|is_block
range|:
literal|1
decl_stmt|;
comment|/* == SUBTYPE_BLOCK */
name|unsigned
name|type
range|:
literal|2
decl_stmt|;
comment|/* == TYPE_BLOCK_BRANCH */
name|unsigned
name|cond
range|:
literal|4
decl_stmt|;
comment|/* one of COND_* defined above */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|branch_fmt
block|{
name|unsigned
name|dest
range|:
literal|24
decl_stmt|;
comment|/* destination of the branch */
name|unsigned
name|link
range|:
literal|1
decl_stmt|;
comment|/* branch with link (function call) */
name|unsigned
name|is_branch
range|:
literal|1
decl_stmt|;
comment|/* == SUBTYPE_BRANCH */
name|unsigned
name|type
range|:
literal|2
decl_stmt|;
comment|/* == TYPE_BLOCK_BRANCH */
name|unsigned
name|cond
range|:
literal|4
decl_stmt|;
comment|/* one of COND_* defined above */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ROUND_N
value|0
end_define

begin_define
define|#
directive|define
name|ROUND_P
value|1
end_define

begin_define
define|#
directive|define
name|ROUND_M
value|2
end_define

begin_define
define|#
directive|define
name|ROUND_Z
value|3
end_define

begin_define
define|#
directive|define
name|FLOAT2_MVF
value|0
end_define

begin_define
define|#
directive|define
name|FLOAT2_MNF
value|1
end_define

begin_define
define|#
directive|define
name|FLOAT2_ABS
value|2
end_define

begin_define
define|#
directive|define
name|FLOAT2_RND
value|3
end_define

begin_define
define|#
directive|define
name|FLOAT2_SQT
value|4
end_define

begin_define
define|#
directive|define
name|FLOAT2_LOG
value|5
end_define

begin_define
define|#
directive|define
name|FLOAT2_LGN
value|6
end_define

begin_define
define|#
directive|define
name|FLOAT2_EXP
value|7
end_define

begin_define
define|#
directive|define
name|FLOAT2_SIN
value|8
end_define

begin_define
define|#
directive|define
name|FLOAT2_COS
value|9
end_define

begin_define
define|#
directive|define
name|FLOAT2_TAN
value|10
end_define

begin_define
define|#
directive|define
name|FLOAT2_ASN
value|11
end_define

begin_define
define|#
directive|define
name|FLOAT2_ACS
value|12
end_define

begin_define
define|#
directive|define
name|FLOAT2_ATN
value|13
end_define

begin_define
define|#
directive|define
name|FLOAT3_ADF
value|0
end_define

begin_define
define|#
directive|define
name|FLOAT3_MUF
value|1
end_define

begin_define
define|#
directive|define
name|FLOAT3_SUF
value|2
end_define

begin_define
define|#
directive|define
name|FLOAT3_RSF
value|3
end_define

begin_define
define|#
directive|define
name|FLOAT3_DVF
value|4
end_define

begin_define
define|#
directive|define
name|FLOAT3_RDF
value|5
end_define

begin_define
define|#
directive|define
name|FLOAT3_POW
value|6
end_define

begin_define
define|#
directive|define
name|FLOAT3_RPW
value|7
end_define

begin_define
define|#
directive|define
name|FLOAT3_RMF
value|8
end_define

begin_define
define|#
directive|define
name|FLOAT3_FML
value|9
end_define

begin_define
define|#
directive|define
name|FLOAT3_FDV
value|10
end_define

begin_define
define|#
directive|define
name|FLOAT3_FRD
value|11
end_define

begin_define
define|#
directive|define
name|FLOAT3_POL
value|12
end_define

begin_struct
struct|struct
name|float2_fmt
block|{
name|unsigned
name|operand2
range|:
literal|3
decl_stmt|;
comment|/* second operand */
name|unsigned
name|immed
range|:
literal|1
decl_stmt|;
comment|/* == 1 if second operand is a constant */
name|unsigned
name|pad1
range|:
literal|1
decl_stmt|;
comment|/* == 0 */
name|unsigned
name|rounding
range|:
literal|2
decl_stmt|;
comment|/* ROUND_* */
name|unsigned
name|is_double
range|:
literal|1
decl_stmt|;
comment|/* == 1 if precision is double (only if not extended) */
name|unsigned
name|pad2
range|:
literal|4
decl_stmt|;
comment|/* == 1 */
name|unsigned
name|dest
range|:
literal|3
decl_stmt|;
comment|/* destination */
name|unsigned
name|is_2_op
range|:
literal|1
decl_stmt|;
comment|/* == 1 if 2 operand ins */
name|unsigned
name|operand1
range|:
literal|3
decl_stmt|;
comment|/* first operand (only of is_2_op == 0) */
name|unsigned
name|is_extended
range|:
literal|1
decl_stmt|;
comment|/* == 1 if precision is extended */
name|unsigned
name|opcode
range|:
literal|4
decl_stmt|;
comment|/* FLOAT2_* or FLOAT3_* depending on is_2_op */
name|unsigned
name|must_be_2
range|:
literal|2
decl_stmt|;
comment|/* == 2 */
name|unsigned
name|type
range|:
literal|2
decl_stmt|;
comment|/* == TYPE_SWI */
name|unsigned
name|cond
range|:
literal|4
decl_stmt|;
comment|/* COND_* */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|swi_fmt
block|{
name|unsigned
name|argument
range|:
literal|24
decl_stmt|;
comment|/* argument to SWI (syscall number) */
name|unsigned
name|must_be_3
range|:
literal|2
decl_stmt|;
comment|/* == 3 */
name|unsigned
name|type
range|:
literal|2
decl_stmt|;
comment|/* == TYPE_SWI */
name|unsigned
name|cond
range|:
literal|4
decl_stmt|;
comment|/* one of COND_* defined above */
block|}
struct|;
end_struct

begin_union
union|union
name|insn_fmt
block|{
name|struct
name|generic_fmt
name|generic
decl_stmt|;
name|struct
name|arith_fmt
name|arith
decl_stmt|;
name|struct
name|ldr_str_fmt
name|ldr_str
decl_stmt|;
name|struct
name|block_fmt
name|block
decl_stmt|;
name|struct
name|branch_fmt
name|branch
decl_stmt|;
name|struct
name|swi_fmt
name|swi
decl_stmt|;
name|unsigned
name|long
name|ins
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|opcode
block|{
name|unsigned
name|long
name|value
decl_stmt|,
name|mask
decl_stmt|;
comment|/* recognise instruction if (op&mask)==value */
name|char
modifier|*
name|assembler
decl_stmt|;
comment|/* how to disassemble this instruction */
block|}
struct|;
end_struct

begin_comment
comment|/* format of the assembler string :        %%			%    %<bitfield>d		print the bitfield in decimal    %<bitfield>x		print the bitfield in hex    %<bitfield>r		print as an ARM register    %<bitfield>f		print a floating point constant if>7 else an fp register    %c			print condition code (always bits 28-31)    %P			print floating point precision in arithmetic insn    %Q			print floating point precision in ldf/stf insn    %R			print floating point rounding mode    %<bitnum>'c		print specified char iff bit is one    %<bitnum>`c		print specified char iff bit is zero    %<bitnum>?ab		print a if bit is one else print b    %p			print 'p' iff bits 12-15 are 15    %o			print operand2 (immediate or register + shift)    %a			print address for ldr/str instruction    %b			print branch destination    %A			print address for ldc/stc/ldf/stf instruction    %m			print register mask for ldm/stm instruction */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|opcode
name|opcodes
index|[]
init|=
block|{
comment|/* ARM instructions */
literal|0x00000090
block|,
literal|0x0fe000f0
block|,
literal|"mul%20's %12-15r, %16-19r, %0-3r"
block|,
literal|0x00200090
block|,
literal|0x0fe000f0
block|,
literal|"mla%20's %12-15r, %16-19r, %0-3r, %8-11r"
block|,
literal|0x00000000
block|,
literal|0x0de00000
block|,
literal|"and%c%20's %12-15r, %16-19r, %o"
block|,
literal|0x00200000
block|,
literal|0x0de00000
block|,
literal|"eor%c%20's %12-15r, %16-19r, %o"
block|,
literal|0x00400000
block|,
literal|0x0de00000
block|,
literal|"sub%c%20's %12-15r, %16-19r, %o"
block|,
literal|0x00600000
block|,
literal|0x0de00000
block|,
literal|"rsb%c%20's %12-15r, %16-19r, %o"
block|,
literal|0x00800000
block|,
literal|0x0de00000
block|,
literal|"add%c%20's %12-15r, %16-19r, %o"
block|,
literal|0x00a00000
block|,
literal|0x0de00000
block|,
literal|"adc%c%20's %12-15r, %16-19r, %o"
block|,
literal|0x00c00000
block|,
literal|0x0de00000
block|,
literal|"sbc%c%20's %12-15r, %16-19r, %o"
block|,
literal|0x00e00000
block|,
literal|0x0de00000
block|,
literal|"rsc%c%20's %12-15r, %16-19r, %o"
block|,
literal|0x01000000
block|,
literal|0x0de00000
block|,
literal|"tst%c%p %16-19r, %o"
block|,
literal|0x01200000
block|,
literal|0x0de00000
block|,
literal|"teq%c%p %16-19r, %o"
block|,
literal|0x01400000
block|,
literal|0x0de00000
block|,
literal|"cmp%c%p %16-19r, %o"
block|,
literal|0x01600000
block|,
literal|0x0de00000
block|,
literal|"cmn%c%p %16-19r, %o"
block|,
literal|0x01800000
block|,
literal|0x0de00000
block|,
literal|"orr%c%20's %12-15r, %16-19r, %o"
block|,
literal|0x01a00000
block|,
literal|0x0de00000
block|,
literal|"mov%c%20's %12-15r, %o"
block|,
literal|0x01c00000
block|,
literal|0x0de00000
block|,
literal|"bic%c%20's %12-15r, %16-19r, %o"
block|,
literal|0x01e00000
block|,
literal|0x0de00000
block|,
literal|"mvn%c%20's %12-15r, %o"
block|,
literal|0x04000000
block|,
literal|0x0c100000
block|,
literal|"str%c%22'b %12-15r, %a"
block|,
literal|0x04100000
block|,
literal|0x0c100000
block|,
literal|"ldr%c%22'b %12-15r, %a"
block|,
literal|0x08000000
block|,
literal|0x0e100000
block|,
literal|"stm%c%23?id%24?ba %16-19r%22`!, %m"
block|,
literal|0x08100000
block|,
literal|0x0e100000
block|,
literal|"ldm%c%23?id%24?ba %16-19r%22`!, %m%22'^"
block|,
literal|0x0a000000
block|,
literal|0x0e000000
block|,
literal|"b%c%24'l %b"
block|,
literal|0x0f000000
block|,
literal|0x0f000000
block|,
literal|"swi%c %0-23x"
block|,
comment|/* Floating point coprocessor instructions */
literal|0x0e000100
block|,
literal|0x0ff08f10
block|,
literal|"adf%c%P%R %12-14f, %16-18f, %0-3f"
block|,
literal|0x0e100100
block|,
literal|0x0ff08f10
block|,
literal|"muf%c%P%R %12-14f, %16-18f, %0-3f"
block|,
literal|0x0e200100
block|,
literal|0x0ff08f10
block|,
literal|"suf%c%P%R %12-14f, %16-18f, %0-3f"
block|,
literal|0x0e300100
block|,
literal|0x0ff08f10
block|,
literal|"rsf%c%P%R %12-14f, %16-18f, %0-3f"
block|,
literal|0x0e400100
block|,
literal|0x0ff08f10
block|,
literal|"dvf%c%P%R %12-14f, %16-18f, %0-3f"
block|,
literal|0x0e500100
block|,
literal|0x0ff08f10
block|,
literal|"rdf%c%P%R %12-14f, %16-18f, %0-3f"
block|,
literal|0x0e600100
block|,
literal|0x0ff08f10
block|,
literal|"pow%c%P%R %12-14f, %16-18f, %0-3f"
block|,
literal|0x0e700100
block|,
literal|0x0ff08f10
block|,
literal|"rpw%c%P%R %12-14f, %16-18f, %0-3f"
block|,
literal|0x0e800100
block|,
literal|0x0ff08f10
block|,
literal|"rmf%c%P%R %12-14f, %16-18f, %0-3f"
block|,
literal|0x0e900100
block|,
literal|0x0ff08f10
block|,
literal|"fml%c%P%R %12-14f, %16-18f, %0-3f"
block|,
literal|0x0ea00100
block|,
literal|0x0ff08f10
block|,
literal|"fdv%c%P%R %12-14f, %16-18f, %0-3f"
block|,
literal|0x0eb00100
block|,
literal|0x0ff08f10
block|,
literal|"frd%c%P%R %12-14f, %16-18f, %0-3f"
block|,
literal|0x0ec00100
block|,
literal|0x0ff08f10
block|,
literal|"pol%c%P%R %12-14f, %16-18f, %0-3f"
block|,
literal|0x0e008100
block|,
literal|0x0ff08f10
block|,
literal|"mvf%c%P%R %12-14f, %0-3f"
block|,
literal|0x0e108100
block|,
literal|0x0ff08f10
block|,
literal|"mnf%c%P%R %12-14f, %0-3f"
block|,
literal|0x0e208100
block|,
literal|0x0ff08f10
block|,
literal|"abs%c%P%R %12-14f, %0-3f"
block|,
literal|0x0e308100
block|,
literal|0x0ff08f10
block|,
literal|"rnd%c%P%R %12-14f, %0-3f"
block|,
literal|0x0e408100
block|,
literal|0x0ff08f10
block|,
literal|"sqt%c%P%R %12-14f, %0-3f"
block|,
literal|0x0e508100
block|,
literal|0x0ff08f10
block|,
literal|"log%c%P%R %12-14f, %0-3f"
block|,
literal|0x0e608100
block|,
literal|0x0ff08f10
block|,
literal|"lgn%c%P%R %12-14f, %0-3f"
block|,
literal|0x0e708100
block|,
literal|0x0ff08f10
block|,
literal|"exp%c%P%R %12-14f, %0-3f"
block|,
literal|0x0e808100
block|,
literal|0x0ff08f10
block|,
literal|"sin%c%P%R %12-14f, %0-3f"
block|,
literal|0x0e908100
block|,
literal|0x0ff08f10
block|,
literal|"cos%c%P%R %12-14f, %0-3f"
block|,
literal|0x0ea08100
block|,
literal|0x0ff08f10
block|,
literal|"tan%c%P%R %12-14f, %0-3f"
block|,
literal|0x0eb08100
block|,
literal|0x0ff08f10
block|,
literal|"asn%c%P%R %12-14f, %0-3f"
block|,
literal|0x0ec08100
block|,
literal|0x0ff08f10
block|,
literal|"acs%c%P%R %12-14f, %0-3f"
block|,
literal|0x0ed08100
block|,
literal|0x0ff08f10
block|,
literal|"atn%c%P%R %12-14f, %0-3f"
block|,
literal|0x0e000110
block|,
literal|0x0ff00f1f
block|,
literal|"flt%c%P%R %16-18f, %12-15r"
block|,
literal|0x0e100110
block|,
literal|0x0fff0f98
block|,
literal|"fix%c%R %12-15r, %0-2f"
block|,
literal|0x0e200110
block|,
literal|0x0fff0fff
block|,
literal|"wfs%c %12-15r"
block|,
literal|0x0e300110
block|,
literal|0x0fff0fff
block|,
literal|"rfs%c %12-15r"
block|,
literal|0x0e400110
block|,
literal|0x0fff0fff
block|,
literal|"wfc%c %12-15r"
block|,
literal|0x0e500110
block|,
literal|0x0fff0fff
block|,
literal|"rfc%c %12-15r"
block|,
literal|0x0e90f110
block|,
literal|0x0ff8fff0
block|,
literal|"cmf%c %16-18f, %0-3f"
block|,
literal|0x0eb0f110
block|,
literal|0x0ff8fff0
block|,
literal|"cnf%c %16-18f, %0-3f"
block|,
literal|0x0ed0f110
block|,
literal|0x0ff8fff0
block|,
literal|"cmfe%c %16-18f, %0-3f"
block|,
literal|0x0ef0f110
block|,
literal|0x0ff8fff0
block|,
literal|"cnfe%c %16-18f, %0-3f"
block|,
literal|0x0c000100
block|,
literal|0x0e100f00
block|,
literal|"stf%c%Q %12-14f, %A"
block|,
literal|0x0c100100
block|,
literal|0x0e100f00
block|,
literal|"ldf%c%Q %12-14f, %A"
block|,
comment|/* Generic coprocessor instructions */
literal|0x0e000000
block|,
literal|0x0f000010
block|,
literal|"cdp%c %8-11d, %20-23d, cr%12-15d, cr%16-19d, cr%0-3d, {%5-7d}"
block|,
literal|0x0e000010
block|,
literal|0x0f100010
block|,
literal|"mrc%c %8-11d, %21-23d, %12-15r, cr%16-19d, cr%0-3d, {%5-7d}"
block|,
literal|0x0e100010
block|,
literal|0x0f100010
block|,
literal|"mcr%c %8-11d, %21-23d, %12-15r, cr%16-19d, cr%0-3d, {%5-7d}"
block|,
literal|0x0c000000
block|,
literal|0x0e100000
block|,
literal|"stc%c%22`l %8-11d, cr%12-15d, %A"
block|,
literal|0x0c100000
block|,
literal|0x0e100000
block|,
literal|"ldc%c%22`l %8-11d, cr%12-15d, %A"
block|,
comment|/* the rest */
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|"undefined instruction %0-31x"
block|, }
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|N_OPCODES
value|(sizeof opcodes / sizeof opcodes[0])
end_define

end_unit

