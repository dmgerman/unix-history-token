begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)getttyent.c	5.3 (Berkeley) 5/19/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<ttyent.h>
end_include

begin_function
name|main
parameter_list|()
block|{
name|struct
name|ttyent
modifier|*
name|t
decl_stmt|;
while|while
condition|(
name|t
operator|=
name|getttyent
argument_list|()
condition|)
block|{
name|printf
argument_list|(
literal|"name \"%s\", "
argument_list|,
name|t
operator|->
name|ty_name
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"getty \"%s\", "
argument_list|,
name|t
operator|->
name|ty_getty
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"type \"%s\", "
argument_list|,
name|t
operator|->
name|ty_type
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|->
name|ty_window
condition|)
name|printf
argument_list|(
literal|"window \"%s\", "
argument_list|,
name|t
operator|->
name|ty_window
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|->
name|ty_status
operator|&
name|TTY_ON
condition|)
name|printf
argument_list|(
literal|"on "
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|->
name|ty_status
operator|&
name|TTY_SECURE
condition|)
name|printf
argument_list|(
literal|"secure "
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|->
name|ty_comment
condition|)
name|printf
argument_list|(
literal|"comment \"%s\", "
argument_list|,
name|t
operator|->
name|ty_comment
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

