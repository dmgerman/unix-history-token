begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Michael Fischbein.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: util.c,v 1.8 1997/02/22 14:04:03 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
specifier|const
name|sccsid
index|[]
init|=
literal|"@(#)util.c	8.3 (Berkeley) 4/2/94"
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
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<fts.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"ls.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_function
name|void
name|prcopy
parameter_list|(
name|src
parameter_list|,
name|dest
parameter_list|,
name|len
parameter_list|)
name|char
modifier|*
name|src
decl_stmt|,
decl|*
name|dest
decl_stmt|;
end_function

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
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
operator|*
name|dest
operator|++
operator|=
name|isprint
argument_list|(
name|ch
argument_list|)
condition|?
name|ch
else|:
literal|'?'
expr_stmt|;
block|}
block|}
end_block

begin_function
name|void
name|usage
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|BSD4_4_LITE
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: ls [-1ACFLRTacdfiklqrstu] [file ...]\n"
argument_list|)
expr_stmt|;
else|#
directive|else
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: ls [-ACFLRTWacdfgikloqrstu1] [file ...]\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

