begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: lex.h,v 1.30.18.3 2005/06/04 00:39:05 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_LEX_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_LEX_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file isc/lex.h  * \brief The "lex" module provides a lightweight tokenizer.  It can operate  * on files or buffers, and can handle "include".  It is designed for  * parsing of DNS master files and the BIND configuration file, but  * should be general enough to tokenize other things, e.g. HTTP.  *  * \li MP:  *	No synchronization is provided.  Clients must ensure exclusive  *	access.  *  * \li Reliability:  *	No anticipated impact.  *  * \li Resources:  *	TBS  *  * \li Security:  *	No anticipated impact.  *  * \li Standards:  * 	None.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/region.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/***  *** Options  ***/
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/*!  * Various options for isc_lex_gettoken().  */
end_comment

begin_define
define|#
directive|define
name|ISC_LEXOPT_EOL
value|0x01
end_define

begin_comment
comment|/*%< Want end-of-line token. */
end_comment

begin_define
define|#
directive|define
name|ISC_LEXOPT_EOF
value|0x02
end_define

begin_comment
comment|/*%< Want end-of-file token. */
end_comment

begin_define
define|#
directive|define
name|ISC_LEXOPT_INITIALWS
value|0x04
end_define

begin_comment
comment|/*%< Want initial whitespace. */
end_comment

begin_define
define|#
directive|define
name|ISC_LEXOPT_NUMBER
value|0x08
end_define

begin_comment
comment|/*%< Recognize numbers. */
end_comment

begin_define
define|#
directive|define
name|ISC_LEXOPT_QSTRING
value|0x10
end_define

begin_comment
comment|/*%< Recognize qstrings. */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/*!  * The ISC_LEXOPT_DNSMULTILINE option handles the processing of '(' and ')' in  * the DNS master file format.  If this option is set, then the  * ISC_LEXOPT_INITIALWS and ISC_LEXOPT_EOL options will be ignored when  * the paren count is> 0.  To use this option, '(' and ')' must be special  * characters.  */
end_comment

begin_define
define|#
directive|define
name|ISC_LEXOPT_DNSMULTILINE
value|0x20
end_define

begin_comment
comment|/*%< Handle '(' and ')'. */
end_comment

begin_define
define|#
directive|define
name|ISC_LEXOPT_NOMORE
value|0x40
end_define

begin_comment
comment|/*%< Want "no more" token. */
end_comment

begin_define
define|#
directive|define
name|ISC_LEXOPT_CNUMBER
value|0x80
end_define

begin_comment
comment|/*%< Regognize octal and hex. */
end_comment

begin_define
define|#
directive|define
name|ISC_LEXOPT_ESCAPE
value|0x100
end_define

begin_comment
comment|/*%< Recognize escapes. */
end_comment

begin_define
define|#
directive|define
name|ISC_LEXOPT_QSTRINGMULTILINE
value|0x200
end_define

begin_comment
comment|/*%< Allow multiline "" strings */
end_comment

begin_define
define|#
directive|define
name|ISC_LEXOPT_OCTAL
value|0x400
end_define

begin_comment
comment|/*%< Expect a octal number. */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/*!  * Various commenting styles, which may be changed at any time with  * isc_lex_setcomments().  */
end_comment

begin_define
define|#
directive|define
name|ISC_LEXCOMMENT_C
value|0x01
end_define

begin_define
define|#
directive|define
name|ISC_LEXCOMMENT_CPLUSPLUS
value|0x02
end_define

begin_define
define|#
directive|define
name|ISC_LEXCOMMENT_SHELL
value|0x04
end_define

begin_define
define|#
directive|define
name|ISC_LEXCOMMENT_DNSMASTERFILE
value|0x08
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_comment
comment|/*! Lex */
end_comment

begin_typedef
typedef|typedef
name|char
name|isc_lexspecials_t
index|[
literal|256
index|]
typedef|;
end_typedef

begin_comment
comment|/* Tokens */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|isc_tokentype_unknown
init|=
literal|0
block|,
name|isc_tokentype_string
init|=
literal|1
block|,
name|isc_tokentype_number
init|=
literal|2
block|,
name|isc_tokentype_qstring
init|=
literal|3
block|,
name|isc_tokentype_eol
init|=
literal|4
block|,
name|isc_tokentype_eof
init|=
literal|5
block|,
name|isc_tokentype_initialws
init|=
literal|6
block|,
name|isc_tokentype_special
init|=
literal|7
block|,
name|isc_tokentype_nomore
init|=
literal|8
block|}
name|isc_tokentype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|char
name|as_char
decl_stmt|;
name|unsigned
name|long
name|as_ulong
decl_stmt|;
name|isc_region_t
name|as_region
decl_stmt|;
name|isc_textregion_t
name|as_textregion
decl_stmt|;
name|void
modifier|*
name|as_pointer
decl_stmt|;
block|}
name|isc_tokenvalue_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|isc_token
block|{
name|isc_tokentype_t
name|type
decl_stmt|;
name|isc_tokenvalue_t
name|value
decl_stmt|;
block|}
name|isc_token_t
typedef|;
end_typedef

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|isc_result_t
name|isc_lex_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|size_t
name|max_token
parameter_list|,
name|isc_lex_t
modifier|*
modifier|*
name|lexp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a lexer.  *  * 'max_token' is a hint of the number of bytes in the largest token.  *  * Requires:  *\li	'*lexp' is a valid lexer.  *  *\li	max_token> 0.  *  * Ensures:  *\li	On success, *lexp is attached to the newly created lexer.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|void
name|isc_lex_destroy
parameter_list|(
name|isc_lex_t
modifier|*
modifier|*
name|lexp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy the lexer.  *  * Requires:  *\li	'*lexp' is a valid lexer.  *  * Ensures:  *\li	*lexp == NULL  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_lex_getcomments
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the current lexer commenting styles.  *  * Requires:  *\li	'lex' is a valid lexer.  *  * Returns:  *\li	The commenting sytles which are currently allowed.  */
end_comment

begin_function_decl
name|void
name|isc_lex_setcomments
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|,
name|unsigned
name|int
name|comments
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set allowed lexer commenting styles.  *  * Requires:  *\li	'lex' is a valid lexer.  *  *\li	'comments' has meaningful values.  */
end_comment

begin_function_decl
name|void
name|isc_lex_getspecials
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|,
name|isc_lexspecials_t
name|specials
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Put the current list of specials into 'specials'.  *  * Requires:  *\li	'lex' is a valid lexer.  */
end_comment

begin_function_decl
name|void
name|isc_lex_setspecials
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|,
name|isc_lexspecials_t
name|specials
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * The characters in 'specials' are returned as tokens.  Along with  * whitespace, they delimit strings and numbers.  *  * Note:  *\li	Comment processing takes precedence over special character  *	recognition.  *  * Requires:  *\li	'lex' is a valid lexer.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_lex_openfile
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Open 'filename' and make it the current input source for 'lex'.  *  * Requires:  *\li	'lex' is a valid lexer.  *  *\li	filename is a valid C string.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY			Out of memory  *\li	#ISC_R_NOTFOUND			File not found  *\li	#ISC_R_NOPERM			No permission to open file  *\li	#ISC_R_FAILURE			Couldn't open file, not sure why  *\li	#ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_lex_openstream
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|,
name|FILE
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Make 'stream' the current input source for 'lex'.  *  * Requires:  *\li	'lex' is a valid lexer.  *  *\li	'stream' is a valid C stream.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY			Out of memory  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_lex_openbuffer
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|,
name|isc_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Make 'buffer' the current input source for 'lex'.  *  * Requires:  *\li	'lex' is a valid lexer.  *  *\li	'buffer' is a valid buffer.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY			Out of memory  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_lex_close
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Close the most recently opened object (i.e. file or buffer).  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMORE			No more input sources  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_lex_gettoken
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_token_t
modifier|*
name|tokenp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the next token.  *  * Requires:  *\li	'lex' is a valid lexer.  *  *\li	'lex' has an input source.  *  *\li	'options' contains valid options.  *  *\li	'*tokenp' is a valid pointer.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_UNEXPECTEDEND  *\li	#ISC_R_NOMEMORY  *  *	These two results are returned only if their corresponding lexer  *	options are not set.  *  *\li	#ISC_R_EOF			End of input source  *\li	#ISC_R_NOMORE			No more input sources  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_lex_getmastertoken
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|,
name|isc_token_t
modifier|*
name|token
parameter_list|,
name|isc_tokentype_t
name|expect
parameter_list|,
name|isc_boolean_t
name|eol
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the next token from a DNS master file type stream.  This is a  * convenience function that sets appropriate options and handles quoted  * strings and end of line correctly for master files.  It also ungets  * unexpected tokens.  *  * Requires:  *\li	'lex' is a valid lexer.  *  *\li	'token' is a valid pointer  *  * Returns:  *  * \li	any return code from isc_lex_gettoken().  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_lex_getoctaltoken
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|,
name|isc_token_t
modifier|*
name|token
parameter_list|,
name|isc_boolean_t
name|eol
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the next token from a DNS master file type stream.  This is a  * convenience function that sets appropriate options and handles end  * of line correctly for master files.  It also ungets unexpected tokens.  *  * Requires:  *\li	'lex' is a valid lexer.  *  *\li	'token' is a valid pointer  *  * Returns:  *  * \li	any return code from isc_lex_gettoken().  */
end_comment

begin_function_decl
name|void
name|isc_lex_ungettoken
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|,
name|isc_token_t
modifier|*
name|tokenp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Unget the current token.  *  * Requires:  *\li	'lex' is a valid lexer.  *  *\li	'lex' has an input source.  *  *\li	'tokenp' points to a valid token.  *  *\li	There is no ungotten token already.  */
end_comment

begin_function_decl
name|void
name|isc_lex_getlasttokentext
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|,
name|isc_token_t
modifier|*
name|tokenp
parameter_list|,
name|isc_region_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns a region containing the text of the last token returned.  *  * Requires:  *\li	'lex' is a valid lexer.  *  *\li	'lex' has an input source.  *  *\li	'tokenp' points to a valid token.  *  *\li	A token has been gotten and not ungotten.  */
end_comment

begin_function_decl
name|char
modifier|*
name|isc_lex_getsourcename
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the input source name.  *  * Requires:  *\li	'lex' is a valid lexer.  *  * Returns:  * \li	source name or NULL if no current source.  *\li	result valid while current input source exists.  */
end_comment

begin_function_decl
name|unsigned
name|long
name|isc_lex_getsourceline
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the input source line number.  *  * Requires:  *\li	'lex' is a valid lexer.  *  * Returns:  *\li 	Current line number or 0 if no current source.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_lex_setsourcename
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Assigns a new name to the input source.  *  * Requires:  *  * \li	'lex' is a valid lexer.  *  * Returns:  * \li	#ISC_R_SUCCESS  * \li	#ISC_R_NOMEMORY  * \li	#ISC_R_NOTFOUND - there are no sources.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_lex_isfile
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return whether the current input source is a file.  *  * Requires:  *\li	'lex' is a valid lexer.  *  * Returns:  * \li	#ISC_TRUE if the current input is a file,  *\li	#ISC_FALSE otherwise.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_LEX_H */
end_comment

end_unit

