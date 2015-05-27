begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|STRESS1_M01_H
end_ifndef

begin_define
define|#
directive|define
name|STRESS1_M01_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_comment
comment|// Trigger the use of special members for a class this is also defined in other
end_comment

begin_comment
comment|// modules.
end_comment

begin_expr_stmt
specifier|inline
name|N00
operator|::
name|S01
name|m01_special_members
argument_list|()
block|{
return|return
name|N00
operator|::
name|S01
argument_list|()
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

