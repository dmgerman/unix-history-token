begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Comma is not allowed in C89
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -E %s -std=c89 -pedantic-errors
end_comment

begin_comment
comment|// Comma is allowed if unevaluated in C99
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s -std=c99 -pedantic-errors
end_comment

begin_comment
comment|// PR2279
end_comment

begin_if
if|#
directive|if
literal|0
condition|?
literal|1
operator|,
literal|2
expr|:
literal|3
end_if

begin_endif
endif|#
directive|endif
end_endif

end_unit

