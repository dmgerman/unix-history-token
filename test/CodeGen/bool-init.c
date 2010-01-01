begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s | grep i1 | count 1
end_comment

begin_comment
comment|// Check that the type of this global isn't i1
end_comment

begin_decl_stmt
name|_Bool
name|test
init|=
operator|&
name|test
decl_stmt|;
end_decl_stmt

end_unit

