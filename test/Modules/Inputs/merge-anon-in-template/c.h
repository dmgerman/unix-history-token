begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_floating
block|{   enum
block|{
name|value
operator|=
literal|0
block|}
block|;
typedef|typedef
name|int
name|type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_include
include|#
directive|include
file|"b.h"
end_include

begin_decl_stmt
name|bool
name|n20
init|=
name|is_floating
operator|<
name|int
operator|>
operator|::
name|value
decl_stmt|;
end_decl_stmt

end_unit

