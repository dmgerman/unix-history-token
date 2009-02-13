begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Poul-Henning Kamp  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACPI_HPET_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACPI_HPET_H__
end_define

begin_define
define|#
directive|define
name|HPET_MEM_WIDTH
value|0x400
end_define

begin_comment
comment|/* Expected memory region size */
end_comment

begin_comment
comment|/* General registers */
end_comment

begin_define
define|#
directive|define
name|HPET_CAPABILITIES
value|0x0
end_define

begin_comment
comment|/* General capabilities and ID */
end_comment

begin_define
define|#
directive|define
name|HPET_CAP_VENDOR_ID
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|HPET_CAP_LEG_RT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|HPET_CAP_COUNT_SIZE
value|0x00002000
end_define

begin_comment
comment|/* 1 = 64-bit, 0 = 32-bit */
end_comment

begin_define
define|#
directive|define
name|HPET_CAP_NUM_TIM
value|0x00001f00
end_define

begin_define
define|#
directive|define
name|HPET_CAP_REV_ID
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HPET_PERIOD
value|0x4
end_define

begin_comment
comment|/* Period (1/hz) of timer */
end_comment

begin_define
define|#
directive|define
name|HPET_CONFIG
value|0x10
end_define

begin_comment
comment|/* General configuration register */
end_comment

begin_define
define|#
directive|define
name|HPET_CNF_LEG_RT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HPET_CNF_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HPET_ISR
value|0x20
end_define

begin_comment
comment|/* General interrupt status register */
end_comment

begin_define
define|#
directive|define
name|HPET_MAIN_COUNTER
value|0xf0
end_define

begin_comment
comment|/* Main counter register */
end_comment

begin_comment
comment|/* Timer registers */
end_comment

begin_define
define|#
directive|define
name|HPET_TIMER_CAP_CNF
parameter_list|(
name|x
parameter_list|)
value|((x) * 0x20 + 0x100)
end_define

begin_define
define|#
directive|define
name|HPET_TCAP_INT_ROUTE
value|0xffffffff00000000
end_define

begin_define
define|#
directive|define
name|HPET_TCAP_FSB_INT_DEL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|HPET_TCNF_FSB_EN
value|0x00004000
end_define

begin_define
define|#
directive|define
name|HPET_TCNF_INT_ROUTE
value|0x00003e00
end_define

begin_define
define|#
directive|define
name|HPET_TCNF_32MODE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HPET_TCNF_VAL_SET
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HPET_TCAP_SIZE
value|0x00000020
end_define

begin_comment
comment|/* 1 = 64-bit, 0 = 32-bit */
end_comment

begin_define
define|#
directive|define
name|HPET_TCAP_PER_INT
value|0x00000010
end_define

begin_comment
comment|/* Supports periodic interrupts */
end_comment

begin_define
define|#
directive|define
name|HPET_TCNF_TYPE
value|0x00000008
end_define

begin_comment
comment|/* 1 = periodic, 0 = one-shot */
end_comment

begin_define
define|#
directive|define
name|HPET_TCNF_INT_ENB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HPET_TCNT_INT_TYPE
value|0x00000002
end_define

begin_comment
comment|/* 1 = level triggered, 0 = edge */
end_comment

begin_define
define|#
directive|define
name|HPET_TIMER_COMPARATOR
parameter_list|(
name|x
parameter_list|)
value|((x) * 0x20 + 0x108)
end_define

begin_define
define|#
directive|define
name|HPET_TIMER_FSB_VAL
parameter_list|(
name|x
parameter_list|)
value|((x) * 0x20 + 0x110)
end_define

begin_define
define|#
directive|define
name|HPET_TIMER_FSB_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x) * 0x20 + 0x114)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__ACPI_HPET_H__ */
end_comment

end_unit

