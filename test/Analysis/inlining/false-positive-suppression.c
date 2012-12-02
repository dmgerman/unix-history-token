begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=core -analyzer-config suppress-null-return-paths=false -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=core -verify -DSUPPRESSED=1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=core -analyzer-config avoid-suppressing-null-argument-paths=true -DSUPPRESSED=1 -DNULL_ARGS=1 -verify %s
end_comment

begin_function_decl
name|int
name|opaquePropertyCheck
parameter_list|(
name|void
modifier|*
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coin
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
modifier|*
name|getNull
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
modifier|*
name|dynCastToInt
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
if|if
condition|(
name|opaquePropertyCheck
argument_list|(
name|ptr
argument_list|)
condition|)
return|return
operator|(
name|int
operator|*
operator|)
name|ptr
return|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
modifier|*
name|dynCastOrNull
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ptr
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|opaquePropertyCheck
argument_list|(
name|ptr
argument_list|)
condition|)
return|return
operator|(
name|int
operator|*
operator|)
name|ptr
return|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|testDynCast
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|int
modifier|*
name|casted
init|=
name|dynCastToInt
argument_list|(
name|p
argument_list|)
decl_stmt|;
operator|*
name|casted
operator|=
literal|1
expr_stmt|;
ifndef|#
directive|ifndef
name|SUPPRESSED
comment|// expected-warning@-2 {{Dereference of null pointer}}
endif|#
directive|endif
block|}
end_function

begin_function
name|void
name|testDynCastOrNull
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|int
modifier|*
name|casted
init|=
name|dynCastOrNull
argument_list|(
name|p
argument_list|)
decl_stmt|;
operator|*
name|casted
operator|=
literal|1
expr_stmt|;
ifndef|#
directive|ifndef
name|SUPPRESSED
comment|// expected-warning@-2 {{Dereference of null pointer}}
endif|#
directive|endif
block|}
end_function

begin_function
name|void
name|testBranch
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|int
modifier|*
name|casted
decl_stmt|;
comment|// Although the report will be suppressed on one branch, it should still be
comment|// valid on the other.
if|if
condition|(
name|coin
argument_list|()
condition|)
block|{
name|casted
operator|=
name|dynCastToInt
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|p
condition|)
return|return;
name|casted
operator|=
operator|(
name|int
operator|*
operator|)
name|p
expr_stmt|;
block|}
operator|*
name|casted
operator|=
literal|1
expr_stmt|;
comment|// expected-warning {{Dereference of null pointer}}
block|}
end_function

begin_function
name|void
name|testBranchReversed
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|int
modifier|*
name|casted
decl_stmt|;
comment|// Although the report will be suppressed on one branch, it should still be
comment|// valid on the other.
if|if
condition|(
name|coin
argument_list|()
condition|)
block|{
if|if
condition|(
name|p
condition|)
return|return;
name|casted
operator|=
operator|(
name|int
operator|*
operator|)
name|p
expr_stmt|;
block|}
else|else
block|{
name|casted
operator|=
name|dynCastToInt
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
operator|*
name|casted
operator|=
literal|1
expr_stmt|;
comment|// expected-warning {{Dereference of null pointer}}
block|}
end_function

begin_comment
comment|// --------------------------
end_comment

begin_comment
comment|// "Suppression suppression"
end_comment

begin_comment
comment|// --------------------------
end_comment

begin_function
name|void
name|testDynCastOrNullOfNull
parameter_list|()
block|{
comment|// Don't suppress when one of the arguments is NULL.
name|int
modifier|*
name|casted
init|=
name|dynCastOrNull
argument_list|(
literal|0
argument_list|)
decl_stmt|;
operator|*
name|casted
operator|=
literal|1
expr_stmt|;
if|#
directive|if
operator|!
name|SUPPRESSED
operator|||
name|NULL_ARGS
comment|// expected-warning@-2 {{Dereference of null pointer}}
endif|#
directive|endif
block|}
end_function

begin_function
name|void
name|testDynCastOfNull
parameter_list|()
block|{
comment|// Don't suppress when one of the arguments is NULL.
name|int
modifier|*
name|casted
init|=
name|dynCastToInt
argument_list|(
literal|0
argument_list|)
decl_stmt|;
operator|*
name|casted
operator|=
literal|1
expr_stmt|;
if|#
directive|if
operator|!
name|SUPPRESSED
operator|||
name|NULL_ARGS
comment|// expected-warning@-2 {{Dereference of null pointer}}
endif|#
directive|endif
block|}
end_function

begin_function
name|int
modifier|*
name|lookUpInt
parameter_list|(
name|int
name|unused
parameter_list|)
block|{
if|if
condition|(
name|coin
argument_list|()
condition|)
return|return
literal|0
return|;
specifier|static
name|int
name|x
decl_stmt|;
return|return
operator|&
name|x
return|;
block|}
end_function

begin_function
name|void
name|testZeroIsNotNull
parameter_list|()
block|{
comment|// /Do/ suppress when the argument is 0 (an integer).
name|int
modifier|*
name|casted
init|=
name|lookUpInt
argument_list|(
literal|0
argument_list|)
decl_stmt|;
operator|*
name|casted
operator|=
literal|1
expr_stmt|;
ifndef|#
directive|ifndef
name|SUPPRESSED
comment|// expected-warning@-2 {{Dereference of null pointer}}
endif|#
directive|endif
block|}
end_function

begin_function
name|void
name|testTrackNull
parameter_list|()
block|{
comment|// /Do/ suppress if the null argument came from another call returning null.
name|int
modifier|*
name|casted
init|=
name|dynCastOrNull
argument_list|(
name|getNull
argument_list|()
argument_list|)
decl_stmt|;
operator|*
name|casted
operator|=
literal|1
expr_stmt|;
ifndef|#
directive|ifndef
name|SUPPRESSED
comment|// expected-warning@-2 {{Dereference of null pointer}}
endif|#
directive|endif
block|}
end_function

begin_function
name|void
name|testTrackNullVariable
parameter_list|()
block|{
comment|// /Do/ suppress if the null argument came from another call returning null.
name|int
modifier|*
name|ptr
decl_stmt|;
name|ptr
operator|=
name|getNull
argument_list|()
expr_stmt|;
name|int
modifier|*
name|casted
init|=
name|dynCastOrNull
argument_list|(
name|ptr
argument_list|)
decl_stmt|;
operator|*
name|casted
operator|=
literal|1
expr_stmt|;
ifndef|#
directive|ifndef
name|SUPPRESSED
comment|// expected-warning@-2 {{Dereference of null pointer}}
endif|#
directive|endif
block|}
end_function

begin_comment
comment|// ---------------------------------------
end_comment

begin_comment
comment|// FALSE NEGATIVES (over-suppression)
end_comment

begin_comment
comment|// ---------------------------------------
end_comment

begin_function
name|void
name|testNoArguments
parameter_list|()
block|{
comment|// In this case the function has no branches, and MUST return null.
name|int
modifier|*
name|casted
init|=
name|getNull
argument_list|()
decl_stmt|;
operator|*
name|casted
operator|=
literal|1
expr_stmt|;
ifndef|#
directive|ifndef
name|SUPPRESSED
comment|// expected-warning@-2 {{Dereference of null pointer}}
endif|#
directive|endif
block|}
end_function

begin_function
name|int
modifier|*
name|getNullIfNonNull
parameter_list|(
name|void
modifier|*
name|input
parameter_list|)
block|{
if|if
condition|(
name|input
condition|)
return|return
literal|0
return|;
specifier|static
name|int
name|x
decl_stmt|;
return|return
operator|&
name|x
return|;
block|}
end_function

begin_function
name|void
name|testKnownPath
parameter_list|(
name|void
modifier|*
name|input
parameter_list|)
block|{
if|if
condition|(
operator|!
name|input
condition|)
return|return;
comment|// In this case we have a known value for the argument, and thus the path
comment|// through the function doesn't ever split.
name|int
modifier|*
name|casted
init|=
name|getNullIfNonNull
argument_list|(
name|input
argument_list|)
decl_stmt|;
operator|*
name|casted
operator|=
literal|1
expr_stmt|;
ifndef|#
directive|ifndef
name|SUPPRESSED
comment|// expected-warning@-2 {{Dereference of null pointer}}
endif|#
directive|endif
block|}
end_function

begin_function
name|int
modifier|*
name|alwaysReturnNull
parameter_list|(
name|void
modifier|*
name|input
parameter_list|)
block|{
if|if
condition|(
name|opaquePropertyCheck
argument_list|(
name|input
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|testAlwaysReturnNull
parameter_list|(
name|void
modifier|*
name|input
parameter_list|)
block|{
comment|// In this case all paths out of the function return 0, but they are all
comment|// dominated by a branch whose condition we don't know!
name|int
modifier|*
name|casted
init|=
name|alwaysReturnNull
argument_list|(
name|input
argument_list|)
decl_stmt|;
operator|*
name|casted
operator|=
literal|1
expr_stmt|;
ifndef|#
directive|ifndef
name|SUPPRESSED
comment|// expected-warning@-2 {{Dereference of null pointer}}
endif|#
directive|endif
block|}
end_function

end_unit

