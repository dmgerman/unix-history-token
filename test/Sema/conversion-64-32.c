begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wshorten-64-to-32 -triple x86_64-apple-darwin %s
end_comment

begin_function
name|int
name|test0
parameter_list|(
name|long
name|v
parameter_list|)
block|{
return|return
name|v
return|;
comment|// expected-warning {{implicit conversion loses integer precision}}
block|}
end_function

begin_comment
comment|// rdar://9546171
end_comment

begin_typedef
typedef|typedef
name|int
name|int4
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|long2
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_function
name|int4
name|test1
parameter_list|(
name|long2
name|a
parameter_list|)
block|{
name|int4
name|v127
init|=
name|a
decl_stmt|;
comment|// no warning.
return|return
name|v127
return|;
block|}
end_function

end_unit

