begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Andrew Turner  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Andrew Turner under  * sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|_SYSCALL
parameter_list|(
name|name
parameter_list|)
define|\
value|mov	x8, SYS_ ## name;				\ 	svc	0
end_define

begin_define
define|#
directive|define
name|SYSCALL
parameter_list|(
name|name
parameter_list|)
define|\
value|ENTRY(__sys_##name);						\ 	WEAK_REFERENCE(__sys_##name, name);			\ 	WEAK_REFERENCE(__sys_##name, _##name);			\ 	_SYSCALL(name);						\ 	ret;							\ END(__sys_##name)
end_define

begin_comment
comment|/*  * Conditional jumps can only go up to one megabyte in either  * direction, and cerror can be located anywhere, so we have  * to jump around to use more capable unconditional branch  * instruction.  */
end_comment

begin_define
define|#
directive|define
name|PSEUDO
parameter_list|(
name|name
parameter_list|)
define|\
value|ENTRY(__sys_##name);						\ 	WEAK_REFERENCE(__sys_##name, _##name);			\ 	_SYSCALL(name);						\ 	b.cs	1f;						\ 	ret;							\ 1:	b	cerror;						\ END(__sys_##name)
end_define

begin_define
define|#
directive|define
name|RSYSCALL
parameter_list|(
name|name
parameter_list|)
define|\
value|ENTRY(__sys_##name);						\ 	WEAK_REFERENCE(__sys_##name, name);			\ 	WEAK_REFERENCE(__sys_##name, _##name);			\ 	_SYSCALL(name);						\ 	b.cs	1f;						\ 	ret;							\ 1:	b	cerror;						\ END(__sys_##name)
end_define

end_unit

