begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)v_util.c	8.1 (Berkeley) 6/9/93"
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
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
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
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"vi.h"
end_include

begin_include
include|#
directive|include
file|"vcmd.h"
end_include

begin_comment
comment|/*  * v_eof --  *	Vi end-of-file error.  */
end_comment

begin_function
name|void
name|v_eof
parameter_list|(
name|sp
parameter_list|,
name|ep
parameter_list|,
name|mp
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|EXF
modifier|*
name|ep
decl_stmt|;
name|MARK
modifier|*
name|mp
decl_stmt|;
block|{
name|u_long
name|lno
decl_stmt|;
if|if
condition|(
name|mp
operator|==
name|NULL
condition|)
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_BERR
argument_list|,
literal|"Already at end-of-file."
argument_list|)
expr_stmt|;
else|else
block|{
if|if
condition|(
name|file_lline
argument_list|(
name|sp
argument_list|,
name|ep
argument_list|,
operator|&
name|lno
argument_list|)
condition|)
return|return;
if|if
condition|(
name|mp
operator|->
name|lno
operator|>=
name|lno
condition|)
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_BERR
argument_list|,
literal|"Already at end-of-file."
argument_list|)
expr_stmt|;
else|else
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_BERR
argument_list|,
literal|"Movement past the end-of-file."
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * v_eol --  *	Vi end-of-line error.  */
end_comment

begin_function
name|void
name|v_eol
parameter_list|(
name|sp
parameter_list|,
name|ep
parameter_list|,
name|mp
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|EXF
modifier|*
name|ep
decl_stmt|;
name|MARK
modifier|*
name|mp
decl_stmt|;
block|{
name|size_t
name|len
decl_stmt|;
if|if
condition|(
name|mp
operator|==
name|NULL
condition|)
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_BERR
argument_list|,
literal|"Already at end-of-line."
argument_list|)
expr_stmt|;
else|else
block|{
if|if
condition|(
name|file_gline
argument_list|(
name|sp
argument_list|,
name|ep
argument_list|,
name|mp
operator|->
name|lno
argument_list|,
operator|&
name|len
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|GETLINE_ERR
argument_list|(
name|sp
argument_list|,
name|mp
operator|->
name|lno
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|mp
operator|->
name|cno
operator|==
name|len
operator|-
literal|1
condition|)
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_BERR
argument_list|,
literal|"Already at end-of-line."
argument_list|)
expr_stmt|;
else|else
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_BERR
argument_list|,
literal|"Movement past the end-of-line."
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * v_sof --  *	Vi start-of-file error.  */
end_comment

begin_function
name|void
name|v_sof
parameter_list|(
name|sp
parameter_list|,
name|mp
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|MARK
modifier|*
name|mp
decl_stmt|;
block|{
if|if
condition|(
name|mp
operator|==
name|NULL
operator|||
name|mp
operator|->
name|lno
operator|==
literal|1
condition|)
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_BERR
argument_list|,
literal|"Already at the beginning of the file."
argument_list|)
expr_stmt|;
else|else
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_BERR
argument_list|,
literal|"Movement past the beginning of the file."
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

