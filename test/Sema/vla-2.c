begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only -pedantic
end_comment

begin_comment
comment|// Check that we don't crash trying to emit warnings in a potentially-evaluated
end_comment

begin_comment
comment|// sizeof or typeof.  (This test needs to be in a separate file because we use
end_comment

begin_comment
comment|// a different codepath when we have already emitted an error.)
end_comment

begin_function
name|int
name|PotentiallyEvaluatedSizeofWarn
parameter_list|(
name|int
name|n
parameter_list|)
block|{
return|return
operator|(
name|int
operator|)
sizeof|sizeof
expr|*
operator|(
literal|0
operator|<<
literal|32
operator|,
operator|(
name|int
argument_list|(
operator|*
argument_list|)
index|[
name|n
index|]
operator|)
literal|0
operator|)
return|;
comment|// expected-warning {{expression result unused}} expected-warning {{shift count>= width of type}}
block|}
end_function

begin_function
name|void
name|PotentiallyEvaluatedTypeofWarn
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|__typeof
argument_list|(
argument|*(
literal|0
argument|<<
literal|32
argument|,(int(*)[n])
literal|0
argument|)
argument_list|)
name|x
expr_stmt|;
comment|// expected-warning {{expression result unused}} expected-warning {{shift count>= width of type}}
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
end_function

begin_function
name|void
name|PotentiallyEvaluatedArrayBoundWarn
parameter_list|(
name|int
name|n
parameter_list|)
block|{
operator|(
name|void
operator|)
operator|*
operator|(
name|int
argument_list|(
operator|*
argument_list|)
index|[
operator|(
literal|0
operator|<<
literal|32
operator|,
name|n
operator|)
index|]
operator|)
literal|0
expr_stmt|;
comment|// FIXME: We should warn here.
block|}
end_function

end_unit

