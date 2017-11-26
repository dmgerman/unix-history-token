begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2004 David Schultz<das@FreeBSD.ORG>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|__fenv_static
end_define

begin_include
include|#
directive|include
file|"fenv.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC_GNU_INLINE__
end_ifdef

begin_error
error|#
directive|error
literal|"This file must be compiled with C99 'inline' semantics"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The FSR_version field may be different on different  * implementations, but it is immutable and opaque to the  * application.  Thus, 0 is valid as the default environment.  */
end_comment

begin_decl_stmt
specifier|const
name|fenv_t
name|__fe_dfl_env
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
specifier|inline
name|int
name|feclearexcept
parameter_list|(
name|int
name|__excepts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|inline
name|int
name|fegetexceptflag
parameter_list|(
name|fexcept_t
modifier|*
name|__flagp
parameter_list|,
name|int
name|__excepts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|inline
name|int
name|fesetexceptflag
parameter_list|(
specifier|const
name|fexcept_t
modifier|*
name|__flagp
parameter_list|,
name|int
name|__excepts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|inline
name|int
name|feraiseexcept
parameter_list|(
name|int
name|__excepts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|inline
name|int
name|fetestexcept
parameter_list|(
name|int
name|__excepts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|inline
name|int
name|fegetround
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|inline
name|int
name|fesetround
parameter_list|(
name|int
name|__round
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|inline
name|int
name|fegetenv
parameter_list|(
name|fenv_t
modifier|*
name|__envp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|inline
name|int
name|feholdexcept
parameter_list|(
name|fenv_t
modifier|*
name|__envp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|inline
name|int
name|fesetenv
parameter_list|(
specifier|const
name|fenv_t
modifier|*
name|__envp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|inline
name|int
name|feupdateenv
parameter_list|(
specifier|const
name|fenv_t
modifier|*
name|__envp
parameter_list|)
function_decl|;
end_function_decl

end_unit

