begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2005, Google Inc.
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
comment|// Utility functions and classes used by the Google C++ testing framework.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Author: wan@google.com (Zhanyong Wan)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file contains purely Google Test's internal implementation.  Please
end_comment

begin_comment
comment|// DO NOT #INCLUDE IT IN A USER PROGRAM.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_SRC_GTEST_INTERNAL_INL_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_SRC_GTEST_INTERNAL_INL_H_
end_define

begin_comment
comment|// GTEST_IMPLEMENTATION is defined iff the current translation unit is
end_comment

begin_comment
comment|// part of Google Test's implementation.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_IMPLEMENTATION
end_ifndef

begin_comment
comment|// A user is trying to include this from his code - just say no.
end_comment

begin_error
error|#
directive|error
literal|"gtest-internal-inl.h is part of Google Test's internal implementation."
end_error

begin_error
error|#
directive|error
literal|"It must not be included except by Google Test itself."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_IMPLEMENTATION
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<gtest/internal/gtest-port.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|GTEST_OS_WINDOWS
end_ifdef

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_comment
comment|// NOLINT
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_OS_WINDOWS
end_comment

begin_include
include|#
directive|include
file|<gtest/gtest.h>
end_include

begin_include
include|#
directive|include
file|<gtest/gtest-spi.h>
end_include

begin_decl_stmt
name|namespace
name|testing
block|{
comment|// Declares the flags.
comment|//
comment|// We don't want the users to modify these flags in the code, but want
comment|// Google Test's own unit tests to be able to access them.  Therefore we
comment|// declare them here as opposed to in gtest.h.
name|GTEST_DECLARE_bool_
argument_list|(
name|break_on_failure
argument_list|)
expr_stmt|;
name|GTEST_DECLARE_bool_
argument_list|(
name|catch_exceptions
argument_list|)
expr_stmt|;
name|GTEST_DECLARE_string_
argument_list|(
name|color
argument_list|)
expr_stmt|;
name|GTEST_DECLARE_string_
argument_list|(
name|filter
argument_list|)
expr_stmt|;
name|GTEST_DECLARE_bool_
argument_list|(
name|list_tests
argument_list|)
expr_stmt|;
name|GTEST_DECLARE_string_
argument_list|(
name|output
argument_list|)
expr_stmt|;
name|GTEST_DECLARE_bool_
argument_list|(
name|print_time
argument_list|)
expr_stmt|;
name|GTEST_DECLARE_int32_
argument_list|(
name|repeat
argument_list|)
expr_stmt|;
name|GTEST_DECLARE_int32_
argument_list|(
name|stack_trace_depth
argument_list|)
expr_stmt|;
name|GTEST_DECLARE_bool_
argument_list|(
name|show_internal_stack_frames
argument_list|)
expr_stmt|;
name|namespace
name|internal
block|{
comment|// The value of GetTestTypeId() as seen from within the Google Test
comment|// library.  This is solely for testing GetTestTypeId().
specifier|extern
specifier|const
name|TypeId
name|kTestTypeIdInGoogleTest
decl_stmt|;
comment|// Names of the flags (needed for parsing Google Test flags).
specifier|const
name|char
name|kBreakOnFailureFlag
index|[]
init|=
literal|"break_on_failure"
decl_stmt|;
specifier|const
name|char
name|kCatchExceptionsFlag
index|[]
init|=
literal|"catch_exceptions"
decl_stmt|;
specifier|const
name|char
name|kColorFlag
index|[]
init|=
literal|"color"
decl_stmt|;
specifier|const
name|char
name|kFilterFlag
index|[]
init|=
literal|"filter"
decl_stmt|;
specifier|const
name|char
name|kListTestsFlag
index|[]
init|=
literal|"list_tests"
decl_stmt|;
specifier|const
name|char
name|kOutputFlag
index|[]
init|=
literal|"output"
decl_stmt|;
specifier|const
name|char
name|kPrintTimeFlag
index|[]
init|=
literal|"print_time"
decl_stmt|;
specifier|const
name|char
name|kRepeatFlag
index|[]
init|=
literal|"repeat"
decl_stmt|;
comment|// This class saves the values of all Google Test flags in its c'tor, and
comment|// restores them in its d'tor.
name|class
name|GTestFlagSaver
block|{
name|public
label|:
comment|// The c'tor.
name|GTestFlagSaver
argument_list|()
block|{
name|break_on_failure_
operator|=
name|GTEST_FLAG
argument_list|(
name|break_on_failure
argument_list|)
expr_stmt|;
name|catch_exceptions_
operator|=
name|GTEST_FLAG
argument_list|(
name|catch_exceptions
argument_list|)
expr_stmt|;
name|color_
operator|=
name|GTEST_FLAG
argument_list|(
name|color
argument_list|)
expr_stmt|;
name|death_test_style_
operator|=
name|GTEST_FLAG
argument_list|(
name|death_test_style
argument_list|)
expr_stmt|;
name|filter_
operator|=
name|GTEST_FLAG
argument_list|(
name|filter
argument_list|)
expr_stmt|;
name|internal_run_death_test_
operator|=
name|GTEST_FLAG
argument_list|(
name|internal_run_death_test
argument_list|)
expr_stmt|;
name|list_tests_
operator|=
name|GTEST_FLAG
argument_list|(
name|list_tests
argument_list|)
expr_stmt|;
name|output_
operator|=
name|GTEST_FLAG
argument_list|(
name|output
argument_list|)
expr_stmt|;
name|print_time_
operator|=
name|GTEST_FLAG
argument_list|(
name|print_time
argument_list|)
expr_stmt|;
name|repeat_
operator|=
name|GTEST_FLAG
argument_list|(
name|repeat
argument_list|)
expr_stmt|;
block|}
comment|// The d'tor is not virtual.  DO NOT INHERIT FROM THIS CLASS.
operator|~
name|GTestFlagSaver
argument_list|()
block|{
name|GTEST_FLAG
argument_list|(
name|break_on_failure
argument_list|)
operator|=
name|break_on_failure_
block|;
name|GTEST_FLAG
argument_list|(
name|catch_exceptions
argument_list|)
operator|=
name|catch_exceptions_
block|;
name|GTEST_FLAG
argument_list|(
name|color
argument_list|)
operator|=
name|color_
block|;
name|GTEST_FLAG
argument_list|(
name|death_test_style
argument_list|)
operator|=
name|death_test_style_
block|;
name|GTEST_FLAG
argument_list|(
name|filter
argument_list|)
operator|=
name|filter_
block|;
name|GTEST_FLAG
argument_list|(
name|internal_run_death_test
argument_list|)
operator|=
name|internal_run_death_test_
block|;
name|GTEST_FLAG
argument_list|(
name|list_tests
argument_list|)
operator|=
name|list_tests_
block|;
name|GTEST_FLAG
argument_list|(
name|output
argument_list|)
operator|=
name|output_
block|;
name|GTEST_FLAG
argument_list|(
name|print_time
argument_list|)
operator|=
name|print_time_
block|;
name|GTEST_FLAG
argument_list|(
name|repeat
argument_list|)
operator|=
name|repeat_
block|;   }
name|private
operator|:
comment|// Fields for saving the original values of flags.
name|bool
name|break_on_failure_
expr_stmt|;
name|bool
name|catch_exceptions_
decl_stmt|;
name|String
name|color_
decl_stmt|;
name|String
name|death_test_style_
decl_stmt|;
name|String
name|filter_
decl_stmt|;
name|String
name|internal_run_death_test_
decl_stmt|;
name|bool
name|list_tests_
decl_stmt|;
name|String
name|output_
decl_stmt|;
name|bool
name|print_time_
decl_stmt|;
name|bool
name|pretty_
decl_stmt|;
name|internal
operator|::
name|Int32
name|repeat_
expr_stmt|;
block|}
name|GTEST_ATTRIBUTE_UNUSED_
expr_stmt|;
comment|// Converts a Unicode code point to a narrow string in UTF-8 encoding.
comment|// code_point parameter is of type UInt32 because wchar_t may not be
comment|// wide enough to contain a code point.
comment|// The output buffer str must containt at least 32 characters.
comment|// The function returns the address of the output buffer.
comment|// If the code_point is not a valid Unicode code point
comment|// (i.e. outside of Unicode range U+0 to U+10FFFF) it will be output
comment|// as '(Invalid Unicode 0xXXXXXXXX)'.
name|char
modifier|*
name|CodePointToUtf8
parameter_list|(
name|UInt32
name|code_point
parameter_list|,
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
comment|// Converts a wide string to a narrow string in UTF-8 encoding.
comment|// The wide string is assumed to have the following encoding:
comment|//   UTF-16 if sizeof(wchar_t) == 2 (on Windows, Cygwin, Symbian OS)
comment|//   UTF-32 if sizeof(wchar_t) == 4 (on Linux)
comment|// Parameter str points to a null-terminated wide string.
comment|// Parameter num_chars may additionally limit the number
comment|// of wchar_t characters processed. -1 is used when the entire string
comment|// should be processed.
comment|// If the string contains code points that are not valid Unicode code points
comment|// (i.e. outside of Unicode range U+0 to U+10FFFF) they will be output
comment|// as '(Invalid Unicode 0xXXXXXXXX)'. If the string is in UTF16 encoding
comment|// and contains invalid UTF-16 surrogate pairs, values in those pairs
comment|// will be encoded as individual Unicode characters from Basic Normal Plane.
name|String
name|WideStringToUtf8
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|str
parameter_list|,
name|int
name|num_chars
parameter_list|)
function_decl|;
comment|// Returns the number of active threads, or 0 when there is an error.
name|size_t
name|GetThreadCount
parameter_list|()
function_decl|;
comment|// List is a simple singly-linked list container.
comment|//
comment|// We cannot use std::list as Microsoft's implementation of STL has
comment|// problems when exception is disabled.  There is a hack to work
comment|// around this, but we've seen cases where the hack fails to work.
comment|//
comment|// TODO(wan): switch to std::list when we have a reliable fix for the
comment|// STL problem, e.g. when we upgrade to the next version of Visual
comment|// C++, or (more likely) switch to STLport.
comment|//
comment|// The element type must support copy constructor.
comment|// Forward declare List
name|template
operator|<
name|typename
name|E
operator|>
comment|// E is the element type.
name|class
name|List
expr_stmt|;
comment|// ListNode is a node in a singly-linked list.  It consists of an
comment|// element and a pointer to the next node.  The last node in the list
comment|// has a NULL value for its next pointer.
name|template
operator|<
name|typename
name|E
operator|>
comment|// E is the element type.
name|class
name|ListNode
block|{
name|friend
name|class
name|List
operator|<
name|E
operator|>
block|;
name|private
operator|:
name|E
name|element_
block|;
name|ListNode
operator|*
name|next_
block|;
comment|// The c'tor is private s.t. only in the ListNode class and in its
comment|// friend class List we can create a ListNode object.
comment|//
comment|// Creates a node with a given element value.  The next pointer is
comment|// set to NULL.
comment|//
comment|// ListNode does NOT have a default constructor.  Always use this
comment|// constructor (with parameter) to create a ListNode object.
name|explicit
name|ListNode
argument_list|(
specifier|const
name|E
operator|&
name|element
argument_list|)
operator|:
name|element_
argument_list|(
name|element
argument_list|)
block|,
name|next_
argument_list|(
argument|NULL
argument_list|)
block|{}
comment|// We disallow copying ListNode
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ListNode
argument_list|)
block|;
name|public
operator|:
comment|// Gets the element in this node.
name|E
operator|&
name|element
argument_list|()
block|{
return|return
name|element_
return|;
block|}
specifier|const
name|E
operator|&
name|element
argument_list|()
specifier|const
block|{
return|return
name|element_
return|;
block|}
comment|// Gets the next node in the list.
name|ListNode
operator|*
name|next
argument_list|()
block|{
return|return
name|next_
return|;
block|}
specifier|const
name|ListNode
operator|*
name|next
argument_list|()
specifier|const
block|{
return|return
name|next_
return|;
block|}
expr|}
block|;
comment|// List is a simple singly-linked list container.
name|template
operator|<
name|typename
name|E
operator|>
comment|// E is the element type.
name|class
name|List
block|{
name|public
operator|:
comment|// Creates an empty list.
name|List
argument_list|()
operator|:
name|head_
argument_list|(
name|NULL
argument_list|)
block|,
name|last_
argument_list|(
name|NULL
argument_list|)
block|,
name|size_
argument_list|(
literal|0
argument_list|)
block|{}
comment|// D'tor.
name|virtual
operator|~
name|List
argument_list|()
block|;
comment|// Clears the list.
name|void
name|Clear
argument_list|()
block|{
if|if
condition|(
name|size_
operator|>
literal|0
condition|)
block|{
comment|// 1. Deletes every node.
name|ListNode
operator|<
name|E
operator|>
operator|*
name|node
operator|=
name|head_
expr_stmt|;
name|ListNode
operator|<
name|E
operator|>
operator|*
name|next
operator|=
name|node
operator|->
name|next
argument_list|()
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|delete
name|node
decl_stmt|;
name|node
operator|=
name|next
expr_stmt|;
if|if
condition|(
name|node
operator|==
name|NULL
condition|)
break|break;
name|next
operator|=
name|node
operator|->
name|next
argument_list|()
expr_stmt|;
block|}
comment|// 2. Resets the member variables.
name|head_
operator|=
name|last_
operator|=
name|NULL
expr_stmt|;
name|size_
operator|=
literal|0
expr_stmt|;
block|}
block|}
comment|// Gets the number of elements.
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|size_
return|;
block|}
comment|// Returns true if the list is empty.
name|bool
name|IsEmpty
argument_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|==
literal|0
return|;
block|}
comment|// Gets the first element of the list, or NULL if the list is empty.
name|ListNode
operator|<
name|E
operator|>
operator|*
name|Head
argument_list|()
block|{
return|return
name|head_
return|;
block|}
specifier|const
name|ListNode
operator|<
name|E
operator|>
operator|*
name|Head
argument_list|()
specifier|const
block|{
return|return
name|head_
return|;
block|}
comment|// Gets the last element of the list, or NULL if the list is empty.
name|ListNode
operator|<
name|E
operator|>
operator|*
name|Last
argument_list|()
block|{
return|return
name|last_
return|;
block|}
specifier|const
name|ListNode
operator|<
name|E
operator|>
operator|*
name|Last
argument_list|()
specifier|const
block|{
return|return
name|last_
return|;
block|}
comment|// Adds an element to the end of the list.  A copy of the element is
comment|// created using the copy constructor, and then stored in the list.
comment|// Changes made to the element in the list doesn't affect the source
comment|// object, and vice versa.
name|void
name|PushBack
argument_list|(
argument|const E& element
argument_list|)
block|{
name|ListNode
operator|<
name|E
operator|>
operator|*
name|new_node
operator|=
name|new
name|ListNode
operator|<
name|E
operator|>
operator|(
name|element
operator|)
block|;
if|if
condition|(
name|size_
operator|==
literal|0
condition|)
block|{
name|head_
operator|=
name|last_
operator|=
name|new_node
expr_stmt|;
name|size_
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|last_
operator|->
name|next_
operator|=
name|new_node
expr_stmt|;
name|last_
operator|=
name|new_node
expr_stmt|;
name|size_
operator|++
expr_stmt|;
block|}
block|}
comment|// Adds an element to the beginning of this list.
name|void
name|PushFront
argument_list|(
argument|const E& element
argument_list|)
block|{
name|ListNode
operator|<
name|E
operator|>
operator|*
specifier|const
name|new_node
operator|=
name|new
name|ListNode
operator|<
name|E
operator|>
operator|(
name|element
operator|)
block|;
if|if
condition|(
name|size_
operator|==
literal|0
condition|)
block|{
name|head_
operator|=
name|last_
operator|=
name|new_node
expr_stmt|;
name|size_
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|new_node
operator|->
name|next_
operator|=
name|head_
expr_stmt|;
name|head_
operator|=
name|new_node
expr_stmt|;
name|size_
operator|++
expr_stmt|;
block|}
block|}
comment|// Removes an element from the beginning of this list.  If the
comment|// result argument is not NULL, the removed element is stored in the
comment|// memory it points to.  Otherwise the element is thrown away.
comment|// Returns true iff the list wasn't empty before the operation.
name|bool
name|PopFront
argument_list|(
argument|E* result
argument_list|)
block|{
if|if
condition|(
name|size_
operator|==
literal|0
condition|)
return|return
name|false
return|;
if|if
condition|(
name|result
operator|!=
name|NULL
condition|)
block|{
operator|*
name|result
operator|=
name|head_
operator|->
name|element_
expr_stmt|;
block|}
name|ListNode
operator|<
name|E
operator|>
operator|*
specifier|const
name|old_head
operator|=
name|head_
expr_stmt|;
name|size_
operator|--
block|;
if|if
condition|(
name|size_
operator|==
literal|0
condition|)
block|{
name|head_
operator|=
name|last_
operator|=
name|NULL
expr_stmt|;
block|}
else|else
block|{
name|head_
operator|=
name|head_
operator|->
name|next_
expr_stmt|;
block|}
name|delete
name|old_head
decl_stmt|;
return|return
name|true
return|;
block|}
comment|// Inserts an element after a given node in the list.  It's the
comment|// caller's responsibility to ensure that the given node is in the
comment|// list.  If the given node is NULL, inserts the element at the
comment|// front of the list.
name|ListNode
operator|<
name|E
operator|>
operator|*
name|InsertAfter
argument_list|(
argument|ListNode<E>* node
argument_list|,
argument|const E& element
argument_list|)
block|{
if|if
condition|(
name|node
operator|==
name|NULL
condition|)
block|{
name|PushFront
argument_list|(
name|element
argument_list|)
expr_stmt|;
return|return
name|Head
argument_list|()
return|;
block|}
name|ListNode
operator|<
name|E
operator|>
operator|*
specifier|const
name|new_node
operator|=
name|new
name|ListNode
operator|<
name|E
operator|>
operator|(
name|element
operator|)
expr_stmt|;
name|new_node
operator|->
name|next_
operator|=
name|node
operator|->
name|next_
expr_stmt|;
name|node
operator|->
name|next_
operator|=
name|new_node
expr_stmt|;
name|size_
operator|++
expr_stmt|;
if|if
condition|(
name|node
operator|==
name|last_
condition|)
block|{
name|last_
operator|=
name|new_node
expr_stmt|;
block|}
return|return
name|new_node
return|;
block|}
end_decl_stmt

begin_comment
comment|// Returns the number of elements that satisfy a given predicate.
end_comment

begin_comment
comment|// The parameter 'predicate' is a Boolean function or functor that
end_comment

begin_comment
comment|// accepts a 'const E&', where E is the element type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|P
operator|>
comment|// P is the type of the predicate function/functor
name|int
name|CountIf
argument_list|(
argument|P predicate
argument_list|)
specifier|const
block|{
name|int
name|count
operator|=
literal|0
block|;
for|for
control|(
specifier|const
name|ListNode
operator|<
name|E
operator|>
operator|*
name|node
operator|=
name|Head
argument_list|()
init|;
name|node
operator|!=
name|NULL
condition|;
name|node
operator|=
name|node
operator|->
name|next
argument_list|()
control|)
block|{
if|if
condition|(
name|predicate
argument_list|(
name|node
operator|->
name|element
argument_list|()
argument_list|)
condition|)
block|{
name|count
operator|++
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}      return
name|count
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// Applies a function/functor to each element in the list.  The
end_comment

begin_comment
comment|// parameter 'functor' is a function/functor that accepts a 'const
end_comment

begin_comment
comment|// E&', where E is the element type.  This method does not change
end_comment

begin_comment
comment|// the elements.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|F
operator|>
comment|// F is the type of the function/functor
name|void
name|ForEach
argument_list|(
argument|F functor
argument_list|)
specifier|const
block|{
for|for
control|(
specifier|const
name|ListNode
operator|<
name|E
operator|>
operator|*
name|node
operator|=
name|Head
argument_list|()
init|;
name|node
operator|!=
name|NULL
condition|;
name|node
operator|=
name|node
operator|->
name|next
argument_list|()
control|)
block|{
name|functor
argument_list|(
name|node
operator|->
name|element
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// Returns the first node whose element satisfies a given predicate,
end_comment

begin_comment
comment|// or NULL if none is found.  The parameter 'predicate' is a
end_comment

begin_comment
comment|// function/functor that accepts a 'const E&', where E is the
end_comment

begin_comment
comment|// element type.  This method does not change the elements.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|P
operator|>
comment|// P is the type of the predicate function/functor.
specifier|const
name|ListNode
operator|<
name|E
operator|>
operator|*
name|FindIf
argument_list|(
argument|P predicate
argument_list|)
specifier|const
block|{
for|for
control|(
specifier|const
name|ListNode
operator|<
name|E
operator|>
operator|*
name|node
operator|=
name|Head
argument_list|()
init|;
name|node
operator|!=
name|NULL
condition|;
name|node
operator|=
name|node
operator|->
name|next
argument_list|()
control|)
block|{
if|if
condition|(
name|predicate
argument_list|(
name|node
operator|->
name|element
argument_list|()
argument_list|)
condition|)
block|{
return|return
name|node
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}      return
name|NULL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|P
operator|>
name|ListNode
operator|<
name|E
operator|>
operator|*
name|FindIf
argument_list|(
argument|P predicate
argument_list|)
block|{
for|for
control|(
name|ListNode
operator|<
name|E
operator|>
operator|*
name|node
operator|=
name|Head
argument_list|()
init|;
name|node
operator|!=
name|NULL
condition|;
name|node
operator|=
name|node
operator|->
name|next
argument_list|()
control|)
block|{
if|if
condition|(
name|predicate
argument_list|(
name|node
operator|->
name|element
argument_list|()
argument_list|)
condition|)
block|{
return|return
name|node
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}      return
name|NULL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}   private:
name|ListNode
operator|<
name|E
operator|>
operator|*
name|head_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The first node of the list.
end_comment

begin_expr_stmt
name|ListNode
operator|<
name|E
operator|>
operator|*
name|last_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The last node of the list.
end_comment

begin_decl_stmt
name|int
name|size_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The number of elements in the list.
end_comment

begin_comment
comment|// We disallow copying List.
end_comment

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|List
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// The virtual destructor of List.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|E
operator|>
name|List
operator|<
name|E
operator|>
operator|::
operator|~
name|List
argument_list|()
block|{
name|Clear
argument_list|()
block|; }
comment|// A function for deleting an object.  Handy for being used as a
comment|// functor.
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|void
name|Delete
argument_list|(
argument|T * x
argument_list|)
block|{
name|delete
name|x
block|; }
comment|// A copyable object representing a user specified test property which can be
comment|// output as a key/value string pair.
comment|//
comment|// Don't inherit from TestProperty as its destructor is not virtual.
name|class
name|TestProperty
block|{
name|public
operator|:
comment|// C'tor.  TestProperty does NOT have a default constructor.
comment|// Always use this constructor (with parameters) to create a
comment|// TestProperty object.
name|TestProperty
argument_list|(
specifier|const
name|char
operator|*
name|key
argument_list|,
specifier|const
name|char
operator|*
name|value
argument_list|)
operator|:
name|key_
argument_list|(
name|key
argument_list|)
block|,
name|value_
argument_list|(
argument|value
argument_list|)
block|{   }
comment|// Gets the user supplied key.
specifier|const
name|char
operator|*
name|key
argument_list|()
specifier|const
block|{
return|return
name|key_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Gets the user supplied value.
specifier|const
name|char
operator|*
name|value
argument_list|()
specifier|const
block|{
return|return
name|value_
operator|.
name|c_str
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Sets a new value, overriding the one supplied in the constructor.
end_comment

begin_function
name|void
name|SetValue
parameter_list|(
specifier|const
name|char
modifier|*
name|new_value
parameter_list|)
block|{
name|value_
operator|=
name|new_value
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_comment
comment|// The key supplied by the user.
end_comment

begin_decl_stmt
name|String
name|key_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The value supplied by the user.
end_comment

begin_decl_stmt
name|String
name|value_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// A predicate that checks the key of a TestProperty against a known key.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TestPropertyKeyIs is copyable.
end_comment

begin_decl_stmt
name|class
name|TestPropertyKeyIs
block|{
name|public
label|:
comment|// Constructor.
comment|//
comment|// TestPropertyKeyIs has NO default constructor.
name|explicit
name|TestPropertyKeyIs
argument_list|(
specifier|const
name|char
operator|*
name|key
argument_list|)
operator|:
name|key_
argument_list|(
argument|key
argument_list|)
block|{}
comment|// Returns true iff the test name of test property matches on key_.
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|TestProperty
operator|&
name|test_property
operator|)
specifier|const
block|{
return|return
name|String
argument_list|(
name|test_property
operator|.
name|key
argument_list|()
argument_list|)
operator|.
name|Compare
argument_list|(
name|key_
argument_list|)
operator|==
literal|0
return|;
block|}
name|private
label|:
name|String
name|key_
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// The result of a single Test.  This includes a list of
end_comment

begin_comment
comment|// TestPartResults, a list of TestProperties, a count of how many
end_comment

begin_comment
comment|// death tests there are in the Test, and how much time it took to run
end_comment

begin_comment
comment|// the Test.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TestResult is not copyable.
end_comment

begin_decl_stmt
name|class
name|TestResult
block|{
name|public
label|:
comment|// Creates an empty TestResult.
name|TestResult
argument_list|()
expr_stmt|;
comment|// D'tor.  Do not inherit from TestResult.
operator|~
name|TestResult
argument_list|()
expr_stmt|;
comment|// Gets the list of TestPartResults.
specifier|const
name|internal
operator|::
name|List
operator|<
name|TestPartResult
operator|>
operator|&
name|test_part_results
argument_list|()
specifier|const
block|{
return|return
name|test_part_results_
return|;
block|}
comment|// Gets the list of TestProperties.
specifier|const
name|internal
operator|::
name|List
operator|<
name|internal
operator|::
name|TestProperty
operator|>
operator|&
name|test_properties
argument_list|()
specifier|const
block|{
return|return
name|test_properties_
return|;
block|}
comment|// Gets the number of successful test parts.
name|int
name|successful_part_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of failed test parts.
name|int
name|failed_part_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of all test parts.  This is the sum of the number
comment|// of successful test parts and the number of failed test parts.
name|int
name|total_part_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns true iff the test passed (i.e. no test part failed).
name|bool
name|Passed
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Failed
argument_list|()
return|;
block|}
comment|// Returns true iff the test failed.
name|bool
name|Failed
argument_list|()
specifier|const
block|{
return|return
name|failed_part_count
argument_list|()
operator|>
literal|0
return|;
block|}
comment|// Returns true iff the test fatally failed.
name|bool
name|HasFatalFailure
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns the elapsed time, in milliseconds.
name|TimeInMillis
name|elapsed_time
argument_list|()
specifier|const
block|{
return|return
name|elapsed_time_
return|;
block|}
comment|// Sets the elapsed time.
name|void
name|set_elapsed_time
parameter_list|(
name|TimeInMillis
name|elapsed
parameter_list|)
block|{
name|elapsed_time_
operator|=
name|elapsed
expr_stmt|;
block|}
comment|// Adds a test part result to the list.
name|void
name|AddTestPartResult
parameter_list|(
specifier|const
name|TestPartResult
modifier|&
name|test_part_result
parameter_list|)
function_decl|;
comment|// Adds a test property to the list. The property is validated and may add
comment|// a non-fatal failure if invalid (e.g., if it conflicts with reserved
comment|// key names). If a property is already recorded for the same key, the
comment|// value will be updated, rather than storing multiple values for the same
comment|// key.
name|void
name|RecordProperty
argument_list|(
specifier|const
name|internal
operator|::
name|TestProperty
operator|&
name|test_property
argument_list|)
decl_stmt|;
comment|// Adds a failure if the key is a reserved attribute of Google Test
comment|// testcase tags.  Returns true if the property is valid.
comment|// TODO(russr): Validate attribute names are legal and human readable.
specifier|static
name|bool
name|ValidateTestProperty
argument_list|(
specifier|const
name|internal
operator|::
name|TestProperty
operator|&
name|test_property
argument_list|)
decl_stmt|;
comment|// Returns the death test count.
name|int
name|death_test_count
argument_list|()
specifier|const
block|{
return|return
name|death_test_count_
return|;
block|}
comment|// Increments the death test count, returning the new count.
name|int
name|increment_death_test_count
parameter_list|()
block|{
return|return
operator|++
name|death_test_count_
return|;
block|}
comment|// Clears the object.
name|void
name|Clear
parameter_list|()
function_decl|;
name|private
label|:
comment|// Protects mutable state of the property list and of owned properties, whose
comment|// values may be updated.
name|internal
operator|::
name|Mutex
name|test_properites_mutex_
expr_stmt|;
comment|// The list of TestPartResults
name|internal
operator|::
name|List
operator|<
name|TestPartResult
operator|>
name|test_part_results_
expr_stmt|;
comment|// The list of TestProperties
name|internal
operator|::
name|List
operator|<
name|internal
operator|::
name|TestProperty
operator|>
name|test_properties_
expr_stmt|;
comment|// Running count of death tests.
name|int
name|death_test_count_
decl_stmt|;
comment|// The elapsed time, in milliseconds.
name|TimeInMillis
name|elapsed_time_
decl_stmt|;
comment|// We disallow copying TestResult.
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|TestResult
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// class TestResult
end_comment

begin_decl_stmt
name|class
name|TestInfoImpl
block|{
name|public
label|:
name|TestInfoImpl
argument_list|(
argument|TestInfo* parent
argument_list|,
argument|const char* test_case_name
argument_list|,
argument|const char* name
argument_list|,
argument|const char* test_case_comment
argument_list|,
argument|const char* comment
argument_list|,
argument|TypeId fixture_class_id
argument_list|,
argument|internal::TestFactoryBase* factory
argument_list|)
empty_stmt|;
operator|~
name|TestInfoImpl
argument_list|()
expr_stmt|;
comment|// Returns true if this test should run.
name|bool
name|should_run
argument_list|()
specifier|const
block|{
return|return
name|should_run_
return|;
block|}
comment|// Sets the should_run member.
name|void
name|set_should_run
parameter_list|(
name|bool
name|should
parameter_list|)
block|{
name|should_run_
operator|=
name|should
expr_stmt|;
block|}
comment|// Returns true if this test is disabled. Disabled tests are not run.
name|bool
name|is_disabled
argument_list|()
specifier|const
block|{
return|return
name|is_disabled_
return|;
block|}
comment|// Sets the is_disabled member.
name|void
name|set_is_disabled
parameter_list|(
name|bool
name|is
parameter_list|)
block|{
name|is_disabled_
operator|=
name|is
expr_stmt|;
block|}
comment|// Returns the test case name.
specifier|const
name|char
operator|*
name|test_case_name
argument_list|()
specifier|const
block|{
return|return
name|test_case_name_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Returns the test name.
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|{
return|return
name|name_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Returns the test case comment.
specifier|const
name|char
operator|*
name|test_case_comment
argument_list|()
specifier|const
block|{
return|return
name|test_case_comment_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Returns the test comment.
specifier|const
name|char
operator|*
name|comment
argument_list|()
specifier|const
block|{
return|return
name|comment_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Returns the ID of the test fixture class.
name|TypeId
name|fixture_class_id
argument_list|()
specifier|const
block|{
return|return
name|fixture_class_id_
return|;
block|}
comment|// Returns the test result.
name|internal
operator|::
name|TestResult
operator|*
name|result
argument_list|()
block|{
return|return
operator|&
name|result_
return|;
block|}
specifier|const
name|internal
operator|::
name|TestResult
operator|*
name|result
argument_list|()
specifier|const
block|{
return|return
operator|&
name|result_
return|;
block|}
comment|// Creates the test object, runs it, records its result, and then
comment|// deletes it.
name|void
name|Run
parameter_list|()
function_decl|;
comment|// Calls the given TestInfo object's Run() method.
specifier|static
name|void
name|RunTest
parameter_list|(
name|TestInfo
modifier|*
name|test_info
parameter_list|)
block|{
name|test_info
operator|->
name|impl
argument_list|()
operator|->
name|Run
argument_list|()
expr_stmt|;
block|}
comment|// Clears the test result.
name|void
name|ClearResult
parameter_list|()
block|{
name|result_
operator|.
name|Clear
argument_list|()
expr_stmt|;
block|}
comment|// Clears the test result in the given TestInfo object.
specifier|static
name|void
name|ClearTestResult
parameter_list|(
name|TestInfo
modifier|*
name|test_info
parameter_list|)
block|{
name|test_info
operator|->
name|impl
argument_list|()
operator|->
name|ClearResult
argument_list|()
expr_stmt|;
block|}
name|private
label|:
comment|// These fields are immutable properties of the test.
name|TestInfo
modifier|*
specifier|const
name|parent_
decl_stmt|;
comment|// The owner of this object
specifier|const
name|String
name|test_case_name_
decl_stmt|;
comment|// Test case name
specifier|const
name|String
name|name_
decl_stmt|;
comment|// Test name
specifier|const
name|String
name|test_case_comment_
decl_stmt|;
comment|// Test case comment
specifier|const
name|String
name|comment_
decl_stmt|;
comment|// Test comment
specifier|const
name|TypeId
name|fixture_class_id_
decl_stmt|;
comment|// ID of the test fixture class
name|bool
name|should_run_
decl_stmt|;
comment|// True iff this test should run
name|bool
name|is_disabled_
decl_stmt|;
comment|// True iff this test is disabled
name|internal
operator|::
name|TestFactoryBase
operator|*
specifier|const
name|factory_
expr_stmt|;
comment|// The factory that creates
comment|// the test object
comment|// This field is mutable and needs to be reset before running the
comment|// test for the second time.
name|internal
operator|::
name|TestResult
name|result_
expr_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|TestInfoImpl
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace internal
end_comment

begin_comment
comment|// A test case, which consists of a list of TestInfos.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TestCase is not copyable.
end_comment

begin_macro
unit|class
name|TestCase
end_macro

begin_block
block|{
name|public
label|:
comment|// Creates a TestCase with the given name.
comment|//
comment|// TestCase does NOT have a default constructor.  Always use this
comment|// constructor to create a TestCase object.
comment|//
comment|// Arguments:
comment|//
comment|//   name:         name of the test case
comment|//   set_up_tc:    pointer to the function that sets up the test case
comment|//   tear_down_tc: pointer to the function that tears down the test case
name|TestCase
argument_list|(
argument|const char* name
argument_list|,
argument|const char* comment
argument_list|,
argument|Test::SetUpTestCaseFunc set_up_tc
argument_list|,
argument|Test::TearDownTestCaseFunc tear_down_tc
argument_list|)
empty_stmt|;
comment|// Destructor of TestCase.
name|virtual
operator|~
name|TestCase
argument_list|()
expr_stmt|;
comment|// Gets the name of the TestCase.
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|{
return|return
name|name_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Returns the test case comment.
specifier|const
name|char
operator|*
name|comment
argument_list|()
specifier|const
block|{
return|return
name|comment_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Returns true if any test in this test case should run.
name|bool
name|should_run
argument_list|()
specifier|const
block|{
return|return
name|should_run_
return|;
block|}
comment|// Sets the should_run member.
name|void
name|set_should_run
parameter_list|(
name|bool
name|should
parameter_list|)
block|{
name|should_run_
operator|=
name|should
expr_stmt|;
block|}
comment|// Gets the (mutable) list of TestInfos in this TestCase.
name|internal
operator|::
name|List
operator|<
name|TestInfo
operator|*
operator|>
operator|&
name|test_info_list
argument_list|()
block|{
return|return
operator|*
name|test_info_list_
return|;
block|}
comment|// Gets the (immutable) list of TestInfos in this TestCase.
specifier|const
name|internal
operator|::
name|List
operator|<
name|TestInfo
operator|*
operator|>
operator|&
name|test_info_list
argument_list|()
specifier|const
block|{
return|return
operator|*
name|test_info_list_
return|;
block|}
comment|// Gets the number of successful tests in this test case.
name|int
name|successful_test_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of failed tests in this test case.
name|int
name|failed_test_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of disabled tests in this test case.
name|int
name|disabled_test_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Get the number of tests in this test case that should run.
name|int
name|test_to_run_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of all tests in this test case.
name|int
name|total_test_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns true iff the test case passed.
name|bool
name|Passed
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Failed
argument_list|()
return|;
block|}
comment|// Returns true iff the test case failed.
name|bool
name|Failed
argument_list|()
specifier|const
block|{
return|return
name|failed_test_count
argument_list|()
operator|>
literal|0
return|;
block|}
comment|// Returns the elapsed time, in milliseconds.
name|internal
operator|::
name|TimeInMillis
name|elapsed_time
argument_list|()
specifier|const
block|{
return|return
name|elapsed_time_
return|;
block|}
comment|// Adds a TestInfo to this test case.  Will delete the TestInfo upon
comment|// destruction of the TestCase object.
name|void
name|AddTestInfo
parameter_list|(
name|TestInfo
modifier|*
name|test_info
parameter_list|)
function_decl|;
comment|// Finds and returns a TestInfo with the given name.  If one doesn't
comment|// exist, returns NULL.
name|TestInfo
modifier|*
name|GetTestInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|test_name
parameter_list|)
function_decl|;
comment|// Clears the results of all tests in this test case.
name|void
name|ClearResult
parameter_list|()
function_decl|;
comment|// Clears the results of all tests in the given test case.
specifier|static
name|void
name|ClearTestCaseResult
parameter_list|(
name|TestCase
modifier|*
name|test_case
parameter_list|)
block|{
name|test_case
operator|->
name|ClearResult
argument_list|()
expr_stmt|;
block|}
comment|// Runs every test in this TestCase.
name|void
name|Run
parameter_list|()
function_decl|;
comment|// Runs every test in the given TestCase.
specifier|static
name|void
name|RunTestCase
parameter_list|(
name|TestCase
modifier|*
name|test_case
parameter_list|)
block|{
name|test_case
operator|->
name|Run
argument_list|()
expr_stmt|;
block|}
comment|// Returns true iff test passed.
specifier|static
name|bool
name|TestPassed
parameter_list|(
specifier|const
name|TestInfo
modifier|*
name|test_info
parameter_list|)
block|{
specifier|const
name|internal
operator|::
name|TestInfoImpl
operator|*
specifier|const
name|impl
operator|=
name|test_info
operator|->
name|impl
argument_list|()
expr_stmt|;
return|return
name|impl
operator|->
name|should_run
argument_list|()
operator|&&
name|impl
operator|->
name|result
argument_list|()
operator|->
name|Passed
argument_list|()
return|;
block|}
comment|// Returns true iff test failed.
specifier|static
name|bool
name|TestFailed
parameter_list|(
specifier|const
name|TestInfo
modifier|*
name|test_info
parameter_list|)
block|{
specifier|const
name|internal
operator|::
name|TestInfoImpl
operator|*
specifier|const
name|impl
operator|=
name|test_info
operator|->
name|impl
argument_list|()
expr_stmt|;
return|return
name|impl
operator|->
name|should_run
argument_list|()
operator|&&
name|impl
operator|->
name|result
argument_list|()
operator|->
name|Failed
argument_list|()
return|;
block|}
comment|// Returns true iff test is disabled.
specifier|static
name|bool
name|TestDisabled
parameter_list|(
specifier|const
name|TestInfo
modifier|*
name|test_info
parameter_list|)
block|{
return|return
name|test_info
operator|->
name|impl
argument_list|()
operator|->
name|is_disabled
argument_list|()
return|;
block|}
comment|// Returns true if the given test should run.
specifier|static
name|bool
name|ShouldRunTest
parameter_list|(
specifier|const
name|TestInfo
modifier|*
name|test_info
parameter_list|)
block|{
return|return
name|test_info
operator|->
name|impl
argument_list|()
operator|->
name|should_run
argument_list|()
return|;
block|}
name|private
label|:
comment|// Name of the test case.
name|internal
operator|::
name|String
name|name_
expr_stmt|;
comment|// Comment on the test case.
name|internal
operator|::
name|String
name|comment_
expr_stmt|;
comment|// List of TestInfos.
name|internal
operator|::
name|List
operator|<
name|TestInfo
operator|*
operator|>
operator|*
name|test_info_list_
expr_stmt|;
comment|// Pointer to the function that sets up the test case.
name|Test
operator|::
name|SetUpTestCaseFunc
name|set_up_tc_
expr_stmt|;
comment|// Pointer to the function that tears down the test case.
name|Test
operator|::
name|TearDownTestCaseFunc
name|tear_down_tc_
expr_stmt|;
comment|// True iff any test in this test case should run.
name|bool
name|should_run_
decl_stmt|;
comment|// Elapsed time, in milliseconds.
name|internal
operator|::
name|TimeInMillis
name|elapsed_time_
expr_stmt|;
comment|// We disallow copying TestCases.
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|TestCase
argument_list|)
expr_stmt|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|namespace
name|internal
block|{
comment|// Class UnitTestOptions.
comment|//
comment|// This class contains functions for processing options the user
comment|// specifies when running the tests.  It has only static members.
comment|//
comment|// In most cases, the user can specify an option using either an
comment|// environment variable or a command line flag.  E.g. you can set the
comment|// test filter using either GTEST_FILTER or --gtest_filter.  If both
comment|// the variable and the flag are present, the latter overrides the
comment|// former.
name|class
name|UnitTestOptions
block|{
name|public
label|:
comment|// Functions for processing the gtest_output flag.
comment|// Returns the output format, or "" for normal printed output.
specifier|static
name|String
name|GetOutputFormat
parameter_list|()
function_decl|;
comment|// Returns the name of the requested output file, or the default if none
comment|// was explicitly specified.
specifier|static
name|String
name|GetOutputFile
parameter_list|()
function_decl|;
comment|// Functions for processing the gtest_filter flag.
comment|// Returns true iff the wildcard pattern matches the string.  The
comment|// first ':' or '\0' character in pattern marks the end of it.
comment|//
comment|// This recursive algorithm isn't very efficient, but is clear and
comment|// works well enough for matching test names, which are short.
specifier|static
name|bool
name|PatternMatchesString
parameter_list|(
specifier|const
name|char
modifier|*
name|pattern
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
comment|// Returns true iff the user-specified filter matches the test case
comment|// name and the test name.
specifier|static
name|bool
name|FilterMatchesTest
parameter_list|(
specifier|const
name|String
modifier|&
name|test_case_name
parameter_list|,
specifier|const
name|String
modifier|&
name|test_name
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|GTEST_OS_WINDOWS
comment|// Function for supporting the gtest_catch_exception flag.
comment|// Returns EXCEPTION_EXECUTE_HANDLER if Google Test should handle the
comment|// given SEH exception, or EXCEPTION_CONTINUE_SEARCH otherwise.
comment|// This function is useful as an __except condition.
specifier|static
name|int
name|GTestShouldProcessSEH
parameter_list|(
name|DWORD
name|exception_code
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// GTEST_OS_WINDOWS
comment|// Returns true if "name" matches the ':' separated list of glob-style
comment|// filters in "filter".
specifier|static
name|bool
name|MatchesFilter
parameter_list|(
specifier|const
name|String
modifier|&
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|filter
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|// Returns the current application's name, removing directory path if that
comment|// is present.  Used by UnitTestOptions::GetOutputFile.
name|FilePath
name|GetCurrentExecutableName
parameter_list|()
function_decl|;
comment|// The role interface for getting the OS stack trace as a string.
name|class
name|OsStackTraceGetterInterface
block|{
name|public
label|:
name|OsStackTraceGetterInterface
argument_list|()
block|{}
name|virtual
operator|~
name|OsStackTraceGetterInterface
argument_list|()
block|{}
comment|// Returns the current OS stack trace as a String.  Parameters:
comment|//
comment|//   max_depth  - the maximum number of stack frames to be included
comment|//                in the trace.
comment|//   skip_count - the number of top frames to be skipped; doesn't count
comment|//                against max_depth.
name|virtual
name|String
name|CurrentStackTrace
argument_list|(
argument|int max_depth
argument_list|,
argument|int skip_count
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|// UponLeavingGTest() should be called immediately before Google Test calls
comment|// user code. It saves some information about the current stack that
comment|// CurrentStackTrace() will use to find and hide Google Test stack frames.
name|virtual
name|void
name|UponLeavingGTest
parameter_list|()
init|=
literal|0
function_decl|;
name|private
label|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|OsStackTraceGetterInterface
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|// A working implementation of the OsStackTraceGetterInterface interface.
name|class
name|OsStackTraceGetter
range|:
name|public
name|OsStackTraceGetterInterface
block|{
name|public
operator|:
name|OsStackTraceGetter
argument_list|()
block|{}
name|virtual
name|String
name|CurrentStackTrace
argument_list|(
argument|int max_depth
argument_list|,
argument|int skip_count
argument_list|)
block|;
name|virtual
name|void
name|UponLeavingGTest
argument_list|()
block|;
comment|// This string is inserted in place of stack frames that are part of
comment|// Google Test's implementation.
specifier|static
specifier|const
name|char
operator|*
specifier|const
name|kElidedFramesMarker
block|;
name|private
operator|:
name|Mutex
name|mutex_
block|;
comment|// protects all internal state
comment|// We save the stack frame below the frame that calls user code.
comment|// We do this because the address of the frame immediately below
comment|// the user code changes between the call to UponLeavingGTest()
comment|// and any calls to CurrentStackTrace() from within the user code.
name|void
operator|*
name|caller_frame_
block|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|OsStackTraceGetter
argument_list|)
block|; }
decl_stmt|;
comment|// Information about a Google Test trace point.
struct|struct
name|TraceInfo
block|{
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|line
decl_stmt|;
name|String
name|message
decl_stmt|;
block|}
struct|;
comment|// This is the default global test part result reporter used in UnitTestImpl.
comment|// This class should only be used by UnitTestImpl.
name|class
name|DefaultGlobalTestPartResultReporter
range|:
name|public
name|TestPartResultReporterInterface
block|{
name|public
operator|:
name|explicit
name|DefaultGlobalTestPartResultReporter
argument_list|(
name|UnitTestImpl
operator|*
name|unit_test
argument_list|)
block|;
comment|// Implements the TestPartResultReporterInterface. Reports the test part
comment|// result in the current test.
name|virtual
name|void
name|ReportTestPartResult
argument_list|(
specifier|const
name|TestPartResult
operator|&
name|result
argument_list|)
block|;
name|private
operator|:
name|UnitTestImpl
operator|*
specifier|const
name|unit_test_
block|; }
decl_stmt|;
comment|// This is the default per thread test part result reporter used in
comment|// UnitTestImpl. This class should only be used by UnitTestImpl.
name|class
name|DefaultPerThreadTestPartResultReporter
range|:
name|public
name|TestPartResultReporterInterface
block|{
name|public
operator|:
name|explicit
name|DefaultPerThreadTestPartResultReporter
argument_list|(
name|UnitTestImpl
operator|*
name|unit_test
argument_list|)
block|;
comment|// Implements the TestPartResultReporterInterface. The implementation just
comment|// delegates to the current global test part result reporter of *unit_test_.
name|virtual
name|void
name|ReportTestPartResult
argument_list|(
specifier|const
name|TestPartResult
operator|&
name|result
argument_list|)
block|;
name|private
operator|:
name|UnitTestImpl
operator|*
specifier|const
name|unit_test_
block|; }
decl_stmt|;
comment|// The private implementation of the UnitTest class.  We don't protect
comment|// the methods under a mutex, as this class is not accessible by a
comment|// user and the UnitTest class that delegates work to this class does
comment|// proper locking.
name|class
name|UnitTestImpl
block|{
name|public
label|:
name|explicit
name|UnitTestImpl
parameter_list|(
name|UnitTest
modifier|*
name|parent
parameter_list|)
function_decl|;
name|virtual
operator|~
name|UnitTestImpl
argument_list|()
expr_stmt|;
comment|// There are two different ways to register your own TestPartResultReporter.
comment|// You can register your own repoter to listen either only for test results
comment|// from the current thread or for results from all threads.
comment|// By default, each per-thread test result repoter just passes a new
comment|// TestPartResult to the global test result reporter, which registers the
comment|// test part result for the currently running test.
comment|// Returns the global test part result reporter.
name|TestPartResultReporterInterface
modifier|*
name|GetGlobalTestPartResultReporter
parameter_list|()
function_decl|;
comment|// Sets the global test part result reporter.
name|void
name|SetGlobalTestPartResultReporter
parameter_list|(
name|TestPartResultReporterInterface
modifier|*
name|reporter
parameter_list|)
function_decl|;
comment|// Returns the test part result reporter for the current thread.
name|TestPartResultReporterInterface
modifier|*
name|GetTestPartResultReporterForCurrentThread
parameter_list|()
function_decl|;
comment|// Sets the test part result reporter for the current thread.
name|void
name|SetTestPartResultReporterForCurrentThread
parameter_list|(
name|TestPartResultReporterInterface
modifier|*
name|reporter
parameter_list|)
function_decl|;
comment|// Gets the number of successful test cases.
name|int
name|successful_test_case_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of failed test cases.
name|int
name|failed_test_case_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of all test cases.
name|int
name|total_test_case_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of all test cases that contain at least one test
comment|// that should run.
name|int
name|test_case_to_run_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of successful tests.
name|int
name|successful_test_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of failed tests.
name|int
name|failed_test_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of disabled tests.
name|int
name|disabled_test_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of all tests.
name|int
name|total_test_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of tests that should run.
name|int
name|test_to_run_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the elapsed time, in milliseconds.
name|TimeInMillis
name|elapsed_time
argument_list|()
specifier|const
block|{
return|return
name|elapsed_time_
return|;
block|}
comment|// Returns true iff the unit test passed (i.e. all test cases passed).
name|bool
name|Passed
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Failed
argument_list|()
return|;
block|}
comment|// Returns true iff the unit test failed (i.e. some test case failed
comment|// or something outside of all tests failed).
name|bool
name|Failed
argument_list|()
specifier|const
block|{
return|return
name|failed_test_case_count
argument_list|()
operator|>
literal|0
operator|||
name|ad_hoc_test_result
argument_list|()
operator|->
name|Failed
argument_list|()
return|;
block|}
comment|// Returns the TestResult for the test that's currently running, or
comment|// the TestResult for the ad hoc test if no test is running.
name|internal
operator|::
name|TestResult
operator|*
name|current_test_result
argument_list|()
expr_stmt|;
comment|// Returns the TestResult for the ad hoc test.
specifier|const
name|internal
operator|::
name|TestResult
operator|*
name|ad_hoc_test_result
argument_list|()
specifier|const
block|{
return|return
operator|&
name|ad_hoc_test_result_
return|;
block|}
comment|// Sets the unit test result printer.
comment|//
comment|// Does nothing if the input and the current printer object are the
comment|// same; otherwise, deletes the old printer object and makes the
comment|// input the current printer.
name|void
name|set_result_printer
parameter_list|(
name|UnitTestEventListenerInterface
modifier|*
name|result_printer
parameter_list|)
function_decl|;
comment|// Returns the current unit test result printer if it is not NULL;
comment|// otherwise, creates an appropriate result printer, makes it the
comment|// current printer, and returns it.
name|UnitTestEventListenerInterface
modifier|*
name|result_printer
parameter_list|()
function_decl|;
comment|// Sets the OS stack trace getter.
comment|//
comment|// Does nothing if the input and the current OS stack trace getter
comment|// are the same; otherwise, deletes the old getter and makes the
comment|// input the current getter.
name|void
name|set_os_stack_trace_getter
parameter_list|(
name|OsStackTraceGetterInterface
modifier|*
name|getter
parameter_list|)
function_decl|;
comment|// Returns the current OS stack trace getter if it is not NULL;
comment|// otherwise, creates an OsStackTraceGetter, makes it the current
comment|// getter, and returns it.
name|OsStackTraceGetterInterface
modifier|*
name|os_stack_trace_getter
parameter_list|()
function_decl|;
comment|// Returns the current OS stack trace as a String.
comment|//
comment|// The maximum number of stack frames to be included is specified by
comment|// the gtest_stack_trace_depth flag.  The skip_count parameter
comment|// specifies the number of top frames to be skipped, which doesn't
comment|// count against the number of frames to be included.
comment|//
comment|// For example, if Foo() calls Bar(), which in turn calls
comment|// CurrentOsStackTraceExceptTop(1), Foo() will be included in the
comment|// trace but Bar() and CurrentOsStackTraceExceptTop() won't.
name|String
name|CurrentOsStackTraceExceptTop
parameter_list|(
name|int
name|skip_count
parameter_list|)
function_decl|;
comment|// Finds and returns a TestCase with the given name.  If one doesn't
comment|// exist, creates one and returns it.
comment|//
comment|// Arguments:
comment|//
comment|//   test_case_name: name of the test case
comment|//   set_up_tc:      pointer to the function that sets up the test case
comment|//   tear_down_tc:   pointer to the function that tears down the test case
name|TestCase
modifier|*
name|GetTestCase
argument_list|(
specifier|const
name|char
operator|*
name|test_case_name
argument_list|,
specifier|const
name|char
operator|*
name|comment
argument_list|,
name|Test
operator|::
name|SetUpTestCaseFunc
name|set_up_tc
argument_list|,
name|Test
operator|::
name|TearDownTestCaseFunc
name|tear_down_tc
argument_list|)
decl_stmt|;
comment|// Adds a TestInfo to the unit test.
comment|//
comment|// Arguments:
comment|//
comment|//   set_up_tc:    pointer to the function that sets up the test case
comment|//   tear_down_tc: pointer to the function that tears down the test case
comment|//   test_info:    the TestInfo object
name|void
name|AddTestInfo
argument_list|(
name|Test
operator|::
name|SetUpTestCaseFunc
name|set_up_tc
argument_list|,
name|Test
operator|::
name|TearDownTestCaseFunc
name|tear_down_tc
argument_list|,
name|TestInfo
operator|*
name|test_info
argument_list|)
block|{
comment|// In order to support thread-safe death tests, we need to
comment|// remember the original working directory when the test program
comment|// was first invoked.  We cannot do this in RUN_ALL_TESTS(), as
comment|// the user may have changed the current directory before calling
comment|// RUN_ALL_TESTS().  Therefore we capture the current directory in
comment|// AddTestInfo(), which is called to register a TEST or TEST_F
comment|// before main() is reached.
if|if
condition|(
name|original_working_dir_
operator|.
name|IsEmpty
argument_list|()
condition|)
block|{
name|original_working_dir_
operator|.
name|Set
argument_list|(
name|FilePath
operator|::
name|GetCurrentDir
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|original_working_dir_
operator|.
name|IsEmpty
argument_list|()
condition|)
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
literal|"Failed to get the current working directory."
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
name|GetTestCase
argument_list|(
name|test_info
operator|->
name|test_case_name
argument_list|()
argument_list|,
name|test_info
operator|->
name|test_case_comment
argument_list|()
argument_list|,
name|set_up_tc
argument_list|,
name|tear_down_tc
argument_list|)
operator|->
name|AddTestInfo
argument_list|(
name|test_info
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|GTEST_HAS_PARAM_TEST
comment|// Returns ParameterizedTestCaseRegistry object used to keep track of
comment|// value-parameterized tests and instantiate and register them.
name|internal
operator|::
name|ParameterizedTestCaseRegistry
operator|&
name|parameterized_test_registry
argument_list|()
block|{
return|return
name|parameterized_test_registry_
return|;
block|}
endif|#
directive|endif
comment|// GTEST_HAS_PARAM_TEST
comment|// Sets the TestCase object for the test that's currently running.
name|void
name|set_current_test_case
parameter_list|(
name|TestCase
modifier|*
name|current_test_case
parameter_list|)
block|{
name|current_test_case_
operator|=
name|current_test_case
expr_stmt|;
block|}
comment|// Sets the TestInfo object for the test that's currently running.  If
comment|// current_test_info is NULL, the assertion results will be stored in
comment|// ad_hoc_test_result_.
name|void
name|set_current_test_info
parameter_list|(
name|TestInfo
modifier|*
name|current_test_info
parameter_list|)
block|{
name|current_test_info_
operator|=
name|current_test_info
expr_stmt|;
block|}
comment|// Registers all parameterized tests defined using TEST_P and
comment|// INSTANTIATE_TEST_P, creating regular tests for each test/parameter
comment|// combination. This method can be called more then once; it has
comment|// guards protecting from registering the tests more then once.
comment|// If value-parameterized tests are disabled, RegisterParameterizedTests
comment|// is present but does nothing.
name|void
name|RegisterParameterizedTests
parameter_list|()
function_decl|;
comment|// Runs all tests in this UnitTest object, prints the result, and
comment|// returns 0 if all tests are successful, or 1 otherwise.  If any
comment|// exception is thrown during a test on Windows, this test is
comment|// considered to be failed, but the rest of the tests will still be
comment|// run.  (We disable exceptions on Linux and Mac OS X, so the issue
comment|// doesn't apply there.)
name|int
name|RunAllTests
parameter_list|()
function_decl|;
comment|// Clears the results of all tests, including the ad hoc test.
name|void
name|ClearResult
parameter_list|()
block|{
name|test_cases_
operator|.
name|ForEach
argument_list|(
name|TestCase
operator|::
name|ClearTestCaseResult
argument_list|)
expr_stmt|;
name|ad_hoc_test_result_
operator|.
name|Clear
argument_list|()
expr_stmt|;
block|}
comment|// Matches the full name of each test against the user-specified
comment|// filter to decide whether the test should run, then records the
comment|// result in each TestCase and TestInfo object.
comment|// Returns the number of tests that should run.
name|int
name|FilterTests
parameter_list|()
function_decl|;
comment|// Lists all the tests by name.
name|void
name|ListAllTests
parameter_list|()
function_decl|;
specifier|const
name|TestCase
operator|*
name|current_test_case
argument_list|()
specifier|const
block|{
return|return
name|current_test_case_
return|;
block|}
name|TestInfo
modifier|*
name|current_test_info
parameter_list|()
block|{
return|return
name|current_test_info_
return|;
block|}
specifier|const
name|TestInfo
operator|*
name|current_test_info
argument_list|()
specifier|const
block|{
return|return
name|current_test_info_
return|;
block|}
comment|// Returns the list of environments that need to be set-up/torn-down
comment|// before/after the tests are run.
name|internal
operator|::
name|List
operator|<
name|Environment
operator|*
operator|>
operator|*
name|environments
argument_list|()
block|{
return|return
operator|&
name|environments_
return|;
block|}
name|internal
operator|::
name|List
operator|<
name|Environment
operator|*
operator|>
operator|*
name|environments_in_reverse_order
argument_list|()
block|{
return|return
operator|&
name|environments_in_reverse_order_
return|;
block|}
name|internal
operator|::
name|List
operator|<
name|TestCase
operator|*
operator|>
operator|*
name|test_cases
argument_list|()
block|{
return|return
operator|&
name|test_cases_
return|;
block|}
specifier|const
name|internal
operator|::
name|List
operator|<
name|TestCase
operator|*
operator|>
operator|*
name|test_cases
argument_list|()
specifier|const
block|{
return|return
operator|&
name|test_cases_
return|;
block|}
comment|// Getters for the per-thread Google Test trace stack.
name|internal
operator|::
name|List
operator|<
name|TraceInfo
operator|>
operator|*
name|gtest_trace_stack
argument_list|()
block|{
return|return
name|gtest_trace_stack_
operator|.
name|pointer
argument_list|()
return|;
block|}
specifier|const
name|internal
operator|::
name|List
operator|<
name|TraceInfo
operator|>
operator|*
name|gtest_trace_stack
argument_list|()
specifier|const
block|{
return|return
name|gtest_trace_stack_
operator|.
name|pointer
argument_list|()
return|;
block|}
ifdef|#
directive|ifdef
name|GTEST_HAS_DEATH_TEST
comment|// Returns a pointer to the parsed --gtest_internal_run_death_test
comment|// flag, or NULL if that flag was not specified.
comment|// This information is useful only in a death test child process.
specifier|const
name|InternalRunDeathTestFlag
operator|*
name|internal_run_death_test_flag
argument_list|()
specifier|const
block|{
return|return
name|internal_run_death_test_flag_
operator|.
name|get
argument_list|()
return|;
block|}
comment|// Returns a pointer to the current death test factory.
name|internal
operator|::
name|DeathTestFactory
operator|*
name|death_test_factory
argument_list|()
block|{
return|return
name|death_test_factory_
operator|.
name|get
argument_list|()
return|;
block|}
name|friend
name|class
name|ReplaceDeathTestFactory
decl_stmt|;
endif|#
directive|endif
comment|// GTEST_HAS_DEATH_TEST
name|private
label|:
name|friend
name|class
operator|::
name|testing
operator|::
name|UnitTest
expr_stmt|;
comment|// The UnitTest object that owns this implementation object.
name|UnitTest
modifier|*
specifier|const
name|parent_
decl_stmt|;
comment|// The working directory when the first TEST() or TEST_F() was
comment|// executed.
name|internal
operator|::
name|FilePath
name|original_working_dir_
expr_stmt|;
comment|// The default test part result reporters.
name|DefaultGlobalTestPartResultReporter
name|default_global_test_part_result_reporter_
decl_stmt|;
name|DefaultPerThreadTestPartResultReporter
name|default_per_thread_test_part_result_reporter_
decl_stmt|;
comment|// Points to (but doesn't own) the global test part result reporter.
name|TestPartResultReporterInterface
modifier|*
name|global_test_part_result_repoter_
decl_stmt|;
comment|// Protects read and write access to global_test_part_result_reporter_.
name|internal
operator|::
name|Mutex
name|global_test_part_result_reporter_mutex_
expr_stmt|;
comment|// Points to (but doesn't own) the per-thread test part result reporter.
name|internal
operator|::
name|ThreadLocal
operator|<
name|TestPartResultReporterInterface
operator|*
operator|>
name|per_thread_test_part_result_reporter_
expr_stmt|;
comment|// The list of environments that need to be set-up/torn-down
comment|// before/after the tests are run.  environments_in_reverse_order_
comment|// simply mirrors environments_ in reverse order.
name|internal
operator|::
name|List
operator|<
name|Environment
operator|*
operator|>
name|environments_
expr_stmt|;
name|internal
operator|::
name|List
operator|<
name|Environment
operator|*
operator|>
name|environments_in_reverse_order_
expr_stmt|;
name|internal
operator|::
name|List
operator|<
name|TestCase
operator|*
operator|>
name|test_cases_
expr_stmt|;
comment|// The list of TestCases.
ifdef|#
directive|ifdef
name|GTEST_HAS_PARAM_TEST
comment|// ParameterizedTestRegistry object used to register value-parameterized
comment|// tests.
name|internal
operator|::
name|ParameterizedTestCaseRegistry
name|parameterized_test_registry_
expr_stmt|;
comment|// Indicates whether RegisterParameterizedTests() has been called already.
name|bool
name|parameterized_tests_registered_
decl_stmt|;
endif|#
directive|endif
comment|// GTEST_HAS_PARAM_TEST
comment|// Points to the last death test case registered.  Initially NULL.
name|internal
operator|::
name|ListNode
operator|<
name|TestCase
operator|*
operator|>
operator|*
name|last_death_test_case_
expr_stmt|;
comment|// This points to the TestCase for the currently running test.  It
comment|// changes as Google Test goes through one test case after another.
comment|// When no test is running, this is set to NULL and Google Test
comment|// stores assertion results in ad_hoc_test_result_.  Initally NULL.
name|TestCase
modifier|*
name|current_test_case_
decl_stmt|;
comment|// This points to the TestInfo for the currently running test.  It
comment|// changes as Google Test goes through one test after another.  When
comment|// no test is running, this is set to NULL and Google Test stores
comment|// assertion results in ad_hoc_test_result_.  Initially NULL.
name|TestInfo
modifier|*
name|current_test_info_
decl_stmt|;
comment|// Normally, a user only writes assertions inside a TEST or TEST_F,
comment|// or inside a function called by a TEST or TEST_F.  Since Google
comment|// Test keeps track of which test is current running, it can
comment|// associate such an assertion with the test it belongs to.
comment|//
comment|// If an assertion is encountered when no TEST or TEST_F is running,
comment|// Google Test attributes the assertion result to an imaginary "ad hoc"
comment|// test, and records the result in ad_hoc_test_result_.
name|internal
operator|::
name|TestResult
name|ad_hoc_test_result_
expr_stmt|;
comment|// The unit test result printer.  Will be deleted when the UnitTest
comment|// object is destructed.  By default, a plain text printer is used,
comment|// but the user can set this field to use a custom printer if that
comment|// is desired.
name|UnitTestEventListenerInterface
modifier|*
name|result_printer_
decl_stmt|;
comment|// The OS stack trace getter.  Will be deleted when the UnitTest
comment|// object is destructed.  By default, an OsStackTraceGetter is used,
comment|// but the user can set this field to use a custom getter if that is
comment|// desired.
name|OsStackTraceGetterInterface
modifier|*
name|os_stack_trace_getter_
decl_stmt|;
comment|// How long the test took to run, in milliseconds.
name|TimeInMillis
name|elapsed_time_
decl_stmt|;
ifdef|#
directive|ifdef
name|GTEST_HAS_DEATH_TEST
comment|// The decomposed components of the gtest_internal_run_death_test flag,
comment|// parsed when RUN_ALL_TESTS is called.
name|internal
operator|::
name|scoped_ptr
operator|<
name|InternalRunDeathTestFlag
operator|>
name|internal_run_death_test_flag_
expr_stmt|;
name|internal
operator|::
name|scoped_ptr
operator|<
name|internal
operator|::
name|DeathTestFactory
operator|>
name|death_test_factory_
expr_stmt|;
endif|#
directive|endif
comment|// GTEST_HAS_DEATH_TEST
comment|// A per-thread stack of traces created by the SCOPED_TRACE() macro.
name|internal
operator|::
name|ThreadLocal
operator|<
name|internal
operator|::
name|List
operator|<
name|TraceInfo
operator|>
expr|>
name|gtest_trace_stack_
expr_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|UnitTestImpl
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|// class UnitTestImpl
comment|// Convenience function for accessing the global UnitTest
comment|// implementation object.
specifier|inline
name|UnitTestImpl
modifier|*
name|GetUnitTestImpl
parameter_list|()
block|{
return|return
name|UnitTest
operator|::
name|GetInstance
argument_list|()
operator|->
name|impl
argument_list|()
return|;
block|}
comment|// Parses the command line for Google Test flags, without initializing
comment|// other parts of Google Test.
name|void
name|ParseGoogleTestFlagsOnly
parameter_list|(
name|int
modifier|*
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
name|void
name|ParseGoogleTestFlagsOnly
parameter_list|(
name|int
modifier|*
name|argc
parameter_list|,
name|wchar_t
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace internal
end_comment

begin_comment
unit|}
comment|// namespace testing
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_SRC_GTEST_INTERNAL_INL_H_
end_comment

end_unit

