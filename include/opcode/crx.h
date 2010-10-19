begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crx.h -- Header file for CRX opcode and register tables.    Copyright 2004 Free Software Foundation, Inc.    Contributed by Tomer Levi, NSC, Israel.    Originally written for GAS 2.12 by Tomer Levi, NSC, Israel.    Updates, BFDizing, GNUifying and ELF support by Tomer Levi.     This file is part of GAS, GDB and the GNU binutils.     GAS, GDB, and GNU binutils is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2, or (at your    option) any later version.     GAS, GDB, and GNU binutils are distributed in the hope that they will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CRX_H_
end_ifndef

begin_define
define|#
directive|define
name|_CRX_H_
end_define

begin_comment
comment|/* CRX core/debug Registers :    The enums are used as indices to CRX registers table (crx_regtab).    Therefore, order MUST be preserved.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* 32-bit general purpose registers.  */
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
name|r12
block|,
name|r13
block|,
name|r14
block|,
name|r15
block|,
name|ra
block|,
name|sp
block|,
comment|/* 32-bit user registers.  */
name|u0
block|,
name|u1
block|,
name|u2
block|,
name|u3
block|,
name|u4
block|,
name|u5
block|,
name|u6
block|,
name|u7
block|,
name|u8
block|,
name|u9
block|,
name|u10
block|,
name|u11
block|,
name|u12
block|,
name|u13
block|,
name|u14
block|,
name|u15
block|,
name|ura
block|,
name|usp
block|,
comment|/* hi and lo registers.  */
name|hi
block|,
name|lo
block|,
comment|/* hi and lo user registers.  */
name|uhi
block|,
name|ulo
block|,
comment|/* Processor Status Register.  */
name|psr
block|,
comment|/* Interrupt Base Register.  */
name|intbase
block|,
comment|/* Interrupt Stack Pointer Register.  */
name|isp
block|,
comment|/* Configuration Register.  */
name|cfg
block|,
comment|/* Coprocessor Configuration Register.  */
name|cpcfg
block|,
comment|/* Coprocessor Enable Register.  */
name|cen
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
comment|/* CRX Coprocessor registers and special registers :    The enums are used as indices to CRX coprocessor registers table    (crx_copregtab). Therefore, order MUST be preserved.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* Coprocessor registers.  */
name|c0
init|=
name|MAX_REG
block|,
name|c1
block|,
name|c2
block|,
name|c3
block|,
name|c4
block|,
name|c5
block|,
name|c6
block|,
name|c7
block|,
name|c8
block|,
name|c9
block|,
name|c10
block|,
name|c11
block|,
name|c12
block|,
name|c13
block|,
name|c14
block|,
name|c15
block|,
comment|/* Coprocessor special registers.  */
name|cs0
block|,
name|cs1
block|,
name|cs2
block|,
name|cs3
block|,
name|cs4
block|,
name|cs5
block|,
name|cs6
block|,
name|cs7
block|,
name|cs8
block|,
name|cs9
block|,
name|cs10
block|,
name|cs11
block|,
name|cs12
block|,
name|cs13
block|,
name|cs14
block|,
name|cs15
block|,
comment|/* Not a Coprocessor register.  */
name|nullcopregister
block|,
name|MAX_COPREG
block|}
name|copreg
typedef|;
end_typedef

begin_comment
comment|/* CRX Register types. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CRX_R_REGTYPE
block|,
comment|/*  r<N>	  */
name|CRX_U_REGTYPE
block|,
comment|/*  u<N>	  */
name|CRX_C_REGTYPE
block|,
comment|/*  c<N>	  */
name|CRX_CS_REGTYPE
block|,
comment|/*  cs<N>	  */
name|CRX_CFG_REGTYPE
comment|/*  configuration register   */
block|}
name|reg_type
typedef|;
end_typedef

begin_comment
comment|/* CRX argument types :    The argument types correspond to instructions operands     Argument types :    r - register    c - constant    i - immediate    idxr - index register    rbase - register base    s - star ('*')    copr - coprocessor register    copsr - coprocessor special register.  */
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
name|arg_ic
block|,
name|arg_icr
block|,
name|arg_sc
block|,
name|arg_idxr
block|,
name|arg_rbase
block|,
name|arg_copr
block|,
name|arg_copsr
block|,
comment|/* Not an argument.  */
name|nullargs
block|}
name|argtype
typedef|;
end_typedef

begin_comment
comment|/* CRX operand types :    The operand types correspond to instructions operands.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dummy
block|,
comment|/* 4-bit encoded constant.  */
name|cst4
block|,
comment|/* N-bit immediate.  */
name|i16
block|,
name|i32
block|,
comment|/* N-bit unsigned immediate.  */
name|ui3
block|,
name|ui4
block|,
name|ui5
block|,
name|ui16
block|,
comment|/* N-bit signed displacement.  */
name|disps9
block|,
name|disps17
block|,
name|disps25
block|,
name|disps32
block|,
comment|/* N-bit unsigned displacement.  */
name|dispu5
block|,
comment|/* N-bit escaped displacement.  */
name|dispe9
block|,
comment|/* N-bit absolute address.  */
name|abs16
block|,
name|abs32
block|,
comment|/* Register relative.  */
name|rbase
block|,
name|rbase_dispu4
block|,
name|rbase_disps12
block|,
name|rbase_disps16
block|,
name|rbase_disps28
block|,
name|rbase_disps32
block|,
comment|/* Register index.  */
name|rindex_disps6
block|,
name|rindex_disps22
block|,
comment|/* 4-bit genaral-purpose register specifier.  */
name|regr
block|,
comment|/* 8-bit register address space.  */
name|regr8
block|,
comment|/* coprocessor register.  */
name|copregr
block|,
comment|/* coprocessor special register.  */
name|copsregr
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
comment|/* CRX instruction types.  */
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
name|CMPBR_INS
value|5
end_define

begin_define
define|#
directive|define
name|SHIFT_INS
value|6
end_define

begin_define
define|#
directive|define
name|BRANCH_NEQ_INS
value|7
end_define

begin_define
define|#
directive|define
name|LD_STOR_INS_INC
value|8
end_define

begin_define
define|#
directive|define
name|STOR_IMM_INS
value|9
end_define

begin_define
define|#
directive|define
name|CSTBIT_INS
value|10
end_define

begin_define
define|#
directive|define
name|COP_BRANCH_INS
value|11
end_define

begin_define
define|#
directive|define
name|COP_REG_INS
value|12
end_define

begin_define
define|#
directive|define
name|COPS_REG_INS
value|13
end_define

begin_define
define|#
directive|define
name|DCR_BRANCH_INS
value|14
end_define

begin_comment
comment|/* Maximum value supported for instruction types.  */
end_comment

begin_define
define|#
directive|define
name|CRX_INS_MAX
value|(1<< 4)
end_define

begin_comment
comment|/* Mask to record an instruction type.  */
end_comment

begin_define
define|#
directive|define
name|CRX_INS_MASK
value|(CRX_INS_MAX - 1)
end_define

begin_comment
comment|/* Return instruction type, given instruction's attributes.  */
end_comment

begin_define
define|#
directive|define
name|CRX_INS_TYPE
parameter_list|(
name|attr
parameter_list|)
value|((attr)& CRX_INS_MASK)
end_define

begin_comment
comment|/* Indicates whether this instruction has a register list as parameter.  */
end_comment

begin_define
define|#
directive|define
name|REG_LIST
value|CRX_INS_MAX
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
comment|/* Kind of displacement map used DISPU[BWD]4.  */
end_comment

begin_define
define|#
directive|define
name|DISPUB4
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DISPUW4
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|DISPUD4
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|DISPU4MAP
value|(DISPUB4 | DISPUW4 | DISPUD4)
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
name|FMT_CRX
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
comment|/* Indicates that instruction can perfom a cst4 mapping.  */
end_comment

begin_define
define|#
directive|define
name|CST4MAP
value|(1<< 16)
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
comment|/* A special arithmetic 4-bit constant operand.  */
end_comment

begin_define
define|#
directive|define
name|OP_CST4
value|(1<< 2)
end_define

begin_comment
comment|/* A special load/stor 4-bit unsigned displacement operand.  */
end_comment

begin_define
define|#
directive|define
name|OP_DISPU4
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
comment|/* Operand is used only for the upper 64 KB (FFFF0000 to FFFFFFFF).  */
end_comment

begin_define
define|#
directive|define
name|OP_UPPER_64KB
value|(1<< 8)
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
comment|/* Match size (in bits).  */
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
comment|/* Index register.  */
name|reg
name|i_r
decl_stmt|;
comment|/* Coprocessor register.  */
name|copreg
name|cr
decl_stmt|;
comment|/* Constant/immediate/absolute value.  */
name|long
name|constant
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
comment|/* The following fields are required only by CRX-assembler.  */
ifdef|#
directive|ifdef
name|TC_CRX
comment|/* Expression used for setting the fixups (if any).  */
name|expressionS
name|exp
decl_stmt|;
name|bfd_reloc_code_real_type
name|rtype
decl_stmt|;
endif|#
directive|endif
comment|/* TC_CRX */
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
comment|/* Coprocessor register.  */
name|copreg
name|copreg_val
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
comment|/* Structure to hold a cst4 operand mapping.  */
end_comment

begin_comment
comment|/* CRX opcode table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|inst
name|crx_instruction
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|crx_num_opcodes
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUMOPCODES
value|crx_num_opcodes
end_define

begin_comment
comment|/* CRX operands table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|operand_entry
name|crx_optab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CRX registers table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|reg_entry
name|crx_regtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|crx_num_regs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUMREGS
value|crx_num_regs
end_define

begin_comment
comment|/* CRX coprocessor registers table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|reg_entry
name|crx_copregtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|crx_num_copregs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUMCOPREGS
value|crx_num_copregs
end_define

begin_comment
comment|/* CRX trap/interrupt table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|trap_entry
name|crx_traps
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|crx_num_traps
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUMTRAPS
value|crx_num_traps
end_define

begin_comment
comment|/* cst4 operand mapping.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|long
name|cst4_map
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|cst4_maps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Table of instructions with no operands.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|no_op_insn
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
value|(CRX_INS_TYPE(instruction->flags) == TYPE)
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
value|(strcmp(instruction->mnemonic,MNEMONIC) == 0)
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
comment|/* _CRX_H_ */
end_comment

end_unit

