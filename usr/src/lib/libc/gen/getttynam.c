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
literal|"@(#)getttynam.c	5.2 (Berkeley) 3/9/86"
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
file|<ttyent.h>
end_include

begin_function
name|struct
name|ttyent
modifier|*
name|getttynam
parameter_list|(
name|tty
parameter_list|)
name|char
modifier|*
name|tty
decl_stmt|;
block|{
specifier|register
name|struct
name|ttyent
modifier|*
name|t
decl_stmt|;
name|setttyent
argument_list|()
expr_stmt|;
while|while
condition|(
name|t
operator|=
name|getttyent
argument_list|()
condition|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|tty
argument_list|,
name|t
operator|->
name|ty_name
argument_list|)
operator|==
literal|0
condition|)
break|break;
block|}
name|endttyent
argument_list|()
expr_stmt|;
return|return
operator|(
name|t
operator|)
return|;
block|}
end_function

end_unit

