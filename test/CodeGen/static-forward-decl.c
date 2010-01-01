begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=i686-apple-darwin9 | grep "global i32 10"
end_comment

begin_decl_stmt
specifier|static
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|j
init|=
operator|&
name|i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|i
init|=
literal|10
decl_stmt|;
end_decl_stmt

end_unit

