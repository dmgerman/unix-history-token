begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 Alfred Perlstein<alfred@freebsd.org>.  * Copyright (c) 1995 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"thr_private.h"
end_include

begin_comment
comment|/*  * This module uses GCC extentions to initialize the  * threads package at program start-up time.  */
end_comment

begin_function_decl
name|void
name|_thread_init_hack
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(constructor
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|_thread_init_hack
parameter_list|(
name|void
parameter_list|)
block|{
name|_thread_init
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * For the shared version of the threads library, the above is sufficient.  * But for the archive version of the library, we need a little bit more.  * Namely, we must arrange for this particular module to be pulled in from  * the archive library at link time.  To accomplish that, we define and  * initialize a variable, "_thread_autoinit_dummy_decl".  This variable is  * referenced (as an extern) from libc/stdlib/exit.c. This will always  * create a need for this module, ensuring that it is present in the  * executable.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_thread_autoinit_dummy_decl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_autoinit_dummy_decl
init|=
literal|0
decl_stmt|;
end_decl_stmt

end_unit

