begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not clang-cc -E %s 2>&1 | grep 'invalid token at start of a preprocessor expression'
end_comment

begin_comment
comment|// RUN: not clang-cc -E %s 2>&1 | grep 'token is not a valid binary operator in a preprocessor subexpression'
end_comment

begin_comment
comment|// RUN: not clang-cc -E %s 2>&1 | grep ':14: error: expected end of line in preprocessor expression'
end_comment

begin_comment
comment|// PR2220
end_comment

begin_if
if|#
directive|if
literal|1
operator|*
operator|*
literal|2
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|4
index|[
literal|2
expr|#
name|endif
end_if

begin_comment
comment|// PR2284 - The constant-expr production does not including comma.
end_comment

begin_if
if|#
directive|if
literal|1
condition|?
literal|2
expr|:
literal|0
operator|,
literal|1
end_if

begin_endif
endif|#
directive|endif
end_endif

end_unit

