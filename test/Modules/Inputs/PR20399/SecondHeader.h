begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|SECONDHEADER
end_ifndef

begin_define
define|#
directive|define
name|SECONDHEADER
end_define

begin_include
include|#
directive|include
file|"vector"
end_include

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|Address
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|Address
operator|<
name|std
operator|::
name|vector
operator|<
name|bool
operator|>>
operator|:
name|Address
operator|<
name|std
operator|::
name|vector
operator|<
name|bool
operator|>
operator|::
name|iterator
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

