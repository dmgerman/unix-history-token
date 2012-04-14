begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FunctionBlackList.cpp - blacklist of functions ----------*- C++ -*-===//
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
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is a utility class for instrumentation passes (like AddressSanitizer
end_comment

begin_comment
comment|// or ThreadSanitizer) to avoid instrumenting some functions based on
end_comment

begin_comment
comment|// user-supplied blacklist.
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

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|Regex
decl_stmt|;
comment|// Blacklisted functions are not instrumented.
comment|// The blacklist file contains one or more lines like this:
comment|// ---
comment|// fun:FunctionWildCard
comment|// ---
comment|// This is similar to the "ignore" feature of ThreadSanitizer.
comment|// http://code.google.com/p/data-race-test/wiki/ThreadSanitizerIgnores
name|class
name|FunctionBlackList
block|{
name|public
label|:
name|FunctionBlackList
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Path
argument_list|)
expr_stmt|;
name|bool
name|isIn
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
name|private
label|:
name|Regex
modifier|*
name|Functions
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

end_unit

