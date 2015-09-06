begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_safestack %s -o %t
end_comment

begin_comment
comment|// RUN: %run %t
end_comment

begin_comment
comment|// Basic smoke test for the runtime library.
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

