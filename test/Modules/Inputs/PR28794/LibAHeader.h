begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|LIB_A_HEADER
end_ifndef

begin_define
define|#
directive|define
name|LIB_A_HEADER
end_define

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|size_t
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
operator|=
name|int
operator|,
name|size_t
name|SlabSize
operator|=
literal|4096
operator|,
name|size_t
operator|=
name|SlabSize
operator|>
name|class
name|BumpPtrAllocatorImpl
expr_stmt|;
end_expr_stmt

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
name|size_t
argument_list|,
name|BumpPtrAllocatorImpl
operator|<
name|T
argument_list|,
name|SlabSize
argument_list|,
name|SizeThreshold
operator|>
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LIB_A_HEADER
end_comment

end_unit

