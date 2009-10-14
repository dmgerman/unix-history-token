begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -analyze -checker-cfref -analyzer-store=region -verify %s
end_comment

begin_comment
comment|// Region store must be enabled for tests in this file.
end_comment

begin_comment
comment|// Exercise creating ElementRegion with symbolic super region.
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
modifier|*
name|x
decl_stmt|;
name|int
name|a
decl_stmt|;
if|if
condition|(
name|p
index|[
literal|0
index|]
operator|==
literal|1
condition|)
name|x
operator|=
operator|&
name|a
expr_stmt|;
if|if
condition|(
name|p
index|[
literal|0
index|]
operator|==
literal|1
condition|)
operator|(
name|void
operator|)
operator|*
name|x
expr_stmt|;
comment|// no-warning
block|}
end_function

end_unit

