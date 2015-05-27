begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Daniel M. Eischen<deischen@freebsd.org>  * Copyright (c) 2014 The FreeBSD Foundation.  * All rights reserved.  *  * Portions of this software were developed by Konstantin Belousov  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucontext.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__sys_swapcontext
argument_list|,
name|__swapcontext
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|swapcontext
argument_list|,
name|__impl_swapcontext
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|swapcontext
argument_list|,
name|__impl_swapcontext
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_default
argument_list|(
name|swapcontext
argument_list|,
name|swapcontext
argument_list|,
name|FBSD_1
literal|.2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_pragma
pragma|#
directive|pragma
name|weak
name|swapcontext
end_pragma

begin_function
name|int
name|swapcontext
parameter_list|(
name|ucontext_t
modifier|*
name|oucp
parameter_list|,
specifier|const
name|ucontext_t
modifier|*
name|ucp
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|ucontext_t
operator|*
argument_list|,
specifier|const
name|ucontext_t
operator|*
argument_list|)
operator|)
name|__libc_interposing
index|[
name|INTERPOS_swapcontext
index|]
operator|)
operator|(
name|oucp
operator|,
name|ucp
operator|)
operator|)
return|;
block|}
end_function

end_unit

