begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vlimit.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VLIMIT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VLIMIT_H_
end_define

begin_comment
comment|/*  * Limits for u.u_limit[i], per process, inherited.  */
end_comment

begin_define
define|#
directive|define
name|LIM_NORAISE
value|0
end_define

begin_comment
comment|/* if<> 0, can't raise limits */
end_comment

begin_define
define|#
directive|define
name|LIM_CPU
value|1
end_define

begin_comment
comment|/* max secs cpu time */
end_comment

begin_define
define|#
directive|define
name|LIM_FSIZE
value|2
end_define

begin_comment
comment|/* max size of file created */
end_comment

begin_define
define|#
directive|define
name|LIM_DATA
value|3
end_define

begin_comment
comment|/* max growth of data space */
end_comment

begin_define
define|#
directive|define
name|LIM_STACK
value|4
end_define

begin_comment
comment|/* max growth of stack */
end_comment

begin_define
define|#
directive|define
name|LIM_CORE
value|5
end_define

begin_comment
comment|/* max size of ``core'' file */
end_comment

begin_define
define|#
directive|define
name|LIM_MAXRSS
value|6
end_define

begin_comment
comment|/* max desired data+stack core usage */
end_comment

begin_define
define|#
directive|define
name|NLIMITS
value|6
end_define

begin_define
define|#
directive|define
name|INFINITY
value|0x7fffffff
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

