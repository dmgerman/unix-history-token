begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)cuserid.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
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

begin_function
name|char
modifier|*
name|cuserid
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
specifier|register
name|struct
name|passwd
modifier|*
name|pwd
decl_stmt|;
if|if
condition|(
operator|(
name|pwd
operator|=
name|getpwuid
argument_list|(
name|geteuid
argument_list|()
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|s
condition|)
operator|*
name|s
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|s
operator|)
return|;
block|}
if|if
condition|(
name|s
condition|)
block|{
operator|(
name|void
operator|)
name|strncpy
argument_list|(
name|s
argument_list|,
name|pwd
operator|->
name|pw_name
argument_list|,
name|L_cuserid
argument_list|)
expr_stmt|;
return|return
operator|(
name|s
operator|)
return|;
block|}
return|return
operator|(
name|pwd
operator|->
name|pw_name
operator|)
return|;
block|}
end_function

end_unit

