begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* template.h */
end_comment

begin_comment
comment|/* all .h's that link for move to .. as config.h    should have the following form */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_H
value|1
end_define

begin_expr_stmt
operator|...
name|non
expr|default
name|defines
operator|...
end_expr_stmt

begin_include
include|#
directive|include
file|"config/Idefault.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_H  */
end_comment

end_unit

