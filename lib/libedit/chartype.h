begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: chartype.h,v 1.6 2010/04/20 02:01:13 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_chartype_f
end_ifndef

begin_define
define|#
directive|define
name|_h_chartype_f
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIDECHAR
end_ifdef

begin_comment
comment|/* Ideally we should also test the value of the define to see if it  * supports non-BMP code points without requiring UTF-16, but nothing  * seems to actually advertise this properly, despite Unicode 3.1 having  * been around since 2001... */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__sun
argument_list|)
operator|&&
operator|!
operator|(
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__MACH__
argument_list|)
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC_ISO_10646__
end_ifndef

begin_comment
comment|/* In many places it is assumed that the first 127 code points are ASCII  * compatible, so ensure wchar_t indeed does ISO 10646 and not some other  * funky encoding that could break us in weird and wonderful ways. */
end_comment

begin_error
error|#
directive|error
error|wchar_t must store ISO 10646 characters
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Oh for a<uchar.h> with char32_t and __STDC_UTF_32__ in it...  * ref: ISO/IEC DTR 19769  */
end_comment

begin_if
if|#
directive|if
name|WCHAR_MAX
operator|<
name|INT32_MAX
end_if

begin_warning
warning|#
directive|warning
warning|Build environment does not support non-BMP characters
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ct_mbtowc
value|mbtowc
end_define

begin_define
define|#
directive|define
name|ct_mbtowc_reset
value|mbtowc(0,0,0)
end_define

begin_define
define|#
directive|define
name|ct_wctomb
value|wctomb
end_define

begin_define
define|#
directive|define
name|ct_wctomb_reset
value|wctomb(0,0)
end_define

begin_define
define|#
directive|define
name|ct_wcstombs
value|wcstombs
end_define

begin_define
define|#
directive|define
name|ct_mbstowcs
value|mbstowcs
end_define

begin_define
define|#
directive|define
name|Char
value|wchar_t
end_define

begin_define
define|#
directive|define
name|Int
value|wint_t
end_define

begin_define
define|#
directive|define
name|FUN
parameter_list|(
name|prefix
parameter_list|,
name|rest
parameter_list|)
value|prefix ## _w ## rest
end_define

begin_define
define|#
directive|define
name|FUNW
parameter_list|(
name|type
parameter_list|)
value|type ## _w
end_define

begin_define
define|#
directive|define
name|TYPE
parameter_list|(
name|type
parameter_list|)
value|type ## W
end_define

begin_define
define|#
directive|define
name|FSTR
value|"%ls"
end_define

begin_define
define|#
directive|define
name|STR
parameter_list|(
name|x
parameter_list|)
value|L ## x
end_define

begin_define
define|#
directive|define
name|UC
parameter_list|(
name|c
parameter_list|)
value|c
end_define

begin_define
define|#
directive|define
name|Isalpha
parameter_list|(
name|x
parameter_list|)
value|iswalpha(x)
end_define

begin_define
define|#
directive|define
name|Isalnum
parameter_list|(
name|x
parameter_list|)
value|iswalnum(x)
end_define

begin_define
define|#
directive|define
name|Isgraph
parameter_list|(
name|x
parameter_list|)
value|iswgraph(x)
end_define

begin_define
define|#
directive|define
name|Isspace
parameter_list|(
name|x
parameter_list|)
value|iswspace(x)
end_define

begin_define
define|#
directive|define
name|Isdigit
parameter_list|(
name|x
parameter_list|)
value|iswdigit(x)
end_define

begin_define
define|#
directive|define
name|Iscntrl
parameter_list|(
name|x
parameter_list|)
value|iswcntrl(x)
end_define

begin_define
define|#
directive|define
name|Isprint
parameter_list|(
name|x
parameter_list|)
value|iswprint(x)
end_define

begin_define
define|#
directive|define
name|Isupper
parameter_list|(
name|x
parameter_list|)
value|iswupper(x)
end_define

begin_define
define|#
directive|define
name|Islower
parameter_list|(
name|x
parameter_list|)
value|iswlower(x)
end_define

begin_define
define|#
directive|define
name|Toupper
parameter_list|(
name|x
parameter_list|)
value|towupper(x)
end_define

begin_define
define|#
directive|define
name|Tolower
parameter_list|(
name|x
parameter_list|)
value|towlower(x)
end_define

begin_define
define|#
directive|define
name|IsASCII
parameter_list|(
name|x
parameter_list|)
value|(x< 0x100)
end_define

begin_define
define|#
directive|define
name|Strlen
parameter_list|(
name|x
parameter_list|)
value|wcslen(x)
end_define

begin_define
define|#
directive|define
name|Strchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|wcschr(s,c)
end_define

begin_define
define|#
directive|define
name|Strrchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|wcsrchr(s,c)
end_define

begin_define
define|#
directive|define
name|Strstr
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|wcsstr(s,v)
end_define

begin_define
define|#
directive|define
name|Strdup
parameter_list|(
name|x
parameter_list|)
value|wcsdup(x)
end_define

begin_define
define|#
directive|define
name|Strcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|wcscpy(d,s)
end_define

begin_define
define|#
directive|define
name|Strncpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|wcsncpy(d,s,n)
end_define

begin_define
define|#
directive|define
name|Strncat
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|wcsncat(d,s,n)
end_define

begin_define
define|#
directive|define
name|Strcmp
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|wcscmp(s,v)
end_define

begin_define
define|#
directive|define
name|Strncmp
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|)
value|wcsncmp(s,v,n)
end_define

begin_define
define|#
directive|define
name|Strcspn
parameter_list|(
name|s
parameter_list|,
name|r
parameter_list|)
value|wcscspn(s,r)
end_define

begin_define
define|#
directive|define
name|Strtol
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|b
parameter_list|)
value|wcstol(p,e,b)
end_define

begin_define
define|#
directive|define
name|Width
parameter_list|(
name|c
parameter_list|)
value|wcwidth(c)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NARROW */
end_comment

begin_define
define|#
directive|define
name|ct_mbtowc
value|error
end_define

begin_define
define|#
directive|define
name|ct_mbtowc_reset
end_define

begin_define
define|#
directive|define
name|ct_wctomb
value|error
end_define

begin_define
define|#
directive|define
name|ct_wctomb_reset
end_define

begin_define
define|#
directive|define
name|ct_wcstombs
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(strncpy(a, b, c), strlen(a))
end_define

begin_define
define|#
directive|define
name|ct_mbstowcs
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(strncpy(a, b, c), strlen(a))
end_define

begin_define
define|#
directive|define
name|Char
value|char
end_define

begin_define
define|#
directive|define
name|Int
value|int
end_define

begin_define
define|#
directive|define
name|FUN
parameter_list|(
name|prefix
parameter_list|,
name|rest
parameter_list|)
value|prefix ## _ ## rest
end_define

begin_define
define|#
directive|define
name|FUNW
parameter_list|(
name|type
parameter_list|)
value|type
end_define

begin_define
define|#
directive|define
name|TYPE
parameter_list|(
name|type
parameter_list|)
value|type
end_define

begin_define
define|#
directive|define
name|FSTR
value|"%s"
end_define

begin_define
define|#
directive|define
name|STR
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|UC
parameter_list|(
name|c
parameter_list|)
value|(unsigned char)(c)
end_define

begin_define
define|#
directive|define
name|Isalpha
parameter_list|(
name|x
parameter_list|)
value|isalpha((unsigned char)x)
end_define

begin_define
define|#
directive|define
name|Isalnum
parameter_list|(
name|x
parameter_list|)
value|isalnum((unsigned char)x)
end_define

begin_define
define|#
directive|define
name|Isgraph
parameter_list|(
name|x
parameter_list|)
value|isgraph((unsigned char)x)
end_define

begin_define
define|#
directive|define
name|Isspace
parameter_list|(
name|x
parameter_list|)
value|isspace((unsigned char)x)
end_define

begin_define
define|#
directive|define
name|Isdigit
parameter_list|(
name|x
parameter_list|)
value|isdigit((unsigned char)x)
end_define

begin_define
define|#
directive|define
name|Iscntrl
parameter_list|(
name|x
parameter_list|)
value|iscntrl((unsigned char)x)
end_define

begin_define
define|#
directive|define
name|Isprint
parameter_list|(
name|x
parameter_list|)
value|isprint((unsigned char)x)
end_define

begin_define
define|#
directive|define
name|Isupper
parameter_list|(
name|x
parameter_list|)
value|isupper((unsigned char)x)
end_define

begin_define
define|#
directive|define
name|Islower
parameter_list|(
name|x
parameter_list|)
value|islower((unsigned char)x)
end_define

begin_define
define|#
directive|define
name|Toupper
parameter_list|(
name|x
parameter_list|)
value|toupper((unsigned char)x)
end_define

begin_define
define|#
directive|define
name|Tolower
parameter_list|(
name|x
parameter_list|)
value|tolower((unsigned char)x)
end_define

begin_define
define|#
directive|define
name|IsASCII
parameter_list|(
name|x
parameter_list|)
value|isascii((unsigned char)x)
end_define

begin_define
define|#
directive|define
name|Strlen
parameter_list|(
name|x
parameter_list|)
value|strlen(x)
end_define

begin_define
define|#
directive|define
name|Strchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|strchr(s,c)
end_define

begin_define
define|#
directive|define
name|Strrchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|strrchr(s,c)
end_define

begin_define
define|#
directive|define
name|Strstr
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|strstr(s,v)
end_define

begin_define
define|#
directive|define
name|Strdup
parameter_list|(
name|x
parameter_list|)
value|strdup(x)
end_define

begin_define
define|#
directive|define
name|Strcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|strcpy(d,s)
end_define

begin_define
define|#
directive|define
name|Strncpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|strncpy(d,s,n)
end_define

begin_define
define|#
directive|define
name|Strncat
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|strncat(d,s,n)
end_define

begin_define
define|#
directive|define
name|Strcmp
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|strcmp(s,v)
end_define

begin_define
define|#
directive|define
name|Strncmp
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|)
value|strncmp(s,v,n)
end_define

begin_define
define|#
directive|define
name|Strcspn
parameter_list|(
name|s
parameter_list|,
name|r
parameter_list|)
value|strcspn(s,r)
end_define

begin_define
define|#
directive|define
name|Strtol
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|b
parameter_list|)
value|strtol(p,e,b)
end_define

begin_define
define|#
directive|define
name|Width
parameter_list|(
name|c
parameter_list|)
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WIDECHAR
end_ifdef

begin_comment
comment|/*  * Conversion buffer  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ct_buffer_t
block|{
name|char
modifier|*
name|cbuff
decl_stmt|;
name|size_t
name|csize
decl_stmt|;
name|Char
modifier|*
name|wbuff
decl_stmt|;
name|size_t
name|wsize
decl_stmt|;
block|}
name|ct_buffer_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ct_encode_string
value|__ct_encode_string
end_define

begin_comment
comment|/* Encode a wide character string and return the UTF-8 encoded result. */
end_comment

begin_function_decl
name|public
name|char
modifier|*
name|ct_encode_string
parameter_list|(
specifier|const
name|Char
modifier|*
parameter_list|,
name|ct_buffer_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ct_decode_string
value|__ct_decode_string
end_define

begin_comment
comment|/* Decode a (multi)?byte string and return the wide character string result. */
end_comment

begin_function_decl
name|public
name|Char
modifier|*
name|ct_decode_string
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|ct_buffer_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Decode a (multi)?byte argv string array.  * The pointer returned must be free()d when done. */
end_comment

begin_function_decl
name|protected
name|Char
modifier|*
modifier|*
name|ct_decode_argv
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
index|[]
parameter_list|,
name|ct_buffer_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Resizes the conversion buffer(s) if needed. */
end_comment

begin_function_decl
name|protected
name|void
name|ct_conv_buff_resize
parameter_list|(
name|ct_buffer_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|ssize_t
name|ct_encode_char
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|Char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|size_t
name|ct_enc_width
parameter_list|(
name|Char
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ct_free_argv
parameter_list|(
name|s
parameter_list|)
value|el_free(s)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ct_encode_string
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|)
value|(s)
end_define

begin_define
define|#
directive|define
name|ct_decode_string
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|)
value|(s)
end_define

begin_define
define|#
directive|define
name|ct_decode_argv
parameter_list|(
name|l
parameter_list|,
name|s
parameter_list|,
name|b
parameter_list|)
value|(s)
end_define

begin_define
define|#
directive|define
name|ct_conv_buff_resize
parameter_list|(
name|b
parameter_list|,
name|os
parameter_list|,
name|ns
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ct_encode_char
parameter_list|(
name|d
parameter_list|,
name|l
parameter_list|,
name|s
parameter_list|)
value|(*d = s, 1)
end_define

begin_define
define|#
directive|define
name|ct_free_argv
parameter_list|(
name|s
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NARROWCHAR
end_ifndef

begin_comment
comment|/* Encode a characted into the destination buffer, provided there is sufficent  * buffer space available. Returns the number of bytes used up (zero if the  * character cannot be encoded, -1 if there was not enough space available). */
end_comment

begin_comment
comment|/* The maximum buffer size to hold the most unwieldly visual representation,  * in this case \U+nnnnn. */
end_comment

begin_define
define|#
directive|define
name|VISUAL_WIDTH_MAX
value|8
end_define

begin_comment
comment|/* The terminal is thought of in terms of X columns by Y lines. In the cases  * where a wide character takes up more than one column, the adjacent   * occupied column entries will contain this faux character. */
end_comment

begin_define
define|#
directive|define
name|MB_FILL_CHAR
value|((Char)-1)
end_define

begin_comment
comment|/* Visual width of character c, taking into account ^? , \0177 and \U+nnnnn  * style visual expansions. */
end_comment

begin_function_decl
name|protected
name|int
name|ct_visual_width
parameter_list|(
name|Char
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Turn the given character into the appropriate visual format, matching  * the width given by ct_visual_width(). Returns the number of characters used  * up, or -1 if insufficient space. Buffer length is in count of Char's. */
end_comment

begin_function_decl
name|protected
name|ssize_t
name|ct_visual_char
parameter_list|(
name|Char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|Char
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert the given string into visual format, using the ct_visual_char()  * function. Uses a static buffer, so not threadsafe. */
end_comment

begin_function_decl
name|protected
specifier|const
name|Char
modifier|*
name|ct_visual_string
parameter_list|(
specifier|const
name|Char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* printable character, use ct_visual_width() to find out display width */
end_comment

begin_define
define|#
directive|define
name|CHTYPE_PRINT
value|( 0)
end_define

begin_comment
comment|/* control character found inside the ASCII portion of the charset */
end_comment

begin_define
define|#
directive|define
name|CHTYPE_ASCIICTL
value|(-1)
end_define

begin_comment
comment|/* a \t */
end_comment

begin_define
define|#
directive|define
name|CHTYPE_TAB
value|(-2)
end_define

begin_comment
comment|/* a \n */
end_comment

begin_define
define|#
directive|define
name|CHTYPE_NL
value|(-3)
end_define

begin_comment
comment|/* non-printable character */
end_comment

begin_define
define|#
directive|define
name|CHTYPE_NONPRINT
value|(-4)
end_define

begin_comment
comment|/* classification of character c, as one of the above defines */
end_comment

begin_function_decl
name|protected
name|int
name|ct_chr_class
parameter_list|(
name|Char
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _chartype_f */
end_comment

end_unit

