begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -emit-llvm -o - %s | FileCheck %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|push
name|(
name|hidden
name|)
end_pragma

begin_decl_stmt
name|int
name|x
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @x = hidden global
end_comment

begin_decl_stmt
specifier|extern
name|int
name|y
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|pop
end_pragma

begin_decl_stmt
name|int
name|y
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @y = hidden global
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|push
name|(
name|hidden
name|)
end_pragma

begin_extern
extern|extern __attribute((visibility(
literal|"default"
end_extern

begin_decl_stmt
unit|)))
name|int
name|z
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|z
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @z = global
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|pop
end_pragma

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|push
name|(
name|hidden
name|)
end_pragma

begin_function
name|void
name|f
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define hidden void @f
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(visibility(
literal|"default"
argument|))
argument_list|)
end_macro

begin_function_decl
name|void
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|g
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @g
end_comment

end_unit

