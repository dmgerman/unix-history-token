begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -E -x c -o %t %s
end_comment

begin_comment
comment|// RUN: grep 'IDENT.2' %t
end_comment

begin_expr_stmt
name|IDENT
literal|.2
end_expr_stmt

end_unit

