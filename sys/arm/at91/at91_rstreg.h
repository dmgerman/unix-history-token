begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Greg Ansley.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91_RSTREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_RSTREG_H
end_define

begin_define
define|#
directive|define
name|RST_CR
value|0x0
end_define

begin_comment
comment|/* Control Register */
end_comment

begin_define
define|#
directive|define
name|RST_SR
value|0x4
end_define

begin_comment
comment|/* Status Register */
end_comment

begin_define
define|#
directive|define
name|RST_MR
value|0x8
end_define

begin_comment
comment|/* Mode Register */
end_comment

begin_comment
comment|/* RST_CR */
end_comment

begin_define
define|#
directive|define
name|RST_CR_PROCRST
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|RST_CR_PERRST
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|RST_CR_EXTRST
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|RST_CR_KEY
value|(0xa5<<24)
end_define

begin_comment
comment|/* RST_SR */
end_comment

begin_define
define|#
directive|define
name|RST_SR_SRCMP
value|(1<<17)
end_define

begin_comment
comment|/* Software Reset in progress */
end_comment

begin_define
define|#
directive|define
name|RST_SR_NRSTL
value|(1<<16)
end_define

begin_comment
comment|/* NRST pin level at MCK */
end_comment

begin_define
define|#
directive|define
name|RST_SR_URSTS
value|(1<<0)
end_define

begin_comment
comment|/* NRST pin has been active */
end_comment

begin_define
define|#
directive|define
name|RST_SR_RST_POW
value|(0<<8)
end_define

begin_comment
comment|/* General (Power On) reset */
end_comment

begin_define
define|#
directive|define
name|RST_SR_RST_WAKE
value|(1<<8)
end_define

begin_comment
comment|/* Wake-up reset */
end_comment

begin_define
define|#
directive|define
name|RST_SR_RST_WDT
value|(2<<8)
end_define

begin_comment
comment|/* Watchdog reset */
end_comment

begin_define
define|#
directive|define
name|RST_SR_RST_SOFT
value|(3<<8)
end_define

begin_comment
comment|/* Software  reset */
end_comment

begin_define
define|#
directive|define
name|RST_SR_RST_USR
value|(4<<8)
end_define

begin_comment
comment|/* User (External) reset */
end_comment

begin_define
define|#
directive|define
name|RST_SR_RST_MASK
value|(7<<8)
end_define

begin_comment
comment|/* User (External) reset */
end_comment

begin_comment
comment|/* RST_MR */
end_comment

begin_define
define|#
directive|define
name|RST_MR_URSTEN
value|(1<<0)
end_define

begin_comment
comment|/* User reset enable */
end_comment

begin_define
define|#
directive|define
name|RST_MR_URSIEN
value|(1<<4)
end_define

begin_comment
comment|/* User interrupt enable */
end_comment

begin_define
define|#
directive|define
name|RST_MR_ERSTL
parameter_list|(
name|x
parameter_list|)
value|((x)<<8)
end_define

begin_comment
comment|/* External reset length */
end_comment

begin_define
define|#
directive|define
name|RST_MR_KEY
value|(0xa5<<24)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLER__
end_ifndef

begin_function_decl
name|void
name|at91_rst_cpu_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_RSTREG_H */
end_comment

end_unit

