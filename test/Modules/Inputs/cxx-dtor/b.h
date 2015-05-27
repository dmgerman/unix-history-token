begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|X
block|{
name|X
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|X
argument_list|()
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
specifier|inline
name|X
operator|::
operator|~
name|X
argument_list|()
block|{}
end_expr_stmt

begin_include
include|#
directive|include
file|"a.h"
end_include

end_unit

