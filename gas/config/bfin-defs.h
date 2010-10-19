begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bfin-defs.h ADI Blackfin gas header file    Copyright 2005    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BFIN_PARSE_H
end_ifndef

begin_define
define|#
directive|define
name|BFIN_PARSE_H
end_define

begin_include
include|#
directive|include
file|<bfd.h>
end_include

begin_include
include|#
directive|include
file|"as.h"
end_include

begin_define
define|#
directive|define
name|PCREL
value|1
end_define

begin_define
define|#
directive|define
name|CODE_FRAG_SIZE
value|4096
end_define

begin_comment
comment|/* 1 page.  */
end_comment

begin_comment
comment|/* Definition for all status bits.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|c_0
block|,
name|c_1
block|,
name|c_4
block|,
name|c_2
block|,
name|c_uimm2
block|,
name|c_uimm3
block|,
name|c_imm3
block|,
name|c_pcrel4
block|,
name|c_imm4
block|,
name|c_uimm4s4
block|,
name|c_uimm4
block|,
name|c_uimm4s2
block|,
name|c_negimm5s4
block|,
name|c_imm5
block|,
name|c_uimm5
block|,
name|c_imm6
block|,
name|c_imm7
block|,
name|c_imm8
block|,
name|c_uimm8
block|,
name|c_pcrel8
block|,
name|c_uimm8s4
block|,
name|c_pcrel8s4
block|,
name|c_lppcrel10
block|,
name|c_pcrel10
block|,
name|c_pcrel12
block|,
name|c_imm16s4
block|,
name|c_luimm16
block|,
name|c_imm16
block|,
name|c_huimm16
block|,
name|c_rimm16
block|,
name|c_imm16s2
block|,
name|c_uimm16s4
block|,
name|c_uimm16
block|,
name|c_pcrel24
block|}
name|const_forms_t
typedef|;
end_typedef

begin_comment
comment|/* High-Nibble: group code, low nibble: register code.  */
end_comment

begin_define
define|#
directive|define
name|T_REG_R
value|0x00
end_define

begin_define
define|#
directive|define
name|T_REG_P
value|0x10
end_define

begin_define
define|#
directive|define
name|T_REG_I
value|0x20
end_define

begin_define
define|#
directive|define
name|T_REG_B
value|0x30
end_define

begin_define
define|#
directive|define
name|T_REG_L
value|0x34
end_define

begin_define
define|#
directive|define
name|T_REG_M
value|0x24
end_define

begin_define
define|#
directive|define
name|T_REG_A
value|0x40
end_define

begin_comment
comment|/* All registers above this value don't    belong to a usuable register group.  */
end_comment

begin_define
define|#
directive|define
name|T_NOGROUP
value|0xa0
end_define

begin_comment
comment|/* Flags.  */
end_comment

begin_define
define|#
directive|define
name|F_REG_ALL
value|0x1000
end_define

begin_define
define|#
directive|define
name|F_REG_HIGH
value|0x2000
end_define

begin_comment
comment|/* Half register: high half.  */
end_comment

begin_enum
enum|enum
name|machine_registers
block|{
name|REG_R0
init|=
name|T_REG_R
block|,
name|REG_R1
block|,
name|REG_R2
block|,
name|REG_R3
block|,
name|REG_R4
block|,
name|REG_R5
block|,
name|REG_R6
block|,
name|REG_R7
block|,
name|REG_P0
init|=
name|T_REG_P
block|,
name|REG_P1
block|,
name|REG_P2
block|,
name|REG_P3
block|,
name|REG_P4
block|,
name|REG_P5
block|,
name|REG_SP
block|,
name|REG_FP
block|,
name|REG_I0
init|=
name|T_REG_I
block|,
name|REG_I1
block|,
name|REG_I2
block|,
name|REG_I3
block|,
name|REG_M0
init|=
name|T_REG_M
block|,
name|REG_M1
block|,
name|REG_M2
block|,
name|REG_M3
block|,
name|REG_B0
init|=
name|T_REG_B
block|,
name|REG_B1
block|,
name|REG_B2
block|,
name|REG_B3
block|,
name|REG_L0
init|=
name|T_REG_L
block|,
name|REG_L1
block|,
name|REG_L2
block|,
name|REG_L3
block|,
name|REG_A0x
init|=
name|T_REG_A
block|,
name|REG_A0w
block|,
name|REG_A1x
block|,
name|REG_A1w
block|,
name|REG_ASTAT
init|=
literal|0x46
block|,
name|REG_RETS
init|=
literal|0x47
block|,
name|REG_LC0
init|=
literal|0x60
block|,
name|REG_LT0
block|,
name|REG_LB0
block|,
name|REG_LC1
block|,
name|REG_LT1
block|,
name|REG_LB1
block|,
name|REG_CYCLES
block|,
name|REG_CYCLES2
block|,
name|REG_USP
init|=
literal|0x70
block|,
name|REG_SEQSTAT
block|,
name|REG_SYSCFG
block|,
name|REG_RETI
block|,
name|REG_RETX
block|,
name|REG_RETN
block|,
name|REG_RETE
block|,
name|REG_EMUDAT
block|,
comment|/* These don't have groups.  */
name|REG_sftreset
init|=
name|T_NOGROUP
block|,
name|REG_omode
block|,
name|REG_excause
block|,
name|REG_emucause
block|,
name|REG_idle_req
block|,
name|REG_hwerrcause
block|,
name|REG_A0
init|=
literal|0xc0
block|,
name|REG_A1
block|,
name|REG_CC
block|,
comment|/* Pseudo registers, used only for distinction from symbols.  */
name|REG_RL0
block|,
name|REG_RL1
block|,
name|REG_RL2
block|,
name|REG_RL3
block|,
name|REG_RL4
block|,
name|REG_RL5
block|,
name|REG_RL6
block|,
name|REG_RL7
block|,
name|REG_RH0
block|,
name|REG_RH1
block|,
name|REG_RH2
block|,
name|REG_RH3
block|,
name|REG_RH4
block|,
name|REG_RH5
block|,
name|REG_RH6
block|,
name|REG_RH7
block|,
name|REG_LASTREG
block|}
enum|;
end_enum

begin_comment
comment|/* Status register flags.  */
end_comment

begin_enum
enum|enum
name|statusflags
block|{
name|S_AZ
init|=
literal|0
block|,
name|S_AN
block|,
name|S_AQ
init|=
literal|6
block|,
name|S_AC0
init|=
literal|12
block|,
name|S_AC1
block|,
name|S_AV0
init|=
literal|16
block|,
name|S_AV0S
block|,
name|S_AV1
block|,
name|S_AV1S
block|,
name|S_V
init|=
literal|24
block|,
name|S_VS
init|=
literal|25
block|}
enum|;
end_enum

begin_enum
enum|enum
name|reg_class
block|{
name|rc_dregs_lo
block|,
name|rc_dregs_hi
block|,
name|rc_dregs
block|,
name|rc_dregs_pair
block|,
name|rc_pregs
block|,
name|rc_spfp
block|,
name|rc_dregs_hilo
block|,
name|rc_accum_ext
block|,
name|rc_accum_word
block|,
name|rc_accum
block|,
name|rc_iregs
block|,
name|rc_mregs
block|,
name|rc_bregs
block|,
name|rc_lregs
block|,
name|rc_dpregs
block|,
name|rc_gregs
block|,
name|rc_regs
block|,
name|rc_statbits
block|,
name|rc_ignore_bits
block|,
name|rc_ccstat
block|,
name|rc_counters
block|,
name|rc_dregs2_sysregs1
block|,
name|rc_open
block|,
name|rc_sysregs2
block|,
name|rc_sysregs3
block|,
name|rc_allregs
block|,
name|LIM_REG_CLASSES
block|}
enum|;
end_enum

begin_comment
comment|/* mmod field.  */
end_comment

begin_define
define|#
directive|define
name|M_S2RND
value|1
end_define

begin_define
define|#
directive|define
name|M_T
value|2
end_define

begin_define
define|#
directive|define
name|M_W32
value|3
end_define

begin_define
define|#
directive|define
name|M_FU
value|4
end_define

begin_define
define|#
directive|define
name|M_TFU
value|6
end_define

begin_define
define|#
directive|define
name|M_IS
value|8
end_define

begin_define
define|#
directive|define
name|M_ISS2
value|9
end_define

begin_define
define|#
directive|define
name|M_IH
value|11
end_define

begin_define
define|#
directive|define
name|M_IU
value|12
end_define

begin_comment
comment|/* Register type checking macros.  */
end_comment

begin_define
define|#
directive|define
name|CODE_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|CLASS_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|REG_SAME
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a).regno == (b).regno)
end_define

begin_define
define|#
directive|define
name|REG_EQUAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a).regno& CODE_MASK) == ((b).regno& CODE_MASK))
end_define

begin_define
define|#
directive|define
name|REG_CLASS
parameter_list|(
name|a
parameter_list|)
value|((a.regno)& 0xf0)
end_define

begin_define
define|#
directive|define
name|IS_A1
parameter_list|(
name|a
parameter_list|)
value|((a).regno == REG_A1)
end_define

begin_define
define|#
directive|define
name|IS_H
parameter_list|(
name|a
parameter_list|)
value|((a).regno& F_REG_HIGH ? 1: 0)
end_define

begin_define
define|#
directive|define
name|IS_EVEN
parameter_list|(
name|r
parameter_list|)
value|(r.regno % 2 == 0)
end_define

begin_define
define|#
directive|define
name|IS_HCOMPL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(REG_EQUAL(a, b)&& \                          ((a).regno& F_REG_HIGH) != ((b).regno& F_REG_HIGH))
end_define

begin_comment
comment|/* register type checking.  */
end_comment

begin_define
define|#
directive|define
name|_TYPECHECK
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|)
value|(((r).regno& CLASS_MASK) == T_REG_##x)
end_define

begin_define
define|#
directive|define
name|IS_DREG
parameter_list|(
name|r
parameter_list|)
value|_TYPECHECK(r, R)
end_define

begin_define
define|#
directive|define
name|IS_DREG_H
parameter_list|(
name|r
parameter_list|)
value|(_TYPECHECK(r, R)&& IS_H(r))
end_define

begin_define
define|#
directive|define
name|IS_DREG_L
parameter_list|(
name|r
parameter_list|)
value|(_TYPECHECK(r, R)&& !IS_H(r))
end_define

begin_define
define|#
directive|define
name|IS_PREG
parameter_list|(
name|r
parameter_list|)
value|_TYPECHECK(r, P)
end_define

begin_define
define|#
directive|define
name|IS_IREG
parameter_list|(
name|r
parameter_list|)
value|(((r).regno& 0xf4) == T_REG_I)
end_define

begin_define
define|#
directive|define
name|IS_MREG
parameter_list|(
name|r
parameter_list|)
value|(((r).regno& 0xf4) == T_REG_M)
end_define

begin_define
define|#
directive|define
name|IS_BREG
parameter_list|(
name|r
parameter_list|)
value|(((r).regno& 0xf4) == T_REG_B)
end_define

begin_define
define|#
directive|define
name|IS_LREG
parameter_list|(
name|r
parameter_list|)
value|(((r).regno& 0xf4) == T_REG_L)
end_define

begin_define
define|#
directive|define
name|IS_CREG
parameter_list|(
name|r
parameter_list|)
value|((r).regno == REG_LC0 || (r).regno == REG_LC1)
end_define

begin_define
define|#
directive|define
name|IS_ALLREG
parameter_list|(
name|r
parameter_list|)
value|((r).regno< T_NOGROUP)
end_define

begin_comment
comment|/* Expression value macros.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ones_compl
block|,
name|twos_compl
block|,
name|mult
block|,
name|divide
block|,
name|mod
block|,
name|add
block|,
name|sub
block|,
name|lsh
block|,
name|rsh
block|,
name|logand
block|,
name|logior
block|,
name|logxor
block|}
name|expr_opcodes_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|expressionS
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|SYMBOL_T
value|symbolS*
end_define

begin_struct
struct|struct
name|expression_cell
block|{
name|int
name|value
decl_stmt|;
name|SYMBOL_T
name|symbol
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* User Type Definitions.  */
end_comment

begin_struct
struct|struct
name|bfin_insn
block|{
name|unsigned
name|long
name|value
decl_stmt|;
name|struct
name|bfin_insn
modifier|*
name|next
decl_stmt|;
name|struct
name|expression_cell
modifier|*
name|exp
decl_stmt|;
name|int
name|pcrel
decl_stmt|;
name|int
name|reloc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INSTR_T
value|struct bfin_insn*
end_define

begin_define
define|#
directive|define
name|EXPR_T
value|struct expression_cell*
end_define

begin_typedef
typedef|typedef
name|struct
name|expr_node_struct
name|Expr_Node
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|INSTR_T
name|gencode
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|INSTR_T
name|conscode
parameter_list|(
name|INSTR_T
name|head
parameter_list|,
name|INSTR_T
name|tail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|INSTR_T
name|conctcode
parameter_list|(
name|INSTR_T
name|head
parameter_list|,
name|INSTR_T
name|tail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|INSTR_T
name|note_reloc
parameter_list|(
name|INSTR_T
name|code
parameter_list|,
name|Expr_Node
modifier|*
parameter_list|,
name|int
name|reloc
parameter_list|,
name|int
name|pcrel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|INSTR_T
name|note_reloc1
parameter_list|(
name|INSTR_T
name|code
parameter_list|,
specifier|const
name|char
modifier|*
name|sym
parameter_list|,
name|int
name|reloc
parameter_list|,
name|int
name|pcrel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|INSTR_T
name|note_reloc2
parameter_list|(
name|INSTR_T
name|code
parameter_list|,
specifier|const
name|char
modifier|*
name|symbol
parameter_list|,
name|int
name|reloc
parameter_list|,
name|int
name|value
parameter_list|,
name|int
name|pcrel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Types of expressions.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Expr_Node_Binop
block|,
comment|/* Binary operator.  */
name|Expr_Node_Unop
block|,
comment|/* Unary operator.  */
name|Expr_Node_Reloc
block|,
comment|/* Symbol to be relocated.  */
name|Expr_Node_GOT_Reloc
block|,
comment|/* Symbol to be relocated using the GOT.  */
name|Expr_Node_Constant
comment|/* Constant.  */
block|}
name|Expr_Node_Type
typedef|;
end_typedef

begin_comment
comment|/* Types of operators.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Expr_Op_Type_Add
block|,
name|Expr_Op_Type_Sub
block|,
name|Expr_Op_Type_Mult
block|,
name|Expr_Op_Type_Div
block|,
name|Expr_Op_Type_Mod
block|,
name|Expr_Op_Type_Lshift
block|,
name|Expr_Op_Type_Rshift
block|,
name|Expr_Op_Type_BAND
block|,
comment|/* Bitwise AND.  */
name|Expr_Op_Type_BOR
block|,
comment|/* Bitwise OR.  */
name|Expr_Op_Type_BXOR
block|,
comment|/* Bitwise exclusive OR.  */
name|Expr_Op_Type_LAND
block|,
comment|/* Logical AND.  */
name|Expr_Op_Type_LOR
block|,
comment|/* Logical OR.  */
name|Expr_Op_Type_NEG
block|,
name|Expr_Op_Type_COMP
comment|/* Complement.  */
block|}
name|Expr_Op_Type
typedef|;
end_typedef

begin_comment
comment|/* The value that can be stored ... depends on type.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
specifier|const
name|char
modifier|*
name|s_value
decl_stmt|;
comment|/* if relocation symbol, the text.  */
name|int
name|i_value
decl_stmt|;
comment|/* if constant, the value.  */
name|Expr_Op_Type
name|op_value
decl_stmt|;
comment|/* if operator, the value.  */
block|}
name|Expr_Node_Value
typedef|;
end_typedef

begin_comment
comment|/* The expression node.  */
end_comment

begin_struct
struct|struct
name|expr_node_struct
block|{
name|Expr_Node_Type
name|type
decl_stmt|;
name|Expr_Node_Value
name|value
decl_stmt|;
name|Expr_Node
modifier|*
name|Left_Child
decl_stmt|;
name|Expr_Node
modifier|*
name|Right_Child
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Operations on the expression node.  */
end_comment

begin_function_decl
name|Expr_Node
modifier|*
name|Expr_Node_Create
parameter_list|(
name|Expr_Node_Type
name|type
parameter_list|,
name|Expr_Node_Value
name|value
parameter_list|,
name|Expr_Node
modifier|*
name|Left_Child
parameter_list|,
name|Expr_Node
modifier|*
name|Right_Child
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generate the reloc structure as a series of instructions.  */
end_comment

begin_function_decl
name|INSTR_T
name|Expr_Node_Gen_Reloc
parameter_list|(
name|Expr_Node
modifier|*
name|head
parameter_list|,
name|int
name|parent_reloc
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MKREF
parameter_list|(
name|x
parameter_list|)
value|mkexpr (0,x)
end_define

begin_define
define|#
directive|define
name|ALLOCATE
parameter_list|(
name|x
parameter_list|)
value|malloc (x)
end_define

begin_define
define|#
directive|define
name|NULL_CODE
value|((INSTR_T) 0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|EXPR_VALUE
end_ifndef

begin_define
define|#
directive|define
name|EXPR_VALUE
parameter_list|(
name|x
parameter_list|)
value|(((x)->type == Expr_Node_Constant) ? ((x)->value.i_value) : 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXPR_SYMBOL
end_ifndef

begin_define
define|#
directive|define
name|EXPR_SYMBOL
parameter_list|(
name|x
parameter_list|)
value|((x)->symbol)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|long
name|reg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_register
block|{
name|reg_t
name|regno
decl_stmt|;
comment|/* Register ID as defined in machine_registers.  */
name|int
name|flags
decl_stmt|;
block|}
name|Register
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_macfunc
block|{
name|char
name|n
decl_stmt|;
name|char
name|op
decl_stmt|;
name|char
name|w
decl_stmt|;
name|char
name|P
decl_stmt|;
name|Register
name|dst
decl_stmt|;
name|Register
name|s0
decl_stmt|;
name|Register
name|s1
decl_stmt|;
block|}
name|Macfunc
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_opt_mode
block|{
name|int
name|MM
decl_stmt|;
name|int
name|mod
decl_stmt|;
block|}
name|Opt_mode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|SEMANTIC_ERROR
block|,
name|NO_INSN_GENERATED
block|,
name|INSN_GENERATED
block|}
name|parse_state
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
name|int
name|debug_codeselection
decl_stmt|;
name|void
name|error
parameter_list|(
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
name|void
name|warn
parameter_list|(
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
name|int
name|semantic_error
parameter_list|(
name|char
modifier|*
name|syntax
parameter_list|)
function_decl|;
name|void
name|semantic_error_2
parameter_list|(
name|char
modifier|*
name|syntax
parameter_list|)
function_decl|;
name|EXPR_T
name|mkexpr
parameter_list|(
name|int
parameter_list|,
name|SYMBOL_T
parameter_list|)
function_decl|;
specifier|extern
name|void
name|bfin_equals
parameter_list|(
name|Expr_Node
modifier|*
name|sym
parameter_list|)
function_decl|;
comment|/* Defined in bfin-lex.l.  */
name|void
name|set_start_state
parameter_list|(
name|void
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BFIN_PARSE_H */
end_comment

end_unit

