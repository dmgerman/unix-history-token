begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.1 $ ** */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/* **  Call mknod(2) to make a fifo. */
end_comment

begin_function
name|int
name|mkfifo
parameter_list|(
name|path
parameter_list|,
name|mode
parameter_list|)
name|char
modifier|*
name|path
decl_stmt|;
name|int
name|mode
decl_stmt|;
block|{
return|return
name|mknod
argument_list|(
name|path
argument_list|,
name|S_IFIFO
operator||
name|mode
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

end_unit

