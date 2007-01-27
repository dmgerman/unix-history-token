begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_STRING_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_STRING_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Basic resizable/reusable string support a la Java's "StringBuffer."  *  * Unlike sbuf(9), the buffers here are fully reusable and track the  * length throughout.  *  * Note that all visible symbols here begin with "__archive" as they  * are internal symbols not intended for anyone outside of this library  * to see or use.  */
end_comment

begin_struct
struct|struct
name|archive_string
block|{
name|char
modifier|*
name|s
decl_stmt|;
comment|/* Pointer to the storage */
name|size_t
name|length
decl_stmt|;
comment|/* Length of 's' */
name|size_t
name|buffer_length
decl_stmt|;
comment|/* Length of malloc-ed storage */
block|}
struct|;
end_struct

begin_comment
comment|/* Initialize an archive_string object on the stack or elsewhere. */
end_comment

begin_define
define|#
directive|define
name|archive_string_init
parameter_list|(
name|a
parameter_list|)
define|\
value|do { (a)->s = NULL; (a)->length = 0; (a)->buffer_length = 0; } while(0)
end_define

begin_comment
comment|/* Append a C char to an archive_string, resizing as necessary. */
end_comment

begin_function_decl
name|struct
name|archive_string
modifier|*
name|__archive_strappend_char
parameter_list|(
name|struct
name|archive_string
modifier|*
parameter_list|,
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|archive_strappend_char
value|__archive_strappend_char
end_define

begin_comment
comment|/* Append a char to an archive_string using UTF8. */
end_comment

begin_function_decl
name|struct
name|archive_string
modifier|*
name|__archive_strappend_char_UTF8
parameter_list|(
name|struct
name|archive_string
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|archive_strappend_char_UTF8
value|__archive_strappend_char_UTF8
end_define

begin_comment
comment|/* Append an integer in the specified base (2<= base<= 16). */
end_comment

begin_function_decl
name|struct
name|archive_string
modifier|*
name|__archive_strappend_int
parameter_list|(
name|struct
name|archive_string
modifier|*
name|as
parameter_list|,
name|int
name|d
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|archive_strappend_int
value|__archive_strappend_int
end_define

begin_comment
comment|/* Basic append operation. */
end_comment

begin_function_decl
name|struct
name|archive_string
modifier|*
name|__archive_string_append
parameter_list|(
name|struct
name|archive_string
modifier|*
name|as
parameter_list|,
specifier|const
name|char
modifier|*
name|p
parameter_list|,
name|size_t
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Ensure that the underlying buffer is at least as large as the request. */
end_comment

begin_function_decl
name|struct
name|archive_string
modifier|*
name|__archive_string_ensure
parameter_list|(
name|struct
name|archive_string
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|archive_string_ensure
value|__archive_string_ensure
end_define

begin_comment
comment|/* Append C string, which may lack trailing \0. */
end_comment

begin_function_decl
name|struct
name|archive_string
modifier|*
name|__archive_strncat
parameter_list|(
name|struct
name|archive_string
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|archive_strncat
value|__archive_strncat
end_define

begin_comment
comment|/* Append a C string to an archive_string, resizing as necessary. */
end_comment

begin_define
define|#
directive|define
name|archive_strcat
parameter_list|(
name|as
parameter_list|,
name|p
parameter_list|)
value|__archive_string_append((as),(p),strlen(p))
end_define

begin_comment
comment|/* Copy a C string to an archive_string, resizing as necessary. */
end_comment

begin_define
define|#
directive|define
name|archive_strcpy
parameter_list|(
name|as
parameter_list|,
name|p
parameter_list|)
define|\
value|((as)->length = 0, __archive_string_append((as), (p), strlen(p)))
end_define

begin_comment
comment|/* Copy a C string to an archive_string with limit, resizing as necessary. */
end_comment

begin_define
define|#
directive|define
name|archive_strncpy
parameter_list|(
name|as
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
define|\
value|((as)->length=0, archive_strncat((as), (p), (l)))
end_define

begin_comment
comment|/* Return length of string. */
end_comment

begin_define
define|#
directive|define
name|archive_strlen
parameter_list|(
name|a
parameter_list|)
value|((a)->length)
end_define

begin_comment
comment|/* Set string length to zero. */
end_comment

begin_define
define|#
directive|define
name|archive_string_empty
parameter_list|(
name|a
parameter_list|)
value|((a)->length = 0)
end_define

begin_comment
comment|/* Release any allocated storage resources. */
end_comment

begin_function_decl
name|void
name|__archive_string_free
parameter_list|(
name|struct
name|archive_string
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|archive_string_free
value|__archive_string_free
end_define

begin_comment
comment|/* Like 'vsprintf', but resizes the underlying string as necessary. */
end_comment

begin_function_decl
name|void
name|__archive_string_vsprintf
parameter_list|(
name|struct
name|archive_string
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|archive_string_vsprintf
value|__archive_string_vsprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

