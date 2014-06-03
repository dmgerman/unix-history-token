begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Andrew Turner<andrew@FreeBSD.ORG>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_FENV_MANGLE_H_
end_ifdef

begin_error
error|#
directive|error
error|Only include fenv-mangle.h once
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_FENV_MANGLE_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FENV_MANGLE
end_ifndef

begin_error
error|#
directive|error
error|FENV_MANGLE is undefined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|feclearexcept
value|FENV_MANGLE(feclearexcept)
end_define

begin_define
define|#
directive|define
name|fegetexceptflag
value|FENV_MANGLE(fegetexceptflag)
end_define

begin_define
define|#
directive|define
name|fesetexceptflag
value|FENV_MANGLE(fesetexceptflag)
end_define

begin_define
define|#
directive|define
name|feraiseexcept
value|FENV_MANGLE(feraiseexcept)
end_define

begin_define
define|#
directive|define
name|fetestexcept
value|FENV_MANGLE(fetestexcept)
end_define

begin_define
define|#
directive|define
name|fegetround
value|FENV_MANGLE(fegetround)
end_define

begin_define
define|#
directive|define
name|fesetround
value|FENV_MANGLE(fesetround)
end_define

begin_define
define|#
directive|define
name|fegetenv
value|FENV_MANGLE(fegetenv)
end_define

begin_define
define|#
directive|define
name|feholdexcept
value|FENV_MANGLE(feholdexcept)
end_define

begin_define
define|#
directive|define
name|fesetenv
value|FENV_MANGLE(fesetenv)
end_define

begin_define
define|#
directive|define
name|feupdateenv
value|FENV_MANGLE(feupdateenv)
end_define

begin_define
define|#
directive|define
name|feenableexcept
value|FENV_MANGLE(feenableexcept)
end_define

begin_define
define|#
directive|define
name|fedisableexcept
value|FENV_MANGLE(fedisableexcept)
end_define

begin_define
define|#
directive|define
name|fegetexcept
value|FENV_MANGLE(fegetexcept)
end_define

end_unit

