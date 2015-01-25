begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SpecialCaseList.h - special case list for sanitizers ----*- C++ -*-===//
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
comment|// This is a utility class used to parse user-provided text files with
end_comment

begin_comment
comment|// "special case lists" for code sanitizers. Such files are used to
end_comment

begin_comment
comment|// define "ABI list" for DataFlowSanitizer and blacklists for another sanitizers
end_comment

begin_comment
comment|// like AddressSanitizer or UndefinedBehaviorSanitizer.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Empty lines and lines starting with "#" are ignored. All the rest lines
end_comment

begin_comment
comment|// should have the form:
end_comment

begin_comment
comment|//   section:wildcard_expression[=category]
end_comment

begin_comment
comment|// If category is not specified, it is assumed to be empty string.
end_comment

begin_comment
comment|// Definitions of "section" and "category" are sanitizer-specific. For example,
end_comment

begin_comment
comment|// sanitizer blacklists support sections "src", "fun" and "global".
end_comment

begin_comment
comment|// Wildcard expressions define, respectively, source files, functions or
end_comment

begin_comment
comment|// globals which shouldn't be instrumented.
end_comment

begin_comment
comment|// Examples of categories:
end_comment

begin_comment
comment|//   "functional": used in DFSan to list functions with pure functional
end_comment

begin_comment
comment|//                 semantics.
end_comment

begin_comment
comment|//   "init": used in ASan blacklist to disable initialization-order bugs
end_comment

begin_comment
comment|//           detection for certain globals or source files.
end_comment

begin_comment
comment|// Full special case list file example:
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
comment|// global:*global_with_initialization_issues*=init
end_comment

begin_comment
comment|// type:*Namespace::ClassName*=init
end_comment

begin_comment
comment|// src:file_with_tricky_code.cc
end_comment

begin_comment
comment|// src:ignore-global-initializers-issues.cc=init
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// # Functions with pure functional semantics:
end_comment

begin_comment
comment|// fun:cos=functional
end_comment

begin_comment
comment|// fun:sin=functional
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_SPECIALCASELIST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_SPECIALCASELIST_H
end_define

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
name|MemoryBuffer
decl_stmt|;
name|class
name|Regex
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|SpecialCaseList
block|{
name|public
label|:
comment|/// Parses the special case list from a file. If Path is empty, returns
comment|/// an empty special case list. On failure, returns 0 and writes an error
comment|/// message to string.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|SpecialCaseList
operator|>
name|create
argument_list|(
argument|StringRef Path
argument_list|,
argument|std::string&Error
argument_list|)
expr_stmt|;
comment|/// Parses the special case list from a memory buffer. On failure, returns
comment|/// 0 and writes an error message to string.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|SpecialCaseList
operator|>
name|create
argument_list|(
specifier|const
name|MemoryBuffer
operator|*
name|MB
argument_list|,
name|std
operator|::
name|string
operator|&
name|Error
argument_list|)
expr_stmt|;
comment|/// Parses the special case list from a file. On failure, reports a fatal
comment|/// error.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|SpecialCaseList
operator|>
name|createOrDie
argument_list|(
argument|StringRef Path
argument_list|)
expr_stmt|;
operator|~
name|SpecialCaseList
argument_list|()
expr_stmt|;
comment|/// Returns true, if special case list contains a line
comment|/// \code
comment|///   @Section:<E>=@Category
comment|/// \endcode
comment|/// and @Query satisfies a wildcard expression<E>.
name|bool
name|inSection
argument_list|(
name|StringRef
name|Section
argument_list|,
name|StringRef
name|Query
argument_list|,
name|StringRef
name|Category
operator|=
name|StringRef
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|SpecialCaseList
argument_list|(
argument|SpecialCaseList const&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|SpecialCaseList
modifier|&
name|operator
init|=
operator|(
name|SpecialCaseList
specifier|const
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
struct_decl|struct
name|Entry
struct_decl|;
name|StringMap
operator|<
name|StringMap
operator|<
name|Entry
operator|>
expr|>
name|Entries
expr_stmt|;
name|SpecialCaseList
argument_list|()
expr_stmt|;
comment|/// Parses just-constructed SpecialCaseList entries from a memory buffer.
name|bool
name|parse
argument_list|(
specifier|const
name|MemoryBuffer
operator|*
name|MB
argument_list|,
name|std
operator|::
name|string
operator|&
name|Error
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_SPECIALCASELIST_H
end_comment

end_unit

