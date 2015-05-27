begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|namespace
name|N
block|{
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|A
block|{
name|friend
name|int
name|f
argument_list|(
name|A
argument_list|)
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// It would seem like this variable should be called 'c'.
end_comment

begin_comment
comment|// But that makes the original problem disappear...
end_comment

begin_decl_stmt
name|int
name|e
init|=
name|f
argument_list|(
name|N
operator|::
name|A
operator|<
name|int
operator|>
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

end_unit

