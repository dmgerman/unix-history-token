begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: sa11x0_ostreg.h,v 1.1 2001/07/08 23:37:53 rjs Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 The NetBSD Foundation, Inc.  All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Ichiro FUKUHARA.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * SA-11x0 OS Timer Register   */
end_comment

begin_comment
comment|/* OS Timer Match Register */
end_comment

begin_define
define|#
directive|define
name|SAOST_MR0
value|0x00
end_define

begin_define
define|#
directive|define
name|SAOST_MR1
value|0x04
end_define

begin_define
define|#
directive|define
name|SAOST_MR2
value|0x08
end_define

begin_define
define|#
directive|define
name|SAOST_MR3
value|0x0C
end_define

begin_comment
comment|/* OS Timer Count Register */
end_comment

begin_define
define|#
directive|define
name|SAOST_CR
value|0x10
end_define

begin_comment
comment|/* OS Timer Status Register */
end_comment

begin_define
define|#
directive|define
name|SAOST_SR
value|0x14
end_define

begin_define
define|#
directive|define
name|SR_CH0
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|SR_CH1
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|SR_CH2
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|SR_CH3
value|(1<<3)
end_define

begin_comment
comment|/* OS Timer Watchdog Match Enable Register */
end_comment

begin_define
define|#
directive|define
name|SAOST_WR
value|0x18
end_define

begin_comment
comment|/* OS Timer Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|SAOST_IR
value|0x1C
end_define

begin_comment
comment|/*  * SA-1110 Real Time Clock  */
end_comment

begin_comment
comment|/* RTC Alarm Register */
end_comment

begin_define
define|#
directive|define
name|SARTC_AR
value|0x00
end_define

begin_comment
comment|/* RTC Counter Register */
end_comment

begin_define
define|#
directive|define
name|SARTC_CR
value|0x04
end_define

begin_comment
comment|/* RTC Trim Register */
end_comment

begin_define
define|#
directive|define
name|SARTC_TR
value|0x08
end_define

begin_comment
comment|/* RTC Status Register */
end_comment

begin_define
define|#
directive|define
name|SARTC_SR
value|0x0C
end_define

begin_comment
comment|/* end of sa11x0_ostreg.h */
end_comment

end_unit

