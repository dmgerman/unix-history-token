begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Matthew Dillon.  All Rights Reserved.  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * This file contains prototypes and high-level inlines related to  * machine-level critical function support:  *  *	cpu_critical_enter()		- inlined  *	cpu_critical_exit()		- inlined  *	cpu_critical_fork_exit()	- prototyped  *	related support functions residing  *	in<arch>/<arch>/critical.c	- prototyped  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CRITICAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CRITICAL_H_
end_define

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * Prototypes - see<arch>/<arch>/critical.c  */
name|void
name|cpu_critical_fork_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|/*  *	cpu_critical_enter:  *  *	This routine is called from critical_enter() on the 0->1 transition  *	of td_critnest, prior to it being incremented to 1.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|cpu_critical_enter
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
name|critical_t
name|pil
decl_stmt|;
name|td
operator|=
name|curthread
expr_stmt|;
name|pil
operator|=
name|rdpr
argument_list|(
name|pil
argument_list|)
expr_stmt|;
name|wrpr
argument_list|(
name|pil
argument_list|,
literal|0
argument_list|,
literal|14
argument_list|)
expr_stmt|;
name|td
operator|->
name|td_md
operator|.
name|md_savecrit
operator|=
name|pil
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *	cpu_critical_exit:  *  *	This routine is called from critical_exit() on a 1->0 transition  *	of td_critnest, after it has been decremented to 0.  We are  *	exiting the last critical section.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|cpu_critical_exit
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
name|td
operator|=
name|curthread
expr_stmt|;
name|wrpr
argument_list|(
name|pil
argument_list|,
name|td
operator|->
name|td_md
operator|.
name|md_savecrit
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__GNUC__ */
end_comment

begin_function_decl
name|void
name|cpu_critical_enter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_critical_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CRITICAL_H_ */
end_comment

end_unit

