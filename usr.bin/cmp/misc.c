begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)misc.c	8.3 (Berkeley) 4/2/94"
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
file|<err.h>
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
file|"extern.h"
end_include

begin_function
name|void
name|eofmsg
parameter_list|(
name|file
parameter_list|)
name|char
modifier|*
name|file
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|sflag
condition|)
name|warnx
argument_list|(
literal|"EOF on %s"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|DIFF_EXIT
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|diffmsg
argument_list|(
name|file1
argument_list|,
name|file2
argument_list|,
name|byte
argument_list|,
name|line
argument_list|)
name|char
modifier|*
name|file1
decl_stmt|,
modifier|*
name|file2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|off_t
name|byte
decl_stmt|,
name|line
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|sflag
condition|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s %s differ: char %qd, line %qd\n"
argument_list|,
name|file1
argument_list|,
name|file2
argument_list|,
name|byte
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|DIFF_EXIT
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

