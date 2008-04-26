begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: makecontext.c,v 1.3 2003/01/19 08:53:36 matt Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Klaus Klein.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: makecontext.c,v 1.3 2003/01/19 08:53:36 matt Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<ucontext.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_function
name|void
name|makecontext
parameter_list|(
name|ucontext_t
modifier|*
name|ucp
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|,
name|int
name|argc
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|/* XXXMIPS: Implement me */
if|#
directive|if
literal|0
block|__greg_t *gr = ucp->uc_mcontext.__gregs; 	uintptr_t *sp; 	int i; 	va_list ap;  	void __resumecontext(void);
comment|/* LINTED uintptr_t is safe */
block|sp  = (uintptr_t *) 	    ((uintptr_t)ucp->uc_stack.ss_sp + ucp->uc_stack.ss_size);
comment|/* LINTED uintptr_t is safe */
block|sp -= (argc>= 4 ? argc : 4);
comment|/* Make room for>=4 arguments. */
block|sp  = (uintptr_t *) 	      ((uintptr_t)sp& ~0x7);
comment|/* Align on double-word boundary. */
block|gr[_REG_SP]  = (__greg_t)sp; 	gr[_REG_RA]  = (__greg_t)__resumecontext; 	gr[_REG_T9]  = (__greg_t)func;
comment|/* required for .abicalls */
block|gr[_REG_EPC] = (__greg_t)func;
comment|/* Construct argument list. */
block|va_start(ap, argc);
comment|/* Up to the first four arguments are passed in $a0-3. */
block|for (i = 0; i< argc&& i< 4; i++)
comment|/* LINTED uintptr_t is safe */
block|gr[_REG_A0 + i] = va_arg(ap, uintptr_t);
comment|/* Pass remaining arguments on the stack above the $a0-3 gap. */
block|for (sp += 4; i< argc; i++)
comment|/* LINTED uintptr_t is safe */
block|*sp++ = va_arg(ap, uintptr_t); 	va_end(ap);
endif|#
directive|endif
block|}
end_function

end_unit

