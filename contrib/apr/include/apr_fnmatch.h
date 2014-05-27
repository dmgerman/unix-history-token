begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fnmatch.h	8.1 (Berkeley) 6/2/93  */
end_comment

begin_comment
comment|/* This file has been modified by the Apache Software Foundation. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_APR_FNMATCH_H_
end_ifndef

begin_define
define|#
directive|define
name|_APR_FNMATCH_H_
end_define

begin_comment
comment|/**  * @file apr_fnmatch.h  * @brief APR FNMatch Functions  */
end_comment

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_include
include|#
directive|include
file|"apr_tables.h"
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
comment|/**  * @defgroup apr_fnmatch Filename Matching Functions  * @ingroup APR   * @{  */
define|#
directive|define
name|APR_FNM_NOMATCH
value|1
comment|/**< Match failed. */
define|#
directive|define
name|APR_FNM_NOESCAPE
value|0x01
comment|/**< Disable backslash escaping. */
define|#
directive|define
name|APR_FNM_PATHNAME
value|0x02
comment|/**< Slash must be matched by slash. */
define|#
directive|define
name|APR_FNM_PERIOD
value|0x04
comment|/**< Period must be matched by period. */
define|#
directive|define
name|APR_FNM_CASE_BLIND
value|0x08
comment|/**< Compare characters case-insensitively. */
comment|/**  * Try to match the string to the given pattern, return APR_SUCCESS if  *    match, else return APR_FNM_NOMATCH.  Note that there is no such thing as  *    an illegal pattern.  *  * With all flags unset, a pattern is interpreted as such:  *  * PATTERN: Backslash followed by any character, including another  *          backslash.<br/>  * MATCHES: That character exactly.  *   *<p>  * PATTERN: ?<br/>  * MATCHES: Any single character.  *</p>  *   *<p>  * PATTERN: *<br/>  * MATCHES: Any sequence of zero or more characters. (Note that multiple  *          *s in a row are equivalent to one.)  *   * PATTERN: Any character other than \?*[ or a \ at the end of the pattern<br/>  * MATCHES: That character exactly. (Case sensitive.)  *   * PATTERN: [ followed by a class description followed by ]<br/>  * MATCHES: A single character described by the class description.  *          (Never matches, if the class description reaches until the  *          end of the string without a ].) If the first character of  *          the class description is ^ or !, the sense of the description  *          is reversed.  The rest of the class description is a list of  *          single characters or pairs of characters separated by -. Any  *          of those characters can have a backslash in front of them,  *          which is ignored; this lets you use the characters ] and -  *          in the character class, as well as ^ and ! at the  *          beginning.  The pattern matches a single character if it  *          is one of the listed characters or falls into one of the  *          listed ranges (inclusive, case sensitive).  Ranges with  *          the first character larger than the second are legal but  *          never match. Edge cases: [] never matches, and [^] and [!]  *          always match without consuming a character.  *   * Note that these patterns attempt to match the entire string, not  * just find a substring matching the pattern.  *  * @param pattern The pattern to match to  * @param strings The string we are trying to match  * @param flags flags to use in the match.  Bitwise OR of:  *<pre>  *              APR_FNM_NOESCAPE       Disable backslash escaping  *              APR_FNM_PATHNAME       Slash must be matched by slash  *              APR_FNM_PERIOD         Period must be matched by period  *              APR_FNM_CASE_BLIND     Compare characters case-insensitively.  *</pre>  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_fnmatch
argument_list|(
argument|const char *pattern
argument_list|,
argument|const char *strings
argument_list|,
argument|int flags
argument_list|)
empty_stmt|;
comment|/**  * Determine if the given pattern is a regular expression.  * @param pattern The pattern to search for glob characters.  * @return non-zero if pattern has any glob characters in it  */
name|APR_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_fnmatch_test
argument_list|(
specifier|const
name|char
operator|*
name|pattern
argument_list|)
expr_stmt|;
comment|/**  * Find all files that match a specified pattern in a directory.  * @param dir_pattern The pattern to use for finding files, appended  * to the search directory.  The pattern is anything following the  * final forward or backward slash in the parameter.  If no slash  * is found, the current directory is searched.  * @param result Array to use when storing the results  * @param p The pool to use.  * @return APR_SUCCESS if no processing errors occurred, APR error  * code otherwise  * @remark The returned array may be empty even if APR_SUCCESS was  * returned.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_match_glob
argument_list|(
specifier|const
name|char
operator|*
name|dir_pattern
argument_list|,
name|apr_array_header_t
operator|*
operator|*
name|result
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_APR_FNMATCH_H_ */
end_comment

end_unit

