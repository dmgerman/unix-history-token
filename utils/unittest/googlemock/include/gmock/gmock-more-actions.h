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
comment|// This file implements some actions that depend on gmock-generated-actions.h.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GMOCK_INCLUDE_GMOCK_GMOCK_MORE_ACTIONS_H_
end_ifndef

begin_define
define|#
directive|define
name|GMOCK_INCLUDE_GMOCK_GMOCK_MORE_ACTIONS_H_
end_define

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|"gmock/gmock-generated-actions.h"
end_include

begin_decl_stmt
name|namespace
name|testing
block|{
name|namespace
name|internal
block|{
comment|// Implements the Invoke(f) action.  The template argument
comment|// FunctionImpl is the implementation type of f, which can be either a
comment|// function pointer or a functor.  Invoke(f) can be used as an
comment|// Action<F> as long as f's type is compatible with F (i.e. f can be
comment|// assigned to a tr1::function<F>).
name|template
operator|<
name|typename
name|FunctionImpl
operator|>
name|class
name|InvokeAction
block|{
name|public
operator|:
comment|// The c'tor makes a copy of function_impl (either a function
comment|// pointer or a functor).
name|explicit
name|InvokeAction
argument_list|(
argument|FunctionImpl function_impl
argument_list|)
operator|:
name|function_impl_
argument_list|(
argument|function_impl
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Result
block|,
name|typename
name|ArgumentTuple
operator|>
name|Result
name|Perform
argument_list|(
argument|const ArgumentTuple& args
argument_list|)
block|{
return|return
name|InvokeHelper
operator|<
name|Result
operator|,
name|ArgumentTuple
operator|>
operator|::
name|Invoke
argument_list|(
name|function_impl_
argument_list|,
name|args
argument_list|)
return|;
block|}
name|private
operator|:
name|FunctionImpl
name|function_impl_
block|;
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|InvokeAction
argument_list|)
block|; }
expr_stmt|;
comment|// Implements the Invoke(object_ptr,&Class::Method) action.
name|template
operator|<
name|class
name|Class
operator|,
name|typename
name|MethodPtr
operator|>
name|class
name|InvokeMethodAction
block|{
name|public
operator|:
name|InvokeMethodAction
argument_list|(
argument|Class* obj_ptr
argument_list|,
argument|MethodPtr method_ptr
argument_list|)
operator|:
name|method_ptr_
argument_list|(
name|method_ptr
argument_list|)
block|,
name|obj_ptr_
argument_list|(
argument|obj_ptr
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Result
block|,
name|typename
name|ArgumentTuple
operator|>
name|Result
name|Perform
argument_list|(
argument|const ArgumentTuple& args
argument_list|)
specifier|const
block|{
return|return
name|InvokeHelper
operator|<
name|Result
operator|,
name|ArgumentTuple
operator|>
operator|::
name|InvokeMethod
argument_list|(
name|obj_ptr_
argument_list|,
name|method_ptr_
argument_list|,
name|args
argument_list|)
return|;
block|}
name|private
operator|:
comment|// The order of these members matters.  Reversing the order can trigger
comment|// warning C4121 in MSVC (see
comment|// http://computer-programming-forum.com/7-vc.net/6fbc30265f860ad1.htm ).
specifier|const
name|MethodPtr
name|method_ptr_
block|;
name|Class
operator|*
specifier|const
name|obj_ptr_
block|;
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|InvokeMethodAction
argument_list|)
block|; }
expr_stmt|;
comment|// An internal replacement for std::copy which mimics its behavior. This is
comment|// necessary because Visual Studio deprecates ::std::copy, issuing warning 4996.
comment|// However Visual Studio 2010 and later do not honor #pragmas which disable that
comment|// warning.
name|template
operator|<
name|typename
name|InputIterator
operator|,
name|typename
name|OutputIterator
operator|>
specifier|inline
name|OutputIterator
name|CopyElements
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|OutputIterator output
argument_list|)
block|{
for|for
control|(
init|;
name|first
operator|!=
name|last
condition|;
operator|++
name|first
operator|,
operator|++
name|output
control|)
block|{
operator|*
name|output
operator|=
operator|*
name|first
expr_stmt|;
block|}
return|return
name|output
return|;
block|}
block|}
comment|// namespace internal
comment|// Various overloads for Invoke().
comment|// Creates an action that invokes 'function_impl' with the mock
comment|// function's arguments.
name|template
operator|<
name|typename
name|FunctionImpl
operator|>
name|PolymorphicAction
operator|<
name|internal
operator|::
name|InvokeAction
operator|<
name|FunctionImpl
operator|>
expr|>
name|Invoke
argument_list|(
argument|FunctionImpl function_impl
argument_list|)
block|{
return|return
name|MakePolymorphicAction
argument_list|(
name|internal
operator|::
name|InvokeAction
operator|<
name|FunctionImpl
operator|>
operator|(
name|function_impl
operator|)
argument_list|)
return|;
block|}
comment|// Creates an action that invokes the given method on the given object
comment|// with the mock function's arguments.
name|template
operator|<
name|class
name|Class
operator|,
name|typename
name|MethodPtr
operator|>
name|PolymorphicAction
operator|<
name|internal
operator|::
name|InvokeMethodAction
operator|<
name|Class
operator|,
name|MethodPtr
operator|>
expr|>
name|Invoke
argument_list|(
argument|Class* obj_ptr
argument_list|,
argument|MethodPtr method_ptr
argument_list|)
block|{
return|return
name|MakePolymorphicAction
argument_list|(
name|internal
operator|::
name|InvokeMethodAction
operator|<
name|Class
argument_list|,
name|MethodPtr
operator|>
operator|(
name|obj_ptr
operator|,
name|method_ptr
operator|)
argument_list|)
return|;
block|}
comment|// WithoutArgs(inner_action) can be used in a mock function with a
comment|// non-empty argument list to perform inner_action, which takes no
comment|// argument.  In other words, it adapts an action accepting no
comment|// argument to one that accepts (and ignores) arguments.
name|template
operator|<
name|typename
name|InnerAction
operator|>
specifier|inline
name|internal
operator|::
name|WithArgsAction
operator|<
name|InnerAction
operator|>
name|WithoutArgs
argument_list|(
argument|const InnerAction& action
argument_list|)
block|{
return|return
name|internal
operator|::
name|WithArgsAction
operator|<
name|InnerAction
operator|>
operator|(
name|action
operator|)
return|;
block|}
comment|// WithArg<k>(an_action) creates an action that passes the k-th
comment|// (0-based) argument of the mock function to an_action and performs
comment|// it.  It adapts an action accepting one argument to one that accepts
comment|// multiple arguments.  For convenience, we also provide
comment|// WithArgs<k>(an_action) (defined below) as a synonym.
name|template
operator|<
name|int
name|k
operator|,
name|typename
name|InnerAction
operator|>
specifier|inline
name|internal
operator|::
name|WithArgsAction
operator|<
name|InnerAction
operator|,
name|k
operator|>
name|WithArg
argument_list|(
argument|const InnerAction& action
argument_list|)
block|{
return|return
name|internal
operator|::
name|WithArgsAction
operator|<
name|InnerAction
operator|,
name|k
operator|>
operator|(
name|action
operator|)
return|;
block|}
comment|// The ACTION*() macros trigger warning C4100 (unreferenced formal
comment|// parameter) in MSVC with -W4.  Unfortunately they cannot be fixed in
comment|// the macro definition, as the warnings are generated when the macro
comment|// is expanded and macro expansion cannot contain #pragma.  Therefore
comment|// we suppress them here.
ifdef|#
directive|ifdef
name|_MSC_VER
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4100
name|)
endif|#
directive|endif
comment|// Action ReturnArg<k>() returns the k-th argument of the mock function.
name|ACTION_TEMPLATE
argument_list|(
argument|ReturnArg
argument_list|,
argument|HAS_1_TEMPLATE_PARAMS(int, k)
argument_list|,
argument|AND_0_VALUE_PARAMS()
argument_list|)
block|{
return|return
operator|::
name|testing
operator|::
name|get
operator|<
name|k
operator|>
operator|(
name|args
operator|)
return|;
block|}
comment|// Action SaveArg<k>(pointer) saves the k-th (0-based) argument of the
comment|// mock function to *pointer.
name|ACTION_TEMPLATE
argument_list|(
argument|SaveArg
argument_list|,
argument|HAS_1_TEMPLATE_PARAMS(int, k)
argument_list|,
argument|AND_1_VALUE_PARAMS(pointer)
argument_list|)
block|{
operator|*
name|pointer
operator|=
operator|::
name|testing
operator|::
name|get
operator|<
name|k
operator|>
operator|(
name|args
operator|)
expr_stmt|;
block|}
comment|// Action SaveArgPointee<k>(pointer) saves the value pointed to
comment|// by the k-th (0-based) argument of the mock function to *pointer.
name|ACTION_TEMPLATE
argument_list|(
argument|SaveArgPointee
argument_list|,
argument|HAS_1_TEMPLATE_PARAMS(int, k)
argument_list|,
argument|AND_1_VALUE_PARAMS(pointer)
argument_list|)
block|{
operator|*
name|pointer
operator|=
operator|*
operator|::
name|testing
operator|::
name|get
operator|<
name|k
operator|>
operator|(
name|args
operator|)
expr_stmt|;
block|}
comment|// Action SetArgReferee<k>(value) assigns 'value' to the variable
comment|// referenced by the k-th (0-based) argument of the mock function.
name|ACTION_TEMPLATE
argument_list|(
argument|SetArgReferee
argument_list|,
argument|HAS_1_TEMPLATE_PARAMS(int, k)
argument_list|,
argument|AND_1_VALUE_PARAMS(value)
argument_list|)
block|{
typedef|typedef
name|typename
operator|::
name|testing
operator|::
name|tuple_element
operator|<
name|k
operator|,
name|args_type
operator|>
operator|::
name|type
name|argk_type
expr_stmt|;
comment|// Ensures that argument #k is a reference.  If you get a compiler
comment|// error on the next line, you are using SetArgReferee<k>(value) in
comment|// a mock function whose k-th (0-based) argument is not a reference.
name|GTEST_COMPILE_ASSERT_
argument_list|(
name|internal
operator|::
name|is_reference
operator|<
name|argk_type
operator|>
operator|::
name|value
argument_list|,
name|SetArgReferee_must_be_used_with_a_reference_argument
argument_list|)
expr_stmt|;
operator|::
name|testing
operator|::
name|get
operator|<
name|k
operator|>
operator|(
name|args
operator|)
operator|=
name|value
expr_stmt|;
block|}
comment|// Action SetArrayArgument<k>(first, last) copies the elements in
comment|// source range [first, last) to the array pointed to by the k-th
comment|// (0-based) argument, which can be either a pointer or an
comment|// iterator. The action does not take ownership of the elements in the
comment|// source range.
name|ACTION_TEMPLATE
argument_list|(
argument|SetArrayArgument
argument_list|,
argument|HAS_1_TEMPLATE_PARAMS(int, k)
argument_list|,
argument|AND_2_VALUE_PARAMS(first, last)
argument_list|)
block|{
comment|// Visual Studio deprecates ::std::copy, so we use our own copy in that case.
ifdef|#
directive|ifdef
name|_MSC_VER
name|internal
operator|::
name|CopyElements
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
operator|::
name|testing
operator|::
name|get
operator|<
name|k
operator|>
operator|(
name|args
operator|)
argument_list|)
expr_stmt|;
else|#
directive|else
operator|::
name|std
operator|::
name|copy
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
operator|::
name|testing
operator|::
name|get
operator|<
name|k
operator|>
operator|(
name|args
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|// Action DeleteArg<k>() deletes the k-th (0-based) argument of the mock
comment|// function.
name|ACTION_TEMPLATE
argument_list|(
argument|DeleteArg
argument_list|,
argument|HAS_1_TEMPLATE_PARAMS(int, k)
argument_list|,
argument|AND_0_VALUE_PARAMS()
argument_list|)
block|{
name|delete
operator|::
name|testing
operator|::
name|get
operator|<
name|k
operator|>
operator|(
name|args
operator|)
expr_stmt|;
block|}
comment|// This action returns the value pointed to by 'pointer'.
name|ACTION_P
argument_list|(
argument|ReturnPointee
argument_list|,
argument|pointer
argument_list|)
block|{
return|return
operator|*
name|pointer
return|;
block|}
comment|// Action Throw(exception) can be used in a mock function of any type
comment|// to throw the given exception.  Any copyable value can be thrown.
if|#
directive|if
name|GTEST_HAS_EXCEPTIONS
comment|// Suppresses the 'unreachable code' warning that VC generates in opt modes.
ifdef|#
directive|ifdef
name|_MSC_VER
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
comment|// Saves the current warning state.
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4702
name|)
comment|// Temporarily disables warning 4702.
endif|#
directive|endif
name|ACTION_P
argument_list|(
argument|Throw
argument_list|,
argument|exception
argument_list|)
block|{
name|throw
name|exception
decl_stmt|;
block|}
ifdef|#
directive|ifdef
name|_MSC_VER
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
comment|// Restores the warning state.
endif|#
directive|endif
endif|#
directive|endif
comment|// GTEST_HAS_EXCEPTIONS
ifdef|#
directive|ifdef
name|_MSC_VER
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
endif|#
directive|endif
block|}
end_decl_stmt

begin_comment
comment|// namespace testing
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GMOCK_INCLUDE_GMOCK_GMOCK_MORE_ACTIONS_H_
end_comment

end_unit

