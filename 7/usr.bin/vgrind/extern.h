begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      @(#)extern.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_typedef
typedef|typedef
name|int
name|boolean
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|boolean
name|_escaped
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if last character was an escape */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|s_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of the current string */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_acmbeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string introducing a comment */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_acmend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string ending a comment */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_blkbeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string begining of a block */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_blkend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string ending a block */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_chrbeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delimiter for character constant */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_chrend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delimiter for character constant */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_combeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string introducing a comment */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_comend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string ending a comment */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|l_escape
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* character used to escape characters */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_keywds
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keyword table address */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|l_onecase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* upper and lower case are equivalent */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_prcbeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* regular expr for procedure begin */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_strbeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delimiter for string constant */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_strend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delimiter for string constant */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|l_toplex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* procedures only defined at top lex level */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|language
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the language indicator */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|int
name|STRNCMP
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|convexp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|expmatch
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

end_unit

