begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $NetBSD: spr.h,v 1.25 2002/08/14 15:38:40 matt Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_SPR_H_
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_SPR_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_define
define|#
directive|define
name|mtspr
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|__asm __volatile("mtspr %0,%1" : : "K"(reg), "r"(val))
end_define

begin_define
define|#
directive|define
name|mfspr
parameter_list|(
name|reg
parameter_list|)
define|\
value|( { register_t val;						\ 	  __asm __volatile("mfspr %0,%1" : "=r"(val) : "K"(reg));	\ 	  val; } )
end_define

begin_comment
comment|/* The following routines allow manipulation of the full 64-bit width   * of SPRs on 64 bit CPUs in bridge mode */
end_comment

begin_define
define|#
directive|define
name|mtspr64
parameter_list|(
name|reg
parameter_list|,
name|valhi
parameter_list|,
name|vallo
parameter_list|,
name|scratch
parameter_list|)
define|\
value|__asm __volatile("						\ 		mfmsr %0; 						\ 		insrdi %0,%5,1,0; 					\ 		mtmsrd %0; 						\ 		isync; 							\ 									\ 		sld %1,%1,%4;						\ 		or %1,%1,%2;						\ 		mtspr %3,%1;						\ 		srd %1,%1,%4;						\ 									\ 		clrldi %0,%0,1; 					\ 		mtmsrd %0; 						\ 		isync;"							\ 	: "=r"(scratch), "=r"(valhi) : "r"(vallo), "K"(reg), "r"(32), "r"(1))
end_define

begin_define
define|#
directive|define
name|mfspr64upper
parameter_list|(
name|reg
parameter_list|,
name|scratch
parameter_list|)
define|\
value|( { register_t val;						\ 	    __asm __volatile("						\ 		mfmsr %0; 						\ 		insrdi %0,%4,1,0; 					\ 		mtmsrd %0; 						\ 		isync; 							\ 									\ 		mfspr %1,%2;						\ 		srd %1,%1,%3;						\ 									\ 		clrldi %0,%0,1; 					\ 		mtmsrd %0; 						\ 		isync;" 						\ 	    : "=r"(scratch), "=r"(val) : "K"(reg), "r"(32), "r"(1));	\ 	    val; } )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LOCORE */
end_comment

begin_comment
comment|/*  * Special Purpose Register declarations.  *  * The first column in the comments indicates which PowerPC  * architectures the SPR is valid on - 4 for 4xx series,  * 6 for 6xx/7xx series and 8 for 8xx and 8xxx series.  */
end_comment

begin_define
define|#
directive|define
name|SPR_MQ
value|0x000
end_define

begin_comment
comment|/* .6. 601 MQ register */
end_comment

begin_define
define|#
directive|define
name|SPR_XER
value|0x001
end_define

begin_comment
comment|/* 468 Fixed Point Exception Register */
end_comment

begin_define
define|#
directive|define
name|SPR_RTCU_R
value|0x004
end_define

begin_comment
comment|/* .6. 601 RTC Upper - Read */
end_comment

begin_define
define|#
directive|define
name|SPR_RTCL_R
value|0x005
end_define

begin_comment
comment|/* .6. 601 RTC Lower - Read */
end_comment

begin_define
define|#
directive|define
name|SPR_LR
value|0x008
end_define

begin_comment
comment|/* 468 Link Register */
end_comment

begin_define
define|#
directive|define
name|SPR_CTR
value|0x009
end_define

begin_comment
comment|/* 468 Count Register */
end_comment

begin_define
define|#
directive|define
name|SPR_DSISR
value|0x012
end_define

begin_comment
comment|/* .68 DSI exception source */
end_comment

begin_define
define|#
directive|define
name|DSISR_DIRECT
value|0x80000000
end_define

begin_comment
comment|/* Direct-store error exception */
end_comment

begin_define
define|#
directive|define
name|DSISR_NOTFOUND
value|0x40000000
end_define

begin_comment
comment|/* Translation not found */
end_comment

begin_define
define|#
directive|define
name|DSISR_PROTECT
value|0x08000000
end_define

begin_comment
comment|/* Memory access not permitted */
end_comment

begin_define
define|#
directive|define
name|DSISR_INVRX
value|0x04000000
end_define

begin_comment
comment|/* Reserve-indexed insn direct-store access */
end_comment

begin_define
define|#
directive|define
name|DSISR_STORE
value|0x02000000
end_define

begin_comment
comment|/* Store operation */
end_comment

begin_define
define|#
directive|define
name|DSISR_DABR
value|0x00400000
end_define

begin_comment
comment|/* DABR match */
end_comment

begin_define
define|#
directive|define
name|DSISR_SEGMENT
value|0x00200000
end_define

begin_comment
comment|/* XXX; not in 6xx PEM */
end_comment

begin_define
define|#
directive|define
name|DSISR_EAR
value|0x00100000
end_define

begin_comment
comment|/* eciwx/ecowx&& EAR[E] == 0 */
end_comment

begin_define
define|#
directive|define
name|SPR_DAR
value|0x013
end_define

begin_comment
comment|/* .68 Data Address Register */
end_comment

begin_define
define|#
directive|define
name|SPR_RTCU_W
value|0x014
end_define

begin_comment
comment|/* .6. 601 RTC Upper - Write */
end_comment

begin_define
define|#
directive|define
name|SPR_RTCL_W
value|0x015
end_define

begin_comment
comment|/* .6. 601 RTC Lower - Write */
end_comment

begin_define
define|#
directive|define
name|SPR_DEC
value|0x016
end_define

begin_comment
comment|/* .68 DECrementer register */
end_comment

begin_define
define|#
directive|define
name|SPR_SDR1
value|0x019
end_define

begin_comment
comment|/* .68 Page table base address register */
end_comment

begin_define
define|#
directive|define
name|SPR_SRR0
value|0x01a
end_define

begin_comment
comment|/* 468 Save/Restore Register 0 */
end_comment

begin_define
define|#
directive|define
name|SPR_SRR1
value|0x01b
end_define

begin_comment
comment|/* 468 Save/Restore Register 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_DECAR
value|0x036
end_define

begin_comment
comment|/* ..8 Decrementer auto reload */
end_comment

begin_define
define|#
directive|define
name|SPR_EIE
value|0x050
end_define

begin_comment
comment|/* ..8 Exception Interrupt ??? */
end_comment

begin_define
define|#
directive|define
name|SPR_EID
value|0x051
end_define

begin_comment
comment|/* ..8 Exception Interrupt ??? */
end_comment

begin_define
define|#
directive|define
name|SPR_NRI
value|0x052
end_define

begin_comment
comment|/* ..8 Exception Interrupt ??? */
end_comment

begin_define
define|#
directive|define
name|SPR_USPRG0
value|0x100
end_define

begin_comment
comment|/* 4.. User SPR General 0 */
end_comment

begin_define
define|#
directive|define
name|SPR_VRSAVE
value|0x100
end_define

begin_comment
comment|/* .6. AltiVec VRSAVE */
end_comment

begin_define
define|#
directive|define
name|SPR_SPRG0
value|0x110
end_define

begin_comment
comment|/* 468 SPR General 0 */
end_comment

begin_define
define|#
directive|define
name|SPR_SPRG1
value|0x111
end_define

begin_comment
comment|/* 468 SPR General 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_SPRG2
value|0x112
end_define

begin_comment
comment|/* 468 SPR General 2 */
end_comment

begin_define
define|#
directive|define
name|SPR_SPRG3
value|0x113
end_define

begin_comment
comment|/* 468 SPR General 3 */
end_comment

begin_define
define|#
directive|define
name|SPR_SPRG4
value|0x114
end_define

begin_comment
comment|/* 4.. SPR General 4 */
end_comment

begin_define
define|#
directive|define
name|SPR_SPRG5
value|0x115
end_define

begin_comment
comment|/* 4.. SPR General 5 */
end_comment

begin_define
define|#
directive|define
name|SPR_SPRG6
value|0x116
end_define

begin_comment
comment|/* 4.. SPR General 6 */
end_comment

begin_define
define|#
directive|define
name|SPR_SPRG7
value|0x117
end_define

begin_comment
comment|/* 4.. SPR General 7 */
end_comment

begin_define
define|#
directive|define
name|SPR_SCOMC
value|0x114
end_define

begin_comment
comment|/* ... SCOM Address Register (970) */
end_comment

begin_define
define|#
directive|define
name|SPR_SCOMD
value|0x115
end_define

begin_comment
comment|/* ... SCOM Data Register (970) */
end_comment

begin_define
define|#
directive|define
name|SPR_ASR
value|0x118
end_define

begin_comment
comment|/* ... Address Space Register (PPC64) */
end_comment

begin_define
define|#
directive|define
name|SPR_EAR
value|0x11a
end_define

begin_comment
comment|/* .68 External Access Register */
end_comment

begin_define
define|#
directive|define
name|SPR_PVR
value|0x11f
end_define

begin_comment
comment|/* 468 Processor Version Register */
end_comment

begin_define
define|#
directive|define
name|MPC601
value|0x0001
end_define

begin_define
define|#
directive|define
name|MPC603
value|0x0003
end_define

begin_define
define|#
directive|define
name|MPC604
value|0x0004
end_define

begin_define
define|#
directive|define
name|MPC602
value|0x0005
end_define

begin_define
define|#
directive|define
name|MPC603e
value|0x0006
end_define

begin_define
define|#
directive|define
name|MPC603ev
value|0x0007
end_define

begin_define
define|#
directive|define
name|MPC750
value|0x0008
end_define

begin_define
define|#
directive|define
name|MPC604ev
value|0x0009
end_define

begin_define
define|#
directive|define
name|MPC7400
value|0x000c
end_define

begin_define
define|#
directive|define
name|MPC620
value|0x0014
end_define

begin_define
define|#
directive|define
name|IBM403
value|0x0020
end_define

begin_define
define|#
directive|define
name|IBM401A1
value|0x0021
end_define

begin_define
define|#
directive|define
name|IBM401B2
value|0x0022
end_define

begin_define
define|#
directive|define
name|IBM401C2
value|0x0023
end_define

begin_define
define|#
directive|define
name|IBM401D2
value|0x0024
end_define

begin_define
define|#
directive|define
name|IBM401E2
value|0x0025
end_define

begin_define
define|#
directive|define
name|IBM401F2
value|0x0026
end_define

begin_define
define|#
directive|define
name|IBM401G2
value|0x0027
end_define

begin_define
define|#
directive|define
name|IBM970
value|0x0039
end_define

begin_define
define|#
directive|define
name|IBM970FX
value|0x003c
end_define

begin_define
define|#
directive|define
name|IBMPOWER3
value|0x0041
end_define

begin_define
define|#
directive|define
name|IBM970MP
value|0x0044
end_define

begin_define
define|#
directive|define
name|IBM970GX
value|0x0045
end_define

begin_define
define|#
directive|define
name|MPC860
value|0x0050
end_define

begin_define
define|#
directive|define
name|MPC8240
value|0x0081
end_define

begin_define
define|#
directive|define
name|IBM405GP
value|0x4011
end_define

begin_define
define|#
directive|define
name|IBM405L
value|0x4161
end_define

begin_define
define|#
directive|define
name|IBM750FX
value|0x7000
end_define

begin_define
define|#
directive|define
name|MPC745X_P
parameter_list|(
name|v
parameter_list|)
value|((v& 0xFFF8) == 0x8000)
end_define

begin_define
define|#
directive|define
name|MPC7450
value|0x8000
end_define

begin_define
define|#
directive|define
name|MPC7455
value|0x8001
end_define

begin_define
define|#
directive|define
name|MPC7457
value|0x8002
end_define

begin_define
define|#
directive|define
name|MPC7447A
value|0x8003
end_define

begin_define
define|#
directive|define
name|MPC7448
value|0x8004
end_define

begin_define
define|#
directive|define
name|MPC7410
value|0x800c
end_define

begin_define
define|#
directive|define
name|MPC8245
value|0x8081
end_define

begin_define
define|#
directive|define
name|FSL_E500v1
value|0x8020
end_define

begin_define
define|#
directive|define
name|FSL_E500v2
value|0x8021
end_define

begin_define
define|#
directive|define
name|SPR_IBAT0U
value|0x210
end_define

begin_comment
comment|/* .68 Instruction BAT Reg 0 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT0U
value|0x210
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 0 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT0L
value|0x211
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 0 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT1U
value|0x212
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 1 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT1L
value|0x213
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 1 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT2U
value|0x214
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 2 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT2L
value|0x215
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 2 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT3U
value|0x216
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 3 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT3L
value|0x217
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 3 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT0U
value|0x218
end_define

begin_comment
comment|/* .6. Data BAT Reg 0 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT0L
value|0x219
end_define

begin_comment
comment|/* .6. Data BAT Reg 0 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT1U
value|0x21a
end_define

begin_comment
comment|/* .6. Data BAT Reg 1 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT1L
value|0x21b
end_define

begin_comment
comment|/* .6. Data BAT Reg 1 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT2U
value|0x21c
end_define

begin_comment
comment|/* .6. Data BAT Reg 2 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT2L
value|0x21d
end_define

begin_comment
comment|/* .6. Data BAT Reg 2 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT3U
value|0x21e
end_define

begin_comment
comment|/* .6. Data BAT Reg 3 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT3L
value|0x21f
end_define

begin_comment
comment|/* .6. Data BAT Reg 3 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_IC_CST
value|0x230
end_define

begin_comment
comment|/* ..8 Instruction Cache CSR */
end_comment

begin_define
define|#
directive|define
name|IC_CST_IEN
value|0x80000000
end_define

begin_comment
comment|/* I cache is ENabled   (RO) */
end_comment

begin_define
define|#
directive|define
name|IC_CST_CMD_INVALL
value|0x0c000000
end_define

begin_comment
comment|/* I cache invalidate all */
end_comment

begin_define
define|#
directive|define
name|IC_CST_CMD_UNLOCKALL
value|0x0a000000
end_define

begin_comment
comment|/* I cache unlock all */
end_comment

begin_define
define|#
directive|define
name|IC_CST_CMD_UNLOCK
value|0x08000000
end_define

begin_comment
comment|/* I cache unlock block */
end_comment

begin_define
define|#
directive|define
name|IC_CST_CMD_LOADLOCK
value|0x06000000
end_define

begin_comment
comment|/* I cache load& lock block */
end_comment

begin_define
define|#
directive|define
name|IC_CST_CMD_DISABLE
value|0x04000000
end_define

begin_comment
comment|/* I cache disable */
end_comment

begin_define
define|#
directive|define
name|IC_CST_CMD_ENABLE
value|0x02000000
end_define

begin_comment
comment|/* I cache enable */
end_comment

begin_define
define|#
directive|define
name|IC_CST_CCER1
value|0x00200000
end_define

begin_comment
comment|/* I cache error type 1 (RO) */
end_comment

begin_define
define|#
directive|define
name|IC_CST_CCER2
value|0x00100000
end_define

begin_comment
comment|/* I cache error type 2 (RO) */
end_comment

begin_define
define|#
directive|define
name|IC_CST_CCER3
value|0x00080000
end_define

begin_comment
comment|/* I cache error type 3 (RO) */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT4U
value|0x230
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 4 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_IC_ADR
value|0x231
end_define

begin_comment
comment|/* ..8 Instruction Cache Address */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT4L
value|0x231
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 4 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_IC_DAT
value|0x232
end_define

begin_comment
comment|/* ..8 Instruction Cache Data */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT5U
value|0x232
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 5 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT5L
value|0x233
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 5 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT6U
value|0x234
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 6 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT6L
value|0x235
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 6 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT7U
value|0x236
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 7 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_IBAT7L
value|0x237
end_define

begin_comment
comment|/* .6. Instruction BAT Reg 7 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_DC_CST
value|0x230
end_define

begin_comment
comment|/* ..8 Data Cache CSR */
end_comment

begin_define
define|#
directive|define
name|DC_CST_DEN
value|0x80000000
end_define

begin_comment
comment|/* D cache ENabled (RO) */
end_comment

begin_define
define|#
directive|define
name|DC_CST_DFWT
value|0x40000000
end_define

begin_comment
comment|/* D cache Force Write-Thru (RO) */
end_comment

begin_define
define|#
directive|define
name|DC_CST_LES
value|0x20000000
end_define

begin_comment
comment|/* D cache Little Endian Swap (RO) */
end_comment

begin_define
define|#
directive|define
name|DC_CST_CMD_FLUSH
value|0x0e000000
end_define

begin_comment
comment|/* D cache invalidate all */
end_comment

begin_define
define|#
directive|define
name|DC_CST_CMD_INVALL
value|0x0c000000
end_define

begin_comment
comment|/* D cache invalidate all */
end_comment

begin_define
define|#
directive|define
name|DC_CST_CMD_UNLOCKALL
value|0x0a000000
end_define

begin_comment
comment|/* D cache unlock all */
end_comment

begin_define
define|#
directive|define
name|DC_CST_CMD_UNLOCK
value|0x08000000
end_define

begin_comment
comment|/* D cache unlock block */
end_comment

begin_define
define|#
directive|define
name|DC_CST_CMD_CLRLESWAP
value|0x07000000
end_define

begin_comment
comment|/* D cache clr little-endian swap */
end_comment

begin_define
define|#
directive|define
name|DC_CST_CMD_LOADLOCK
value|0x06000000
end_define

begin_comment
comment|/* D cache load& lock block */
end_comment

begin_define
define|#
directive|define
name|DC_CST_CMD_SETLESWAP
value|0x05000000
end_define

begin_comment
comment|/* D cache set little-endian swap */
end_comment

begin_define
define|#
directive|define
name|DC_CST_CMD_DISABLE
value|0x04000000
end_define

begin_comment
comment|/* D cache disable */
end_comment

begin_define
define|#
directive|define
name|DC_CST_CMD_CLRFWT
value|0x03000000
end_define

begin_comment
comment|/* D cache clear forced write-thru */
end_comment

begin_define
define|#
directive|define
name|DC_CST_CMD_ENABLE
value|0x02000000
end_define

begin_comment
comment|/* D cache enable */
end_comment

begin_define
define|#
directive|define
name|DC_CST_CMD_SETFWT
value|0x01000000
end_define

begin_comment
comment|/* D cache set forced write-thru */
end_comment

begin_define
define|#
directive|define
name|DC_CST_CCER1
value|0x00200000
end_define

begin_comment
comment|/* D cache error type 1 (RO) */
end_comment

begin_define
define|#
directive|define
name|DC_CST_CCER2
value|0x00100000
end_define

begin_comment
comment|/* D cache error type 2 (RO) */
end_comment

begin_define
define|#
directive|define
name|DC_CST_CCER3
value|0x00080000
end_define

begin_comment
comment|/* D cache error type 3 (RO) */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT4U
value|0x238
end_define

begin_comment
comment|/* .6. Data BAT Reg 4 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_DC_ADR
value|0x231
end_define

begin_comment
comment|/* ..8 Data Cache Address */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT4L
value|0x239
end_define

begin_comment
comment|/* .6. Data BAT Reg 4 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_DC_DAT
value|0x232
end_define

begin_comment
comment|/* ..8 Data Cache Data */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT5U
value|0x23a
end_define

begin_comment
comment|/* .6. Data BAT Reg 5 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT5L
value|0x23b
end_define

begin_comment
comment|/* .6. Data BAT Reg 5 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT6U
value|0x23c
end_define

begin_comment
comment|/* .6. Data BAT Reg 6 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT6L
value|0x23d
end_define

begin_comment
comment|/* .6. Data BAT Reg 6 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT7U
value|0x23e
end_define

begin_comment
comment|/* .6. Data BAT Reg 7 Upper */
end_comment

begin_define
define|#
directive|define
name|SPR_DBAT7L
value|0x23f
end_define

begin_comment
comment|/* .6. Data BAT Reg 7 Lower */
end_comment

begin_define
define|#
directive|define
name|SPR_MI_CTR
value|0x310
end_define

begin_comment
comment|/* ..8 IMMU control */
end_comment

begin_define
define|#
directive|define
name|Mx_CTR_GPM
value|0x80000000
end_define

begin_comment
comment|/* Group Protection Mode */
end_comment

begin_define
define|#
directive|define
name|Mx_CTR_PPM
value|0x40000000
end_define

begin_comment
comment|/* Page Protection Mode */
end_comment

begin_define
define|#
directive|define
name|Mx_CTR_CIDEF
value|0x20000000
end_define

begin_comment
comment|/* Cache-Inhibit DEFault */
end_comment

begin_define
define|#
directive|define
name|MD_CTR_WTDEF
value|0x20000000
end_define

begin_comment
comment|/* Write-Through DEFault */
end_comment

begin_define
define|#
directive|define
name|Mx_CTR_RSV4
value|0x08000000
end_define

begin_comment
comment|/* Reserve 4 TLB entries */
end_comment

begin_define
define|#
directive|define
name|MD_CTR_TWAM
value|0x04000000
end_define

begin_comment
comment|/* TableWalk Assist Mode */
end_comment

begin_define
define|#
directive|define
name|Mx_CTR_PPCS
value|0x02000000
end_define

begin_comment
comment|/* Priv/user state compare mode */
end_comment

begin_define
define|#
directive|define
name|Mx_CTR_TLB_INDX
value|0x000001f0
end_define

begin_comment
comment|/* TLB index mask */
end_comment

begin_define
define|#
directive|define
name|Mx_CTR_TLB_INDX_BITPOS
value|8
end_define

begin_comment
comment|/* TLB index shift */
end_comment

begin_define
define|#
directive|define
name|SPR_MI_AP
value|0x312
end_define

begin_comment
comment|/* ..8 IMMU access protection */
end_comment

begin_define
define|#
directive|define
name|Mx_GP_SUPER
parameter_list|(
name|n
parameter_list|)
value|(0<< (2*(15-(n))))
end_define

begin_comment
comment|/* access is supervisor */
end_comment

begin_define
define|#
directive|define
name|Mx_GP_PAGE
value|(1<< (2*(15-(n))))
end_define

begin_comment
comment|/* access is page protect */
end_comment

begin_define
define|#
directive|define
name|Mx_GP_SWAPPED
value|(2<< (2*(15-(n))))
end_define

begin_comment
comment|/* access is swapped */
end_comment

begin_define
define|#
directive|define
name|Mx_GP_USER
value|(3<< (2*(15-(n))))
end_define

begin_comment
comment|/* access is user */
end_comment

begin_define
define|#
directive|define
name|SPR_MI_EPN
value|0x313
end_define

begin_comment
comment|/* ..8 IMMU effective number */
end_comment

begin_define
define|#
directive|define
name|Mx_EPN_EPN
value|0xfffff000
end_define

begin_comment
comment|/* Effective Page Number mask */
end_comment

begin_define
define|#
directive|define
name|Mx_EPN_EV
value|0x00000020
end_define

begin_comment
comment|/* Entry Valid */
end_comment

begin_define
define|#
directive|define
name|Mx_EPN_ASID
value|0x0000000f
end_define

begin_comment
comment|/* Address Space ID */
end_comment

begin_define
define|#
directive|define
name|SPR_MI_TWC
value|0x315
end_define

begin_comment
comment|/* ..8 IMMU tablewalk control */
end_comment

begin_define
define|#
directive|define
name|MD_TWC_L2TB
value|0xfffff000
end_define

begin_comment
comment|/* Level-2 Tablewalk Base */
end_comment

begin_define
define|#
directive|define
name|Mx_TWC_APG
value|0x000001e0
end_define

begin_comment
comment|/* Access Protection Group */
end_comment

begin_define
define|#
directive|define
name|Mx_TWC_G
value|0x00000010
end_define

begin_comment
comment|/* Guarded memory */
end_comment

begin_define
define|#
directive|define
name|Mx_TWC_PS
value|0x0000000c
end_define

begin_comment
comment|/* Page Size (L1) */
end_comment

begin_define
define|#
directive|define
name|MD_TWC_WT
value|0x00000002
end_define

begin_comment
comment|/* Write-Through */
end_comment

begin_define
define|#
directive|define
name|Mx_TWC_V
value|0x00000001
end_define

begin_comment
comment|/* Entry Valid */
end_comment

begin_define
define|#
directive|define
name|SPR_MI_RPN
value|0x316
end_define

begin_comment
comment|/* ..8 IMMU real (phys) page number */
end_comment

begin_define
define|#
directive|define
name|Mx_RPN_RPN
value|0xfffff000
end_define

begin_comment
comment|/* Real Page Number */
end_comment

begin_define
define|#
directive|define
name|Mx_RPN_PP
value|0x00000ff0
end_define

begin_comment
comment|/* Page Protection */
end_comment

begin_define
define|#
directive|define
name|Mx_RPN_SPS
value|0x00000008
end_define

begin_comment
comment|/* Small Page Size */
end_comment

begin_define
define|#
directive|define
name|Mx_RPN_SH
value|0x00000004
end_define

begin_comment
comment|/* SHared page */
end_comment

begin_define
define|#
directive|define
name|Mx_RPN_CI
value|0x00000002
end_define

begin_comment
comment|/* Cache Inhibit */
end_comment

begin_define
define|#
directive|define
name|Mx_RPN_V
value|0x00000001
end_define

begin_comment
comment|/* Valid */
end_comment

begin_define
define|#
directive|define
name|SPR_MD_CTR
value|0x318
end_define

begin_comment
comment|/* ..8 DMMU control */
end_comment

begin_define
define|#
directive|define
name|SPR_M_CASID
value|0x319
end_define

begin_comment
comment|/* ..8 CASID */
end_comment

begin_define
define|#
directive|define
name|M_CASID
value|0x0000000f
end_define

begin_comment
comment|/* Current AS Id */
end_comment

begin_define
define|#
directive|define
name|SPR_MD_AP
value|0x31a
end_define

begin_comment
comment|/* ..8 DMMU access protection */
end_comment

begin_define
define|#
directive|define
name|SPR_MD_EPN
value|0x31b
end_define

begin_comment
comment|/* ..8 DMMU effective number */
end_comment

begin_define
define|#
directive|define
name|SPR_M_TWB
value|0x31c
end_define

begin_comment
comment|/* ..8 MMU tablewalk base */
end_comment

begin_define
define|#
directive|define
name|M_TWB_L1TB
value|0xfffff000
end_define

begin_comment
comment|/* level-1 translation base */
end_comment

begin_define
define|#
directive|define
name|M_TWB_L1INDX
value|0x00000ffc
end_define

begin_comment
comment|/* level-1 index */
end_comment

begin_define
define|#
directive|define
name|SPR_MD_TWC
value|0x31d
end_define

begin_comment
comment|/* ..8 DMMU tablewalk control */
end_comment

begin_define
define|#
directive|define
name|SPR_MD_RPN
value|0x31e
end_define

begin_comment
comment|/* ..8 DMMU real (phys) page number */
end_comment

begin_define
define|#
directive|define
name|SPR_MD_TW
value|0x31f
end_define

begin_comment
comment|/* ..8 MMU tablewalk scratch */
end_comment

begin_define
define|#
directive|define
name|SPR_MI_CAM
value|0x330
end_define

begin_comment
comment|/* ..8 IMMU CAM entry read */
end_comment

begin_define
define|#
directive|define
name|SPR_MI_RAM0
value|0x331
end_define

begin_comment
comment|/* ..8 IMMU RAM entry read reg 0 */
end_comment

begin_define
define|#
directive|define
name|SPR_MI_RAM1
value|0x332
end_define

begin_comment
comment|/* ..8 IMMU RAM entry read reg 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_MD_CAM
value|0x338
end_define

begin_comment
comment|/* ..8 IMMU CAM entry read */
end_comment

begin_define
define|#
directive|define
name|SPR_MD_RAM0
value|0x339
end_define

begin_comment
comment|/* ..8 IMMU RAM entry read reg 0 */
end_comment

begin_define
define|#
directive|define
name|SPR_MD_RAM1
value|0x33a
end_define

begin_comment
comment|/* ..8 IMMU RAM entry read reg 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_UMMCR2
value|0x3a0
end_define

begin_comment
comment|/* .6. User Monitor Mode Control Register 2 */
end_comment

begin_define
define|#
directive|define
name|SPR_UMMCR0
value|0x3a8
end_define

begin_comment
comment|/* .6. User Monitor Mode Control Register 0 */
end_comment

begin_define
define|#
directive|define
name|SPR_USIA
value|0x3ab
end_define

begin_comment
comment|/* .6. User Sampled Instruction Address */
end_comment

begin_define
define|#
directive|define
name|SPR_UMMCR1
value|0x3ac
end_define

begin_comment
comment|/* .6. User Monitor Mode Control Register 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_ZPR
value|0x3b0
end_define

begin_comment
comment|/* 4.. Zone Protection Register */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR2
value|0x3b0
end_define

begin_comment
comment|/* .6. Monitor Mode Control Register 2 */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR2_THRESHMULT_32
value|0x80000000
end_define

begin_comment
comment|/* Multiply MMCR0 threshold by 32 */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR2_THRESHMULT_2
value|0x00000000
end_define

begin_comment
comment|/* Multiply MMCR0 threshold by 2 */
end_comment

begin_define
define|#
directive|define
name|SPR_PID
value|0x3b1
end_define

begin_comment
comment|/* 4.. Process ID */
end_comment

begin_define
define|#
directive|define
name|SPR_PMC5
value|0x3b1
end_define

begin_comment
comment|/* .6. Performance Counter Register 5 */
end_comment

begin_define
define|#
directive|define
name|SPR_PMC6
value|0x3b2
end_define

begin_comment
comment|/* .6. Performance Counter Register 6 */
end_comment

begin_define
define|#
directive|define
name|SPR_CCR0
value|0x3b3
end_define

begin_comment
comment|/* 4.. Core Configuration Register 0 */
end_comment

begin_define
define|#
directive|define
name|SPR_IAC3
value|0x3b4
end_define

begin_comment
comment|/* 4.. Instruction Address Compare 3 */
end_comment

begin_define
define|#
directive|define
name|SPR_IAC4
value|0x3b5
end_define

begin_comment
comment|/* 4.. Instruction Address Compare 4 */
end_comment

begin_define
define|#
directive|define
name|SPR_DVC1
value|0x3b6
end_define

begin_comment
comment|/* 4.. Data Value Compare 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_DVC2
value|0x3b7
end_define

begin_comment
comment|/* 4.. Data Value Compare 2 */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0
value|0x3b8
end_define

begin_comment
comment|/* .6. Monitor Mode Control Register 0 */
end_comment

begin_define
define|#
directive|define
name|SPR_970MMCR0
value|0x31b
end_define

begin_comment
comment|/* ... Monitor Mode Control Register 0 (PPC 970) */
end_comment

begin_define
define|#
directive|define
name|SPR_970MMCR1
value|0x31e
end_define

begin_comment
comment|/* ... Monitor Mode Control Register 1 (PPC 970) */
end_comment

begin_define
define|#
directive|define
name|SPR_970MMCRA
value|0x312
end_define

begin_comment
comment|/* ... Monitor Mode Control Register 2 (PPC 970) */
end_comment

begin_define
define|#
directive|define
name|SPR_970MMCR0
value|0x31b
end_define

begin_comment
comment|/* ... Monitor Mode Control Register 0 (PPC 970) */
end_comment

begin_define
define|#
directive|define
name|SPR_970PMC1
value|0x313
end_define

begin_comment
comment|/* ... PMC 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_970PMC2
value|0x314
end_define

begin_comment
comment|/* ... PMC 2 */
end_comment

begin_define
define|#
directive|define
name|SPR_970PMC3
value|0x315
end_define

begin_comment
comment|/* ... PMC 3 */
end_comment

begin_define
define|#
directive|define
name|SPR_970PMC4
value|0x316
end_define

begin_comment
comment|/* ... PMC 4 */
end_comment

begin_define
define|#
directive|define
name|SPR_970PMC5
value|0x317
end_define

begin_comment
comment|/* ... PMC 5 */
end_comment

begin_define
define|#
directive|define
name|SPR_970PMC6
value|0x318
end_define

begin_comment
comment|/* ... PMC 6 */
end_comment

begin_define
define|#
directive|define
name|SPR_970PMC7
value|0x319
end_define

begin_comment
comment|/* ... PMC 7 */
end_comment

begin_define
define|#
directive|define
name|SPR_970PMC8
value|0x31a
end_define

begin_comment
comment|/* ... PMC 8 */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_FC
value|0x80000000
end_define

begin_comment
comment|/* Freeze counters */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_FCS
value|0x40000000
end_define

begin_comment
comment|/* Freeze counters in supervisor mode */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_FCP
value|0x20000000
end_define

begin_comment
comment|/* Freeze counters in user mode */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_FCM1
value|0x10000000
end_define

begin_comment
comment|/* Freeze counters when mark=1 */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_FCM0
value|0x08000000
end_define

begin_comment
comment|/* Freeze counters when mark=0 */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_PMXE
value|0x04000000
end_define

begin_comment
comment|/* Enable PM interrupt */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_FCECE
value|0x02000000
end_define

begin_comment
comment|/* Freeze counters after event */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_TBSEL_15
value|0x01800000
end_define

begin_comment
comment|/* Count bit 15 of TBL */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_TBSEL_19
value|0x01000000
end_define

begin_comment
comment|/* Count bit 19 of TBL */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_TBSEL_23
value|0x00800000
end_define

begin_comment
comment|/* Count bit 23 of TBL */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_TBSEL_31
value|0x00000000
end_define

begin_comment
comment|/* Count bit 31 of TBL */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_TBEE
value|0x00400000
end_define

begin_comment
comment|/* Time-base event enable */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCRO_THRESHOLD
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_comment
comment|/* Threshold value */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_PMC1CE
value|0x00008000
end_define

begin_comment
comment|/* PMC1 condition enable */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_PMCNCE
value|0x00004000
end_define

begin_comment
comment|/* PMCn condition enable */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_TRIGGER
value|0x00002000
end_define

begin_comment
comment|/* Trigger */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_PMC1SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_comment
comment|/* PMC1 selector */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR0_PMC2SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_comment
comment|/* PMC2 selector */
end_comment

begin_define
define|#
directive|define
name|SPR_970MMCR0_PMC1SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_comment
comment|/* PMC1 selector (970) */
end_comment

begin_define
define|#
directive|define
name|SPR_970MMCR0_PMC2SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_comment
comment|/* PMC2 selector (970) */
end_comment

begin_define
define|#
directive|define
name|SPR_SGR
value|0x3b9
end_define

begin_comment
comment|/* 4.. Storage Guarded Register */
end_comment

begin_define
define|#
directive|define
name|SPR_PMC1
value|0x3b9
end_define

begin_comment
comment|/* .6. Performance Counter Register 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_DCWR
value|0x3ba
end_define

begin_comment
comment|/* 4.. Data Cache Write-through Register */
end_comment

begin_define
define|#
directive|define
name|SPR_PMC2
value|0x3ba
end_define

begin_comment
comment|/* .6. Performance Counter Register 2 */
end_comment

begin_define
define|#
directive|define
name|SPR_SLER
value|0x3bb
end_define

begin_comment
comment|/* 4.. Storage Little Endian Register */
end_comment

begin_define
define|#
directive|define
name|SPR_SIA
value|0x3bb
end_define

begin_comment
comment|/* .6. Sampled Instruction Address */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR1
value|0x3bc
end_define

begin_comment
comment|/* .6. Monitor Mode Control Register 2 */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR1_PMC3SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 27)
end_define

begin_comment
comment|/* PMC 3 selector */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR1_PMC4SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 22)
end_define

begin_comment
comment|/* PMC 4 selector */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR1_PMC5SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 17)
end_define

begin_comment
comment|/* PMC 5 selector */
end_comment

begin_define
define|#
directive|define
name|SPR_MMCR1_PMC6SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 11)
end_define

begin_comment
comment|/* PMC 6 selector */
end_comment

begin_define
define|#
directive|define
name|SPR_SU0R
value|0x3bc
end_define

begin_comment
comment|/* 4.. Storage User-defined 0 Register */
end_comment

begin_define
define|#
directive|define
name|SPR_PMC3
value|0x3bd
end_define

begin_comment
comment|/* .6. Performance Counter Register 3 */
end_comment

begin_define
define|#
directive|define
name|SPR_PMC4
value|0x3be
end_define

begin_comment
comment|/* .6. Performance Counter Register 4 */
end_comment

begin_define
define|#
directive|define
name|SPR_DMISS
value|0x3d0
end_define

begin_comment
comment|/* .68 Data TLB Miss Address Register */
end_comment

begin_define
define|#
directive|define
name|SPR_DCMP
value|0x3d1
end_define

begin_comment
comment|/* .68 Data TLB Compare Register */
end_comment

begin_define
define|#
directive|define
name|SPR_HASH1
value|0x3d2
end_define

begin_comment
comment|/* .68 Primary Hash Address Register */
end_comment

begin_define
define|#
directive|define
name|SPR_ICDBDR
value|0x3d3
end_define

begin_comment
comment|/* 4.. Instruction Cache Debug Data Register */
end_comment

begin_define
define|#
directive|define
name|SPR_HASH2
value|0x3d3
end_define

begin_comment
comment|/* .68 Secondary Hash Address Register */
end_comment

begin_define
define|#
directive|define
name|SPR_IMISS
value|0x3d4
end_define

begin_comment
comment|/* .68 Instruction TLB Miss Address Register */
end_comment

begin_define
define|#
directive|define
name|SPR_TLBMISS
value|0x3d4
end_define

begin_comment
comment|/* .6. TLB Miss Address Register */
end_comment

begin_define
define|#
directive|define
name|SPR_DEAR
value|0x3d5
end_define

begin_comment
comment|/* 4.. Data Error Address Register */
end_comment

begin_define
define|#
directive|define
name|SPR_ICMP
value|0x3d5
end_define

begin_comment
comment|/* .68 Instruction TLB Compare Register */
end_comment

begin_define
define|#
directive|define
name|SPR_PTEHI
value|0x3d5
end_define

begin_comment
comment|/* .6. Instruction TLB Compare Register */
end_comment

begin_define
define|#
directive|define
name|SPR_EVPR
value|0x3d6
end_define

begin_comment
comment|/* 4.. Exception Vector Prefix Register */
end_comment

begin_define
define|#
directive|define
name|SPR_RPA
value|0x3d6
end_define

begin_comment
comment|/* .68 Required Physical Address Register */
end_comment

begin_define
define|#
directive|define
name|SPR_PTELO
value|0x3d6
end_define

begin_comment
comment|/* .6. Required Physical Address Register */
end_comment

begin_define
define|#
directive|define
name|SPR_TSR
value|0x150
end_define

begin_comment
comment|/* ..8 Timer Status Register */
end_comment

begin_define
define|#
directive|define
name|SPR_TCR
value|0x154
end_define

begin_comment
comment|/* ..8 Timer Control Register */
end_comment

begin_define
define|#
directive|define
name|TSR_ENW
value|0x80000000
end_define

begin_comment
comment|/* Enable Next Watchdog */
end_comment

begin_define
define|#
directive|define
name|TSR_WIS
value|0x40000000
end_define

begin_comment
comment|/* Watchdog Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|TSR_WRS_MASK
value|0x30000000
end_define

begin_comment
comment|/* Watchdog Reset Status */
end_comment

begin_define
define|#
directive|define
name|TSR_WRS_NONE
value|0x00000000
end_define

begin_comment
comment|/* No watchdog reset has occurred */
end_comment

begin_define
define|#
directive|define
name|TSR_WRS_CORE
value|0x10000000
end_define

begin_comment
comment|/* Core reset was forced by the watchdog */
end_comment

begin_define
define|#
directive|define
name|TSR_WRS_CHIP
value|0x20000000
end_define

begin_comment
comment|/* Chip reset was forced by the watchdog */
end_comment

begin_define
define|#
directive|define
name|TSR_WRS_SYSTEM
value|0x30000000
end_define

begin_comment
comment|/* System reset was forced by the watchdog */
end_comment

begin_define
define|#
directive|define
name|TSR_PIS
value|0x08000000
end_define

begin_comment
comment|/* PIT Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|TSR_DIS
value|0x08000000
end_define

begin_comment
comment|/* Decrementer Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|TSR_FIS
value|0x04000000
end_define

begin_comment
comment|/* FIT Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|TCR_WP_MASK
value|0xc0000000
end_define

begin_comment
comment|/* Watchdog Period mask */
end_comment

begin_define
define|#
directive|define
name|TCR_WP_2_17
value|0x00000000
end_define

begin_comment
comment|/* 2**17 clocks */
end_comment

begin_define
define|#
directive|define
name|TCR_WP_2_21
value|0x40000000
end_define

begin_comment
comment|/* 2**21 clocks */
end_comment

begin_define
define|#
directive|define
name|TCR_WP_2_25
value|0x80000000
end_define

begin_comment
comment|/* 2**25 clocks */
end_comment

begin_define
define|#
directive|define
name|TCR_WP_2_29
value|0xc0000000
end_define

begin_comment
comment|/* 2**29 clocks */
end_comment

begin_define
define|#
directive|define
name|TCR_WRC_MASK
value|0x30000000
end_define

begin_comment
comment|/* Watchdog Reset Control mask */
end_comment

begin_define
define|#
directive|define
name|TCR_WRC_NONE
value|0x00000000
end_define

begin_comment
comment|/* No watchdog reset */
end_comment

begin_define
define|#
directive|define
name|TCR_WRC_CORE
value|0x10000000
end_define

begin_comment
comment|/* Core reset */
end_comment

begin_define
define|#
directive|define
name|TCR_WRC_CHIP
value|0x20000000
end_define

begin_comment
comment|/* Chip reset */
end_comment

begin_define
define|#
directive|define
name|TCR_WRC_SYSTEM
value|0x30000000
end_define

begin_comment
comment|/* System reset */
end_comment

begin_define
define|#
directive|define
name|TCR_WIE
value|0x08000000
end_define

begin_comment
comment|/* Watchdog Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|TCR_PIE
value|0x04000000
end_define

begin_comment
comment|/* PIT Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|TCR_DIE
value|0x04000000
end_define

begin_comment
comment|/* Pecrementer Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|TCR_FP_MASK
value|0x03000000
end_define

begin_comment
comment|/* FIT Period */
end_comment

begin_define
define|#
directive|define
name|TCR_FP_2_9
value|0x00000000
end_define

begin_comment
comment|/* 2**9 clocks */
end_comment

begin_define
define|#
directive|define
name|TCR_FP_2_13
value|0x01000000
end_define

begin_comment
comment|/* 2**13 clocks */
end_comment

begin_define
define|#
directive|define
name|TCR_FP_2_17
value|0x02000000
end_define

begin_comment
comment|/* 2**17 clocks */
end_comment

begin_define
define|#
directive|define
name|TCR_FP_2_21
value|0x03000000
end_define

begin_comment
comment|/* 2**21 clocks */
end_comment

begin_define
define|#
directive|define
name|TCR_FIE
value|0x00800000
end_define

begin_comment
comment|/* FIT Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|TCR_ARE
value|0x00400000
end_define

begin_comment
comment|/* Auto Reload Enable */
end_comment

begin_define
define|#
directive|define
name|SPR_PIT
value|0x3db
end_define

begin_comment
comment|/* 4.. Programmable Interval Timer */
end_comment

begin_define
define|#
directive|define
name|SPR_SRR2
value|0x3de
end_define

begin_comment
comment|/* 4.. Save/Restore Register 2 */
end_comment

begin_define
define|#
directive|define
name|SPR_SRR3
value|0x3df
end_define

begin_comment
comment|/* 4.. Save/Restore Register 3 */
end_comment

begin_define
define|#
directive|define
name|SPR_HID0
value|0x3f0
end_define

begin_comment
comment|/* ..8 Hardware Implementation Register 0 */
end_comment

begin_define
define|#
directive|define
name|SPR_HID1
value|0x3f1
end_define

begin_comment
comment|/* ..8 Hardware Implementation Register 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_HID4
value|0x3f4
end_define

begin_comment
comment|/* ..8 Hardware Implementation Register 4 */
end_comment

begin_define
define|#
directive|define
name|SPR_HID5
value|0x3f6
end_define

begin_comment
comment|/* ..8 Hardware Implementation Register 5 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AIM
argument_list|)
end_if

begin_define
define|#
directive|define
name|SPR_DBSR
value|0x3f0
end_define

begin_comment
comment|/* 4.. Debug Status Register */
end_comment

begin_define
define|#
directive|define
name|DBSR_IC
value|0x80000000
end_define

begin_comment
comment|/* Instruction completion debug event */
end_comment

begin_define
define|#
directive|define
name|DBSR_BT
value|0x40000000
end_define

begin_comment
comment|/* Branch Taken debug event */
end_comment

begin_define
define|#
directive|define
name|DBSR_EDE
value|0x20000000
end_define

begin_comment
comment|/* Exception debug event */
end_comment

begin_define
define|#
directive|define
name|DBSR_TIE
value|0x10000000
end_define

begin_comment
comment|/* Trap Instruction debug event */
end_comment

begin_define
define|#
directive|define
name|DBSR_UDE
value|0x08000000
end_define

begin_comment
comment|/* Unconditional debug event */
end_comment

begin_define
define|#
directive|define
name|DBSR_IA1
value|0x04000000
end_define

begin_comment
comment|/* IAC1 debug event */
end_comment

begin_define
define|#
directive|define
name|DBSR_IA2
value|0x02000000
end_define

begin_comment
comment|/* IAC2 debug event */
end_comment

begin_define
define|#
directive|define
name|DBSR_DR1
value|0x01000000
end_define

begin_comment
comment|/* DAC1 Read debug event */
end_comment

begin_define
define|#
directive|define
name|DBSR_DW1
value|0x00800000
end_define

begin_comment
comment|/* DAC1 Write debug event */
end_comment

begin_define
define|#
directive|define
name|DBSR_DR2
value|0x00400000
end_define

begin_comment
comment|/* DAC2 Read debug event */
end_comment

begin_define
define|#
directive|define
name|DBSR_DW2
value|0x00200000
end_define

begin_comment
comment|/* DAC2 Write debug event */
end_comment

begin_define
define|#
directive|define
name|DBSR_IDE
value|0x00100000
end_define

begin_comment
comment|/* Imprecise debug event */
end_comment

begin_define
define|#
directive|define
name|DBSR_IA3
value|0x00080000
end_define

begin_comment
comment|/* IAC3 debug event */
end_comment

begin_define
define|#
directive|define
name|DBSR_IA4
value|0x00040000
end_define

begin_comment
comment|/* IAC4 debug event */
end_comment

begin_define
define|#
directive|define
name|DBSR_MRR
value|0x00000300
end_define

begin_comment
comment|/* Most recent reset */
end_comment

begin_define
define|#
directive|define
name|SPR_DBCR0
value|0x3f2
end_define

begin_comment
comment|/* 4.. Debug Control Register 0 */
end_comment

begin_define
define|#
directive|define
name|SPR_DBCR1
value|0x3bd
end_define

begin_comment
comment|/* 4.. Debug Control Register 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_IAC1
value|0x3f4
end_define

begin_comment
comment|/* 4.. Instruction Address Compare 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_IAC2
value|0x3f5
end_define

begin_comment
comment|/* 4.. Instruction Address Compare 2 */
end_comment

begin_define
define|#
directive|define
name|SPR_DAC1
value|0x3f6
end_define

begin_comment
comment|/* 4.. Data Address Compare 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_DAC2
value|0x3f7
end_define

begin_comment
comment|/* 4.. Data Address Compare 2 */
end_comment

begin_define
define|#
directive|define
name|SPR_PIR
value|0x3ff
end_define

begin_comment
comment|/* .6. Processor Identification Register */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|E500
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SPR_PIR
value|0x11e
end_define

begin_comment
comment|/* ..8 Processor Identification Register */
end_comment

begin_define
define|#
directive|define
name|SPR_DBSR
value|0x130
end_define

begin_comment
comment|/* ..8 Debug Status Register */
end_comment

begin_define
define|#
directive|define
name|DBSR_IDE
value|0x80000000
end_define

begin_comment
comment|/* Imprecise debug event. */
end_comment

begin_define
define|#
directive|define
name|DBSR_UDE
value|0x40000000
end_define

begin_comment
comment|/* Unconditional debug event. */
end_comment

begin_define
define|#
directive|define
name|DBSR_MRR
value|0x30000000
end_define

begin_comment
comment|/* Most recent Reset (mask). */
end_comment

begin_define
define|#
directive|define
name|DBSR_ICMP
value|0x08000000
end_define

begin_comment
comment|/* Instr. complete debug event. */
end_comment

begin_define
define|#
directive|define
name|DBSR_BRT
value|0x04000000
end_define

begin_comment
comment|/* Branch taken debug event. */
end_comment

begin_define
define|#
directive|define
name|DBSR_IRPT
value|0x02000000
end_define

begin_comment
comment|/* Interrupt taken debug event. */
end_comment

begin_define
define|#
directive|define
name|DBSR_TRAP
value|0x01000000
end_define

begin_comment
comment|/* Trap instr. debug event. */
end_comment

begin_define
define|#
directive|define
name|DBSR_IAC1
value|0x00800000
end_define

begin_comment
comment|/* Instr. address compare #1. */
end_comment

begin_define
define|#
directive|define
name|DBSR_IAC2
value|0x00400000
end_define

begin_comment
comment|/* Instr. address compare #2. */
end_comment

begin_define
define|#
directive|define
name|DBSR_IAC3
value|0x00200000
end_define

begin_comment
comment|/* Instr. address compare #3. */
end_comment

begin_define
define|#
directive|define
name|DBSR_IAC4
value|0x00100000
end_define

begin_comment
comment|/* Instr. address compare #4. */
end_comment

begin_define
define|#
directive|define
name|DBSR_DAC1R
value|0x00080000
end_define

begin_comment
comment|/* Data addr. read compare #1. */
end_comment

begin_define
define|#
directive|define
name|DBSR_DAC1W
value|0x00040000
end_define

begin_comment
comment|/* Data addr. write compare #1. */
end_comment

begin_define
define|#
directive|define
name|DBSR_DAC2R
value|0x00020000
end_define

begin_comment
comment|/* Data addr. read compare #2. */
end_comment

begin_define
define|#
directive|define
name|DBSR_DAC2W
value|0x00010000
end_define

begin_comment
comment|/* Data addr. write compare #2. */
end_comment

begin_define
define|#
directive|define
name|DBSR_RET
value|0x00008000
end_define

begin_comment
comment|/* Return debug event. */
end_comment

begin_define
define|#
directive|define
name|SPR_DBCR0
value|0x134
end_define

begin_comment
comment|/* ..8 Debug Control Register 0 */
end_comment

begin_define
define|#
directive|define
name|SPR_DBCR1
value|0x135
end_define

begin_comment
comment|/* ..8 Debug Control Register 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_IAC1
value|0x138
end_define

begin_comment
comment|/* ..8 Instruction Address Compare 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_IAC2
value|0x139
end_define

begin_comment
comment|/* ..8 Instruction Address Compare 2 */
end_comment

begin_define
define|#
directive|define
name|SPR_DAC1
value|0x13c
end_define

begin_comment
comment|/* ..8 Data Address Compare 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_DAC2
value|0x13d
end_define

begin_comment
comment|/* ..8 Data Address Compare 2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DBCR0_EDM
value|0x80000000
end_define

begin_comment
comment|/* External Debug Mode */
end_comment

begin_define
define|#
directive|define
name|DBCR0_IDM
value|0x40000000
end_define

begin_comment
comment|/* Internal Debug Mode */
end_comment

begin_define
define|#
directive|define
name|DBCR0_RST_MASK
value|0x30000000
end_define

begin_comment
comment|/* ReSeT */
end_comment

begin_define
define|#
directive|define
name|DBCR0_RST_NONE
value|0x00000000
end_define

begin_comment
comment|/*   No action */
end_comment

begin_define
define|#
directive|define
name|DBCR0_RST_CORE
value|0x10000000
end_define

begin_comment
comment|/*   Core reset */
end_comment

begin_define
define|#
directive|define
name|DBCR0_RST_CHIP
value|0x20000000
end_define

begin_comment
comment|/*   Chip reset */
end_comment

begin_define
define|#
directive|define
name|DBCR0_RST_SYSTEM
value|0x30000000
end_define

begin_comment
comment|/*   System reset */
end_comment

begin_define
define|#
directive|define
name|DBCR0_IC
value|0x08000000
end_define

begin_comment
comment|/* Instruction Completion debug event */
end_comment

begin_define
define|#
directive|define
name|DBCR0_BT
value|0x04000000
end_define

begin_comment
comment|/* Branch Taken debug event */
end_comment

begin_define
define|#
directive|define
name|DBCR0_EDE
value|0x02000000
end_define

begin_comment
comment|/* Exception Debug Event */
end_comment

begin_define
define|#
directive|define
name|DBCR0_TDE
value|0x01000000
end_define

begin_comment
comment|/* Trap Debug Event */
end_comment

begin_define
define|#
directive|define
name|DBCR0_IA1
value|0x00800000
end_define

begin_comment
comment|/* IAC (Instruction Address Compare) 1 debug event */
end_comment

begin_define
define|#
directive|define
name|DBCR0_IA2
value|0x00400000
end_define

begin_comment
comment|/* IAC 2 debug event */
end_comment

begin_define
define|#
directive|define
name|DBCR0_IA12
value|0x00200000
end_define

begin_comment
comment|/* Instruction Address Range Compare 1-2 */
end_comment

begin_define
define|#
directive|define
name|DBCR0_IA12X
value|0x00100000
end_define

begin_comment
comment|/* IA12 eXclusive */
end_comment

begin_define
define|#
directive|define
name|DBCR0_IA3
value|0x00080000
end_define

begin_comment
comment|/* IAC 3 debug event */
end_comment

begin_define
define|#
directive|define
name|DBCR0_IA4
value|0x00040000
end_define

begin_comment
comment|/* IAC 4 debug event */
end_comment

begin_define
define|#
directive|define
name|DBCR0_IA34
value|0x00020000
end_define

begin_comment
comment|/* Instruction Address Range Compare 3-4 */
end_comment

begin_define
define|#
directive|define
name|DBCR0_IA34X
value|0x00010000
end_define

begin_comment
comment|/* IA34 eXclusive */
end_comment

begin_define
define|#
directive|define
name|DBCR0_IA12T
value|0x00008000
end_define

begin_comment
comment|/* Instruction Address Range Compare 1-2 range Toggle */
end_comment

begin_define
define|#
directive|define
name|DBCR0_IA34T
value|0x00004000
end_define

begin_comment
comment|/* Instruction Address Range Compare 3-4 range Toggle */
end_comment

begin_define
define|#
directive|define
name|DBCR0_FT
value|0x00000001
end_define

begin_comment
comment|/* Freeze Timers on debug event */
end_comment

begin_define
define|#
directive|define
name|SPR_IABR
value|0x3f2
end_define

begin_comment
comment|/* ..8 Instruction Address Breakpoint Register 0 */
end_comment

begin_define
define|#
directive|define
name|SPR_DABR
value|0x3f5
end_define

begin_comment
comment|/* .6. Data Address Breakpoint Register */
end_comment

begin_define
define|#
directive|define
name|SPR_MSSCR0
value|0x3f6
end_define

begin_comment
comment|/* .6. Memory SubSystem Control Register */
end_comment

begin_define
define|#
directive|define
name|MSSCR0_SHDEN
value|0x80000000
end_define

begin_comment
comment|/* 0: Shared-state enable */
end_comment

begin_define
define|#
directive|define
name|MSSCR0_SHDPEN3
value|0x40000000
end_define

begin_comment
comment|/* 1: ~SHD[01] signal enable in MEI mode */
end_comment

begin_define
define|#
directive|define
name|MSSCR0_L1INTVEN
value|0x38000000
end_define

begin_comment
comment|/* 2-4: L1 data cache ~HIT intervention enable */
end_comment

begin_define
define|#
directive|define
name|MSSCR0_L2INTVEN
value|0x07000000
end_define

begin_comment
comment|/* 5-7: L2 data cache ~HIT intervention enable*/
end_comment

begin_define
define|#
directive|define
name|MSSCR0_DL1HWF
value|0x00800000
end_define

begin_comment
comment|/* 8: L1 data cache hardware flush */
end_comment

begin_define
define|#
directive|define
name|MSSCR0_MBO
value|0x00400000
end_define

begin_comment
comment|/* 9: must be one */
end_comment

begin_define
define|#
directive|define
name|MSSCR0_EMODE
value|0x00200000
end_define

begin_comment
comment|/* 10: MPX bus mode (read-only) */
end_comment

begin_define
define|#
directive|define
name|MSSCR0_ABD
value|0x00100000
end_define

begin_comment
comment|/* 11: address bus driven (read-only) */
end_comment

begin_define
define|#
directive|define
name|MSSCR0_MBZ
value|0x000fffff
end_define

begin_comment
comment|/* 12-31: must be zero */
end_comment

begin_define
define|#
directive|define
name|SPR_L2PM
value|0x3f8
end_define

begin_comment
comment|/* .6. L2 Private Memory Control Register */
end_comment

begin_define
define|#
directive|define
name|SPR_L2CR
value|0x3f9
end_define

begin_comment
comment|/* .6. L2 Control Register */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2E
value|0x80000000
end_define

begin_comment
comment|/* 0: L2 enable */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2PE
value|0x40000000
end_define

begin_comment
comment|/* 1: L2 data parity enable */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2SIZ
value|0x30000000
end_define

begin_comment
comment|/* 2-3: L2 size */
end_comment

begin_define
define|#
directive|define
name|L2SIZ_2M
value|0x00000000
end_define

begin_define
define|#
directive|define
name|L2SIZ_256K
value|0x10000000
end_define

begin_define
define|#
directive|define
name|L2SIZ_512K
value|0x20000000
end_define

begin_define
define|#
directive|define
name|L2SIZ_1M
value|0x30000000
end_define

begin_define
define|#
directive|define
name|L2CR_L2CLK
value|0x0e000000
end_define

begin_comment
comment|/* 4-6: L2 clock ratio */
end_comment

begin_define
define|#
directive|define
name|L2CLK_DIS
value|0x00000000
end_define

begin_comment
comment|/* disable L2 clock */
end_comment

begin_define
define|#
directive|define
name|L2CLK_10
value|0x02000000
end_define

begin_comment
comment|/* core clock / 1   */
end_comment

begin_define
define|#
directive|define
name|L2CLK_15
value|0x04000000
end_define

begin_comment
comment|/*            / 1.5 */
end_comment

begin_define
define|#
directive|define
name|L2CLK_20
value|0x08000000
end_define

begin_comment
comment|/*            / 2   */
end_comment

begin_define
define|#
directive|define
name|L2CLK_25
value|0x0a000000
end_define

begin_comment
comment|/*            / 2.5 */
end_comment

begin_define
define|#
directive|define
name|L2CLK_30
value|0x0c000000
end_define

begin_comment
comment|/*            / 3   */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2RAM
value|0x01800000
end_define

begin_comment
comment|/* 7-8: L2 RAM type */
end_comment

begin_define
define|#
directive|define
name|L2RAM_FLOWTHRU_BURST
value|0x00000000
end_define

begin_define
define|#
directive|define
name|L2RAM_PIPELINE_BURST
value|0x01000000
end_define

begin_define
define|#
directive|define
name|L2RAM_PIPELINE_LATE
value|0x01800000
end_define

begin_define
define|#
directive|define
name|L2CR_L2DO
value|0x00400000
end_define

begin_comment
comment|/* 9: L2 data-only. 				      Setting this bit disables instruction 				      caching. */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2I
value|0x00200000
end_define

begin_comment
comment|/* 10: L2 global invalidate. */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2CTL
value|0x00100000
end_define

begin_comment
comment|/* 11: L2 RAM control (ZZ enable). 				      Enables automatic operation of the 				      L2ZZ (low-power mode) signal. */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2WT
value|0x00080000
end_define

begin_comment
comment|/* 12: L2 write-through. */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2TS
value|0x00040000
end_define

begin_comment
comment|/* 13: L2 test support. */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2OH
value|0x00030000
end_define

begin_comment
comment|/* 14-15: L2 output hold. */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2SL
value|0x00008000
end_define

begin_comment
comment|/* 16: L2 DLL slow. */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2DF
value|0x00004000
end_define

begin_comment
comment|/* 17: L2 differential clock. */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2BYP
value|0x00002000
end_define

begin_comment
comment|/* 18: L2 DLL bypass. */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2FA
value|0x00001000
end_define

begin_comment
comment|/* 19: L2 flush assist (for software flush). */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2HWF
value|0x00000800
end_define

begin_comment
comment|/* 20: L2 hardware flush. */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2IO
value|0x00000400
end_define

begin_comment
comment|/* 21: L2 instruction-only. */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2CLKSTP
value|0x00000200
end_define

begin_comment
comment|/* 22: L2 clock stop. */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2DRO
value|0x00000100
end_define

begin_comment
comment|/* 23: L2DLL rollover checkstop enable. */
end_comment

begin_define
define|#
directive|define
name|L2CR_L2IP
value|0x00000001
end_define

begin_comment
comment|/* 31: L2 global invalidate in */
end_comment

begin_comment
comment|/*     progress (read only). */
end_comment

begin_define
define|#
directive|define
name|SPR_L3CR
value|0x3fa
end_define

begin_comment
comment|/* .6. L3 Control Register */
end_comment

begin_define
define|#
directive|define
name|L3CR_L3E
value|0x80000000
end_define

begin_comment
comment|/* 0: L3 enable */
end_comment

begin_define
define|#
directive|define
name|L3CR_L3PE
value|0x40000000
end_define

begin_comment
comment|/* 1: L3 data parity enable */
end_comment

begin_define
define|#
directive|define
name|L3CR_L3APE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|L3CR_L3SIZ
value|0x10000000
end_define

begin_comment
comment|/* 3: L3 size (0=1MB, 1=2MB) */
end_comment

begin_define
define|#
directive|define
name|L3CR_L3CLKEN
value|0x08000000
end_define

begin_comment
comment|/* 4: Enables L3_CLK[0:1] */
end_comment

begin_define
define|#
directive|define
name|L3CR_L3CLK
value|0x03800000
end_define

begin_define
define|#
directive|define
name|L3CR_L3IO
value|0x00400000
end_define

begin_define
define|#
directive|define
name|L3CR_L3CLKEXT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|L3CR_L3CKSPEXT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|L3CR_L3OH1
value|0x00080000
end_define

begin_define
define|#
directive|define
name|L3CR_L3SPO
value|0x00040000
end_define

begin_define
define|#
directive|define
name|L3CR_L3CKSP
value|0x00030000
end_define

begin_define
define|#
directive|define
name|L3CR_L3PSP
value|0x0000e000
end_define

begin_define
define|#
directive|define
name|L3CR_L3REP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|L3CR_L3HWF
value|0x00000800
end_define

begin_define
define|#
directive|define
name|L3CR_L3I
value|0x00000400
end_define

begin_comment
comment|/* 21: L3 global invalidate */
end_comment

begin_define
define|#
directive|define
name|L3CR_L3RT
value|0x00000300
end_define

begin_define
define|#
directive|define
name|L3CR_L3NIRCA
value|0x00000080
end_define

begin_define
define|#
directive|define
name|L3CR_L3DO
value|0x00000040
end_define

begin_define
define|#
directive|define
name|L3CR_PMEN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|L3CR_PMSIZ
value|0x00000003
end_define

begin_define
define|#
directive|define
name|SPR_DCCR
value|0x3fa
end_define

begin_comment
comment|/* 4.. Data Cache Cachability Register */
end_comment

begin_define
define|#
directive|define
name|SPR_ICCR
value|0x3fb
end_define

begin_comment
comment|/* 4.. Instruction Cache Cachability Register */
end_comment

begin_define
define|#
directive|define
name|SPR_THRM1
value|0x3fc
end_define

begin_comment
comment|/* .6. Thermal Management Register */
end_comment

begin_define
define|#
directive|define
name|SPR_THRM2
value|0x3fd
end_define

begin_comment
comment|/* .6. Thermal Management Register */
end_comment

begin_define
define|#
directive|define
name|SPR_THRM_TIN
value|0x80000000
end_define

begin_comment
comment|/* Thermal interrupt bit (RO) */
end_comment

begin_define
define|#
directive|define
name|SPR_THRM_TIV
value|0x40000000
end_define

begin_comment
comment|/* Thermal interrupt valid (RO) */
end_comment

begin_define
define|#
directive|define
name|SPR_THRM_THRESHOLD
parameter_list|(
name|x
parameter_list|)
value|((x)<< 23)
end_define

begin_comment
comment|/* Thermal sensor threshold */
end_comment

begin_define
define|#
directive|define
name|SPR_THRM_TID
value|0x00000004
end_define

begin_comment
comment|/* Thermal interrupt direction */
end_comment

begin_define
define|#
directive|define
name|SPR_THRM_TIE
value|0x00000002
end_define

begin_comment
comment|/* Thermal interrupt enable */
end_comment

begin_define
define|#
directive|define
name|SPR_THRM_VALID
value|0x00000001
end_define

begin_comment
comment|/* Valid bit */
end_comment

begin_define
define|#
directive|define
name|SPR_THRM3
value|0x3fe
end_define

begin_comment
comment|/* .6. Thermal Management Register */
end_comment

begin_define
define|#
directive|define
name|SPR_THRM_TIMER
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_comment
comment|/* Sampling interval timer */
end_comment

begin_define
define|#
directive|define
name|SPR_THRM_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* TAU Enable */
end_comment

begin_define
define|#
directive|define
name|SPR_FPECR
value|0x3fe
end_define

begin_comment
comment|/* .6. Floating-Point Exception Cause Register */
end_comment

begin_comment
comment|/* Time Base Register declarations */
end_comment

begin_define
define|#
directive|define
name|TBR_TBL
value|0x10c
end_define

begin_comment
comment|/* 468 Time Base Lower - read */
end_comment

begin_define
define|#
directive|define
name|TBR_TBU
value|0x10d
end_define

begin_comment
comment|/* 468 Time Base Upper - read */
end_comment

begin_define
define|#
directive|define
name|TBR_TBWL
value|0x11c
end_define

begin_comment
comment|/* 468 Time Base Lower - supervisor, write */
end_comment

begin_define
define|#
directive|define
name|TBR_TBWU
value|0x11d
end_define

begin_comment
comment|/* 468 Time Base Upper - supervisor, write */
end_comment

begin_comment
comment|/* Performance counter declarations */
end_comment

begin_define
define|#
directive|define
name|PMC_OVERFLOW
value|0x80000000
end_define

begin_comment
comment|/* Counter has overflowed */
end_comment

begin_comment
comment|/* The first five countable [non-]events are common to many PMC's */
end_comment

begin_define
define|#
directive|define
name|PMCN_NONE
value|0
end_define

begin_comment
comment|/* Count nothing */
end_comment

begin_define
define|#
directive|define
name|PMCN_CYCLES
value|1
end_define

begin_comment
comment|/* Processor cycles */
end_comment

begin_define
define|#
directive|define
name|PMCN_ICOMP
value|2
end_define

begin_comment
comment|/* Instructions completed */
end_comment

begin_define
define|#
directive|define
name|PMCN_TBLTRANS
value|3
end_define

begin_comment
comment|/* TBL bit transitions */
end_comment

begin_define
define|#
directive|define
name|PCMN_IDISPATCH
value|4
end_define

begin_comment
comment|/* Instructions dispatched */
end_comment

begin_comment
comment|/* Similar things for the 970 PMC direct counters */
end_comment

begin_define
define|#
directive|define
name|PMC970N_NONE
value|0x8
end_define

begin_comment
comment|/* Count nothing */
end_comment

begin_define
define|#
directive|define
name|PMC970N_CYCLES
value|0xf
end_define

begin_comment
comment|/* Processor cycles */
end_comment

begin_define
define|#
directive|define
name|PMC970N_ICOMP
value|0x9
end_define

begin_comment
comment|/* Instructions completed */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AIM
argument_list|)
end_if

begin_define
define|#
directive|define
name|SPR_ESR
value|0x3d4
end_define

begin_comment
comment|/* 4.. Exception Syndrome Register */
end_comment

begin_define
define|#
directive|define
name|ESR_MCI
value|0x80000000
end_define

begin_comment
comment|/* Machine check - instruction */
end_comment

begin_define
define|#
directive|define
name|ESR_PIL
value|0x08000000
end_define

begin_comment
comment|/* Program interrupt - illegal */
end_comment

begin_define
define|#
directive|define
name|ESR_PPR
value|0x04000000
end_define

begin_comment
comment|/* Program interrupt - privileged */
end_comment

begin_define
define|#
directive|define
name|ESR_PTR
value|0x02000000
end_define

begin_comment
comment|/* Program interrupt - trap */
end_comment

begin_define
define|#
directive|define
name|ESR_ST
value|0x01000000
end_define

begin_comment
comment|/* Store operation */
end_comment

begin_define
define|#
directive|define
name|ESR_DST
value|0x00800000
end_define

begin_comment
comment|/* Data storage interrupt - store fault */
end_comment

begin_define
define|#
directive|define
name|ESR_DIZ
value|0x00800000
end_define

begin_comment
comment|/* Data/instruction storage interrupt - zone fault */
end_comment

begin_define
define|#
directive|define
name|ESR_U0F
value|0x00008000
end_define

begin_comment
comment|/* Data storage interrupt - U0 fault */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|E500
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SPR_ESR
value|0x003e
end_define

begin_comment
comment|/* ..8 Exception Syndrome Register */
end_comment

begin_define
define|#
directive|define
name|ESR_PIL
value|0x08000000
end_define

begin_comment
comment|/* Program interrupt - illegal */
end_comment

begin_define
define|#
directive|define
name|ESR_PPR
value|0x04000000
end_define

begin_comment
comment|/* Program interrupt - privileged */
end_comment

begin_define
define|#
directive|define
name|ESR_PTR
value|0x02000000
end_define

begin_comment
comment|/* Program interrupt - trap */
end_comment

begin_define
define|#
directive|define
name|ESR_ST
value|0x00800000
end_define

begin_comment
comment|/* Store operation */
end_comment

begin_define
define|#
directive|define
name|ESR_DLK
value|0x00200000
end_define

begin_comment
comment|/* Data storage, D cache locking */
end_comment

begin_define
define|#
directive|define
name|ESR_ILK
value|0x00100000
end_define

begin_comment
comment|/* Data storage, I cache locking */
end_comment

begin_define
define|#
directive|define
name|ESR_BO
value|0x00020000
end_define

begin_comment
comment|/* Data/instruction storage, byte ordering */
end_comment

begin_define
define|#
directive|define
name|ESR_SPE
value|0x00000080
end_define

begin_comment
comment|/* SPE exception bit */
end_comment

begin_define
define|#
directive|define
name|SPR_CSRR0
value|0x03a
end_define

begin_comment
comment|/* ..8 58 Critical SRR0 */
end_comment

begin_define
define|#
directive|define
name|SPR_CSRR1
value|0x03b
end_define

begin_comment
comment|/* ..8 59 Critical SRR1 */
end_comment

begin_define
define|#
directive|define
name|SPR_MCSRR0
value|0x23a
end_define

begin_comment
comment|/* ..8 570 Machine check SRR0 */
end_comment

begin_define
define|#
directive|define
name|SPR_MCSRR1
value|0x23b
end_define

begin_comment
comment|/* ..8 571 Machine check SRR1 */
end_comment

begin_define
define|#
directive|define
name|SPR_SVR
value|0x3ff
end_define

begin_comment
comment|/* ..8 1023 System Version Register */
end_comment

begin_define
define|#
directive|define
name|SVR_MPC8533
value|0x803c
end_define

begin_define
define|#
directive|define
name|SVR_MPC8533E
value|0x8034
end_define

begin_define
define|#
directive|define
name|SVR_MPC8541
value|0x8072
end_define

begin_define
define|#
directive|define
name|SVR_MPC8541E
value|0x807a
end_define

begin_define
define|#
directive|define
name|SVR_MPC8548
value|0x8031
end_define

begin_define
define|#
directive|define
name|SVR_MPC8548E
value|0x8039
end_define

begin_define
define|#
directive|define
name|SVR_MPC8555
value|0x8071
end_define

begin_define
define|#
directive|define
name|SVR_MPC8555E
value|0x8079
end_define

begin_define
define|#
directive|define
name|SVR_MPC8572
value|0x80e0
end_define

begin_define
define|#
directive|define
name|SVR_MPC8572E
value|0x80e8
end_define

begin_define
define|#
directive|define
name|SVR_VER
parameter_list|(
name|svr
parameter_list|)
value|(((svr)>> 16)& 0xffff)
end_define

begin_define
define|#
directive|define
name|SPR_PID0
value|0x030
end_define

begin_comment
comment|/* ..8 Process ID Register 0 */
end_comment

begin_define
define|#
directive|define
name|SPR_PID1
value|0x279
end_define

begin_comment
comment|/* ..8 Process ID Register 1 */
end_comment

begin_define
define|#
directive|define
name|SPR_PID2
value|0x27a
end_define

begin_comment
comment|/* ..8 Process ID Register 2 */
end_comment

begin_define
define|#
directive|define
name|SPR_TLB0CFG
value|0x2B0
end_define

begin_comment
comment|/* ..8 TLB 0 Config Register */
end_comment

begin_define
define|#
directive|define
name|SPR_TLB1CFG
value|0x2B1
end_define

begin_comment
comment|/* ..8 TLB 1 Config Register */
end_comment

begin_define
define|#
directive|define
name|TLBCFG_ASSOC_MASK
value|0xff000000
end_define

begin_comment
comment|/* Associativity of TLB */
end_comment

begin_define
define|#
directive|define
name|TLBCFG_ASSOC_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|TLBCFG_NENTRY_MASK
value|0x00000fff
end_define

begin_comment
comment|/* Number of entries in TLB */
end_comment

begin_define
define|#
directive|define
name|SPR_IVPR
value|0x03f
end_define

begin_comment
comment|/* ..8 Interrupt Vector Prefix Register */
end_comment

begin_define
define|#
directive|define
name|SPR_IVOR0
value|0x190
end_define

begin_comment
comment|/* ..8 Critical input */
end_comment

begin_define
define|#
directive|define
name|SPR_IVOR1
value|0x191
end_define

begin_comment
comment|/* ..8 Machine check */
end_comment

begin_define
define|#
directive|define
name|SPR_IVOR2
value|0x192
end_define

begin_define
define|#
directive|define
name|SPR_IVOR3
value|0x193
end_define

begin_define
define|#
directive|define
name|SPR_IVOR4
value|0x194
end_define

begin_define
define|#
directive|define
name|SPR_IVOR5
value|0x195
end_define

begin_define
define|#
directive|define
name|SPR_IVOR6
value|0x196
end_define

begin_define
define|#
directive|define
name|SPR_IVOR7
value|0x197
end_define

begin_define
define|#
directive|define
name|SPR_IVOR8
value|0x198
end_define

begin_define
define|#
directive|define
name|SPR_IVOR9
value|0x199
end_define

begin_define
define|#
directive|define
name|SPR_IVOR10
value|0x19a
end_define

begin_define
define|#
directive|define
name|SPR_IVOR11
value|0x19b
end_define

begin_define
define|#
directive|define
name|SPR_IVOR12
value|0x19c
end_define

begin_define
define|#
directive|define
name|SPR_IVOR13
value|0x19d
end_define

begin_define
define|#
directive|define
name|SPR_IVOR14
value|0x19e
end_define

begin_define
define|#
directive|define
name|SPR_IVOR15
value|0x19f
end_define

begin_define
define|#
directive|define
name|SPR_IVOR32
value|0x210
end_define

begin_define
define|#
directive|define
name|SPR_IVOR33
value|0x211
end_define

begin_define
define|#
directive|define
name|SPR_IVOR34
value|0x212
end_define

begin_define
define|#
directive|define
name|SPR_IVOR35
value|0x213
end_define

begin_define
define|#
directive|define
name|SPR_MAS0
value|0x270
end_define

begin_comment
comment|/* ..8 MMU Assist Register 0 Book-E/e500 */
end_comment

begin_define
define|#
directive|define
name|SPR_MAS1
value|0x271
end_define

begin_comment
comment|/* ..8 MMU Assist Register 1 Book-E/e500 */
end_comment

begin_define
define|#
directive|define
name|SPR_MAS2
value|0x272
end_define

begin_comment
comment|/* ..8 MMU Assist Register 2 Book-E/e500 */
end_comment

begin_define
define|#
directive|define
name|SPR_MAS3
value|0x273
end_define

begin_comment
comment|/* ..8 MMU Assist Register 3 Book-E/e500 */
end_comment

begin_define
define|#
directive|define
name|SPR_MAS4
value|0x274
end_define

begin_comment
comment|/* ..8 MMU Assist Register 4 Book-E/e500 */
end_comment

begin_define
define|#
directive|define
name|SPR_MAS5
value|0x275
end_define

begin_comment
comment|/* ..8 MMU Assist Register 5 Book-E */
end_comment

begin_define
define|#
directive|define
name|SPR_MAS6
value|0x276
end_define

begin_comment
comment|/* ..8 MMU Assist Register 6 Book-E/e500 */
end_comment

begin_define
define|#
directive|define
name|SPR_MAS7
value|0x3B0
end_define

begin_comment
comment|/* ..8 MMU Assist Register 7 Book-E/e500 */
end_comment

begin_define
define|#
directive|define
name|SPR_L1CSR0
value|0x3F2
end_define

begin_comment
comment|/* ..8 L1 Cache Control and Status Register 0 */
end_comment

begin_define
define|#
directive|define
name|L1CSR0_DCPE
value|0x00010000
end_define

begin_comment
comment|/* Data Cache Parity Enable */
end_comment

begin_define
define|#
directive|define
name|L1CSR0_DCLFR
value|0x00000100
end_define

begin_comment
comment|/* Data Cache Lock Bits Flash Reset */
end_comment

begin_define
define|#
directive|define
name|L1CSR0_DCFI
value|0x00000002
end_define

begin_comment
comment|/* Data Cache Flash Invalidate */
end_comment

begin_define
define|#
directive|define
name|L1CSR0_DCE
value|0x00000001
end_define

begin_comment
comment|/* Data Cache Enable */
end_comment

begin_define
define|#
directive|define
name|SPR_L1CSR1
value|0x3F3
end_define

begin_comment
comment|/* ..8 L1 Cache Control and Status Register 1 */
end_comment

begin_define
define|#
directive|define
name|L1CSR1_ICPE
value|0x00010000
end_define

begin_comment
comment|/* Instruction Cache Parity Enable */
end_comment

begin_define
define|#
directive|define
name|L1CSR1_ICLFR
value|0x00000100
end_define

begin_comment
comment|/* Instruction Cache Lock Bits Flash Reset */
end_comment

begin_define
define|#
directive|define
name|L1CSR1_ICFI
value|0x00000002
end_define

begin_comment
comment|/* Instruction Cache Flash Invalidate */
end_comment

begin_define
define|#
directive|define
name|L1CSR1_ICE
value|0x00000001
end_define

begin_comment
comment|/* Instruction Cache Enable */
end_comment

begin_define
define|#
directive|define
name|SPR_BUCSR
value|0x3F5
end_define

begin_comment
comment|/* ..8 Branch Unit Control and Status Register */
end_comment

begin_define
define|#
directive|define
name|BUCSR_BPEN
value|0x00000001
end_define

begin_comment
comment|/* Branch Prediction Enable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #elif defined(E500) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POWERPC_SPR_H_ */
end_comment

end_unit

