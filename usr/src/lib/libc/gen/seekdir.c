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
literal|"@(#)seekdir.c 1.1 %G%"
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
comment|/*  * reset a directory.  */
end_comment

begin_function
name|void
name|resetdir
parameter_list|(
name|dirp
parameter_list|)
name|DIR
modifier|*
name|dirp
decl_stmt|;
block|{
name|lseek
argument_list|(
name|dirp
operator|->
name|dd_fd
argument_list|,
operator|(
name|long
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|dirp
operator|->
name|dd_loc
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

