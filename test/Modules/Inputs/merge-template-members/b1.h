begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"a1.h"
end_include

begin_comment
comment|// Add update record for definition of A<int> and constructors.
end_comment

begin_comment
comment|// We need an eagerly-emitted use here to get the problematic
end_comment

begin_comment
comment|// deserialization ordering.
end_comment

begin_expr_stmt
name|N
operator|::
name|A
operator|<
name|int
operator|>
name|b1
expr_stmt|;
end_expr_stmt

end_unit

