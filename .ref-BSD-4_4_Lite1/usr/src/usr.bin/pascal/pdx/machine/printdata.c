begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)printdata.c	8.1 (Berkeley) 6/6/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * print contents of data addresses in octal  *  * There are two entries:  one is given a range of addresses,  * the other is given a count and a starting address.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"machine.h"
end_include

begin_include
include|#
directive|include
file|"process.h"
end_include

begin_include
include|#
directive|include
file|"object.h"
end_include

begin_include
include|#
directive|include
file|"process/process.rep"
end_include

begin_include
include|#
directive|include
file|"process/pxinfo.h"
end_include

begin_define
define|#
directive|define
name|WORDSPERLINE
value|4
end_define

begin_comment
comment|/*  * print words from lowaddr to highaddr  */
end_comment

begin_macro
name|printdata
argument_list|(
argument|lowaddr
argument_list|,
argument|highaddr
argument_list|)
end_macro

begin_decl_stmt
name|ADDRESS
name|lowaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDRESS
name|highaddr
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|count
decl_stmt|;
specifier|register
name|ADDRESS
name|addr
decl_stmt|;
name|int
name|val
decl_stmt|;
if|if
condition|(
name|lowaddr
operator|>
name|highaddr
condition|)
block|{
name|error
argument_list|(
literal|"first address larger than second"
argument_list|)
expr_stmt|;
block|}
name|count
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|addr
operator|=
name|lowaddr
init|;
name|addr
operator|<=
name|highaddr
condition|;
name|addr
operator|+=
sizeof|sizeof
argument_list|(
name|int
argument_list|)
control|)
block|{
if|if
condition|(
name|count
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"%8x: "
argument_list|,
name|addr
argument_list|)
expr_stmt|;
block|}
name|dread
argument_list|(
operator|&
name|val
argument_list|,
name|addr
argument_list|,
sizeof|sizeof
argument_list|(
name|val
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  %8x"
argument_list|,
name|val
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|count
operator|>=
name|WORDSPERLINE
condition|)
block|{
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
name|count
operator|=
literal|0
expr_stmt|;
block|}
block|}
if|if
condition|(
name|count
operator|!=
literal|0
condition|)
block|{
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

