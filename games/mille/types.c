begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)types.c	8.1 (Berkeley) 5/31/93";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
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
file|"mille.h"
end_include

begin_comment
comment|/*  * @(#)types.c	1.1 (Berkeley) 4/1/82  */
end_comment

begin_function
name|int
name|isrepair
parameter_list|(
name|card
parameter_list|)
name|CARD
name|card
decl_stmt|;
block|{
return|return
name|card
operator|==
name|C_GAS
operator|||
name|card
operator|==
name|C_SPARE
operator|||
name|card
operator|==
name|C_REPAIRS
operator|||
name|card
operator|==
name|C_INIT
return|;
block|}
end_function

begin_function
name|CARD
name|safety
parameter_list|(
name|card
parameter_list|)
name|CARD
name|card
decl_stmt|;
block|{
switch|switch
condition|(
name|card
condition|)
block|{
case|case
name|C_EMPTY
case|:
case|case
name|C_GAS
case|:
case|case
name|C_GAS_SAFE
case|:
return|return
name|C_GAS_SAFE
return|;
case|case
name|C_FLAT
case|:
case|case
name|C_SPARE
case|:
case|case
name|C_SPARE_SAFE
case|:
return|return
name|C_SPARE_SAFE
return|;
case|case
name|C_CRASH
case|:
case|case
name|C_REPAIRS
case|:
case|case
name|C_DRIVE_SAFE
case|:
return|return
name|C_DRIVE_SAFE
return|;
case|case
name|C_GO
case|:
case|case
name|C_STOP
case|:
case|case
name|C_RIGHT_WAY
case|:
case|case
name|C_LIMIT
case|:
case|case
name|C_END_LIMIT
case|:
return|return
name|C_RIGHT_WAY
return|;
block|}
comment|/* NOTREACHED */
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

