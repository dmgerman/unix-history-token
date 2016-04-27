begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2007  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: string.h,v 1.23 2007/09/13 04:48:16 each Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_STRING_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_STRING_H
value|1
end_define

begin_comment
comment|/*! \file isc/string.h */
end_comment

begin_include
include|#
directive|include
file|<isc/formatcheck.h>
end_include

begin_include
include|#
directive|include
file|<isc/int.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_HAVESTRINGSH
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISC_STRING_MAGIC
value|0x5e
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_uint64_t
name|isc_string_touint64
parameter_list|(
name|char
modifier|*
name|source
parameter_list|,
name|char
modifier|*
modifier|*
name|endp
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert the string pointed to by 'source' to isc_uint64_t.  *  * On successful conversion 'endp' points to the first character  * after conversion is complete.  *  * 'base': 0 or 2..36  *  * If base is 0 the base is computed from the string type.  *  * On error 'endp' points to 'source'.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_string_copy
parameter_list|(
name|char
modifier|*
name|target
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Copy the string pointed to by 'source' to 'target' which is a  * pointer to a string of at least 'size' bytes.  *  * Requires:  *	'target' is a pointer to a char[] of at least 'size' bytes.  *	'size' an integer> 0.  *	'source' == NULL or points to a NUL terminated string.  *  * Ensures:  *	If result == ISC_R_SUCCESS  *		'target' will be a NUL terminated string of no more  *		than 'size' bytes (including NUL).  *  *	If result == ISC_R_NOSPACE  *		'target' is undefined.  *  * Returns:  *	ISC_R_SUCCESS  -- 'source' was successfully copied to 'target'.  *	ISC_R_NOSPACE  -- 'source' could not be copied since 'target'  *	                  is too small.  */
end_comment

begin_function_decl
name|void
name|isc_string_copy_truncate
parameter_list|(
name|char
modifier|*
name|target
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Copy the string pointed to by 'source' to 'target' which is a  * pointer to a string of at least 'size' bytes.  *  * Requires:  *	'target' is a pointer to a char[] of at least 'size' bytes.  *	'size' an integer> 0.  *	'source' == NULL or points to a NUL terminated string.  *  * Ensures:  *	'target' will be a NUL terminated string of no more  *	than 'size' bytes (including NUL).  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_string_append
parameter_list|(
name|char
modifier|*
name|target
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Append the string pointed to by 'source' to 'target' which is a  * pointer to a NUL terminated string of at least 'size' bytes.  *  * Requires:  *	'target' is a pointer to a NUL terminated char[] of at  *	least 'size' bytes.  *	'size' an integer> 0.  *	'source' == NULL or points to a NUL terminated string.  *  * Ensures:  *	If result == ISC_R_SUCCESS  *		'target' will be a NUL terminated string of no more  *		than 'size' bytes (including NUL).  *  *	If result == ISC_R_NOSPACE  *		'target' is undefined.  *  * Returns:  *	ISC_R_SUCCESS  -- 'source' was successfully appended to 'target'.  *	ISC_R_NOSPACE  -- 'source' could not be appended since 'target'  *	                  is too small.  */
end_comment

begin_function_decl
name|void
name|isc_string_append_truncate
parameter_list|(
name|char
modifier|*
name|target
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Append the string pointed to by 'source' to 'target' which is a  * pointer to a NUL terminated string of at least 'size' bytes.  *  * Requires:  *	'target' is a pointer to a NUL terminated char[] of at  *	least 'size' bytes.  *	'size' an integer> 0.  *	'source' == NULL or points to a NUL terminated string.  *  * Ensures:  *	'target' will be a NUL terminated string of no more  *	than 'size' bytes (including NUL).  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_string_printf
parameter_list|(
name|char
modifier|*
name|target
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Print 'format' to 'target' which is a pointer to a string of at least  * 'size' bytes.  *  * Requires:  *	'target' is a pointer to a char[] of at least 'size' bytes.  *	'size' an integer> 0.  *	'format' == NULL or points to a NUL terminated string.  *  * Ensures:  *	If result == ISC_R_SUCCESS  *		'target' will be a NUL terminated string of no more  *		than 'size' bytes (including NUL).  *  *	If result == ISC_R_NOSPACE  *		'target' is undefined.  *  * Returns:  *	ISC_R_SUCCESS  -- 'format' was successfully printed to 'target'.  *	ISC_R_NOSPACE  -- 'format' could not be printed to 'target' since it  *	                  is too small.  */
end_comment

begin_function_decl
name|void
name|isc_string_printf_truncate
parameter_list|(
name|char
modifier|*
name|target
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Print 'format' to 'target' which is a pointer to a string of at least  * 'size' bytes.  *  * Requires:  *	'target' is a pointer to a char[] of at least 'size' bytes.  *	'size' an integer> 0.  *	'format' == NULL or points to a NUL terminated string.  *  * Ensures:  *	'target' will be a NUL terminated string of no more  *	than 'size' bytes (including NUL).  */
end_comment

begin_function_decl
name|char
modifier|*
name|isc_string_regiondup
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
specifier|const
name|isc_region_t
modifier|*
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Copy the region pointed to by r to a NUL terminated string  * allocated from the memory context pointed to by mctx.  *  * The result should be deallocated using isc_mem_free()  *  * Requires:  *	'mctx' is a point to a valid memory context.  *	'source' is a pointer to a valid region.  *  * Returns:  *	a pointer to a NUL terminated string or  *	NULL if memory for the copy could not be allocated  *  */
end_comment

begin_function_decl
name|int
name|isc_tsmemcmp
parameter_list|(
specifier|const
name|void
modifier|*
name|p1
parameter_list|,
specifier|const
name|void
modifier|*
name|p2
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Lexicographic compare 'len' unsigned bytes from 'p1' and 'p2'  * like 'memcmp()'.  *  * This function is safe from timing attacks as it has a runtime that  * only depends on 'len' and has no early-out option.  *  * Use this to check MACs and other material that is security sensitive.  *  * Returns:  *  (let x be the byte offset of the first different byte)  *  -1 if (u_char)p1[x]< (u_char)p2[x]  *   1 if (u_char)p1[x]> (u_char)p2[x]  *   0 if byte series are equal  */
end_comment

begin_function_decl
name|char
modifier|*
name|isc_string_separate
parameter_list|(
name|char
modifier|*
modifier|*
name|stringp
parameter_list|,
specifier|const
name|char
modifier|*
name|delim
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDSTRSEP
end_ifdef

begin_define
define|#
directive|define
name|strsep
value|isc_string_separate
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDMEMMOVE
end_ifdef

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bcopy(b,a,c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|size_t
name|isc_string_strlcpy
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDSTRLCPY
end_ifdef

begin_define
define|#
directive|define
name|strlcpy
value|isc_string_strlcpy
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|size_t
name|isc_string_strlcat
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDSTRLCAT
end_ifdef

begin_define
define|#
directive|define
name|strlcat
value|isc_string_strlcat
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_STRING_H */
end_comment

end_unit

