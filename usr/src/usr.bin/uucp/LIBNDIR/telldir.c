begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)telldir.c 4.1 2/21/82"
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

begin_function_decl
specifier|extern
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* needed for pdp 11s -- ikonas!mcm */
end_comment

begin_comment
comment|/*  * return a pointer into a directory  */
end_comment

begin_function
name|long
name|telldir
parameter_list|(
name|dirp
parameter_list|)
name|DIR
modifier|*
name|dirp
decl_stmt|;
block|{
return|return
operator|(
name|lseek
argument_list|(
name|dirp
operator|->
name|dd_fd
argument_list|,
literal|0L
argument_list|,
literal|1
argument_list|)
operator|-
name|dirp
operator|->
name|dd_size
operator|+
name|dirp
operator|->
name|dd_loc
operator|)
return|;
block|}
end_function

end_unit

