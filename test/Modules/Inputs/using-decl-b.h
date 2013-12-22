begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|namespace
name|UsingDecl
block|{
name|namespace
name|B
block|{
typedef|typedef
name|int
name|inner
typedef|;
block|}
name|using
name|B
operator|::
name|inner
expr_stmt|;
block|}
end_decl_stmt

begin_include
include|#
directive|include
file|"using-decl-a.h"
end_include

begin_decl_stmt
name|namespace
name|UsingDecl
block|{
name|using
operator|::
name|using_decl_type
expr_stmt|;
name|using
operator|::
name|using_decl_var
expr_stmt|;
block|}
end_decl_stmt

end_unit

