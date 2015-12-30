begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"b.h"
end_include

begin_include
include|#
directive|include
file|"c.h"
end_include

begin_function
specifier|inline
name|void
name|g
parameter_list|()
block|{
name|f
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|int
name|h
parameter_list|()
block|{
return|return
name|n
return|;
block|}
end_function

end_unit

