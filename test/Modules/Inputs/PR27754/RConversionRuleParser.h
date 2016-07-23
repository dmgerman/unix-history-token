begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"algobase.h"
end_include

begin_typedef
typedef|typedef
name|integral_constant
operator|<
name|bool
operator|,
name|true
operator|>
name|true_type
expr_stmt|;
end_typedef

begin_decl_stmt
name|class
name|_Rb_tree
block|{
name|_Rb_tree
argument_list|()
block|{
name|true_type
argument_list|()
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_include
include|#
directive|include
file|"TSchemaType.h"
end_include

end_unit

