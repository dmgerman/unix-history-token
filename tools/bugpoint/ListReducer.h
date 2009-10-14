begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ListReducer.h - Trim down list while retaining property --*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This class is to be used as a base class for operations that want to zero in
end_comment

begin_comment
comment|// on a subset of the input which still causes the bug we are tracking.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUGPOINT_LIST_REDUCER_H
end_ifndef

begin_define
define|#
directive|define
name|BUGPOINT_LIST_REDUCER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
specifier|extern
name|bool
name|BugpointIsInterrupted
decl_stmt|;
name|template
operator|<
name|typename
name|ElTy
operator|>
expr|struct
name|ListReducer
block|{   enum
name|TestResult
block|{
name|NoFailure
block|,
comment|// No failure of the predicate was detected
name|KeepSuffix
block|,
comment|// The suffix alone satisfies the predicate
name|KeepPrefix
comment|// The prefix alone satisfies the predicate
block|}
block|;
name|virtual
operator|~
name|ListReducer
argument_list|()
block|{}
comment|// doTest - This virtual function should be overriden by subclasses to
comment|// implement the test desired.  The testcase is only required to test to see
comment|// if the Kept list still satisfies the property, but if it is going to check
comment|// the prefix anyway, it can.
comment|//
name|virtual
name|TestResult
name|doTest
argument_list|(
name|std
operator|::
name|vector
operator|<
name|ElTy
operator|>
operator|&
name|Prefix
argument_list|,
name|std
operator|::
name|vector
operator|<
name|ElTy
operator|>
operator|&
name|Kept
argument_list|)
operator|=
literal|0
block|;
comment|// reduceList - This function attempts to reduce the length of the specified
comment|// list while still maintaining the "test" property.  This is the core of the
comment|// "work" that bugpoint does.
comment|//
name|bool
name|reduceList
argument_list|(
argument|std::vector<ElTy>&TheList
argument_list|)
block|{
name|std
operator|::
name|vector
operator|<
name|ElTy
operator|>
name|empty
block|;
name|std
operator|::
name|srand
argument_list|(
literal|0x6e5ea738
argument_list|)
block|;
comment|// Seed the random number generator
switch|switch
condition|(
name|doTest
argument_list|(
name|TheList
argument_list|,
name|empty
argument_list|)
condition|)
block|{
case|case
name|KeepPrefix
case|:
if|if
condition|(
name|TheList
operator|.
name|size
argument_list|()
operator|==
literal|1
condition|)
comment|// we are done, it's the base case and it fails
return|return
name|true
return|;
else|else
break|break;
comment|// there's definitely an error, but we need to narrow it down
case|case
name|KeepSuffix
case|:
comment|// cannot be reached!
name|errs
argument_list|()
operator|<<
literal|"bugpoint ListReducer internal error: selected empty set.\n"
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
case|case
name|NoFailure
case|:
return|return
name|false
return|;
comment|// there is no failure with the full set of passes/funcs!
block|}
comment|// Maximal number of allowed splitting iterations,
comment|// before the elements are randomly shuffled.
specifier|const
name|unsigned
name|MaxIterationsWithoutProgress
init|=
literal|3
decl_stmt|;
name|bool
name|ShufflingEnabled
operator|=
name|true
block|;
name|Backjump
operator|:
name|unsigned
name|MidTop
operator|=
name|TheList
operator|.
name|size
argument_list|()
block|;
name|unsigned
name|MaxIterations
operator|=
name|MaxIterationsWithoutProgress
block|;
name|unsigned
name|NumOfIterationsWithoutProgress
operator|=
literal|0
block|;
while|while
condition|(
name|MidTop
operator|>
literal|1
condition|)
block|{
comment|// Binary split reduction loop
comment|// Halt if the user presses ctrl-c.
if|if
condition|(
name|BugpointIsInterrupted
condition|)
block|{
name|errs
argument_list|()
operator|<<
literal|"\n\n*** Reduction Interrupted, cleaning up...\n\n"
expr_stmt|;
return|return
name|true
return|;
block|}
comment|// If the loop doesn't make satisfying progress, try shuffling.
comment|// The purpose of shuffling is to avoid the heavy tails of the
comment|// distribution (improving the speed of convergence).
if|if
condition|(
name|ShufflingEnabled
operator|&&
name|NumOfIterationsWithoutProgress
operator|>
name|MaxIterations
condition|)
block|{
name|std
operator|::
name|vector
operator|<
name|ElTy
operator|>
name|ShuffledList
argument_list|(
name|TheList
argument_list|)
expr_stmt|;
name|std
operator|::
name|random_shuffle
argument_list|(
name|ShuffledList
operator|.
name|begin
argument_list|()
argument_list|,
name|ShuffledList
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|errs
argument_list|()
operator|<<
literal|"\n\n*** Testing shuffled set...\n\n"
expr_stmt|;
comment|// Check that random shuffle doesn't loose the bug
if|if
condition|(
name|doTest
argument_list|(
name|ShuffledList
argument_list|,
name|empty
argument_list|)
operator|==
name|KeepPrefix
condition|)
block|{
comment|// If the bug is still here, use the shuffled list.
name|TheList
operator|.
name|swap
argument_list|(
name|ShuffledList
argument_list|)
expr_stmt|;
name|MidTop
operator|=
name|TheList
operator|.
name|size
argument_list|()
expr_stmt|;
comment|// Must increase the shuffling treshold to avoid the small
comment|// probability of inifinite looping without making progress.
name|MaxIterations
operator|+=
literal|2
expr_stmt|;
name|errs
argument_list|()
operator|<<
literal|"\n\n*** Shuffling does not hide the bug...\n\n"
expr_stmt|;
block|}
else|else
block|{
name|ShufflingEnabled
operator|=
name|false
expr_stmt|;
comment|// Disable shuffling further on
name|errs
argument_list|()
operator|<<
literal|"\n\n*** Shuffling hides the bug...\n\n"
expr_stmt|;
block|}
name|NumOfIterationsWithoutProgress
operator|=
literal|0
expr_stmt|;
block|}
name|unsigned
name|Mid
init|=
name|MidTop
operator|/
literal|2
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|ElTy
operator|>
name|Prefix
argument_list|(
name|TheList
operator|.
name|begin
argument_list|()
argument_list|,
name|TheList
operator|.
name|begin
argument_list|()
operator|+
name|Mid
argument_list|)
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|ElTy
operator|>
name|Suffix
argument_list|(
name|TheList
operator|.
name|begin
argument_list|()
operator|+
name|Mid
argument_list|,
name|TheList
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|doTest
argument_list|(
name|Prefix
argument_list|,
name|Suffix
argument_list|)
condition|)
block|{
case|case
name|KeepSuffix
case|:
comment|// The property still holds.  We can just drop the prefix elements, and
comment|// shorten the list to the "kept" elements.
name|TheList
operator|.
name|swap
argument_list|(
name|Suffix
argument_list|)
expr_stmt|;
name|MidTop
operator|=
name|TheList
operator|.
name|size
argument_list|()
expr_stmt|;
comment|// Reset progress treshold and progress counter
name|MaxIterations
operator|=
name|MaxIterationsWithoutProgress
expr_stmt|;
name|NumOfIterationsWithoutProgress
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|KeepPrefix
case|:
comment|// The predicate still holds, shorten the list to the prefix elements.
name|TheList
operator|.
name|swap
argument_list|(
name|Prefix
argument_list|)
expr_stmt|;
name|MidTop
operator|=
name|TheList
operator|.
name|size
argument_list|()
expr_stmt|;
comment|// Reset progress treshold and progress counter
name|MaxIterations
operator|=
name|MaxIterationsWithoutProgress
expr_stmt|;
name|NumOfIterationsWithoutProgress
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|NoFailure
case|:
comment|// Otherwise the property doesn't hold.  Some of the elements we removed
comment|// must be necessary to maintain the property.
name|MidTop
operator|=
name|Mid
expr_stmt|;
name|NumOfIterationsWithoutProgress
operator|++
expr_stmt|;
break|break;
block|}
block|}
comment|// Probability of backjumping from the trimming loop back to the binary
comment|// split reduction loop.
specifier|const
name|int
name|BackjumpProbability
init|=
literal|10
decl_stmt|;
comment|// Okay, we trimmed as much off the top and the bottom of the list as we
comment|// could.  If there is more than two elements in the list, try deleting
comment|// interior elements and testing that.
comment|//
if|if
condition|(
name|TheList
operator|.
name|size
argument_list|()
operator|>
literal|2
condition|)
block|{
name|bool
name|Changed
init|=
name|true
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|ElTy
operator|>
name|EmptyList
expr_stmt|;
while|while
condition|(
name|Changed
condition|)
block|{
comment|// Trimming loop.
name|Changed
operator|=
name|false
expr_stmt|;
comment|// If the binary split reduction loop made an unfortunate sequence of
comment|// splits, the trimming loop might be left off with a huge number of
comment|// remaining elements (large search space). Backjumping out of that
comment|// search space and attempting a different split can significantly
comment|// improve the convergence speed.
if|if
condition|(
name|std
operator|::
name|rand
argument_list|()
operator|%
literal|100
operator|<
name|BackjumpProbability
condition|)
goto|goto
name|Backjump
goto|;
for|for
control|(
name|unsigned
name|i
init|=
literal|1
init|;
name|i
operator|<
name|TheList
operator|.
name|size
argument_list|()
operator|-
literal|1
condition|;
operator|++
name|i
control|)
block|{
comment|// Check interior elts
if|if
condition|(
name|BugpointIsInterrupted
condition|)
block|{
name|errs
argument_list|()
operator|<<
literal|"\n\n*** Reduction Interrupted, cleaning up...\n\n"
expr_stmt|;
return|return
name|true
return|;
block|}
name|std
operator|::
name|vector
operator|<
name|ElTy
operator|>
name|TestList
argument_list|(
name|TheList
argument_list|)
expr_stmt|;
name|TestList
operator|.
name|erase
argument_list|(
name|TestList
operator|.
name|begin
argument_list|()
operator|+
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|doTest
argument_list|(
name|EmptyList
argument_list|,
name|TestList
argument_list|)
operator|==
name|KeepSuffix
condition|)
block|{
comment|// We can trim down the list!
name|TheList
operator|.
name|swap
argument_list|(
name|TestList
argument_list|)
expr_stmt|;
operator|--
name|i
expr_stmt|;
comment|// Don't skip an element of the list
name|Changed
operator|=
name|true
expr_stmt|;
block|}
block|}
comment|// This can take a long time if left uncontrolled.  For now, don't
comment|// iterate.
break|break;
block|}
block|}
return|return
name|true
return|;
comment|// there are some failure and we've narrowed them down
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

