begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_typedef
typedef|typedef
name|float
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|v4f_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|float
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|,
name|w
decl_stmt|;
block|}
name|s
struct|;
name|v4f_t
name|v
decl_stmt|;
block|}
name|vector_t
typedef|;
end_typedef

begin_function
name|vector_t
name|foo
parameter_list|(
name|v4f_t
name|p
parameter_list|)
block|{
name|vector_t
name|v
init|=
block|{
operator|.
name|v
operator|=
name|p
block|}
decl_stmt|;
return|return
name|v
return|;
block|}
end_function

end_unit

