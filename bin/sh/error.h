begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)error.h	8.2 (Berkeley) 5/4/95  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Types of operations (passed to the errmsg routine).  */
end_comment

begin_define
define|#
directive|define
name|E_OPEN
value|01
end_define

begin_comment
comment|/* opening a file */
end_comment

begin_define
define|#
directive|define
name|E_CREAT
value|02
end_define

begin_comment
comment|/* creating a file */
end_comment

begin_define
define|#
directive|define
name|E_EXEC
value|04
end_define

begin_comment
comment|/* executing a program */
end_comment

begin_comment
comment|/*  * We enclose jmp_buf in a structure so that we can declare pointers to  * jump locations.  The global variable handler contains the location to  * jump to when an exception occurs, and the global variable exception  * contains a code identifying the exception.  To implement nested  * exception handlers, the user should save the value of handler on entry  * to an inner scope, set handler to point to a jmploc structure for the  * inner scope, and restore handler on exit from the scope.  */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_struct
struct|struct
name|jmploc
block|{
name|jmp_buf
name|loc
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|jmploc
modifier|*
name|handler
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|sig_atomic_t
name|exception
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exceptions */
end_comment

begin_define
define|#
directive|define
name|EXINT
value|0
end_define

begin_comment
comment|/* SIGINT received */
end_comment

begin_define
define|#
directive|define
name|EXERROR
value|1
end_define

begin_comment
comment|/* a generic error */
end_comment

begin_define
define|#
directive|define
name|EXSHELLPROC
value|2
end_define

begin_comment
comment|/* execute a shell procedure */
end_comment

begin_define
define|#
directive|define
name|EXEXEC
value|3
end_define

begin_comment
comment|/* command execution failed */
end_comment

begin_comment
comment|/*  * These macros allow the user to suspend the handling of interrupt signals  * over a period of time.  This is similar to SIGHOLD to or sigblock, but  * much more efficient and portable.  (But hacking the kernel is so much  * more fun than worrying about efficiency and portability. :-))  */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|sig_atomic_t
name|suppressint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|sig_atomic_t
name|intpending
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INTOFF
value|suppressint++
end_define

begin_define
define|#
directive|define
name|INTON
value|{ if (--suppressint == 0&& intpending) onint(); }
end_define

begin_define
define|#
directive|define
name|FORCEINTON
value|{suppressint = 0; if (intpending) onint();}
end_define

begin_define
define|#
directive|define
name|CLEAR_PENDING_INT
value|intpending = 0
end_define

begin_define
define|#
directive|define
name|int_pending
parameter_list|()
value|intpending
end_define

begin_decl_stmt
name|void
name|exraise
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|onint
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|error
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|__printf0like
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|exerror
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|__printf0like
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|errmsg
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * BSD setjmp saves the signal mask, which violates ANSI C and takes time,  * so we use _setjmp instead.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_define
define|#
directive|define
name|setjmp
parameter_list|(
name|jmploc
parameter_list|)
value|_setjmp(jmploc)
end_define

begin_define
define|#
directive|define
name|longjmp
parameter_list|(
name|jmploc
parameter_list|,
name|val
parameter_list|)
value|_longjmp(jmploc, val)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

