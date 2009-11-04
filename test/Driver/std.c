begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -std=c99 -trigraphs -std=gnu99 %s -E -o - | FileCheck -check-prefix=OVERRIDE %s&&
end_comment

begin_comment
comment|// OVERRIDE: ??(??)
end_comment

begin_comment
comment|// RUN: clang -ansi %s -E -o - | FileCheck -check-prefix=ANSI %s&&
end_comment

begin_comment
comment|// ANSI: []
end_comment

begin_comment
comment|// RUN: clang -std=gnu99 -trigraphs %s -E -o - | FileCheck -check-prefix=EXPLICIT %s
end_comment

begin_comment
comment|// EXPLICIT: []
end_comment

begin_expr_stmt
operator|??
operator|(
operator|??
operator|)
end_expr_stmt

end_unit

