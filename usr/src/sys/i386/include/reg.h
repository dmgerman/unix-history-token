begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)reg.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_comment
comment|/*  * Location of the users' stored  * registers within appropriate frame of 'trap' and 'syscall', relative to  * base of stack frame.  * Normal usage is u.u_ar0[XX] in kernel.  */
end_comment

begin_comment
comment|/* When referenced during a trap/exception, registers are at these offsets */
end_comment

begin_define
define|#
directive|define
name|tES
value|(0)
end_define

begin_define
define|#
directive|define
name|tDS
value|(1)
end_define

begin_define
define|#
directive|define
name|tEDI
value|(2)
end_define

begin_define
define|#
directive|define
name|tESI
value|(3)
end_define

begin_define
define|#
directive|define
name|tEBP
value|(4)
end_define

begin_define
define|#
directive|define
name|tEBX
value|(6)
end_define

begin_define
define|#
directive|define
name|tEDX
value|(7)
end_define

begin_define
define|#
directive|define
name|tECX
value|(8)
end_define

begin_define
define|#
directive|define
name|tEAX
value|(9)
end_define

begin_define
define|#
directive|define
name|tEIP
value|(12)
end_define

begin_define
define|#
directive|define
name|tCS
value|(13)
end_define

begin_define
define|#
directive|define
name|tEFLAGS
value|(14)
end_define

begin_define
define|#
directive|define
name|tESP
value|(15)
end_define

begin_define
define|#
directive|define
name|tSS
value|(16)
end_define

begin_comment
comment|/* During a system call, registers are at these offsets instead of above. */
end_comment

begin_define
define|#
directive|define
name|sEDI
value|(0)
end_define

begin_define
define|#
directive|define
name|sESI
value|(1)
end_define

begin_define
define|#
directive|define
name|sEBP
value|(2)
end_define

begin_define
define|#
directive|define
name|sEBX
value|(4)
end_define

begin_define
define|#
directive|define
name|sEDX
value|(5)
end_define

begin_define
define|#
directive|define
name|sECX
value|(6)
end_define

begin_define
define|#
directive|define
name|sEAX
value|(7)
end_define

begin_define
define|#
directive|define
name|sEFLAGS
value|(8)
end_define

begin_define
define|#
directive|define
name|sEIP
value|(9)
end_define

begin_define
define|#
directive|define
name|sCS
value|(10)
end_define

begin_define
define|#
directive|define
name|sESP
value|(11)
end_define

begin_define
define|#
directive|define
name|sSS
value|(12)
end_define

begin_define
define|#
directive|define
name|PC
value|sEIP
end_define

begin_define
define|#
directive|define
name|SP
value|sESP
end_define

begin_define
define|#
directive|define
name|PS
value|sEFLAGS
end_define

begin_define
define|#
directive|define
name|R0
value|sEDX
end_define

begin_define
define|#
directive|define
name|R1
value|sECX
end_define

begin_comment
comment|/*  * Registers accessible to ptrace(2) syscall for debugger  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IPCREG
end_ifdef

begin_define
define|#
directive|define
name|NIPCREG
value|14
end_define

begin_decl_stmt
name|int
name|ipcreg
index|[
name|NIPCREG
index|]
init|=
block|{
name|tES
block|,
name|tDS
block|,
name|tEDI
block|,
name|tESI
block|,
name|tEBP
block|,
name|tEBX
block|,
name|tEDX
block|,
name|tECX
block|,
name|tEAX
block|,
name|tEIP
block|,
name|tCS
block|,
name|tEFLAGS
block|,
name|tESP
block|,
name|tSS
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

