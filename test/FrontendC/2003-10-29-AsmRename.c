begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_struct
struct|struct
name|foo
block|{
name|int
name|X
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bar
block|{
name|int
name|Y
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|Func
argument_list|(
expr|struct
name|foo
operator|*
argument_list|)
name|__asm__
argument_list|(
literal|"Func64"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|Func64
parameter_list|(
name|struct
name|bar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|Func
parameter_list|(
name|struct
name|foo
modifier|*
name|F
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|Func64
parameter_list|(
name|struct
name|bar
modifier|*
name|B
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|test
parameter_list|()
block|{
name|Func
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* should be renamed to call Func64 */
name|Func64
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

