begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=core,unix -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// Testing core functionality of the SValBuilder.
end_comment

begin_function
name|int
name|SValBuilderLogicNoCrash
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
block|{
return|return
literal|3
operator|-
call|(
name|int
call|)
argument_list|(
name|x
operator|+
literal|3
argument_list|)
return|;
block|}
end_function

end_unit

