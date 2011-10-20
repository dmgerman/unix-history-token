begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include %S/functions.h -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t %S/functions.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t -fsyntax-only -verify %s
end_comment

begin_comment
comment|// expected-note{{'f1' declared here}}
end_comment

begin_function
name|int
name|f0
parameter_list|(
name|int
name|x0
parameter_list|,
name|int
name|y0
parameter_list|,
modifier|...
parameter_list|)
block|{
return|return
name|x0
operator|+
name|y0
return|;
block|}
end_function

begin_comment
comment|// expected-note{{passing argument to parameter here}}
end_comment

begin_function
name|float
modifier|*
name|test_f1
parameter_list|(
name|int
name|val
parameter_list|,
name|double
name|x
parameter_list|,
name|double
name|y
parameter_list|)
block|{
if|if
condition|(
name|val
operator|>
literal|5
condition|)
return|return
name|f1
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
else|else
return|return
name|f1
argument_list|(
name|x
argument_list|)
return|;
comment|// expected-error{{too few arguments to function call}}
block|}
end_function

begin_function
name|void
name|test_g0
parameter_list|(
name|int
modifier|*
name|x
parameter_list|,
name|float
modifier|*
name|y
parameter_list|)
block|{
name|g0
argument_list|(
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning{{incompatible pointer types passing 'float *' to parameter of type 'int *'}}
name|g0
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
name|test_abort
argument_list|(
name|int
name|code
argument_list|)
block|{
name|do_abort
argument_list|(
name|code
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

end_unit

