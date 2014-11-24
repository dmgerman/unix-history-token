begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -triple x86_64-unknown-unknown -emit-llvm-only %s
end_comment

begin_typedef
typedef|typedef
name|int
name|vec256
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(8)));
end_typedef

begin_function
name|vec256
name|foo
parameter_list|(
name|vec256
name|in
parameter_list|)
block|{
name|vec256
name|out
decl_stmt|;
asm|asm("something %0" : : "y"(in));
comment|// expected-error {{invalid type 'vec256' (vector of 8 'int' values) in asm input for constraint 'y'}}
asm|asm("something %0" : "=y"(out));
comment|// expected-error {{invalid type 'vec256' (vector of 8 'int' values) in asm input for constraint 'y'}}
asm|asm("something %0, %0" : "+y"(out));
comment|// expected-error {{invalid type 'vec256' (vector of 8 'int' values) in asm input for constraint 'y'}}
return|return
name|out
return|;
block|}
end_function

end_unit

