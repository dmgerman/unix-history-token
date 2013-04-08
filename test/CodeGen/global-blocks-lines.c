begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fblocks -g -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Make sure we do not generate line info for debugging-related frame setup.
end_comment

begin_comment
comment|// CHECK: define {{.*}}block_invoke
end_comment

begin_comment
comment|// CHECK-NOT: store {{.*}}%struct.__block_descriptor*{{.*}}dbg
end_comment

begin_comment
comment|// CHECK: store {{.*}}%struct.__block_descriptor*{{.*}}, align
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_comment
comment|// CHECK: define {{.*}}block_invoke
end_comment

begin_comment
comment|// CHECK-NOT: store {{.*}}%struct.__block_descriptor*{{.*}}dbg
end_comment

begin_comment
comment|// CHECK: store {{.*}}%struct.__block_descriptor*{{.*}}, align
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_comment
comment|// CHECK: define {{.*}}block_invoke
end_comment

begin_comment
comment|// CHECK-NOT: store {{.*}}%struct.__block_descriptor*{{.*}}dbg
end_comment

begin_comment
comment|// CHECK: store {{.*}}%struct.__block_descriptor*{{.*}}, align
end_comment

begin_comment
comment|// CHECK: ret
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

begin_decl_stmt
specifier|static
name|void
modifier|*
name|_NSConcreteGlobalBlock
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|^
name|HelloBlock_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Breakpoint for first Block function.  */
end_comment

begin_decl_stmt
name|HelloBlock_t
name|helloBlock
init|=
lambda|^
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|printf
argument_list|(
literal|"Hello there, %s!\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Breakpoint for second Block function.  */
end_comment

begin_decl_stmt
specifier|static
name|HelloBlock_t
name|s_helloBlock
init|=
lambda|^
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|printf
argument_list|(
literal|"Hello there, %s!\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Breakpoint for third Block function.  */
end_comment

begin_decl_stmt
name|int
name|X
init|=
literal|1234
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|^
name|CP
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
name|X
operator|=
name|X
operator|+
literal|1
function_decl|;
end_function_decl

begin_return
return|return
name|X
return|;
end_return

begin_function
unit|};
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|helloBlock
argument_list|(
literal|"world"
argument_list|)
expr_stmt|;
name|s_helloBlock
argument_list|(
literal|"world"
argument_list|)
expr_stmt|;
name|CP
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"X = %d\n"
argument_list|,
name|X
argument_list|)
expr_stmt|;
return|return
name|X
operator|-
literal|1235
return|;
block|}
end_function

end_unit

