begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"def-include.h"
end_include

begin_decl_stmt
unit|@
name|interface
name|A
block|{ @
name|public
name|int
name|ivar
decl_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|Def
operator|-
name|defMethod
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|@
name|end
ifdef|#
directive|ifdef
name|__cplusplus
name|class
name|Def2
block|{
name|public
label|:
name|void
name|func
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|namespace
name|Def3NS
block|{
name|class
name|Def3
block|{
name|public
label|:
name|void
name|func
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

