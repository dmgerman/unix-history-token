begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_BROADCOM_MIPS74KREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_BROADCOM_MIPS74KREG_H_
end_define

begin_define
define|#
directive|define
name|BCM_MIPS74K_CORECTL
value|0x00
end_define

begin_comment
comment|/**< core control */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_EXCBASE
value|0x04
end_define

begin_comment
comment|/**< exception base */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_BIST_STATUS
value|0x0C
end_define

begin_comment
comment|/**< built-in self-test status */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_INTR_STATUS
value|0x10
end_define

begin_comment
comment|/**< interrupt status */
end_comment

begin_comment
comment|/* INTR(0-5)_MASK map bcma(4) OOB interrupt bus lines to MIPS hardware  * interrupts. */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_INTR0_SEL
value|0x14
end_define

begin_comment
comment|/**< IRQ0 OOBSEL mask */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_INTR1_SEL
value|0x18
end_define

begin_comment
comment|/**< IRQ1 OOBSEL mask */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_INTR2_SEL
value|0x1C
end_define

begin_comment
comment|/**< IRQ2 OOBSEL mask */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_INTR3_SEL
value|0x20
end_define

begin_comment
comment|/**< IRQ3 OOBSEL mask */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_INTR4_SEL
value|0x24
end_define

begin_comment
comment|/**< IRQ4 OOBSEL mask */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_INTR5_SEL
value|0x28
end_define

begin_comment
comment|/**< IRQ5 OOBSEL mask */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_NUM_INTR
value|6
end_define

begin_comment
comment|/**< routable CPU interrupt count */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_INTR_SEL
parameter_list|(
name|_intr
parameter_list|)
define|\
value|(BCM_MIPS74K_INTR0_SEL + ((_intr) * 4))
end_define

begin_define
define|#
directive|define
name|BCM_MIPS74K_INTR_SEL_FLAG
parameter_list|(
name|_i
parameter_list|)
value|(1<<_i)
end_define

begin_define
define|#
directive|define
name|BCM_MIPS74K_TIMER_IVEC
value|31
end_define

begin_comment
comment|/**< MIPS timer's bus interrupt vector */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_NMI_MASK
value|0x2C
end_define

begin_comment
comment|/**< nmi mask */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_GPIO_SEL
value|0x40
end_define

begin_comment
comment|/**< gpio select */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_GPIO_OUT
value|0x44
end_define

begin_comment
comment|/**< gpio output enable */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_GPIO_EN
value|0x48
end_define

begin_comment
comment|/**< gpio enable */
end_comment

begin_comment
comment|/** The MIPS timer interrupt IRQ assignment */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS74K_GET_TIMER_IRQ
parameter_list|()
define|\
value|((mips_rd_intctl()& MIPS_INTCTL_IPTI_MASK)>> MIPS_INTCTL_IPTI_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_BROADCOM_MIPS74KREG_H_ */
end_comment

end_unit

