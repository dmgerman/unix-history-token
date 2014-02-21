begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* cr16.h -- Header file for CR16 opcode and register tables.    Copyright 2007 Free Software Foundation, Inc.    Contributed by M R Swami Reddy     This file is part of GAS, GDB and the GNU binutils.     GAS, GDB, and GNU binutils is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2, or (at your    option) any later version.     GAS, GDB, and GNU binutils are distributed in the hope that they will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CR16_H_
end_ifndef

begin_define
define|#
directive|define
name|_CR16_H_
end_define

begin_comment
comment|/* CR16 core Registers :    The enums are used as indices to CR16 registers table (cr16_regtab).    Therefore, order MUST be preserved.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* 16-bit general purpose registers.  */
name|r0
block|,
name|r1
block|,
name|r2
block|,
name|r3
block|,
name|r4
block|,
name|r5
block|,
name|r6
block|,
name|r7
block|,
name|r8
block|,
name|r9
block|,
name|r10
block|,
name|r11
block|,
name|r12_L
init|=
literal|12
block|,
name|r13_L
init|=
literal|13
block|,
name|ra
init|=
literal|14
block|,
name|sp_L
init|=
literal|15
block|,
comment|/* 32-bit general purpose registers.  */
name|r12
init|=
literal|12
block|,
name|r13
init|=
literal|13
block|,
name|r14
init|=
literal|14
block|,
name|r15
init|=
literal|15
block|,
name|era
init|=
literal|14
block|,
name|sp
init|=
literal|15
block|,
name|RA
block|,
comment|/* Not a register.  */
name|nullregister
block|,
name|MAX_REG
block|}
name|reg
typedef|;
end_typedef

begin_comment
comment|/* CR16 processor registers and special registers :    The enums are used as indices to CR16 processor registers table    (cr16_pregtab). Therefore, order MUST be preserved.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* processor registers.  */
name|dbs
init|=
name|MAX_REG
block|,
name|dsr
block|,
name|dcrl
block|,
name|dcrh
block|,
name|car0l
block|,
name|car0h
block|,
name|car1l
block|,
name|car1h
block|,
name|cfg
block|,
name|psr
block|,
name|intbasel
block|,
name|intbaseh
block|,
name|ispl
block|,
name|isph
block|,
name|uspl
block|,
name|usph
block|,
name|dcr
init|=
name|dcrl
block|,
name|car0
init|=
name|car0l
block|,
name|car1
init|=
name|car1l
block|,
name|intbase
init|=
name|intbasel
block|,
name|isp
init|=
name|ispl
block|,
name|usp
init|=
name|uspl
block|,
comment|/* Not a processor register.  */
name|nullpregister
init|=
name|usph
operator|+
literal|1
block|,
name|MAX_PREG
block|}
name|preg
typedef|;
end_typedef

begin_comment
comment|/* CR16 Register types. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CR16_R_REGTYPE
block|,
comment|/* r<N>      */
name|CR16_RP_REGTYPE
block|,
comment|/* reg pair  */
name|CR16_P_REGTYPE
comment|/* Processor register  */
block|}
name|reg_type
typedef|;
end_typedef

begin_comment
comment|/* CR16 argument types :    The argument types correspond to instructions operands     Argument types :    r - register    rp - register pair    c - constant    i - immediate    idxr - index with register    idxrp - index with register pair    rbase - register base    rpbase - register pair base    pr - processor register */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|arg_r
block|,
name|arg_c
block|,
name|arg_cr
block|,
name|arg_crp
block|,
name|arg_ic
block|,
name|arg_icr
block|,
name|arg_idxr
block|,
name|arg_idxrp
block|,
name|arg_rbase
block|,
name|arg_rpbase
block|,
name|arg_rp
block|,
name|arg_pr
block|,
name|arg_prp
block|,
name|arg_cc
block|,
name|arg_ra
block|,
comment|/* Not an argument.  */
name|nullargs
block|}
name|argtype
typedef|;
end_typedef

begin_comment
comment|/* CR16 operand types:The operand types correspond to instructions operands.*/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dummy
block|,
comment|/* N-bit signed immediate.  */
name|imm3
block|,
name|imm4
block|,
name|imm5
block|,
name|imm6
block|,
name|imm16
block|,
name|imm20
block|,
name|imm32
block|,
comment|/* N-bit unsigned immediate.  */
name|uimm3
block|,
name|uimm3_1
block|,
name|uimm4
block|,
name|uimm4_1
block|,
name|uimm5
block|,
name|uimm16
block|,
name|uimm20
block|,
name|uimm32
block|,
comment|/* N-bit signed displacement.  */
name|disps5
block|,
name|disps17
block|,
name|disps25
block|,
comment|/* N-bit unsigned displacement.  */
name|dispe9
block|,
comment|/* N-bit absolute address.  */
name|abs20
block|,
name|abs24
block|,
comment|/* Register relative.  */
name|rra
block|,
name|rbase
block|,
name|rbase_disps20
block|,
name|rbase_dispe20
block|,
comment|/* Register pair relative.  */
name|rpbase_disps0
block|,
name|rpbase_dispe4
block|,
name|rpbase_disps4
block|,
name|rpbase_disps16
block|,
name|rpbase_disps20
block|,
name|rpbase_dispe20
block|,
comment|/* Register index.  */
name|rindex7_abs20
block|,
name|rindex8_abs20
block|,
comment|/* Register pair index.  */
name|rpindex_disps0
block|,
name|rpindex_disps14
block|,
name|rpindex_disps20
block|,
comment|/* register.  */
name|regr
block|,
comment|/* register pair.  */
name|regp
block|,
comment|/* processor register.  */
name|pregr
block|,
comment|/* processor register 32 bit.  */
name|pregrp
block|,
comment|/* condition code - 4 bit.  */
name|cc
block|,
comment|/* Not an operand.  */
name|nulloperand
block|,
comment|/* Maximum supported operand.  */
name|MAX_OPRD
block|}
name|operand_type
typedef|;
end_typedef

begin_comment
comment|/* CR16 instruction types.  */
end_comment

begin_define
define|#
directive|define
name|NO_TYPE_INS
value|0
end_define

begin_define
define|#
directive|define
name|ARITH_INS
value|1
end_define

begin_define
define|#
directive|define
name|LD_STOR_INS
value|2
end_define

begin_define
define|#
directive|define
name|BRANCH_INS
value|3
end_define

begin_define
define|#
directive|define
name|ARITH_BYTE_INS
value|4
end_define

begin_define
define|#
directive|define
name|SHIFT_INS
value|5
end_define

begin_define
define|#
directive|define
name|BRANCH_NEQ_INS
value|6
end_define

begin_define
define|#
directive|define
name|LD_STOR_INS_INC
value|7
end_define

begin_define
define|#
directive|define
name|STOR_IMM_INS
value|8
end_define

begin_define
define|#
directive|define
name|CSTBIT_INS
value|9
end_define

begin_comment
comment|/* Maximum value supported for instruction types.  */
end_comment

begin_define
define|#
directive|define
name|CR16_INS_MAX
value|(1<< 4)
end_define

begin_comment
comment|/* Mask to record an instruction type.  */
end_comment

begin_define
define|#
directive|define
name|CR16_INS_MASK
value|(CR16_INS_MAX - 1)
end_define

begin_comment
comment|/* Return instruction type, given instruction's attributes.  */
end_comment

begin_define
define|#
directive|define
name|CR16_INS_TYPE
parameter_list|(
name|attr
parameter_list|)
value|((attr)& CR16_INS_MASK)
end_define

begin_comment
comment|/* Indicates whether this instruction has a register list as parameter.  */
end_comment

begin_define
define|#
directive|define
name|REG_LIST
value|CR16_INS_MAX
end_define

begin_comment
comment|/* The operands in binary and assembly are placed in reverse order.    load - (REVERSE_MATCH)/store - (! REVERSE_MATCH).  */
end_comment

begin_define
define|#
directive|define
name|REVERSE_MATCH
value|(1<< 5)
end_define

begin_comment
comment|/* Printing formats, where the instruction prefix isn't consecutive.  */
end_comment

begin_define
define|#
directive|define
name|FMT_1
value|(1<< 9)
end_define

begin_comment
comment|/* 0xF0F00000 */
end_comment

begin_define
define|#
directive|define
name|FMT_2
value|(1<< 10)
end_define

begin_comment
comment|/* 0xFFF0FF00 */
end_comment

begin_define
define|#
directive|define
name|FMT_3
value|(1<< 11)
end_define

begin_comment
comment|/* 0xFFF00F00 */
end_comment

begin_define
define|#
directive|define
name|FMT_4
value|(1<< 12)
end_define

begin_comment
comment|/* 0xFFF0F000 */
end_comment

begin_define
define|#
directive|define
name|FMT_5
value|(1<< 13)
end_define

begin_comment
comment|/* 0xFFF0FFF0 */
end_comment

begin_define
define|#
directive|define
name|FMT_CR16
value|(FMT_1 | FMT_2 | FMT_3 | FMT_4 | FMT_5)
end_define

begin_comment
comment|/* Indicates whether this instruction can be relaxed.  */
end_comment

begin_define
define|#
directive|define
name|RELAXABLE
value|(1<< 14)
end_define

begin_comment
comment|/* Indicates that instruction uses user registers (and not     general-purpose registers) as operands.  */
end_comment

begin_define
define|#
directive|define
name|USER_REG
value|(1<< 15)
end_define

begin_comment
comment|/* Instruction shouldn't allow 'sp' usage.  */
end_comment

begin_define
define|#
directive|define
name|NO_SP
value|(1<< 17)
end_define

begin_comment
comment|/* Instruction shouldn't allow to push a register which is used as a rptr.  */
end_comment

begin_define
define|#
directive|define
name|NO_RPTR
value|(1<< 18)
end_define

begin_comment
comment|/* Maximum operands per instruction.  */
end_comment

begin_define
define|#
directive|define
name|MAX_OPERANDS
value|5
end_define

begin_comment
comment|/* Maximum register name length. */
end_comment

begin_define
define|#
directive|define
name|MAX_REGNAME_LEN
value|10
end_define

begin_comment
comment|/* Maximum instruction length. */
end_comment

begin_define
define|#
directive|define
name|MAX_INST_LEN
value|256
end_define

begin_comment
comment|/* Values defined for the flags field of a struct operand_entry.  */
end_comment

begin_comment
comment|/* Operand must be an unsigned number.  */
end_comment

begin_define
define|#
directive|define
name|OP_UNSIGNED
value|(1<< 0)
end_define

begin_comment
comment|/* Operand must be a signed number.  */
end_comment

begin_define
define|#
directive|define
name|OP_SIGNED
value|(1<< 1)
end_define

begin_comment
comment|/* Operand must be a negative number.  */
end_comment

begin_define
define|#
directive|define
name|OP_NEG
value|(1<< 2)
end_define

begin_comment
comment|/* A special load/stor 4-bit unsigned displacement operand.  */
end_comment

begin_define
define|#
directive|define
name|OP_DEC
value|(1<< 3)
end_define

begin_comment
comment|/* Operand must be an even number.  */
end_comment

begin_define
define|#
directive|define
name|OP_EVEN
value|(1<< 4)
end_define

begin_comment
comment|/* Operand is shifted right.  */
end_comment

begin_define
define|#
directive|define
name|OP_SHIFT
value|(1<< 5)
end_define

begin_comment
comment|/* Operand is shifted right and decremented.  */
end_comment

begin_define
define|#
directive|define
name|OP_SHIFT_DEC
value|(1<< 6)
end_define

begin_comment
comment|/* Operand has reserved escape sequences.  */
end_comment

begin_define
define|#
directive|define
name|OP_ESC
value|(1<< 7)
end_define

begin_comment
comment|/* Operand must be a ABS20 number.  */
end_comment

begin_define
define|#
directive|define
name|OP_ABS20
value|(1<< 8)
end_define

begin_comment
comment|/* Operand must be a ABS24 number.  */
end_comment

begin_define
define|#
directive|define
name|OP_ABS24
value|(1<< 9)
end_define

begin_comment
comment|/* Operand has reserved escape sequences type 1.  */
end_comment

begin_define
define|#
directive|define
name|OP_ESC1
value|(1<< 10)
end_define

begin_comment
comment|/* Single operand description.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Operand type.  */
name|operand_type
name|op_type
decl_stmt|;
comment|/* Operand location within the opcode.  */
name|unsigned
name|int
name|shift
decl_stmt|;
block|}
name|operand_desc
typedef|;
end_typedef

begin_comment
comment|/* Instruction data structure used in instruction table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Name.  */
specifier|const
name|char
modifier|*
name|mnemonic
decl_stmt|;
comment|/* Size (in words).  */
name|unsigned
name|int
name|size
decl_stmt|;
comment|/* Constant prefix (matched by the disassembler).  */
name|unsigned
name|long
name|match
decl_stmt|;
comment|/* ie opcode */
comment|/* Match size (in bits).  */
comment|/* MASK: if( (i& match_bits) == match ) then match */
name|int
name|match_bits
decl_stmt|;
comment|/* Attributes.  */
name|unsigned
name|int
name|flags
decl_stmt|;
comment|/* Operands (always last, so unreferenced operands are initialized).  */
name|operand_desc
name|operands
index|[
name|MAX_OPERANDS
index|]
decl_stmt|;
block|}
name|inst
typedef|;
end_typedef

begin_comment
comment|/* Data structure for a single instruction's arguments (Operands).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Register or base register.  */
name|reg
name|r
decl_stmt|;
comment|/* Register pair register.  */
name|reg
name|rp
decl_stmt|;
comment|/* Index register.  */
name|reg
name|i_r
decl_stmt|;
comment|/* Processor register.  */
name|preg
name|pr
decl_stmt|;
comment|/* Processor register. 32 bit  */
name|preg
name|prp
decl_stmt|;
comment|/* Constant/immediate/absolute value.  */
name|long
name|constant
decl_stmt|;
comment|/* CC code.  */
name|unsigned
name|int
name|cc
decl_stmt|;
comment|/* Scaled index mode.  */
name|unsigned
name|int
name|scale
decl_stmt|;
comment|/* Argument type.  */
name|argtype
name|type
decl_stmt|;
comment|/* Size of the argument (in bits) required to represent.  */
name|int
name|size
decl_stmt|;
comment|/* The type of the expression.  */
name|unsigned
name|char
name|X_op
decl_stmt|;
block|}
name|argument
typedef|;
end_typedef

begin_comment
comment|/* Internal structure to hold the various entities    corresponding to the current assembling instruction.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Number of arguments.  */
name|int
name|nargs
decl_stmt|;
comment|/* The argument data structure for storing args (operands).  */
name|argument
name|arg
index|[
name|MAX_OPERANDS
index|]
decl_stmt|;
comment|/* The following fields are required only by CR16-assembler.  */
ifdef|#
directive|ifdef
name|TC_CR16
comment|/* Expression used for setting the fixups (if any).  */
name|expressionS
name|exp
decl_stmt|;
name|bfd_reloc_code_real_type
name|rtype
decl_stmt|;
endif|#
directive|endif
comment|/* TC_CR16 */
comment|/* Instruction size (in bytes).  */
name|int
name|size
decl_stmt|;
block|}
name|ins
typedef|;
end_typedef

begin_comment
comment|/* Structure to hold information about predefined operands.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Size (in bits).  */
name|unsigned
name|int
name|bit_size
decl_stmt|;
comment|/* Argument type.  */
name|argtype
name|arg_type
decl_stmt|;
comment|/* One bit syntax flags.  */
name|int
name|flags
decl_stmt|;
block|}
name|operand_entry
typedef|;
end_typedef

begin_comment
comment|/* Structure to hold trap handler information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Trap name.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Index in dispatch table.  */
name|unsigned
name|int
name|entry
decl_stmt|;
block|}
name|trap_entry
typedef|;
end_typedef

begin_comment
comment|/* Structure to hold information about predefined registers.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Name (string representation).  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Value (enum representation).  */
union|union
block|{
comment|/* Register.  */
name|reg
name|reg_val
decl_stmt|;
comment|/* processor register.  */
name|preg
name|preg_val
decl_stmt|;
block|}
name|value
union|;
comment|/* Register image.  */
name|int
name|image
decl_stmt|;
comment|/* Register type.  */
name|reg_type
name|type
decl_stmt|;
block|}
name|reg_entry
typedef|;
end_typedef

begin_comment
comment|/* CR16 opcode table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|inst
name|cr16_instruction
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|int
name|cr16_num_opcodes
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUMOPCODES
value|cr16_num_opcodes
end_define

begin_comment
comment|/* CR16 operands table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|operand_entry
name|cr16_optab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CR16 registers table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|reg_entry
name|cr16_regtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|int
name|cr16_num_regs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUMREGS
value|cr16_num_regs
end_define

begin_comment
comment|/* CR16 register pair table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|reg_entry
name|cr16_regptab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|int
name|cr16_num_regps
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUMREGPS
value|cr16_num_regps
end_define

begin_comment
comment|/* CR16 processor registers table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|reg_entry
name|cr16_pregtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|int
name|cr16_num_pregs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUMPREGS
value|cr16_num_pregs
end_define

begin_comment
comment|/* CR16 processor registers - 32 bit table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|reg_entry
name|cr16_pregptab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|int
name|cr16_num_pregps
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUMPREGPS
value|cr16_num_pregps
end_define

begin_comment
comment|/* CR16 trap/interrupt table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|trap_entry
name|cr16_traps
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|int
name|cr16_num_traps
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUMTRAPS
value|cr16_num_traps
end_define

begin_comment
comment|/* CR16 CC - codes bit table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cr16_b_cond_tab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|int
name|cr16_num_cc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUMCC
value|cr16_num_cc;
end_define

begin_comment
comment|/* Table of instructions with no operands.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cr16_no_op_insn
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current instruction we're assembling.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|inst
modifier|*
name|instruction
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A macro for representing the instruction "constant" opcode, that is,    the FIXED part of the instruction. The "constant" opcode is represented    as a 32-bit unsigned long, where OPC is expanded (by a left SHIFT)    over that range.  */
end_comment

begin_define
define|#
directive|define
name|BIN
parameter_list|(
name|OPC
parameter_list|,
name|SHIFT
parameter_list|)
value|(OPC<< SHIFT)
end_define

begin_comment
comment|/* Is the current instruction type is TYPE ?  */
end_comment

begin_define
define|#
directive|define
name|IS_INSN_TYPE
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(CR16_INS_TYPE (instruction->flags) == TYPE)
end_define

begin_comment
comment|/* Is the current instruction mnemonic is MNEMONIC ?  */
end_comment

begin_define
define|#
directive|define
name|IS_INSN_MNEMONIC
parameter_list|(
name|MNEMONIC
parameter_list|)
define|\
value|(strcmp (instruction->mnemonic, MNEMONIC) == 0)
end_define

begin_comment
comment|/* Does the current instruction has register list ?  */
end_comment

begin_define
define|#
directive|define
name|INST_HAS_REG_LIST
define|\
value|(instruction->flags& REG_LIST)
end_define

begin_comment
comment|/* Utility macros for string comparison.  */
end_comment

begin_define
define|#
directive|define
name|streq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp (a, b) == 0)
end_define

begin_define
define|#
directive|define
name|strneq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(strncmp (a, b, c) == 0)
end_define

begin_comment
comment|/* Long long type handling.  */
end_comment

begin_comment
comment|/* Replace all appearances of 'long long int' with LONGLONG.  */
end_comment

begin_typedef
typedef|typedef
name|long
name|long
name|int
name|LONGLONG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|ULONGLONG
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CR16_H_ */
end_comment

end_unit

