begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_typedef
typedef|typedef
name|double
name|vector4double
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|vector8float
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_function
name|vector8float
name|foo1
parameter_list|(
name|vector4double
name|x
parameter_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|vector8float
argument_list|)
return|;
comment|// expected-error {{same number of elements}}
block|}
end_function

begin_function
name|float
name|foo2
parameter_list|(
name|vector4double
name|x
parameter_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|float
argument_list|)
return|;
comment|// expected-error {{must be a vector type}}
block|}
end_function

begin_function
name|vector8float
name|foo3
parameter_list|(
name|double
name|x
parameter_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|vector8float
argument_list|)
return|;
comment|// expected-error {{must be a vector}}
block|}
end_function

end_unit

