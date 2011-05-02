begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|float
name|test1
parameter_list|(
name|int
name|cond
parameter_list|,
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
return|return
name|cond
condition|?
name|a
else|:
name|b
return|;
block|}
end_function

begin_function
name|double
name|test2
parameter_list|(
name|int
name|cond
parameter_list|,
name|float
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
return|return
name|cond
condition|?
name|a
else|:
name|b
return|;
block|}
end_function

begin_function_decl
name|void
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test3
parameter_list|()
block|{
literal|1
condition|?
name|f
argument_list|()
else|:
operator|(
name|void
operator|)
literal|0
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test4
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|short
name|j
decl_stmt|;
name|float
modifier|*
name|k
init|=
literal|1
condition|?
operator|&
name|i
else|:
operator|&
name|j
decl_stmt|;
block|}
end_function

begin_function
name|void
name|test5
parameter_list|()
block|{
specifier|const
name|int
modifier|*
name|cip
decl_stmt|;
name|void
modifier|*
name|vp
decl_stmt|;
name|cip
operator|=
literal|0
condition|?
name|vp
else|:
name|cip
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|test6
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test7
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
modifier|*
name|test8
parameter_list|()
block|{
return|return
literal|1
condition|?
name|test6
else|:
name|test7
return|;
block|}
end_function

begin_function_decl
name|void
name|_efree
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_php_stream_free3
parameter_list|()
block|{
operator|(
literal|1
condition|?
name|free
argument_list|(
literal|0
argument_list|)
else|:
name|_efree
argument_list|(
literal|0
argument_list|)
operator|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_php_stream_free4
parameter_list|()
block|{
literal|1
condition|?
name|_efree
argument_list|(
literal|0
argument_list|)
else|:
name|free
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR5526
end_comment

begin_struct
struct|struct
name|test9
block|{
name|int
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
modifier|*
name|test9spare
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test9
parameter_list|(
name|struct
name|test9
modifier|*
name|p
parameter_list|)
block|{
name|p
condition|?
name|p
else|:
name|test9spare
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test10
end_comment

begin_comment
comment|// CHECK: select i1 {{.*}}, i32 4, i32 5
end_comment

begin_function
name|int
name|test10
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|c
condition|?
literal|4
else|:
literal|5
return|;
block|}
end_function

begin_enum
enum|enum
block|{
name|Gronk
init|=
literal|5
block|}
enum|;
end_enum

begin_comment
comment|// rdar://9289603
end_comment

begin_comment
comment|// CHECK: @test11
end_comment

begin_comment
comment|// CHECK: select i1 {{.*}}, i32 4, i32 5
end_comment

begin_function
name|int
name|test11
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|c
condition|?
literal|4
else|:
name|Gronk
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test12
end_comment

begin_comment
comment|// CHECK: select i1 {{.*}}, double 4.0{{.*}}, double 2.0
end_comment

begin_function
name|double
name|test12
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|c
condition|?
literal|4.0
else|:
literal|2.0
return|;
block|}
end_function

end_unit

