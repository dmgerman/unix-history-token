begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)search.h	8.9 (Berkeley) 3/16/94  */
end_comment

begin_define
define|#
directive|define
name|RE_WSTART
value|"[[:<:]]"
end_define

begin_comment
comment|/* Not-in-word search patterns. */
end_comment

begin_define
define|#
directive|define
name|RE_WSTOP
value|"[[:>:]]"
end_define

begin_define
define|#
directive|define
name|SEARCH_DELTA
value|0x001
end_define

begin_comment
comment|/* A delta part of the search.*/
end_comment

begin_define
define|#
directive|define
name|SEARCH_EOL
value|0x002
end_define

begin_comment
comment|/* Offset past EOL is okay. */
end_comment

begin_define
define|#
directive|define
name|SEARCH_FILE
value|0x004
end_define

begin_comment
comment|/* Search the entire file. */
end_comment

begin_define
define|#
directive|define
name|SEARCH_MSG
value|0x008
end_define

begin_comment
comment|/* Display search warning messages. */
end_comment

begin_define
define|#
directive|define
name|SEARCH_PARSE
value|0x010
end_define

begin_comment
comment|/* Parse the search pattern. */
end_comment

begin_define
define|#
directive|define
name|SEARCH_SET
value|0x020
end_define

begin_comment
comment|/* Set search direction. */
end_comment

begin_define
define|#
directive|define
name|SEARCH_TAG
value|0x040
end_define

begin_comment
comment|/* Search pattern is a tag pattern. */
end_comment

begin_define
define|#
directive|define
name|SEARCH_TERM
value|0x080
end_define

begin_comment
comment|/* Search pattern should terminate. */
end_comment

begin_enum
enum|enum
name|direction
block|{
name|NOTSET
block|,
name|FORWARD
block|,
name|BACKWARD
block|}
enum|;
end_enum

begin_comment
comment|/* Search functions. */
end_comment

begin_decl_stmt
name|int
name|b_search
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|MARK
operator|*
operator|,
name|MARK
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|u_int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|f_search
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|MARK
operator|*
operator|,
name|MARK
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|u_int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|re_conv
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|re_error
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|int
operator|,
name|regex_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

