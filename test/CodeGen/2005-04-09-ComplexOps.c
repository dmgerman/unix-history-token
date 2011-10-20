begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_define
define|#
directive|define
name|I
value|1.0iF
end_define

begin_function
name|double
name|__complex
name|test
parameter_list|(
name|double
name|X
parameter_list|)
block|{
return|return
operator|~
operator|-
operator|(
name|X
operator|*
name|I
operator|)
return|;
block|}
end_function

begin_function
name|_Bool
name|EQ
parameter_list|(
name|double
name|__complex
name|A
parameter_list|,
name|double
name|__complex
name|B
parameter_list|)
block|{
return|return
name|A
operator|==
name|B
return|;
block|}
end_function

begin_function
name|_Bool
name|NE
parameter_list|(
name|double
name|__complex
name|A
parameter_list|,
name|double
name|__complex
name|B
parameter_list|)
block|{
return|return
name|A
operator|!=
name|B
return|;
block|}
end_function

end_unit

