begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: x86emu_regs.h,v 1.1 2007/12/01 20:14:10 joerg Exp $	*/
end_comment

begin_comment
comment|/*	$OpenBSD: x86emu_regs.h,v 1.2 2009/06/06 03:45:05 matthieu Exp $ */
end_comment

begin_comment
comment|/**************************************************************************** * *  Realmode X86 Emulator Library * *  Copyright (C) 1996-1999 SciTech Software, Inc. *  Copyright (C) David Mosberger-Tang *  Copyright (C) 1999 Egbert Eich *  Copyright (C) 2007 Joerg Sonnenberger * *  ======================================================================== * *  Permission to use, copy, modify, distribute, and sell this software and *  its documentation for any purpose is hereby granted without fee, *  provided that the above copyright notice appear in all copies and that *  both that copyright notice and this permission notice appear in *  supporting documentation, and that the name of the authors not be used *  in advertising or publicity pertaining to distribution of the software *  without specific, written prior permission.  The authors makes no *  representations about the suitability of this software for any purpose. *  It is provided "as is" without express or implied warranty. * *  THE AUTHORS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, *  INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO *  EVENT SHALL THE AUTHORS BE LIABLE FOR ANY SPECIAL, INDIRECT OR *  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF *  USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR *  OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR *  PERFORMANCE OF THIS SOFTWARE. * ****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__X86EMU_REGS_H
end_ifndef

begin_define
define|#
directive|define
name|__X86EMU_REGS_H
end_define

begin_comment
comment|/*---------------------- Macros and type definitions ----------------------*/
end_comment

begin_comment
comment|/* 8 bit registers */
end_comment

begin_define
define|#
directive|define
name|R_AH
value|register_a.I8_reg.h_reg
end_define

begin_define
define|#
directive|define
name|R_AL
value|register_a.I8_reg.l_reg
end_define

begin_define
define|#
directive|define
name|R_BH
value|register_b.I8_reg.h_reg
end_define

begin_define
define|#
directive|define
name|R_BL
value|register_b.I8_reg.l_reg
end_define

begin_define
define|#
directive|define
name|R_CH
value|register_c.I8_reg.h_reg
end_define

begin_define
define|#
directive|define
name|R_CL
value|register_c.I8_reg.l_reg
end_define

begin_define
define|#
directive|define
name|R_DH
value|register_d.I8_reg.h_reg
end_define

begin_define
define|#
directive|define
name|R_DL
value|register_d.I8_reg.l_reg
end_define

begin_comment
comment|/* 16 bit registers */
end_comment

begin_define
define|#
directive|define
name|R_AX
value|register_a.I16_reg.x_reg
end_define

begin_define
define|#
directive|define
name|R_BX
value|register_b.I16_reg.x_reg
end_define

begin_define
define|#
directive|define
name|R_CX
value|register_c.I16_reg.x_reg
end_define

begin_define
define|#
directive|define
name|R_DX
value|register_d.I16_reg.x_reg
end_define

begin_comment
comment|/* 32 bit extended registers */
end_comment

begin_define
define|#
directive|define
name|R_EAX
value|register_a.I32_reg.e_reg
end_define

begin_define
define|#
directive|define
name|R_EBX
value|register_b.I32_reg.e_reg
end_define

begin_define
define|#
directive|define
name|R_ECX
value|register_c.I32_reg.e_reg
end_define

begin_define
define|#
directive|define
name|R_EDX
value|register_d.I32_reg.e_reg
end_define

begin_comment
comment|/* special registers */
end_comment

begin_define
define|#
directive|define
name|R_SP
value|register_sp.I16_reg.x_reg
end_define

begin_define
define|#
directive|define
name|R_BP
value|register_bp.I16_reg.x_reg
end_define

begin_define
define|#
directive|define
name|R_SI
value|register_si.I16_reg.x_reg
end_define

begin_define
define|#
directive|define
name|R_DI
value|register_di.I16_reg.x_reg
end_define

begin_define
define|#
directive|define
name|R_IP
value|register_ip.I16_reg.x_reg
end_define

begin_define
define|#
directive|define
name|R_FLG
value|register_flags
end_define

begin_comment
comment|/* special registers */
end_comment

begin_define
define|#
directive|define
name|R_ESP
value|register_sp.I32_reg.e_reg
end_define

begin_define
define|#
directive|define
name|R_EBP
value|register_bp.I32_reg.e_reg
end_define

begin_define
define|#
directive|define
name|R_ESI
value|register_si.I32_reg.e_reg
end_define

begin_define
define|#
directive|define
name|R_EDI
value|register_di.I32_reg.e_reg
end_define

begin_define
define|#
directive|define
name|R_EIP
value|register_ip.I32_reg.e_reg
end_define

begin_define
define|#
directive|define
name|R_EFLG
value|register_flags
end_define

begin_comment
comment|/* segment registers */
end_comment

begin_define
define|#
directive|define
name|R_CS
value|register_cs
end_define

begin_define
define|#
directive|define
name|R_DS
value|register_ds
end_define

begin_define
define|#
directive|define
name|R_SS
value|register_ss
end_define

begin_define
define|#
directive|define
name|R_ES
value|register_es
end_define

begin_define
define|#
directive|define
name|R_FS
value|register_fs
end_define

begin_define
define|#
directive|define
name|R_GS
value|register_gs
end_define

begin_comment
comment|/* flag conditions   */
end_comment

begin_define
define|#
directive|define
name|FB_CF
value|0x0001
end_define

begin_comment
comment|/* CARRY flag  */
end_comment

begin_define
define|#
directive|define
name|FB_PF
value|0x0004
end_define

begin_comment
comment|/* PARITY flag */
end_comment

begin_define
define|#
directive|define
name|FB_AF
value|0x0010
end_define

begin_comment
comment|/* AUX  flag   */
end_comment

begin_define
define|#
directive|define
name|FB_ZF
value|0x0040
end_define

begin_comment
comment|/* ZERO flag   */
end_comment

begin_define
define|#
directive|define
name|FB_SF
value|0x0080
end_define

begin_comment
comment|/* SIGN flag   */
end_comment

begin_define
define|#
directive|define
name|FB_TF
value|0x0100
end_define

begin_comment
comment|/* TRAP flag   */
end_comment

begin_define
define|#
directive|define
name|FB_IF
value|0x0200
end_define

begin_comment
comment|/* INTERRUPT ENABLE flag */
end_comment

begin_define
define|#
directive|define
name|FB_DF
value|0x0400
end_define

begin_comment
comment|/* DIR flag    */
end_comment

begin_define
define|#
directive|define
name|FB_OF
value|0x0800
end_define

begin_comment
comment|/* OVERFLOW flag */
end_comment

begin_comment
comment|/* 80286 and above always have bit#1 set */
end_comment

begin_define
define|#
directive|define
name|F_ALWAYS_ON
value|(0x0002)
end_define

begin_comment
comment|/* flag bits always on */
end_comment

begin_comment
comment|/*  * Define a mask for only those flag bits we will ever pass back   * (via PUSHF)   */
end_comment

begin_define
define|#
directive|define
name|F_MSK
value|(FB_CF|FB_PF|FB_AF|FB_ZF|FB_SF|FB_TF|FB_IF|FB_DF|FB_OF)
end_define

begin_comment
comment|/* following bits masked in to a 16bit quantity */
end_comment

begin_define
define|#
directive|define
name|F_CF
value|0x0001
end_define

begin_comment
comment|/* CARRY flag  */
end_comment

begin_define
define|#
directive|define
name|F_PF
value|0x0004
end_define

begin_comment
comment|/* PARITY flag */
end_comment

begin_define
define|#
directive|define
name|F_AF
value|0x0010
end_define

begin_comment
comment|/* AUX  flag   */
end_comment

begin_define
define|#
directive|define
name|F_ZF
value|0x0040
end_define

begin_comment
comment|/* ZERO flag   */
end_comment

begin_define
define|#
directive|define
name|F_SF
value|0x0080
end_define

begin_comment
comment|/* SIGN flag   */
end_comment

begin_define
define|#
directive|define
name|F_TF
value|0x0100
end_define

begin_comment
comment|/* TRAP flag   */
end_comment

begin_define
define|#
directive|define
name|F_IF
value|0x0200
end_define

begin_comment
comment|/* INTERRUPT ENABLE flag */
end_comment

begin_define
define|#
directive|define
name|F_DF
value|0x0400
end_define

begin_comment
comment|/* DIR flag    */
end_comment

begin_define
define|#
directive|define
name|F_OF
value|0x0800
end_define

begin_comment
comment|/* OVERFLOW flag */
end_comment

begin_define
define|#
directive|define
name|SET_FLAG
parameter_list|(
name|flag
parameter_list|)
value|(emu->x86.R_FLG |= (flag))
end_define

begin_define
define|#
directive|define
name|CLEAR_FLAG
parameter_list|(
name|flag
parameter_list|)
value|(emu->x86.R_FLG&= ~(flag))
end_define

begin_define
define|#
directive|define
name|ACCESS_FLAG
parameter_list|(
name|flag
parameter_list|)
value|(emu->x86.R_FLG& (flag))
end_define

begin_define
define|#
directive|define
name|CLEARALL_FLAG
parameter_list|(
name|m
parameter_list|)
value|(emu->x86.R_FLG = 0)
end_define

begin_define
define|#
directive|define
name|CONDITIONAL_SET_FLAG
parameter_list|(
name|COND
parameter_list|,
name|FLAG
parameter_list|)
define|\
value|if (COND) SET_FLAG(FLAG); else CLEAR_FLAG(FLAG)
end_define

begin_define
define|#
directive|define
name|F_PF_CALC
value|0x010000
end_define

begin_comment
comment|/* PARITY flag has been calced    */
end_comment

begin_define
define|#
directive|define
name|F_ZF_CALC
value|0x020000
end_define

begin_comment
comment|/* ZERO flag has been calced      */
end_comment

begin_define
define|#
directive|define
name|F_SF_CALC
value|0x040000
end_define

begin_comment
comment|/* SIGN flag has been calced      */
end_comment

begin_define
define|#
directive|define
name|F_ALL_CALC
value|0xff0000
end_define

begin_comment
comment|/* All have been calced   */
end_comment

begin_comment
comment|/*  * Emulator machine state.  * Segment usage control.  */
end_comment

begin_define
define|#
directive|define
name|SYSMODE_SEG_DS_SS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SYSMODE_SEGOVR_CS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SYSMODE_SEGOVR_DS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SYSMODE_SEGOVR_ES
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SYSMODE_SEGOVR_FS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SYSMODE_SEGOVR_GS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SYSMODE_SEGOVR_SS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SYSMODE_PREFIX_REPE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SYSMODE_PREFIX_REPNE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SYSMODE_PREFIX_DATA
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SYSMODE_PREFIX_ADDR
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SYSMODE_INTR_PENDING
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SYSMODE_EXTRN_INTR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SYSMODE_HALTED
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SYSMODE_SEGMASK
value|(SYSMODE_SEG_DS_SS      | \ 						 SYSMODE_SEGOVR_CS      | \ 						 SYSMODE_SEGOVR_DS      | \ 						 SYSMODE_SEGOVR_ES      | \ 						 SYSMODE_SEGOVR_FS      | \ 						 SYSMODE_SEGOVR_GS      | \ 						 SYSMODE_SEGOVR_SS)
end_define

begin_define
define|#
directive|define
name|SYSMODE_CLRMASK
value|(SYSMODE_SEG_DS_SS      | \ 						 SYSMODE_SEGOVR_CS      | \ 						 SYSMODE_SEGOVR_DS      | \ 						 SYSMODE_SEGOVR_ES      | \ 						 SYSMODE_SEGOVR_FS      | \ 						 SYSMODE_SEGOVR_GS      | \ 						 SYSMODE_SEGOVR_SS      | \ 						 SYSMODE_PREFIX_DATA    | \ 						 SYSMODE_PREFIX_ADDR)
end_define

begin_define
define|#
directive|define
name|INTR_SYNCH
value|0x1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __X86EMU_REGS_H */
end_comment

end_unit

