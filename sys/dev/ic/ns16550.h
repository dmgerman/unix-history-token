begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)ns16550.h	7.1 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * NS16550 UART registers  */
end_comment

begin_define
define|#
directive|define
name|com_data
value|0
end_define

begin_comment
comment|/* data register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_dlbl
value|0
end_define

begin_comment
comment|/* divisor latch low (W) */
end_comment

begin_define
define|#
directive|define
name|com_dlbh
value|1
end_define

begin_comment
comment|/* divisor latch high (W) */
end_comment

begin_define
define|#
directive|define
name|com_ier
value|1
end_define

begin_comment
comment|/* interrupt enable (W) */
end_comment

begin_define
define|#
directive|define
name|com_iir
value|2
end_define

begin_comment
comment|/* interrupt identification (R) */
end_comment

begin_define
define|#
directive|define
name|com_fifo
value|2
end_define

begin_comment
comment|/* FIFO control (W) */
end_comment

begin_define
define|#
directive|define
name|com_lctl
value|3
end_define

begin_comment
comment|/* line control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_cfcr
value|3
end_define

begin_comment
comment|/* line control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_mcr
value|4
end_define

begin_comment
comment|/* modem control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_lsr
value|5
end_define

begin_comment
comment|/* line status register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_msr
value|6
end_define

begin_comment
comment|/* modem status register (R/W) */
end_comment

end_unit

