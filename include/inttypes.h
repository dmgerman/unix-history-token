begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Mike Barcroft<mike@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INTTYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_INTTYPES_H_
end_define

begin_include
include|#
directive|include
file|<machine/_inttypes.h>
end_include

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_WCHAR_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_WCHAR_T_
name|wchar_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_WCHAR_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|intmax_t
name|quot
decl_stmt|;
comment|/* Quotient. */
name|intmax_t
name|rem
decl_stmt|;
comment|/* Remainder. */
block|}
name|imaxdiv_t
typedef|;
end_typedef

begin_function_decl
name|intmax_t
name|imaxabs
parameter_list|(
name|intmax_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|imaxdiv_t
name|imaxdiv
parameter_list|(
name|intmax_t
parameter_list|,
name|intmax_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX: The following functions are missing the restrict type qualifier. */
end_comment

begin_function_decl
name|intmax_t
name|strtoimax
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uintmax_t
name|strtoumax
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intmax_t
name|wcstoimax
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|wchar_t
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uintmax_t
name|wcstoumax
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|wchar_t
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_INTTYPES_H_ */
end_comment

end_unit

