begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|__has_include_next
argument_list|(
operator|<
name|rewrite
operator|-
name|includes8
operator|.
name|h
operator|>
argument_list|)
end_if

begin_elif
elif|#
directive|elif
name|__has_include
argument_list|(
operator|<
name|rewrite
operator|-
name|includes8
operator|.
name|hfail
operator|>
argument_list|)
end_elif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|__has_include
argument_list|(
literal|"rewrite-includes8.h"
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

end_unit

