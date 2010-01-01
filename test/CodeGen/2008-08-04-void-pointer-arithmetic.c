begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s
end_comment

begin_comment
comment|//<rdar://problem/6122967>
end_comment

begin_function
name|int
name|f0
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|void
modifier|*
name|b
parameter_list|)
block|{
return|return
name|a
operator|-
name|b
return|;
block|}
end_function

end_unit

