begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1988, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)mkdstoas.c	8.1 (Berkeley) 6/6/93"
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
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|unix
argument_list|)
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(unix) */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(unix) */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"../api/asc_ebc.h"
end_include

begin_include
include|#
directive|include
file|"../api/ebc_disp.h"
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
comment|/* For each display code, find the ascii code that matches */
name|printf
argument_list|(
literal|"unsigned char disp_asc[256] = {"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
name|disp_ebc
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|i
operator|%
literal|8
operator|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\t0x%02x,"
argument_list|,
name|ebc_asc
index|[
name|disp_ebc
index|[
name|i
index|]
index|]
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
sizeof|sizeof
name|disp_ebc
init|;
name|i
operator|<
literal|256
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|i
operator|%
literal|8
operator|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\t0x%02x,"
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n};\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

