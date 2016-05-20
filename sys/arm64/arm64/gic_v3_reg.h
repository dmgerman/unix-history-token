begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Semihalf under  * the sponsorship of the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GIC_V3_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_GIC_V3_REG_H_
end_define

begin_comment
comment|/*  * Maximum number of interrupts  * supported by GIC (including SGIs, PPIs and SPIs)  */
end_comment

begin_define
define|#
directive|define
name|GIC_I_NUM_MAX
value|(1020)
end_define

begin_comment
comment|/*  * Priority MAX/MIN values  */
end_comment

begin_define
define|#
directive|define
name|GIC_PRIORITY_MAX
value|(0x00UL)
end_define

begin_comment
comment|/* Upper value is determined by LPI max priority */
end_comment

begin_define
define|#
directive|define
name|GIC_PRIORITY_MIN
value|(0xFCUL)
end_define

begin_comment
comment|/* Numbers for software generated interrupts */
end_comment

begin_define
define|#
directive|define
name|GIC_FIRST_SGI
value|(0)
end_define

begin_define
define|#
directive|define
name|GIC_LAST_SGI
value|(15)
end_define

begin_comment
comment|/* Numbers for private peripheral interrupts */
end_comment

begin_define
define|#
directive|define
name|GIC_FIRST_PPI
value|(16)
end_define

begin_define
define|#
directive|define
name|GIC_LAST_PPI
value|(31)
end_define

begin_comment
comment|/* Numbers for spared peripheral interrupts */
end_comment

begin_define
define|#
directive|define
name|GIC_FIRST_SPI
value|(32)
end_define

begin_define
define|#
directive|define
name|GIC_LAST_SPI
value|(1019)
end_define

begin_comment
comment|/* Numbers for local peripheral interrupts */
end_comment

begin_define
define|#
directive|define
name|GIC_FIRST_LPI
value|(8192)
end_define

begin_comment
comment|/*  * Registers (v2/v3)  */
end_comment

begin_define
define|#
directive|define
name|GICD_CTLR
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|GICD_CTLR_G1
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GICD_CTLR_G1A
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|GICD_CTLR_ARE_NS
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|GICD_CTLR_RWP
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|GICD_TYPER
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|GICD_TYPER_IDBITS
parameter_list|(
name|n
parameter_list|)
value|((((n)>> 19)& 0x1F) + 1)
end_define

begin_define
define|#
directive|define
name|GICD_TYPER_I_NUM
parameter_list|(
name|n
parameter_list|)
value|((((n)& 0x1F) + 1) * 32)
end_define

begin_define
define|#
directive|define
name|GICD_ISENABLER
parameter_list|(
name|n
parameter_list|)
value|(0x0100 + (((n)>> 5) * 4))
end_define

begin_define
define|#
directive|define
name|GICD_I_PER_ISENABLERn
value|(32)
end_define

begin_define
define|#
directive|define
name|GICD_ICENABLER
parameter_list|(
name|n
parameter_list|)
value|(0x0180 + (((n)>> 5) * 4))
end_define

begin_define
define|#
directive|define
name|GICD_IPRIORITYR
parameter_list|(
name|n
parameter_list|)
value|(0x0400 + (((n)>> 2) * 4))
end_define

begin_define
define|#
directive|define
name|GICD_I_PER_IPRIORITYn
value|(4)
end_define

begin_define
define|#
directive|define
name|GICD_I_MASK
parameter_list|(
name|n
parameter_list|)
value|(1<< ((n) % 32))
end_define

begin_define
define|#
directive|define
name|GICD_ICFGR
parameter_list|(
name|n
parameter_list|)
value|(0x0C00 + (((n)>> 4) * 4))
end_define

begin_comment
comment|/* First bit is a polarity bit (0 - low, 1 - high) */
end_comment

begin_define
define|#
directive|define
name|GICD_ICFGR_POL_LOW
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|GICD_ICFGR_POL_HIGH
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GICD_ICFGR_POL_MASK
value|(0x1)
end_define

begin_comment
comment|/* Second bit is a trigger bit (0 - level, 1 - edge) */
end_comment

begin_define
define|#
directive|define
name|GICD_ICFGR_TRIG_LVL
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|GICD_ICFGR_TRIG_EDGE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|GICD_ICFGR_TRIG_MASK
value|(0x2)
end_define

begin_define
define|#
directive|define
name|GICD_I_PER_ICFGRn
value|(16)
end_define

begin_comment
comment|/*  * Registers (v3)  */
end_comment

begin_define
define|#
directive|define
name|GICD_IROUTER
parameter_list|(
name|n
parameter_list|)
value|(0x6000 + ((n) * 8))
end_define

begin_define
define|#
directive|define
name|GICD_PIDR2
value|(0xFFE8)
end_define

begin_define
define|#
directive|define
name|GICR_PIDR2_ARCH_MASK
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|GICR_PIDR2_ARCH_GICv3
value|(0x30)
end_define

begin_define
define|#
directive|define
name|GICR_PIDR2_ARCH_GICv4
value|(0x40)
end_define

begin_comment
comment|/* Redistributor registers */
end_comment

begin_define
define|#
directive|define
name|GICR_CTLR
value|GICD_CTLR
end_define

begin_define
define|#
directive|define
name|GICR_CTLR_LPI_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GICR_PIDR2
value|GICD_PIDR2
end_define

begin_define
define|#
directive|define
name|GICR_TYPER
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|GICR_TYPER_PLPIS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GICR_TYPER_VLPIS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|GICR_TYPER_LAST
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|GICR_TYPER_CPUNUM_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|GICR_TYPER_CPUNUM_MASK
value|(0xFFFUL<< GICR_TYPER_CPUNUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|GICR_TYPER_CPUNUM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& GICR_TYPER_CPUNUM_MASK)>> GICR_TYPER_CPUNUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|GICR_TYPER_AFF_SHIFT
value|(32)
end_define

begin_define
define|#
directive|define
name|GICR_WAKER
value|(0x0014)
end_define

begin_define
define|#
directive|define
name|GICR_WAKER_PS
value|(1<< 1)
end_define

begin_comment
comment|/* Processor sleep */
end_comment

begin_define
define|#
directive|define
name|GICR_WAKER_CA
value|(1<< 2)
end_define

begin_comment
comment|/* Children asleep */
end_comment

begin_define
define|#
directive|define
name|GICR_PROPBASER
value|(0x0070)
end_define

begin_define
define|#
directive|define
name|GICR_PROPBASER_IDBITS_MASK
value|0x1FUL
end_define

begin_comment
comment|/*  * Cacheability  * 0x0 - Device-nGnRnE  * 0x1 - Normal Inner Non-cacheable  * 0x2 - Normal Inner Read-allocate, Write-through  * 0x3 - Normal Inner Read-allocate, Write-back  * 0x4 - Normal Inner Write-allocate, Write-through  * 0x5 - Normal Inner Write-allocate, Write-back  * 0x6 - Normal Inner Read-allocate, Write-allocate, Write-through  * 0x7 - Normal Inner Read-allocate, Write-allocate, Write-back  */
end_comment

begin_define
define|#
directive|define
name|GICR_PROPBASER_CACHE_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|GICR_PROPBASER_CACHE_DnGnRnE
value|0x0UL
end_define

begin_define
define|#
directive|define
name|GICR_PROPBASER_CACHE_NIN
value|0x1UL
end_define

begin_define
define|#
directive|define
name|GICR_PROPBASER_CACHE_NIRAWT
value|0x2UL
end_define

begin_define
define|#
directive|define
name|GICR_PROPBASER_CACHE_NIRAWB
value|0x3UL
end_define

begin_define
define|#
directive|define
name|GICR_PROPBASER_CACHE_NIWAWT
value|0x4UL
end_define

begin_define
define|#
directive|define
name|GICR_PROPBASER_CACHE_NIWAWB
value|0x5UL
end_define

begin_define
define|#
directive|define
name|GICR_PROPBASER_CACHE_NIRAWAWT
value|0x6UL
end_define

begin_define
define|#
directive|define
name|GICR_PROPBASER_CACHE_NIRAWAWB
value|0x7UL
end_define

begin_define
define|#
directive|define
name|GICR_PROPBASER_CACHE_MASK
define|\
value|(0x7UL<< GICR_PROPBASER_CACHE_SHIFT)
end_define

begin_comment
comment|/*  * Shareability  * 0x0 - Non-shareable  * 0x1 - Inner-shareable  * 0x2 - Outer-shareable  * 0x3 - Reserved. Threated as 0x0  */
end_comment

begin_define
define|#
directive|define
name|GICR_PROPBASER_SHARE_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|GICR_PROPBASER_SHARE_NS
value|0x0UL
end_define

begin_define
define|#
directive|define
name|GICR_PROPBASER_SHARE_IS
value|0x1UL
end_define

begin_define
define|#
directive|define
name|GICR_PROPBASER_SHARE_OS
value|0x2UL
end_define

begin_define
define|#
directive|define
name|GICR_PROPBASER_SHARE_RES
value|0x3UL
end_define

begin_define
define|#
directive|define
name|GICR_PROPBASER_SHARE_MASK
define|\
value|(0x3UL<< GICR_PROPBASER_SHARE_SHIFT)
end_define

begin_define
define|#
directive|define
name|GICR_PENDBASER
value|(0x0078)
end_define

begin_comment
comment|/*  * Cacheability  * 0x0 - Device-nGnRnE  * 0x1 - Normal Inner Non-cacheable  * 0x2 - Normal Inner Read-allocate, Write-through  * 0x3 - Normal Inner Read-allocate, Write-back  * 0x4 - Normal Inner Write-allocate, Write-through  * 0x5 - Normal Inner Write-allocate, Write-back  * 0x6 - Normal Inner Read-allocate, Write-allocate, Write-through  * 0x7 - Normal Inner Read-allocate, Write-allocate, Write-back  */
end_comment

begin_define
define|#
directive|define
name|GICR_PENDBASER_CACHE_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|GICR_PENDBASER_CACHE_DnGnRnE
value|0x0UL
end_define

begin_define
define|#
directive|define
name|GICR_PENDBASER_CACHE_NIN
value|0x1UL
end_define

begin_define
define|#
directive|define
name|GICR_PENDBASER_CACHE_NIRAWT
value|0x2UL
end_define

begin_define
define|#
directive|define
name|GICR_PENDBASER_CACHE_NIRAWB
value|0x3UL
end_define

begin_define
define|#
directive|define
name|GICR_PENDBASER_CACHE_NIWAWT
value|0x4UL
end_define

begin_define
define|#
directive|define
name|GICR_PENDBASER_CACHE_NIWAWB
value|0x5UL
end_define

begin_define
define|#
directive|define
name|GICR_PENDBASER_CACHE_NIRAWAWT
value|0x6UL
end_define

begin_define
define|#
directive|define
name|GICR_PENDBASER_CACHE_NIRAWAWB
value|0x7UL
end_define

begin_define
define|#
directive|define
name|GICR_PENDBASER_CACHE_MASK
define|\
value|(0x7UL<< GICR_PENDBASER_CACHE_SHIFT)
end_define

begin_comment
comment|/*  * Shareability  * 0x0 - Non-shareable  * 0x1 - Inner-shareable  * 0x2 - Outer-shareable  * 0x3 - Reserved. Threated as 0x0  */
end_comment

begin_define
define|#
directive|define
name|GICR_PENDBASER_SHARE_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|GICR_PENDBASER_SHARE_NS
value|0x0UL
end_define

begin_define
define|#
directive|define
name|GICR_PENDBASER_SHARE_IS
value|0x1UL
end_define

begin_define
define|#
directive|define
name|GICR_PENDBASER_SHARE_OS
value|0x2UL
end_define

begin_define
define|#
directive|define
name|GICR_PENDBASER_SHARE_RES
value|0x3UL
end_define

begin_define
define|#
directive|define
name|GICR_PENDBASER_SHARE_MASK
define|\
value|(0x3UL<< GICR_PENDBASER_SHARE_SHIFT)
end_define

begin_comment
comment|/* Re-distributor registers for SGIs and PPIs */
end_comment

begin_define
define|#
directive|define
name|GICR_RD_BASE_SIZE
value|PAGE_SIZE_64K
end_define

begin_define
define|#
directive|define
name|GICR_SGI_BASE_SIZE
value|PAGE_SIZE_64K
end_define

begin_define
define|#
directive|define
name|GICR_VLPI_BASE_SIZE
value|PAGE_SIZE_64K
end_define

begin_define
define|#
directive|define
name|GICR_RESERVED_SIZE
value|PAGE_SIZE_64K
end_define

begin_define
define|#
directive|define
name|GICR_ISENABLER0
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|GICR_ICENABLER0
value|(0x0180)
end_define

begin_define
define|#
directive|define
name|GICR_I_ENABLER_SGI_MASK
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|GICR_I_ENABLER_PPI_MASK
value|(0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|GICR_I_PER_IPRIORITYn
value|(GICD_I_PER_IPRIORITYn)
end_define

begin_comment
comment|/* ITS registers */
end_comment

begin_define
define|#
directive|define
name|GITS_PIDR2
value|GICR_PIDR2
end_define

begin_define
define|#
directive|define
name|GITS_PIDR2_ARCH_MASK
value|GICR_PIDR2_ARCH_MASK
end_define

begin_define
define|#
directive|define
name|GITS_PIDR2_ARCH_GICv3
value|GICR_PIDR2_ARCH_GICv3
end_define

begin_define
define|#
directive|define
name|GITS_PIDR2_ARCH_GICv4
value|GICR_PIDR2_ARCH_GICv4
end_define

begin_define
define|#
directive|define
name|GITS_CTLR
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|GITS_CTLR_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GITS_IIDR
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|GITS_IIDR_PRODUCT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|GITS_IIDR_PRODUCT_MASK
value|(0xff<< GITS_IIDR_PRODUCT_SHIFT)
end_define

begin_define
define|#
directive|define
name|GITS_IIDR_VARIANT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GITS_IIDR_VARIANT_MASK
value|(0xf<< GITS_IIDR_VARIANT_SHIFT)
end_define

begin_define
define|#
directive|define
name|GITS_IIDR_REVISION_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|GITS_IIDR_REVISION_MASK
value|(0xf<< GITS_IIDR_REVISION_SHIFT)
end_define

begin_define
define|#
directive|define
name|GITS_IIDR_IMPLEMENTOR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GITS_IIDR_IMPLEMENTOR_MASK
value|(0xfff<< GITS_IIDR_IMPLEMENTOR_SHIFT)
end_define

begin_define
define|#
directive|define
name|GITS_IIDR_RAW
parameter_list|(
name|impl
parameter_list|,
name|prod
parameter_list|,
name|var
parameter_list|,
name|rev
parameter_list|)
define|\
value|((prod)<< GITS_IIDR_PRODUCT_SHIFT |		\      (var)<< GITS_IIDR_VARIANT_SHIFT | 		\      (rev)<< GITS_IIDR_REVISION_SHIFT |		\      (impl)<< GITS_IIDR_IMPLEMENTOR_SHIFT)
end_define

begin_define
define|#
directive|define
name|GITS_IIDR_IMPL_CAVIUM
value|(0x34c)
end_define

begin_define
define|#
directive|define
name|GITS_IIDR_PROD_THUNDER
value|(0xa1)
end_define

begin_define
define|#
directive|define
name|GITS_IIDR_VAR_THUNDER_1
value|(0x0)
end_define

begin_define
define|#
directive|define
name|GITS_CBASER
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_VALID
value|(1UL<< 63)
end_define

begin_comment
comment|/*  * Cacheability  * 0x0 - Device-nGnRnE  * 0x1 - Normal Inner Non-cacheable  * 0x2 - Normal Inner Read-allocate, Write-through  * 0x3 - Normal Inner Read-allocate, Write-back  * 0x4 - Normal Inner Write-allocate, Write-through  * 0x5 - Normal Inner Write-allocate, Write-back  * 0x6 - Normal Inner Read-allocate, Write-allocate, Write-through  * 0x7 - Normal Inner Read-allocate, Write-allocate, Write-back  */
end_comment

begin_define
define|#
directive|define
name|GITS_CBASER_CACHE_SHIFT
value|59
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_CACHE_DnGnRnE
value|0x0UL
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_CACHE_NIN
value|0x1UL
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_CACHE_NIRAWT
value|0x2UL
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_CACHE_NIRAWB
value|0x3UL
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_CACHE_NIWAWT
value|0x4UL
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_CACHE_NIWAWB
value|0x5UL
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_CACHE_NIRAWAWT
value|0x6UL
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_CACHE_NIRAWAWB
value|0x7UL
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_CACHE_MASK
value|(0x7UL<< GITS_CBASER_CACHE_SHIFT)
end_define

begin_comment
comment|/*  * Shareability  * 0x0 - Non-shareable  * 0x1 - Inner-shareable  * 0x2 - Outer-shareable  * 0x3 - Reserved. Threated as 0x0  */
end_comment

begin_define
define|#
directive|define
name|GITS_CBASER_SHARE_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_SHARE_NS
value|0x0UL
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_SHARE_IS
value|0x1UL
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_SHARE_OS
value|0x2UL
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_SHARE_RES
value|0x3UL
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_SHARE_MASK
define|\
value|(0x3UL<< GITS_CBASER_SHARE_SHIFT)
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_PA_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|GITS_CBASER_PA_MASK
value|(0xFFFFFFFFFUL<< GITS_CBASER_PA_SHIFT)
end_define

begin_define
define|#
directive|define
name|GITS_CWRITER
value|(0x0088)
end_define

begin_define
define|#
directive|define
name|GITS_CREADR
value|(0x0090)
end_define

begin_define
define|#
directive|define
name|GITS_BASER_BASE
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|GITS_BASER
parameter_list|(
name|x
parameter_list|)
value|(GITS_BASER_BASE + (x) * 8)
end_define

begin_define
define|#
directive|define
name|GITS_BASER_VALID
value|(1UL<< 63)
end_define

begin_define
define|#
directive|define
name|GITS_BASER_TYPE_SHIFT
value|56
end_define

begin_define
define|#
directive|define
name|GITS_BASER_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& GITS_BASER_TYPE_MASK)>> GITS_BASER_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|GITS_BASER_TYPE_UNIMPL
value|0x0UL
end_define

begin_comment
comment|/* Unimplemented */
end_comment

begin_define
define|#
directive|define
name|GITS_BASER_TYPE_DEV
value|0x1UL
end_define

begin_comment
comment|/* Devices */
end_comment

begin_define
define|#
directive|define
name|GITS_BASER_TYPE_VP
value|0x2UL
end_define

begin_comment
comment|/* Virtual Processors */
end_comment

begin_define
define|#
directive|define
name|GITS_BASER_TYPE_PP
value|0x3UL
end_define

begin_comment
comment|/* Physical Processors */
end_comment

begin_define
define|#
directive|define
name|GITS_BASER_TYPE_IC
value|0x4UL
end_define

begin_comment
comment|/* Interrupt Collections */
end_comment

begin_define
define|#
directive|define
name|GITS_BASER_TYPE_RES5
value|0x5UL
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|GITS_BASER_TYPE_RES6
value|0x6UL
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|GITS_BASER_TYPE_RES7
value|0x7UL
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|GITS_BASER_TYPE_MASK
value|(0x7UL<< GITS_BASER_TYPE_SHIFT)
end_define

begin_comment
comment|/*  * Cacheability  * 0x0 - Non-cacheable, non-bufferable  * 0x1 - Non-cacheable  * 0x2 - Read-allocate, Write-through  * 0x3 - Read-allocate, Write-back  * 0x4 - Write-allocate, Write-through  * 0x5 - Write-allocate, Write-back  * 0x6 - Read-allocate, Write-allocate, Write-through  * 0x7 - Read-allocate, Write-allocate, Write-back  */
end_comment

begin_define
define|#
directive|define
name|GITS_BASER_CACHE_SHIFT
value|59
end_define

begin_define
define|#
directive|define
name|GITS_BASER_CACHE_NCNB
value|0x0UL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_CACHE_NC
value|0x1UL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_CACHE_RAWT
value|0x2UL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_CACHE_RAWB
value|0x3UL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_CACHE_WAWT
value|0x4UL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_CACHE_WAWB
value|0x5UL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_CACHE_RAWAWT
value|0x6UL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_CACHE_RAWAWB
value|0x7UL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_CACHE_MASK
value|(0x7UL<< GITS_BASER_CACHE_SHIFT)
end_define

begin_define
define|#
directive|define
name|GITS_BASER_ESIZE_SHIFT
value|48
end_define

begin_define
define|#
directive|define
name|GITS_BASER_ESIZE_MASK
value|(0x1FUL<< GITS_BASER_ESIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|GITS_BASER_ESIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)& GITS_BASER_ESIZE_MASK)>> GITS_BASER_ESIZE_SHIFT) + 1)
end_define

begin_define
define|#
directive|define
name|GITS_BASER_PA_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|GITS_BASER_PA_MASK
value|(0xFFFFFFFFFUL<< GITS_BASER_PA_SHIFT)
end_define

begin_comment
comment|/*  * Shareability  * 0x0 - Non-shareable  * 0x1 - Inner-shareable  * 0x2 - Outer-shareable  * 0x3 - Reserved. Threated as 0x0  */
end_comment

begin_define
define|#
directive|define
name|GITS_BASER_SHARE_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|GITS_BASER_SHARE_NS
value|0x0UL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_SHARE_IS
value|0x1UL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_SHARE_OS
value|0x2UL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_SHARE_RES
value|0x3UL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_SHARE_MASK
value|(0x3UL<< GITS_BASER_SHARE_SHIFT)
end_define

begin_define
define|#
directive|define
name|GITS_BASER_PSZ_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|GITS_BASER_PSZ_4K
value|0x0UL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_PSZ_16K
value|0x1UL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_PSZ_64K
value|0x2UL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_PSZ_MASK
value|(0x3UL<< GITS_BASER_PSZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|GITS_BASER_SIZE_MASK
value|0xFFUL
end_define

begin_define
define|#
directive|define
name|GITS_BASER_NUM
value|8
end_define

begin_define
define|#
directive|define
name|GITS_TYPER
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|GITS_TYPER_PTA
value|(1UL<< 19)
end_define

begin_define
define|#
directive|define
name|GITS_TYPER_DEVB_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|GITS_TYPER_DEVB_MASK
value|(0x1FUL<< GITS_TYPER_DEVB_SHIFT)
end_define

begin_comment
comment|/* Number of device identifiers implemented */
end_comment

begin_define
define|#
directive|define
name|GITS_TYPER_DEVB
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)& GITS_TYPER_DEVB_MASK)>> GITS_TYPER_DEVB_SHIFT) + 1)
end_define

begin_define
define|#
directive|define
name|GITS_TYPER_ITTES_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|GITS_TYPER_ITTES_MASK
value|(0xFUL<< GITS_TYPER_ITTES_SHIFT)
end_define

begin_comment
comment|/* Number of bytes per ITT Entry */
end_comment

begin_define
define|#
directive|define
name|GITS_TYPER_ITTES
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)& GITS_TYPER_ITTES_MASK)>> GITS_TYPER_ITTES_SHIFT) + 1)
end_define

begin_define
define|#
directive|define
name|GITS_TRANSLATER
value|(0x10040)
end_define

begin_comment
comment|/*  * LPI related  */
end_comment

begin_define
define|#
directive|define
name|LPI_CONF_PRIO_MASK
value|(0xFC)
end_define

begin_define
define|#
directive|define
name|LPI_CONF_GROUP1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPI_CONF_ENABLE
value|(1<< 0)
end_define

begin_comment
comment|/*  * CPU interface  */
end_comment

begin_comment
comment|/*  * Registers list (ICC_xyz_EL1):  *  * PMR     - Priority Mask Register  *		* interrupts of priority higher than specified  *		  in this mask will be signalled to the CPU.  *		  (0xff - lowest possible prio., 0x00 - highest prio.)  *  * CTLR    - Control Register  *		* controls behavior of the CPU interface and displays  *		  implemented features.  *  * IGRPEN1 - Interrupt Group 1 Enable Register  *  * IAR1    - Interrupt Acknowledge Register Group 1  *		* contains number of the highest priority pending  *		  interrupt from the Group 1.  *  * EOIR1   - End of Interrupt Register Group 1  *		* Writes inform CPU interface about completed Group 1  *		  interrupts processing.  */
end_comment

begin_define
define|#
directive|define
name|gic_icc_write
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\ 	WRITE_SPECIALREG(ICC_ ##reg ##_EL1, val);		\ 	isb();							\ } while (0)
end_define

begin_define
define|#
directive|define
name|gic_icc_read
parameter_list|(
name|reg
parameter_list|)
define|\
value|({								\ 	uint64_t val;						\ 								\ 	val = READ_SPECIALREG(ICC_ ##reg ##_EL1);		\ 	(val);							\ })
end_define

begin_define
define|#
directive|define
name|gic_icc_set
parameter_list|(
name|reg
parameter_list|,
name|mask
parameter_list|)
define|\
value|do {								\ 	uint64_t val;						\ 	val = gic_icc_read(reg);				\ 	val |= (mask);						\ 	gic_icc_write(reg, val);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|gic_icc_clear
parameter_list|(
name|reg
parameter_list|,
name|mask
parameter_list|)
define|\
value|do {								\ 	uint64_t val;						\ 	val = gic_icc_read(reg);				\ 	val&= ~(mask);						\ 	gic_icc_write(reg, val);				\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GIC_V3_REG_H_ */
end_comment

end_unit

