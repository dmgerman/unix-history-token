begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1984 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)ptrace.h	7.4 (Berkeley) 2/22/91  *	$Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PTRACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_PTRACE_H_
end_define

begin_define
define|#
directive|define
name|PT_TRACE_ME
value|0
end_define

begin_comment
comment|/* child declares it's being traced */
end_comment

begin_define
define|#
directive|define
name|PT_READ_I
value|1
end_define

begin_comment
comment|/* read word in child's I space */
end_comment

begin_define
define|#
directive|define
name|PT_READ_D
value|2
end_define

begin_comment
comment|/* read word in child's D space */
end_comment

begin_define
define|#
directive|define
name|PT_READ_U
value|3
end_define

begin_comment
comment|/* read word in child's user structure */
end_comment

begin_define
define|#
directive|define
name|PT_WRITE_I
value|4
end_define

begin_comment
comment|/* write word in child's I space */
end_comment

begin_define
define|#
directive|define
name|PT_WRITE_D
value|5
end_define

begin_comment
comment|/* write word in child's D space */
end_comment

begin_define
define|#
directive|define
name|PT_WRITE_U
value|6
end_define

begin_comment
comment|/* write word in child's user structure */
end_comment

begin_define
define|#
directive|define
name|PT_CONTINUE
value|7
end_define

begin_comment
comment|/* continue the child */
end_comment

begin_define
define|#
directive|define
name|PT_KILL
value|8
end_define

begin_comment
comment|/* kill the child process */
end_comment

begin_define
define|#
directive|define
name|PT_STEP
value|9
end_define

begin_comment
comment|/* single step the child */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|ptrace
name|__P
argument_list|(
operator|(
name|int
name|_request
operator|,
name|pid_t
name|_pid
operator|,
name|caddr_t
name|_addr
operator|,
name|int
name|_data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PTRACE_H_ */
end_comment

end_unit

