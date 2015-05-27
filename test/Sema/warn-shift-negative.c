begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wshift-count-negative -fblocks -verify %s
end_comment

begin_function
name|int
name|f
parameter_list|(
name|int
name|a
parameter_list|)
block|{
specifier|const
name|int
name|i
init|=
operator|-
literal|1
decl_stmt|;
return|return
name|a
operator|<<
name|i
return|;
comment|// expected-warning{{shift count is negative}}
block|}
end_function

end_unit

