begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -ast-print -fms-extensions | FileCheck %s
end_comment

begin_comment
comment|// CHECK: int x __attribute__((aligned(4)));
end_comment

begin_decl_stmt
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|4
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// FIXME: Print this at a valid location for a __declspec attr.
end_comment

begin_comment
comment|// CHECK: int y __declspec(align(4));
end_comment

begin_macro
name|__declspec
argument_list|(
argument|align(
literal|4
argument|)
argument_list|)
end_macro

begin_decl_stmt
name|int
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: void foo() __attribute__((const));
end_comment

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: void bar() __attribute__((__const));
end_comment

begin_function_decl
name|void
name|bar
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(__const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// FIXME: Print these at a valid location for these attributes.
end_comment

begin_comment
comment|// CHECK: int *p32 __ptr32;
end_comment

begin_decl_stmt
name|int
modifier|*
name|__ptr32
name|p32
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: int *p64 __ptr64;
end_comment

begin_decl_stmt
name|int
modifier|*
name|__ptr64
name|p64
decl_stmt|;
end_decl_stmt

end_unit

