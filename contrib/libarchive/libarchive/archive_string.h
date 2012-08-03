begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2010 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBARCHIVE_BUILD
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBARCHIVE_TEST
end_ifndef

begin_error
error|#
directive|error
error|This header is only to be used internally to libarchive.
end_error

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
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* required for wchar_t on some systems */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_WCHAR_H
end_ifdef

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"archive.h"
end_include

begin_comment
comment|/*  * Basic resizable/reusable string support similar to Java's "StringBuffer."  *  * Unlike sbuf(9), the buffers here are fully reusable and track the  * length throughout.  */
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
comment|/* Length of 's' in characters */
name|size_t
name|buffer_length
decl_stmt|;
comment|/* Length of malloc-ed storage in bytes. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|archive_wstring
block|{
name|wchar_t
modifier|*
name|s
decl_stmt|;
comment|/* Pointer to the storage */
name|size_t
name|length
decl_stmt|;
comment|/* Length of 's' in characters */
name|size_t
name|buffer_length
decl_stmt|;
comment|/* Length of malloc-ed storage in bytes. */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|archive_string_conv
struct_decl|;
end_struct_decl

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
name|archive_strappend_char
parameter_list|(
name|struct
name|archive_string
modifier|*
parameter_list|,
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Ditto for a wchar_t and an archive_wstring. */
end_comment

begin_function_decl
name|struct
name|archive_wstring
modifier|*
name|archive_wstrappend_wchar
parameter_list|(
name|struct
name|archive_wstring
modifier|*
parameter_list|,
name|wchar_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert a Unicode string to current locale and append the result. */
end_comment

begin_comment
comment|/* Returns -1 if conversion fails. */
end_comment

begin_function_decl
name|int
name|archive_string_append_from_wcs
parameter_list|(
name|struct
name|archive_string
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a string conversion object.  * Return NULL and set a error message if the conversion is not supported  * on the platform. */
end_comment

begin_function_decl
name|struct
name|archive_string_conv
modifier|*
name|archive_string_conversion_to_charset
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|archive_string_conv
modifier|*
name|archive_string_conversion_from_charset
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create the default string conversion object for reading/writing an archive.  * Return NULL if the conversion is unneeded.  * Note: On non Windows platform this always returns NULL.  */
end_comment

begin_function_decl
name|struct
name|archive_string_conv
modifier|*
name|archive_string_default_conversion_for_read
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|archive_string_conv
modifier|*
name|archive_string_default_conversion_for_write
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Dispose of a string conversion object. */
end_comment

begin_function_decl
name|void
name|archive_string_conversion_free
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|archive_string_conversion_charset_name
parameter_list|(
name|struct
name|archive_string_conv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_string_conversion_set_opt
parameter_list|(
name|struct
name|archive_string_conv
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SCONV_SET_OPT_UTF8_LIBARCHIVE2X
value|1
end_define

begin_define
define|#
directive|define
name|SCONV_SET_OPT_NORMALIZATION_C
value|2
end_define

begin_define
define|#
directive|define
name|SCONV_SET_OPT_NORMALIZATION_D
value|4
end_define

begin_comment
comment|/* Copy one archive_string to another in locale conversion.  * Return -1 if conversion failes. */
end_comment

begin_function_decl
name|int
name|archive_strncpy_l
parameter_list|(
name|struct
name|archive_string
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|archive_string_conv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Copy one archive_string to another in locale conversion.  * Return -1 if conversion failes. */
end_comment

begin_function_decl
name|int
name|archive_strncat_l
parameter_list|(
name|struct
name|archive_string
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|archive_string_conv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Copy one archive_string to another */
end_comment

begin_define
define|#
directive|define
name|archive_string_copy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
define|\
value|((dest)->length = 0, archive_string_concat((dest), (src)))
end_define

begin_define
define|#
directive|define
name|archive_wstring_copy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
define|\
value|((dest)->length = 0, archive_wstring_concat((dest), (src)))
end_define

begin_comment
comment|/* Concatenate one archive_string to another */
end_comment

begin_function_decl
name|void
name|archive_string_concat
parameter_list|(
name|struct
name|archive_string
modifier|*
name|dest
parameter_list|,
name|struct
name|archive_string
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_wstring_concat
parameter_list|(
name|struct
name|archive_wstring
modifier|*
name|dest
parameter_list|,
name|struct
name|archive_wstring
modifier|*
name|src
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
name|archive_string_ensure
parameter_list|(
name|struct
name|archive_string
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|archive_wstring
modifier|*
name|archive_wstring_ensure
parameter_list|(
name|struct
name|archive_wstring
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Append C string, which may lack trailing \0. */
end_comment

begin_comment
comment|/* The source is declared void * here because this gets used with  * "signed char *", "unsigned char *" and "char *" arguments.  * Declaring it "char *" as with some of the other functions just  * leads to a lot of extra casts. */
end_comment

begin_function_decl
name|struct
name|archive_string
modifier|*
name|archive_strncat
parameter_list|(
name|struct
name|archive_string
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|archive_wstring
modifier|*
name|archive_wstrncat
parameter_list|(
name|struct
name|archive_wstring
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Append a C string to an archive_string, resizing as necessary. */
end_comment

begin_function_decl
name|struct
name|archive_string
modifier|*
name|archive_strcat
parameter_list|(
name|struct
name|archive_string
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|archive_wstring
modifier|*
name|archive_wstrcat
parameter_list|(
name|struct
name|archive_wstring
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
value|archive_strncpy((as), (p), ((p) == NULL ? 0 : strlen(p)))
end_define

begin_define
define|#
directive|define
name|archive_wstrcpy
parameter_list|(
name|as
parameter_list|,
name|p
parameter_list|)
define|\
value|archive_wstrncpy((as), (p), ((p) == NULL ? 0 : wcslen(p)))
end_define

begin_define
define|#
directive|define
name|archive_strcpy_l
parameter_list|(
name|as
parameter_list|,
name|p
parameter_list|,
name|lo
parameter_list|)
define|\
value|archive_strncpy_l((as), (p), ((p) == NULL ? 0 : strlen(p)), (lo))
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

begin_define
define|#
directive|define
name|archive_wstrncpy
parameter_list|(
name|as
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
define|\
value|((as)->length = 0, archive_wstrncat((as), (p), (l)))
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

begin_define
define|#
directive|define
name|archive_wstring_empty
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
name|archive_string_free
parameter_list|(
name|struct
name|archive_string
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_wstring_free
parameter_list|(
name|struct
name|archive_wstring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Like 'vsprintf', but resizes the underlying string as necessary. */
end_comment

begin_comment
comment|/* Note: This only implements a small subset of standard printf functionality. */
end_comment

begin_function_decl
name|void
name|archive_string_vsprintf
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
function_decl|__LA_PRINTF
parameter_list|(
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|archive_string_sprintf
parameter_list|(
name|struct
name|archive_string
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__LA_PRINTF
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Translates from MBS to Unicode. */
end_comment

begin_comment
comment|/* Returns non-zero if conversion failed in any way. */
end_comment

begin_function_decl
name|int
name|archive_wstring_append_from_mbs
parameter_list|(
name|struct
name|archive_wstring
modifier|*
name|dest
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* A "multistring" can hold Unicode, UTF8, or MBS versions of  * the string.  If you set and read the same version, no translation  * is done.  If you set and read different versions, the library  * will attempt to transparently convert.  */
end_comment

begin_struct
struct|struct
name|archive_mstring
block|{
name|struct
name|archive_string
name|aes_mbs
decl_stmt|;
name|struct
name|archive_string
name|aes_utf8
decl_stmt|;
name|struct
name|archive_wstring
name|aes_wcs
decl_stmt|;
name|struct
name|archive_string
name|aes_mbs_in_locale
decl_stmt|;
comment|/* Bitmap of which of the above are valid.  Because we're lazy 	 * about malloc-ing and reusing the underlying storage, we 	 * can't rely on NULL pointers to indicate whether a string 	 * has been set. */
name|int
name|aes_set
decl_stmt|;
define|#
directive|define
name|AES_SET_MBS
value|1
define|#
directive|define
name|AES_SET_UTF8
value|2
define|#
directive|define
name|AES_SET_WCS
value|4
block|}
struct|;
end_struct

begin_function_decl
name|void
name|archive_mstring_clean
parameter_list|(
name|struct
name|archive_mstring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_mstring_copy
parameter_list|(
name|struct
name|archive_mstring
modifier|*
name|dest
parameter_list|,
name|struct
name|archive_mstring
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_mstring_get_mbs
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|struct
name|archive_mstring
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_mstring_get_utf8
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|struct
name|archive_mstring
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_mstring_get_wcs
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|struct
name|archive_mstring
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_mstring_get_mbs_l
parameter_list|(
name|struct
name|archive_mstring
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|struct
name|archive_string_conv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_mstring_copy_mbs
parameter_list|(
name|struct
name|archive_mstring
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|mbs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_mstring_copy_mbs_len
parameter_list|(
name|struct
name|archive_mstring
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|mbs
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_mstring_copy_utf8
parameter_list|(
name|struct
name|archive_mstring
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|utf8
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_mstring_copy_wcs
parameter_list|(
name|struct
name|archive_mstring
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|wcs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_mstring_copy_wcs_len
parameter_list|(
name|struct
name|archive_mstring
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|wcs
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_mstring_copy_mbs_len_l
parameter_list|(
name|struct
name|archive_mstring
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|mbs
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|archive_string_conv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_mstring_update_utf8
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|struct
name|archive_mstring
modifier|*
name|aes
parameter_list|,
specifier|const
name|char
modifier|*
name|utf8
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

