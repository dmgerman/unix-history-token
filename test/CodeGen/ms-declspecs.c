begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-win32 %s -emit-llvm -fms-compatibility -O2 -disable-llvm-passes -o - | FileCheck %s
end_comment

begin_macro
name|__declspec
argument_list|(
argument|selectany
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x1
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|__declspec
argument_list|(
argument|selectany
argument_list|)
name|int
name|x2
operator|=
literal|2
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK: @x1 = weak_odr global i32 1, comdat, align 4
end_comment

begin_comment
comment|// CHECK: @x2 = weak_odr constant i32 2, comdat, align 4
end_comment

begin_comment
comment|// selectany turns extern variable declarations into definitions.
end_comment

begin_macro
name|__declspec
argument_list|(
argument|selectany
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x3
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern __declspec(selectany
end_extern

begin_decl_stmt
unit|)
name|int
name|x4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @x3 = weak_odr global i32 0, comdat, align 4
end_comment

begin_comment
comment|// CHECK: @x4 = weak_odr global i32 0, comdat, align 4
end_comment

begin_struct
struct|struct
name|__declspec
argument_list|(
argument|align(
literal|16
argument|)
argument_list|)
name|S
block|{
name|char
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
block|{
name|struct
name|S
name|s
decl_stmt|;
block|}
name|u
union|;
end_union

begin_comment
comment|// CHECK: @u = {{.*}}zeroinitializer, align 16
end_comment

begin_comment
comment|// CHECK: define void @t3() [[NAKED:#[0-9]+]] {
end_comment

begin_macro
name|__declspec
argument_list|(
argument|naked
argument_list|)
end_macro

begin_function
name|void
name|t3
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: define void @t22() [[NUW:#[0-9]+]]
end_comment

begin_function_decl
name|void
name|__declspec
parameter_list|(
name|nothrow
parameter_list|)
function_decl|t22
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|t22
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: define void @t2() [[NI:#[0-9]+]] {
end_comment

begin_macro
name|__declspec
argument_list|(
argument|noinline
argument_list|)
end_macro

begin_function
name|void
name|t2
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: call void @f20_t() [[NR:#[0-9]+]]
end_comment

begin_macro
name|__declspec
argument_list|(
argument|noreturn
argument_list|)
end_macro

begin_function_decl
name|void
name|f20_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f20
parameter_list|(
name|void
parameter_list|)
block|{
name|f20_t
argument_list|()
expr_stmt|;
block|}
end_function

begin_macro
name|__declspec
argument_list|(
argument|noalias
argument_list|)
end_macro

begin_function_decl
name|void
name|noalias_callee
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: call void @noalias_callee({{.*}}) [[NA:#[0-9]+]]
end_comment

begin_function
name|void
name|noalias_caller
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
block|{
name|noalias_callee
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: attributes [[NAKED]] = { naked noinline nounwind{{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[NUW]] = { nounwind{{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[NI]] = { noinline nounwind{{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[NR]] = { noreturn }
end_comment

begin_comment
comment|// CHECK: attributes [[NA]] = { argmemonly nounwind{{.*}} }
end_comment

end_unit

