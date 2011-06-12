begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=i686-pc-linux-gnu -emit-llvm %s -o - | FileCheck %s --check-prefix=LINUX
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple=i686-apple-darwin9 -emit-llvm %s -o - | FileCheck %s --check-prefix=DARWIN
end_comment

begin_decl_stmt
name|char
modifier|*
name|strerror
argument_list|(
name|int
argument_list|)
name|asm
argument_list|(
literal|"alias"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test
parameter_list|(
name|void
parameter_list|)
block|{
name|strerror
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// LINUX: declare i8* @alias(i32)
end_comment

begin_comment
comment|// DARWIN: declare i8* @"\01alias"(i32)
end_comment

end_unit

