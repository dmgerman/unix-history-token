begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"quipu/util.h"
end_include

begin_include
include|#
directive|include
file|"quipu/name.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|AttrT_free
end_ifdef

begin_undef
undef|#
directive|undef
name|AttrT_free
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|AttrT_free
argument_list|(
name|x
argument_list|)
specifier|register
name|AttributeType
name|x
expr_stmt|;
end_expr_stmt

begin_block
block|{
empty_stmt|;
block|}
end_block

end_unit

