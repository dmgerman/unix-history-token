begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_decl_stmt
name|int
name|c
index|[
literal|1
index|]
index|[
literal|3
operator|*
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @{{.+}} = {{.*}} global [1 x [6 x {{i[0-9]+}}]] zeroinitializer
end_comment

begin_comment
comment|// CHECK-LABEL: @f
end_comment

begin_decl_stmt
name|int
name|f
argument_list|(
name|int
operator|*
specifier|const
name|m
argument_list|,
name|int
argument_list|(
operator|*
operator|*
name|v
argument_list|)
index|[
operator|*
name|m
operator|*
literal|2
index|]
argument_list|)
block|{
return|return
operator|&
operator|(
name|c
index|[
literal|0
index|]
index|[
operator|*
name|m
index|]
operator|)
operator|==
operator|&
operator|(
operator|(
operator|*
name|v
operator|)
index|[
literal|0
index|]
index|[
operator|*
name|m
index|]
operator|)
return|;
comment|// CHECK: icmp
comment|// CHECK: ret i{{[0-9]+}}
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: @test
end_comment

begin_decl_stmt
name|int
name|test
argument_list|(
name|int
name|n
argument_list|,
name|int
argument_list|(
operator|*
call|(
modifier|*
name|fn
call|)
argument_list|(
name|void
argument_list|)
argument_list|)
index|[
name|n
index|]
argument_list|)
block|{
return|return
operator|(
operator|*
name|fn
argument_list|()
operator|)
index|[
literal|0
index|]
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: @main
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|m
init|=
literal|3
decl_stmt|;
name|int
argument_list|(
operator|*
name|d
argument_list|)
index|[
literal|3
operator|*
literal|2
index|]
operator|=
name|c
expr_stmt|;
name|int
function_decl|(
modifier|*
name|fn
index|[
name|m
index|]
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
return|return
name|f
argument_list|(
operator|&
name|m
argument_list|,
operator|&
name|d
argument_list|)
operator|+
name|test
argument_list|(
name|m
argument_list|,
operator|&
name|fn
argument_list|)
return|;
comment|// CHECK: call {{.+}} @f(
comment|// CHECK: ret i{{[0-9]+}}
block|}
end_function

end_unit

