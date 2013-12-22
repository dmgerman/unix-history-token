begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fvisibility hidden "-triple" "x86_64-apple-darwin8.0.0" -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-10_4 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fvisibility hidden "-triple" "x86_64-apple-darwin9.0.0" -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-10_5 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fvisibility hidden "-triple" "x86_64-apple-darwin10.0.0" -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-10_6 %s
end_comment

begin_comment
comment|// CHECK-10_4-LABEL: define hidden void @f2
end_comment

begin_comment
comment|// CHECK-10_5-LABEL: define hidden void @f2
end_comment

begin_comment
comment|// CHECK-10_6-LABEL: define hidden void @f2
end_comment

begin_function_decl
name|void
name|f2
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|f2
parameter_list|()
block|{ }
end_function

begin_comment
comment|// CHECK-10_4-LABEL: define void @f3
end_comment

begin_comment
comment|// CHECK-10_5-LABEL: define void @f3
end_comment

begin_comment
comment|// CHECK-10_6-LABEL: define void @f3
end_comment

begin_function_decl
name|void
name|f3
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.5
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|f3
parameter_list|()
block|{ }
end_function

begin_comment
comment|// CHECK-10_4: declare extern_weak void @f0
end_comment

begin_comment
comment|// CHECK-10_5: declare void @f0
end_comment

begin_comment
comment|// CHECK-10_6: declare void @f0
end_comment

begin_function_decl
name|void
name|f0
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.5
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK-10_4: declare extern_weak void @f1
end_comment

begin_comment
comment|// CHECK-10_5: declare extern_weak void @f1
end_comment

begin_comment
comment|// CHECK-10_6: declare void @f1
end_comment

begin_function_decl
name|void
name|f1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.6
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test
parameter_list|()
block|{
name|f0
argument_list|()
expr_stmt|;
name|f1
argument_list|()
expr_stmt|;
name|f2
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

