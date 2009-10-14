begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{ }
name|rwlock_t
typedef|;
end_typedef

begin_struct
struct|struct
name|fs_struct
block|{
name|rwlock_t
name|lock
decl_stmt|;
name|int
name|umask
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|__copy_fs_struct
parameter_list|(
name|struct
name|fs_struct
modifier|*
name|fs
parameter_list|)
block|{
name|fs
operator|->
name|lock
operator|=
operator|(
name|rwlock_t
operator|)
block|{ }
expr_stmt|;
block|}
end_function

end_unit

