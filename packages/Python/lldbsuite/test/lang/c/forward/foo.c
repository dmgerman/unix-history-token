begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"foo.h"
end_include

begin_function
name|int
name|foo
parameter_list|(
name|struct
name|bar
modifier|*
name|bar_ptr
parameter_list|)
block|{
return|return
name|printf
argument_list|(
literal|"bar_ptr = %p\n"
argument_list|,
name|bar_ptr
argument_list|)
return|;
block|}
end_function

end_unit

