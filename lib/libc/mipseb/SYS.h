begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      $OpenBSD: SYS.h,v 1.3 1996/07/30 20:27:48 pefo Exp $   */
end_comment

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_include
include|#
directive|include
file|<machine/asm.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|RSYSCALL
parameter_list|(
name|x
parameter_list|)
define|\
value|LEAF(x);		\ 			li	v0,SYS_ ## x;	\ 			syscall;		\ 			bne	a3,zero,err;	\ 			j	ra;		\ 			err: la t9, cerror;	\ 			jr t9;			\ 			END(x);
end_define

begin_define
define|#
directive|define
name|PSEUDO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|LEAF(x);		\ 			li	v0,SYS_ ## y;	\ 			syscall;		\ 			bne	a3,zero,err;	\ 			j	ra;		\ 			err: la t9, cerror;	\ 			jr t9;			\ 			END(x);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RSYSCALL
parameter_list|(
name|x
parameter_list|)
define|\
value|LEAF(x);		\ 			li	v0,SYS_
comment|/**/
value|x;	\ 			syscall;		\ 			bne	a3,zero,err;	\ 			j	ra;		\ 			err: la t9, cerror;	\ 			jr	t9;		\ 			END(x);
end_define

begin_define
define|#
directive|define
name|PSEUDO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|LEAF(x);		\ 			li	v0,SYS_
comment|/**/
value|y;	\ 			syscall;		\ 			bne	a3,zero,err;	\ 			j	ra;		\ 			err: la t9, cerror;	\ 			jr t9;			\ 			END(x);
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

