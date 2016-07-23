begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_LIBCPP_ALGORITHM
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_ALGORITHM
end_define

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|_Tp
operator|>
expr|struct
name|integral_constant
block|{
specifier|static
specifier|const
name|_Tp
name|value
operator|=
name|_Tp
argument_list|()
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
expr|struct
name|is_nothrow_default_constructible
operator|:
name|integral_constant
operator|<
name|bool
operator|,
name|__is_constructible
argument_list|(
name|_Tp
argument_list|)
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
expr|struct
name|is_nothrow_move_constructible
operator|:
name|integral_constant
operator|<
name|bool
operator|,
name|__is_constructible
argument_list|(
name|_Tp
argument_list|,
name|_Tp
argument_list|)
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|class
name|allocator
block|{}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

