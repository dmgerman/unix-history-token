begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91STREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91STREG_H
end_define

begin_define
define|#
directive|define
name|ST_CR
value|0x00
end_define

begin_comment
comment|/* Control register */
end_comment

begin_define
define|#
directive|define
name|ST_PIMR
value|0x04
end_define

begin_comment
comment|/* Period interval mode register */
end_comment

begin_define
define|#
directive|define
name|ST_WDMR
value|0x08
end_define

begin_comment
comment|/* Watchdog mode register */
end_comment

begin_define
define|#
directive|define
name|ST_RTMR
value|0x0c
end_define

begin_comment
comment|/* Real-time mode register */
end_comment

begin_define
define|#
directive|define
name|ST_SR
value|0x10
end_define

begin_comment
comment|/* Status register */
end_comment

begin_define
define|#
directive|define
name|ST_IER
value|0x14
end_define

begin_comment
comment|/* Interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|ST_IDR
value|0x18
end_define

begin_comment
comment|/* Interrupt disable register */
end_comment

begin_define
define|#
directive|define
name|ST_IMR
value|0x1c
end_define

begin_comment
comment|/* Interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|ST_RTAR
value|0x20
end_define

begin_comment
comment|/* Real-time alarm register */
end_comment

begin_define
define|#
directive|define
name|ST_CRTR
value|0x24
end_define

begin_comment
comment|/* Current real-time register */
end_comment

begin_comment
comment|/* ST_CR */
end_comment

begin_define
define|#
directive|define
name|ST_CR_WDRST
value|(1U<< 0)
end_define

begin_comment
comment|/* WDRST: Watchdog Timer Restart */
end_comment

begin_comment
comment|/* ST_WDMR */
end_comment

begin_define
define|#
directive|define
name|ST_WDMR_EXTEN
value|(1U<< 17)
end_define

begin_comment
comment|/* EXTEN: External Signal Assert Enable */
end_comment

begin_define
define|#
directive|define
name|ST_WDMR_RSTEN
value|(1U<< 16)
end_define

begin_comment
comment|/* RSTEN: Reset Enable */
end_comment

begin_comment
comment|/* ST_SR, ST_IER, ST_IDR, ST_IMR */
end_comment

begin_define
define|#
directive|define
name|ST_SR_PITS
value|(1U<< 0)
end_define

begin_comment
comment|/* PITS: Period Interval Timer Status */
end_comment

begin_define
define|#
directive|define
name|ST_SR_WDOVF
value|(1U<< 1)
end_define

begin_comment
comment|/* WDOVF: Watchdog Overflow */
end_comment

begin_define
define|#
directive|define
name|ST_SR_RTTINC
value|(1U<< 2)
end_define

begin_comment
comment|/* RTTINC: Real-time Timer Increment */
end_comment

begin_define
define|#
directive|define
name|ST_SR_ALMS
value|(1U<< 3)
end_define

begin_comment
comment|/* ALMS: Alarm Status */
end_comment

begin_comment
comment|/* ST_CRTR */
end_comment

begin_define
define|#
directive|define
name|ST_CRTR_MASK
value|0xfffff
end_define

begin_comment
comment|/* 20-bit counter */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91STREG_H */
end_comment

end_unit

