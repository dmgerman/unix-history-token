begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_else
unit|static char sccsid[] = "@(#)getent.c	8.2 (Berkeley) 12/15/93";
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|area
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|getent
argument_list|(
argument|cp
argument_list|,
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|HAS_CGETENT
name|char
modifier|*
name|dba
index|[
literal|2
index|]
decl_stmt|;
name|dba
index|[
literal|0
index|]
operator|=
literal|"/etc/gettytab"
expr_stmt|;
name|dba
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
return|return
operator|(
operator|(
name|cgetent
argument_list|(
operator|&
name|area
argument_list|,
name|dba
argument_list|,
name|name
argument_list|)
operator|==
literal|0
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
block|}
end_block

begin_ifndef
ifndef|#
directive|ifndef
name|SOLARIS
end_ifndef

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|char
modifier|*
name|Getstr
parameter_list|(
name|id
parameter_list|,
name|cpp
parameter_list|)
name|char
modifier|*
name|id
decl_stmt|,
decl|*
modifier|*
name|cpp
decl_stmt|;
end_function

begin_block
block|{
ifdef|#
directive|ifdef
name|HAS_CGETENT
name|char
modifier|*
name|answer
decl_stmt|;
return|return
operator|(
operator|(
name|cgetstr
argument_list|(
name|area
argument_list|,
name|id
argument_list|,
operator|&
name|answer
argument_list|)
operator|>
literal|0
operator|)
condition|?
name|answer
else|:
literal|0
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

