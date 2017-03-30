begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)stddef.h	8.1 (Berkeley) 6/2/93  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STDDEF_H_
end_ifndef

begin_define
define|#
directive|define
name|_STDDEF_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_null.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_PTRDIFF_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__ptrdiff_t
name|ptrdiff_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_PTRDIFF_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_RUNE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__rune_t
name|rune_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_RUNE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_WCHAR_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|___wchar_t
name|wchar_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_WCHAR_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|201112L
operator|||
name|__cplusplus
operator|>=
literal|201103L
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__CLANG_MAX_ALIGN_T_DEFINED
end_ifndef

begin_typedef
typedef|typedef
name|__max_align_t
name|max_align_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__CLANG_MAX_ALIGN_T_DEFINED
end_define

begin_define
define|#
directive|define
name|_GCC_MAX_ALIGN_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|member
parameter_list|)
value|__offsetof(type, member)
end_define

begin_if
if|#
directive|if
name|__EXT1_VISIBLE
end_if

begin_comment
comment|/* ISO/IEC 9899:2011 K.3.3.2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RSIZE_T_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_RSIZE_T_DEFINED
end_define

begin_typedef
typedef|typedef
name|size_t
name|rsize_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __EXT1_VISIBLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDDEF_H_ */
end_comment

end_unit

