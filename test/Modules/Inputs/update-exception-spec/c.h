begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"a.h"
end_include

begin_include
include|#
directive|include
file|"b.h"
end_include

begin_function
specifier|inline
name|void
name|g
parameter_list|(
name|B
modifier|*
name|p
parameter_list|)
block|{
name|p
operator|->
expr|~
name|B
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

