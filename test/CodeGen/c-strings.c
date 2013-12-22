begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Should be 3 hello strings, two global (of different sizes), the rest are
end_comment

begin_comment
comment|// shared.
end_comment

begin_comment
comment|// CHECK: @align = global i8 [[ALIGN:[0-9]+]]
end_comment

begin_comment
comment|// CHECK: @.str = private unnamed_addr constant [6 x i8] c"hello\00"
end_comment

begin_comment
comment|// CHECK: @f1.x = internal global i8* getelementptr inbounds ([6 x i8]* @.str, i32 0, i32 0)
end_comment

begin_comment
comment|// CHECK: @f2.x = internal global [6 x i8] c"hello\00", align [[ALIGN]]
end_comment

begin_comment
comment|// CHECK: @f3.x = internal global [8 x i8] c"hello\00\00\00", align [[ALIGN]]
end_comment

begin_comment
comment|// CHECK: @f4.x = internal global %struct.s { i8* getelementptr inbounds ([6 x i8]* @.str, i32 0, i32 0) }
end_comment

begin_comment
comment|// CHECK: @x = global [3 x i8] c"ola", align [[ALIGN]]
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__s390x__
argument_list|)
end_if

begin_decl_stmt
name|unsigned
name|char
name|align
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|unsigned
name|char
name|align
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|bar
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: define void @f0()
end_comment

begin_function
name|void
name|f0
parameter_list|()
block|{
name|bar
argument_list|(
literal|"hello"
argument_list|)
expr_stmt|;
comment|// CHECK: call void @bar({{.*}} @.str
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f1()
end_comment

begin_function
name|void
name|f1
parameter_list|()
block|{
specifier|static
name|char
modifier|*
name|x
init|=
literal|"hello"
decl_stmt|;
name|bar
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: [[T1:%.*]] = load i8** @f1.x
comment|// CHECK: call void @bar(i8* [[T1:%.*]])
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f2()
end_comment

begin_function
name|void
name|f2
parameter_list|()
block|{
specifier|static
name|char
name|x
index|[]
init|=
literal|"hello"
decl_stmt|;
name|bar
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call void @bar({{.*}} @f2.x
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f3()
end_comment

begin_function
name|void
name|f3
parameter_list|()
block|{
specifier|static
name|char
name|x
index|[
literal|8
index|]
init|=
literal|"hello"
decl_stmt|;
name|bar
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call void @bar({{.*}} @f3.x
block|}
end_function

begin_function_decl
name|void
name|gaz
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: define void @f4()
end_comment

begin_function
name|void
name|f4
parameter_list|()
block|{
specifier|static
struct|struct
name|s
block|{
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|x
init|=
block|{
literal|"hello"
block|}
struct|;
name|gaz
argument_list|(
operator|&
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: call void @gaz({{.*}} @f4.x
block|}
end_function

begin_decl_stmt
name|char
name|x
index|[
literal|3
index|]
init|=
literal|"ola"
decl_stmt|;
end_decl_stmt

end_unit

