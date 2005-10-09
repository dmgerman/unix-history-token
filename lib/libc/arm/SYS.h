begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: SYS.h,v 1.8 2003/08/07 16:42:02 agc Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)SYS.h	5.5 (Berkeley) 5/7/91  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<machine/asm.h>
end_include

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_include
include|#
directive|include
file|<machine/swi.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|SYSTRAP
parameter_list|(
name|x
parameter_list|)
value|swi 0 | SYS_ ## x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYSTRAP
parameter_list|(
name|x
parameter_list|)
value|swi 0 | SYS_
comment|/**/
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

begin_define
define|#
directive|define
name|CERROR
value|_C_LABEL(cerror)
end_define

begin_define
define|#
directive|define
name|CURBRK
value|_C_LABEL(curbrk)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CERROR
value|_ASM_LABEL(cerror)
end_define

begin_define
define|#
directive|define
name|CURBRK
value|_ASM_LABEL(curbrk)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_SYSCALL_NOERROR
parameter_list|(
name|x
parameter_list|)
define|\
value|ENTRY(__CONCAT(__sys_, x));					\ 	.weak _C_LABEL(x);						\ 	.set _C_LABEL(x), _C_LABEL(__CONCAT(__sys_,x));			\ 	.weak _C_LABEL(__CONCAT(_,x));					\ 	.set _C_LABEL(__CONCAT(_,x)),_C_LABEL(__CONCAT(__sys_,x));	\ 	SYSTRAP(x)
end_define

begin_define
define|#
directive|define
name|_SYSCALL
parameter_list|(
name|x
parameter_list|)
define|\
value|_SYSCALL_NOERROR(x);						\ 	bcs PIC_SYM(CERROR, PLT)
end_define

begin_define
define|#
directive|define
name|SYSCALL_NOERROR
parameter_list|(
name|x
parameter_list|)
define|\
value|_SYSCALL_NOERROR(x)
end_define

begin_define
define|#
directive|define
name|SYSCALL
parameter_list|(
name|x
parameter_list|)
define|\
value|_SYSCALL(x)
end_define

begin_define
define|#
directive|define
name|PSEUDO_NOERROR
parameter_list|(
name|x
parameter_list|)
define|\
value|_SYSCALL_NOERROR(x);						\ 	RET
end_define

begin_define
define|#
directive|define
name|PSEUDO
parameter_list|(
name|x
parameter_list|)
define|\
value|_SYSCALL(x);							\ 	RET
end_define

begin_define
define|#
directive|define
name|RSYSCALL_NOERROR
parameter_list|(
name|x
parameter_list|)
define|\
value|PSEUDO_NOERROR(x)
end_define

begin_define
define|#
directive|define
name|RSYSCALL
parameter_list|(
name|x
parameter_list|)
define|\
value|PSEUDO(x)
end_define

begin_expr_stmt
operator|.
name|globl
name|CERROR
end_expr_stmt

end_unit

