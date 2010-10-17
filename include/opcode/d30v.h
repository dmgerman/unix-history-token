begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* d30v.h -- Header file for D30V opcode table    Copyright 1997, 1998, 1999, 2000, 2001, 2003 Free Software Foundation, Inc.    Written by Martin Hunt (hunt@cygnus.com), Cygnus Solutions  This file is part of GDB, GAS, and the GNU binutils.  GDB, GAS, and the GNU binutils are free software; you can redistribute them and/or modify them under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB, GAS, and the GNU binutils are distributed in the hope that they will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this file; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|D30V_H
end_ifndef

begin_define
define|#
directive|define
name|D30V_H
end_define

begin_define
define|#
directive|define
name|NOP
value|0x00F00000
end_define

begin_comment
comment|/* Structure to hold information about predefined registers.  */
end_comment

begin_struct
struct|struct
name|pd_reg
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name to recognize */
name|char
modifier|*
name|pname
decl_stmt|;
comment|/* name to print for this register */
name|int
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|pd_reg
name|pre_defined_registers
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|reg_name_cnt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* the number of control registers */
end_comment

begin_define
define|#
directive|define
name|MAX_CONTROL_REG
value|64
end_define

begin_comment
comment|/* define the format specifiers */
end_comment

begin_define
define|#
directive|define
name|FM00
value|0
end_define

begin_define
define|#
directive|define
name|FM01
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM10
value|0x8000000000000000LL
end_define

begin_define
define|#
directive|define
name|FM11
value|0x8000000080000000LL
end_define

begin_comment
comment|/* define the opcode classes */
end_comment

begin_define
define|#
directive|define
name|BRA
value|0
end_define

begin_define
define|#
directive|define
name|LOGIC
value|1
end_define

begin_define
define|#
directive|define
name|IMEM
value|2
end_define

begin_define
define|#
directive|define
name|IALU1
value|4
end_define

begin_define
define|#
directive|define
name|IALU2
value|5
end_define

begin_comment
comment|/* define the execution condition codes */
end_comment

begin_define
define|#
directive|define
name|ECC_AL
value|0
end_define

begin_comment
comment|/* ALways (default) */
end_comment

begin_define
define|#
directive|define
name|ECC_TX
value|1
end_define

begin_comment
comment|/* F0=True, F1=Don't care */
end_comment

begin_define
define|#
directive|define
name|ECC_FX
value|2
end_define

begin_comment
comment|/* F0=False, F1=Don't care */
end_comment

begin_define
define|#
directive|define
name|ECC_XT
value|3
end_define

begin_comment
comment|/* F0=Don't care, F1=True */
end_comment

begin_define
define|#
directive|define
name|ECC_XF
value|4
end_define

begin_comment
comment|/* F0=Don't care, F1=False */
end_comment

begin_define
define|#
directive|define
name|ECC_TT
value|5
end_define

begin_comment
comment|/* F0=True, F1=True */
end_comment

begin_define
define|#
directive|define
name|ECC_TF
value|6
end_define

begin_comment
comment|/* F0=True, F1=False */
end_comment

begin_define
define|#
directive|define
name|ECC_RESERVED
value|7
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|ECC_MAX
value|ECC_RESERVED
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|d30v_ecc_names
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* condition code table for CMP and CMPU */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|d30v_cc_names
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The opcode table is an array of struct d30v_opcode.  */
end_comment

begin_struct
struct|struct
name|d30v_opcode
block|{
comment|/* The opcode name.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* the opcode */
name|int
name|op1
decl_stmt|;
comment|/* first part, "IALU1" for example */
name|int
name|op2
decl_stmt|;
comment|/* the rest of the opcode */
comment|/* opcode format(s).  These numbers correspond to entries */
comment|/* in the d30v_format_table */
name|unsigned
name|char
name|format
index|[
literal|4
index|]
decl_stmt|;
define|#
directive|define
name|SHORT_M
value|1
define|#
directive|define
name|SHORT_M2
value|5
comment|/* for ld2w and st2w */
define|#
directive|define
name|SHORT_A
value|9
define|#
directive|define
name|SHORT_B1
value|11
define|#
directive|define
name|SHORT_B2
value|12
define|#
directive|define
name|SHORT_B2r
value|13
define|#
directive|define
name|SHORT_B3
value|14
define|#
directive|define
name|SHORT_B3r
value|16
define|#
directive|define
name|SHORT_B3b
value|18
define|#
directive|define
name|SHORT_B3br
value|20
define|#
directive|define
name|SHORT_D1r
value|22
define|#
directive|define
name|SHORT_D2
value|24
define|#
directive|define
name|SHORT_D2r
value|26
define|#
directive|define
name|SHORT_D2Br
value|28
define|#
directive|define
name|SHORT_U
value|30
comment|/* unary SHORT_A.  ABS for example */
define|#
directive|define
name|SHORT_F
value|31
comment|/* SHORT_A with flag registers */
define|#
directive|define
name|SHORT_AF
value|33
comment|/* SHORT_A with only the first register a flag register */
define|#
directive|define
name|SHORT_T
value|35
comment|/* for trap instruction */
define|#
directive|define
name|SHORT_A5
value|36
comment|/* SHORT_A with a 5-bit immediate instead of 6 */
define|#
directive|define
name|SHORT_CMP
value|38
comment|/* special form for CMPcc */
define|#
directive|define
name|SHORT_CMPU
value|40
comment|/* special form for CMPUcc */
define|#
directive|define
name|SHORT_A1
value|42
comment|/* special form of SHORT_A for MACa opcodes where a=1 */
define|#
directive|define
name|SHORT_AA
value|44
comment|/* SHORT_A with the first register an accumulator */
define|#
directive|define
name|SHORT_RA
value|46
comment|/* SHORT_A with the second register an accumulator */
define|#
directive|define
name|SHORT_MODINC
value|48
define|#
directive|define
name|SHORT_MODDEC
value|49
define|#
directive|define
name|SHORT_C1
value|50
define|#
directive|define
name|SHORT_C2
value|51
define|#
directive|define
name|SHORT_UF
value|52
define|#
directive|define
name|SHORT_A2
value|53
define|#
directive|define
name|SHORT_NONE
value|55
comment|/* no operands */
define|#
directive|define
name|SHORT_AR
value|56
comment|/* like SHORT_AA but only accept register as third parameter  */
define|#
directive|define
name|LONG
value|57
define|#
directive|define
name|LONG_U
value|58
comment|/* unary LONG */
define|#
directive|define
name|LONG_Ur
value|59
comment|/* LONG pc-relative */
define|#
directive|define
name|LONG_CMP
value|60
comment|/* special form for CMPcc and CMPUcc */
define|#
directive|define
name|LONG_M
value|61
comment|/* Memory long for ldb, stb */
define|#
directive|define
name|LONG_M2
value|62
comment|/* Memory long for ld2w, st2w */
define|#
directive|define
name|LONG_2
value|63
comment|/* LONG with 2 operands; jmptnz */
define|#
directive|define
name|LONG_2r
value|64
comment|/* LONG with 2 operands; bratnz */
define|#
directive|define
name|LONG_2b
value|65
comment|/* LONG_2 with modifier of 3 */
define|#
directive|define
name|LONG_2br
value|66
comment|/* LONG_2r with modifier of 3 */
define|#
directive|define
name|LONG_D
value|67
comment|/* for DJMPI */
define|#
directive|define
name|LONG_Dr
value|68
comment|/* for DBRAI */
define|#
directive|define
name|LONG_Dbr
value|69
comment|/* for repeati */
comment|/* the execution unit(s) used */
name|int
name|unit
decl_stmt|;
define|#
directive|define
name|EITHER
value|0
define|#
directive|define
name|IU
value|1
define|#
directive|define
name|MU
value|2
define|#
directive|define
name|EITHER_BUT_PREFER_MU
value|3
comment|/* this field is used to decide if two instructions */
comment|/* can be executed in parallel */
name|long
name|flags_used
decl_stmt|;
name|long
name|flags_set
decl_stmt|;
define|#
directive|define
name|FLAG_0
value|(1L<<0)
define|#
directive|define
name|FLAG_1
value|(1L<<1)
define|#
directive|define
name|FLAG_2
value|(1L<<2)
define|#
directive|define
name|FLAG_3
value|(1L<<3)
define|#
directive|define
name|FLAG_4
value|(1L<<4)
comment|/* S (saturation) */
define|#
directive|define
name|FLAG_5
value|(1L<<5)
comment|/* V (overflow) */
define|#
directive|define
name|FLAG_6
value|(1L<<6)
comment|/* VA (accumulated overflow) */
define|#
directive|define
name|FLAG_7
value|(1L<<7)
comment|/* C (carry/borrow) */
define|#
directive|define
name|FLAG_SM
value|(1L<<8)
comment|/* SM (stack mode) */
define|#
directive|define
name|FLAG_RP
value|(1L<<9)
comment|/* RP (repeat enable) */
define|#
directive|define
name|FLAG_CONTROL
value|(1L<<10)
comment|/* control registers */
define|#
directive|define
name|FLAG_A0
value|(1L<<11)
comment|/* A0 */
define|#
directive|define
name|FLAG_A1
value|(1L<<12)
comment|/* A1 */
define|#
directive|define
name|FLAG_JMP
value|(1L<<13)
comment|/* instruction is a branch */
define|#
directive|define
name|FLAG_JSR
value|(1L<<14)
comment|/* subroutine call.  must be aligned */
define|#
directive|define
name|FLAG_MEM
value|(1L<<15)
comment|/* reads/writes memory */
define|#
directive|define
name|FLAG_NOT_WITH_ADDSUBppp
value|(1L<<16)
comment|/* Old meaning: a 2 word 4 byter operation 					   New meaning: operation cannot be  					   combined in parallel with ADD/SUBppp. */
define|#
directive|define
name|FLAG_MUL16
value|(1L<<17)
comment|/* 16 bit multiply */
define|#
directive|define
name|FLAG_MUL32
value|(1L<<18)
comment|/* 32 bit multiply */
define|#
directive|define
name|FLAG_ADDSUBppp
value|(1L<<19)
comment|/* ADDppp or SUBppp */
define|#
directive|define
name|FLAG_DELAY
value|(1L<<20)
comment|/* This is a delayed branch or jump */
define|#
directive|define
name|FLAG_LKR
value|(1L<<21)
comment|/* insn in left slot kills right slot */
define|#
directive|define
name|FLAG_CVVA
value|(FLAG_5|FLAG_6|FLAG_7)
define|#
directive|define
name|FLAG_C
value|FLAG_7
define|#
directive|define
name|FLAG_ALL
value|(FLAG_0 | \ 			 FLAG_1 | \ 			 FLAG_2 | \ 			 FLAG_3 | \ 			 FLAG_4 | \ 			 FLAG_5 | \ 			 FLAG_6 | \ 			 FLAG_7 | \ 			 FLAG_SM | \ 			 FLAG_RP | \ 			 FLAG_CONTROL)
name|int
name|reloc_flag
decl_stmt|;
define|#
directive|define
name|RELOC_PCREL
value|1
define|#
directive|define
name|RELOC_ABS
value|2
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|d30v_opcode
name|d30v_opcode_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|d30v_num_opcodes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The operands table is an array of struct d30v_operand.  */
end_comment

begin_struct
struct|struct
name|d30v_operand
block|{
comment|/* the length of the field */
name|int
name|length
decl_stmt|;
comment|/* The number of significant bits in the operand.  */
name|int
name|bits
decl_stmt|;
comment|/* position relative to Ra */
name|int
name|position
decl_stmt|;
comment|/* syntax flags.  */
name|long
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|d30v_operand
name|d30v_operand_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values defined for the flags field of a struct d30v_operand.  */
end_comment

begin_comment
comment|/* this is the destination register; it will be modified */
end_comment

begin_comment
comment|/* this is used by the optimizer */
end_comment

begin_define
define|#
directive|define
name|OPERAND_DEST
value|(1)
end_define

begin_comment
comment|/* number or symbol */
end_comment

begin_define
define|#
directive|define
name|OPERAND_NUM
value|(2)
end_define

begin_comment
comment|/* address or label */
end_comment

begin_define
define|#
directive|define
name|OPERAND_ADDR
value|(4)
end_define

begin_comment
comment|/* register */
end_comment

begin_define
define|#
directive|define
name|OPERAND_REG
value|(8)
end_define

begin_comment
comment|/* postincrement +  */
end_comment

begin_define
define|#
directive|define
name|OPERAND_PLUS
value|(0x10)
end_define

begin_comment
comment|/* postdecrement -  */
end_comment

begin_define
define|#
directive|define
name|OPERAND_MINUS
value|(0x20)
end_define

begin_comment
comment|/* signed number */
end_comment

begin_define
define|#
directive|define
name|OPERAND_SIGNED
value|(0x40)
end_define

begin_comment
comment|/* this operand must be shifted left by 3 */
end_comment

begin_define
define|#
directive|define
name|OPERAND_SHIFT
value|(0x80)
end_define

begin_comment
comment|/* flag register */
end_comment

begin_define
define|#
directive|define
name|OPERAND_FLAG
value|(0x100)
end_define

begin_comment
comment|/* control register  */
end_comment

begin_define
define|#
directive|define
name|OPERAND_CONTROL
value|(0x200)
end_define

begin_comment
comment|/* accumulator */
end_comment

begin_define
define|#
directive|define
name|OPERAND_ACC
value|(0x400)
end_define

begin_comment
comment|/* @  */
end_comment

begin_define
define|#
directive|define
name|OPERAND_ATSIGN
value|(0x800)
end_define

begin_comment
comment|/* @(  */
end_comment

begin_define
define|#
directive|define
name|OPERAND_ATPAR
value|(0x1000)
end_define

begin_comment
comment|/* predecrement mode '@-sp'  */
end_comment

begin_define
define|#
directive|define
name|OPERAND_ATMINUS
value|(0x2000)
end_define

begin_comment
comment|/* this operand changes the instruction name */
end_comment

begin_comment
comment|/* for example, CPMcc, CMPUcc */
end_comment

begin_define
define|#
directive|define
name|OPERAND_NAME
value|(0x4000)
end_define

begin_comment
comment|/* fake operand for mvtsys and mvfsys */
end_comment

begin_define
define|#
directive|define
name|OPERAND_SPECIAL
value|(0x8000)
end_define

begin_comment
comment|/* let the optimizer know that two registers are affected */
end_comment

begin_define
define|#
directive|define
name|OPERAND_2REG
value|(0x10000)
end_define

begin_comment
comment|/* This operand is pc-relative.  Note that repeati can have two immediate    operands, one of which is pcrel, the other (the IMM6U one) is not.  */
end_comment

begin_define
define|#
directive|define
name|OPERAND_PCREL
value|(0x20000)
end_define

begin_comment
comment|/* The format table is an array of struct d30v_format.  */
end_comment

begin_struct
struct|struct
name|d30v_format
block|{
name|int
name|form
decl_stmt|;
comment|/* SHORT_A, LONG, etc */
name|int
name|modifier
decl_stmt|;
comment|/* two bit modifier following opcode */
name|unsigned
name|char
name|operands
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|d30v_format
name|d30v_format_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* an instruction is defined by an opcode and a format */
end_comment

begin_comment
comment|/* for example, "add" has one opcode, but three different */
end_comment

begin_comment
comment|/* formats, 2 SHORT_A forms and a LONG form. */
end_comment

begin_struct
struct|struct
name|d30v_insn
block|{
name|struct
name|d30v_opcode
modifier|*
name|op
decl_stmt|;
comment|/* pointer to an entry in the opcode table */
name|struct
name|d30v_format
modifier|*
name|form
decl_stmt|;
comment|/* pointer to an entry in the format table */
name|int
name|ecc
decl_stmt|;
comment|/* execution condition code */
block|}
struct|;
end_struct

begin_comment
comment|/* an expressionS only has one register type, so we fake it */
end_comment

begin_comment
comment|/* by setting high bits to indicate type */
end_comment

begin_define
define|#
directive|define
name|REGISTER_MASK
value|0xFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* D30V_H */
end_comment

end_unit

