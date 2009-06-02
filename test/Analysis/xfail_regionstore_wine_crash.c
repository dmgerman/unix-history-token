begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -checker-cfref -analyze -analyzer-store=region -verify %s
end_comment

begin_comment
comment|// XFAIL
end_comment

begin_comment
comment|// When this test passes we should put it in the misc-ps.m test file.
end_comment

begin_comment
comment|// This test fails now because RegionStoreManager::Retrieve() does correctly
end_comment

begin_comment
comment|// retrieve the first byte of 'x' when retrieving '*y'.
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|long
name|x
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|y
init|=
operator|(
name|char
operator|*
operator|)
operator|&
name|x
decl_stmt|;
if|if
condition|(
operator|!
operator|*
name|y
condition|)
return|return;
block|}
end_function

end_unit

