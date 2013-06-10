begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BlackList.h - blacklist for sanitizers ------------------*- C++ -*-===//
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
comment|// or ThreadSanitizer) to avoid instrumenting some functions or global
end_comment

begin_comment
comment|// variables based on a user-supplied blacklist.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The blacklist disables instrumentation of various functions and global
end_comment

begin_comment
comment|// variables.  Each line contains a prefix, followed by a wild card expression.
end_comment

begin_comment
comment|// Empty lines and lines starting with "#" are ignored.
end_comment

begin_comment
comment|// ---
end_comment

begin_comment
comment|// # Blacklisted items:
end_comment

begin_comment
comment|// fun:*_ZN4base6subtle*
end_comment

begin_comment
comment|// global:*global_with_bad_access_or_initialization*
end_comment

begin_comment
comment|// global-init:*global_with_initialization_issues*
end_comment

begin_comment
comment|// global-init-type:*Namespace::ClassName*
end_comment

begin_comment
comment|// src:file_with_tricky_code.cc
end_comment

begin_comment
comment|// global-init-src:ignore-global-initializers-issues.cc
end_comment

begin_comment
comment|// ---
end_comment

begin_comment
comment|// Note that the wild card is in fact an llvm::Regex, but * is automatically
end_comment

begin_comment
comment|// replaced with .*
end_comment

begin_comment
comment|// This is similar to the "ignore" feature of ThreadSanitizer.
end_comment

begin_comment
comment|// http://code.google.com/p/data-race-test/wiki/ThreadSanitizerIgnores
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
file|"llvm/ADT/StringMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Regex
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|BlackList
block|{
name|public
label|:
name|BlackList
argument_list|(
argument|const StringRef Path
argument_list|)
empty_stmt|;
comment|// Returns whether either this function or it's source file are blacklisted.
name|bool
name|isIn
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|)
decl|const
decl_stmt|;
comment|// Returns whether either this global or it's source file are blacklisted.
name|bool
name|isIn
argument_list|(
specifier|const
name|GlobalVariable
operator|&
name|G
argument_list|)
decl|const
decl_stmt|;
comment|// Returns whether this module is blacklisted by filename.
name|bool
name|isIn
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|)
decl|const
decl_stmt|;
comment|// Returns whether a global should be excluded from initialization checking.
name|bool
name|isInInit
argument_list|(
specifier|const
name|GlobalVariable
operator|&
name|G
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|StringMap
operator|<
name|Regex
operator|*
operator|>
name|Entries
expr_stmt|;
name|bool
name|inSection
argument_list|(
specifier|const
name|StringRef
name|Section
argument_list|,
specifier|const
name|StringRef
name|Query
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

end_unit

