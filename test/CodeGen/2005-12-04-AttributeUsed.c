begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @llvm.used = appending global [2 x i8*] [i8* bitcast (void ()* @foo to i8*), i8* bitcast (i32* @X to i8*)], section "llvm.metadata"
end_comment

begin_decl_stmt
name|int
name|X
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Y
decl_stmt|;
end_decl_stmt

begin_macro
name|__attribute__
argument_list|(
argument|(used)
argument_list|)
end_macro

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

end_unit

