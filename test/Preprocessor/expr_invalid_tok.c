begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -E %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// PR2220
end_comment

begin_comment
comment|// CHECK: invalid token at start of a preprocessor expression
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

begin_comment
comment|// CHECK: token is not a valid binary operator in a preprocessor subexpression
end_comment

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

begin_comment
comment|// CHECK: [[@LINE+1]]:14: error: expected end of line in preprocessor expression
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

begin_comment
comment|// CHECK: [[@LINE+1]]:5: error: function-like macro 'FOO' is not defined
end_comment

begin_if
if|#
directive|if
name|FOO
argument_list|(
literal|1
operator|,
literal|2
operator|,
literal|3
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK: [[@LINE+1]]:9: error: function-like macro 'BAR' is not defined
end_comment

begin_if
if|#
directive|if
literal|1
operator|+
name|BAR
argument_list|(
literal|1
operator|,
literal|2
operator|,
literal|3
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK: [[@LINE+1]]:10: error: token is not a valid binary operator
end_comment

begin_if
if|#
directive|if
call|(
name|FOO
call|)
argument_list|(
literal|1
operator|,
literal|2
operator|,
literal|3
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

end_unit

