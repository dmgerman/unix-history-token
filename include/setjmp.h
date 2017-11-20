begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)setjmp.h	8.2 (Berkeley) 1/21/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SETJMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_SETJMP_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* The size of the jmp_buf is machine dependent: */
end_comment

begin_include
include|#
directive|include
file|<machine/setjmp.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
if|#
directive|if
name|__XSI_VISIBLE
operator|>=
literal|600
name|void
name|_longjmp
argument_list|(
name|jmp_buf
argument_list|,
name|int
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_setjmp
argument_list|(
name|jmp_buf
argument_list|)
name|__returns_twice
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|longjmp
argument_list|(
name|jmp_buf
argument_list|,
name|int
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|void
name|longjmperror
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|setjmp
argument_list|(
name|jmp_buf
argument_list|)
name|__returns_twice
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

begin_decl_stmt
name|void
name|siglongjmp
argument_list|(
name|sigjmp_buf
argument_list|,
name|int
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigsetjmp
argument_list|(
name|sigjmp_buf
argument_list|,
name|int
argument_list|)
name|__returns_twice
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SETJMP_H_ */
end_comment

end_unit

