begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|B_H
end_ifndef

begin_define
define|#
directive|define
name|B_H
end_define

begin_include
include|#
directive|include
file|"a.h"
end_include

begin_expr_stmt
name|S
operator|<
name|int
operator|>
operator|*
name|s1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|T
operator|<
name|int
operator|>
operator|::
name|S
operator|*
name|s2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|T
operator|<
name|int
operator|>
operator|::
name|E
name|e1
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

