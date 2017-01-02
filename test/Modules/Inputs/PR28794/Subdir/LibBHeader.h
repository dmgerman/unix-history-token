begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|LIB_B_HEADER
end_ifndef

begin_define
define|#
directive|define
name|LIB_B_HEADER
end_define

begin_include
include|#
directive|include
file|"LibAHeader.h"
end_include

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|size_t
name|SlabSize
operator|,
name|size_t
name|SizeThreshold
operator|>
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t
argument_list|,
argument|BumpPtrAllocatorImpl<T
argument_list|,
argument|SlabSize
argument_list|,
argument|SizeThreshold>&
argument_list|)
block|{   struct
name|S
block|{}
block|;
return|return
operator|(
name|void
operator|*
operator|)
literal|0xdead
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LIB_B_HEADER
end_comment

end_unit

