begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2007, Google Inc.
end_comment

begin_comment
comment|// All rights reserved.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Redistribution and use in source and binary forms, with or without
end_comment

begin_comment
comment|// modification, are permitted provided that the following conditions are
end_comment

begin_comment
comment|// met:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     * Redistributions of source code must retain the above copyright
end_comment

begin_comment
comment|// notice, this list of conditions and the following disclaimer.
end_comment

begin_comment
comment|//     * Redistributions in binary form must reproduce the above
end_comment

begin_comment
comment|// copyright notice, this list of conditions and the following disclaimer
end_comment

begin_comment
comment|// in the documentation and/or other materials provided with the
end_comment

begin_comment
comment|// distribution.
end_comment

begin_comment
comment|//     * Neither the name of Google Inc. nor the names of its
end_comment

begin_comment
comment|// contributors may be used to endorse or promote products derived from
end_comment

begin_comment
comment|// this software without specific prior written permission.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
end_comment

begin_comment
comment|// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
end_comment

begin_comment
comment|// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
end_comment

begin_comment
comment|// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
end_comment

begin_comment
comment|// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
end_comment

begin_comment
comment|// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
end_comment

begin_comment
comment|// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
end_comment

begin_comment
comment|// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
end_comment

begin_comment
comment|// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Author: wan@google.com (Zhanyong Wan)
end_comment

begin_comment
comment|// Google Mock - a framework for writing C++ mock classes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file implements the ON_CALL() and EXPECT_CALL() macros.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A user can use the ON_CALL() macro to specify the default action of
end_comment

begin_comment
comment|// a mock method.  The syntax is:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   ON_CALL(mock_object, Method(argument-matchers))
end_comment

begin_comment
comment|//       .With(multi-argument-matcher)
end_comment

begin_comment
comment|//       .WillByDefault(action);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  where the .With() clause is optional.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A user can use the EXPECT_CALL() macro to specify an expectation on
end_comment

begin_comment
comment|// a mock method.  The syntax is:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   EXPECT_CALL(mock_object, Method(argument-matchers))
end_comment

begin_comment
comment|//       .With(multi-argument-matchers)
end_comment

begin_comment
comment|//       .Times(cardinality)
end_comment

begin_comment
comment|//       .InSequence(sequences)
end_comment

begin_comment
comment|//       .After(expectations)
end_comment

begin_comment
comment|//       .WillOnce(action)
end_comment

begin_comment
comment|//       .WillRepeatedly(action)
end_comment

begin_comment
comment|//       .RetiresOnSaturation();
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// where all clauses are optional, and .InSequence()/.After()/
end_comment

begin_comment
comment|// .WillOnce() can appear any number of times.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GMOCK_INCLUDE_GMOCK_GMOCK_SPEC_BUILDERS_H_
end_ifndef

begin_define
define|#
directive|define
name|GMOCK_INCLUDE_GMOCK_GMOCK_SPEC_BUILDERS_H_
end_define

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<sstream>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_if
if|#
directive|if
name|GTEST_HAS_EXCEPTIONS
end_if

begin_include
include|#
directive|include
file|<stdexcept>
end_include

begin_comment
comment|// NOLINT
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"gmock/gmock-actions.h"
end_include

begin_include
include|#
directive|include
file|"gmock/gmock-cardinalities.h"
end_include

begin_include
include|#
directive|include
file|"gmock/gmock-matchers.h"
end_include

begin_include
include|#
directive|include
file|"gmock/internal/gmock-internal-utils.h"
end_include

begin_include
include|#
directive|include
file|"gmock/internal/gmock-port.h"
end_include

begin_include
include|#
directive|include
file|"gtest/gtest.h"
end_include

begin_decl_stmt
name|namespace
name|testing
block|{
comment|// An abstract handle of an expectation.
name|class
name|Expectation
decl_stmt|;
comment|// A set of expectation handles.
name|class
name|ExpectationSet
decl_stmt|;
comment|// Anything inside the 'internal' namespace IS INTERNAL IMPLEMENTATION
comment|// and MUST NOT BE USED IN USER CODE!!!
name|namespace
name|internal
block|{
comment|// Implements a mock function.
name|template
operator|<
name|typename
name|F
operator|>
name|class
name|FunctionMocker
expr_stmt|;
comment|// Base class for expectations.
name|class
name|ExpectationBase
decl_stmt|;
comment|// Implements an expectation.
name|template
operator|<
name|typename
name|F
operator|>
name|class
name|TypedExpectation
expr_stmt|;
comment|// Helper class for testing the Expectation class template.
name|class
name|ExpectationTester
decl_stmt|;
comment|// Base class for function mockers.
name|template
operator|<
name|typename
name|F
operator|>
name|class
name|FunctionMockerBase
expr_stmt|;
comment|// Protects the mock object registry (in class Mock), all function
comment|// mockers, and all expectations.
comment|//
comment|// The reason we don't use more fine-grained protection is: when a
comment|// mock function Foo() is called, it needs to consult its expectations
comment|// to see which one should be picked.  If another thread is allowed to
comment|// call a mock function (either Foo() or a different one) at the same
comment|// time, it could affect the "retired" attributes of Foo()'s
comment|// expectations when InSequence() is used, and thus affect which
comment|// expectation gets picked.  Therefore, we sequence all mock function
comment|// calls to ensure the integrity of the mock objects' states.
name|GTEST_API_
name|GTEST_DECLARE_STATIC_MUTEX_
parameter_list|(
name|g_gmock_mutex
parameter_list|)
function_decl|;
comment|// Untyped base class for ActionResultHolder<R>.
name|class
name|UntypedActionResultHolderBase
decl_stmt|;
comment|// Abstract base class of FunctionMockerBase.  This is the
comment|// type-agnostic part of the function mocker interface.  Its pure
comment|// virtual methods are implemented by FunctionMockerBase.
name|class
name|GTEST_API_
name|UntypedFunctionMockerBase
block|{
name|public
label|:
name|UntypedFunctionMockerBase
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|UntypedFunctionMockerBase
argument_list|()
expr_stmt|;
comment|// Verifies that all expectations on this mock function have been
comment|// satisfied.  Reports one or more Google Test non-fatal failures
comment|// and returns false if not.
name|bool
name|VerifyAndClearExpectationsLocked
parameter_list|()
function_decl|GTEST_EXCLUSIVE_LOCK_REQUIRED_
parameter_list|(
name|g_gmock_mutex
parameter_list|)
function_decl|;
comment|// Clears the ON_CALL()s set on this mock function.
name|virtual
name|void
name|ClearDefaultActionsLocked
parameter_list|()
function_decl|GTEST_EXCLUSIVE_LOCK_REQUIRED_
parameter_list|(
name|g_gmock_mutex
parameter_list|)
init|=
literal|0
function_decl|;
comment|// In all of the following Untyped* functions, it's the caller's
comment|// responsibility to guarantee the correctness of the arguments'
comment|// types.
comment|// Performs the default action with the given arguments and returns
comment|// the action's result.  The call description string will be used in
comment|// the error message to describe the call in the case the default
comment|// action fails.
comment|// L = *
name|virtual
name|UntypedActionResultHolderBase
modifier|*
name|UntypedPerformDefaultAction
argument_list|(
specifier|const
name|void
operator|*
name|untyped_args
argument_list|,
specifier|const
name|string
operator|&
name|call_description
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// Performs the given action with the given arguments and returns
comment|// the action's result.
comment|// L = *
name|virtual
name|UntypedActionResultHolderBase
modifier|*
name|UntypedPerformAction
argument_list|(
specifier|const
name|void
operator|*
name|untyped_action
argument_list|,
specifier|const
name|void
operator|*
name|untyped_args
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// Writes a message that the call is uninteresting (i.e. neither
comment|// explicitly expected nor explicitly unexpected) to the given
comment|// ostream.
name|virtual
name|void
name|UntypedDescribeUninterestingCall
argument_list|(
specifier|const
name|void
operator|*
name|untyped_args
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
name|GTEST_LOCK_EXCLUDED_
argument_list|(
name|g_gmock_mutex
argument_list|)
init|=
literal|0
decl_stmt|;
comment|// Returns the expectation that matches the given function arguments
comment|// (or NULL is there's no match); when a match is found,
comment|// untyped_action is set to point to the action that should be
comment|// performed (or NULL if the action is "do default"), and
comment|// is_excessive is modified to indicate whether the call exceeds the
comment|// expected number.
name|virtual
specifier|const
name|ExpectationBase
modifier|*
name|UntypedFindMatchingExpectation
argument_list|(
specifier|const
name|void
operator|*
name|untyped_args
argument_list|,
specifier|const
name|void
operator|*
operator|*
name|untyped_action
argument_list|,
name|bool
operator|*
name|is_excessive
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|what
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|why
argument_list|)
name|GTEST_LOCK_EXCLUDED_
argument_list|(
name|g_gmock_mutex
argument_list|)
init|=
literal|0
decl_stmt|;
comment|// Prints the given function arguments to the ostream.
name|virtual
name|void
name|UntypedPrintArgs
argument_list|(
specifier|const
name|void
operator|*
name|untyped_args
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// Sets the mock object this mock method belongs to, and registers
comment|// this information in the global mock registry.  Will be called
comment|// whenever an EXPECT_CALL() or ON_CALL() is executed on this mock
comment|// method.
comment|// TODO(wan@google.com): rename to SetAndRegisterOwner().
name|void
name|RegisterOwner
parameter_list|(
specifier|const
name|void
modifier|*
name|mock_obj
parameter_list|)
function_decl|GTEST_LOCK_EXCLUDED_
parameter_list|(
name|g_gmock_mutex
parameter_list|)
function_decl|;
comment|// Sets the mock object this mock method belongs to, and sets the
comment|// name of the mock function.  Will be called upon each invocation
comment|// of this mock function.
name|void
name|SetOwnerAndName
parameter_list|(
specifier|const
name|void
modifier|*
name|mock_obj
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|GTEST_LOCK_EXCLUDED_
parameter_list|(
name|g_gmock_mutex
parameter_list|)
function_decl|;
comment|// Returns the mock object this mock method belongs to.  Must be
comment|// called after RegisterOwner() or SetOwnerAndName() has been
comment|// called.
specifier|const
name|void
operator|*
name|MockObject
argument_list|()
specifier|const
name|GTEST_LOCK_EXCLUDED_
argument_list|(
name|g_gmock_mutex
argument_list|)
expr_stmt|;
comment|// Returns the name of this mock method.  Must be called after
comment|// SetOwnerAndName() has been called.
specifier|const
name|char
operator|*
name|Name
argument_list|()
specifier|const
name|GTEST_LOCK_EXCLUDED_
argument_list|(
name|g_gmock_mutex
argument_list|)
expr_stmt|;
comment|// Returns the result of invoking this mock function with the given
comment|// arguments.  This function can be safely called from multiple
comment|// threads concurrently.  The caller is responsible for deleting the
comment|// result.
name|UntypedActionResultHolderBase
modifier|*
name|UntypedInvokeWith
parameter_list|(
specifier|const
name|void
modifier|*
name|untyped_args
parameter_list|)
function_decl|GTEST_LOCK_EXCLUDED_
parameter_list|(
name|g_gmock_mutex
parameter_list|)
function_decl|;
name|protected
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
specifier|const
name|void
operator|*
operator|>
name|UntypedOnCallSpecs
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|internal
operator|::
name|linked_ptr
operator|<
name|ExpectationBase
operator|>
expr|>
name|UntypedExpectations
expr_stmt|;
comment|// Returns an Expectation object that references and co-owns exp,
comment|// which must be an expectation on this mock function.
name|Expectation
name|GetHandleOf
parameter_list|(
name|ExpectationBase
modifier|*
name|exp
parameter_list|)
function_decl|;
comment|// Address of the mock object this mock method belongs to.  Only
comment|// valid after this mock method has been called or
comment|// ON_CALL/EXPECT_CALL has been invoked on it.
specifier|const
name|void
modifier|*
name|mock_obj_
decl_stmt|;
comment|// Protected by g_gmock_mutex.
comment|// Name of the function being mocked.  Only valid after this mock
comment|// method has been called.
specifier|const
name|char
modifier|*
name|name_
decl_stmt|;
comment|// Protected by g_gmock_mutex.
comment|// All default action specs for this function mocker.
name|UntypedOnCallSpecs
name|untyped_on_call_specs_
decl_stmt|;
comment|// All expectations for this function mocker.
name|UntypedExpectations
name|untyped_expectations_
decl_stmt|;
block|}
empty_stmt|;
comment|// class UntypedFunctionMockerBase
comment|// Untyped base class for OnCallSpec<F>.
name|class
name|UntypedOnCallSpecBase
block|{
name|public
label|:
comment|// The arguments are the location of the ON_CALL() statement.
name|UntypedOnCallSpecBase
argument_list|(
argument|const char* a_file
argument_list|,
argument|int a_line
argument_list|)
block|:
name|file_
argument_list|(
name|a_file
argument_list|)
operator|,
name|line_
argument_list|(
name|a_line
argument_list|)
operator|,
name|last_clause_
argument_list|(
argument|kNone
argument_list|)
block|{}
comment|// Where in the source file was the default action spec defined?
specifier|const
name|char
operator|*
name|file
argument_list|()
specifier|const
block|{
return|return
name|file_
return|;
block|}
name|int
name|line
argument_list|()
specifier|const
block|{
return|return
name|line_
return|;
block|}
name|protected
label|:
comment|// Gives each clause in the ON_CALL() statement a name.
enum|enum
name|Clause
block|{
comment|// Do not change the order of the enum members!  The run-time
comment|// syntax checking relies on it.
name|kNone
block|,
name|kWith
block|,
name|kWillByDefault
block|}
enum|;
comment|// Asserts that the ON_CALL() statement has a certain property.
name|void
name|AssertSpecProperty
argument_list|(
name|bool
name|property
argument_list|,
specifier|const
name|string
operator|&
name|failure_message
argument_list|)
decl|const
block|{
name|Assert
argument_list|(
name|property
argument_list|,
name|file_
argument_list|,
name|line_
argument_list|,
name|failure_message
argument_list|)
expr_stmt|;
block|}
comment|// Expects that the ON_CALL() statement has a certain property.
name|void
name|ExpectSpecProperty
argument_list|(
name|bool
name|property
argument_list|,
specifier|const
name|string
operator|&
name|failure_message
argument_list|)
decl|const
block|{
name|Expect
argument_list|(
name|property
argument_list|,
name|file_
argument_list|,
name|line_
argument_list|,
name|failure_message
argument_list|)
expr_stmt|;
block|}
specifier|const
name|char
modifier|*
name|file_
decl_stmt|;
name|int
name|line_
decl_stmt|;
comment|// The last clause in the ON_CALL() statement as seen so far.
comment|// Initially kNone and changes as the statement is parsed.
name|Clause
name|last_clause_
decl_stmt|;
block|}
empty_stmt|;
comment|// class UntypedOnCallSpecBase
comment|// This template class implements an ON_CALL spec.
name|template
operator|<
name|typename
name|F
operator|>
name|class
name|OnCallSpec
operator|:
name|public
name|UntypedOnCallSpecBase
block|{
name|public
operator|:
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentTuple
name|ArgumentTuple
expr_stmt|;
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentMatcherTuple
name|ArgumentMatcherTuple
expr_stmt|;
comment|// Constructs an OnCallSpec object from the information inside
comment|// the parenthesis of an ON_CALL() statement.
name|OnCallSpec
argument_list|(
argument|const char* a_file
argument_list|,
argument|int a_line
argument_list|,
argument|const ArgumentMatcherTuple& matchers
argument_list|)
block|:
name|UntypedOnCallSpecBase
argument_list|(
name|a_file
argument_list|,
name|a_line
argument_list|)
operator|,
name|matchers_
argument_list|(
name|matchers
argument_list|)
operator|,
comment|// By default, extra_matcher_ should match anything.  However,
comment|// we cannot initialize it with _ as that triggers a compiler
comment|// bug in Symbian's C++ compiler (cannot decide between two
comment|// overloaded constructors of Matcher<const ArgumentTuple&>).
name|extra_matcher_
argument_list|(
argument|A<const ArgumentTuple&>()
argument_list|)
block|{   }
comment|// Implements the .With() clause.
name|OnCallSpec
operator|&
name|With
argument_list|(
argument|const Matcher<const ArgumentTuple&>& m
argument_list|)
block|{
comment|// Makes sure this is called at most once.
name|ExpectSpecProperty
argument_list|(
name|last_clause_
operator|<
name|kWith
argument_list|,
literal|".With() cannot appear "
literal|"more than once in an ON_CALL()."
argument_list|)
block|;
name|last_clause_
operator|=
name|kWith
block|;
name|extra_matcher_
operator|=
name|m
block|;
return|return
operator|*
name|this
return|;
block|}
comment|// Implements the .WillByDefault() clause.
name|OnCallSpec
modifier|&
name|WillByDefault
argument_list|(
specifier|const
name|Action
operator|<
name|F
operator|>
operator|&
name|action
argument_list|)
block|{
name|ExpectSpecProperty
argument_list|(
name|last_clause_
operator|<
name|kWillByDefault
argument_list|,
literal|".WillByDefault() must appear "
literal|"exactly once in an ON_CALL()."
argument_list|)
expr_stmt|;
name|last_clause_
operator|=
name|kWillByDefault
expr_stmt|;
name|ExpectSpecProperty
argument_list|(
operator|!
name|action
operator|.
name|IsDoDefault
argument_list|()
argument_list|,
literal|"DoDefault() cannot be used in ON_CALL()."
argument_list|)
expr_stmt|;
name|action_
operator|=
name|action
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|// Returns true iff the given arguments match the matchers.
name|bool
name|Matches
argument_list|(
specifier|const
name|ArgumentTuple
operator|&
name|args
argument_list|)
decl|const
block|{
return|return
name|TupleMatches
argument_list|(
name|matchers_
argument_list|,
name|args
argument_list|)
operator|&&
name|extra_matcher_
operator|.
name|Matches
argument_list|(
name|args
argument_list|)
return|;
block|}
comment|// Returns the action specified by the user.
specifier|const
name|Action
operator|<
name|F
operator|>
operator|&
name|GetAction
argument_list|()
specifier|const
block|{
name|AssertSpecProperty
argument_list|(
name|last_clause_
operator|==
name|kWillByDefault
argument_list|,
literal|".WillByDefault() must appear exactly "
literal|"once in an ON_CALL()."
argument_list|)
block|;
return|return
name|action_
return|;
block|}
name|private
label|:
comment|// The information in statement
comment|//
comment|//   ON_CALL(mock_object, Method(matchers))
comment|//       .With(multi-argument-matcher)
comment|//       .WillByDefault(action);
comment|//
comment|// is recorded in the data members like this:
comment|//
comment|//   source file that contains the statement => file_
comment|//   line number of the statement            => line_
comment|//   matchers                                => matchers_
comment|//   multi-argument-matcher                  => extra_matcher_
comment|//   action                                  => action_
name|ArgumentMatcherTuple
name|matchers_
decl_stmt|;
name|Matcher
operator|<
specifier|const
name|ArgumentTuple
operator|&
operator|>
name|extra_matcher_
expr_stmt|;
name|Action
operator|<
name|F
operator|>
name|action_
expr_stmt|;
block|}
empty_stmt|;
comment|// class OnCallSpec
comment|// Possible reactions on uninteresting calls.
enum|enum
name|CallReaction
block|{
name|kAllow
block|,
name|kWarn
block|,
name|kFail
block|,
name|kDefault
init|=
name|kWarn
comment|// By default, warn about uninteresting calls.
block|}
enum|;
block|}
end_decl_stmt

begin_comment
comment|// namespace internal
end_comment

begin_comment
comment|// Utilities for manipulating mock objects.
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
name|Mock
block|{
name|public
label|:
comment|// The following public methods can be called concurrently.
comment|// Tells Google Mock to ignore mock_obj when checking for leaked
comment|// mock objects.
specifier|static
name|void
name|AllowLeak
parameter_list|(
specifier|const
name|void
modifier|*
name|mock_obj
parameter_list|)
function_decl|GTEST_LOCK_EXCLUDED_
parameter_list|(
function_decl|internal::g_gmock_mutex
block|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Verifies and clears all expectations on the given mock object.
end_comment

begin_comment
comment|// If the expectations aren't satisfied, generates one or more
end_comment

begin_comment
comment|// Google Test non-fatal failures and returns false.
end_comment

begin_function_decl
specifier|static
name|bool
name|VerifyAndClearExpectations
parameter_list|(
name|void
modifier|*
name|mock_obj
parameter_list|)
function_decl|GTEST_LOCK_EXCLUDED_
parameter_list|(
function_decl|internal::g_gmock_mutex
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Verifies all expectations on the given mock object and clears its
end_comment

begin_comment
comment|// default actions and expectations.  Returns true iff the
end_comment

begin_comment
comment|// verification was successful.
end_comment

begin_function_decl
specifier|static
name|bool
name|VerifyAndClear
parameter_list|(
name|void
modifier|*
name|mock_obj
parameter_list|)
function_decl|GTEST_LOCK_EXCLUDED_
parameter_list|(
function_decl|internal::g_gmock_mutex
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|friend
name|class
name|internal
operator|::
name|UntypedFunctionMockerBase
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Needed for a function mocker to register itself (so that we know
end_comment

begin_comment
comment|// how to clear a mock object).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|F
operator|>
name|friend
name|class
name|internal
operator|::
name|FunctionMockerBase
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|M
operator|>
name|friend
name|class
name|NiceMock
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|M
operator|>
name|friend
name|class
name|NaggyMock
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|M
operator|>
name|friend
name|class
name|StrictMock
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Tells Google Mock to allow uninteresting calls on the given mock
end_comment

begin_comment
comment|// object.
end_comment

begin_function_decl
specifier|static
name|void
name|AllowUninterestingCalls
parameter_list|(
specifier|const
name|void
modifier|*
name|mock_obj
parameter_list|)
function_decl|GTEST_LOCK_EXCLUDED_
parameter_list|(
function_decl|internal::g_gmock_mutex
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Tells Google Mock to warn the user about uninteresting calls on
end_comment

begin_comment
comment|// the given mock object.
end_comment

begin_function_decl
specifier|static
name|void
name|WarnUninterestingCalls
parameter_list|(
specifier|const
name|void
modifier|*
name|mock_obj
parameter_list|)
function_decl|GTEST_LOCK_EXCLUDED_
parameter_list|(
function_decl|internal::g_gmock_mutex
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Tells Google Mock to fail uninteresting calls on the given mock
end_comment

begin_comment
comment|// object.
end_comment

begin_function_decl
specifier|static
name|void
name|FailUninterestingCalls
parameter_list|(
specifier|const
name|void
modifier|*
name|mock_obj
parameter_list|)
function_decl|GTEST_LOCK_EXCLUDED_
parameter_list|(
function_decl|internal::g_gmock_mutex
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Tells Google Mock the given mock object is being destroyed and
end_comment

begin_comment
comment|// its entry in the call-reaction table should be removed.
end_comment

begin_function_decl
specifier|static
name|void
name|UnregisterCallReaction
parameter_list|(
specifier|const
name|void
modifier|*
name|mock_obj
parameter_list|)
function_decl|GTEST_LOCK_EXCLUDED_
parameter_list|(
function_decl|internal::g_gmock_mutex
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Returns the reaction Google Mock will have on uninteresting calls
end_comment

begin_comment
comment|// made on the given mock object.
end_comment

begin_expr_stmt
specifier|static
name|internal
operator|::
name|CallReaction
name|GetReactionOnUninterestingCalls
argument_list|(
argument|const void* mock_obj
argument_list|)
name|GTEST_LOCK_EXCLUDED_
argument_list|(
name|internal
operator|::
name|g_gmock_mutex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Verifies that all expectations on the given mock object have been
end_comment

begin_comment
comment|// satisfied.  Reports one or more Google Test non-fatal failures
end_comment

begin_comment
comment|// and returns false if not.
end_comment

begin_function_decl
specifier|static
name|bool
name|VerifyAndClearExpectationsLocked
parameter_list|(
name|void
modifier|*
name|mock_obj
parameter_list|)
function_decl|GTEST_EXCLUSIVE_LOCK_REQUIRED_
parameter_list|(
function_decl|internal::g_gmock_mutex
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Clears all ON_CALL()s set on the given mock object.
end_comment

begin_function_decl
specifier|static
name|void
name|ClearDefaultActionsLocked
parameter_list|(
name|void
modifier|*
name|mock_obj
parameter_list|)
function_decl|GTEST_EXCLUSIVE_LOCK_REQUIRED_
parameter_list|(
function_decl|internal::g_gmock_mutex
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Registers a mock object and a mock method it owns.
end_comment

begin_decl_stmt
specifier|static
name|void
name|Register
argument_list|(
specifier|const
name|void
operator|*
name|mock_obj
argument_list|,
name|internal
operator|::
name|UntypedFunctionMockerBase
operator|*
name|mocker
argument_list|)
name|GTEST_LOCK_EXCLUDED_
argument_list|(
name|internal
operator|::
name|g_gmock_mutex
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Tells Google Mock where in the source code mock_obj is used in an
end_comment

begin_comment
comment|// ON_CALL or EXPECT_CALL.  In case mock_obj is leaked, this
end_comment

begin_comment
comment|// information helps the user identify which object it is.
end_comment

begin_function_decl
specifier|static
name|void
name|RegisterUseByOnCallOrExpectCall
parameter_list|(
specifier|const
name|void
modifier|*
name|mock_obj
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|GTEST_LOCK_EXCLUDED_
parameter_list|(
function_decl|internal::g_gmock_mutex
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Unregisters a mock method; removes the owning mock object from
end_comment

begin_comment
comment|// the registry when the last mock method associated with it has
end_comment

begin_comment
comment|// been unregistered.  This is called only in the destructor of
end_comment

begin_comment
comment|// FunctionMockerBase.
end_comment

begin_decl_stmt
specifier|static
name|void
name|UnregisterLocked
argument_list|(
name|internal
operator|::
name|UntypedFunctionMockerBase
operator|*
name|mocker
argument_list|)
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
name|internal
operator|::
name|g_gmock_mutex
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// class Mock
end_comment

begin_comment
comment|// An abstract handle of an expectation.  Useful in the .After()
end_comment

begin_comment
comment|// clause of EXPECT_CALL() for setting the (partial) order of
end_comment

begin_comment
comment|// expectations.  The syntax:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   Expectation e1 = EXPECT_CALL(...)...;
end_comment

begin_comment
comment|//   EXPECT_CALL(...).After(e1)...;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// sets two expectations where the latter can only be matched after
end_comment

begin_comment
comment|// the former has been satisfied.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Notes:
end_comment

begin_comment
comment|//   - This class is copyable and has value semantics.
end_comment

begin_comment
comment|//   - Constness is shallow: a const Expectation object itself cannot
end_comment

begin_comment
comment|//     be modified, but the mutable methods of the ExpectationBase
end_comment

begin_comment
comment|//     object it references can be called via expectation_base().
end_comment

begin_comment
comment|//   - The constructors and destructor are defined out-of-line because
end_comment

begin_comment
comment|//     the Symbian WINSCW compiler wants to otherwise instantiate them
end_comment

begin_comment
comment|//     when it sees this class definition, at which point it doesn't have
end_comment

begin_comment
comment|//     ExpectationBase available yet, leading to incorrect destruction
end_comment

begin_comment
comment|//     in the linked_ptr (or compilation errors if using a checking
end_comment

begin_comment
comment|//     linked_ptr).
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
name|Expectation
block|{
name|public
label|:
comment|// Constructs a null object that doesn't reference any expectation.
name|Expectation
argument_list|()
expr_stmt|;
operator|~
name|Expectation
argument_list|()
expr_stmt|;
comment|// This single-argument ctor must not be explicit, in order to support the
comment|//   Expectation e = EXPECT_CALL(...);
comment|// syntax.
comment|//
comment|// A TypedExpectation object stores its pre-requisites as
comment|// Expectation objects, and needs to call the non-const Retire()
comment|// method on the ExpectationBase objects they reference.  Therefore
comment|// Expectation must receive a *non-const* reference to the
comment|// ExpectationBase object.
name|Expectation
argument_list|(
name|internal
operator|::
name|ExpectationBase
operator|&
name|exp
argument_list|)
expr_stmt|;
comment|// NOLINT
comment|// The compiler-generated copy ctor and operator= work exactly as
comment|// intended, so we don't need to define our own.
comment|// Returns true iff rhs references the same expectation as this object does.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Expectation
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|expectation_base_
operator|==
name|rhs
operator|.
name|expectation_base_
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Expectation
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|rhs
operator|)
return|;
block|}
name|private
label|:
name|friend
name|class
name|ExpectationSet
decl_stmt|;
name|friend
name|class
name|Sequence
decl_stmt|;
name|friend
name|class
operator|::
name|testing
operator|::
name|internal
operator|::
name|ExpectationBase
expr_stmt|;
name|friend
name|class
operator|::
name|testing
operator|::
name|internal
operator|::
name|UntypedFunctionMockerBase
expr_stmt|;
name|template
operator|<
name|typename
name|F
operator|>
name|friend
name|class
operator|::
name|testing
operator|::
name|internal
operator|::
name|FunctionMockerBase
expr_stmt|;
name|template
operator|<
name|typename
name|F
operator|>
name|friend
name|class
operator|::
name|testing
operator|::
name|internal
operator|::
name|TypedExpectation
expr_stmt|;
comment|// This comparator is needed for putting Expectation objects into a set.
name|class
name|Less
block|{
name|public
label|:
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|Expectation
operator|&
name|lhs
operator|,
specifier|const
name|Expectation
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|lhs
operator|.
name|expectation_base_
operator|.
name|get
argument_list|()
operator|<
name|rhs
operator|.
name|expectation_base_
operator|.
name|get
argument_list|()
return|;
block|}
block|}
empty_stmt|;
typedef|typedef
operator|::
name|std
operator|::
name|set
operator|<
name|Expectation
operator|,
name|Less
operator|>
name|Set
expr_stmt|;
name|Expectation
argument_list|(
specifier|const
name|internal
operator|::
name|linked_ptr
operator|<
name|internal
operator|::
name|ExpectationBase
operator|>
operator|&
name|expectation_base
argument_list|)
expr_stmt|;
comment|// Returns the expectation this object references.
specifier|const
name|internal
operator|::
name|linked_ptr
operator|<
name|internal
operator|::
name|ExpectationBase
operator|>
operator|&
name|expectation_base
argument_list|()
specifier|const
block|{
return|return
name|expectation_base_
return|;
block|}
comment|// A linked_ptr that co-owns the expectation this handle references.
name|internal
operator|::
name|linked_ptr
operator|<
name|internal
operator|::
name|ExpectationBase
operator|>
name|expectation_base_
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// A set of expectation handles.  Useful in the .After() clause of
end_comment

begin_comment
comment|// EXPECT_CALL() for setting the (partial) order of expectations.  The
end_comment

begin_comment
comment|// syntax:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   ExpectationSet es;
end_comment

begin_comment
comment|//   es += EXPECT_CALL(...)...;
end_comment

begin_comment
comment|//   es += EXPECT_CALL(...)...;
end_comment

begin_comment
comment|//   EXPECT_CALL(...).After(es)...;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// sets three expectations where the last one can only be matched
end_comment

begin_comment
comment|// after the first two have both been satisfied.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This class is copyable and has value semantics.
end_comment

begin_decl_stmt
name|class
name|ExpectationSet
block|{
name|public
label|:
comment|// A bidirectional iterator that can read a const element in the set.
typedef|typedef
name|Expectation
operator|::
name|Set
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
comment|// An object stored in the set.  This is an alias of Expectation.
typedef|typedef
name|Expectation
operator|::
name|Set
operator|::
name|value_type
name|value_type
expr_stmt|;
comment|// Constructs an empty set.
name|ExpectationSet
argument_list|()
block|{}
comment|// This single-argument ctor must not be explicit, in order to support the
comment|//   ExpectationSet es = EXPECT_CALL(...);
comment|// syntax.
name|ExpectationSet
argument_list|(
argument|internal::ExpectationBase& exp
argument_list|)
block|{
comment|// NOLINT
operator|*
name|this
operator|+=
name|Expectation
argument_list|(
name|exp
argument_list|)
expr_stmt|;
block|}
comment|// This single-argument ctor implements implicit conversion from
comment|// Expectation and thus must not be explicit.  This allows either an
comment|// Expectation or an ExpectationSet to be used in .After().
name|ExpectationSet
argument_list|(
argument|const Expectation& e
argument_list|)
block|{
comment|// NOLINT
operator|*
name|this
operator|+=
name|e
expr_stmt|;
block|}
comment|// The compiler-generator ctor and operator= works exactly as
comment|// intended, so we don't need to define our own.
comment|// Returns true iff rhs contains the same set of Expectation objects
comment|// as this does.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ExpectationSet
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|expectations_
operator|==
name|rhs
operator|.
name|expectations_
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ExpectationSet
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|rhs
operator|)
return|;
block|}
comment|// Implements the syntax
comment|//   expectation_set += EXPECT_CALL(...);
name|ExpectationSet
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|Expectation
operator|&
name|e
operator|)
block|{
name|expectations_
operator|.
name|insert
argument_list|(
name|e
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|expectations_
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|expectations_
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|expectations_
operator|.
name|end
argument_list|()
return|;
block|}
name|private
label|:
name|Expectation
operator|::
name|Set
name|expectations_
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Sequence objects are used by a user to specify the relative order
end_comment

begin_comment
comment|// in which the expectations should match.  They are copyable (we rely
end_comment

begin_comment
comment|// on the compiler-defined copy constructor and assignment operator).
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
name|Sequence
block|{
name|public
label|:
comment|// Constructs an empty sequence.
name|Sequence
argument_list|()
operator|:
name|last_expectation_
argument_list|(
argument|new Expectation
argument_list|)
block|{}
comment|// Adds an expectation to this sequence.  The caller must ensure
comment|// that no other thread is accessing this Sequence object.
name|void
name|AddExpectation
argument_list|(
argument|const Expectation& expectation
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
comment|// The last expectation in this sequence.  We use a linked_ptr here
comment|// because Sequence objects are copyable and we want the copies to
comment|// be aliases.  The linked_ptr allows the copies to co-own and share
comment|// the same Expectation object.
name|internal
operator|::
name|linked_ptr
operator|<
name|Expectation
operator|>
name|last_expectation_
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// class Sequence
end_comment

begin_comment
comment|// An object of this type causes all EXPECT_CALL() statements
end_comment

begin_comment
comment|// encountered in its scope to be put in an anonymous sequence.  The
end_comment

begin_comment
comment|// work is done in the constructor and destructor.  You should only
end_comment

begin_comment
comment|// create an InSequence object on the stack.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The sole purpose for this class is to support easy definition of
end_comment

begin_comment
comment|// sequential expectations, e.g.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   {
end_comment

begin_comment
comment|//     InSequence dummy;  // The name of the object doesn't matter.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     // The following expectations must match in the order they appear.
end_comment

begin_comment
comment|//     EXPECT_CALL(a, Bar())...;
end_comment

begin_comment
comment|//     EXPECT_CALL(a, Baz())...;
end_comment

begin_comment
comment|//     ...
end_comment

begin_comment
comment|//     EXPECT_CALL(b, Xyz())...;
end_comment

begin_comment
comment|//   }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// You can create InSequence objects in multiple threads, as long as
end_comment

begin_comment
comment|// they are used to affect different mock objects.  The idea is that
end_comment

begin_comment
comment|// each thread can create and set up its own mocks as if it's the only
end_comment

begin_comment
comment|// thread.  However, for clarity of your tests we recommend you to set
end_comment

begin_comment
comment|// up mocks in the main thread unless you have a good reason not to do
end_comment

begin_comment
comment|// so.
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
name|InSequence
block|{
name|public
label|:
name|InSequence
argument_list|()
expr_stmt|;
operator|~
name|InSequence
argument_list|()
expr_stmt|;
name|private
label|:
name|bool
name|sequence_created_
decl_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|InSequence
argument_list|)
expr_stmt|;
comment|// NOLINT
block|}
end_decl_stmt

begin_expr_stmt
name|GTEST_ATTRIBUTE_UNUSED_
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|namespace
name|internal
block|{
comment|// Points to the implicit sequence introduced by a living InSequence
comment|// object (if any) in the current thread or NULL.
name|GTEST_API_
specifier|extern
name|ThreadLocal
operator|<
name|Sequence
operator|*
operator|>
name|g_gmock_implicit_sequence
expr_stmt|;
comment|// Base class for implementing expectations.
comment|//
comment|// There are two reasons for having a type-agnostic base class for
comment|// Expectation:
comment|//
comment|//   1. We need to store collections of expectations of different
comment|//   types (e.g. all pre-requisites of a particular expectation, all
comment|//   expectations in a sequence).  Therefore these expectation objects
comment|//   must share a common base class.
comment|//
comment|//   2. We can avoid binary code bloat by moving methods not depending
comment|//   on the template argument of Expectation to the base class.
comment|//
comment|// This class is internal and mustn't be used by user code directly.
name|class
name|GTEST_API_
name|ExpectationBase
block|{
name|public
label|:
comment|// source_text is the EXPECT_CALL(...) source that created this Expectation.
name|ExpectationBase
argument_list|(
argument|const char* file
argument_list|,
argument|int line
argument_list|,
argument|const string& source_text
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|ExpectationBase
argument_list|()
expr_stmt|;
comment|// Where in the source file was the expectation spec defined?
specifier|const
name|char
operator|*
name|file
argument_list|()
specifier|const
block|{
return|return
name|file_
return|;
block|}
name|int
name|line
argument_list|()
specifier|const
block|{
return|return
name|line_
return|;
block|}
specifier|const
name|char
operator|*
name|source_text
argument_list|()
specifier|const
block|{
return|return
name|source_text_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Returns the cardinality specified in the expectation spec.
specifier|const
name|Cardinality
operator|&
name|cardinality
argument_list|()
specifier|const
block|{
return|return
name|cardinality_
return|;
block|}
comment|// Describes the source file location of this expectation.
name|void
name|DescribeLocationTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
name|FormatFileLocation
argument_list|(
name|file
argument_list|()
argument_list|,
name|line
argument_list|()
argument_list|)
operator|<<
literal|" "
expr_stmt|;
block|}
comment|// Describes how many times a function call matching this
comment|// expectation has occurred.
name|void
name|DescribeCallCountTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
name|g_gmock_mutex
argument_list|)
decl_stmt|;
comment|// If this mock method has an extra matcher (i.e. .With(matcher)),
comment|// describes it to the ostream.
name|virtual
name|void
name|MaybeDescribeExtraMatcherTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
init|=
literal|0
decl_stmt|;
name|protected
label|:
name|friend
name|class
operator|::
name|testing
operator|::
name|Expectation
expr_stmt|;
name|friend
name|class
name|UntypedFunctionMockerBase
decl_stmt|;
enum|enum
name|Clause
block|{
comment|// Don't change the order of the enum members!
name|kNone
block|,
name|kWith
block|,
name|kTimes
block|,
name|kInSequence
block|,
name|kAfter
block|,
name|kWillOnce
block|,
name|kWillRepeatedly
block|,
name|kRetiresOnSaturation
block|}
enum|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
specifier|const
name|void
operator|*
operator|>
name|UntypedActions
expr_stmt|;
comment|// Returns an Expectation object that references and co-owns this
comment|// expectation.
name|virtual
name|Expectation
name|GetHandle
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Asserts that the EXPECT_CALL() statement has the given property.
name|void
name|AssertSpecProperty
argument_list|(
name|bool
name|property
argument_list|,
specifier|const
name|string
operator|&
name|failure_message
argument_list|)
decl|const
block|{
name|Assert
argument_list|(
name|property
argument_list|,
name|file_
argument_list|,
name|line_
argument_list|,
name|failure_message
argument_list|)
expr_stmt|;
block|}
comment|// Expects that the EXPECT_CALL() statement has the given property.
name|void
name|ExpectSpecProperty
argument_list|(
name|bool
name|property
argument_list|,
specifier|const
name|string
operator|&
name|failure_message
argument_list|)
decl|const
block|{
name|Expect
argument_list|(
name|property
argument_list|,
name|file_
argument_list|,
name|line_
argument_list|,
name|failure_message
argument_list|)
expr_stmt|;
block|}
comment|// Explicitly specifies the cardinality of this expectation.  Used
comment|// by the subclasses to implement the .Times() clause.
name|void
name|SpecifyCardinality
parameter_list|(
specifier|const
name|Cardinality
modifier|&
name|cardinality
parameter_list|)
function_decl|;
comment|// Returns true iff the user specified the cardinality explicitly
comment|// using a .Times().
name|bool
name|cardinality_specified
argument_list|()
specifier|const
block|{
return|return
name|cardinality_specified_
return|;
block|}
comment|// Sets the cardinality of this expectation spec.
name|void
name|set_cardinality
parameter_list|(
specifier|const
name|Cardinality
modifier|&
name|a_cardinality
parameter_list|)
block|{
name|cardinality_
operator|=
name|a_cardinality
expr_stmt|;
block|}
comment|// The following group of methods should only be called after the
comment|// EXPECT_CALL() statement, and only when g_gmock_mutex is held by
comment|// the current thread.
comment|// Retires all pre-requisites of this expectation.
name|void
name|RetireAllPreRequisites
parameter_list|()
function_decl|GTEST_EXCLUSIVE_LOCK_REQUIRED_
parameter_list|(
name|g_gmock_mutex
parameter_list|)
function_decl|;
comment|// Returns true iff this expectation is retired.
name|bool
name|is_retired
argument_list|()
specifier|const
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
argument|g_gmock_mutex
argument_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
block|;
return|return
name|retired_
return|;
block|}
comment|// Retires this expectation.
name|void
name|Retire
parameter_list|()
function|GTEST_EXCLUSIVE_LOCK_REQUIRED_
parameter_list|(
name|g_gmock_mutex
parameter_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
expr_stmt|;
name|retired_
operator|=
name|true
expr_stmt|;
block|}
comment|// Returns true iff this expectation is satisfied.
name|bool
name|IsSatisfied
argument_list|()
specifier|const
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
argument|g_gmock_mutex
argument_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
block|;
return|return
name|cardinality
argument_list|()
operator|.
name|IsSatisfiedByCallCount
argument_list|(
name|call_count_
argument_list|)
return|;
block|}
comment|// Returns true iff this expectation is saturated.
name|bool
name|IsSaturated
argument_list|()
specifier|const
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
argument|g_gmock_mutex
argument_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
block|;
return|return
name|cardinality
argument_list|()
operator|.
name|IsSaturatedByCallCount
argument_list|(
name|call_count_
argument_list|)
return|;
block|}
comment|// Returns true iff this expectation is over-saturated.
name|bool
name|IsOverSaturated
argument_list|()
specifier|const
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
argument|g_gmock_mutex
argument_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
block|;
return|return
name|cardinality
argument_list|()
operator|.
name|IsOverSaturatedByCallCount
argument_list|(
name|call_count_
argument_list|)
return|;
block|}
comment|// Returns true iff all pre-requisites of this expectation are satisfied.
name|bool
name|AllPrerequisitesAreSatisfied
argument_list|()
specifier|const
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
name|g_gmock_mutex
argument_list|)
expr_stmt|;
comment|// Adds unsatisfied pre-requisites of this expectation to 'result'.
name|void
name|FindUnsatisfiedPrerequisites
argument_list|(
name|ExpectationSet
operator|*
name|result
argument_list|)
decl|const
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
name|g_gmock_mutex
argument_list|)
decl_stmt|;
comment|// Returns the number this expectation has been invoked.
name|int
name|call_count
argument_list|()
specifier|const
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
argument|g_gmock_mutex
argument_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
block|;
return|return
name|call_count_
return|;
block|}
comment|// Increments the number this expectation has been invoked.
name|void
name|IncrementCallCount
parameter_list|()
function|GTEST_EXCLUSIVE_LOCK_REQUIRED_
parameter_list|(
name|g_gmock_mutex
parameter_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
expr_stmt|;
name|call_count_
operator|++
expr_stmt|;
block|}
comment|// Checks the action count (i.e. the number of WillOnce() and
comment|// WillRepeatedly() clauses) against the cardinality if this hasn't
comment|// been done before.  Prints a warning if there are too many or too
comment|// few actions.
name|void
name|CheckActionCountIfNotDone
argument_list|()
specifier|const
name|GTEST_LOCK_EXCLUDED_
argument_list|(
name|mutex_
argument_list|)
expr_stmt|;
name|friend
name|class
operator|::
name|testing
operator|::
name|Sequence
expr_stmt|;
name|friend
name|class
operator|::
name|testing
operator|::
name|internal
operator|::
name|ExpectationTester
expr_stmt|;
name|template
operator|<
name|typename
name|Function
operator|>
name|friend
name|class
name|TypedExpectation
expr_stmt|;
comment|// Implements the .Times() clause.
name|void
name|UntypedTimes
parameter_list|(
specifier|const
name|Cardinality
modifier|&
name|a_cardinality
parameter_list|)
function_decl|;
comment|// This group of fields are part of the spec and won't change after
comment|// an EXPECT_CALL() statement finishes.
specifier|const
name|char
modifier|*
name|file_
decl_stmt|;
comment|// The file that contains the expectation.
name|int
name|line_
decl_stmt|;
comment|// The line number of the expectation.
specifier|const
name|string
name|source_text_
decl_stmt|;
comment|// The EXPECT_CALL(...) source text.
comment|// True iff the cardinality is specified explicitly.
name|bool
name|cardinality_specified_
decl_stmt|;
name|Cardinality
name|cardinality_
decl_stmt|;
comment|// The cardinality of the expectation.
comment|// The immediate pre-requisites (i.e. expectations that must be
comment|// satisfied before this expectation can be matched) of this
comment|// expectation.  We use linked_ptr in the set because we want an
comment|// Expectation object to be co-owned by its FunctionMocker and its
comment|// successors.  This allows multiple mock objects to be deleted at
comment|// different times.
name|ExpectationSet
name|immediate_prerequisites_
decl_stmt|;
comment|// This group of fields are the current state of the expectation,
comment|// and can change as the mock function is called.
name|int
name|call_count_
decl_stmt|;
comment|// How many times this expectation has been invoked.
name|bool
name|retired_
decl_stmt|;
comment|// True iff this expectation has retired.
name|UntypedActions
name|untyped_actions_
decl_stmt|;
name|bool
name|extra_matcher_specified_
decl_stmt|;
name|bool
name|repeated_action_specified_
decl_stmt|;
comment|// True if a WillRepeatedly() was specified.
name|bool
name|retires_on_saturation_
decl_stmt|;
name|Clause
name|last_clause_
decl_stmt|;
name|mutable
name|bool
name|action_count_checked_
decl_stmt|;
comment|// Under mutex_.
name|mutable
name|Mutex
name|mutex_
decl_stmt|;
comment|// Protects action_count_checked_.
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|ExpectationBase
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|// class ExpectationBase
comment|// Impements an expectation for the given function type.
name|template
operator|<
name|typename
name|F
operator|>
name|class
name|TypedExpectation
operator|:
name|public
name|ExpectationBase
block|{
name|public
operator|:
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentTuple
name|ArgumentTuple
expr_stmt|;
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentMatcherTuple
name|ArgumentMatcherTuple
expr_stmt|;
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
name|TypedExpectation
argument_list|(
argument|FunctionMockerBase<F>* owner
argument_list|,
argument|const char* a_file
argument_list|,
argument|int a_line
argument_list|,
argument|const string& a_source_text
argument_list|,
argument|const ArgumentMatcherTuple& m
argument_list|)
block|:
name|ExpectationBase
argument_list|(
name|a_file
argument_list|,
name|a_line
argument_list|,
name|a_source_text
argument_list|)
operator|,
name|owner_
argument_list|(
name|owner
argument_list|)
operator|,
name|matchers_
argument_list|(
name|m
argument_list|)
operator|,
comment|// By default, extra_matcher_ should match anything.  However,
comment|// we cannot initialize it with _ as that triggers a compiler
comment|// bug in Symbian's C++ compiler (cannot decide between two
comment|// overloaded constructors of Matcher<const ArgumentTuple&>).
name|extra_matcher_
argument_list|(
name|A
operator|<
specifier|const
name|ArgumentTuple
operator|&
operator|>
operator|(
operator|)
argument_list|)
operator|,
name|repeated_action_
argument_list|(
argument|DoDefault()
argument_list|)
block|{}
name|virtual
operator|~
name|TypedExpectation
argument_list|()
block|{
comment|// Check the validity of the action count if it hasn't been done
comment|// yet (for example, if the expectation was never used).
name|CheckActionCountIfNotDone
argument_list|()
block|;
for|for
control|(
name|UntypedActions
operator|::
name|const_iterator
name|it
operator|=
name|untyped_actions_
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|untyped_actions_
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|delete
name|static_cast
operator|<
specifier|const
name|Action
operator|<
name|F
operator|>
operator|*
operator|>
operator|(
operator|*
name|it
operator|)
expr_stmt|;
block|}
block|}
comment|// Implements the .With() clause.
name|TypedExpectation
operator|&
name|With
argument_list|(
argument|const Matcher<const ArgumentTuple&>& m
argument_list|)
block|{
if|if
condition|(
name|last_clause_
operator|==
name|kWith
condition|)
block|{
name|ExpectSpecProperty
argument_list|(
name|false
argument_list|,
literal|".With() cannot appear "
literal|"more than once in an EXPECT_CALL()."
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ExpectSpecProperty
argument_list|(
name|last_clause_
operator|<
name|kWith
argument_list|,
literal|".With() must be the first "
literal|"clause in an EXPECT_CALL()."
argument_list|)
expr_stmt|;
block|}
name|last_clause_
operator|=
name|kWith
expr_stmt|;
name|extra_matcher_
operator|=
name|m
expr_stmt|;
name|extra_matcher_specified_
operator|=
name|true
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_comment
comment|// Implements the .Times() clause.
end_comment

begin_function
name|TypedExpectation
modifier|&
name|Times
parameter_list|(
specifier|const
name|Cardinality
modifier|&
name|a_cardinality
parameter_list|)
block|{
name|ExpectationBase
operator|::
name|UntypedTimes
argument_list|(
name|a_cardinality
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function

begin_comment
comment|// Implements the .Times() clause.
end_comment

begin_function
name|TypedExpectation
modifier|&
name|Times
parameter_list|(
name|int
name|n
parameter_list|)
block|{
return|return
name|Times
argument_list|(
name|Exactly
argument_list|(
name|n
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Implements the .InSequence() clause.
end_comment

begin_function
name|TypedExpectation
modifier|&
name|InSequence
parameter_list|(
specifier|const
name|Sequence
modifier|&
name|s
parameter_list|)
block|{
name|ExpectSpecProperty
argument_list|(
name|last_clause_
operator|<=
name|kInSequence
argument_list|,
literal|".InSequence() cannot appear after .After(),"
literal|" .WillOnce(), .WillRepeatedly(), or "
literal|".RetiresOnSaturation()."
argument_list|)
expr_stmt|;
name|last_clause_
operator|=
name|kInSequence
expr_stmt|;
name|s
operator|.
name|AddExpectation
argument_list|(
name|GetHandle
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function

begin_function
name|TypedExpectation
modifier|&
name|InSequence
parameter_list|(
specifier|const
name|Sequence
modifier|&
name|s1
parameter_list|,
specifier|const
name|Sequence
modifier|&
name|s2
parameter_list|)
block|{
return|return
name|InSequence
argument_list|(
name|s1
argument_list|)
operator|.
name|InSequence
argument_list|(
name|s2
argument_list|)
return|;
block|}
end_function

begin_function
name|TypedExpectation
modifier|&
name|InSequence
parameter_list|(
specifier|const
name|Sequence
modifier|&
name|s1
parameter_list|,
specifier|const
name|Sequence
modifier|&
name|s2
parameter_list|,
specifier|const
name|Sequence
modifier|&
name|s3
parameter_list|)
block|{
return|return
name|InSequence
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
operator|.
name|InSequence
argument_list|(
name|s3
argument_list|)
return|;
block|}
end_function

begin_function
name|TypedExpectation
modifier|&
name|InSequence
parameter_list|(
specifier|const
name|Sequence
modifier|&
name|s1
parameter_list|,
specifier|const
name|Sequence
modifier|&
name|s2
parameter_list|,
specifier|const
name|Sequence
modifier|&
name|s3
parameter_list|,
specifier|const
name|Sequence
modifier|&
name|s4
parameter_list|)
block|{
return|return
name|InSequence
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|,
name|s3
argument_list|)
operator|.
name|InSequence
argument_list|(
name|s4
argument_list|)
return|;
block|}
end_function

begin_function
name|TypedExpectation
modifier|&
name|InSequence
parameter_list|(
specifier|const
name|Sequence
modifier|&
name|s1
parameter_list|,
specifier|const
name|Sequence
modifier|&
name|s2
parameter_list|,
specifier|const
name|Sequence
modifier|&
name|s3
parameter_list|,
specifier|const
name|Sequence
modifier|&
name|s4
parameter_list|,
specifier|const
name|Sequence
modifier|&
name|s5
parameter_list|)
block|{
return|return
name|InSequence
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|,
name|s3
argument_list|,
name|s4
argument_list|)
operator|.
name|InSequence
argument_list|(
name|s5
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Implements that .After() clause.
end_comment

begin_function
name|TypedExpectation
modifier|&
name|After
parameter_list|(
specifier|const
name|ExpectationSet
modifier|&
name|s
parameter_list|)
block|{
name|ExpectSpecProperty
argument_list|(
name|last_clause_
operator|<=
name|kAfter
argument_list|,
literal|".After() cannot appear after .WillOnce(),"
literal|" .WillRepeatedly(), or "
literal|".RetiresOnSaturation()."
argument_list|)
expr_stmt|;
name|last_clause_
operator|=
name|kAfter
expr_stmt|;
for|for
control|(
name|ExpectationSet
operator|::
name|const_iterator
name|it
operator|=
name|s
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|s
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|immediate_prerequisites_
operator|+=
operator|*
name|it
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_function

begin_function
name|TypedExpectation
modifier|&
name|After
parameter_list|(
specifier|const
name|ExpectationSet
modifier|&
name|s1
parameter_list|,
specifier|const
name|ExpectationSet
modifier|&
name|s2
parameter_list|)
block|{
return|return
name|After
argument_list|(
name|s1
argument_list|)
operator|.
name|After
argument_list|(
name|s2
argument_list|)
return|;
block|}
end_function

begin_function
name|TypedExpectation
modifier|&
name|After
parameter_list|(
specifier|const
name|ExpectationSet
modifier|&
name|s1
parameter_list|,
specifier|const
name|ExpectationSet
modifier|&
name|s2
parameter_list|,
specifier|const
name|ExpectationSet
modifier|&
name|s3
parameter_list|)
block|{
return|return
name|After
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
operator|.
name|After
argument_list|(
name|s3
argument_list|)
return|;
block|}
end_function

begin_function
name|TypedExpectation
modifier|&
name|After
parameter_list|(
specifier|const
name|ExpectationSet
modifier|&
name|s1
parameter_list|,
specifier|const
name|ExpectationSet
modifier|&
name|s2
parameter_list|,
specifier|const
name|ExpectationSet
modifier|&
name|s3
parameter_list|,
specifier|const
name|ExpectationSet
modifier|&
name|s4
parameter_list|)
block|{
return|return
name|After
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|,
name|s3
argument_list|)
operator|.
name|After
argument_list|(
name|s4
argument_list|)
return|;
block|}
end_function

begin_function
name|TypedExpectation
modifier|&
name|After
parameter_list|(
specifier|const
name|ExpectationSet
modifier|&
name|s1
parameter_list|,
specifier|const
name|ExpectationSet
modifier|&
name|s2
parameter_list|,
specifier|const
name|ExpectationSet
modifier|&
name|s3
parameter_list|,
specifier|const
name|ExpectationSet
modifier|&
name|s4
parameter_list|,
specifier|const
name|ExpectationSet
modifier|&
name|s5
parameter_list|)
block|{
return|return
name|After
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|,
name|s3
argument_list|,
name|s4
argument_list|)
operator|.
name|After
argument_list|(
name|s5
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Implements the .WillOnce() clause.
end_comment

begin_decl_stmt
name|TypedExpectation
modifier|&
name|WillOnce
argument_list|(
specifier|const
name|Action
operator|<
name|F
operator|>
operator|&
name|action
argument_list|)
block|{
name|ExpectSpecProperty
argument_list|(
name|last_clause_
operator|<=
name|kWillOnce
argument_list|,
literal|".WillOnce() cannot appear after "
literal|".WillRepeatedly() or .RetiresOnSaturation()."
argument_list|)
expr_stmt|;
name|last_clause_
operator|=
name|kWillOnce
expr_stmt|;
name|untyped_actions_
operator|.
name|push_back
argument_list|(
argument|new Action<F>(action)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|cardinality_specified
argument_list|()
condition|)
block|{
name|set_cardinality
argument_list|(
name|Exactly
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|untyped_actions_
operator|.
name|size
argument_list|()
operator|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_comment
comment|// Implements the .WillRepeatedly() clause.
end_comment

begin_decl_stmt
name|TypedExpectation
modifier|&
name|WillRepeatedly
argument_list|(
specifier|const
name|Action
operator|<
name|F
operator|>
operator|&
name|action
argument_list|)
block|{
if|if
condition|(
name|last_clause_
operator|==
name|kWillRepeatedly
condition|)
block|{
name|ExpectSpecProperty
argument_list|(
name|false
argument_list|,
literal|".WillRepeatedly() cannot appear "
literal|"more than once in an EXPECT_CALL()."
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ExpectSpecProperty
argument_list|(
name|last_clause_
operator|<
name|kWillRepeatedly
argument_list|,
literal|".WillRepeatedly() cannot appear "
literal|"after .RetiresOnSaturation()."
argument_list|)
expr_stmt|;
block|}
name|last_clause_
operator|=
name|kWillRepeatedly
expr_stmt|;
name|repeated_action_specified_
operator|=
name|true
expr_stmt|;
name|repeated_action_
operator|=
name|action
expr_stmt|;
if|if
condition|(
operator|!
name|cardinality_specified
argument_list|()
condition|)
block|{
name|set_cardinality
argument_list|(
name|AtLeast
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|untyped_actions_
operator|.
name|size
argument_list|()
operator|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Now that no more action clauses can be specified, we check
comment|// whether their count makes sense.
name|CheckActionCountIfNotDone
argument_list|()
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_comment
comment|// Implements the .RetiresOnSaturation() clause.
end_comment

begin_function
name|TypedExpectation
modifier|&
name|RetiresOnSaturation
parameter_list|()
block|{
name|ExpectSpecProperty
argument_list|(
name|last_clause_
operator|<
name|kRetiresOnSaturation
argument_list|,
literal|".RetiresOnSaturation() cannot appear "
literal|"more than once."
argument_list|)
expr_stmt|;
name|last_clause_
operator|=
name|kRetiresOnSaturation
expr_stmt|;
name|retires_on_saturation_
operator|=
name|true
expr_stmt|;
comment|// Now that no more action clauses can be specified, we check
comment|// whether their count makes sense.
name|CheckActionCountIfNotDone
argument_list|()
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function

begin_comment
comment|// Returns the matchers for the arguments as specified inside the
end_comment

begin_comment
comment|// EXPECT_CALL() macro.
end_comment

begin_expr_stmt
specifier|const
name|ArgumentMatcherTuple
operator|&
name|matchers
argument_list|()
specifier|const
block|{
return|return
name|matchers_
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns the matcher specified by the .With() clause.
end_comment

begin_expr_stmt
specifier|const
name|Matcher
operator|<
specifier|const
name|ArgumentTuple
operator|&
operator|>
operator|&
name|extra_matcher
argument_list|()
specifier|const
block|{
return|return
name|extra_matcher_
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns the action specified by the .WillRepeatedly() clause.
end_comment

begin_expr_stmt
specifier|const
name|Action
operator|<
name|F
operator|>
operator|&
name|repeated_action
argument_list|()
specifier|const
block|{
return|return
name|repeated_action_
return|;
block|}
end_expr_stmt

begin_comment
comment|// If this mock method has an extra matcher (i.e. .With(matcher)),
end_comment

begin_comment
comment|// describes it to the ostream.
end_comment

begin_decl_stmt
name|virtual
name|void
name|MaybeDescribeExtraMatcherTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
block|{
if|if
condition|(
name|extra_matcher_specified_
condition|)
block|{
operator|*
name|os
operator|<<
literal|"    Expected args: "
expr_stmt|;
name|extra_matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
expr_stmt|;
operator|*
name|os
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|template
operator|<
name|typename
name|Function
operator|>
name|friend
name|class
name|FunctionMockerBase
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Returns an Expectation object that references and co-owns this
end_comment

begin_comment
comment|// expectation.
end_comment

begin_function
name|virtual
name|Expectation
name|GetHandle
parameter_list|()
block|{
return|return
name|owner_
operator|->
name|GetHandleOf
argument_list|(
name|this
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// The following methods will be called only after the EXPECT_CALL()
end_comment

begin_comment
comment|// statement finishes and when the current thread holds
end_comment

begin_comment
comment|// g_gmock_mutex.
end_comment

begin_comment
comment|// Returns true iff this expectation matches the given arguments.
end_comment

begin_decl_stmt
name|bool
name|Matches
argument_list|(
specifier|const
name|ArgumentTuple
operator|&
name|args
argument_list|)
decl|const
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
name|g_gmock_mutex
argument_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
expr_stmt|;
return|return
name|TupleMatches
argument_list|(
name|matchers_
argument_list|,
name|args
argument_list|)
operator|&&
name|extra_matcher_
operator|.
name|Matches
argument_list|(
name|args
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Returns true iff this expectation should handle the given arguments.
end_comment

begin_decl_stmt
name|bool
name|ShouldHandleArguments
argument_list|(
specifier|const
name|ArgumentTuple
operator|&
name|args
argument_list|)
decl|const
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
name|g_gmock_mutex
argument_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
expr_stmt|;
comment|// In case the action count wasn't checked when the expectation
comment|// was defined (e.g. if this expectation has no WillRepeatedly()
comment|// or RetiresOnSaturation() clause), we check it when the
comment|// expectation is used for the first time.
name|CheckActionCountIfNotDone
argument_list|()
expr_stmt|;
return|return
operator|!
name|is_retired
argument_list|()
operator|&&
name|AllPrerequisitesAreSatisfied
argument_list|()
operator|&&
name|Matches
argument_list|(
name|args
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Describes the result of matching the arguments against this
end_comment

begin_comment
comment|// expectation to the given ostream.
end_comment

begin_decl_stmt
name|void
name|ExplainMatchResultTo
argument_list|(
specifier|const
name|ArgumentTuple
operator|&
name|args
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
name|g_gmock_mutex
argument_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
expr_stmt|;
if|if
condition|(
name|is_retired
argument_list|()
condition|)
block|{
operator|*
name|os
operator|<<
literal|"         Expected: the expectation is active\n"
operator|<<
literal|"           Actual: it is retired\n"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|Matches
argument_list|(
name|args
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|TupleMatches
argument_list|(
name|matchers_
argument_list|,
name|args
argument_list|)
condition|)
block|{
name|ExplainMatchFailureTupleTo
argument_list|(
name|matchers_
argument_list|,
name|args
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
name|StringMatchResultListener
name|listener
decl_stmt|;
if|if
condition|(
operator|!
name|extra_matcher_
operator|.
name|MatchAndExplain
argument_list|(
name|args
argument_list|,
operator|&
name|listener
argument_list|)
condition|)
block|{
operator|*
name|os
operator|<<
literal|"    Expected args: "
expr_stmt|;
name|extra_matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
expr_stmt|;
operator|*
name|os
operator|<<
literal|"\n           Actual: don't match"
expr_stmt|;
name|internal
operator|::
name|PrintIfNotEmpty
argument_list|(
name|listener
operator|.
name|str
argument_list|()
argument_list|,
name|os
argument_list|)
expr_stmt|;
operator|*
name|os
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
operator|!
name|AllPrerequisitesAreSatisfied
argument_list|()
condition|)
block|{
operator|*
name|os
operator|<<
literal|"         Expected: all pre-requisites are satisfied\n"
operator|<<
literal|"           Actual: the following immediate pre-requisites "
operator|<<
literal|"are not satisfied:\n"
expr_stmt|;
name|ExpectationSet
name|unsatisfied_prereqs
decl_stmt|;
name|FindUnsatisfiedPrerequisites
argument_list|(
operator|&
name|unsatisfied_prereqs
argument_list|)
expr_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
for|for
control|(
name|ExpectationSet
operator|::
name|const_iterator
name|it
operator|=
name|unsatisfied_prereqs
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|unsatisfied_prereqs
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|it
operator|->
name|expectation_base
argument_list|()
operator|->
name|DescribeLocationTo
argument_list|(
name|os
argument_list|)
expr_stmt|;
operator|*
name|os
operator|<<
literal|"pre-requisite #"
operator|<<
name|i
operator|++
operator|<<
literal|"\n"
expr_stmt|;
block|}
operator|*
name|os
operator|<<
literal|"                   (end of pre-requisites)\n"
expr_stmt|;
block|}
else|else
block|{
comment|// This line is here just for completeness' sake.  It will never
comment|// be executed as currently the ExplainMatchResultTo() function
comment|// is called only when the mock function call does NOT match the
comment|// expectation.
operator|*
name|os
operator|<<
literal|"The call matches the expectation.\n"
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// Returns the action that should be taken for the current invocation.
end_comment

begin_expr_stmt
specifier|const
name|Action
operator|<
name|F
operator|>
operator|&
name|GetCurrentAction
argument_list|(
argument|const FunctionMockerBase<F>* mocker
argument_list|,
argument|const ArgumentTuple& args
argument_list|)
specifier|const
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
argument|g_gmock_mutex
argument_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
block|;
specifier|const
name|int
name|count
operator|=
name|call_count
argument_list|()
block|;
name|Assert
argument_list|(
name|count
operator|>=
literal|1
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|,
literal|"call_count() is<= 0 when GetCurrentAction() is "
literal|"called - this should never happen."
argument_list|)
block|;
specifier|const
name|int
name|action_count
operator|=
name|static_cast
operator|<
name|int
operator|>
operator|(
name|untyped_actions_
operator|.
name|size
argument_list|()
operator|)
block|;
if|if
condition|(
name|action_count
operator|>
literal|0
operator|&&
operator|!
name|repeated_action_specified_
operator|&&
name|count
operator|>
name|action_count
condition|)
block|{
comment|// If there is at least one WillOnce() and no WillRepeatedly(),
comment|// we warn the user when the WillOnce() clauses ran out.
operator|::
name|std
operator|::
name|stringstream
name|ss
expr_stmt|;
name|DescribeLocationTo
argument_list|(
operator|&
name|ss
argument_list|)
expr_stmt|;
name|ss
operator|<<
literal|"Actions ran out in "
operator|<<
name|source_text
argument_list|()
operator|<<
literal|"...\n"
operator|<<
literal|"Called "
operator|<<
name|count
operator|<<
literal|" times, but only "
operator|<<
name|action_count
operator|<<
literal|" WillOnce()"
operator|<<
operator|(
name|action_count
operator|==
literal|1
condition|?
literal|" is"
else|:
literal|"s are"
operator|)
operator|<<
literal|" specified - "
expr_stmt|;
name|mocker
operator|->
name|DescribeDefaultActionTo
argument_list|(
name|args
argument_list|,
operator|&
name|ss
argument_list|)
expr_stmt|;
name|Log
argument_list|(
name|kWarning
argument_list|,
name|ss
operator|.
name|str
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|count
operator|<=
name|action_count
condition|?
operator|*
name|static_cast
operator|<
specifier|const
name|Action
operator|<
name|F
operator|>
operator|*
operator|>
operator|(
name|untyped_actions_
index|[
name|count
operator|-
literal|1
index|]
operator|)
else|:
name|repeated_action
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|// Given the arguments of a mock function call, if the call will
end_comment

begin_comment
comment|// over-saturate this expectation, returns the default action;
end_comment

begin_comment
comment|// otherwise, returns the next action in this expectation.  Also
end_comment

begin_comment
comment|// describes *what* happened to 'what', and explains *why* Google
end_comment

begin_comment
comment|// Mock does it to 'why'.  This method is not const as it calls
end_comment

begin_comment
comment|// IncrementCallCount().  A return value of NULL means the default
end_comment

begin_comment
comment|// action.
end_comment

begin_expr_stmt
unit|const
name|Action
operator|<
name|F
operator|>
operator|*
name|GetActionForArguments
argument_list|(
argument|const FunctionMockerBase<F>* mocker
argument_list|,
argument|const ArgumentTuple& args
argument_list|,
argument|::std::ostream* what
argument_list|,
argument|::std::ostream* why
argument_list|)
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
argument|g_gmock_mutex
argument_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
block|;
if|if
condition|(
name|IsSaturated
argument_list|()
condition|)
block|{
comment|// We have an excessive call.
name|IncrementCallCount
argument_list|()
expr_stmt|;
operator|*
name|what
operator|<<
literal|"Mock function called more times than expected - "
expr_stmt|;
name|mocker
operator|->
name|DescribeDefaultActionTo
argument_list|(
name|args
argument_list|,
name|what
argument_list|)
expr_stmt|;
name|DescribeCallCountTo
argument_list|(
name|why
argument_list|)
expr_stmt|;
comment|// TODO(wan@google.com): allow the user to control whether
comment|// unexpected calls should fail immediately or continue using a
comment|// flag --gmock_unexpected_calls_are_fatal.
return|return
name|NULL
return|;
block|}
name|IncrementCallCount
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RetireAllPreRequisites
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|retires_on_saturation_
operator|&&
name|IsSaturated
argument_list|()
condition|)
block|{
name|Retire
argument_list|()
expr_stmt|;
block|}
end_if

begin_comment
comment|// Must be done after IncrementCount()!
end_comment

begin_expr_stmt
operator|*
name|what
operator|<<
literal|"Mock function call matches "
operator|<<
name|source_text
argument_list|()
operator|<<
literal|"...\n"
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|&
operator|(
name|GetCurrentAction
argument_list|(
name|mocker
argument_list|,
name|args
argument_list|)
operator|)
return|;
end_return

begin_comment
unit|}
comment|// All the fields below won't change once the EXPECT_CALL()
end_comment

begin_comment
comment|// statement finishes.
end_comment

begin_expr_stmt
unit|FunctionMockerBase
operator|<
name|F
operator|>
operator|*
specifier|const
name|owner_
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ArgumentMatcherTuple
name|matchers_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|Matcher
operator|<
specifier|const
name|ArgumentTuple
operator|&
operator|>
name|extra_matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Action
operator|<
name|F
operator|>
name|repeated_action_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|TypedExpectation
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// class TypedExpectation
end_comment

begin_comment
comment|// A MockSpec object is used by ON_CALL() or EXPECT_CALL() for
end_comment

begin_comment
comment|// specifying the default behavior of, or expectation on, a mock
end_comment

begin_comment
comment|// function.
end_comment

begin_comment
comment|// Note: class MockSpec really belongs to the ::testing namespace.
end_comment

begin_comment
comment|// However if we define it in ::testing, MSVC will complain when
end_comment

begin_comment
comment|// classes in ::testing::internal declare it as a friend class
end_comment

begin_comment
comment|// template.  To workaround this compiler bug, we define MockSpec in
end_comment

begin_comment
comment|// ::testing::internal and import it into ::testing.
end_comment

begin_comment
comment|// Logs a message including file and line number information.
end_comment

begin_decl_stmt
name|GTEST_API_
name|void
name|LogWithLocation
argument_list|(
name|testing
operator|::
name|internal
operator|::
name|LogSeverity
name|severity
argument_list|,
specifier|const
name|char
operator|*
name|file
argument_list|,
name|int
name|line
argument_list|,
specifier|const
name|string
operator|&
name|message
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|F
operator|>
name|class
name|MockSpec
block|{
name|public
operator|:
typedef|typedef
name|typename
name|internal
operator|::
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentTuple
name|ArgumentTuple
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|internal
operator|::
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentMatcherTuple
name|ArgumentMatcherTuple
expr_stmt|;
end_typedef

begin_comment
comment|// Constructs a MockSpec object, given the function mocker object
end_comment

begin_comment
comment|// that the spec is associated with.
end_comment

begin_decl_stmt
name|explicit
name|MockSpec
argument_list|(
name|internal
operator|::
name|FunctionMockerBase
operator|<
name|F
operator|>
operator|*
name|function_mocker
argument_list|)
range|:
name|function_mocker_
argument_list|(
argument|function_mocker
argument_list|)
block|{}
comment|// Adds a new default action spec to the function mocker and returns
comment|// the newly created spec.
name|internal
operator|::
name|OnCallSpec
operator|<
name|F
operator|>
operator|&
name|InternalDefaultActionSetAt
argument_list|(
argument|const char* file
argument_list|,
argument|int line
argument_list|,
argument|const char* obj
argument_list|,
argument|const char* call
argument_list|)
block|{
name|LogWithLocation
argument_list|(
name|internal
operator|::
name|kInfo
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|string
argument_list|(
literal|"ON_CALL("
argument_list|)
operator|+
name|obj
operator|+
literal|", "
operator|+
name|call
operator|+
literal|") invoked"
argument_list|)
block|;
return|return
name|function_mocker_
operator|->
name|AddNewOnCallSpec
argument_list|(
name|file
argument_list|,
name|line
argument_list|,
name|matchers_
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Adds a new expectation spec to the function mocker and returns
end_comment

begin_comment
comment|// the newly created spec.
end_comment

begin_expr_stmt
name|internal
operator|::
name|TypedExpectation
operator|<
name|F
operator|>
operator|&
name|InternalExpectedAt
argument_list|(
argument|const char* file
argument_list|,
argument|int line
argument_list|,
argument|const char* obj
argument_list|,
argument|const char* call
argument_list|)
block|{
specifier|const
name|string
name|source_text
argument_list|(
name|string
argument_list|(
literal|"EXPECT_CALL("
argument_list|)
operator|+
name|obj
operator|+
literal|", "
operator|+
name|call
operator|+
literal|")"
argument_list|)
block|;
name|LogWithLocation
argument_list|(
name|internal
operator|::
name|kInfo
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|source_text
operator|+
literal|" invoked"
argument_list|)
block|;
return|return
name|function_mocker_
operator|->
name|AddNewExpectation
argument_list|(
name|file
argument_list|,
name|line
argument_list|,
name|source_text
argument_list|,
name|matchers_
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|template
operator|<
name|typename
name|Function
operator|>
name|friend
name|class
name|internal
operator|::
name|FunctionMocker
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|SetMatchers
parameter_list|(
specifier|const
name|ArgumentMatcherTuple
modifier|&
name|matchers
parameter_list|)
block|{
name|matchers_
operator|=
name|matchers
expr_stmt|;
block|}
end_function

begin_comment
comment|// The function mocker that owns this spec.
end_comment

begin_expr_stmt
name|internal
operator|::
name|FunctionMockerBase
operator|<
name|F
operator|>
operator|*
specifier|const
name|function_mocker_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The argument matchers specified in the spec.
end_comment

begin_decl_stmt
name|ArgumentMatcherTuple
name|matchers_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|MockSpec
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// class MockSpec
end_comment

begin_comment
comment|// Wrapper type for generically holding an ordinary value or lvalue reference.
end_comment

begin_comment
comment|// If T is not a reference type, it must be copyable or movable.
end_comment

begin_comment
comment|// ReferenceOrValueWrapper<T> is movable, and will also be copyable unless
end_comment

begin_comment
comment|// T is a move-only value type (which means that it will always be copyable
end_comment

begin_comment
comment|// if the current platform does not support move semantics).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The primary template defines handling for values, but function header
end_comment

begin_comment
comment|// comments describe the contract for the whole template (including
end_comment

begin_comment
comment|// specializations).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ReferenceOrValueWrapper
block|{
name|public
operator|:
comment|// Constructs a wrapper from the given value/reference.
name|explicit
name|ReferenceOrValueWrapper
argument_list|(
argument|T value
argument_list|)
operator|:
name|value_
argument_list|(
argument|::testing::internal::move(value)
argument_list|)
block|{   }
comment|// Unwraps and returns the underlying value/reference, exactly as
comment|// originally passed. The behavior of calling this more than once on
comment|// the same object is unspecified.
name|T
name|Unwrap
argument_list|()
block|{
return|return
operator|::
name|testing
operator|::
name|internal
operator|::
name|move
argument_list|(
name|value_
argument_list|)
return|;
block|}
comment|// Provides nondestructive access to the underlying value/reference.
comment|// Always returns a const reference (more precisely,
comment|// const RemoveReference<T>&). The behavior of calling this after
comment|// calling Unwrap on the same object is unspecified.
specifier|const
name|T
operator|&
name|Peek
argument_list|()
specifier|const
block|{
return|return
name|value_
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|T
name|value_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// Specialization for lvalue reference types. See primary template
end_comment

begin_comment
comment|// for documentation.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ReferenceOrValueWrapper
operator|<
name|T
operator|&
operator|>
block|{
name|public
operator|:
comment|// Workaround for debatable pass-by-reference lint warning (c-library-team
comment|// policy precludes NOLINT in this context)
typedef|typedef
name|T
modifier|&
name|reference
typedef|;
name|explicit
name|ReferenceOrValueWrapper
argument_list|(
argument|reference ref
argument_list|)
operator|:
name|value_ptr_
argument_list|(
argument|&ref
argument_list|)
block|{}
name|T
operator|&
name|Unwrap
argument_list|()
block|{
return|return
operator|*
name|value_ptr_
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|T
operator|&
name|Peek
argument_list|()
specifier|const
block|{
return|return
operator|*
name|value_ptr_
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|T
modifier|*
name|value_ptr_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// MSVC warns about using 'this' in base member initializer list, so
end_comment

begin_comment
comment|// we need to temporarily disable the warning.  We have to do it for
end_comment

begin_comment
comment|// the entire class to suppress the warning, even though it's about
end_comment

begin_comment
comment|// the constructor only.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
end_pragma

begin_comment
comment|// Saves the current warning state.
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4355
name|)
end_pragma

begin_comment
comment|// Temporarily disables warning 4355.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _MSV_VER
end_comment

begin_comment
comment|// C++ treats the void type specially.  For example, you cannot define
end_comment

begin_comment
comment|// a void-typed variable or pass a void value to a function.
end_comment

begin_comment
comment|// ActionResultHolder<T> holds a value of type T, where T must be a
end_comment

begin_comment
comment|// copyable type or void (T doesn't need to be default-constructable).
end_comment

begin_comment
comment|// It hides the syntactic difference between void and other types, and
end_comment

begin_comment
comment|// is used to unify the code for invoking both void-returning and
end_comment

begin_comment
comment|// non-void-returning mock functions.
end_comment

begin_comment
comment|// Untyped base class for ActionResultHolder<T>.
end_comment

begin_decl_stmt
name|class
name|UntypedActionResultHolderBase
block|{
name|public
label|:
name|virtual
operator|~
name|UntypedActionResultHolderBase
argument_list|()
block|{}
comment|// Prints the held value as an action's result to os.
name|virtual
name|void
name|PrintAsActionResult
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// This generic definition is used when T is not void.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ActionResultHolder
operator|:
name|public
name|UntypedActionResultHolderBase
block|{
name|public
operator|:
comment|// Returns the held value. Must not be called more than once.
name|T
name|Unwrap
argument_list|()
block|{
return|return
name|result_
operator|.
name|Unwrap
argument_list|()
return|;
block|}
comment|// Prints the held value as an action's result to os.
name|virtual
name|void
name|PrintAsActionResult
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"\n          Returns: "
block|;
comment|// T may be a reference type, so we don't use UniversalPrint().
name|UniversalPrinter
operator|<
name|T
operator|>
operator|::
name|Print
argument_list|(
name|result_
operator|.
name|Peek
argument_list|()
argument_list|,
name|os
argument_list|)
block|;   }
comment|// Performs the given mock function's default action and returns the
comment|// result in a new-ed ActionResultHolder.
name|template
operator|<
name|typename
name|F
operator|>
specifier|static
name|ActionResultHolder
operator|*
name|PerformDefaultAction
argument_list|(
argument|const FunctionMockerBase<F>* func_mocker
argument_list|,
argument|const typename Function<F>::ArgumentTuple& args
argument_list|,
argument|const string& call_description
argument_list|)
block|{
return|return
name|new
name|ActionResultHolder
argument_list|(
name|Wrapper
argument_list|(
name|func_mocker
operator|->
name|PerformDefaultAction
argument_list|(
name|args
argument_list|,
name|call_description
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Performs the given action and returns the result in a new-ed
end_comment

begin_comment
comment|// ActionResultHolder.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|F
operator|>
specifier|static
name|ActionResultHolder
operator|*
name|PerformAction
argument_list|(
argument|const Action<F>& action
argument_list|,
argument|const typename Function<F>::ArgumentTuple& args
argument_list|)
block|{
return|return
name|new
name|ActionResultHolder
argument_list|(
name|Wrapper
argument_list|(
name|action
operator|.
name|Perform
argument_list|(
name|args
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_typedef
typedef|typedef
name|ReferenceOrValueWrapper
operator|<
name|T
operator|>
name|Wrapper
expr_stmt|;
end_typedef

begin_macro
name|explicit
end_macro

begin_macro
name|ActionResultHolder
argument_list|(
argument|Wrapper result
argument_list|)
end_macro

begin_macro
unit|:
name|result_
argument_list|(
argument|::testing::internal::move(result)
argument_list|)
end_macro

begin_block
block|{   }
end_block

begin_decl_stmt
name|Wrapper
name|result_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ActionResultHolder
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Specialization for T = void.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|ActionResultHolder
operator|<
name|void
operator|>
operator|:
name|public
name|UntypedActionResultHolderBase
block|{
name|public
operator|:
name|void
name|Unwrap
argument_list|()
block|{ }
name|virtual
name|void
name|PrintAsActionResult
argument_list|(
argument|::std::ostream*
comment|/* os */
argument_list|)
specifier|const
block|{}
comment|// Performs the given mock function's default action and returns ownership
comment|// of an empty ActionResultHolder*.
name|template
operator|<
name|typename
name|F
operator|>
specifier|static
name|ActionResultHolder
operator|*
name|PerformDefaultAction
argument_list|(
argument|const FunctionMockerBase<F>* func_mocker
argument_list|,
argument|const typename Function<F>::ArgumentTuple& args
argument_list|,
argument|const string& call_description
argument_list|)
block|{
name|func_mocker
operator|->
name|PerformDefaultAction
argument_list|(
name|args
argument_list|,
name|call_description
argument_list|)
block|;
return|return
name|new
name|ActionResultHolder
return|;
block|}
comment|// Performs the given action and returns ownership of an empty
comment|// ActionResultHolder*.
name|template
operator|<
name|typename
name|F
operator|>
specifier|static
name|ActionResultHolder
operator|*
name|PerformAction
argument_list|(
argument|const Action<F>& action
argument_list|,
argument|const typename Function<F>::ArgumentTuple& args
argument_list|)
block|{
name|action
operator|.
name|Perform
argument_list|(
name|args
argument_list|)
block|;
return|return
name|new
name|ActionResultHolder
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_macro
name|ActionResultHolder
argument_list|()
end_macro

begin_block
block|{}
end_block

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ActionResultHolder
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// The base of the function mocker class for the given function type.
end_comment

begin_comment
comment|// We put the methods in this class instead of its child to avoid code
end_comment

begin_comment
comment|// bloat.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|F
operator|>
name|class
name|FunctionMockerBase
operator|:
name|public
name|UntypedFunctionMockerBase
block|{
name|public
operator|:
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentTuple
name|ArgumentTuple
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentMatcherTuple
name|ArgumentMatcherTuple
expr_stmt|;
end_typedef

begin_expr_stmt
name|FunctionMockerBase
argument_list|()
operator|:
name|current_spec_
argument_list|(
argument|this
argument_list|)
block|{}
comment|// The destructor verifies that all expectations on this mock
comment|// function have been satisfied.  If not, it will report Google Test
comment|// non-fatal failures for the violations.
name|virtual
operator|~
name|FunctionMockerBase
argument_list|()
name|GTEST_LOCK_EXCLUDED_
argument_list|(
argument|g_gmock_mutex
argument_list|)
block|{
name|MutexLock
name|l
argument_list|(
operator|&
name|g_gmock_mutex
argument_list|)
block|;
name|VerifyAndClearExpectationsLocked
argument_list|()
block|;
name|Mock
operator|::
name|UnregisterLocked
argument_list|(
name|this
argument_list|)
block|;
name|ClearDefaultActionsLocked
argument_list|()
block|;   }
comment|// Returns the ON_CALL spec that matches this mock function with the
comment|// given arguments; returns NULL if no matching ON_CALL is found.
comment|// L = *
specifier|const
name|OnCallSpec
operator|<
name|F
operator|>
operator|*
name|FindOnCallSpec
argument_list|(
argument|const ArgumentTuple& args
argument_list|)
specifier|const
block|{
for|for
control|(
name|UntypedOnCallSpecs
operator|::
name|const_reverse_iterator
name|it
operator|=
name|untyped_on_call_specs_
operator|.
name|rbegin
argument_list|()
init|;
name|it
operator|!=
name|untyped_on_call_specs_
operator|.
name|rend
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
specifier|const
name|OnCallSpec
operator|<
name|F
operator|>
operator|*
name|spec
operator|=
name|static_cast
operator|<
specifier|const
name|OnCallSpec
operator|<
name|F
operator|>
operator|*
operator|>
operator|(
operator|*
name|it
operator|)
expr_stmt|;
if|if
condition|(
name|spec
operator|->
name|Matches
argument_list|(
name|args
argument_list|)
condition|)
return|return
name|spec
return|;
block|}
end_expr_stmt

begin_return
return|return
name|NULL
return|;
end_return

begin_comment
unit|}
comment|// Performs the default action of this mock function on the given
end_comment

begin_comment
comment|// arguments and returns the result. Asserts (or throws if
end_comment

begin_comment
comment|// exceptions are enabled) with a helpful call descrption if there
end_comment

begin_comment
comment|// is no valid return value. This method doesn't depend on the
end_comment

begin_comment
comment|// mutable state of this object, and thus can be called concurrently
end_comment

begin_comment
comment|// without locking.
end_comment

begin_comment
comment|// L = *
end_comment

begin_macro
unit|Result
name|PerformDefaultAction
argument_list|(
argument|const ArgumentTuple& args
argument_list|,
argument|const string& call_description
argument_list|)
end_macro

begin_expr_stmt
specifier|const
block|{
specifier|const
name|OnCallSpec
operator|<
name|F
operator|>
operator|*
specifier|const
name|spec
operator|=
name|this
operator|->
name|FindOnCallSpec
argument_list|(
name|args
argument_list|)
block|;
if|if
condition|(
name|spec
operator|!=
name|NULL
condition|)
block|{
return|return
name|spec
operator|->
name|GetAction
argument_list|()
operator|.
name|Perform
argument_list|(
name|args
argument_list|)
return|;
block|}
specifier|const
name|string
name|message
operator|=
name|call_description
operator|+
literal|"\n    The mock function has no default action "
literal|"set, and its return type has no default value set."
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|GTEST_HAS_EXCEPTIONS
end_if

begin_if
if|if
condition|(
operator|!
name|DefaultValue
operator|<
name|Result
operator|>
operator|::
name|Exists
argument_list|()
condition|)
block|{
name|throw
name|std
operator|::
name|runtime_error
argument_list|(
name|message
argument_list|)
expr_stmt|;
block|}
end_if

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|Assert
argument_list|(
name|DefaultValue
operator|<
name|Result
operator|>
operator|::
name|Exists
argument_list|()
argument_list|,
literal|""
argument_list|,
operator|-
literal|1
argument_list|,
name|message
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_return
return|return
name|DefaultValue
operator|<
name|Result
operator|>
operator|::
name|Get
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|// Performs the default action with the given arguments and returns
end_comment

begin_comment
comment|// the action's result.  The call description string will be used in
end_comment

begin_comment
comment|// the error message to describe the call in the case the default
end_comment

begin_comment
comment|// action fails.  The caller is responsible for deleting the result.
end_comment

begin_comment
comment|// L = *
end_comment

begin_decl_stmt
unit|virtual
name|UntypedActionResultHolderBase
modifier|*
name|UntypedPerformDefaultAction
argument_list|(
specifier|const
name|void
operator|*
name|untyped_args
argument_list|,
comment|// must point to an ArgumentTuple
specifier|const
name|string
operator|&
name|call_description
argument_list|)
decl|const
block|{
specifier|const
name|ArgumentTuple
modifier|&
name|args
init|=
operator|*
name|static_cast
operator|<
specifier|const
name|ArgumentTuple
operator|*
operator|>
operator|(
name|untyped_args
operator|)
decl_stmt|;
return|return
name|ResultHolder
operator|::
name|PerformDefaultAction
argument_list|(
name|this
argument_list|,
name|args
argument_list|,
name|call_description
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Performs the given action with the given arguments and returns
end_comment

begin_comment
comment|// the action's result.  The caller is responsible for deleting the
end_comment

begin_comment
comment|// result.
end_comment

begin_comment
comment|// L = *
end_comment

begin_decl_stmt
name|virtual
name|UntypedActionResultHolderBase
modifier|*
name|UntypedPerformAction
argument_list|(
specifier|const
name|void
operator|*
name|untyped_action
argument_list|,
specifier|const
name|void
operator|*
name|untyped_args
argument_list|)
decl|const
block|{
comment|// Make a copy of the action before performing it, in case the
comment|// action deletes the mock object (and thus deletes itself).
specifier|const
name|Action
operator|<
name|F
operator|>
name|action
operator|=
operator|*
name|static_cast
operator|<
specifier|const
name|Action
operator|<
name|F
operator|>
operator|*
operator|>
operator|(
name|untyped_action
operator|)
expr_stmt|;
specifier|const
name|ArgumentTuple
modifier|&
name|args
init|=
operator|*
name|static_cast
operator|<
specifier|const
name|ArgumentTuple
operator|*
operator|>
operator|(
name|untyped_args
operator|)
decl_stmt|;
return|return
name|ResultHolder
operator|::
name|PerformAction
argument_list|(
name|action
argument_list|,
name|args
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Implements UntypedFunctionMockerBase::ClearDefaultActionsLocked():
end_comment

begin_comment
comment|// clears the ON_CALL()s set on this mock function.
end_comment

begin_function
name|virtual
name|void
name|ClearDefaultActionsLocked
parameter_list|()
function|GTEST_EXCLUSIVE_LOCK_REQUIRED_
parameter_list|(
name|g_gmock_mutex
parameter_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
expr_stmt|;
comment|// Deleting our default actions may trigger other mock objects to be
comment|// deleted, for example if an action contains a reference counted smart
comment|// pointer to that mock object, and that is the last reference. So if we
comment|// delete our actions within the context of the global mutex we may deadlock
comment|// when this method is called again. Instead, make a copy of the set of
comment|// actions to delete, clear our set within the mutex, and then delete the
comment|// actions outside of the mutex.
name|UntypedOnCallSpecs
name|specs_to_delete
decl_stmt|;
name|untyped_on_call_specs_
operator|.
name|swap
argument_list|(
name|specs_to_delete
argument_list|)
expr_stmt|;
name|g_gmock_mutex
operator|.
name|Unlock
argument_list|()
expr_stmt|;
for|for
control|(
name|UntypedOnCallSpecs
operator|::
name|const_iterator
name|it
operator|=
name|specs_to_delete
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|specs_to_delete
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|delete
name|static_cast
operator|<
specifier|const
name|OnCallSpec
operator|<
name|F
operator|>
operator|*
operator|>
operator|(
operator|*
name|it
operator|)
expr_stmt|;
block|}
comment|// Lock the mutex again, since the caller expects it to be locked when we
comment|// return.
name|g_gmock_mutex
operator|.
name|Lock
argument_list|()
expr_stmt|;
block|}
end_function

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|template
operator|<
name|typename
name|Function
operator|>
name|friend
name|class
name|MockSpec
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|ActionResultHolder
operator|<
name|Result
operator|>
name|ResultHolder
expr_stmt|;
end_typedef

begin_comment
comment|// Returns the result of invoking this mock function with the given
end_comment

begin_comment
comment|// arguments.  This function can be safely called from multiple
end_comment

begin_comment
comment|// threads concurrently.
end_comment

begin_function
name|Result
name|InvokeWith
parameter_list|(
specifier|const
name|ArgumentTuple
modifier|&
name|args
parameter_list|)
function|GTEST_LOCK_EXCLUDED_
parameter_list|(
name|g_gmock_mutex
parameter_list|)
block|{
name|scoped_ptr
operator|<
name|ResultHolder
operator|>
name|holder
argument_list|(
name|DownCast_
operator|<
name|ResultHolder
operator|*
operator|>
operator|(
name|this
operator|->
name|UntypedInvokeWith
argument_list|(
operator|&
name|args
argument_list|)
operator|)
argument_list|)
expr_stmt|;
return|return
name|holder
operator|->
name|Unwrap
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// Adds and returns a default action spec for this mock function.
end_comment

begin_expr_stmt
name|OnCallSpec
operator|<
name|F
operator|>
operator|&
name|AddNewOnCallSpec
argument_list|(
argument|const char* file
argument_list|,
argument|int line
argument_list|,
argument|const ArgumentMatcherTuple& m
argument_list|)
name|GTEST_LOCK_EXCLUDED_
argument_list|(
argument|g_gmock_mutex
argument_list|)
block|{
name|Mock
operator|::
name|RegisterUseByOnCallOrExpectCall
argument_list|(
name|MockObject
argument_list|()
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
block|;
name|OnCallSpec
operator|<
name|F
operator|>
operator|*
specifier|const
name|on_call_spec
operator|=
name|new
name|OnCallSpec
operator|<
name|F
operator|>
operator|(
name|file
operator|,
name|line
operator|,
name|m
operator|)
block|;
name|untyped_on_call_specs_
operator|.
name|push_back
argument_list|(
name|on_call_spec
argument_list|)
block|;
return|return
operator|*
name|on_call_spec
return|;
block|}
end_expr_stmt

begin_comment
comment|// Adds and returns an expectation spec for this mock function.
end_comment

begin_expr_stmt
name|TypedExpectation
operator|<
name|F
operator|>
operator|&
name|AddNewExpectation
argument_list|(
argument|const char* file
argument_list|,
argument|int line
argument_list|,
argument|const string& source_text
argument_list|,
argument|const ArgumentMatcherTuple& m
argument_list|)
name|GTEST_LOCK_EXCLUDED_
argument_list|(
argument|g_gmock_mutex
argument_list|)
block|{
name|Mock
operator|::
name|RegisterUseByOnCallOrExpectCall
argument_list|(
name|MockObject
argument_list|()
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
block|;
name|TypedExpectation
operator|<
name|F
operator|>
operator|*
specifier|const
name|expectation
operator|=
name|new
name|TypedExpectation
operator|<
name|F
operator|>
operator|(
name|this
operator|,
name|file
operator|,
name|line
operator|,
name|source_text
operator|,
name|m
operator|)
block|;
specifier|const
name|linked_ptr
operator|<
name|ExpectationBase
operator|>
name|untyped_expectation
argument_list|(
name|expectation
argument_list|)
block|;
name|untyped_expectations_
operator|.
name|push_back
argument_list|(
name|untyped_expectation
argument_list|)
block|;
comment|// Adds this expectation into the implicit sequence if there is one.
name|Sequence
operator|*
specifier|const
name|implicit_sequence
operator|=
name|g_gmock_implicit_sequence
operator|.
name|get
argument_list|()
block|;
if|if
condition|(
name|implicit_sequence
operator|!=
name|NULL
condition|)
block|{
name|implicit_sequence
operator|->
name|AddExpectation
argument_list|(
name|Expectation
argument_list|(
name|untyped_expectation
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
operator|*
name|expectation
return|;
end_return

begin_comment
unit|}
comment|// The current spec (either default action spec or expectation spec)
end_comment

begin_comment
comment|// being described on this function mocker.
end_comment

begin_expr_stmt
unit|MockSpec
operator|<
name|F
operator|>
operator|&
name|current_spec
argument_list|()
block|{
return|return
name|current_spec_
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|template
operator|<
name|typename
name|Func
operator|>
name|friend
name|class
name|TypedExpectation
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Some utilities needed for implementing UntypedInvokeWith().
end_comment

begin_comment
comment|// Describes what default action will be performed for the given
end_comment

begin_comment
comment|// arguments.
end_comment

begin_comment
comment|// L = *
end_comment

begin_decl_stmt
name|void
name|DescribeDefaultActionTo
argument_list|(
specifier|const
name|ArgumentTuple
operator|&
name|args
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
specifier|const
name|OnCallSpec
operator|<
name|F
operator|>
operator|*
specifier|const
name|spec
operator|=
name|FindOnCallSpec
argument_list|(
name|args
argument_list|)
expr_stmt|;
if|if
condition|(
name|spec
operator|==
name|NULL
condition|)
block|{
operator|*
name|os
operator|<<
operator|(
name|internal
operator|::
name|type_equals
operator|<
name|Result
operator|,
name|void
operator|>
operator|::
name|value
condition|?
literal|"returning directly.\n"
else|:
literal|"returning default value.\n"
operator|)
expr_stmt|;
block|}
else|else
block|{
operator|*
name|os
operator|<<
literal|"taking default action specified at:\n"
operator|<<
name|FormatFileLocation
argument_list|(
name|spec
operator|->
name|file
argument_list|()
argument_list|,
name|spec
operator|->
name|line
argument_list|()
argument_list|)
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// Writes a message that the call is uninteresting (i.e. neither
end_comment

begin_comment
comment|// explicitly expected nor explicitly unexpected) to the given
end_comment

begin_comment
comment|// ostream.
end_comment

begin_decl_stmt
name|virtual
name|void
name|UntypedDescribeUninterestingCall
argument_list|(
specifier|const
name|void
operator|*
name|untyped_args
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
name|GTEST_LOCK_EXCLUDED_
argument_list|(
name|g_gmock_mutex
argument_list|)
block|{
specifier|const
name|ArgumentTuple
modifier|&
name|args
init|=
operator|*
name|static_cast
operator|<
specifier|const
name|ArgumentTuple
operator|*
operator|>
operator|(
name|untyped_args
operator|)
decl_stmt|;
operator|*
name|os
operator|<<
literal|"Uninteresting mock function call - "
expr_stmt|;
name|DescribeDefaultActionTo
argument_list|(
name|args
argument_list|,
name|os
argument_list|)
expr_stmt|;
operator|*
name|os
operator|<<
literal|"    Function call: "
operator|<<
name|Name
argument_list|()
expr_stmt|;
name|UniversalPrint
argument_list|(
name|args
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Returns the expectation that matches the given function arguments
end_comment

begin_comment
comment|// (or NULL is there's no match); when a match is found,
end_comment

begin_comment
comment|// untyped_action is set to point to the action that should be
end_comment

begin_comment
comment|// performed (or NULL if the action is "do default"), and
end_comment

begin_comment
comment|// is_excessive is modified to indicate whether the call exceeds the
end_comment

begin_comment
comment|// expected number.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Critical section: We must find the matching expectation and the
end_comment

begin_comment
comment|// corresponding action that needs to be taken in an ATOMIC
end_comment

begin_comment
comment|// transaction.  Otherwise another thread may call this mock
end_comment

begin_comment
comment|// method in the middle and mess up the state.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// However, performing the action has to be left out of the critical
end_comment

begin_comment
comment|// section.  The reason is that we have no control on what the
end_comment

begin_comment
comment|// action does (it can invoke an arbitrary user function or even a
end_comment

begin_comment
comment|// mock function) and excessive locking could cause a dead lock.
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|ExpectationBase
modifier|*
name|UntypedFindMatchingExpectation
argument_list|(
specifier|const
name|void
operator|*
name|untyped_args
argument_list|,
specifier|const
name|void
operator|*
operator|*
name|untyped_action
argument_list|,
name|bool
operator|*
name|is_excessive
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|what
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|why
argument_list|)
name|GTEST_LOCK_EXCLUDED_
argument_list|(
name|g_gmock_mutex
argument_list|)
block|{
specifier|const
name|ArgumentTuple
modifier|&
name|args
init|=
operator|*
name|static_cast
operator|<
specifier|const
name|ArgumentTuple
operator|*
operator|>
operator|(
name|untyped_args
operator|)
decl_stmt|;
name|MutexLock
name|l
argument_list|(
operator|&
name|g_gmock_mutex
argument_list|)
decl_stmt|;
name|TypedExpectation
operator|<
name|F
operator|>
operator|*
name|exp
operator|=
name|this
operator|->
name|FindMatchingExpectationLocked
argument_list|(
name|args
argument_list|)
expr_stmt|;
if|if
condition|(
name|exp
operator|==
name|NULL
condition|)
block|{
comment|// A match wasn't found.
name|this
operator|->
name|FormatUnexpectedCallMessageLocked
argument_list|(
name|args
argument_list|,
name|what
argument_list|,
name|why
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
comment|// This line must be done before calling GetActionForArguments(),
comment|// which will increment the call count for *exp and thus affect
comment|// its saturation status.
operator|*
name|is_excessive
operator|=
name|exp
operator|->
name|IsSaturated
argument_list|()
expr_stmt|;
specifier|const
name|Action
operator|<
name|F
operator|>
operator|*
name|action
operator|=
name|exp
operator|->
name|GetActionForArguments
argument_list|(
name|this
argument_list|,
name|args
argument_list|,
name|what
argument_list|,
name|why
argument_list|)
expr_stmt|;
if|if
condition|(
name|action
operator|!=
name|NULL
operator|&&
name|action
operator|->
name|IsDoDefault
argument_list|()
condition|)
name|action
operator|=
name|NULL
expr_stmt|;
comment|// Normalize "do default" to NULL.
operator|*
name|untyped_action
operator|=
name|action
expr_stmt|;
return|return
name|exp
return|;
block|}
end_decl_stmt

begin_comment
comment|// Prints the given function arguments to the ostream.
end_comment

begin_decl_stmt
name|virtual
name|void
name|UntypedPrintArgs
argument_list|(
specifier|const
name|void
operator|*
name|untyped_args
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
specifier|const
name|ArgumentTuple
modifier|&
name|args
init|=
operator|*
name|static_cast
operator|<
specifier|const
name|ArgumentTuple
operator|*
operator|>
operator|(
name|untyped_args
operator|)
decl_stmt|;
name|UniversalPrint
argument_list|(
name|args
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Returns the expectation that matches the arguments, or NULL if no
end_comment

begin_comment
comment|// expectation matches them.
end_comment

begin_expr_stmt
name|TypedExpectation
operator|<
name|F
operator|>
operator|*
name|FindMatchingExpectationLocked
argument_list|(
argument|const ArgumentTuple& args
argument_list|)
specifier|const
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
argument|g_gmock_mutex
argument_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
block|;
for|for
control|(
name|typename
name|UntypedExpectations
operator|::
name|const_reverse_iterator
name|it
operator|=
name|untyped_expectations_
operator|.
name|rbegin
argument_list|()
init|;
name|it
operator|!=
name|untyped_expectations_
operator|.
name|rend
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|TypedExpectation
operator|<
name|F
operator|>
operator|*
specifier|const
name|exp
operator|=
name|static_cast
operator|<
name|TypedExpectation
operator|<
name|F
operator|>
operator|*
operator|>
operator|(
name|it
operator|->
name|get
argument_list|()
operator|)
expr_stmt|;
if|if
condition|(
name|exp
operator|->
name|ShouldHandleArguments
argument_list|(
name|args
argument_list|)
condition|)
block|{
return|return
name|exp
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}     return
name|NULL
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// Returns a message that the arguments don't match any expectation.
end_comment

begin_macro
unit|void
name|FormatUnexpectedCallMessageLocked
argument_list|(
argument|const ArgumentTuple& args
argument_list|,
argument|::std::ostream* os
argument_list|,
argument|::std::ostream* why
argument_list|)
end_macro

begin_expr_stmt
specifier|const
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
argument|g_gmock_mutex
argument_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
block|;
operator|*
name|os
operator|<<
literal|"\nUnexpected mock function call - "
block|;
name|DescribeDefaultActionTo
argument_list|(
name|args
argument_list|,
name|os
argument_list|)
block|;
name|PrintTriedExpectationsLocked
argument_list|(
name|args
argument_list|,
name|why
argument_list|)
block|;   }
comment|// Prints a list of expectations that have been tried against the
comment|// current mock function call.
name|void
name|PrintTriedExpectationsLocked
argument_list|(
argument|const ArgumentTuple& args
argument_list|,
argument|::std::ostream* why
argument_list|)
specifier|const
name|GTEST_EXCLUSIVE_LOCK_REQUIRED_
argument_list|(
argument|g_gmock_mutex
argument_list|)
block|{
name|g_gmock_mutex
operator|.
name|AssertHeld
argument_list|()
block|;
specifier|const
name|int
name|count
operator|=
name|static_cast
operator|<
name|int
operator|>
operator|(
name|untyped_expectations_
operator|.
name|size
argument_list|()
operator|)
block|;
operator|*
name|why
operator|<<
literal|"Google Mock tried the following "
operator|<<
name|count
operator|<<
literal|" "
operator|<<
operator|(
name|count
operator|==
literal|1
condition|?
literal|"expectation, but it didn't match"
else|:
literal|"expectations, but none matched"
operator|)
operator|<<
literal|":\n"
block|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
name|i
operator|++
control|)
block|{
name|TypedExpectation
operator|<
name|F
operator|>
operator|*
specifier|const
name|expectation
operator|=
name|static_cast
operator|<
name|TypedExpectation
operator|<
name|F
operator|>
operator|*
operator|>
operator|(
name|untyped_expectations_
index|[
name|i
index|]
operator|.
name|get
argument_list|()
operator|)
expr_stmt|;
operator|*
name|why
operator|<<
literal|"\n"
expr_stmt|;
name|expectation
operator|->
name|DescribeLocationTo
argument_list|(
name|why
argument_list|)
expr_stmt|;
if|if
condition|(
name|count
operator|>
literal|1
condition|)
block|{
operator|*
name|why
operator|<<
literal|"tried expectation #"
operator|<<
name|i
operator|<<
literal|": "
expr_stmt|;
block|}
operator|*
name|why
operator|<<
name|expectation
operator|->
name|source_text
argument_list|()
operator|<<
literal|"...\n"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|expectation
operator|->
name|ExplainMatchResultTo
argument_list|(
name|args
argument_list|,
name|why
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|expectation
operator|->
name|DescribeCallCountTo
argument_list|(
name|why
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}   }
comment|// The current spec (either default action spec or expectation spec)
end_comment

begin_comment
comment|// being described on this function mocker.
end_comment

begin_expr_stmt
name|MockSpec
operator|<
name|F
operator|>
name|current_spec_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// There is no generally useful and implementable semantics of
end_comment

begin_comment
comment|// copying a mock object, so copying a mock is usually a user error.
end_comment

begin_comment
comment|// Thus we disallow copying function mockers.  If the user really
end_comment

begin_comment
comment|// wants to copy a mock object, he should implement his own copy
end_comment

begin_comment
comment|// operation, for example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   class MockFoo : public Foo {
end_comment

begin_comment
comment|//    public:
end_comment

begin_comment
comment|//     // Defines a copy constructor explicitly.
end_comment

begin_comment
comment|//     MockFoo(const MockFoo& src) {}
end_comment

begin_comment
comment|//     ...
end_comment

begin_comment
comment|//   };
end_comment

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|FunctionMockerBase
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// class FunctionMockerBase
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
end_pragma

begin_comment
comment|// Restores the warning state.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _MSV_VER
end_comment

begin_comment
comment|// Implements methods of FunctionMockerBase.
end_comment

begin_comment
comment|// Verifies that all expectations on this mock function have been
end_comment

begin_comment
comment|// satisfied.  Reports one or more Google Test non-fatal failures and
end_comment

begin_comment
comment|// returns false if not.
end_comment

begin_comment
comment|// Reports an uninteresting call (whose description is in msg) in the
end_comment

begin_comment
comment|// manner specified by 'reaction'.
end_comment

begin_function_decl
name|void
name|ReportUninterestingCall
parameter_list|(
name|CallReaction
name|reaction
parameter_list|,
specifier|const
name|string
modifier|&
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|}
comment|// namespace internal
end_comment

begin_comment
comment|// The style guide prohibits "using" statements in a namespace scope
end_comment

begin_comment
comment|// inside a header file.  However, the MockSpec class template is
end_comment

begin_comment
comment|// meant to be defined in the ::testing namespace.  The following line
end_comment

begin_comment
comment|// is just a trick for working around a bug in MSVC 8.0, which cannot
end_comment

begin_comment
comment|// handle it if we define MockSpec in ::testing.
end_comment

begin_expr_stmt
unit|using
name|internal
operator|::
name|MockSpec
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Const(x) is a convenient function for obtaining a const reference
end_comment

begin_comment
comment|// to x.  This is useful for setting expectations on an overloaded
end_comment

begin_comment
comment|// const mock method, e.g.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   class MockFoo : public FooInterface {
end_comment

begin_comment
comment|//    public:
end_comment

begin_comment
comment|//     MOCK_METHOD0(Bar, int());
end_comment

begin_comment
comment|//     MOCK_CONST_METHOD0(Bar, int&());
end_comment

begin_comment
comment|//   };
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   MockFoo foo;
end_comment

begin_comment
comment|//   // Expects a call to non-const MockFoo::Bar().
end_comment

begin_comment
comment|//   EXPECT_CALL(foo, Bar());
end_comment

begin_comment
comment|//   // Expects a call to const MockFoo::Bar().
end_comment

begin_comment
comment|//   EXPECT_CALL(Const(foo), Bar());
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
specifier|const
name|T
operator|&
name|Const
argument_list|(
argument|const T& x
argument_list|)
block|{
return|return
name|x
return|;
block|}
end_expr_stmt

begin_comment
comment|// Constructs an Expectation object that references and co-owns exp.
end_comment

begin_expr_stmt
specifier|inline
name|Expectation
operator|::
name|Expectation
argument_list|(
name|internal
operator|::
name|ExpectationBase
operator|&
name|exp
argument_list|)
comment|// NOLINT
operator|:
name|expectation_base_
argument_list|(
argument|exp.GetHandle().expectation_base()
argument_list|)
block|{}
end_expr_stmt

begin_comment
unit|}
comment|// namespace testing
end_comment

begin_comment
comment|// A separate macro is required to avoid compile errors when the name
end_comment

begin_comment
comment|// of the method used in call is a result of macro expansion.
end_comment

begin_comment
comment|// See CompilesWithMethodNameExpandedFromMacro tests in
end_comment

begin_comment
comment|// internal/gmock-spec-builders_test.cc for more details.
end_comment

begin_define
define|#
directive|define
name|GMOCK_ON_CALL_IMPL_
parameter_list|(
name|obj
parameter_list|,
name|call
parameter_list|)
define|\
value|((obj).gmock_##call).InternalDefaultActionSetAt(__FILE__, __LINE__, \                                                     #obj, #call)
end_define

begin_define
define|#
directive|define
name|ON_CALL
parameter_list|(
name|obj
parameter_list|,
name|call
parameter_list|)
value|GMOCK_ON_CALL_IMPL_(obj, call)
end_define

begin_define
define|#
directive|define
name|GMOCK_EXPECT_CALL_IMPL_
parameter_list|(
name|obj
parameter_list|,
name|call
parameter_list|)
define|\
value|((obj).gmock_##call).InternalExpectedAt(__FILE__, __LINE__, #obj, #call)
end_define

begin_define
define|#
directive|define
name|EXPECT_CALL
parameter_list|(
name|obj
parameter_list|,
name|call
parameter_list|)
value|GMOCK_EXPECT_CALL_IMPL_(obj, call)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GMOCK_INCLUDE_GMOCK_GMOCK_SPEC_BUILDERS_H_
end_comment

end_unit

