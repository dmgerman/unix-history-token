begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Gallon Sylvestre.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91WDTREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91WDTREG_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|WDT_CLOCK
end_ifndef

begin_define
define|#
directive|define
name|WDT_CLOCK
value|(32768)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WDT_DIV
value|(128)
end_define

begin_comment
comment|/* Clock is slow clock / 128 */
end_comment

begin_define
define|#
directive|define
name|WDT_CR
value|0x0
end_define

begin_comment
comment|/* Control Register */
end_comment

begin_define
define|#
directive|define
name|WDT_MR
value|0x4
end_define

begin_comment
comment|/* Mode Register */
end_comment

begin_define
define|#
directive|define
name|WDT_SR
value|0x8
end_define

begin_comment
comment|/* Status Register */
end_comment

begin_comment
comment|/* WDT_CR */
end_comment

begin_define
define|#
directive|define
name|WDT_KEY
value|(0xa5<<24)
end_define

begin_define
define|#
directive|define
name|WDT_WDRSTT
value|0x1
end_define

begin_comment
comment|/* WDT_MR */
end_comment

begin_define
define|#
directive|define
name|WDT_WDV
parameter_list|(
name|x
parameter_list|)
value|(x& 0xfff)
end_define

begin_comment
comment|/* counter value*/
end_comment

begin_define
define|#
directive|define
name|WDT_WDFIEN
value|(1<<12)
end_define

begin_comment
comment|/* enable interrupt */
end_comment

begin_define
define|#
directive|define
name|WDT_WDRSTEN
value|(1<<13)
end_define

begin_comment
comment|/* enable reset */
end_comment

begin_define
define|#
directive|define
name|WDT_WDRPROC
value|(1<<14)
end_define

begin_comment
comment|/* processor reset */
end_comment

begin_define
define|#
directive|define
name|WDT_WDDIS
value|(1<<15)
end_define

begin_comment
comment|/* disable */
end_comment

begin_define
define|#
directive|define
name|WDT_WDD
parameter_list|(
name|x
parameter_list|)
value|((x& 0xfff)<< 16)
end_define

begin_comment
comment|/* delta value */
end_comment

begin_define
define|#
directive|define
name|WDT_WDDBGHLT
value|(1<<28)
end_define

begin_comment
comment|/* halt in debug */
end_comment

begin_define
define|#
directive|define
name|WDT_WDIDLEHLT
value|(1<<29)
end_define

begin_comment
comment|/* halt in idle */
end_comment

begin_comment
comment|/* WDT_SR */
end_comment

begin_define
define|#
directive|define
name|WDT_WDUNF
value|0x1
end_define

begin_define
define|#
directive|define
name|WDT_WDERR
value|0x2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91WDTREG_H */
end_comment

end_unit

