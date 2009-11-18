begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -analyze -analyzer-experimental-internal-checks -checker-cfref -analyzer-store=region -verify %s
end_comment

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

end_unit

