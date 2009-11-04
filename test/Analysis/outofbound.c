begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -analyze -checker-cfref -analyzer-store=region -verify %s
end_comment

begin_comment
comment|// XFAIL: *
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
comment|// expected-warning{{Load or store into an out-of-bound memory position.}}
block|}
end_function

end_unit

