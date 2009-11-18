begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @__func__.plainFunction = private constant [14 x i8] c"plainFunction\00"
end_comment

begin_comment
comment|// CHECK: @__PRETTY_FUNCTION__.plainFunction = private constant [21 x i8] c"void plainFunction()\00"
end_comment

begin_comment
comment|// CHECK: @__func__.externFunction = private constant [15 x i8] c"externFunction\00"
end_comment

begin_comment
comment|// CHECK: @__PRETTY_FUNCTION__.externFunction = private constant [22 x i8] c"void externFunction()\00"
end_comment

begin_comment
comment|// CHECK: @__func__.privateExternFunction = private constant [22 x i8] c"privateExternFunction\00"
end_comment

begin_comment
comment|// CHECK: @__PRETTY_FUNCTION__.privateExternFunction = private constant [29 x i8] c"void privateExternFunction()\00"
end_comment

begin_comment
comment|// CHECK: @__func__.staticFunction = private constant [15 x i8] c"staticFunction\00"
end_comment

begin_comment
comment|// CHECK: @__PRETTY_FUNCTION__.staticFunction = private constant [22 x i8] c"void staticFunction()\00"
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|plainFunction
parameter_list|()
block|{
name|printf
argument_list|(
literal|"__func__ %s\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"__FUNCTION__ %s\n"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"__PRETTY_FUNCTION__ %s\n\n"
argument_list|,
name|__PRETTY_FUNCTION__
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|extern
name|void
name|externFunction
parameter_list|()
block|{
name|printf
argument_list|(
literal|"__func__ %s\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"__FUNCTION__ %s\n"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"__PRETTY_FUNCTION__ %s\n\n"
argument_list|,
name|__PRETTY_FUNCTION__
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__private_extern__
name|void
name|privateExternFunction
parameter_list|()
block|{
name|printf
argument_list|(
literal|"__func__ %s\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"__FUNCTION__ %s\n"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"__PRETTY_FUNCTION__ %s\n\n"
argument_list|,
name|__PRETTY_FUNCTION__
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|staticFunction
parameter_list|()
block|{
name|printf
argument_list|(
literal|"__func__ %s\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"__FUNCTION__ %s\n"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"__PRETTY_FUNCTION__ %s\n\n"
argument_list|,
name|__PRETTY_FUNCTION__
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|plainFunction
argument_list|()
expr_stmt|;
name|externFunction
argument_list|()
expr_stmt|;
name|privateExternFunction
argument_list|()
expr_stmt|;
name|staticFunction
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

