begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: mips_opcode.h,v 1.2 1999/01/27 04:46:05 imp Exp $	*/
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)mips_opcode.h 8.1 (Berkeley) 6/10/93  *	JNPR: mips_opcode.h,v 1.1 2006/08/07 05:38:57 katta  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MIPS_OPCODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MIPS_OPCODE_H_
end_define

begin_comment
comment|/*  * Define the instruction formats and opcode values for the  * MIPS instruction set.  */
end_comment

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_comment
comment|/*  * Define the instruction formats.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|unsigned
name|word
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
struct|struct
block|{
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
name|unsigned
name|rs
range|:
literal|5
decl_stmt|;
name|unsigned
name|rt
range|:
literal|5
decl_stmt|;
name|unsigned
name|imm
range|:
literal|16
decl_stmt|;
block|}
name|IType
struct|;
struct|struct
block|{
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
name|unsigned
name|target
range|:
literal|26
decl_stmt|;
block|}
name|JType
struct|;
struct|struct
block|{
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
name|unsigned
name|rs
range|:
literal|5
decl_stmt|;
name|unsigned
name|rt
range|:
literal|5
decl_stmt|;
name|unsigned
name|rd
range|:
literal|5
decl_stmt|;
name|unsigned
name|shamt
range|:
literal|5
decl_stmt|;
name|unsigned
name|func
range|:
literal|6
decl_stmt|;
block|}
name|RType
struct|;
struct|struct
block|{
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
comment|/* always '0x11' */
name|unsigned
label|:
literal|1
expr_stmt|;
comment|/* always '1' */
name|unsigned
name|fmt
range|:
literal|4
decl_stmt|;
name|unsigned
name|ft
range|:
literal|5
decl_stmt|;
name|unsigned
name|fs
range|:
literal|5
decl_stmt|;
name|unsigned
name|fd
range|:
literal|5
decl_stmt|;
name|unsigned
name|func
range|:
literal|6
decl_stmt|;
block|}
name|FRType
struct|;
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
struct|struct
block|{
name|unsigned
name|imm
range|:
literal|16
decl_stmt|;
name|unsigned
name|rt
range|:
literal|5
decl_stmt|;
name|unsigned
name|rs
range|:
literal|5
decl_stmt|;
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
block|}
name|IType
struct|;
struct|struct
block|{
name|unsigned
name|target
range|:
literal|26
decl_stmt|;
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
block|}
name|JType
struct|;
struct|struct
block|{
name|unsigned
name|func
range|:
literal|6
decl_stmt|;
name|unsigned
name|shamt
range|:
literal|5
decl_stmt|;
name|unsigned
name|rd
range|:
literal|5
decl_stmt|;
name|unsigned
name|rt
range|:
literal|5
decl_stmt|;
name|unsigned
name|rs
range|:
literal|5
decl_stmt|;
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
block|}
name|RType
struct|;
struct|struct
block|{
name|unsigned
name|func
range|:
literal|6
decl_stmt|;
name|unsigned
name|fd
range|:
literal|5
decl_stmt|;
name|unsigned
name|fs
range|:
literal|5
decl_stmt|;
name|unsigned
name|ft
range|:
literal|5
decl_stmt|;
name|unsigned
name|fmt
range|:
literal|4
decl_stmt|;
name|unsigned
label|:
literal|1
expr_stmt|;
comment|/* always '1' */
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
comment|/* always '0x11' */
block|}
name|FRType
struct|;
endif|#
directive|endif
block|}
name|InstFmt
typedef|;
end_typedef

begin_comment
comment|/* instruction field decoding macros */
end_comment

begin_define
define|#
directive|define
name|MIPS_INST_OPCODE
parameter_list|(
name|val
parameter_list|)
value|(val>> 26)
end_define

begin_define
define|#
directive|define
name|MIPS_INST_RS
parameter_list|(
name|val
parameter_list|)
value|((val& 0x03e00000)>> 21)
end_define

begin_define
define|#
directive|define
name|MIPS_INST_RT
parameter_list|(
name|val
parameter_list|)
value|((val& 0x001f0000)>> 16)
end_define

begin_define
define|#
directive|define
name|MIPS_INST_IMM
parameter_list|(
name|val
parameter_list|)
value|((val& 0x0000ffff))
end_define

begin_define
define|#
directive|define
name|MIPS_INST_RD
parameter_list|(
name|val
parameter_list|)
value|((val& 0x0000f800)>> 11)
end_define

begin_define
define|#
directive|define
name|MIPS_INST_SA
parameter_list|(
name|val
parameter_list|)
value|((val& 0x000007c0)>> 6)
end_define

begin_define
define|#
directive|define
name|MIPS_INST_FUNC
parameter_list|(
name|val
parameter_list|)
value|(val& 0x0000003f)
end_define

begin_define
define|#
directive|define
name|MIPS_INST_INDEX
parameter_list|(
name|val
parameter_list|)
value|(val& 0x03ffffff)
end_define

begin_comment
comment|/*  * the mips opcode and function table use a 3bit row and 3bit col  * number we define the following macro for easy transcribing  */
end_comment

begin_define
define|#
directive|define
name|MIPS_OPCODE
parameter_list|(
name|r
parameter_list|,
name|c
parameter_list|)
value|(((r& 0x07)<< 3) | (c& 0x07))
end_define

begin_comment
comment|/*  * Values for the 'op' field.  */
end_comment

begin_define
define|#
directive|define
name|OP_SPECIAL
value|000
end_define

begin_define
define|#
directive|define
name|OP_BCOND
value|001
end_define

begin_define
define|#
directive|define
name|OP_J
value|002
end_define

begin_define
define|#
directive|define
name|OP_JAL
value|003
end_define

begin_define
define|#
directive|define
name|OP_BEQ
value|004
end_define

begin_define
define|#
directive|define
name|OP_BNE
value|005
end_define

begin_define
define|#
directive|define
name|OP_BLEZ
value|006
end_define

begin_define
define|#
directive|define
name|OP_BGTZ
value|007
end_define

begin_define
define|#
directive|define
name|OP_REGIMM
value|OP_BCOND
end_define

begin_define
define|#
directive|define
name|OP_ADDI
value|010
end_define

begin_define
define|#
directive|define
name|OP_ADDIU
value|011
end_define

begin_define
define|#
directive|define
name|OP_SLTI
value|012
end_define

begin_define
define|#
directive|define
name|OP_SLTIU
value|013
end_define

begin_define
define|#
directive|define
name|OP_ANDI
value|014
end_define

begin_define
define|#
directive|define
name|OP_ORI
value|015
end_define

begin_define
define|#
directive|define
name|OP_XORI
value|016
end_define

begin_define
define|#
directive|define
name|OP_LUI
value|017
end_define

begin_define
define|#
directive|define
name|OP_COP0
value|020
end_define

begin_define
define|#
directive|define
name|OP_COP1
value|021
end_define

begin_define
define|#
directive|define
name|OP_COP2
value|022
end_define

begin_define
define|#
directive|define
name|OP_COP3
value|023
end_define

begin_define
define|#
directive|define
name|OP_BEQL
value|024
end_define

begin_define
define|#
directive|define
name|OP_BNEL
value|025
end_define

begin_define
define|#
directive|define
name|OP_BLEZL
value|026
end_define

begin_define
define|#
directive|define
name|OP_BGTZL
value|027
end_define

begin_define
define|#
directive|define
name|OP_COP1X
value|OP_COP3
end_define

begin_define
define|#
directive|define
name|OP_DADDI
value|030
end_define

begin_define
define|#
directive|define
name|OP_DADDIU
value|031
end_define

begin_define
define|#
directive|define
name|OP_LDL
value|032
end_define

begin_define
define|#
directive|define
name|OP_LDR
value|033
end_define

begin_define
define|#
directive|define
name|OP_SPECIAL2
value|034
end_define

begin_define
define|#
directive|define
name|OP_JALX
value|035
end_define

begin_define
define|#
directive|define
name|OP_SPECIAL3
value|037
end_define

begin_define
define|#
directive|define
name|OP_LB
value|040
end_define

begin_define
define|#
directive|define
name|OP_LH
value|041
end_define

begin_define
define|#
directive|define
name|OP_LWL
value|042
end_define

begin_define
define|#
directive|define
name|OP_LW
value|043
end_define

begin_define
define|#
directive|define
name|OP_LBU
value|044
end_define

begin_define
define|#
directive|define
name|OP_LHU
value|045
end_define

begin_define
define|#
directive|define
name|OP_LWR
value|046
end_define

begin_define
define|#
directive|define
name|OP_LWU
value|047
end_define

begin_define
define|#
directive|define
name|OP_SB
value|050
end_define

begin_define
define|#
directive|define
name|OP_SH
value|051
end_define

begin_define
define|#
directive|define
name|OP_SWL
value|052
end_define

begin_define
define|#
directive|define
name|OP_SW
value|053
end_define

begin_define
define|#
directive|define
name|OP_SDL
value|054
end_define

begin_define
define|#
directive|define
name|OP_SDR
value|055
end_define

begin_define
define|#
directive|define
name|OP_SWR
value|056
end_define

begin_define
define|#
directive|define
name|OP_CACHE
value|057
end_define

begin_define
define|#
directive|define
name|OP_LL
value|060
end_define

begin_define
define|#
directive|define
name|OP_LWC1
value|061
end_define

begin_define
define|#
directive|define
name|OP_LWC2
value|062
end_define

begin_define
define|#
directive|define
name|OP_LWC3
value|063
end_define

begin_define
define|#
directive|define
name|OP_LLD
value|064
end_define

begin_define
define|#
directive|define
name|OP_LDC1
value|065
end_define

begin_define
define|#
directive|define
name|OP_LDC2
value|066
end_define

begin_define
define|#
directive|define
name|OP_LD
value|067
end_define

begin_define
define|#
directive|define
name|OP_PREF
value|OP_LWC3
end_define

begin_define
define|#
directive|define
name|OP_SC
value|070
end_define

begin_define
define|#
directive|define
name|OP_SWC1
value|071
end_define

begin_define
define|#
directive|define
name|OP_SWC2
value|072
end_define

begin_define
define|#
directive|define
name|OP_SWC3
value|073
end_define

begin_define
define|#
directive|define
name|OP_SCD
value|074
end_define

begin_define
define|#
directive|define
name|OP_SDC1
value|075
end_define

begin_define
define|#
directive|define
name|OP_SDC2
value|076
end_define

begin_define
define|#
directive|define
name|OP_SD
value|077
end_define

begin_comment
comment|/*  * Values for the 'func' field when 'op' == OP_SPECIAL.  */
end_comment

begin_define
define|#
directive|define
name|OP_SLL
value|000
end_define

begin_define
define|#
directive|define
name|OP_MOVCI
value|001
end_define

begin_define
define|#
directive|define
name|OP_SRL
value|002
end_define

begin_define
define|#
directive|define
name|OP_SRA
value|003
end_define

begin_define
define|#
directive|define
name|OP_SLLV
value|004
end_define

begin_define
define|#
directive|define
name|OP_SRLV
value|006
end_define

begin_define
define|#
directive|define
name|OP_SRAV
value|007
end_define

begin_define
define|#
directive|define
name|OP_F_SLL
value|OP_SLL
end_define

begin_define
define|#
directive|define
name|OP_F_MOVCI
value|OP_MOVCI
end_define

begin_define
define|#
directive|define
name|OP_F_SRL
value|OP_SRL
end_define

begin_define
define|#
directive|define
name|OP_F_SRA
value|OP_SRA
end_define

begin_define
define|#
directive|define
name|OP_F_SLLV
value|OP_SLLV
end_define

begin_define
define|#
directive|define
name|OP_F_SRLV
value|OP_SRLV
end_define

begin_define
define|#
directive|define
name|OP_F_SRAV
value|OP_SRAV
end_define

begin_define
define|#
directive|define
name|OP_JR
value|010
end_define

begin_define
define|#
directive|define
name|OP_JALR
value|011
end_define

begin_define
define|#
directive|define
name|OP_MOVZ
value|012
end_define

begin_define
define|#
directive|define
name|OP_MOVN
value|013
end_define

begin_define
define|#
directive|define
name|OP_SYSCALL
value|014
end_define

begin_define
define|#
directive|define
name|OP_BREAK
value|015
end_define

begin_define
define|#
directive|define
name|OP_SYNC
value|017
end_define

begin_define
define|#
directive|define
name|OP_F_JR
value|OP_JR
end_define

begin_define
define|#
directive|define
name|OP_F_JALR
value|OP_JALR
end_define

begin_define
define|#
directive|define
name|OP_F_MOVZ
value|OP_MOVZ
end_define

begin_define
define|#
directive|define
name|OP_F_MOVN
value|OP_MOVN
end_define

begin_define
define|#
directive|define
name|OP_F_SYSCALL
value|OP_SYSCALL
end_define

begin_define
define|#
directive|define
name|OP_F_BREAK
value|OP_BREAK
end_define

begin_define
define|#
directive|define
name|OP_F_SYNC
value|OP_SYNC
end_define

begin_define
define|#
directive|define
name|OP_MFHI
value|020
end_define

begin_define
define|#
directive|define
name|OP_MTHI
value|021
end_define

begin_define
define|#
directive|define
name|OP_MFLO
value|022
end_define

begin_define
define|#
directive|define
name|OP_MTLO
value|023
end_define

begin_define
define|#
directive|define
name|OP_DSLLV
value|024
end_define

begin_define
define|#
directive|define
name|OP_DSRLV
value|026
end_define

begin_define
define|#
directive|define
name|OP_DSRAV
value|027
end_define

begin_define
define|#
directive|define
name|OP_F_MFHI
value|OP_MFHI
end_define

begin_define
define|#
directive|define
name|OP_F_MTHI
value|OP_MTHI
end_define

begin_define
define|#
directive|define
name|OP_F_MFLO
value|OP_MFLO
end_define

begin_define
define|#
directive|define
name|OP_F_MTLO
value|OP_MTLO
end_define

begin_define
define|#
directive|define
name|OP_F_DSLLV
value|OP_DSLLV
end_define

begin_define
define|#
directive|define
name|OP_F_DSRLV
value|OP_DSRLV
end_define

begin_define
define|#
directive|define
name|OP_F_DSRAV
value|OP_DSRAV
end_define

begin_define
define|#
directive|define
name|OP_MULT
value|030
end_define

begin_define
define|#
directive|define
name|OP_MULTU
value|031
end_define

begin_define
define|#
directive|define
name|OP_DIV
value|032
end_define

begin_define
define|#
directive|define
name|OP_DIVU
value|033
end_define

begin_define
define|#
directive|define
name|OP_DMULT
value|034
end_define

begin_define
define|#
directive|define
name|OP_DMULTU
value|035
end_define

begin_define
define|#
directive|define
name|OP_DDIV
value|036
end_define

begin_define
define|#
directive|define
name|OP_DDIVU
value|037
end_define

begin_define
define|#
directive|define
name|OP_F_MULT
value|OP_MULT
end_define

begin_define
define|#
directive|define
name|OP_F_MULTU
value|OP_MULTU
end_define

begin_define
define|#
directive|define
name|OP_F_DIV
value|OP_DIV
end_define

begin_define
define|#
directive|define
name|OP_F_DIVU
value|OP_DIVU
end_define

begin_define
define|#
directive|define
name|OP_F_DMULT
value|OP_DMULT
end_define

begin_define
define|#
directive|define
name|OP_F_DMULTU
value|OP_DMULTU
end_define

begin_define
define|#
directive|define
name|OP_F_DDIV
value|OP_DDIV
end_define

begin_define
define|#
directive|define
name|OP_F_DDIVU
value|OP_DDIVU
end_define

begin_define
define|#
directive|define
name|OP_ADD
value|040
end_define

begin_define
define|#
directive|define
name|OP_ADDU
value|041
end_define

begin_define
define|#
directive|define
name|OP_SUB
value|042
end_define

begin_define
define|#
directive|define
name|OP_SUBU
value|043
end_define

begin_define
define|#
directive|define
name|OP_AND
value|044
end_define

begin_define
define|#
directive|define
name|OP_OR
value|045
end_define

begin_define
define|#
directive|define
name|OP_XOR
value|046
end_define

begin_define
define|#
directive|define
name|OP_NOR
value|047
end_define

begin_define
define|#
directive|define
name|OP_F_ADD
value|OP_ADD
end_define

begin_define
define|#
directive|define
name|OP_F_ADDU
value|OP_ADDU
end_define

begin_define
define|#
directive|define
name|OP_F_SUB
value|OP_SUB
end_define

begin_define
define|#
directive|define
name|OP_F_SUBU
value|OP_SUBU
end_define

begin_define
define|#
directive|define
name|OP_F_AND
value|OP_AND
end_define

begin_define
define|#
directive|define
name|OP_F_OR
value|OP_OR
end_define

begin_define
define|#
directive|define
name|OP_F_XOR
value|OP_XOR
end_define

begin_define
define|#
directive|define
name|OP_F_NOR
value|OP_NOR
end_define

begin_define
define|#
directive|define
name|OP_SLT
value|052
end_define

begin_define
define|#
directive|define
name|OP_SLTU
value|053
end_define

begin_define
define|#
directive|define
name|OP_DADD
value|054
end_define

begin_define
define|#
directive|define
name|OP_DADDU
value|055
end_define

begin_define
define|#
directive|define
name|OP_DSUB
value|056
end_define

begin_define
define|#
directive|define
name|OP_DSUBU
value|057
end_define

begin_define
define|#
directive|define
name|OP_F_SLT
value|OP_SLT
end_define

begin_define
define|#
directive|define
name|OP_F_SLTU
value|OP_SLTU
end_define

begin_define
define|#
directive|define
name|OP_F_DADD
value|OP_DADD
end_define

begin_define
define|#
directive|define
name|OP_F_DADDU
value|OP_DADDU
end_define

begin_define
define|#
directive|define
name|OP_F_DSUB
value|OP_DSUB
end_define

begin_define
define|#
directive|define
name|OP_F_DSUBU
value|OP_DSUBU
end_define

begin_define
define|#
directive|define
name|OP_TGE
value|060
end_define

begin_define
define|#
directive|define
name|OP_TGEU
value|061
end_define

begin_define
define|#
directive|define
name|OP_TLT
value|062
end_define

begin_define
define|#
directive|define
name|OP_TLTU
value|063
end_define

begin_define
define|#
directive|define
name|OP_TEQ
value|064
end_define

begin_define
define|#
directive|define
name|OP_TNE
value|066
end_define

begin_define
define|#
directive|define
name|OP_F_TGE
value|OP_TGE
end_define

begin_define
define|#
directive|define
name|OP_F_TGEU
value|OP_TGEU
end_define

begin_define
define|#
directive|define
name|OP_F_TLT
value|OP_TLT
end_define

begin_define
define|#
directive|define
name|OP_F_TLTU
value|OP_TLTU
end_define

begin_define
define|#
directive|define
name|OP_F_TEQ
value|OP_TEQ
end_define

begin_define
define|#
directive|define
name|OP_F_TNE
value|OP_TNE
end_define

begin_define
define|#
directive|define
name|OP_DSLL
value|070
end_define

begin_define
define|#
directive|define
name|OP_DSRL
value|072
end_define

begin_define
define|#
directive|define
name|OP_DSRA
value|073
end_define

begin_define
define|#
directive|define
name|OP_DSLL32
value|074
end_define

begin_define
define|#
directive|define
name|OP_DSRL32
value|076
end_define

begin_define
define|#
directive|define
name|OP_DSRA32
value|077
end_define

begin_define
define|#
directive|define
name|OP_F_DSLL
value|OP_DSLL
end_define

begin_define
define|#
directive|define
name|OP_F_DSRL
value|OP_DSRL
end_define

begin_define
define|#
directive|define
name|OP_F_DSRA
value|OP_DSRA
end_define

begin_define
define|#
directive|define
name|OP_F_DSLL32
value|OP_DSLL32
end_define

begin_define
define|#
directive|define
name|OP_F_DSRL32
value|OP_DSRL32
end_define

begin_define
define|#
directive|define
name|OP_F_DSRA32
value|OP_DSRA32
end_define

begin_comment
comment|/*  * The REGIMM - register immediate instructions are further  * decoded using this table that has 2bit row numbers, hence  * a need for a new helper macro.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_ROP
parameter_list|(
name|r
parameter_list|,
name|c
parameter_list|)
value|((r& 0x03)<< 3) | (c& 0x07)
end_define

begin_comment
comment|/*  * Values for the 'func' field when 'op' == OP_BCOND.  */
end_comment

begin_define
define|#
directive|define
name|OP_BLTZ
value|000
end_define

begin_define
define|#
directive|define
name|OP_BGEZ
value|001
end_define

begin_define
define|#
directive|define
name|OP_BLTZL
value|002
end_define

begin_define
define|#
directive|define
name|OP_BGEZL
value|003
end_define

begin_define
define|#
directive|define
name|OP_R_BLTZ
value|OP_BLTZ
end_define

begin_define
define|#
directive|define
name|OP_R_BGEZ
value|OP_BGEZ
end_define

begin_define
define|#
directive|define
name|OP_R_BLTZL
value|OP_BLTZL
end_define

begin_define
define|#
directive|define
name|OP_R_BGEZL
value|OP_BGEZL
end_define

begin_define
define|#
directive|define
name|OP_TGEI
value|010
end_define

begin_define
define|#
directive|define
name|OP_TGEIU
value|011
end_define

begin_define
define|#
directive|define
name|OP_TLTI
value|012
end_define

begin_define
define|#
directive|define
name|OP_TLTIU
value|013
end_define

begin_define
define|#
directive|define
name|OP_TEQI
value|014
end_define

begin_define
define|#
directive|define
name|OP_TNEI
value|016
end_define

begin_define
define|#
directive|define
name|OP_R_TGEI
value|OP_TGEI
end_define

begin_define
define|#
directive|define
name|OP_R_TGEIU
value|OP_TGEIU
end_define

begin_define
define|#
directive|define
name|OP_R_TLTI
value|OP_TLTI
end_define

begin_define
define|#
directive|define
name|OP_R_TLTIU
value|OP_TLTIU
end_define

begin_define
define|#
directive|define
name|OP_R_TEQI
value|OP_TEQI
end_define

begin_define
define|#
directive|define
name|OP_R_TNEI
value|OP_TNEI
end_define

begin_define
define|#
directive|define
name|OP_BLTZAL
value|020
end_define

begin_define
define|#
directive|define
name|OP_BGEZAL
value|021
end_define

begin_define
define|#
directive|define
name|OP_BLTZALL
value|022
end_define

begin_define
define|#
directive|define
name|OP_BGEZALL
value|023
end_define

begin_define
define|#
directive|define
name|OP_R_BLTZAL
value|OP_BLTZAL
end_define

begin_define
define|#
directive|define
name|OP_R_BGEZAL
value|OP_BGEZAL
end_define

begin_define
define|#
directive|define
name|OP_R_BLTZALL
value|OP_BLTZALL
end_define

begin_define
define|#
directive|define
name|OP_R_BGEZALL
value|OP_BGEZALL
end_define

begin_comment
comment|/*  * Values for the 'func' field when 'op' == OP_SPECIAL3.  */
end_comment

begin_define
define|#
directive|define
name|OP_RDHWR
value|073
end_define

begin_comment
comment|/*  * Values for the 'rs' field when 'op' == OP_COPz.  */
end_comment

begin_define
define|#
directive|define
name|OP_MF
value|000
end_define

begin_define
define|#
directive|define
name|OP_DMF
value|001
end_define

begin_define
define|#
directive|define
name|OP_MT
value|004
end_define

begin_define
define|#
directive|define
name|OP_DMT
value|005
end_define

begin_define
define|#
directive|define
name|OP_BCx
value|010
end_define

begin_define
define|#
directive|define
name|OP_BCy
value|014
end_define

begin_define
define|#
directive|define
name|OP_CF
value|002
end_define

begin_define
define|#
directive|define
name|OP_CT
value|006
end_define

begin_comment
comment|/*  * Values for the 'rt' field when 'op' == OP_COPz.  */
end_comment

begin_define
define|#
directive|define
name|COPz_BC_TF_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|COPz_BC_TRUE
value|0x01
end_define

begin_define
define|#
directive|define
name|COPz_BC_FALSE
value|0x00
end_define

begin_define
define|#
directive|define
name|COPz_BCL_TF_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|COPz_BCL_TRUE
value|0x02
end_define

begin_define
define|#
directive|define
name|COPz_BCL_FALSE
value|0x00
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_MIPS_OPCODE_H_ */
end_comment

end_unit

