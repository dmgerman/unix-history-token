begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: fpgetmask.c,v 1.4 2008/04/28 20:23:00 martin Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Neil A. Carson and Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|<ieeefp.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SOFTFLOAT_FOR_GCC
end_ifdef

begin_include
include|#
directive|include
file|"softfloat-for-gcc.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"milieu.h"
end_include

begin_include
include|#
directive|include
file|"softfloat.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__weak_alias
end_ifdef

begin_macro
name|__weak_alias
argument_list|(
argument|fpgetmask
argument_list|,
argument|_fpgetmask
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|fp_except
name|fpgetmask
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|float_exception_mask
return|;
block|}
end_function

end_unit

