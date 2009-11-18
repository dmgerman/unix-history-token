begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -analyze -analyzer-experimental-internal-checks -warn-dead-stores -warn-uninit-values -verify %s
end_comment

begin_function
name|void
name|f1
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|int
name|j
init|=
name|i
condition|?
else|:
literal|1
decl_stmt|;
comment|// expected-warning{{use of uninitialized variable}} //expected-warning{{Value stored to 'j' during its initialization is never read}}
block|}
end_function

begin_function
name|void
modifier|*
name|f2
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{
return|return
name|i
condition|?
else|:
literal|0
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|f3
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{
name|int
name|a
decl_stmt|;
return|return
operator|&
name|a
condition|?
else|:
name|i
return|;
block|}
end_function

begin_function
name|void
name|f4
parameter_list|()
block|{
name|char
name|c
index|[
literal|1
condition|?
else|:
literal|2
index|]
decl_stmt|;
block|}
end_function

end_unit

