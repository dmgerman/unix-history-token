begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -xc %s -w -S -o - | llc
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// See PR2452
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_function
name|float
name|test
parameter_list|(
name|int
name|X
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|float
name|F
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|X
argument_list|)
expr_stmt|;
name|F
operator|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|float
argument_list|)
expr_stmt|;
return|return
name|F
return|;
block|}
end_function

end_unit

