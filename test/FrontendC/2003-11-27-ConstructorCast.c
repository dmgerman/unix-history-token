begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_struct
struct|struct
name|i387_soft_struct
block|{
name|long
name|cwd
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|i387_union
block|{
name|struct
name|i387_soft_struct
name|soft
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|thread_struct
block|{
name|union
name|i387_union
name|i387
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|_init_task_union
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|thread_struct
name|thread
init|=
operator|(
expr|struct
name|thread_struct
operator|)
block|{
block|{
block|{
literal|0
block|}
block|}
block|}
decl_stmt|;
block|}
end_function

end_unit

