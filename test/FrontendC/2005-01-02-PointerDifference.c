begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -xc %s -S -o - | grep -v div
end_comment

begin_function
name|int
name|Diff
parameter_list|(
name|int
modifier|*
name|P
parameter_list|,
name|int
modifier|*
name|Q
parameter_list|)
block|{
return|return
name|P
operator|-
name|Q
return|;
block|}
end_function

end_unit

