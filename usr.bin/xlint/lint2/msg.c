begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: msg.c,v 1.6 2002/01/21 19:49:52 tv Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Jochen Pohl  * All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jochen Pohl for  *	The NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__RCSID
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: msg.c,v 1.6 2002/01/21 19:49:52 tv Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"lint2.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|msgs
index|[]
init|=
block|{
literal|"%s used( %s ), but not defined"
block|,
comment|/* 0 */
literal|"%s defined( %s ), but never used"
block|,
comment|/* 1 */
literal|"%s declared( %s ), but never used or defined"
block|,
comment|/* 2 */
literal|"%s multiply defined  \t%s  ::  %s"
block|,
comment|/* 3 */
literal|"%s value used inconsistently  \t%s  ::  %s"
block|,
comment|/* 4 */
literal|"%s value declared inconsistently  \t%s  ::  %s"
block|,
comment|/* 5 */
literal|"%s, arg %d used inconsistently  \t%s  ::  %s"
block|,
comment|/* 6 */
literal|"%s: variable # of args  \t%s  ::  %s"
block|,
comment|/* 7 */
literal|"%s returns value which is always ignored"
block|,
comment|/* 8 */
literal|"%s returns value which is sometimes ignored"
block|,
comment|/* 9 */
literal|"%s value is used( %s ), but none returned"
block|,
comment|/* 10 */
literal|"%s, arg %d declared inconsistently  \t%s :: %s"
block|,
comment|/* 11 */
literal|"%s: variable # of args declared  \t%s  ::  %s"
block|,
comment|/* 12 */
literal|"%s: malformed format string  \t%s"
block|,
comment|/* 13 */
literal|"%s, arg %d inconsistent with format  \t%s"
block|,
comment|/* 14 */
literal|"%s: too few args for format  \t%s"
block|,
comment|/* 15 */
literal|"%s: too many args for format  \t%s"
block|,
comment|/* 16 */
literal|"%s function value must be declared before use  \t%s  ::  %s"
block|,
comment|/* 17 */
literal|"%s renamed multiple times  \t%s  ::  %s"
block|,
comment|/* 18 */
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
specifier|const
name|char
modifier|*
name|lbasename
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|msg
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|n
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|vprintf
argument_list|(
name|msgs
index|[
name|n
index|]
argument_list|,
name|ap
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Return a pointer to the last component of a path.  */
end_comment

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|lbasename
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|cp1
decl_stmt|,
modifier|*
name|cp2
decl_stmt|;
if|if
condition|(
name|Fflag
condition|)
return|return
operator|(
name|path
operator|)
return|;
name|cp
operator|=
name|cp1
operator|=
name|cp2
operator|=
name|path
expr_stmt|;
while|while
condition|(
operator|*
name|cp
operator|!=
literal|'\0'
condition|)
block|{
if|if
condition|(
operator|*
name|cp
operator|++
operator|==
literal|'/'
condition|)
block|{
name|cp2
operator|=
name|cp1
expr_stmt|;
name|cp1
operator|=
name|cp
expr_stmt|;
block|}
block|}
return|return
operator|(
operator|*
name|cp1
operator|==
literal|'\0'
condition|?
name|cp2
else|:
name|cp1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Create a string which describes a position in a source file.  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|mkpos
parameter_list|(
name|pos_t
modifier|*
name|posp
parameter_list|)
block|{
name|size_t
name|len
decl_stmt|;
specifier|const
name|char
modifier|*
name|fn
decl_stmt|;
specifier|static
name|char
modifier|*
name|buf
decl_stmt|;
specifier|static
name|size_t
name|blen
init|=
literal|0
decl_stmt|;
name|int
name|qm
decl_stmt|,
name|src
decl_stmt|,
name|line
decl_stmt|;
if|if
condition|(
name|Hflag
operator|&&
name|posp
operator|->
name|p_src
operator|!=
name|posp
operator|->
name|p_isrc
condition|)
block|{
name|src
operator|=
name|posp
operator|->
name|p_isrc
expr_stmt|;
name|line
operator|=
name|posp
operator|->
name|p_iline
expr_stmt|;
block|}
else|else
block|{
name|src
operator|=
name|posp
operator|->
name|p_src
expr_stmt|;
name|line
operator|=
name|posp
operator|->
name|p_line
expr_stmt|;
block|}
name|qm
operator|=
operator|!
name|Hflag
operator|&&
name|posp
operator|->
name|p_src
operator|!=
name|posp
operator|->
name|p_isrc
expr_stmt|;
name|len
operator|=
name|strlen
argument_list|(
name|fn
operator|=
name|lbasename
argument_list|(
name|fnames
index|[
name|src
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|len
operator|+=
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|u_short
argument_list|)
operator|+
literal|4
expr_stmt|;
if|if
condition|(
name|len
operator|>
name|blen
condition|)
name|buf
operator|=
name|xrealloc
argument_list|(
name|buf
argument_list|,
name|blen
operator|=
name|len
argument_list|)
expr_stmt|;
if|if
condition|(
name|line
operator|!=
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s(%hu)"
argument_list|,
name|fn
argument_list|,
name|qm
condition|?
literal|"?"
else|:
literal|""
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s"
argument_list|,
name|fn
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|buf
operator|)
return|;
block|}
end_function

end_unit

