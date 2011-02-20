begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple powerpc-apple-darwin -emit-llvm -o - %s| FileCheck -check-prefix=DARWINPPC-CHECK %s
end_comment

begin_decl_stmt
name|int
name|boolsize
init|=
sizeof|sizeof
argument_list|(
name|_Bool
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//DARWINPPC-CHECK: boolsize = global i32 4, align 4
end_comment

end_unit

