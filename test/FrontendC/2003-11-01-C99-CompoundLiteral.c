begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|foo
decl_stmt|;
block|}
name|spinlock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|wait_queue_head_t
block|{
name|spinlock_t
name|lock
decl_stmt|;
block|}
name|wait_queue_head_t
typedef|;
end_typedef

begin_function
name|void
name|call_usermodehelper
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|wait_queue_head_t
name|work
init|=
block|{
name|lock
operator|:
operator|(
name|spinlock_t
operator|)
block|{
literal|0
block|}
block|, }
decl_stmt|;
block|}
end_function

end_unit

