begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Michael Fischbein.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)util.c	5.8 (Berkeley) 7/22/90"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header: /a/cvs/386BSD/src/bin/ls/util.c,v 1.2 1993/06/29 02:59:34 nate Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_expr_stmt
name|prcopy
argument_list|(
name|src
argument_list|,
name|dest
argument_list|,
name|len
argument_list|)
specifier|register
name|char
operator|*
name|src
operator|,
operator|*
name|dest
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|unsigned
name|char
name|ch
decl_stmt|;
while|while
condition|(
name|len
operator|--
condition|)
block|{
name|ch
operator|=
operator|*
name|src
operator|++
expr_stmt|;
comment|/* XXX: 		 * because *BSD don't have setlocale() (yet) 		 * here simple hack that allows ISO8859-x 		 * and koi8-r charsets in terminal mode. 		 * Note: range 0x80-0x9F skipped to avoid 		 * some kinda security hole on poor DEC VTs 		 */
operator|*
name|dest
operator|++
operator|=
operator|(
name|ch
operator|>=
literal|0xA0
operator|||
name|isprint
argument_list|(
name|ch
argument_list|)
operator|)
condition|?
name|ch
else|:
literal|'?'
expr_stmt|;
block|}
block|}
end_block

begin_function
name|char
modifier|*
name|emalloc
parameter_list|(
name|size
parameter_list|)
name|u_int
name|size
decl_stmt|;
block|{
name|char
modifier|*
name|retval
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|retval
operator|=
name|malloc
argument_list|(
name|size
argument_list|)
operator|)
condition|)
name|nomem
argument_list|()
expr_stmt|;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_macro
name|nomem
argument_list|()
end_macro

begin_block
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ls: out of memory.\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|usage
argument_list|()
end_macro

begin_block
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: ls [-1ACFLRTacdfgiklqrstu] [file ...]\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

