begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-experimental-internal-checks -analyzer-experimental-checks -checker-cfref -analyzer-store=region -verify %s
end_comment

begin_typedef
typedef|typedef
name|__typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|char
name|f1
parameter_list|()
block|{
name|char
modifier|*
name|s
init|=
literal|"abcd"
decl_stmt|;
name|char
name|c
init|=
name|s
index|[
literal|4
index|]
decl_stmt|;
comment|// no-warning
return|return
name|s
index|[
literal|5
index|]
operator|+
name|c
return|;
comment|// expected-warning{{Access out-of-bound array element (buffer overflow)}}
block|}
end_function

begin_function
name|void
name|f2
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|p
index|[
literal|3
index|]
operator|=
literal|4
expr_stmt|;
comment|// expected-warning{{Access out-of-bound array element (buffer overflow)}}
block|}
end_function

end_unit

