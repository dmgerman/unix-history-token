begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<clean-one.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function
name|unsigned
name|int
name|another_method
parameter_list|()
block|{
name|unsigned
name|int
specifier|const
name|size
init|=
name|do_nothing_loop
argument_list|()
decl_stmt|;
name|unsigned
name|int
specifier|const
name|square
init|=
name|size
operator|*
name|size
decl_stmt|;
return|return
name|square
return|;
block|}
end_function

end_unit

