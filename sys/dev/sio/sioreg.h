begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)comreg.h	7.2 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Receiver clock frequency for "standard" pc serial ports. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_RCLK
value|1843200
end_define

begin_comment
comment|/* speed to initialize to during chip tests */
end_comment

begin_define
define|#
directive|define
name|SIO_TEST_SPEED
value|9600
end_define

begin_comment
comment|/* default serial console speed if not set with sysctl or probed from boot */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONSPEED
end_ifndef

begin_define
define|#
directive|define
name|CONSPEED
value|9600
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* default serial gdb speed if not set with sysctl or probed from boot */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDBSPEED
end_ifndef

begin_define
define|#
directive|define
name|GDBSPEED
value|CONSPEED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IO_COMSIZE
value|8
end_define

begin_comment
comment|/* 8250, 16x50 com controllers */
end_comment

end_unit

