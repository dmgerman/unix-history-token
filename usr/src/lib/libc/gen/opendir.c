begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1982 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)opendir.c 1.1 %G%"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<ndir.h>
end_include

begin_comment
comment|/*  * open a directory.  */
end_comment

begin_function
name|DIR
modifier|*
name|opendir
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|DIR
modifier|*
name|dirp
decl_stmt|;
name|dirp
operator|=
operator|(
name|DIR
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|DIR
argument_list|)
argument_list|)
expr_stmt|;
name|dirp
operator|->
name|dd_fd
operator|=
name|open
argument_list|(
name|name
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|dirp
operator|->
name|dd_fd
operator|==
operator|-
literal|1
condition|)
block|{
name|free
argument_list|(
name|dirp
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|dirp
operator|->
name|dd_loc
operator|=
literal|0
expr_stmt|;
return|return
name|dirp
return|;
block|}
end_function

end_unit

