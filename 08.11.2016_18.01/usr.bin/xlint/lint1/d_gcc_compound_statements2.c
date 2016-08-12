begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GCC compound statements with non-expressions */
end_comment

begin_struct
struct|struct
name|cpu_info
block|{
name|int
name|bar
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
block|{ 	    struct
name|cpu_info
operator|*
name|__ci
block|;
name|__asm__
specifier|volatile
operator|(
literal|"movl %%fs:4,%0"
operator|:
literal|"=r"
operator|(
name|__ci
operator|)
operator|)
block|;
name|__ci
block|; 	}
operator|)
operator|->
name|bar
return|;
block|}
end_function

end_unit

