begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_ctype.h  * @brief Character classification routines  * @since New in 1.2.  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_CTYPE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_CTYPE_H
end_define

begin_include
include|#
directive|include
file|<apr.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
comment|/** Table of flags for character classification. */
specifier|extern
specifier|const
name|apr_uint32_t
modifier|*
specifier|const
name|svn_ctype_table
decl_stmt|;
comment|/** Check if @a c is in the character class described by @a flags.  * The @a flags is a bitwise-or combination of @c SVN_CTYPE_*  * constants. Uses #svn_ctype_table.  */
define|#
directive|define
name|svn_ctype_test
parameter_list|(
name|c
parameter_list|,
name|flags
parameter_list|)
define|\
value|(0 != (svn_ctype_table[(unsigned char)(c)]& (flags)))
comment|/**  * @defgroup ctype_basic Basic character classification - 7-bit ASCII only  * @{  */
comment|/* Basic character classes */
define|#
directive|define
name|SVN_CTYPE_CNTRL
value|0x0001
comment|/**< Control character */
define|#
directive|define
name|SVN_CTYPE_SPACE
value|0x0002
comment|/**< Whitespace */
define|#
directive|define
name|SVN_CTYPE_DIGIT
value|0x0004
comment|/**< Decimal digit */
define|#
directive|define
name|SVN_CTYPE_UPPER
value|0x0008
comment|/**< Uppercase letter */
define|#
directive|define
name|SVN_CTYPE_LOWER
value|0x0010
comment|/**< Lowercase letter */
define|#
directive|define
name|SVN_CTYPE_PUNCT
value|0x0020
comment|/**< Punctuation mark */
define|#
directive|define
name|SVN_CTYPE_XALPHA
value|0x0040
comment|/**< Hexadecimal digits A to F */
define|#
directive|define
name|SVN_CTYPE_ASCII
value|0x0080
comment|/**< ASCII subset*/
comment|/* Derived character classes */
comment|/** ASCII letter */
define|#
directive|define
name|SVN_CTYPE_ALPHA
value|(SVN_CTYPE_LOWER | SVN_CTYPE_UPPER)
comment|/** ASCII letter or decimal digit */
define|#
directive|define
name|SVN_CTYPE_ALNUM
value|(SVN_CTYPE_ALPHA | SVN_CTYPE_DIGIT)
comment|/** ASCII hexadecimal digit */
define|#
directive|define
name|SVN_CTYPE_XDIGIT
value|(SVN_CTYPE_DIGIT | SVN_CTYPE_XALPHA)
comment|/** Printable ASCII except space */
define|#
directive|define
name|SVN_CTYPE_GRAPH
value|(SVN_CTYPE_PUNCT | SVN_CTYPE_ALNUM)
comment|/** All printable ASCII */
define|#
directive|define
name|SVN_CTYPE_PRINT
value|(SVN_CTYPE_GRAPH | SVN_CTYPE_SPACE)
comment|/** Check if @a c is an ASCII control character. */
define|#
directive|define
name|svn_ctype_iscntrl
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYPE_CNTRL)
comment|/** Check if @a c is an ASCII whitespace character. */
define|#
directive|define
name|svn_ctype_isspace
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYPE_SPACE)
comment|/** Check if @a c is an ASCII digit. */
define|#
directive|define
name|svn_ctype_isdigit
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYPE_DIGIT)
comment|/** Check if @a c is an ASCII uppercase letter. */
define|#
directive|define
name|svn_ctype_isupper
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYPE_UPPER)
comment|/** Check if @a c is an ASCII lowercase letter. */
define|#
directive|define
name|svn_ctype_islower
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYPE_LOWER)
comment|/** Check if @a c is an ASCII punctuation mark. */
define|#
directive|define
name|svn_ctype_ispunct
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYPE_PUNCT)
comment|/** Check if @a c is an ASCII character. */
define|#
directive|define
name|svn_ctype_isascii
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYPE_ASCII)
comment|/** Check if @a c is an ASCII letter. */
define|#
directive|define
name|svn_ctype_isalpha
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYPE_ALPHA)
comment|/** Check if @a c is an ASCII letter or decimal digit. */
define|#
directive|define
name|svn_ctype_isalnum
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYPE_ALNUM)
comment|/** Check if @a c is an ASCII hexadecimal digit. */
define|#
directive|define
name|svn_ctype_isxdigit
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYPE_XDIGIT)
comment|/** Check if @a c is an ASCII graphical (visible printable) character. */
define|#
directive|define
name|svn_ctype_isgraph
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYPE_GRAPH)
comment|/** Check if @a c is an ASCII printable character. */
define|#
directive|define
name|svn_ctype_isprint
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYPE_PRINT)
comment|/** @} */
comment|/**  * @defgroup ctype_extra Extended character classification  * @{  */
comment|/* Basic extended character classes */
define|#
directive|define
name|SVN_CTYPE_UTF8LEAD
value|0x0100
comment|/**< UTF-8 multibyte lead byte */
define|#
directive|define
name|SVN_CTYPE_UTF8CONT
value|0x0200
comment|/**< UTF-8 multibyte non-lead byte */
comment|/* ### TBD #define SVN_CTYPE_XMLNAME  0x0400 #define SVN_CTYPE_URISAFE  0x0800 */
comment|/* Derived extended character classes */
comment|/** Part of a UTF-8 multibyte character. */
define|#
directive|define
name|SVN_CTYPE_UTF8MBC
value|(SVN_CTYPE_UTF8LEAD | SVN_CTYPE_UTF8CONT)
comment|/** All valid UTF-8 bytes. */
define|#
directive|define
name|SVN_CTYPE_UTF8
value|(SVN_CTYPE_ASCII | SVN_CTYPE_UTF8MBC)
comment|/** Check if @a c is a UTF-8 multibyte lead byte. */
define|#
directive|define
name|svn_ctype_isutf8lead
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYPE_UTF8LEAD)
comment|/** Check if @a c is a UTF-8 multibyte continuation (non-lead) byte. */
define|#
directive|define
name|svn_ctype_isutf8cont
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYLE_UTF8CONT)
comment|/** Check if @a c is part of a UTF-8 multibyte character. */
define|#
directive|define
name|svn_ctype_isutf8mbc
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYPE_UTF8MBC)
comment|/** Check if @a c is valid in UTF-8. */
define|#
directive|define
name|svn_ctype_isutf8
parameter_list|(
name|c
parameter_list|)
value|svn_ctype_test((c), SVN_CTYPE_UTF8)
comment|/** @} */
comment|/**  * @defgroup ctype_ascii ASCII character value constants  * @{  */
define|#
directive|define
name|SVN_CTYPE_ASCII_MINUS
value|45
comment|/**< ASCII value of '-' */
define|#
directive|define
name|SVN_CTYPE_ASCII_DOT
value|46
comment|/**< ASCII value of '.' */
define|#
directive|define
name|SVN_CTYPE_ASCII_COLON
value|58
comment|/**< ASCII value of ':' */
define|#
directive|define
name|SVN_CTYPE_ASCII_UNDERSCORE
value|95
comment|/**< ASCII value of '_' */
define|#
directive|define
name|SVN_CTYPE_ASCII_TAB
value|9
comment|/**< ASCII value of a tab */
define|#
directive|define
name|SVN_CTYPE_ASCII_LINEFEED
value|10
comment|/**< ASCII value of a line feed */
define|#
directive|define
name|SVN_CTYPE_ASCII_CARRIAGERETURN
value|13
comment|/**< ASCII value of a carriage return */
define|#
directive|define
name|SVN_CTYPE_ASCII_DELETE
value|127
comment|/**< ASCII value of a delete character */
comment|/** @} */
comment|/**  * @defgroup ctype_case ASCII-subset case folding  * @{  */
comment|/**  * Compare two characters @a a and @a b, treating case-equivalent  * unaccented Latin (ASCII subset) letters as equal.  *  * Returns in integer greater than, equal to, or less than 0,  * according to whether @a a is considered greater than, equal to,  * or less than @a b.  *  * @since New in 1.5.  */
name|int
name|svn_ctype_casecmp
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
function_decl|;
comment|/** @} */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_CTYPE_H */
end_comment

end_unit

