begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: base64.h,v 1.15.206.1 2004/03/06 08:14:38 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_BASE64_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_BASE64_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/***  *** Functions  ***/
name|isc_result_t
name|isc_base64_totext
parameter_list|(
name|isc_region_t
modifier|*
name|source
parameter_list|,
name|int
name|wordlength
parameter_list|,
specifier|const
name|char
modifier|*
name|wordbreak
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert data into base64 encoded text.  *  * Notes:  *	The base64 encoded text in 'target' will be divided into  *	words of at most 'wordlength' characters, separated by  * 	the 'wordbreak' string.  No parentheses will surround  *	the text.  *  * Requires:  *	'source' is a region containing binary data  *	'target' is a text buffer containing available space  *	'wordbreak' points to a null-terminated string of  *		zero or more whitespace characters  *  * Ensures:  *	target will contain the base64 encoded version of the data  *	in source.  The 'used' pointer in target will be advanced as  *	necessary.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_base64_decodestring
parameter_list|(
specifier|const
name|char
modifier|*
name|cstr
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Decode a null-terminated base64 string.  *  * Requires:  *	'cstr' is non-null.  *	'target' is a valid buffer.  *  * Returns:  *	ISC_R_SUCCESS	-- the entire decoded representation of 'cstring'  *			   fit in 'target'.  *	ISC_R_BADBASE64 -- 'cstr' is not a valid base64 encoding.  *  * 	Other error returns are any possible error code from:  *		isc_lex_create(),  *		isc_lex_openbuffer(),  *		isc_base64_tobuffer().  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_base64_tobuffer
parameter_list|(
name|isc_lex_t
modifier|*
name|lexer
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert base64 encoded text from a lexer context into data.  *  * Requires:  *	'lex' is a valid lexer context  *	'target' is a buffer containing binary data  *	'length' is an integer  *  * Ensures:  *	target will contain the data represented by the base64 encoded  *	string parsed by the lexer.  No more than length bytes will be read,  *	if length is positive.  The 'used' pointer in target will be  *	advanced as necessary.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_BASE64_H */
end_comment

end_unit

