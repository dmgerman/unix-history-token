begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|dirent
name|entry
decl_stmt|;
return|return
operator|(
sizeof|sizeof
argument_list|(
name|entry
operator|.
name|d_namlen
argument_list|)
operator|==
literal|0
operator|)
return|;
block|}
end_function

end_unit

