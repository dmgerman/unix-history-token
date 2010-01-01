begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -O1< %s | grep "ret i32 0"
end_comment

begin_function
name|int
name|a
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|++
operator|(
expr|struct
name|x
block|{
name|unsigned
name|x
operator|:
literal|2
block|;}
operator|)
block|{
literal|3
block|}
operator|.
name|x
return|;
block|}
end_function

end_unit

