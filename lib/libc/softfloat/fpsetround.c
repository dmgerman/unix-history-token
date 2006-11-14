begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: fpsetround.c,v 1.2 2002/01/13 21:45:53 thorpej Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Neil A. Carson and Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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
argument|fpsetround
argument_list|,
argument|_fpsetround
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|fp_rnd_t
name|fpsetround
parameter_list|(
name|fp_rnd_t
name|rnd_dir
parameter_list|)
block|{
name|fp_rnd_t
name|old
decl_stmt|;
name|old
operator|=
name|float_rounding_mode
expr_stmt|;
name|float_rounding_mode
operator|=
name|rnd_dir
expr_stmt|;
return|return
name|old
return|;
block|}
end_function

end_unit

