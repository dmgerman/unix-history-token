begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2000, Richard Sharpe  *  * This software may be distributed either under the terms of the   * BSD-style licence that accompanies tcpdump or under the GNU GPL   * version 2 or later.  *  * print-bxxp.c  *  */
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
name|rcsid
index|[]
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-bxxp.c,v 1.3 2000/10/05 04:10:01 itojun Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MEMORY_H
end_ifdef

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_comment
comment|/* Check for a string but not go beyond length  * Return TRUE on match, FALSE otherwise  *   * Looks at the first few chars up to tl1 ...  */
end_comment

begin_function_decl
name|int
name|l_strnstart
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|l_strnstart
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
name|tstr1
parameter_list|,
specifier|register
name|u_int
name|tl1
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
name|str2
parameter_list|,
specifier|register
name|u_int
name|l2
parameter_list|)
block|{
if|if
condition|(
name|tl1
operator|>
name|l2
condition|)
return|return
literal|0
return|;
return|return
operator|(
name|strncmp
argument_list|(
name|tstr1
argument_list|,
name|str2
argument_list|,
name|tl1
argument_list|)
operator|==
literal|0
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|bxxp_print
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|,
specifier|register
name|u_int
name|length
parameter_list|)
block|{
if|if
condition|(
name|l_strnstart
argument_list|(
literal|"REQ "
argument_list|,
literal|4
argument_list|,
name|bp
argument_list|,
name|length
argument_list|)
condition|)
block|{
comment|/* A REQuest */
name|printf
argument_list|(
literal|" BXXP REQ"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|l_strnstart
argument_list|(
literal|"RSP "
argument_list|,
literal|4
argument_list|,
name|bp
argument_list|,
name|length
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|" BXXP RSP"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|l_strnstart
argument_list|(
literal|"SEQ "
argument_list|,
literal|4
argument_list|,
name|bp
argument_list|,
name|length
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|" BXXP SEQ"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|l_strnstart
argument_list|(
literal|"END"
argument_list|,
literal|4
argument_list|,
name|bp
argument_list|,
name|length
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|" BXXP END"
argument_list|)
expr_stmt|;
block|}
else|else
name|printf
argument_list|(
literal|" BXXP (payload or undecoded)"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

