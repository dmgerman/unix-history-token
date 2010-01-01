begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -trigraphs %s | grep -- ' ->'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -trigraphs %s 2>&1 | grep 'backslash and newline separated by space'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -trigraphs %s 2>&1 | grep 'trigraph converted'
end_comment

begin_comment
comment|// This is an ugly way to spell a -> token.
end_comment

begin_expr_stmt
operator|-
operator|??
operator|/
operator|>
end_expr_stmt

end_unit

