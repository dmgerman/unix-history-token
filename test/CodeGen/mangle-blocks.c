begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-ios -fblocks -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function_decl
name|void
name|__assert_rtn
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|( noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_macro
name|void
argument_list|(
argument|^mangle(void)
argument_list|)
end_macro

begin_expr_stmt
operator|(
name|void
operator|)
block|{
return|return
lambda|^
block|{
name|void
function_decl|(
modifier|^
name|block
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
name|__assert_rtn
argument_list|(
name|__func__
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|,
literal|"mangle"
argument_list|)
function_decl|;
block|}
expr_stmt|;
end_expr_stmt

begin_comment
unit|}; }
comment|// CHECK: @__func__.__mangle_block_invoke_2 = private unnamed_addr constant [24 x i8] c"__mangle_block_invoke_2\00", align 1
end_comment

begin_comment
comment|// CHECK: @.str = private unnamed_addr constant {{.*}}, align 1
end_comment

begin_comment
comment|// CHECK: @.str1 = private unnamed_addr constant [7 x i8] c"mangle\00", align 1
end_comment

begin_comment
comment|// CHECK: define internal void @__mangle_block_invoke(i8* %.block_descriptor)
end_comment

begin_comment
comment|// CHECK: define internal void @__mangle_block_invoke_2(i8* %.block_descriptor){{.*}}{
end_comment

begin_comment
comment|// CHECK:   call void @__assert_rtn(i8* getelementptr inbounds ([24 x i8]* @__func__.__mangle_block_invoke_2, i32 0, i32 0), i8* getelementptr inbounds {{.*}}, i32 9, i8* getelementptr inbounds ([7 x i8]* @.str1, i32 0, i32 0))
end_comment

begin_comment
comment|// CHECK: }
end_comment

end_unit

