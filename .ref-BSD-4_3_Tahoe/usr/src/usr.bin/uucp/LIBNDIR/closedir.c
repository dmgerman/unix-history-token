begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)closedir.c 4.2 3/10/82"
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
comment|/*  * close a directory.  */
end_comment

begin_function
name|void
name|closedir
parameter_list|(
name|dirp
parameter_list|)
specifier|register
name|DIR
modifier|*
name|dirp
decl_stmt|;
block|{
name|close
argument_list|(
name|dirp
operator|->
name|dd_fd
argument_list|)
expr_stmt|;
name|dirp
operator|->
name|dd_fd
operator|=
operator|-
literal|1
expr_stmt|;
name|dirp
operator|->
name|dd_loc
operator|=
literal|0
expr_stmt|;
name|free
argument_list|(
name|dirp
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

