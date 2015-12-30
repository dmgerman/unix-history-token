begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Include the headers we use in int_lib.h, to verify that they work. */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|// Force us to link at least one symbol in a system library
end_comment

begin_comment
comment|// to detect systems where we don't have those for a given
end_comment

begin_comment
comment|// architecture.
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
name|memcpy
argument_list|(
operator|&
name|x
argument_list|,
operator|&
name|argc
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

