begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_BROADCOM_BMIPSREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_BROADCOM_BMIPSREG_H_
end_define

begin_comment
comment|/*  * Common BMIPS32/BMIPS3300 Registers  */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS_CORECTL
value|0x00
end_define

begin_comment
comment|/**< core control */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS_CORECTL_FORCE_RST
value|0x01
end_define

begin_comment
comment|/**< force reset */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS_CORECTL_NO_FLSH_EXC
value|0x02
end_define

begin_comment
comment|/**< flash exception disable */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS_INTR_STATUS
value|0x20
end_define

begin_comment
comment|/**< interrupt status */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS_INTR_MASK
value|0x24
end_define

begin_comment
comment|/**< interrupt mask */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS_TIMER_INTMASK
value|0x01
end_define

begin_comment
comment|/**< timer interrupt mask */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS_TIMER_CTRL
value|0x28
end_define

begin_comment
comment|/**< timer interval (?) */
end_comment

begin_comment
comment|/*  * Broadcom BMIPS32 (BHND_COREID_MIPS)  */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS32_CORECTL
value|BCM_BMIPS_CORECTL
end_define

begin_define
define|#
directive|define
name|BCM_BMIPS32_BIST_STATUS
value|0x04
end_define

begin_comment
comment|/**< built-in self-test status */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS32_INTR_STATUS
value|BCM_BMIPS_INTR_STATUS
end_define

begin_define
define|#
directive|define
name|BCM_BMIPS32_INTR_MASK
value|BCM_BMIPS_INTR_MASK
end_define

begin_define
define|#
directive|define
name|BCM_BMIPS32_TIMER_CTRL
value|BCM_BMIPS_TIMER_CTRL
end_define

begin_comment
comment|/*  * Broadcom BMIPS3300+ (BHND_COREID_MIPS33)  */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS33_CORECTL
value|BCM_BMIPS_CORECTL
end_define

begin_define
define|#
directive|define
name|BCM_BMIPS33_BIST_CTRL
value|0x04
end_define

begin_comment
comment|/**< build-in self-test control */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS33_BIST_CTRL_DUMP
value|0x01
end_define

begin_comment
comment|/**< BIST dump */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS33_BIST_CTRL_DEBUG
value|0x02
end_define

begin_comment
comment|/**< BIST debug */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS33_BIST_CTRL_HOLD
value|0x04
end_define

begin_comment
comment|/**< BIST hold */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS33_BIST_STATUS
value|0x08
end_define

begin_comment
comment|/**< built-in self-test status */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS33_INTR_STATUS
value|BCM_BMIPS_INTR_STATUS
end_define

begin_define
define|#
directive|define
name|BCM_BMIPS33_INTR_MASK
value|BCM_BMIPS_INTR_MASK
end_define

begin_define
define|#
directive|define
name|BCM_BMIPS33_TIMER_CTRL
value|BCM_BMIPS_TIMER_CTRL
end_define

begin_define
define|#
directive|define
name|BCM_BMIPS33_TEST_MUX_SEL
value|0x30
end_define

begin_comment
comment|/**< test multiplexer select (?) */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS33_TEST_MUX_EN
value|0x34
end_define

begin_comment
comment|/**< test multiplexer enable (?) */
end_comment

begin_define
define|#
directive|define
name|BCM_BMIPS33_EJTAG_GPIO_EN
value|0x2C
end_define

begin_comment
comment|/**< ejtag gpio enable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_BROADCOM_BMIPSREG_H_ */
end_comment

end_unit

