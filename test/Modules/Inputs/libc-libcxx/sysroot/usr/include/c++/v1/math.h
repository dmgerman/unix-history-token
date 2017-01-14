begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|LIBCXX_MATH_H
end_ifndef

begin_define
define|#
directive|define
name|LIBCXX_MATH_H
end_define

begin_empty
empty|#include_next<math.h>
end_empty

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|abs
argument_list|(
argument|T t
argument_list|)
block|{
return|return
operator|(
name|t
operator|<
literal|0
operator|)
operator|?
operator|-
name|t
operator|:
name|t
return|;
block|}
end_expr_stmt

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

