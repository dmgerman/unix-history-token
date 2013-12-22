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
comment|// GTEST_IMPLEMENTATION_ is defined to 1 iff the current translation unit is
end_comment

begin_comment
comment|// part of Google Test's implementation; otherwise it's undefined.
end_comment

begin_if
if|#
directive|if
operator|!
name|GTEST_IMPLEMENTATION_
end_if

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
comment|// GTEST_IMPLEMENTATION_
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32_WCE
end_ifndef

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !_WIN32_WCE
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|// For strtoll/_strtoul64/malloc/free.
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|// For memmove.
end_comment

begin_include
include|#
directive|include
file|<algorithm>
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

begin_include
include|#
directive|include
file|"gtest/internal/gtest-port.h"
end_include

begin_if
if|#
directive|if
name|GTEST_OS_WINDOWS
end_if

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
file|"gtest/gtest.h"
end_include

begin_comment
comment|// NOLINT
end_comment

begin_include
include|#
directive|include
file|"gtest/gtest-spi.h"
end_include

begin_decl_stmt
name|namespace
name|testing
block|{
comment|// Declares the flags.
comment|//
comment|// We don't want the users to modify this flag in the code, but want
comment|// Google Test's own unit tests to be able to access it. Therefore we
comment|// declare it here as opposed to in gtest.h.
name|GTEST_DECLARE_bool_
argument_list|(
name|death_test_use_fork
argument_list|)
expr_stmt|;
name|namespace
name|internal
block|{
comment|// The value of GetTestTypeId() as seen from within the Google Test
comment|// library.  This is solely for testing GetTestTypeId().
name|GTEST_API_
specifier|extern
specifier|const
name|TypeId
name|kTestTypeIdInGoogleTest
decl_stmt|;
comment|// Names of the flags (needed for parsing Google Test flags).
specifier|const
name|char
name|kAlsoRunDisabledTestsFlag
index|[]
init|=
literal|"also_run_disabled_tests"
decl_stmt|;
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
name|kRandomSeedFlag
index|[]
init|=
literal|"random_seed"
decl_stmt|;
specifier|const
name|char
name|kRepeatFlag
index|[]
init|=
literal|"repeat"
decl_stmt|;
specifier|const
name|char
name|kShuffleFlag
index|[]
init|=
literal|"shuffle"
decl_stmt|;
specifier|const
name|char
name|kStackTraceDepthFlag
index|[]
init|=
literal|"stack_trace_depth"
decl_stmt|;
specifier|const
name|char
name|kStreamResultToFlag
index|[]
init|=
literal|"stream_result_to"
decl_stmt|;
specifier|const
name|char
name|kThrowOnFailureFlag
index|[]
init|=
literal|"throw_on_failure"
decl_stmt|;
comment|// A valid random seed must be in [1, kMaxRandomSeed].
specifier|const
name|int
name|kMaxRandomSeed
init|=
literal|99999
decl_stmt|;
comment|// g_help_flag is true iff the --help flag or an equivalent form is
comment|// specified on the command line.
name|GTEST_API_
specifier|extern
name|bool
name|g_help_flag
decl_stmt|;
comment|// Returns the current time in milliseconds.
name|GTEST_API_
name|TimeInMillis
name|GetTimeInMillis
parameter_list|()
function_decl|;
comment|// Returns true iff Google Test should use colors in the output.
name|GTEST_API_
name|bool
name|ShouldUseColor
parameter_list|(
name|bool
name|stdout_is_tty
parameter_list|)
function_decl|;
comment|// Formats the given time in milliseconds as seconds.
name|GTEST_API_
name|std
operator|::
name|string
name|FormatTimeInMillisAsSeconds
argument_list|(
argument|TimeInMillis ms
argument_list|)
expr_stmt|;
comment|// Parses a string for an Int32 flag, in the form of "--flag=value".
comment|//
comment|// On success, stores the value of the flag in *value, and returns
comment|// true.  On failure, returns false without changing *value.
name|GTEST_API_
name|bool
name|ParseInt32Flag
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|flag
parameter_list|,
name|Int32
modifier|*
name|value
parameter_list|)
function_decl|;
comment|// Returns a random seed in range [1, kMaxRandomSeed] based on the
comment|// given --gtest_random_seed flag value.
specifier|inline
name|int
name|GetRandomSeedFromFlag
parameter_list|(
name|Int32
name|random_seed_flag
parameter_list|)
block|{
specifier|const
name|unsigned
name|int
name|raw_seed
init|=
operator|(
name|random_seed_flag
operator|==
literal|0
operator|)
condition|?
name|static_cast
operator|<
name|unsigned
name|int
operator|>
operator|(
name|GetTimeInMillis
argument_list|()
operator|)
else|:
name|static_cast
operator|<
name|unsigned
name|int
operator|>
operator|(
name|random_seed_flag
operator|)
decl_stmt|;
comment|// Normalizes the actual seed to range [1, kMaxRandomSeed] such that
comment|// it's easy to type.
specifier|const
name|int
name|normalized_seed
init|=
name|static_cast
operator|<
name|int
operator|>
operator|(
operator|(
name|raw_seed
operator|-
literal|1U
operator|)
operator|%
name|static_cast
operator|<
name|unsigned
name|int
operator|>
operator|(
name|kMaxRandomSeed
operator|)
operator|)
operator|+
literal|1
decl_stmt|;
return|return
name|normalized_seed
return|;
block|}
comment|// Returns the first valid random seed after 'seed'.  The behavior is
comment|// undefined if 'seed' is invalid.  The seed after kMaxRandomSeed is
comment|// considered to be 1.
specifier|inline
name|int
name|GetNextRandomSeed
parameter_list|(
name|int
name|seed
parameter_list|)
block|{
name|GTEST_CHECK_
argument_list|(
literal|1
operator|<=
name|seed
operator|&&
name|seed
operator|<=
name|kMaxRandomSeed
argument_list|)
operator|<<
literal|"Invalid random seed "
operator|<<
name|seed
operator|<<
literal|" - must be in [1, "
operator|<<
name|kMaxRandomSeed
operator|<<
literal|"]."
expr_stmt|;
specifier|const
name|int
name|next_seed
init|=
name|seed
operator|+
literal|1
decl_stmt|;
return|return
operator|(
name|next_seed
operator|>
name|kMaxRandomSeed
operator|)
condition|?
literal|1
else|:
name|next_seed
return|;
block|}
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
name|also_run_disabled_tests_
operator|=
name|GTEST_FLAG
argument_list|(
name|also_run_disabled_tests
argument_list|)
expr_stmt|;
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
name|death_test_use_fork_
operator|=
name|GTEST_FLAG
argument_list|(
name|death_test_use_fork
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
name|random_seed_
operator|=
name|GTEST_FLAG
argument_list|(
name|random_seed
argument_list|)
expr_stmt|;
name|repeat_
operator|=
name|GTEST_FLAG
argument_list|(
name|repeat
argument_list|)
expr_stmt|;
name|shuffle_
operator|=
name|GTEST_FLAG
argument_list|(
name|shuffle
argument_list|)
expr_stmt|;
name|stack_trace_depth_
operator|=
name|GTEST_FLAG
argument_list|(
name|stack_trace_depth
argument_list|)
expr_stmt|;
name|stream_result_to_
operator|=
name|GTEST_FLAG
argument_list|(
name|stream_result_to
argument_list|)
expr_stmt|;
name|throw_on_failure_
operator|=
name|GTEST_FLAG
argument_list|(
name|throw_on_failure
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
name|also_run_disabled_tests
argument_list|)
operator|=
name|also_run_disabled_tests_
block|;
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
name|death_test_use_fork
argument_list|)
operator|=
name|death_test_use_fork_
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
name|random_seed
argument_list|)
operator|=
name|random_seed_
block|;
name|GTEST_FLAG
argument_list|(
name|repeat
argument_list|)
operator|=
name|repeat_
block|;
name|GTEST_FLAG
argument_list|(
name|shuffle
argument_list|)
operator|=
name|shuffle_
block|;
name|GTEST_FLAG
argument_list|(
name|stack_trace_depth
argument_list|)
operator|=
name|stack_trace_depth_
block|;
name|GTEST_FLAG
argument_list|(
name|stream_result_to
argument_list|)
operator|=
name|stream_result_to_
block|;
name|GTEST_FLAG
argument_list|(
name|throw_on_failure
argument_list|)
operator|=
name|throw_on_failure_
block|;   }
name|private
operator|:
comment|// Fields for saving the original values of flags.
name|bool
name|also_run_disabled_tests_
expr_stmt|;
name|bool
name|break_on_failure_
decl_stmt|;
name|bool
name|catch_exceptions_
decl_stmt|;
name|String
name|color_
decl_stmt|;
name|String
name|death_test_style_
decl_stmt|;
name|bool
name|death_test_use_fork_
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
name|internal
operator|::
name|Int32
name|random_seed_
expr_stmt|;
name|internal
operator|::
name|Int32
name|repeat_
expr_stmt|;
name|bool
name|shuffle_
decl_stmt|;
name|internal
operator|::
name|Int32
name|stack_trace_depth_
expr_stmt|;
name|String
name|stream_result_to_
decl_stmt|;
name|bool
name|throw_on_failure_
decl_stmt|;
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
name|GTEST_API_
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
name|GTEST_API_
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
comment|// Reads the GTEST_SHARD_STATUS_FILE environment variable, and creates the file
comment|// if the variable is present. If a file already exists at this location, this
comment|// function will write over it. If the variable is present, but the file cannot
comment|// be created, prints an error and exits.
name|void
name|WriteToShardStatusFileIfNeeded
parameter_list|()
function_decl|;
comment|// Checks whether sharding is enabled by examining the relevant
comment|// environment variable values. If the variables are present,
comment|// but inconsistent (e.g., shard_index>= total_shards), prints
comment|// an error and exits. If in_subprocess_for_death_test, sharding is
comment|// disabled because it must only be applied to the original test
comment|// process. Otherwise, we could filter out death tests we intended to execute.
name|GTEST_API_
name|bool
name|ShouldShard
parameter_list|(
specifier|const
name|char
modifier|*
name|total_shards_str
parameter_list|,
specifier|const
name|char
modifier|*
name|shard_index_str
parameter_list|,
name|bool
name|in_subprocess_for_death_test
parameter_list|)
function_decl|;
comment|// Parses the environment variable var as an Int32. If it is unset,
comment|// returns default_val. If it is not an Int32, prints an error and
comment|// and aborts.
name|GTEST_API_
name|Int32
name|Int32FromEnvOrDie
parameter_list|(
specifier|const
name|char
modifier|*
name|env_var
parameter_list|,
name|Int32
name|default_val
parameter_list|)
function_decl|;
comment|// Given the total number of shards, the shard index, and the test id,
comment|// returns true iff the test should be run on this shard. The test id is
comment|// some arbitrary but unique non-negative integer assigned to each test
comment|// method. Assumes that 0<= shard_index< total_shards.
name|GTEST_API_
name|bool
name|ShouldRunTestOnShard
parameter_list|(
name|int
name|total_shards
parameter_list|,
name|int
name|shard_index
parameter_list|,
name|int
name|test_id
parameter_list|)
function_decl|;
comment|// STL container utilities.
comment|// Returns the number of elements in the given container that satisfy
comment|// the given predicate.
name|template
operator|<
name|class
name|Container
operator|,
name|typename
name|Predicate
operator|>
specifier|inline
name|int
name|CountIf
argument_list|(
argument|const Container& c
argument_list|,
argument|Predicate predicate
argument_list|)
block|{
comment|// Implemented as an explicit loop since std::count_if() in libCstd on
comment|// Solaris has a non-standard signature.
name|int
name|count
operator|=
literal|0
block|;
for|for
control|(
name|typename
name|Container
operator|::
name|const_iterator
name|it
operator|=
name|c
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|c
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
name|predicate
argument_list|(
operator|*
name|it
argument_list|)
condition|)
operator|++
name|count
expr_stmt|;
block|}
return|return
name|count
return|;
block|}
comment|// Applies a function/functor to each element in the container.
name|template
operator|<
name|class
name|Container
operator|,
name|typename
name|Functor
operator|>
name|void
name|ForEach
argument_list|(
argument|const Container& c
argument_list|,
argument|Functor functor
argument_list|)
block|{
name|std
operator|::
name|for_each
argument_list|(
name|c
operator|.
name|begin
argument_list|()
argument_list|,
name|c
operator|.
name|end
argument_list|()
argument_list|,
name|functor
argument_list|)
block|; }
comment|// Returns the i-th element of the vector, or default_value if i is not
comment|// in range [0, v.size()).
name|template
operator|<
name|typename
name|E
operator|>
specifier|inline
name|E
name|GetElementOr
argument_list|(
argument|const std::vector<E>& v
argument_list|,
argument|int i
argument_list|,
argument|E default_value
argument_list|)
block|{
return|return
operator|(
name|i
operator|<
literal|0
operator|||
name|i
operator|>=
name|static_cast
operator|<
name|int
operator|>
operator|(
name|v
operator|.
name|size
argument_list|()
operator|)
operator|)
operator|?
name|default_value
operator|:
name|v
index|[
name|i
index|]
return|;
block|}
comment|// Performs an in-place shuffle of a range of the vector's elements.
comment|// 'begin' and 'end' are element indices as an STL-style range;
comment|// i.e. [begin, end) are shuffled, where 'end' == size() means to
comment|// shuffle to the end of the vector.
name|template
operator|<
name|typename
name|E
operator|>
name|void
name|ShuffleRange
argument_list|(
argument|internal::Random* random
argument_list|,
argument|int begin
argument_list|,
argument|int end
argument_list|,
argument|std::vector<E>* v
argument_list|)
block|{
specifier|const
name|int
name|size
operator|=
name|static_cast
operator|<
name|int
operator|>
operator|(
name|v
operator|->
name|size
argument_list|()
operator|)
block|;
name|GTEST_CHECK_
argument_list|(
literal|0
operator|<=
name|begin
operator|&&
name|begin
operator|<=
name|size
argument_list|)
operator|<<
literal|"Invalid shuffle range start "
operator|<<
name|begin
operator|<<
literal|": must be in range [0, "
operator|<<
name|size
operator|<<
literal|"]."
block|;
name|GTEST_CHECK_
argument_list|(
name|begin
operator|<=
name|end
operator|&&
name|end
operator|<=
name|size
argument_list|)
operator|<<
literal|"Invalid shuffle range finish "
operator|<<
name|end
operator|<<
literal|": must be in range ["
operator|<<
name|begin
operator|<<
literal|", "
operator|<<
name|size
operator|<<
literal|"]."
block|;
comment|// Fisher-Yates shuffle, from
comment|// http://en.wikipedia.org/wiki/Fisher-Yates_shuffle
for|for
control|(
name|int
name|range_width
init|=
name|end
operator|-
name|begin
init|;
name|range_width
operator|>=
literal|2
condition|;
name|range_width
operator|--
control|)
block|{
specifier|const
name|int
name|last_in_range
init|=
name|begin
operator|+
name|range_width
operator|-
literal|1
decl_stmt|;
specifier|const
name|int
name|selected
init|=
name|begin
operator|+
name|random
operator|->
name|Generate
argument_list|(
name|range_width
argument_list|)
decl_stmt|;
name|std
operator|::
name|swap
argument_list|(
operator|(
operator|*
name|v
operator|)
index|[
name|selected
index|]
argument_list|,
operator|(
operator|*
name|v
operator|)
index|[
name|last_in_range
index|]
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Performs an in-place shuffle of the vector's elements.
name|template
operator|<
name|typename
name|E
operator|>
specifier|inline
name|void
name|Shuffle
argument_list|(
argument|internal::Random* random
argument_list|,
argument|std::vector<E>* v
argument_list|)
block|{
name|ShuffleRange
argument_list|(
name|random
argument_list|,
literal|0
argument_list|,
name|static_cast
operator|<
name|int
operator|>
operator|(
name|v
operator|->
name|size
argument_list|()
operator|)
argument_list|,
name|v
argument_list|)
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
argument|T* x
argument_list|)
block|{
name|delete
name|x
block|; }
comment|// A predicate that checks the key of a TestProperty against a known key.
comment|//
comment|// TestPropertyKeyIs is copyable.
name|class
name|TestPropertyKeyIs
block|{
name|public
operator|:
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
operator|:
name|String
name|key_
block|; }
expr_stmt|;
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
name|GTEST_API_
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
comment|// Returns the absolute path of the requested output file, or the
comment|// default (test_detail.xml in the original working directory) if
comment|// none was explicitly specified.
specifier|static
name|String
name|GetAbsolutePathToOutputFile
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
if|#
directive|if
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
name|GTEST_API_
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
expr_stmt|;
comment|// Returns the current OS stack trace as a String.  Parameters:
comment|//
comment|//   max_depth  - the maximum number of stack frames to be included
comment|//                in the trace.
comment|//   skip_count - the number of top frames to be skipped; doesn't count
comment|//                against max_depth.
name|virtual
name|String
name|CurrentStackTrace
parameter_list|(
name|int
name|max_depth
parameter_list|,
name|int
name|skip_count
parameter_list|)
init|=
literal|0
function_decl|;
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
operator|:
name|caller_frame_
argument_list|(
argument|NULL
argument_list|)
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
block|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|DefaultGlobalTestPartResultReporter
argument_list|)
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
block|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|DefaultPerThreadTestPartResultReporter
argument_list|)
block|; }
decl_stmt|;
comment|// The private implementation of the UnitTest class.  We don't protect
comment|// the methods under a mutex, as this class is not accessible by a
comment|// user and the UnitTest class that delegates work to this class does
comment|// proper locking.
name|class
name|GTEST_API_
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
comment|// Gets the i-th test case among all the test cases. i can range from 0 to
comment|// total_test_case_count() - 1. If i is not in that range, returns NULL.
specifier|const
name|TestCase
modifier|*
name|GetTestCase
argument_list|(
name|int
name|i
argument_list|)
decl|const
block|{
specifier|const
name|int
name|index
init|=
name|GetElementOr
argument_list|(
name|test_case_indices_
argument_list|,
name|i
argument_list|,
operator|-
literal|1
argument_list|)
decl_stmt|;
return|return
name|index
operator|<
literal|0
condition|?
name|NULL
else|:
name|test_cases_
index|[
name|i
index|]
return|;
block|}
comment|// Gets the i-th test case among all the test cases. i can range from 0 to
comment|// total_test_case_count() - 1. If i is not in that range, returns NULL.
name|TestCase
modifier|*
name|GetMutableTestCase
parameter_list|(
name|int
name|i
parameter_list|)
block|{
specifier|const
name|int
name|index
init|=
name|GetElementOr
argument_list|(
name|test_case_indices_
argument_list|,
name|i
argument_list|,
operator|-
literal|1
argument_list|)
decl_stmt|;
return|return
name|index
operator|<
literal|0
condition|?
name|NULL
else|:
name|test_cases_
index|[
name|index
index|]
return|;
block|}
comment|// Provides access to the event listener list.
name|TestEventListeners
modifier|*
name|listeners
parameter_list|()
block|{
return|return
operator|&
name|listeners_
return|;
block|}
comment|// Returns the TestResult for the test that's currently running, or
comment|// the TestResult for the ad hoc test if no test is running.
name|TestResult
modifier|*
name|current_test_result
parameter_list|()
function_decl|;
comment|// Returns the TestResult for the ad hoc test.
specifier|const
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
comment|//   type_param:     the name of the test's type parameter, or NULL if
comment|//                   this is not a typed or a type-parameterized test.
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
name|type_param
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
name|GTEST_CHECK_
argument_list|(
operator|!
name|original_working_dir_
operator|.
name|IsEmpty
argument_list|()
argument_list|)
operator|<<
literal|"Failed to get the current working directory."
expr_stmt|;
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
name|type_param
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
if|#
directive|if
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
name|a_current_test_case
parameter_list|)
block|{
name|current_test_case_
operator|=
name|a_current_test_case
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
name|a_current_test_info
parameter_list|)
block|{
name|current_test_info_
operator|=
name|a_current_test_info
expr_stmt|;
block|}
comment|// Registers all parameterized tests defined using TEST_P and
comment|// INSTANTIATE_TEST_CASE_P, creating regular tests for each test/parameter
comment|// combination. This method can be called more then once; it has guards
comment|// protecting from registering the tests more then once.  If
comment|// value-parameterized tests are disabled, RegisterParameterizedTests is
comment|// present but does nothing.
name|void
name|RegisterParameterizedTests
parameter_list|()
function_decl|;
comment|// Runs all tests in this UnitTest object, prints the result, and
comment|// returns true if all tests are successful.  If any exception is
comment|// thrown during a test, this test is considered to be failed, but
comment|// the rest of the tests will still be run.
name|bool
name|RunAllTests
parameter_list|()
function_decl|;
comment|// Clears the results of all tests, except the ad hoc tests.
name|void
name|ClearNonAdHocTestResult
parameter_list|()
block|{
name|ForEach
argument_list|(
name|test_cases_
argument_list|,
name|TestCase
operator|::
name|ClearTestCaseResult
argument_list|)
expr_stmt|;
block|}
comment|// Clears the results of ad-hoc test assertions.
name|void
name|ClearAdHocTestResult
parameter_list|()
block|{
name|ad_hoc_test_result_
operator|.
name|Clear
argument_list|()
expr_stmt|;
block|}
enum|enum
name|ReactionToSharding
block|{
name|HONOR_SHARDING_PROTOCOL
block|,
name|IGNORE_SHARDING_PROTOCOL
block|}
enum|;
comment|// Matches the full name of each test against the user-specified
comment|// filter to decide whether the test should run, then records the
comment|// result in each TestCase and TestInfo object.
comment|// If shard_tests == HONOR_SHARDING_PROTOCOL, further filters tests
comment|// based on sharding variables in the environment.
comment|// Returns the number of tests that should run.
name|int
name|FilterTests
parameter_list|(
name|ReactionToSharding
name|shard_tests
parameter_list|)
function_decl|;
comment|// Prints the names of the tests matching the user-specified filter flag.
name|void
name|ListTestsMatchingFilter
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
comment|// Returns the vector of environments that need to be set-up/torn-down
comment|// before/after the tests are run.
name|std
operator|::
name|vector
operator|<
name|Environment
operator|*
operator|>
operator|&
name|environments
argument_list|()
block|{
return|return
name|environments_
return|;
block|}
comment|// Getters for the per-thread Google Test trace stack.
name|std
operator|::
name|vector
operator|<
name|TraceInfo
operator|>
operator|&
name|gtest_trace_stack
argument_list|()
block|{
return|return
operator|*
operator|(
name|gtest_trace_stack_
operator|.
name|pointer
argument_list|()
operator|)
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|TraceInfo
operator|>
operator|&
name|gtest_trace_stack
argument_list|()
specifier|const
block|{
return|return
name|gtest_trace_stack_
operator|.
name|get
argument_list|()
return|;
block|}
if|#
directive|if
name|GTEST_HAS_DEATH_TEST
name|void
name|InitDeathTestSubprocessControlInfo
parameter_list|()
block|{
name|internal_run_death_test_flag_
operator|.
name|reset
argument_list|(
name|ParseInternalRunDeathTestFlag
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Returns a pointer to the parsed --gtest_internal_run_death_test
comment|// flag, or NULL if that flag was not specified.
comment|// This information is useful only in a death test child process.
comment|// Must not be called before a call to InitGoogleTest.
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
name|void
name|SuppressTestEventsIfInSubprocess
parameter_list|()
function_decl|;
name|friend
name|class
name|ReplaceDeathTestFactory
decl_stmt|;
endif|#
directive|endif
comment|// GTEST_HAS_DEATH_TEST
comment|// Initializes the event listener performing XML output as specified by
comment|// UnitTestOptions. Must not be called before InitGoogleTest.
name|void
name|ConfigureXmlOutput
parameter_list|()
function_decl|;
if|#
directive|if
name|GTEST_CAN_STREAM_RESULTS_
comment|// Initializes the event listener for streaming test results to a socket.
comment|// Must not be called before InitGoogleTest.
name|void
name|ConfigureStreamingOutput
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|// Performs initialization dependent upon flag values obtained in
comment|// ParseGoogleTestFlagsOnly.  Is called from InitGoogleTest after the call to
comment|// ParseGoogleTestFlagsOnly.  In case a user neglects to call InitGoogleTest
comment|// this function is also called from RunAllTests.  Since this function can be
comment|// called more than once, it has to be idempotent.
name|void
name|PostFlagParsingInit
parameter_list|()
function_decl|;
comment|// Gets the random seed used at the start of the current test iteration.
name|int
name|random_seed
argument_list|()
specifier|const
block|{
return|return
name|random_seed_
return|;
block|}
comment|// Gets the random number generator.
name|internal
operator|::
name|Random
operator|*
name|random
argument_list|()
block|{
return|return
operator|&
name|random_
return|;
block|}
comment|// Shuffles all test cases, and the tests within each test case,
comment|// making sure that death tests are still run first.
name|void
name|ShuffleTests
parameter_list|()
function_decl|;
comment|// Restores the test cases and tests to their order before the first shuffle.
name|void
name|UnshuffleTests
parameter_list|()
function_decl|;
comment|// Returns the value of GTEST_FLAG(catch_exceptions) at the moment
comment|// UnitTest::Run() starts.
name|bool
name|catch_exceptions
argument_list|()
specifier|const
block|{
return|return
name|catch_exceptions_
return|;
block|}
name|private
label|:
name|friend
name|class
operator|::
name|testing
operator|::
name|UnitTest
expr_stmt|;
comment|// Used by UnitTest::Run() to capture the state of
comment|// GTEST_FLAG(catch_exceptions) at the moment it starts.
name|void
name|set_catch_exceptions
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|catch_exceptions_
operator|=
name|value
expr_stmt|;
block|}
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
comment|// The vector of environments that need to be set-up/torn-down
comment|// before/after the tests are run.
name|std
operator|::
name|vector
operator|<
name|Environment
operator|*
operator|>
name|environments_
expr_stmt|;
comment|// The vector of TestCases in their original order.  It owns the
comment|// elements in the vector.
name|std
operator|::
name|vector
operator|<
name|TestCase
operator|*
operator|>
name|test_cases_
expr_stmt|;
comment|// Provides a level of indirection for the test case list to allow
comment|// easy shuffling and restoring the test case order.  The i-th
comment|// element of this vector is the index of the i-th test case in the
comment|// shuffled order.
name|std
operator|::
name|vector
operator|<
name|int
operator|>
name|test_case_indices_
expr_stmt|;
if|#
directive|if
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
comment|// Index of the last death test case registered.  Initially -1.
name|int
name|last_death_test_case_
decl_stmt|;
comment|// This points to the TestCase for the currently running test.  It
comment|// changes as Google Test goes through one test case after another.
comment|// When no test is running, this is set to NULL and Google Test
comment|// stores assertion results in ad_hoc_test_result_.  Initially NULL.
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
name|TestResult
name|ad_hoc_test_result_
decl_stmt|;
comment|// The list of event listeners that can be used to track events inside
comment|// Google Test.
name|TestEventListeners
name|listeners_
decl_stmt|;
comment|// The OS stack trace getter.  Will be deleted when the UnitTest
comment|// object is destructed.  By default, an OsStackTraceGetter is used,
comment|// but the user can set this field to use a custom getter if that is
comment|// desired.
name|OsStackTraceGetterInterface
modifier|*
name|os_stack_trace_getter_
decl_stmt|;
comment|// True iff PostFlagParsingInit() has been called.
name|bool
name|post_flag_parse_init_performed_
decl_stmt|;
comment|// The random number seed used at the beginning of the test run.
name|int
name|random_seed_
decl_stmt|;
comment|// Our random number generator.
name|internal
operator|::
name|Random
name|random_
expr_stmt|;
comment|// How long the test took to run, in milliseconds.
name|TimeInMillis
name|elapsed_time_
decl_stmt|;
if|#
directive|if
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
name|std
operator|::
name|vector
operator|<
name|TraceInfo
operator|>
expr|>
name|gtest_trace_stack_
expr_stmt|;
comment|// The value of GTEST_FLAG(catch_exceptions) at the moment RunAllTests()
comment|// starts.
name|bool
name|catch_exceptions_
decl_stmt|;
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
if|#
directive|if
name|GTEST_USES_SIMPLE_RE
comment|// Internal helper functions for implementing the simple regular
comment|// expression matcher.
name|GTEST_API_
name|bool
name|IsInSet
parameter_list|(
name|char
name|ch
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
name|GTEST_API_
name|bool
name|IsAsciiDigit
parameter_list|(
name|char
name|ch
parameter_list|)
function_decl|;
name|GTEST_API_
name|bool
name|IsAsciiPunct
parameter_list|(
name|char
name|ch
parameter_list|)
function_decl|;
name|GTEST_API_
name|bool
name|IsRepeat
parameter_list|(
name|char
name|ch
parameter_list|)
function_decl|;
name|GTEST_API_
name|bool
name|IsAsciiWhiteSpace
parameter_list|(
name|char
name|ch
parameter_list|)
function_decl|;
name|GTEST_API_
name|bool
name|IsAsciiWordChar
parameter_list|(
name|char
name|ch
parameter_list|)
function_decl|;
name|GTEST_API_
name|bool
name|IsValidEscape
parameter_list|(
name|char
name|ch
parameter_list|)
function_decl|;
name|GTEST_API_
name|bool
name|AtomMatchesChar
parameter_list|(
name|bool
name|escaped
parameter_list|,
name|char
name|pattern
parameter_list|,
name|char
name|ch
parameter_list|)
function_decl|;
name|GTEST_API_
name|bool
name|ValidateRegex
parameter_list|(
specifier|const
name|char
modifier|*
name|regex
parameter_list|)
function_decl|;
name|GTEST_API_
name|bool
name|MatchRegexAtHead
parameter_list|(
specifier|const
name|char
modifier|*
name|regex
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
name|GTEST_API_
name|bool
name|MatchRepetitionAndRegexAtHead
parameter_list|(
name|bool
name|escaped
parameter_list|,
name|char
name|ch
parameter_list|,
name|char
name|repeat
parameter_list|,
specifier|const
name|char
modifier|*
name|regex
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
name|GTEST_API_
name|bool
name|MatchRegexAnywhere
parameter_list|(
specifier|const
name|char
modifier|*
name|regex
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// GTEST_USES_SIMPLE_RE
comment|// Parses the command line for Google Test flags, without initializing
comment|// other parts of Google Test.
name|GTEST_API_
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
name|GTEST_API_
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
if|#
directive|if
name|GTEST_HAS_DEATH_TEST
comment|// Returns the message describing the last system error, regardless of the
comment|// platform.
name|GTEST_API_
name|String
name|GetLastErrnoDescription
parameter_list|()
function_decl|;
if|#
directive|if
name|GTEST_OS_WINDOWS
comment|// Provides leak-safe Windows kernel handle ownership.
name|class
name|AutoHandle
block|{
name|public
label|:
name|AutoHandle
argument_list|()
operator|:
name|handle_
argument_list|(
argument|INVALID_HANDLE_VALUE
argument_list|)
block|{}
name|explicit
name|AutoHandle
argument_list|(
argument|HANDLE handle
argument_list|)
operator|:
name|handle_
argument_list|(
argument|handle
argument_list|)
block|{}
operator|~
name|AutoHandle
argument_list|()
block|{
name|Reset
argument_list|()
block|; }
name|HANDLE
name|Get
argument_list|()
specifier|const
block|{
return|return
name|handle_
return|;
block|}
name|void
name|Reset
parameter_list|()
block|{
name|Reset
argument_list|(
name|INVALID_HANDLE_VALUE
argument_list|)
expr_stmt|;
block|}
name|void
name|Reset
parameter_list|(
name|HANDLE
name|handle
parameter_list|)
block|{
if|if
condition|(
name|handle
operator|!=
name|handle_
condition|)
block|{
if|if
condition|(
name|handle_
operator|!=
name|INVALID_HANDLE_VALUE
condition|)
operator|::
name|CloseHandle
argument_list|(
name|handle_
argument_list|)
expr_stmt|;
name|handle_
operator|=
name|handle
expr_stmt|;
block|}
block|}
name|private
label|:
name|HANDLE
name|handle_
decl_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|AutoHandle
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
endif|#
directive|endif
comment|// GTEST_OS_WINDOWS
comment|// Attempts to parse a string into a positive integer pointed to by the
comment|// number parameter.  Returns true if that is possible.
comment|// GTEST_HAS_DEATH_TEST implies that we have ::std::string, so we can use
comment|// it here.
name|template
operator|<
name|typename
name|Integer
operator|>
name|bool
name|ParseNaturalNumber
argument_list|(
argument|const ::std::string& str
argument_list|,
argument|Integer* number
argument_list|)
block|{
comment|// Fail fast if the given string does not begin with a digit;
comment|// this bypasses strtoXXX's "optional leading whitespace and plus
comment|// or minus sign" semantics, which are undesirable here.
if|if
condition|(
name|str
operator|.
name|empty
argument_list|()
operator|||
operator|!
name|IsDigit
argument_list|(
name|str
index|[
literal|0
index|]
argument_list|)
condition|)
block|{
return|return
name|false
return|;
block|}
name|errno
operator|=
literal|0
expr_stmt|;
name|char
operator|*
name|end
expr_stmt|;
comment|// BiggestConvertible is the largest integer type that system-provided
comment|// string-to-number conversion routines can return.
if|#
directive|if
name|GTEST_OS_WINDOWS
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
comment|// MSVC and C++ Builder define __int64 instead of the standard long long.
typedef|typedef
name|unsigned
name|__int64
name|BiggestConvertible
typedef|;
specifier|const
name|BiggestConvertible
name|parsed
init|=
name|_strtoui64
argument_list|(
name|str
operator|.
name|c_str
argument_list|()
argument_list|,
operator|&
name|end
argument_list|,
literal|10
argument_list|)
decl_stmt|;
else|#
directive|else
typedef|typedef
name|unsigned
name|long
name|long
name|BiggestConvertible
typedef|;
comment|// NOLINT
specifier|const
name|BiggestConvertible
name|parsed
init|=
name|strtoull
argument_list|(
name|str
operator|.
name|c_str
argument_list|()
argument_list|,
operator|&
name|end
argument_list|,
literal|10
argument_list|)
decl_stmt|;
endif|#
directive|endif
comment|// GTEST_OS_WINDOWS&& !defined(__GNUC__)
specifier|const
name|bool
name|parse_success
init|=
operator|*
name|end
operator|==
literal|'\0'
operator|&&
name|errno
operator|==
literal|0
decl_stmt|;
comment|// TODO(vladl@google.com): Convert this to compile time assertion when it is
comment|// available.
name|GTEST_CHECK_
argument_list|(
sizeof|sizeof
argument_list|(
name|Integer
argument_list|)
operator|<=
sizeof|sizeof
argument_list|(
name|parsed
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|Integer
name|result
init|=
name|static_cast
operator|<
name|Integer
operator|>
operator|(
name|parsed
operator|)
decl_stmt|;
if|if
condition|(
name|parse_success
operator|&&
name|static_cast
operator|<
name|BiggestConvertible
operator|>
operator|(
name|result
operator|)
operator|==
name|parsed
condition|)
block|{
operator|*
name|number
operator|=
name|result
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
endif|#
directive|endif
comment|// GTEST_HAS_DEATH_TEST
comment|// TestResult contains some private methods that should be hidden from
comment|// Google Test user but are required for testing. This class allow our tests
comment|// to access them.
comment|//
comment|// This class is supplied only for the purpose of testing Google Test's own
comment|// constructs. Do not use it in user tests, either directly or indirectly.
name|class
name|TestResultAccessor
block|{
name|public
label|:
specifier|static
name|void
name|RecordProperty
parameter_list|(
name|TestResult
modifier|*
name|test_result
parameter_list|,
specifier|const
name|TestProperty
modifier|&
name|property
parameter_list|)
block|{
name|test_result
operator|->
name|RecordProperty
argument_list|(
name|property
argument_list|)
expr_stmt|;
block|}
specifier|static
name|void
name|ClearTestPartResults
parameter_list|(
name|TestResult
modifier|*
name|test_result
parameter_list|)
block|{
name|test_result
operator|->
name|ClearTestPartResults
argument_list|()
expr_stmt|;
block|}
specifier|static
specifier|const
name|std
operator|::
name|vector
operator|<
name|testing
operator|::
name|TestPartResult
operator|>
operator|&
name|test_part_results
argument_list|(
argument|const TestResult& test_result
argument_list|)
block|{
return|return
name|test_result
operator|.
name|test_part_results
argument_list|()
return|;
block|}
block|}
empty_stmt|;
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

