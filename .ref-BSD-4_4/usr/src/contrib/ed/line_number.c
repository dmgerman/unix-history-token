begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rodney Ruddock of the University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)line_number.c	8.1 (Berkeley) 5/31/93"
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
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DBI
end_ifdef

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ed.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_comment
comment|/*  * Converts a LINE to a line number (int) that can be printed to  * the device the user is at. Used by n and =.  */
end_comment

begin_function
name|int
name|line_number
parameter_list|(
name|line_addr
parameter_list|)
name|LINE
modifier|*
name|line_addr
decl_stmt|;
block|{
name|LINE
modifier|*
name|l_temp1
decl_stmt|;
name|int
name|l_cnt
init|=
literal|1
decl_stmt|;
comment|/* yes! =1 */
name|l_temp1
operator|=
name|top
expr_stmt|;
if|if
condition|(
operator|(
name|line_addr
operator|==
name|NULL
operator|)
operator|&&
operator|(
name|top
operator|==
name|NULL
operator|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|line_addr
operator|==
name|l_temp1
condition|)
break|break;
name|l_temp1
operator|=
name|l_temp1
operator|->
name|below
expr_stmt|;
name|l_cnt
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|l_cnt
operator|)
return|;
block|}
end_function

end_unit

