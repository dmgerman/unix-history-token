begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"a.h"
end_include

begin_struct
struct|struct
name|X
block|{
name|mutex
name|m
decl_stmt|;
name|int
name|n
name|__attribute__
argument_list|(
operator|(
name|guarded_by
argument_list|(
name|m
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|void
name|f
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

end_unit

