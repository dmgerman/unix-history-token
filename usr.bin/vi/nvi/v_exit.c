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
literal|"@(#)v_exit.c	8.5 (Berkeley) 12/10/93"
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"vi.h"
end_include

begin_include
include|#
directive|include
file|"excmd.h"
end_include

begin_include
include|#
directive|include
file|"vcmd.h"
end_include

begin_comment
comment|/*  * v_exit -- ZZ  *	Save the file and exit.  */
end_comment

begin_function
name|int
name|v_exit
parameter_list|(
name|sp
parameter_list|,
name|ep
parameter_list|,
name|vp
parameter_list|,
name|fm
parameter_list|,
name|tm
parameter_list|,
name|rp
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|EXF
modifier|*
name|ep
decl_stmt|;
name|VICMDARG
modifier|*
name|vp
decl_stmt|;
name|MARK
modifier|*
name|fm
decl_stmt|,
decl|*
name|tm
decl_stmt|,
modifier|*
name|rp
decl_stmt|;
end_function

begin_block
block|{
if|if
condition|(
name|F_ISSET
argument_list|(
name|ep
argument_list|,
name|F_MODIFIED
argument_list|)
operator|&&
name|file_write
argument_list|(
name|sp
argument_list|,
name|ep
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|FS_ALL
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* 	 * !!! 	 * Historic practice: quit! or two quit's done in succession 	 * (where ZZ counts as a quit) didn't check for other files. 	 * 	 * Also check for related screens; if they exist, quit, the 	 * user will get the message on the last screen. 	 */
if|if
condition|(
name|sp
operator|->
name|ccnt
operator|!=
name|sp
operator|->
name|q_ccnt
operator|+
literal|1
operator|&&
name|ep
operator|->
name|refcnt
operator|<=
literal|1
operator|&&
name|file_unedited
argument_list|(
name|sp
argument_list|)
operator|!=
name|NULL
condition|)
block|{
name|sp
operator|->
name|q_ccnt
operator|=
name|sp
operator|->
name|ccnt
expr_stmt|;
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_ERR
argument_list|,
literal|"More files to edit; use \":n\" to go to the next file"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|F_SET
argument_list|(
name|sp
argument_list|,
name|S_EXIT
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

