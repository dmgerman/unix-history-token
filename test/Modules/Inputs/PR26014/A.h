begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_LIBCPP_TYPE_TRAITS
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_TYPE_TRAITS
end_define

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
expr|struct
name|underlying_type
block|{
typedef|typedef
name|__underlying_type
argument_list|(
argument|_Tp
argument_list|)
name|type
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_TYPE_TRAITS
end_comment

begin_include
include|#
directive|include
file|"B.h"
end_include

end_unit

