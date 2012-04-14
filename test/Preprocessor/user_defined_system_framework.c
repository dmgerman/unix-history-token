begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -cc1 -fsyntax-only -F %S/Inputs -Wsign-conversion -verify %s
end_comment

begin_comment
comment|// Check that TestFramework is treated as a system header.
end_comment

begin_include
include|#
directive|include
file|<TestFramework/TestFramework.h>
end_include

begin_function
name|int
name|f1
parameter_list|()
block|{
return|return
name|test_framework_func
argument_list|(
literal|1
argument_list|)
operator|+
name|another_test_framework_func
argument_list|(
literal|2
argument_list|)
return|;
block|}
end_function

end_unit

