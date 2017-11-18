begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: SYS.h,v 1.19 2009/12/14 01:07:41 matt Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-4-Clause  *  * Copyright (c) 1996 Jonathan Stone  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jonathan Stone for  *      the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)SYS.h	8.1 (Berkeley) 6/4/93  */
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

begin_comment
comment|/*  * If compiling for shared libs, Emit sysV ABI PIC segment pseudo-ops.  *  * i)  Emit .abicalls before .LEAF entrypoint, and .cpload/.cprestore after.  * ii) Do interprocedure jumps indirectly via t9, with the side-effect of  *     preserving the callee's entry address in t9.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ABICALLS__
end_ifdef

begin_expr_stmt
operator|.
name|abicalls
end_expr_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_o32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_o64
argument_list|)
end_if

begin_define
define|#
directive|define
name|PIC_PROLOGUE
parameter_list|(
name|x
parameter_list|)
value|SETUP_GP
end_define

begin_define
define|#
directive|define
name|PIC_TAILCALL
parameter_list|(
name|l
parameter_list|)
value|PTR_LA t9, _C_LABEL(l); jr t9
end_define

begin_define
define|#
directive|define
name|PIC_RETURN
parameter_list|()
value|j ra
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PIC_PROLOGUE
parameter_list|(
name|x
parameter_list|)
value|SETUP_GP64(t3, x)
end_define

begin_define
define|#
directive|define
name|PIC_TAILCALL
parameter_list|(
name|l
parameter_list|)
value|PTR_LA t9, _C_LABEL(l); RESTORE_GP64; jr t9
end_define

begin_define
define|#
directive|define
name|PIC_RETURN
parameter_list|()
value|RESTORE_GP64; j ra
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PIC_PROLOGUE
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PIC_TAILCALL
parameter_list|(
name|l
parameter_list|)
value|j  _C_LABEL(l)
end_define

begin_define
define|#
directive|define
name|PIC_RETURN
parameter_list|()
value|j ra
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ABICALLS__ */
end_comment

begin_define
define|#
directive|define
name|SYSTRAP
parameter_list|(
name|x
parameter_list|)
value|li v0,SYS_ ## x; syscall;
end_define

begin_comment
comment|/*  * Do a syscall that cannot fail (sync, get{p,u,g,eu,eg)id)  */
end_comment

begin_define
define|#
directive|define
name|RSYSCALL_NOERROR
parameter_list|(
name|x
parameter_list|)
define|\
value|LEAF(__sys_ ## x);							\ 	.weak _C_LABEL(x);						\ 	_C_LABEL(x) = _C_LABEL(__CONCAT(__sys_,x));			\ 	.weak _C_LABEL(__CONCAT(_,x));					\ 	_C_LABEL(__CONCAT(_,x)) = _C_LABEL(__CONCAT(__sys_,x));		\ 	SYSTRAP(x);							\ 	j ra;								\ END(__sys_ ## x)
end_define

begin_comment
comment|/*  * Do a normal syscall.  */
end_comment

begin_define
define|#
directive|define
name|RSYSCALL
parameter_list|(
name|x
parameter_list|)
define|\
value|LEAF(__sys_ ## x);							\ 	.weak _C_LABEL(x);						\ 	_C_LABEL(x) = _C_LABEL(__CONCAT(__sys_,x));			\ 	.weak _C_LABEL(__CONCAT(_,x));					\ 	_C_LABEL(__CONCAT(_,x)) = _C_LABEL(__CONCAT(__sys_,x));		\ 	PIC_PROLOGUE(__sys_ ## x);					\ 	SYSTRAP(x);							\ 	bne a3,zero,err;						\ 	PIC_RETURN();							\ err:									\ 	PIC_TAILCALL(__cerror);						\ END(__sys_ ## x)
end_define

begin_comment
comment|/*  * Do a renamed or pseudo syscall (e.g., _exit()), where the entrypoint  * and syscall name are not the same.  */
end_comment

begin_define
define|#
directive|define
name|PSEUDO_NOERROR
parameter_list|(
name|x
parameter_list|)
define|\
value|LEAF(__sys_ ## x);							\ 	.weak _C_LABEL(__CONCAT(_,x));					\ 	_C_LABEL(__CONCAT(_,x)) = _C_LABEL(__CONCAT(__sys_,x));		\ 	SYSTRAP(x);							\ 	j ra;								\ END(__sys_ ## x)
end_define

begin_define
define|#
directive|define
name|PSEUDO
parameter_list|(
name|x
parameter_list|)
define|\
value|LEAF(__sys_ ## x);							\ 	.weak _C_LABEL(__CONCAT(_,x));					\ 	_C_LABEL(__CONCAT(_,x)) = _C_LABEL(__CONCAT(__sys_,x));		\ 	PIC_PROLOGUE(__sys_ ## x);					\ 	SYSTRAP(x);							\ 	bne a3,zero,err;						\ 	PIC_RETURN();							\ err:									\ 	PIC_TAILCALL(__cerror);						\ END(__sys_ ## x)
end_define

end_unit

