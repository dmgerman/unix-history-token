begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|namespace
name|N
block|{
name|template
operator|<
name|typename
operator|>
expr|struct
name|A
block|{
name|int
name|n
block|;
name|A
argument_list|()
operator|:
name|n
argument_list|()
block|{}
block|}
expr_stmt|;
comment|// Trigger instantiation of definition of A<int>.
struct|struct
name|C
block|{
name|A
operator|<
name|int
operator|>
name|a
expr_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// Merge in another declaration and update records.
end_comment

begin_include
include|#
directive|include
file|"b1.h"
end_include

end_unit

