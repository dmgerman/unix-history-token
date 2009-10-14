begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{ }
name|the_coolest_struct_in_the_world
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|the_coolest_struct_in_the_world
name|xyzzy
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|foo
parameter_list|()
block|{
return|return
operator|&
name|xyzzy
return|;
block|}
end_function

end_unit

