begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -S -emit-llvm -o - -O0 %s | FileCheck %s -check-prefix=O0
end_comment

begin_comment
comment|// RUN: %clang -S -emit-llvm -o - -O1 %s | FileCheck %s -check-prefix=O1
end_comment

begin_comment
comment|// RUN: %clang -S -emit-llvm -o - -O2 %s | FileCheck %s -check-prefix=O2
end_comment

begin_comment
comment|// RUN: %clang -S -emit-llvm -o - -O3 %s | FileCheck %s -check-prefix=O3
end_comment

begin_function_decl
specifier|extern
name|void
name|use
parameter_list|(
name|char
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__attribute__
argument_list|(
argument|(always_inline)
argument_list|)
end_macro

begin_function
name|void
name|helper_no_markers
parameter_list|()
block|{
name|char
name|a
decl_stmt|;
name|use
argument_list|(
operator|&
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|lifetime_test
parameter_list|()
block|{
comment|// O0: lifetime_test
comment|// O1: lifetime_test
comment|// O2: lifetime_test
comment|// O3: lifetime_test
comment|// O0-NOT: @llvm.lifetime.start
comment|// O1: @llvm.lifetime.start
comment|// O2: @llvm.lifetime.start
comment|// O3: @llvm.lifetime.start
name|helper_no_markers
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

