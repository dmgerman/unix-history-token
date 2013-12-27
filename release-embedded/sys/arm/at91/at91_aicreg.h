begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Sylvestre Gallon. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91_AICREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_AICREG_H
end_define

begin_comment
comment|/* Interrupt Controller */
end_comment

begin_define
define|#
directive|define
name|IC_SMR
value|(0)
end_define

begin_comment
comment|/* Source mode register */
end_comment

begin_define
define|#
directive|define
name|IC_SVR
value|(128)
end_define

begin_comment
comment|/* Source vector register */
end_comment

begin_define
define|#
directive|define
name|IC_IVR
value|(256)
end_define

begin_comment
comment|/* IRQ vector register */
end_comment

begin_define
define|#
directive|define
name|IC_FVR
value|(260)
end_define

begin_comment
comment|/* FIQ vector register */
end_comment

begin_define
define|#
directive|define
name|IC_ISR
value|(264)
end_define

begin_comment
comment|/* Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|IC_IPR
value|(268)
end_define

begin_comment
comment|/* Interrupt pending register */
end_comment

begin_define
define|#
directive|define
name|IC_IMR
value|(272)
end_define

begin_comment
comment|/* Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|IC_CISR
value|(276)
end_define

begin_comment
comment|/* Core interrupt status register */
end_comment

begin_define
define|#
directive|define
name|IC_IECR
value|(288)
end_define

begin_comment
comment|/* Interrupt enable command register */
end_comment

begin_define
define|#
directive|define
name|IC_IDCR
value|(292)
end_define

begin_comment
comment|/* Interrupt disable command register */
end_comment

begin_define
define|#
directive|define
name|IC_ICCR
value|(296)
end_define

begin_comment
comment|/* Interrupt clear command register */
end_comment

begin_define
define|#
directive|define
name|IC_ISCR
value|(300)
end_define

begin_comment
comment|/* Interrupt set command register */
end_comment

begin_define
define|#
directive|define
name|IC_EOICR
value|(304)
end_define

begin_comment
comment|/* End of interrupt command register */
end_comment

begin_define
define|#
directive|define
name|IC_SPU
value|(308)
end_define

begin_comment
comment|/* Spurious vector register */
end_comment

begin_define
define|#
directive|define
name|IC_DCR
value|(312)
end_define

begin_comment
comment|/* Debug control register */
end_comment

begin_define
define|#
directive|define
name|IC_FFER
value|(320)
end_define

begin_comment
comment|/* Fast forcing enable register */
end_comment

begin_define
define|#
directive|define
name|IC_FFDR
value|(324)
end_define

begin_comment
comment|/* Fast forcing disable register */
end_comment

begin_define
define|#
directive|define
name|IC_FFSR
value|(328)
end_define

begin_comment
comment|/* Fast forcing status register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*ARM_AT91_AT91_AICREG_H*/
end_comment

end_unit

