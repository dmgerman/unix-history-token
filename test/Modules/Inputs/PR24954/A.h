begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"B.h"
end_include

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|Expr
block|{
name|public
operator|:
name|void
name|print
argument_list|(
argument|B::basic_ostream<char>& os
argument_list|)
block|{
name|os
operator|<<
name|B
operator|::
name|setw
argument_list|(
literal|42
argument_list|)
block|;
name|os
operator|<<
name|B
operator|::
name|endl
block|;   }
block|}
expr_stmt|;
end_expr_stmt

end_unit

