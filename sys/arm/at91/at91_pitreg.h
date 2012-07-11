begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Sylvestre Gallon.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91_PITREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_PITREG_H
end_define

begin_define
define|#
directive|define
name|PIT_MR
value|0x0
end_define

begin_define
define|#
directive|define
name|PIT_SR
value|0x4
end_define

begin_define
define|#
directive|define
name|PIT_PIVR
value|0x8
end_define

begin_define
define|#
directive|define
name|PIT_PIIR
value|0xc
end_define

begin_comment
comment|/* PIT_MR */
end_comment

begin_define
define|#
directive|define
name|PIT_PIV
parameter_list|(
name|x
parameter_list|)
value|(x& 0xfffff)
end_define

begin_comment
comment|/* periodic interval value */
end_comment

begin_define
define|#
directive|define
name|PIT_CNT
parameter_list|(
name|x
parameter_list|)
value|((x>>20)& 0xfff)
end_define

begin_comment
comment|/* periodic interval counter */
end_comment

begin_define
define|#
directive|define
name|PIT_EN
value|(1<< 24)
end_define

begin_comment
comment|/* pit enable */
end_comment

begin_define
define|#
directive|define
name|PIT_IEN
value|(1<< 25)
end_define

begin_comment
comment|/* pit interrupt enable */
end_comment

begin_comment
comment|/* PIT_SR */
end_comment

begin_define
define|#
directive|define
name|PIT_PITS_DONE
value|1
end_define

begin_comment
comment|/* interrupt done */
end_comment

begin_function_decl
name|void
name|at91_pit_delay
parameter_list|(
name|int
name|us
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_PITREG_H */
end_comment

end_unit

