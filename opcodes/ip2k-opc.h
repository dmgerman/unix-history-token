begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Instruction opcode header for ip2k.  THIS FILE IS MACHINE GENERATED WITH CGEN.  Copyright 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.  This file is part of the GNU Binutils and/or GDB, the GNU debugger.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IP2K_OPC_H
end_ifndef

begin_define
define|#
directive|define
name|IP2K_OPC_H
end_define

begin_comment
comment|/* -- opc.h */
end_comment

begin_comment
comment|/* Check applicability of instructions against machines.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_VALIDATE_INSN_SUPPORTED
end_define

begin_comment
comment|/* Allows reason codes to be output when assembler errors occur.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_VERBOSE_ASSEMBLER_ERRORS
end_define

begin_comment
comment|/* Override disassembly hashing - there are variable bits in the top    byte of these instructions.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_DIS_HASH_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|CGEN_DIS_HASH
parameter_list|(
name|buf
parameter_list|,
name|value
parameter_list|)
value|(((* (unsigned char*) (buf))>> 5) % CGEN_DIS_HASH_SIZE)
end_define

begin_define
define|#
directive|define
name|CGEN_ASM_HASH_SIZE
value|127
end_define

begin_define
define|#
directive|define
name|CGEN_ASM_HASH
parameter_list|(
name|insn
parameter_list|)
value|ip2k_asm_hash(insn)
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|ip2k_asm_hash
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|insn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip2k_cgen_insn_supported
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
specifier|const
name|CGEN_INSN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* -- opc.c */
end_comment

begin_comment
comment|/* Enum declaration for ip2k instruction types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cgen_insn_type
block|{
name|IP2K_INSN_INVALID
block|,
name|IP2K_INSN_JMP
block|,
name|IP2K_INSN_CALL
block|,
name|IP2K_INSN_SB
block|,
name|IP2K_INSN_SNB
block|,
name|IP2K_INSN_SETB
block|,
name|IP2K_INSN_CLRB
block|,
name|IP2K_INSN_XORW_L
block|,
name|IP2K_INSN_ANDW_L
block|,
name|IP2K_INSN_ORW_L
block|,
name|IP2K_INSN_ADDW_L
block|,
name|IP2K_INSN_SUBW_L
block|,
name|IP2K_INSN_CMPW_L
block|,
name|IP2K_INSN_RETW_L
block|,
name|IP2K_INSN_CSEW_L
block|,
name|IP2K_INSN_CSNEW_L
block|,
name|IP2K_INSN_PUSH_L
block|,
name|IP2K_INSN_MULSW_L
block|,
name|IP2K_INSN_MULUW_L
block|,
name|IP2K_INSN_LOADL_L
block|,
name|IP2K_INSN_LOADH_L
block|,
name|IP2K_INSN_LOADL_A
block|,
name|IP2K_INSN_LOADH_A
block|,
name|IP2K_INSN_ADDCFR_W
block|,
name|IP2K_INSN_ADDCW_FR
block|,
name|IP2K_INSN_INCSNZ_FR
block|,
name|IP2K_INSN_INCSNZW_FR
block|,
name|IP2K_INSN_MULSW_FR
block|,
name|IP2K_INSN_MULUW_FR
block|,
name|IP2K_INSN_DECSNZ_FR
block|,
name|IP2K_INSN_DECSNZW_FR
block|,
name|IP2K_INSN_SUBCW_FR
block|,
name|IP2K_INSN_SUBCFR_W
block|,
name|IP2K_INSN_POP_FR
block|,
name|IP2K_INSN_PUSH_FR
block|,
name|IP2K_INSN_CSEW_FR
block|,
name|IP2K_INSN_CSNEW_FR
block|,
name|IP2K_INSN_INCSZ_FR
block|,
name|IP2K_INSN_INCSZW_FR
block|,
name|IP2K_INSN_SWAP_FR
block|,
name|IP2K_INSN_SWAPW_FR
block|,
name|IP2K_INSN_RL_FR
block|,
name|IP2K_INSN_RLW_FR
block|,
name|IP2K_INSN_RR_FR
block|,
name|IP2K_INSN_RRW_FR
block|,
name|IP2K_INSN_DECSZ_FR
block|,
name|IP2K_INSN_DECSZW_FR
block|,
name|IP2K_INSN_INC_FR
block|,
name|IP2K_INSN_INCW_FR
block|,
name|IP2K_INSN_NOT_FR
block|,
name|IP2K_INSN_NOTW_FR
block|,
name|IP2K_INSN_TEST_FR
block|,
name|IP2K_INSN_MOVW_L
block|,
name|IP2K_INSN_MOVFR_W
block|,
name|IP2K_INSN_MOVW_FR
block|,
name|IP2K_INSN_ADDFR_W
block|,
name|IP2K_INSN_ADDW_FR
block|,
name|IP2K_INSN_XORFR_W
block|,
name|IP2K_INSN_XORW_FR
block|,
name|IP2K_INSN_ANDFR_W
block|,
name|IP2K_INSN_ANDW_FR
block|,
name|IP2K_INSN_ORFR_W
block|,
name|IP2K_INSN_ORW_FR
block|,
name|IP2K_INSN_DEC_FR
block|,
name|IP2K_INSN_DECW_FR
block|,
name|IP2K_INSN_SUBFR_W
block|,
name|IP2K_INSN_SUBW_FR
block|,
name|IP2K_INSN_CLR_FR
block|,
name|IP2K_INSN_CMPW_FR
block|,
name|IP2K_INSN_SPEED
block|,
name|IP2K_INSN_IREADI
block|,
name|IP2K_INSN_IWRITEI
block|,
name|IP2K_INSN_FREAD
block|,
name|IP2K_INSN_FWRITE
block|,
name|IP2K_INSN_IREAD
block|,
name|IP2K_INSN_IWRITE
block|,
name|IP2K_INSN_PAGE
block|,
name|IP2K_INSN_SYSTEM
block|,
name|IP2K_INSN_RETI
block|,
name|IP2K_INSN_RET
block|,
name|IP2K_INSN_INT
block|,
name|IP2K_INSN_BREAKX
block|,
name|IP2K_INSN_CWDT
block|,
name|IP2K_INSN_FERASE
block|,
name|IP2K_INSN_RETNP
block|,
name|IP2K_INSN_BREAK
block|,
name|IP2K_INSN_NOP
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
value|IP2K_INSN_INVALID
end_define

begin_comment
comment|/* Total number of insns in table.  */
end_comment

begin_define
define|#
directive|define
name|MAX_INSNS
value|((int) IP2K_INSN_NOP + 1)
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
name|f_imm8
decl_stmt|;
name|long
name|f_reg
decl_stmt|;
name|long
name|f_addr16cjp
decl_stmt|;
name|long
name|f_dir
decl_stmt|;
name|long
name|f_bitno
decl_stmt|;
name|long
name|f_op3
decl_stmt|;
name|long
name|f_op4
decl_stmt|;
name|long
name|f_op4mid
decl_stmt|;
name|long
name|f_op6
decl_stmt|;
name|long
name|f_op8
decl_stmt|;
name|long
name|f_op6_10low
decl_stmt|;
name|long
name|f_op6_7low
decl_stmt|;
name|long
name|f_reti3
decl_stmt|;
name|long
name|f_skipb
decl_stmt|;
name|long
name|f_page3
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
comment|/* IP2K_OPC_H */
end_comment

end_unit

