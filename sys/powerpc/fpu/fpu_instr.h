begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: instr.h,v 1.4 2005/12/11 12:18:43 christos Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)instr.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_comment
comment|/*  * An instruction.  */
end_comment

begin_union
union|union
name|instr
block|{
name|int
name|i_int
decl_stmt|;
comment|/* as a whole */
comment|/* 	 * Any instruction type. 	 */
struct|struct
block|{
name|u_int
name|i_opcd
range|:
literal|6
decl_stmt|;
comment|/* first-level decode */
name|u_int
label|:
literal|25
expr_stmt|;
name|u_int
name|i_rc
range|:
literal|1
decl_stmt|;
block|}
name|i_any
struct|;
comment|/* 	 * Format A 	 */
struct|struct
block|{
name|u_int
name|i_opcd
range|:
literal|6
decl_stmt|;
name|u_int
name|i_frt
range|:
literal|5
decl_stmt|;
name|u_int
name|i_fra
range|:
literal|5
decl_stmt|;
name|u_int
name|i_frb
range|:
literal|5
decl_stmt|;
name|u_int
name|i_frc
range|:
literal|5
decl_stmt|;
name|u_int
name|i_xo
range|:
literal|5
decl_stmt|;
name|u_int
name|i_rc
range|:
literal|1
decl_stmt|;
block|}
name|i_a
struct|;
comment|/* 	 * Format B 	 */
struct|struct
block|{
name|u_int
name|i_opcd
range|:
literal|6
decl_stmt|;
name|int
name|i_bo
range|:
literal|5
decl_stmt|;
name|int
name|i_bi
range|:
literal|5
decl_stmt|;
name|int
name|i_bd
range|:
literal|14
decl_stmt|;
name|int
name|i_aa
range|:
literal|1
decl_stmt|;
name|int
name|i_lk
range|:
literal|1
decl_stmt|;
block|}
name|i_b
struct|;
comment|/* 	 * Format D 	 */
struct|struct
block|{
name|u_int
name|i_opcd
range|:
literal|6
decl_stmt|;
name|u_int
name|i_rs
range|:
literal|5
decl_stmt|;
name|u_int
name|i_ra
range|:
literal|5
decl_stmt|;
name|int
name|i_d
range|:
literal|16
decl_stmt|;
block|}
name|i_d
struct|;
comment|/* 	 * Format DE 	 */
struct|struct
block|{
name|u_int
name|i_opcd
range|:
literal|6
decl_stmt|;
name|u_int
name|i_rs
range|:
literal|5
decl_stmt|;
name|u_int
name|i_ra
range|:
literal|5
decl_stmt|;
name|int
name|i_d
range|:
literal|12
decl_stmt|;
name|u_int
name|i_xo
range|:
literal|4
decl_stmt|;
block|}
name|i_de
struct|;
comment|/* 	 * Format I 	 */
struct|struct
block|{
name|u_int
name|i_opcd
range|:
literal|6
decl_stmt|;
name|int
name|i_li
range|:
literal|24
decl_stmt|;
name|int
name|i_aa
range|:
literal|1
decl_stmt|;
name|int
name|i_lk
range|:
literal|1
decl_stmt|;
block|}
name|i_i
struct|;
comment|/* 	 * Format M 	 */
struct|struct
block|{
name|u_int
name|i_opcd
range|:
literal|6
decl_stmt|;
name|u_int
name|i_rs
range|:
literal|5
decl_stmt|;
name|u_int
name|i_ra
range|:
literal|5
decl_stmt|;
name|u_int
name|i_rb
range|:
literal|5
decl_stmt|;
name|int
name|i_mb
range|:
literal|5
decl_stmt|;
name|int
name|i_me
range|:
literal|5
decl_stmt|;
name|u_int
name|i_rc
range|:
literal|1
decl_stmt|;
block|}
name|i_m
struct|;
comment|/* 	 * Format MD 	 */
struct|struct
block|{
name|u_int
name|i_opcd
range|:
literal|6
decl_stmt|;
name|u_int
name|i_rs
range|:
literal|5
decl_stmt|;
name|u_int
name|i_ra
range|:
literal|5
decl_stmt|;
name|u_int
name|i_rb
range|:
literal|5
decl_stmt|;
name|int
name|i_sh1_5
range|:
literal|5
decl_stmt|;
name|int
name|i_mb
range|:
literal|6
decl_stmt|;
name|u_int
name|i_xo
range|:
literal|3
decl_stmt|;
name|int
name|i_sh0
range|:
literal|2
decl_stmt|;
name|u_int
name|i_rc
range|:
literal|1
decl_stmt|;
block|}
name|i_md
struct|;
comment|/* 	 * Format MDS 	 */
struct|struct
block|{
name|u_int
name|i_opcd
range|:
literal|6
decl_stmt|;
name|u_int
name|i_rs
range|:
literal|5
decl_stmt|;
name|u_int
name|i_ra
range|:
literal|5
decl_stmt|;
name|u_int
name|i_rb
range|:
literal|5
decl_stmt|;
name|int
name|i_sh
range|:
literal|5
decl_stmt|;
name|int
name|i_mb
range|:
literal|6
decl_stmt|;
name|u_int
name|i_xo
range|:
literal|4
decl_stmt|;
name|u_int
name|i_rc
range|:
literal|1
decl_stmt|;
block|}
name|i_mds
struct|;
comment|/* 	 * Format S 	 */
struct|struct
block|{
name|u_int
name|i_opcd
range|:
literal|6
decl_stmt|;
name|int
label|:
literal|24
expr_stmt|;
name|int
name|i_i
range|:
literal|1
decl_stmt|;
name|int
label|:
literal|1
expr_stmt|;
block|}
name|i_s
struct|;
comment|/* 	 * Format X 	 */
struct|struct
block|{
name|u_int
name|i_opcd
range|:
literal|6
decl_stmt|;
name|u_int
name|i_rs
range|:
literal|5
decl_stmt|;
name|u_int
name|i_ra
range|:
literal|5
decl_stmt|;
name|u_int
name|i_rb
range|:
literal|5
decl_stmt|;
name|u_int
name|i_xo
range|:
literal|10
decl_stmt|;
name|u_int
name|i_rc
range|:
literal|1
decl_stmt|;
block|}
name|i_x
struct|;
comment|/* 	 * Format XFL 	 */
struct|struct
block|{
name|u_int
name|i_opcd
range|:
literal|6
decl_stmt|;
name|int
label|:
literal|1
expr_stmt|;
name|int
name|i_flm
range|:
literal|8
decl_stmt|;
name|int
label|:
literal|1
expr_stmt|;
name|int
name|i_frb
range|:
literal|5
decl_stmt|;
name|u_int
name|i_xo
range|:
literal|10
decl_stmt|;
name|int
label|:
literal|1
expr_stmt|;
block|}
name|i_xfl
struct|;
comment|/* 	 * Format XFX 	 */
struct|struct
block|{
name|u_int
name|i_opcd
range|:
literal|6
decl_stmt|;
name|int
name|i_dcrn
range|:
literal|10
decl_stmt|;
name|u_int
name|i_xo
range|:
literal|10
decl_stmt|;
name|int
label|:
literal|1
expr_stmt|;
block|}
name|i_xfx
struct|;
comment|/* 	 * Format XL 	 */
struct|struct
block|{
name|u_int
name|i_opcd
range|:
literal|6
decl_stmt|;
name|int
name|i_bt
range|:
literal|5
decl_stmt|;
name|int
name|i_ba
range|:
literal|5
decl_stmt|;
name|int
name|i_bb
range|:
literal|5
decl_stmt|;
name|u_int
name|i_xo
range|:
literal|10
decl_stmt|;
name|int
name|i_lk
range|:
literal|1
decl_stmt|;
block|}
name|i_xl
struct|;
comment|/* 	 * Format XS 	 */
struct|struct
block|{
name|u_int
name|i_opcd
range|:
literal|6
decl_stmt|;
name|u_int
name|i_rs
range|:
literal|5
decl_stmt|;
name|u_int
name|i_ra
range|:
literal|5
decl_stmt|;
name|int
name|i_sh0_4
range|:
literal|5
decl_stmt|;
name|u_int
name|i_xo
range|:
literal|9
decl_stmt|;
name|int
name|i_sh5
range|:
literal|1
decl_stmt|;
name|u_int
name|i_rc
range|:
literal|1
decl_stmt|;
block|}
name|i_xs
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|i_rt
value|i_rs
end_define

begin_comment
comment|/*  * Primary opcode numbers:  */
end_comment

begin_define
define|#
directive|define
name|OPC_TDI
value|0x02
end_define

begin_define
define|#
directive|define
name|OPC_TWI
value|0x03
end_define

begin_define
define|#
directive|define
name|OPC_MULLI
value|0x07
end_define

begin_define
define|#
directive|define
name|OPC_SUBFIC
value|0x08
end_define

begin_define
define|#
directive|define
name|OPC_BCE
value|0x09
end_define

begin_define
define|#
directive|define
name|OPC_CMPLI
value|0x0a
end_define

begin_define
define|#
directive|define
name|OPC_CMPI
value|0x0b
end_define

begin_define
define|#
directive|define
name|OPC_ADDIC
value|0x0c
end_define

begin_define
define|#
directive|define
name|OPC_ADDIC_DOT
value|0x0d
end_define

begin_define
define|#
directive|define
name|OPC_ADDI
value|0x0e
end_define

begin_define
define|#
directive|define
name|OPC_ADDIS
value|0x0f
end_define

begin_define
define|#
directive|define
name|OPC_BC
value|0x10
end_define

begin_define
define|#
directive|define
name|OPC_SC
value|0x11
end_define

begin_define
define|#
directive|define
name|OPC_B
value|0x12
end_define

begin_define
define|#
directive|define
name|OPC_branch_19
value|0x13
end_define

begin_define
define|#
directive|define
name|OPC_RLWIMI
value|0x14
end_define

begin_define
define|#
directive|define
name|OPC_RLWINM
value|0x15
end_define

begin_define
define|#
directive|define
name|OPC_BE
value|0x16
end_define

begin_define
define|#
directive|define
name|OPC_RLWNM
value|0x17
end_define

begin_define
define|#
directive|define
name|OPC_ORI
value|0x18
end_define

begin_define
define|#
directive|define
name|OPC_ORIS
value|0x19
end_define

begin_define
define|#
directive|define
name|OPC_XORI
value|0x1a
end_define

begin_define
define|#
directive|define
name|OPC_XORIS
value|0x1b
end_define

begin_define
define|#
directive|define
name|OPC_ANDI
value|0x1c
end_define

begin_define
define|#
directive|define
name|OPC_ANDIS
value|0x1d
end_define

begin_define
define|#
directive|define
name|OPC_dwe_rot_30
value|0x1e
end_define

begin_define
define|#
directive|define
name|OPC_integer_31
value|0x1f
end_define

begin_define
define|#
directive|define
name|OPC_LWZ
value|0x20
end_define

begin_define
define|#
directive|define
name|OPC_LWZU
value|0x21
end_define

begin_define
define|#
directive|define
name|OPC_LBZ
value|0x22
end_define

begin_define
define|#
directive|define
name|OPC_LBZU
value|0x23
end_define

begin_define
define|#
directive|define
name|OPC_STW
value|0x24
end_define

begin_define
define|#
directive|define
name|OPC_STWU
value|0x25
end_define

begin_define
define|#
directive|define
name|OPC_STB
value|0x26
end_define

begin_define
define|#
directive|define
name|OPC_STBU
value|0x27
end_define

begin_define
define|#
directive|define
name|OPC_LHZ
value|0x28
end_define

begin_define
define|#
directive|define
name|OPC_LHZU
value|0x29
end_define

begin_define
define|#
directive|define
name|OPC_LHA
value|0x2a
end_define

begin_define
define|#
directive|define
name|OPC_LHAU
value|0x2b
end_define

begin_define
define|#
directive|define
name|OPC_STH
value|0x2c
end_define

begin_define
define|#
directive|define
name|OPC_STHU
value|0x2d
end_define

begin_define
define|#
directive|define
name|OPC_LMW
value|0x2e
end_define

begin_define
define|#
directive|define
name|OPC_STMW
value|0x2f
end_define

begin_define
define|#
directive|define
name|OPC_LFS
value|0x30
end_define

begin_define
define|#
directive|define
name|OPC_LFSU
value|0x31
end_define

begin_define
define|#
directive|define
name|OPC_LFD
value|0x32
end_define

begin_define
define|#
directive|define
name|OPC_LFDU
value|0x33
end_define

begin_define
define|#
directive|define
name|OPC_STFS
value|0x34
end_define

begin_define
define|#
directive|define
name|OPC_STFSU
value|0x35
end_define

begin_define
define|#
directive|define
name|OPC_STFD
value|0x36
end_define

begin_define
define|#
directive|define
name|OPC_STFDU
value|0x37
end_define

begin_define
define|#
directive|define
name|OPC_load_st_58
value|0x3a
end_define

begin_define
define|#
directive|define
name|OPC_sp_fp_59
value|0x3b
end_define

begin_define
define|#
directive|define
name|OPC_load_st_62
value|0x3e
end_define

begin_define
define|#
directive|define
name|OPC_dp_fp_63
value|0x3f
end_define

begin_comment
comment|/*  * Opcode 31 sub-types (FP only)  */
end_comment

begin_define
define|#
directive|define
name|OPC31_TW
value|0x004
end_define

begin_define
define|#
directive|define
name|OPC31_LFSX
value|0x217
end_define

begin_define
define|#
directive|define
name|OPC31_LFSUX
value|0x237
end_define

begin_define
define|#
directive|define
name|OPC31_LFDX
value|0x257
end_define

begin_define
define|#
directive|define
name|OPC31_LFDUX
value|0x277
end_define

begin_define
define|#
directive|define
name|OPC31_STFSX
value|0x297
end_define

begin_define
define|#
directive|define
name|OPC31_STFSUX
value|0x2b7
end_define

begin_define
define|#
directive|define
name|OPC31_STFDX
value|0x2d7
end_define

begin_define
define|#
directive|define
name|OPC31_STFDUX
value|0x2f7
end_define

begin_define
define|#
directive|define
name|OPC31_STFIWX
value|0x3d7
end_define

begin_comment
comment|/* Mask for all valid indexed FP load/store ops (except stfiwx) */
end_comment

begin_define
define|#
directive|define
name|OPC31_FPMASK
value|0x31f
end_define

begin_define
define|#
directive|define
name|OPC31_FPOP
value|0x217
end_define

begin_comment
comment|/*  * Opcode 59 sub-types:  */
end_comment

begin_define
define|#
directive|define
name|OPC59_FDIVS
value|0x12
end_define

begin_define
define|#
directive|define
name|OPC59_FSUBS
value|0x14
end_define

begin_define
define|#
directive|define
name|OPC59_FADDS
value|0x15
end_define

begin_define
define|#
directive|define
name|OPC59_FSQRTS
value|0x16
end_define

begin_define
define|#
directive|define
name|OPC59_FRES
value|0x18
end_define

begin_define
define|#
directive|define
name|OPC59_FMULS
value|0x19
end_define

begin_define
define|#
directive|define
name|OPC59_FMSUBS
value|0x1c
end_define

begin_define
define|#
directive|define
name|OPC59_FMADDS
value|0x1d
end_define

begin_define
define|#
directive|define
name|OPC59_FNMSUBS
value|0x1e
end_define

begin_define
define|#
directive|define
name|OPC59_FNMADDS
value|0x1f
end_define

begin_comment
comment|/*  * Opcode 62 sub-types:  */
end_comment

begin_define
define|#
directive|define
name|OPC62_LDE
value|0x0
end_define

begin_define
define|#
directive|define
name|OPC62_LDEU
value|0x1
end_define

begin_define
define|#
directive|define
name|OPC62_LFSE
value|0x4
end_define

begin_define
define|#
directive|define
name|OPC62_LFSEU
value|0x5
end_define

begin_define
define|#
directive|define
name|OPC62_LFDE
value|0x6
end_define

begin_define
define|#
directive|define
name|OPC62_LFDEU
value|0x7
end_define

begin_define
define|#
directive|define
name|OPC62_STDE
value|0x8
end_define

begin_define
define|#
directive|define
name|OPC62_STDEU
value|0x9
end_define

begin_define
define|#
directive|define
name|OPC62_STFSE
value|0xc
end_define

begin_define
define|#
directive|define
name|OPC62_STFSEU
value|0xd
end_define

begin_define
define|#
directive|define
name|OPC62_STFDE
value|0xe
end_define

begin_define
define|#
directive|define
name|OPC62_STFDEU
value|0xf
end_define

begin_comment
comment|/*  * Opcode 63 sub-types:  *  * (The first group are masks....)  */
end_comment

begin_define
define|#
directive|define
name|OPC63M_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|OPC63M_FDIV
value|0x12
end_define

begin_define
define|#
directive|define
name|OPC63M_FSUB
value|0x14
end_define

begin_define
define|#
directive|define
name|OPC63M_FADD
value|0x15
end_define

begin_define
define|#
directive|define
name|OPC63M_FSQRT
value|0x16
end_define

begin_define
define|#
directive|define
name|OPC63M_FSEL
value|0x17
end_define

begin_define
define|#
directive|define
name|OPC63M_FMUL
value|0x19
end_define

begin_define
define|#
directive|define
name|OPC63M_FRSQRTE
value|0x1a
end_define

begin_define
define|#
directive|define
name|OPC63M_FMSUB
value|0x1c
end_define

begin_define
define|#
directive|define
name|OPC63M_FMADD
value|0x1d
end_define

begin_define
define|#
directive|define
name|OPC63M_FNMSUB
value|0x1e
end_define

begin_define
define|#
directive|define
name|OPC63M_FNMADD
value|0x1f
end_define

begin_define
define|#
directive|define
name|OPC63_FCMPU
value|0x00
end_define

begin_define
define|#
directive|define
name|OPC63_FRSP
value|0x0c
end_define

begin_define
define|#
directive|define
name|OPC63_FCTIW
value|0x0e
end_define

begin_define
define|#
directive|define
name|OPC63_FCTIWZ
value|0x0f
end_define

begin_define
define|#
directive|define
name|OPC63_FCMPO
value|0x20
end_define

begin_define
define|#
directive|define
name|OPC63_MTFSB1
value|0x26
end_define

begin_define
define|#
directive|define
name|OPC63_FNEG
value|0x28
end_define

begin_define
define|#
directive|define
name|OPC63_MCRFS
value|0x40
end_define

begin_define
define|#
directive|define
name|OPC63_MTFSB0
value|0x46
end_define

begin_define
define|#
directive|define
name|OPC63_FMR
value|0x48
end_define

begin_define
define|#
directive|define
name|OPC63_MTFSFI
value|0x86
end_define

begin_define
define|#
directive|define
name|OPC63_FNABS
value|0x88
end_define

begin_define
define|#
directive|define
name|OPC63_FABS
value|0x108
end_define

begin_define
define|#
directive|define
name|OPC63_MFFS
value|0x247
end_define

begin_define
define|#
directive|define
name|OPC63_MTFSF
value|0x2c7
end_define

begin_define
define|#
directive|define
name|OPC63_FCTID
value|0x32e
end_define

begin_define
define|#
directive|define
name|OPC63_FCTIDZ
value|0x32f
end_define

begin_define
define|#
directive|define
name|OPC63_FCFID
value|0x34e
end_define

begin_comment
comment|/*  * FPU data types.  */
end_comment

begin_define
define|#
directive|define
name|FTYPE_LNG
value|-1
end_define

begin_comment
comment|/* data = 64-bit signed long integer */
end_comment

begin_define
define|#
directive|define
name|FTYPE_INT
value|0
end_define

begin_comment
comment|/* data = 32-bit signed integer */
end_comment

begin_define
define|#
directive|define
name|FTYPE_SNG
value|1
end_define

begin_comment
comment|/* data = 32-bit float */
end_comment

begin_define
define|#
directive|define
name|FTYPE_DBL
value|2
end_define

begin_comment
comment|/* data = 64-bit double */
end_comment

end_unit

