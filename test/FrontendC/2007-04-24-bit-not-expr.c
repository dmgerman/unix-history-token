begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// PR 1346
end_comment

begin_comment
comment|// RUN: %llvmgcc -S %s  -o /dev/null
end_comment

begin_extern
extern|extern bar(void *
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|f
parameter_list|(
name|void
modifier|*
name|cd
parameter_list|)
block|{
name|bar
argument_list|(
operator|(
operator|(
name|void
operator|*
operator|)
operator|(
call|(
name|unsigned
name|long
call|)
argument_list|(
name|cd
argument_list|)
operator|^
operator|-
literal|1
operator|)
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

