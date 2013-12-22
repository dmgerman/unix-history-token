begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-mingw32 -emit-llvm< %s | FileCheck %s
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
name|foo1
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllexport
operator|)
argument_list|)
name|foo1
argument_list|()
block|{}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define dllexport void @foo1
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllexport
operator|)
argument_list|)
name|foo2
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR6269
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|foo3
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function
name|void
name|foo3
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define dllexport void @foo3
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function_decl
name|void
name|foo4
parameter_list|()
function_decl|;
end_function_decl

end_unit

