begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Matthew Dillon.  All Rights Reserved.  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * This file contains prototypes and high-level inlines related to  * machine-level critical function support:  *  *	cpu_critical_enter()		- inlined  *	cpu_critical_exit()		- inlined  *	cpu_critical_fork_exit()	- prototyped  *	related support functions residing  *	in<arch>/<arch>/critical.c	- prototyped  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE_CRITICAL_H
end_ifndef

begin_define
define|#
directive|define
name|MACHINE_CRITICAL_H
end_define

begin_function_decl
name|void
name|cpu_critical_fork_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|cpu_critical_enter
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
name|cd
operator|->
name|td_md
operator|.
name|md_savecrit
operator|=
name|disable_interrupts
argument_list|(
name|I32_bit
operator||
name|F32_bit
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|cpu_critical_exit
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
name|restore_interrupts
argument_list|(
name|td
operator|->
name|td_md
operator|.
name|md_savecrit
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

