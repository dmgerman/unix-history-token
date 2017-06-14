begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2008 Semihalf, Rafal Jaworowski  * Copyright 2006 by Juniper Networks.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MPC85XX_H_
end_ifndef

begin_define
define|#
directive|define
name|_MPC85XX_H_
end_define

begin_include
include|#
directive|include
file|<machine/platformvar.h>
end_include

begin_comment
comment|/*  * Configuration control and status registers  */
end_comment

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|ccsrbar_va
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|ccsrbar_pa
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_size_t
name|ccsrbar_size
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CCSRBAR_VA
value|ccsrbar_va
end_define

begin_define
define|#
directive|define
name|OCP85XX_CCSRBAR
value|(CCSRBAR_VA + 0x0)
end_define

begin_define
define|#
directive|define
name|OCP85XX_BPTR
value|(CCSRBAR_VA + 0x20)
end_define

begin_define
define|#
directive|define
name|OCP85XX_BSTRH
value|(CCSRBAR_VA + 0x20)
end_define

begin_define
define|#
directive|define
name|OCP85XX_BSTRL
value|(CCSRBAR_VA + 0x24)
end_define

begin_define
define|#
directive|define
name|OCP85XX_BSTAR
value|(CCSRBAR_VA + 0x28)
end_define

begin_define
define|#
directive|define
name|OCP85XX_COREDISR
value|(CCSRBAR_VA + 0xE0094)
end_define

begin_define
define|#
directive|define
name|OCP85XX_BRR
value|(CCSRBAR_VA + 0xE00E4)
end_define

begin_comment
comment|/*  * Run Control and Power Management registers  */
end_comment

begin_define
define|#
directive|define
name|CCSR_CTBENR
value|(CCSRBAR_VA + 0xE2084)
end_define

begin_define
define|#
directive|define
name|CCSR_CTBCKSELR
value|(CCSRBAR_VA + 0xE208C)
end_define

begin_define
define|#
directive|define
name|CCSR_CTBCHLTCR
value|(CCSRBAR_VA + 0xE2094)
end_define

begin_comment
comment|/*  * DDR Memory controller.  */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_DDR1_CS0_CONFIG
value|(CCSRBAR_VA + 0x8080)
end_define

begin_comment
comment|/*  * E500 Coherency Module registers  */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_EEBPCR
value|(CCSRBAR_VA + 0x1010)
end_define

begin_comment
comment|/*  * Local access registers  */
end_comment

begin_comment
comment|/* Write order: OCP_LAWBARH -> OCP_LAWBARL -> OCP_LAWSR */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_LAWBARH
parameter_list|(
name|n
parameter_list|)
value|(CCSRBAR_VA + 0xc00 + 0x10 * (n))
end_define

begin_define
define|#
directive|define
name|OCP85XX_LAWBARL
parameter_list|(
name|n
parameter_list|)
value|(CCSRBAR_VA + 0xc04 + 0x10 * (n))
end_define

begin_define
define|#
directive|define
name|OCP85XX_LAWSR_QORIQ
parameter_list|(
name|n
parameter_list|)
value|(CCSRBAR_VA + 0xc08 + 0x10 * (n))
end_define

begin_define
define|#
directive|define
name|OCP85XX_LAWBAR
parameter_list|(
name|n
parameter_list|)
value|(CCSRBAR_VA + 0xc08 + 0x10 * (n))
end_define

begin_define
define|#
directive|define
name|OCP85XX_LAWSR_85XX
parameter_list|(
name|n
parameter_list|)
value|(CCSRBAR_VA + 0xc10 + 0x10 * (n))
end_define

begin_define
define|#
directive|define
name|OCP85XX_LAWSR
parameter_list|(
name|n
parameter_list|)
value|(mpc85xx_is_qoriq() ? OCP85XX_LAWSR_QORIQ(n) : \ 				 OCP85XX_LAWSR_85XX(n))
end_define

begin_comment
comment|/* Attribute register */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_ENA_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|OCP85XX_DIS_MASK
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_LBC_QORIQ
value|0x1f
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RAM_INTL_QORIQ
value|0x14
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RAM1_QORIQ
value|0x10
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RAM2_QORIQ
value|0x11
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_BMAN
value|0x18
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_DCSR
value|0x1D
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_QMAN
value|0x3C
end_define

begin_define
define|#
directive|define
name|OCP85XX_TRGT_SHIFT_QORIQ
value|20
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_LBC_85XX
value|0x04
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RAM_INTL_85XX
value|0x0b
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RIO_85XX
value|0x0c
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RAM1_85XX
value|0x0f
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RAM2_85XX
value|0x16
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_LBC
define|\
value|(mpc85xx_is_qoriq() ? OCP85XX_TGTIF_LBC_QORIQ : OCP85XX_TGTIF_LBC_85XX)
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RAM_INTL
define|\
value|(mpc85xx_is_qoriq() ? OCP85XX_TGTIF_RAM_INTL_QORIQ : OCP85XX_TGTIF_RAM_INTL_85XX)
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RIO
define|\
value|(mpc85xx_is_qoriq() ? OCP85XX_TGTIF_RIO_QORIQ : OCP85XX_TGTIF_RIO_85XX)
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RAM1
define|\
value|(mpc85xx_is_qoriq() ? OCP85XX_TGTIF_RAM1_QORIQ : OCP85XX_TGTIF_RAM1_85XX)
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RAM2
define|\
value|(mpc85xx_is_qoriq() ? OCP85XX_TGTIF_RAM2_QORIQ : OCP85XX_TGTIF_RAM2_85XX)
end_define

begin_comment
comment|/*  * L2 cache registers  */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_L2CTL
value|(CCSRBAR_VA + 0x20000)
end_define

begin_comment
comment|/*  * L3 CoreNet platform cache (CPC) registers  */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_CPC_CSR0
value|(CCSRBAR_VA + 0x10000)
end_define

begin_define
define|#
directive|define
name|OCP85XX_CPC_CSR0_CE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|OCP85XX_CPC_CSR0_PE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|OCP85XX_CPC_CSR0_FI
value|0x00200000
end_define

begin_define
define|#
directive|define
name|OCP85XX_CPC_CSR0_WT
value|0x00080000
end_define

begin_define
define|#
directive|define
name|OCP85XX_CPC_CSR0_FL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|OCP85XX_CPC_CSR0_LFC
value|0x00000400
end_define

begin_define
define|#
directive|define
name|OCP85XX_CPC_CFG0
value|(CCSRBAR_VA + 0x10008)
end_define

begin_define
define|#
directive|define
name|OCP85XX_CPC_CFG_SZ_MASK
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|OCP85XX_CPC_CFG0_SZ_K
parameter_list|(
name|x
parameter_list|)
value|(((x)& OCP85XX_CPC_CFG_SZ_MASK)<< 6)
end_define

begin_comment
comment|/*  * Power-On Reset configuration  */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_PORDEVSR
value|(CCSRBAR_VA + 0xe000c)
end_define

begin_define
define|#
directive|define
name|OCP85XX_PORDEVSR_IO_SEL
value|0x00780000
end_define

begin_define
define|#
directive|define
name|OCP85XX_PORDEVSR_IO_SEL_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|OCP85XX_PORDEVSR2
value|(CCSRBAR_VA + 0xe0014)
end_define

begin_comment
comment|/*  * Status Registers.  */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_RSTCR
value|(CCSRBAR_VA + 0xe00b0)
end_define

begin_define
define|#
directive|define
name|OCP85XX_CLKDVDR
value|(CCSRBAR_VA + 0xe0800)
end_define

begin_define
define|#
directive|define
name|OCP85XX_CLKDVDR_PXCKEN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|OCP85XX_CLKDVDR_SSICKEN
value|0x20000000
end_define

begin_define
define|#
directive|define
name|OCP85XX_CLKDVDR_PXCKINV
value|0x10000000
end_define

begin_define
define|#
directive|define
name|OCP85XX_CLKDVDR_PXCLK_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|OCP85XX_CLKDVDR_SSICLK_MASK
value|0x000000FF
end_define

begin_comment
comment|/*  * Run Control/Power Management Registers.  */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_RCPM_CDOZSR
value|(CCSRBAR_VA + 0xe2004)
end_define

begin_define
define|#
directive|define
name|OCP85XX_RCPM_CDOZCR
value|(CCSRBAR_VA + 0xe200c)
end_define

begin_comment
comment|/*  * Prototypes.  */
end_comment

begin_function_decl
name|uint32_t
name|ccsr_read4
parameter_list|(
name|uintptr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ccsr_write4
parameter_list|(
name|uintptr_t
name|addr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|law_enable
parameter_list|(
name|int
name|trgt
parameter_list|,
name|uint64_t
name|bar
parameter_list|,
name|uint32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|law_disable
parameter_list|(
name|int
name|trgt
parameter_list|,
name|uint64_t
name|bar
parameter_list|,
name|uint32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|law_getmax
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|law_pci_target
parameter_list|(
name|struct
name|resource
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|mpc85xx_platform
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|mpc85xx_attach
parameter_list|(
name|platform_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpc85xx_enable_l3_cache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpc85xx_fix_errata
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dataloss_erratum_access
parameter_list|(
name|vm_offset_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpc85xx_is_qoriq
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|mpc85xx_get_platform_clock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|mpc85xx_get_system_clock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MPC85XX_H_ */
end_comment

end_unit

