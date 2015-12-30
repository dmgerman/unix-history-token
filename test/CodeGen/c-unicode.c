begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang --target=x86_64--linug-gnu -S %s -o - | FileCheck %s -check-prefix=ALLOWED
end_comment

begin_comment
comment|// RUN: not %clang --target=x86_64--linux-gnu -std=c89 -S %s -o - 2>&1 | FileCheck %s -check-prefix=DENIED
end_comment

begin_expr_stmt
name|int
operator|\
name|uaccess
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|// ALLOWED: "ê³ss":
end_comment

begin_comment
comment|// ALLOWED-NOT: "\uaccess":
end_comment

begin_comment
comment|// DENIED: warning: universal character names are only valid in C99 or C++; treating as '\' followed by identifier [-Wunicode]
end_comment

begin_comment
comment|// DENIED: error: expected identifier or '('
end_comment

end_unit

