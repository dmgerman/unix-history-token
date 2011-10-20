begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: hidden global
end_comment

begin_decl_stmt
name|int
name|X
name|__attribute__
argument_list|(
operator|(
name|__visibility__
argument_list|(
literal|"hidden"
argument_list|)
operator|)
argument_list|)
init|=
literal|123
decl_stmt|;
end_decl_stmt

end_unit

