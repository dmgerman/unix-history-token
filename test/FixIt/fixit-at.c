begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fixit-at=fixit-at.c:3:1 %s -o - | clang-cc -verify -x c -
end_comment

begin_expr_stmt
specifier|_Complex
name|cd
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|i0
index|[
literal|1
index|]
init|=
block|{
block|{
literal|17
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{braces}}
end_comment

end_unit

