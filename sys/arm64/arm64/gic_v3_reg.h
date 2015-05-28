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
value|((((n)& 0xF1) + 1) * 32)
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

