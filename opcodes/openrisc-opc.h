begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Instruction opcode header for openrisc.  THIS FILE IS MACHINE GENERATED WITH CGEN.  Copyright 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.  This file is part of the GNU Binutils and/or GDB, the GNU debugger.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENRISC_OPC_H
end_ifndef

begin_define
define|#
directive|define
name|OPENRISC_OPC_H
end_define

begin_comment
comment|/* -- opc.h */
end_comment

begin_undef
undef|#
directive|undef
name|CGEN_DIS_HASH_SIZE
end_undef

begin_define
define|#
directive|define
name|CGEN_DIS_HASH_SIZE
value|64
end_define

begin_undef
undef|#
directive|undef
name|CGEN_DIS_HASH
end_undef

begin_define
define|#
directive|define
name|CGEN_DIS_HASH
parameter_list|(
name|buffer
parameter_list|,
name|value
parameter_list|)
value|(((unsigned char *) (buffer))[0]>> 2)
end_define

begin_decl_stmt
specifier|extern
name|long
name|openrisc_sign_extend_16bit
name|PARAMS
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -- */
end_comment

begin_comment
comment|/* Enum declaration for openrisc instruction types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cgen_insn_type
block|{
name|OPENRISC_INSN_INVALID
block|,
name|OPENRISC_INSN_L_J
block|,
name|OPENRISC_INSN_L_JAL
block|,
name|OPENRISC_INSN_L_JR
block|,
name|OPENRISC_INSN_L_JALR
block|,
name|OPENRISC_INSN_L_BAL
block|,
name|OPENRISC_INSN_L_BNF
block|,
name|OPENRISC_INSN_L_BF
block|,
name|OPENRISC_INSN_L_BRK
block|,
name|OPENRISC_INSN_L_RFE
block|,
name|OPENRISC_INSN_L_SYS
block|,
name|OPENRISC_INSN_L_NOP
block|,
name|OPENRISC_INSN_L_MOVHI
block|,
name|OPENRISC_INSN_L_MFSR
block|,
name|OPENRISC_INSN_L_MTSR
block|,
name|OPENRISC_INSN_L_LW
block|,
name|OPENRISC_INSN_L_LBZ
block|,
name|OPENRISC_INSN_L_LBS
block|,
name|OPENRISC_INSN_L_LHZ
block|,
name|OPENRISC_INSN_L_LHS
block|,
name|OPENRISC_INSN_L_SW
block|,
name|OPENRISC_INSN_L_SB
block|,
name|OPENRISC_INSN_L_SH
block|,
name|OPENRISC_INSN_L_SLL
block|,
name|OPENRISC_INSN_L_SLLI
block|,
name|OPENRISC_INSN_L_SRL
block|,
name|OPENRISC_INSN_L_SRLI
block|,
name|OPENRISC_INSN_L_SRA
block|,
name|OPENRISC_INSN_L_SRAI
block|,
name|OPENRISC_INSN_L_ROR
block|,
name|OPENRISC_INSN_L_RORI
block|,
name|OPENRISC_INSN_L_ADD
block|,
name|OPENRISC_INSN_L_ADDI
block|,
name|OPENRISC_INSN_L_SUB
block|,
name|OPENRISC_INSN_L_SUBI
block|,
name|OPENRISC_INSN_L_AND
block|,
name|OPENRISC_INSN_L_ANDI
block|,
name|OPENRISC_INSN_L_OR
block|,
name|OPENRISC_INSN_L_ORI
block|,
name|OPENRISC_INSN_L_XOR
block|,
name|OPENRISC_INSN_L_XORI
block|,
name|OPENRISC_INSN_L_MUL
block|,
name|OPENRISC_INSN_L_MULI
block|,
name|OPENRISC_INSN_L_DIV
block|,
name|OPENRISC_INSN_L_DIVU
block|,
name|OPENRISC_INSN_L_SFGTS
block|,
name|OPENRISC_INSN_L_SFGTU
block|,
name|OPENRISC_INSN_L_SFGES
block|,
name|OPENRISC_INSN_L_SFGEU
block|,
name|OPENRISC_INSN_L_SFLTS
block|,
name|OPENRISC_INSN_L_SFLTU
block|,
name|OPENRISC_INSN_L_SFLES
block|,
name|OPENRISC_INSN_L_SFLEU
block|,
name|OPENRISC_INSN_L_SFGTSI
block|,
name|OPENRISC_INSN_L_SFGTUI
block|,
name|OPENRISC_INSN_L_SFGESI
block|,
name|OPENRISC_INSN_L_SFGEUI
block|,
name|OPENRISC_INSN_L_SFLTSI
block|,
name|OPENRISC_INSN_L_SFLTUI
block|,
name|OPENRISC_INSN_L_SFLESI
block|,
name|OPENRISC_INSN_L_SFLEUI
block|,
name|OPENRISC_INSN_L_SFEQ
block|,
name|OPENRISC_INSN_L_SFEQI
block|,
name|OPENRISC_INSN_L_SFNE
block|,
name|OPENRISC_INSN_L_SFNEI
block|}
name|CGEN_INSN_TYPE
typedef|;
end_typedef

begin_comment
comment|/* Index of `invalid' insn place holder.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_INSN_INVALID
value|OPENRISC_INSN_INVALID
end_define

begin_comment
comment|/* Total number of insns in table.  */
end_comment

begin_define
define|#
directive|define
name|MAX_INSNS
value|((int) OPENRISC_INSN_L_SFNEI + 1)
end_define

begin_comment
comment|/* This struct records data prior to insertion or after extraction.  */
end_comment

begin_struct
struct|struct
name|cgen_fields
block|{
name|int
name|length
decl_stmt|;
name|long
name|f_nil
decl_stmt|;
name|long
name|f_anyof
decl_stmt|;
name|long
name|f_class
decl_stmt|;
name|long
name|f_sub
decl_stmt|;
name|long
name|f_r1
decl_stmt|;
name|long
name|f_r2
decl_stmt|;
name|long
name|f_r3
decl_stmt|;
name|long
name|f_simm16
decl_stmt|;
name|long
name|f_uimm16
decl_stmt|;
name|long
name|f_uimm5
decl_stmt|;
name|long
name|f_hi16
decl_stmt|;
name|long
name|f_lo16
decl_stmt|;
name|long
name|f_op1
decl_stmt|;
name|long
name|f_op2
decl_stmt|;
name|long
name|f_op3
decl_stmt|;
name|long
name|f_op4
decl_stmt|;
name|long
name|f_op5
decl_stmt|;
name|long
name|f_op6
decl_stmt|;
name|long
name|f_op7
decl_stmt|;
name|long
name|f_i16_1
decl_stmt|;
name|long
name|f_i16_2
decl_stmt|;
name|long
name|f_disp26
decl_stmt|;
name|long
name|f_abs26
decl_stmt|;
name|long
name|f_i16nc
decl_stmt|;
name|long
name|f_f_15_8
decl_stmt|;
name|long
name|f_f_10_3
decl_stmt|;
name|long
name|f_f_4_1
decl_stmt|;
name|long
name|f_f_7_3
decl_stmt|;
name|long
name|f_f_10_7
decl_stmt|;
name|long
name|f_f_10_11
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CGEN_INIT_PARSE
parameter_list|(
name|od
parameter_list|)
define|\
value|{\ }
end_define

begin_define
define|#
directive|define
name|CGEN_INIT_INSERT
parameter_list|(
name|od
parameter_list|)
define|\
value|{\ }
end_define

begin_define
define|#
directive|define
name|CGEN_INIT_EXTRACT
parameter_list|(
name|od
parameter_list|)
define|\
value|{\ }
end_define

begin_define
define|#
directive|define
name|CGEN_INIT_PRINT
parameter_list|(
name|od
parameter_list|)
define|\
value|{\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENRISC_OPC_H */
end_comment

end_unit

