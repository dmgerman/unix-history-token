begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-eagerly-assume -analyzer-checker=core -analyzer-config suppress-null-return-paths=false -verify %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-eagerly-assume -analyzer-checker=core -verify -DSUPPRESSED=1 %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-eagerly-assume -analyzer-checker=core -analyzer-config avoid-suppressing-null-argument-paths=true -DSUPPRESSED=1 -DNULL_ARGS=1 -verify %s
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

begin_function_decl
name|int
modifier|*
name|getPtr
parameter_list|()
function_decl|;
end_function_decl

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

begin_function
name|void
name|testMultipleStore
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
literal|0
decl_stmt|;
name|casted
operator|=
name|dynCastToInt
argument_list|(
name|p
argument_list|)
expr_stmt|;
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
comment|// Test that div by zero does not get suppressed. This is a policy choice.
end_comment

begin_function
name|int
name|retZero
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|triggerDivZero
parameter_list|()
block|{
name|int
name|y
init|=
name|retZero
argument_list|()
decl_stmt|;
return|return
literal|5
operator|/
name|y
return|;
comment|// expected-warning {{Division by zero}}
block|}
end_function

begin_comment
comment|// Treat a function-like macro similarly to an inlined function, so suppress
end_comment

begin_comment
comment|// warnings along paths resulting from inlined checks.
end_comment

begin_define
define|#
directive|define
name|MACRO_WITH_CHECK
parameter_list|(
name|a
parameter_list|)
value|( ((a) != 0) ? *a : 17)
end_define

begin_function
name|void
name|testInlineCheckInMacro
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
name|i
init|=
name|MACRO_WITH_CHECK
argument_list|(
name|p
argument_list|)
decl_stmt|;
operator|(
name|void
operator|)
name|i
expr_stmt|;
operator|*
name|p
operator|=
literal|1
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_define
define|#
directive|define
name|MACRO_WITH_NESTED_CHECK
parameter_list|(
name|a
parameter_list|)
value|( { int j = MACRO_WITH_CHECK(a); j; } )
end_define

begin_function
name|void
name|testInlineCheckInNestedMacro
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
name|i
init|=
name|MACRO_WITH_NESTED_CHECK
argument_list|(
name|p
argument_list|)
decl_stmt|;
operator|(
name|void
operator|)
name|i
expr_stmt|;
operator|*
name|p
operator|=
literal|1
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// If there is a check in a macro that is not function-like, don't treat
end_comment

begin_comment
comment|// it like a function so don't suppress.
end_comment

begin_define
define|#
directive|define
name|NON_FUNCTION_MACRO_WITH_CHECK
value|( ((p) != 0) ? *p : 17)
end_define

begin_function
name|void
name|testNonFunctionMacro
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
name|i
init|=
name|NON_FUNCTION_MACRO_WITH_CHECK
decl_stmt|;
operator|(
name|void
operator|)
name|i
expr_stmt|;
operator|*
name|p
operator|=
literal|1
expr_stmt|;
comment|// expected-warning {{Dereference of null pointer (loaded from variable 'p')}}
block|}
end_function

begin_comment
comment|// This macro will dereference its argument if the argument is NULL.
end_comment

begin_define
define|#
directive|define
name|MACRO_WITH_ERROR
parameter_list|(
name|a
parameter_list|)
value|( ((a) != 0) ? 0 : *a)
end_define

begin_function
name|void
name|testErrorInMacro
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
name|i
init|=
name|MACRO_WITH_ERROR
argument_list|(
name|p
argument_list|)
decl_stmt|;
comment|// expected-warning {{Dereference of null pointer (loaded from variable 'p')}}
operator|(
name|void
operator|)
name|i
expr_stmt|;
block|}
end_function

begin_comment
comment|// Here the check (the "if") is not in a macro, so we should still warn.
end_comment

begin_define
define|#
directive|define
name|MACRO_IN_GUARD
parameter_list|(
name|a
parameter_list|)
value|(!(a))
end_define

begin_function
name|void
name|testMacroUsedAsGuard
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
name|MACRO_IN_GUARD
argument_list|(
name|p
argument_list|)
condition|)
operator|*
name|p
operator|=
literal|1
expr_stmt|;
comment|// expected-warning {{Dereference of null pointer (loaded from variable 'p')}}
block|}
end_function

begin_comment
comment|// When a nil case split is introduced in a macro and the macro is in a guard,
end_comment

begin_comment
comment|// we still shouldn't warn.
end_comment

begin_function_decl
name|int
name|isNull
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isEqual
parameter_list|(
name|int
modifier|*
name|p
parameter_list|,
name|int
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ISNULL
parameter_list|(
name|ptr
parameter_list|)
value|((ptr) == 0 || isNull(ptr))
end_define

begin_define
define|#
directive|define
name|ISEQUAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int *)(a) == (int *)(b) || (ISNULL(a)&& ISNULL(b)) || isEqual(a,b))
end_define

begin_define
define|#
directive|define
name|ISNOTEQUAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(!ISEQUAL(a, b))
end_define

begin_function
name|void
name|testNestedDisjunctiveMacro
parameter_list|(
name|int
modifier|*
name|p
parameter_list|,
name|int
modifier|*
name|q
parameter_list|)
block|{
if|if
condition|(
name|ISNOTEQUAL
argument_list|(
name|p
argument_list|,
name|q
argument_list|)
condition|)
block|{
operator|*
name|p
operator|=
literal|1
expr_stmt|;
comment|// no-warning
operator|*
name|q
operator|=
literal|1
expr_stmt|;
comment|// no-warning
block|}
operator|*
name|p
operator|=
literal|1
expr_stmt|;
comment|// no-warning
operator|*
name|q
operator|=
literal|1
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|testNestedDisjunctiveMacro2
parameter_list|(
name|int
modifier|*
name|p
parameter_list|,
name|int
modifier|*
name|q
parameter_list|)
block|{
if|if
condition|(
name|ISEQUAL
argument_list|(
name|p
argument_list|,
name|q
argument_list|)
condition|)
block|{
return|return;
block|}
operator|*
name|p
operator|=
literal|1
expr_stmt|;
comment|// no-warning
operator|*
name|q
operator|=
literal|1
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Here the check is entirely in non-macro code even though the code itself
end_comment

begin_comment
comment|// is a macro argument.
end_comment

begin_define
define|#
directive|define
name|MACRO_DO_IT
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_function
name|void
name|testErrorInArgument
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
name|i
init|=
name|MACRO_DO_IT
argument_list|(
operator|(
name|p
condition|?
literal|0
else|:
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
comment|// expected-warning {{Dereference of null pointer (loaded from variable 'p')}}c
operator|(
name|void
operator|)
name|i
expr_stmt|;
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

begin_function
name|void
name|inlinedIsDifferent
parameter_list|(
name|int
name|inlined
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
comment|// We were erroneously picking up the inner stack frame's initialization,
comment|// even though the error occurs in the outer stack frame!
name|int
modifier|*
name|p
init|=
name|inlined
condition|?
operator|&
name|i
else|:
name|getNull
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|inlined
condition|)
name|inlinedIsDifferent
argument_list|(
literal|1
argument_list|)
expr_stmt|;
operator|*
name|p
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
name|testInlinedIsDifferent
parameter_list|()
block|{
comment|//<rdar://problem/13787723>
name|inlinedIsDifferent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
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

begin_function
name|int
name|derefArg
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|*
name|p
return|;
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
name|ternaryArg
parameter_list|(
name|char
name|cond
parameter_list|)
block|{
specifier|static
name|int
name|x
decl_stmt|;
name|derefArg
argument_list|(
name|cond
condition|?
operator|&
name|x
else|:
name|getNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|derefArgCast
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|*
name|p
return|;
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
name|ternaryArgCast
parameter_list|(
name|char
name|cond
parameter_list|)
block|{
specifier|static
name|int
name|x
decl_stmt|;
name|derefArgCast
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|(
operator|(
name|unsigned
operator|)
name|cond
condition|?
operator|&
name|x
else|:
name|getNull
argument_list|()
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|derefAssignment
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|*
name|p
return|;
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
name|ternaryAssignment
parameter_list|(
name|char
name|cond
parameter_list|)
block|{
specifier|static
name|int
name|x
decl_stmt|;
name|int
modifier|*
name|p
init|=
name|cond
condition|?
name|getNull
argument_list|()
else|:
name|getPtr
argument_list|()
decl_stmt|;
name|derefAssignment
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
modifier|*
name|retNull
parameter_list|(
name|char
name|cond
parameter_list|)
block|{
specifier|static
name|int
name|x
decl_stmt|;
return|return
name|cond
condition|?
operator|&
name|x
else|:
name|getNull
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|ternaryRetNull
parameter_list|(
name|char
name|cond
parameter_list|)
block|{
name|int
modifier|*
name|p
init|=
name|retNull
argument_list|(
name|cond
argument_list|)
decl_stmt|;
return|return
operator|*
name|p
return|;
ifndef|#
directive|ifndef
name|SUPPRESSED
comment|// expected-warning@-2 {{Dereference of null pointer}}
endif|#
directive|endif
block|}
end_function

begin_comment
comment|// Test suppression of nested conditional operators.
end_comment

begin_function
name|int
name|testConditionalOperatorSuppress
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
operator|*
operator|(
name|x
condition|?
name|getNull
argument_list|()
else|:
name|getPtr
argument_list|()
operator|)
return|;
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
name|testNestedConditionalOperatorSuppress
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
operator|*
operator|(
name|x
condition|?
operator|(
name|x
condition|?
name|getNull
argument_list|()
else|:
name|getPtr
argument_list|()
operator|)
else|:
name|getPtr
argument_list|()
operator|)
return|;
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
name|testConditionalOperator
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
operator|*
operator|(
name|x
condition|?
literal|0
else|:
name|getPtr
argument_list|()
operator|)
return|;
comment|// expected-warning {{Dereference of null pointer}}
block|}
end_function

begin_function
name|int
name|testNestedConditionalOperator
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
operator|*
operator|(
name|x
condition|?
operator|(
name|x
condition|?
literal|0
else|:
name|getPtr
argument_list|()
operator|)
else|:
name|getPtr
argument_list|()
operator|)
return|;
comment|// expected-warning {{Dereference of null pointer}}
block|}
end_function

begin_function
name|int
name|testConditionalOperatorSuppressFloatCond
parameter_list|(
name|float
name|x
parameter_list|)
block|{
return|return
operator|*
operator|(
name|x
condition|?
name|getNull
argument_list|()
else|:
name|getPtr
argument_list|()
operator|)
return|;
ifndef|#
directive|ifndef
name|SUPPRESSED
comment|// expected-warning@-2 {{Dereference of null pointer}}
endif|#
directive|endif
block|}
end_function

end_unit

