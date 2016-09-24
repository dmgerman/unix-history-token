begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2000,2001,2002,2003 Broadcom Corporation.  * All rights reserved.  *  * This file is derived from the sbmips32.h header distributed  * by Broadcom with the CFE 1.4.2 sources.  *  * This software is furnished under license and may be used and  * copied only in accordance with the following terms and  * conditions.  Subject to these conditions, you may download,  * copy, install, use, modify and distribute modified or unmodified  * copies of this software in source and/or binary form.  No title  * or ownership is transferred hereby.  *  * 1) Any source code used, modified or distributed must reproduce  *    and retain this copyright notice and list of conditions  *    as they appear in the source file.  *  * 2) No right is granted to use any trade name, trademark, or  *    logo of Broadcom Corporation.  The "Broadcom Corporation"  *    name may not be used to endorse or promote products derived  *    from this software without the prior written permission of  *    Broadcom Corporation.  *  * 3) THIS SOFTWARE IS PROVIDED "AS-IS" AND ANY EXPRESS OR  *    IMPLIED WARRANTIES, INCLUDING BUT NOT LIMITED TO, ANY IMPLIED  *    WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR  *    PURPOSE, OR NON-INFRINGEMENT ARE DISCLAIMED. IN NO EVENT  *    SHALL BROADCOM BE LIABLE FOR ANY DAMAGES WHATSOEVER, AND IN  *    PARTICULAR, BROADCOM SHALL NOT BE LIABLE FOR DIRECT, INDIRECT,  *    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  *    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  *    GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  *    OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *    TORT (INCLUDING NEGLIGENCE OR OTHERWISE), EVEN IF ADVISED OF  *    THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *********************************************************************     *  Broadcom Common Firmware Environment (CFE)     *       *  MIPS32 CPU definitions			File: sbmips32.h     *      *  This module contains constants and macros specific to the     *  Broadcom MIPS32 core.  In addition to generic MIPS32, it     *  includes definitions for the MIP32-01 and MIPS3302 OCP cores     *  for the Silicon Backplane.     *     *********************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_BROADCOM_BCM_BMIPS_EXTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_BROADCOM_BCM_BMIPS_EXTS_H_
end_define

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_comment
comment|/*  * The following Broadcom Custom CP0 Registers appear in the Broadcom  * BMIPS330x MIPS32 core.  */
end_comment

begin_define
define|#
directive|define
name|BMIPS_COP_0_BCMCFG
value|22
end_define

begin_comment
comment|/*  * Custom CP0 Accessors  */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS_RW32_COP0_SEL
parameter_list|(
name|n
parameter_list|,
name|r
parameter_list|,
name|s
parameter_list|)
define|\
value|static __inline uint32_t					\ bcm_bmips_rd_ ## n(void)					\ {								\ 	int v0;							\ 	__asm __volatile ("mfc0 %[v0], $"__XSTRING(r)", "__XSTRING(s)";"	\ 			  : [v0] "=&r"(v0));			\ 	mips_barrier();						\ 	return (v0);						\ }								\ static __inline void						\ bcm_bmips_wr_ ## n(uint32_t a0)					\ {								\ 	__asm __volatile ("mtc0 %[a0], $"__XSTRING(r)", "__XSTRING(s)";"	\ 			 __XSTRING(COP0_SYNC)";"		\ 			 "nop;"					\ 			 "nop;"					\ 			 :					\ 			 : [a0] "r"(a0));			\ 	mips_barrier();						\ } struct __hack
end_define

begin_expr_stmt
name|BCM_BMIPS_RW32_COP0_SEL
argument_list|(
name|pllcfg1
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BCM_BMIPS_RW32_COP0_SEL
argument_list|(
name|pllcfg2
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BCM_BMIPS_RW32_COP0_SEL
argument_list|(
name|clksync
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BCM_BMIPS_RW32_COP0_SEL
argument_list|(
name|pllcfg3
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BCM_BMIPS_RW32_COP0_SEL
argument_list|(
name|rstcfg
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|,
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Broadcom PLLConfig1 Register (22, select 1)  */
end_comment

begin_comment
comment|/* SoftMIPSPLLCfg */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG1_MC_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG1_MC_MASK
value|0xFFFFFC00
end_define

begin_comment
comment|/* SoftISBPLLCfg */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG1_BC_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG1_BC_MASK
value|0x000003E0
end_define

begin_comment
comment|/* SoftRefPLLCfg */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG1_PC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG1_PC_MASK
value|0x0000001F
end_define

begin_comment
comment|/*  * Broadcom PLLConfig2 Register (22, select 2)  */
end_comment

begin_comment
comment|/* Soft1to1ClkRatio */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG2_CR
value|(1<<23)
end_define

begin_comment
comment|/* SoftUSBxPLLCfg */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG2_UC_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG2_UC_MASK
value|0x007F8000
end_define

begin_comment
comment|/* SoftIDExPLLCfg */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG2_IC_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG2_IC_MASK
value|0x00007F80
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG2_BE
value|(1<<6)
end_define

begin_comment
comment|/* ISBxSoftCfgEnable */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG2_UE
value|(1<<5)
end_define

begin_comment
comment|/* USBxSoftCfgEnable */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG2_IE
value|(1<<4)
end_define

begin_comment
comment|/* IDExSoftCfgEnable */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG2_CA
value|(1<<3)
end_define

begin_comment
comment|/* CfgActive */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG2_CF
value|(1<<2)
end_define

begin_comment
comment|/* RefSoftCfgEnable */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG2_CI
value|(1<<1)
end_define

begin_comment
comment|/* ISBSoftCfgEnable */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG2_CC
value|(1<<0)
end_define

begin_comment
comment|/* MIPSSoftCfgEnable */
end_comment

begin_comment
comment|/*  * Broadcom ClkSync Register (22, select 3)  */
end_comment

begin_comment
comment|/* SoftClkCfgHigh */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_CLKSYNC_CH_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_CLKSYNC_CH_MASK
value|0xFFFF0000
end_define

begin_comment
comment|/* SoftClkCfgLow */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_CLKSYNC_CL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_CLKSYNC_CL_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/*  * Broadcom ISBxPLLConfig3 Register (22, select 4)  */
end_comment

begin_comment
comment|/* AsyncClkRatio */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG3_AR_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG3_AR_MASK
value|0x01800000
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG3_SM
value|(1<<22)
end_define

begin_comment
comment|/* SyncMode */
end_comment

begin_comment
comment|/* SoftISBxPLLCfg */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG3_IC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_PLLCFG3_IC_MASK
value|0x003FFFFF
end_define

begin_comment
comment|/*  * Broadcom BRCMRstConfig Register (22, select 5)  */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RSTCFG_SR
value|(1<<18)
end_define

begin_comment
comment|/* SSMR */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RSTCFG_DT
value|(1<<16)
end_define

begin_comment
comment|/* BHTD */
end_comment

begin_comment
comment|/* RStSt */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RSTCFG_RS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RSTCFG_RS_MASK
value|0x00001F00
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RST_OTHER
value|0x00
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RST_SH
value|0x01
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RST_SS
value|0x02
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RST_EJTAG
value|0x04
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RST_WDOG
value|0x08
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RST_CRC
value|0x10
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RSTCFG_CR
value|(1<<7)
end_define

begin_comment
comment|/* RStCr */
end_comment

begin_comment
comment|/* WBMD */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RSTCFG_WD_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RSTCFG_WD_MASK
value|0x00000078
end_define

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RSTCFG_SS
value|(1<<2)
end_define

begin_comment
comment|/* SSR */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RSTCFG_SH
value|(1<<1)
end_define

begin_comment
comment|/* SHR */
end_comment

begin_define
define|#
directive|define
name|BMIPS_BCMCFG_RSTCFG_BR
value|(1<<0)
end_define

begin_comment
comment|/* BdR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_BROADCOM_BCM_BMIPS_EXTS_H_ */
end_comment

end_unit

