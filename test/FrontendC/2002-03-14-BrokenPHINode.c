begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|/* GCC was generating PHI nodes with an arity< #pred of the basic block the  * PHI node lived in.  This was breaking LLVM because the number of entries  * in a PHI node must equal the number of predecessors for a basic block.  */
end_comment

begin_function
name|int
name|trys
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|int
name|x
parameter_list|)
block|{
name|int
name|asa
decl_stmt|;
name|double
name|Val
decl_stmt|;
name|int
name|LLS
decl_stmt|;
if|if
condition|(
name|x
condition|)
block|{
name|asa
operator|=
name|LLS
operator|+
name|asa
expr_stmt|;
block|}
else|else
block|{   }
return|return
name|asa
operator|+
operator|(
name|int
operator|)
name|Val
return|;
block|}
end_function

end_unit

