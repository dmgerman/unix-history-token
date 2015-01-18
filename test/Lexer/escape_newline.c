begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -ftrigraphs %s | grep -- ' ->'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ftrigraphs %s 2>&1 | grep 'backslash and newline separated by space'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ftrigraphs %s 2>&1 | grep 'trigraph converted'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -CC -ftrigraphs %s
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

begin_comment
comment|// \
end_comment

end_unit

