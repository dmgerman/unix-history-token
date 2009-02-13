begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2006, Maxime Henrion<mux@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MISC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MISC_H_
end_define

begin_include
include|#
directive|include
file|<openssl/md5.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* If we're not compiling in a C99 environment, define the C99 types. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC_VERSION__
argument_list|)
operator|||
name|__STDC_VERSION__
operator|<
literal|199901
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|uint32_t
end_ifdef

begin_undef
undef|#
directive|undef
name|uint32_t
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|uint32_t
value|u_int32_t
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|uint16_t
end_ifdef

begin_undef
undef|#
directive|undef
name|uint16_t
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|uint16_t
value|u_int16_t
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|uint8_t
end_ifdef

begin_undef
undef|#
directive|undef
name|uint8_t
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|uint8_t
value|u_int8_t
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is a GCC-specific keyword but some other compilers (namely icc)    understand it, and the code won't work if we can't disable padding    anyways. */
end_comment

begin_undef
undef|#
directive|undef
name|__packed
end_undef

begin_define
define|#
directive|define
name|__packed
value|__attribute__((__packed__))
end_define

begin_comment
comment|/* We explicitely don't define this with icc because it defines __GNUC__    but doesn't support it. */
end_comment

begin_undef
undef|#
directive|undef
name|__printflike
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
operator|&&
expr|\
operator|(
name|__GNUC__
operator|>
literal|2
operator|||
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC__MINOR__
operator|>=
literal|7
operator|)
end_if

begin_define
define|#
directive|define
name|__printflike
parameter_list|(
name|fmtarg
parameter_list|,
name|firstvararg
parameter_list|)
define|\
value|__attribute__((__format__ (__printf__, fmtarg, firstvararg)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__printflike
parameter_list|(
name|fmtarg
parameter_list|,
name|firstvararg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Exit codes. */
end_comment

begin_define
define|#
directive|define
name|STATUS_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|STATUS_FAILURE
value|1
end_define

begin_define
define|#
directive|define
name|STATUS_TRANSIENTFAILURE
value|2
end_define

begin_define
define|#
directive|define
name|STATUS_INTERRUPTED
value|3
end_define

begin_struct_decl
struct_decl|struct
name|config
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|stream
struct_decl|;
end_struct_decl

begin_comment
comment|/* Thread parameters. */
end_comment

begin_struct
struct|struct
name|thread_args
block|{
name|struct
name|config
modifier|*
name|config
decl_stmt|;
name|struct
name|stream
modifier|*
name|rd
decl_stmt|;
name|struct
name|stream
modifier|*
name|wr
decl_stmt|;
name|int
name|status
decl_stmt|;
name|char
modifier|*
name|errmsg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Minimum size for MD5_File() and MD5_End() buffers. */
end_comment

begin_define
define|#
directive|define
name|MD5_DIGEST_SIZE
value|33
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (b) : (a))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (b) : (a))
end_define

begin_struct_decl
struct_decl|struct
name|backoff_timer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pattlist
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tm
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|asciitoint
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lprintf
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|MD5_File
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD5_End
parameter_list|(
name|char
modifier|*
parameter_list|,
name|MD5_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rcsdatetotm
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|tm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|rcsdatetotime
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pathcmp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|commonpathlength
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pathlast
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|checkoutpath
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mkdirhier
parameter_list|(
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tempname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|xmalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|xrealloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xstrdup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xasprintf
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|struct
name|pattlist
modifier|*
name|pattlist_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pattlist_add
parameter_list|(
name|struct
name|pattlist
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pattlist_get
parameter_list|(
name|struct
name|pattlist
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|pattlist_size
parameter_list|(
name|struct
name|pattlist
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pattlist_free
parameter_list|(
name|struct
name|pattlist
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|backoff_timer
modifier|*
name|bt_new
parameter_list|(
name|time_t
parameter_list|,
name|time_t
parameter_list|,
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|bt_get
parameter_list|(
name|struct
name|backoff_timer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bt_pause
parameter_list|(
name|struct
name|backoff_timer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bt_free
parameter_list|(
name|struct
name|backoff_timer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MISC_H_ */
end_comment

end_unit

