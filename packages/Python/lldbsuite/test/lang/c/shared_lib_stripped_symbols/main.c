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
name|main
parameter_list|()
block|{
name|struct
name|foo
modifier|*
name|my_foo_ptr
decl_stmt|;
name|my_foo_ptr
operator|=
name|GetMeAFoo
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"My sub foo has: %d.\n"
argument_list|,
name|GetMeASubFoo
argument_list|(
name|my_foo_ptr
argument_list|)
operator|->
name|sub_1
argument_list|)
expr_stmt|;
comment|// Set breakpoint 0 here.
return|return
literal|0
return|;
block|}
end_function

end_unit

