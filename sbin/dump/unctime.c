begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
unit|static char sccsid[] = "@(#)unctime.c	8.2 (Berkeley) 6/14/94";
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
file|<time.h>
end_include

begin_comment
comment|/*  * Convert a ctime(3) format string into a system format date.  * Return the date thus calculated.  *  * Return -1 if the string is not in ctime format.  */
end_comment

begin_function
name|time_t
name|unctime
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
block|{
name|struct
name|tm
name|then
decl_stmt|;
name|str
operator|=
name|strptime
argument_list|(
name|str
argument_list|,
literal|"%a %b %e %T %Y"
argument_list|,
operator|&
name|then
argument_list|)
expr_stmt|;
if|if
condition|(
name|str
operator|==
name|NULL
operator|||
operator|(
operator|*
name|str
operator|!=
literal|'\n'
operator|&&
operator|*
name|str
operator|!=
literal|'\0'
operator|)
condition|)
return|return
operator|(
operator|(
name|time_t
operator|)
operator|-
literal|1
operator|)
return|;
name|then
operator|.
name|tm_isdst
operator|=
operator|-
literal|1
expr_stmt|;
return|return
operator|(
name|mktime
argument_list|(
operator|&
name|then
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

