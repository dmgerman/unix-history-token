begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1  %s -emit-llvm -o /dev/null
end_comment

begin_include
include|#
directive|include
file|"2006-09-25-DebugFilename.h"
end_include

begin_function
name|int
name|func1
parameter_list|()
block|{
return|return
name|hfunc1
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|func2
parameter_list|()
block|{
name|fluffy
expr_stmt|;
return|return
name|hfunc1
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// expected-error {{use of undeclared identifier 'fluffy'}}
end_comment

end_unit

