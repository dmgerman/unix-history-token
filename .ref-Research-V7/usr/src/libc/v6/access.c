begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_macro
name|access
argument_list|(
argument|name
argument_list|,
argument|mode
argument_list|)
end_macro

begin_block
block|{
name|struct
name|stat
name|foo
decl_stmt|;
return|return
operator|(
name|stat
argument_list|(
name|name
argument_list|,
operator|&
name|foo
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

