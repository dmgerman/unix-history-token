begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
unit|static char sccsid[] = "@(#)getcodi.c	8.1 (Berkeley) 5/31/93";
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
file|"getpar.h"
end_include

begin_comment
comment|/* **  get course and distance ** **	The user is asked for a course and distance.  This is used by **	move, impulse, and some of the computer functions. ** **	The return value is zero for success, one for an invalid input **	(meaning to drop the request). */
end_comment

begin_macro
name|getcodi
argument_list|(
argument|co
argument_list|,
argument|di
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|co
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
modifier|*
name|di
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|co
operator|=
name|getintpar
argument_list|(
literal|"Course"
argument_list|)
expr_stmt|;
comment|/* course must be in the interval [0, 360] */
if|if
condition|(
operator|*
name|co
operator|<
literal|0
operator|||
operator|*
name|co
operator|>
literal|360
condition|)
return|return
operator|(
literal|1
operator|)
return|;
operator|*
name|di
operator|=
name|getfltpar
argument_list|(
literal|"Distance"
argument_list|)
expr_stmt|;
comment|/* distance must be in the interval [0, 15] */
if|if
condition|(
operator|*
name|di
operator|<=
literal|0.0
operator|||
operator|*
name|di
operator|>
literal|15.0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* good return */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

