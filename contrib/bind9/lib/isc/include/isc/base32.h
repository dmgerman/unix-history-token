begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2008, 2014  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_BASE32_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_BASE32_H
value|1
end_define

begin_comment
comment|/*! \file */
end_comment

begin_comment
comment|/*  * Routines for manipulating base 32 and base 32 hex encoded data.  * Based on RFC 4648.  *  * Base 32 hex preserves the sort order of data when it is encoded /  * decoded.  *  * Base 32 hex "np" is base 32 hex but no padding is produced or accepted.  */
end_comment

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
name|isc_base32_totext
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

begin_function_decl
name|isc_result_t
name|isc_base32hex_totext
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

begin_function_decl
name|isc_result_t
name|isc_base32hexnp_totext
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
comment|/*!<  * \brief Convert data into base32 encoded text.  *  * Notes:  *\li	The base32 encoded text in 'target' will be divided into  *	words of at most 'wordlength' characters, separated by  * 	the 'wordbreak' string.  No parentheses will surround  *	the text.  *  * Requires:  *\li	'source' is a region containing binary data  *\li	'target' is a text buffer containing available space  *\li	'wordbreak' points to a null-terminated string of  *		zero or more whitespace characters  *  * Ensures:  *\li	target will contain the base32 encoded version of the data  *	in source.  The 'used' pointer in target will be advanced as  *	necessary.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_base32_decodestring
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

begin_function_decl
name|isc_result_t
name|isc_base32hex_decodestring
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

begin_function_decl
name|isc_result_t
name|isc_base32hexnp_decodestring
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
comment|/*!<  * \brief Decode a null-terminated string in base32, base32hex, or  * base32hex non-padded.  *  * Requires:  *\li	'cstr' is non-null.  *\li	'target' is a valid buffer.  *  * Returns:  *\li	#ISC_R_SUCCESS	-- the entire decoded representation of 'cstring'  *			   fit in 'target'.  *\li	#ISC_R_BADBASE32 -- 'cstr' is not a valid base32 encoding.  *  * 	Other error returns are any possible error code from:  *\li		isc_lex_create(),  *\li		isc_lex_openbuffer(),  *\li		isc_base32_tobuffer().  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_base32_tobuffer
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

begin_function_decl
name|isc_result_t
name|isc_base32hex_tobuffer
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

begin_function_decl
name|isc_result_t
name|isc_base32hexnp_tobuffer
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
comment|/*!<  * \brief Convert text encoded in base32, base32hex, or base32hex  * non-padded from a lexer context into data.  *  * Requires:  *\li	'lex' is a valid lexer context  *\li	'target' is a buffer containing binary data  *\li	'length' is an integer  *  * Ensures:  *\li	target will contain the data represented by the base32 encoded  *	string parsed by the lexer.  No more than length bytes will be read,  *	if length is positive.  The 'used' pointer in target will be  *	advanced as necessary.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_base32_decoderegion
parameter_list|(
name|isc_region_t
modifier|*
name|source
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_base32hex_decoderegion
parameter_list|(
name|isc_region_t
modifier|*
name|source
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_base32hexnp_decoderegion
parameter_list|(
name|isc_region_t
modifier|*
name|source
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Decode a packed (no white space permitted) region in  * base32, base32hex or base32hex non-padded.  *  * Requires:  *\li   'source' is a valid region.  *\li   'target' is a valid buffer.  *  * Returns:  *\li   #ISC_R_SUCCESS  -- the entire decoded representation of 'cstring'  *                         fit in 'target'.  *\li   #ISC_R_BADBASE32 -- 'source' is not a valid base32 encoding.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_BASE32_H */
end_comment

end_unit

